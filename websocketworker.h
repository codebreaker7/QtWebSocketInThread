#ifndef WEBSOCKETWORKER_H
#define WEBSOCKETWORKER_H

#include <QThread>
#include <QtWebSockets/QWebSocket>
#include <QUrl>

class WebSocketWorker: public QObject
{
    Q_OBJECT
public:
    WebSocketWorker(QObject *parent = 0);
    void setUrl(const QString& newurl);
    void setMessage(const QString& newmessage);
private:
    QWebSocket * socket;
    QUrl url;
    QString message;
signals:
    void respReceived(const QString& response);
public slots:
    void onConnected();
    void onReceived(const QString& response);
    // QThread interface
public slots:
    void do_work(const QString &url, const QString &message);
};

#endif // WEBSOCKETWORKER_H
