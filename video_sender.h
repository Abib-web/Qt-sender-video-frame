#ifndef VIDEO_SENDER_H
#define VIDEO_SENDER_H

#include <QString>
#include <QSerialPort>
#include <QProgressBar>
#include <QTextEdit>

class VideoSender {
public:
    void sendVideoFrames(const std::string &path, QSerialPort &serial, QProgressBar *progress, QTextEdit *log);
};

#endif // VIDEO_SENDER_H
