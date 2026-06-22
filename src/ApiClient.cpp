#include "ApiClient.h"

#include <QDebug>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QStandardPaths>
#include <QUrl>

ApiClient::ApiClient(QObject *parent) : QObject(parent) {
	m_net = new QNetworkAccessManager(this);
	m_token = loadToken();
}
QString ApiClient::loadToken() const {
	QString path = QStandardPaths::writableLocation(QStandardPaths::AppConfigLocation) + "/token";
	QFile f(path);
	if (!f.open(QIODevice::ReadOnly)) {
		qWarning() << "ApiClient: no token file at" << path;
		return QString();
	}
	return QString::fromUtf8(f.readAll()).trimmed();
}
void ApiClient::pull(const QString &slug) {
	QUrl url(m_baseUrl + "/" + slug);
	QNetworkRequest req(url);
	req.setRawHeader("Authorization", "Bearer " + m_token.toUtf8());
	QNetworkReply *reply = m_net->get(req);
	connect(reply, &QNetworkReply::finished, this, [this, reply]() {
		if (reply->error() != QNetworkReply::NoError) {
			emit errored(reply->errorString());
			reply->deleteLater();
			return;
		}
		QJsonDocument doc = QJsonDocument::fromJson(reply->readAll());
		QJsonObject obj = doc.object();
		emit pulled(obj["title"].toString(), obj["body"].toString());
		reply->deleteLater();
	});
}
void ApiClient::push(const QString &slug, const QString &title, const QString &body) {
	QUrl url(m_baseUrl + "/" + slug);
	QNetworkRequest req(url);
	req.setRawHeader("Authorization", "Bearer " + m_token.toUtf8());
	req.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

	QJsonObject obj;
	obj["title"] = title;
	obj["body"] = body;
	QByteArray payload = QJsonDocument(obj).toJson(QJsonDocument::Compact);

	QNetworkReply *reply = m_net->put(req, payload);

	connect(reply, &QNetworkReply::finished, this, [this, reply]() {
		if (reply->error() != QNetworkReply::NoError) {
			emit errored(reply->errorString());
			reply->deleteLater();
			return;
		}
		emit pushed();
		reply->deleteLater();
	});
}

void ApiClient::pushNew(const QString &slug, const QString &title, const QString &body) {
	QUrl url(m_baseUrl); // NO /slug — POSTs go to the collection
	QNetworkRequest req(url);
	req.setRawHeader("Authorization", "Bearer " + m_token.toUtf8());
	req.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

	QJsonObject obj;
	obj["slug"] = slug; // slug IS in the payload (PUT it isn't)
	obj["title"] = title;
	obj["body"] = body;
	QByteArray payload = QJsonDocument(obj).toJson(QJsonDocument::Compact);

	QNetworkReply *reply = m_net->post(req, payload); // post(), not put()

	connect(reply, &QNetworkReply::finished, this, [this, reply]() {
		if (reply->error() != QNetworkReply::NoError) {
			emit errored(reply->errorString());
			reply->deleteLater();
			return;
		}
		emit pushed();
		reply->deleteLater();
	});
}
