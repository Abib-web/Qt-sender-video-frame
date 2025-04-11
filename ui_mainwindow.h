/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *btnLoadVideo;
    QComboBox *comboPort;
    QPushButton *btnConnect;
    QPushButton *btnSend;
    QProgressBar *progressBar;
    QTextEdit *logConsole;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(600, 400);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        btnLoadVideo = new QPushButton(centralwidget);
        btnLoadVideo->setObjectName(QString::fromUtf8("btnLoadVideo"));
        btnLoadVideo->setGeometry(QRect(30, 20, 150, 30));
        comboPort = new QComboBox(centralwidget);
        comboPort->setObjectName(QString::fromUtf8("comboPort"));
        comboPort->setGeometry(QRect(200, 20, 150, 30));
        btnConnect = new QPushButton(centralwidget);
        btnConnect->setObjectName(QString::fromUtf8("btnConnect"));
        btnConnect->setGeometry(QRect(370, 20, 100, 30));
        btnSend = new QPushButton(centralwidget);
        btnSend->setObjectName(QString::fromUtf8("btnSend"));
        btnSend->setGeometry(QRect(480, 20, 80, 30));
        progressBar = new QProgressBar(centralwidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(30, 70, 530, 25));
        progressBar->setValue(0);
        logConsole = new QTextEdit(centralwidget);
        logConsole->setObjectName(QString::fromUtf8("logConsole"));
        logConsole->setGeometry(QRect(30, 110, 530, 230));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "App Send Frame", nullptr));
        btnLoadVideo->setText(QApplication::translate("MainWindow", "Charger une vid\303\251o", nullptr));
        btnConnect->setText(QApplication::translate("MainWindow", "Se connecter", nullptr));
        btnSend->setText(QApplication::translate("MainWindow", "Envoyer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
