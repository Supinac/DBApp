#include "ApiClient.h"

#include <QDebug>
#include <QFile>
#include <QStandardPaths>

ApiClient::ApiClient(QObject *parent) : QObject(parent) {
	m_token = loadToken();
}
QString ApiClient::loadToken() const {
	QString path =
	    QStandardPaths::writableLocation(QStandardPaths::AppConfigLocation) +
	    "/token";

	QFile f(path);
	if (!f.open(QIODevice::ReadOnly)) {
		qWarning() << "ApiClient: no token file at" << path;
		return QString();
	}
	return QString::fromUtf8(f.readAll()).trimmed();
}
void ApiClient::pull(const QString &slug) { qDebug() << "TODO pull:" << slug; }

void ApiClient::push(const QString &slug, const QString &title,
                     const QString &body) {
	qDebug() << "TODO push:" << slug << title << body.size();
}
void ApiClient::pushNew(const QString &slug, const QString &title,
                        const QString &body) {
	qDebug() << "TODO pushNew:" << slug << title << body.size();
}
