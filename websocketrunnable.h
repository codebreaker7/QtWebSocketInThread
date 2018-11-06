#ifndef WEBSOCKETRUNNABLE_H
#define WEBSOCKETRUNNABLE_H

#include <QRunnable>
#include <QWebSocket>

class WebSocketRunnable : public QObject, public QRunnable
{
    Q_OBJECT
public:
    WebSocketRunnable();
    void setUrl(const QString&);
    void setMessage(const QString&);
signals:
    void responseReady(const QString&);
    // QRunnable interface
public:
    virtual void run() override;
public slots:
    void processConnection();
    void processReception(const QString&);
private:
    QString message;
    QUrl url;
};

#endif // WEBSOCKETRUNNABLE_H
