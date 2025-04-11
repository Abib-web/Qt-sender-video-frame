#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSerialPortInfo>
#include <QFileDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    // Lister les ports disponibles
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        ui->comboPort->addItem(info.portName());
    }
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_btnLoadVideo_clicked() {
    videoPath = QFileDialog::getOpenFileName(this, "Open Video", "", "Videos (*.mp4 *.avi)");
    if (!videoPath.isEmpty()) {
        ui->logConsole->append("Vidéo chargée : " + videoPath);
    }
}

void MainWindow::on_btnConnect_clicked() {
    QString portName = ui->comboPort->currentText();
    serial.setPortName(portName);
    serial.setBaudRate(QSerialPort::Baud115200);
    if (serial.open(QIODevice::WriteOnly)) {
        ui->logConsole->append("Connecté à " + portName);
    } else {
        QMessageBox::critical(this, "Erreur", "Impossible d'ouvrir le port.");
    }
}

void MainWindow::on_btnSend_clicked() {
    if (videoPath.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez charger une vidéo.");
        return;
    }
    if (!serial.isOpen()) {
        QMessageBox::warning(this, "Erreur", "Connectez d'abord le port UART.");
        return;
    }

    ui->logConsole->append("Envoi en cours...");
    videoSender.sendVideoFrames(videoPath.toStdString(), serial, ui->progressBar, ui->logConsole);
}
