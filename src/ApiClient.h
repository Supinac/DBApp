#pragma once
#include <QObject>
#include <QString>

class QNetworkAccessManager;

class ApiClient : public QObject {
	Q_OBJECT
public:
	explicit ApiClient(QObject *parent = nullptr);
	void pull(const QString &slug);
	void push(const QString &slug, const QString &title, const QString &body);
	void pushNew(const QString &slug, const QString &title, const QString &body); // Finish later
signals:
	void pulled(const QString &title, const QString &body);
	void pushed();
	void errored(const QString &msg);

private:
	QString loadToken() const;
	QNetworkAccessManager *m_net;
	QString m_token;
	QString m_baseUrl = "https://api.tobiasweb.xyz/api/content/pages";
};
