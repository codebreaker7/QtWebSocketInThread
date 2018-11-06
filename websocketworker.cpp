#include "websocketworker.h"
#include <QObject>

WebSocketWorker::WebSocketWorker(QObject *parent)
{
    socket = new QWebSocket("", QWebSocketProtocol::VersionLatest, this);
}

void WebSocketWorker::setUrl(const QString &newurl) {
    url.setUrl(newurl);
}

void WebSocketWorker::setMessage(const QString &newmessage) {
    message = newmessage;
}

void WebSocketWorker::do_work(const QString& url, const QString& message) {
    this->message = message;
    socket->open(url);
    connect(socket, &QWebSocket::connected, this, &WebSocketWorker::onConnected);
}

void WebSocketWorker::onConnected() {
    socket->sendTextMessage(message);
    connect(socket, &QWebSocket::textMessageReceived, this, &WebSocketWorker::onReceived);
}

void WebSocketWorker::onReceived(const QString &response) {
    emit respReceived(response);
}

