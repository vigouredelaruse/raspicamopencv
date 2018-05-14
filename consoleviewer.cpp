#include "consoleviewer.h"
/*
ConsoleViewer::ConsoleViewer(QWidget *parent, const QPoint& Position, const QSize& Size) : QWidget (parent)
{
    setAttribute(Qt::WA_OpaquePaintEvent);

    move(Position);
    resize(Size);
}
*/

ConsoleViewer::ConsoleViewer(QWidget *parent) : QWidget(parent)
{

}

void ConsoleViewer::paintEvent(QPaintEvent *){
    QPainter p(this);
    p.drawImage(0,0,m_img);
    m_img = {};
}

void ConsoleViewer::setImage(const QImage &img)
{
    if (!m_img.isNull()) qDebug() << "Viewer dropped frame";
    m_img = img;
    if (m_img.size() != size()) setFixedSize(m_img.size());
    update();
}
