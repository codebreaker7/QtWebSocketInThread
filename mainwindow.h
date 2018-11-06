#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "websocketworker.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void sendRequest();
    void showResponse(const QString& response);
    void showResponseRunnable(const QString& response);
signals:
    void operate(const QString&, const QString&);
private:
    Ui::MainWindow *ui;
    QThread workerThread;
};

#endif // MAINWINDOW_H
