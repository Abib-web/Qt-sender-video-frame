#include "video_sender.h"
#include <opencv2/opencv.hpp>
#include <QThread>

void VideoSender::sendVideoFrames(const std::string &path, QSerialPort &serial, QProgressBar *progress, QTextEdit *log) {
    cv::VideoCapture cap(path);
    if (!cap.isOpened()) {
        log->append("Erreur: impossible d'ouvrir la vidéo.");
        return;
    }

    int totalFrames = static_cast<int>(cap.get(cv::CAP_PROP_FRAME_COUNT));
    progress->setMaximum(totalFrames);

    cv::Mat frame;
    int count = 0;

    while (cap.read(frame)) {
        std::vector<uchar> buffer;
        cv::imencode(".jpg", frame, buffer);

        QByteArray data(reinterpret_cast<const char*>(buffer.data()), buffer.size());
        serial.write(data);
        serial.waitForBytesWritten(-1);

        count++;
        progress->setValue(count);
        QThread::msleep(100);  // pour ne pas saturer le port
    }

    log->append("Envoi terminé.");
}
