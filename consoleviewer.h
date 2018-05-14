#ifndef CONSOLEVIEWER_H
#define CONSOLEVIEWER_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>
#include <opencv2/opencv.hpp>

class ConsoleViewer : public QWidget
{
    Q_OBJECT
    QImage m_img;
    void paintEvent(QPaintEvent *);

public:
   explicit ConsoleViewer(QWidget *parent = 0);
   //explicit ConsoleViewer(QWidget *parent, const QPoint& Position, const QSize& Size);

signals:

public slots:
    void setImage(const QImage & img);
};

#endif // CONSOLEVIEWER_H
