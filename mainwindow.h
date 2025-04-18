#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include "video_sender.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnLoadVideo_clicked();
    void on_btnConnect_clicked();
    void on_btnSend_clicked();

private:
    Ui::MainWindow *ui;
    QSerialPort serial;
    VideoSender videoSender;
    QString videoPath;
};
#endif // MAINWINDOW_H
