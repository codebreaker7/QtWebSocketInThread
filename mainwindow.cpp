#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QThreadPool>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    WebSocketWorker * backgroundWorker = new WebSocketWorker();
    backgroundWorker->moveToThread(&workerThread);
    connect(this, &MainWindow::operate, backgroundWorker, &WebSocketWorker::do_work);
    connect(backgroundWorker, &WebSocketWorker::respReceived, this, &MainWindow::showResponse);
    connect(&workerThread, &QThread::finished, backgroundWorker, &QObject::deleteLater);
    workerThread.start();
}

void MainWindow::sendRequest() {
    if (ui->threadRadioButton->isChecked()) {
        emit operate("ws://echo.websocket.org", ui->textToSendEdit->text());
    } else  {

    }
}

void MainWindow::showResponse(const QString &response) {
    ui->responseLabel->setText(response);
    workerThread.exit();
}

void MainWindow::showResponseRunnable(const QString &response) {
    ui->responseLabel->setText(response);
}

MainWindow::~MainWindow()
{
    delete ui;
}
