#include "websocketrunnable.h"
#include <QThread>

WebSocketRunnable::WebSocketRunnable()
{

}

void WebSocketRunnable::run() {
    QWebSocket socket;
    socket.moveToThread(QThread::currentThread());
    socket.open(url);
    connect(&socket, &QWebSocket::connected, this, &WebSocketRunnable::processConnection);
}

void WebSocketRunnable::processConnection() {
    QWebSocket * socket =qobject_cast<QWebSocket*>(sender());
    socket->sendTextMessage(message);
    connect(socket, &QWebSocket::textMessageReceived, this, &WebSocketRunnable::processReception);
}

void WebSocketRunnable::processReception(const QString & str) {
    emit responseReady(str);
}

void WebSocketRunnable::setUrl(const QString & newurl) {
    url.setUrl(newurl);
}

void WebSocketRunnable::setMessage(const QString & message) {
    this->message = message;
}
