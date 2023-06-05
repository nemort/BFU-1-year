#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QPainter>
#include <QMouseEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QRect setka(QPoint(0, 0), QSize(B, B));
    for (int i = 0; i < 400; i++){
        for (int j = 0; j < 400; j++){
            painter.drawRect(setka.translated(B * j, B * i));
        }
    }

    if (!c.center.isNull()){
        painter.setBrush(Qt::green);
        painter.drawEllipse(c.center, c.radius, c.radius);
    }

    if (!ant.isNull()){
        painter.setBrush(Qt::black);
        painter.drawEllipse(ant, 10, 10);
    }

    if (!fly.isNull()){
        painter.setBrush(Qt::red);
        painter.drawEllipse(fly, 10, 10);
    }

    if (!ant.isNull() && !fly.isNull())
        for(int i = 0; i < min_p.size() - 1; i++){
            QPen brush(Qt::red);
            brush.setWidth(4);
            painter.setPen(brush);
            painter.drawLine(min_p[i], min_p[i + 1]);
        }
}



void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (event->button()&Qt::MiddleButton)
        c = {event->pos(), R};

    if (event->button()&Qt::LeftButton)
        ant = event->pos()/B*B;

    if (event->button()&Qt::RightButton && !contains(c, event->pos()))
        fly = event->pos()/B*B;
    ant_move = ant;
    min_p.clear();
    min_p.append(ant);
    int i = 0;
    while (ant_move != fly && !ant.isNull() && !fly.isNull()){
        i++;
        moves[0] = QPoint(-B, 0) + ant_move;
        moves[1] = QPoint(0, B) + ant_move;
        moves[2] = QPoint(B, 0) + ant_move;
        moves[3] = QPoint(0, -B) + ant_move;
        int min = 9999999;
        for (int i = 0; i < 4; i++)
            if (!contains(c, moves[i]) && (min_p.size() == 1 || moves[i] != min_p[min_p.size() - 2])){
                len = sqrt((fly.x() - moves[i].x()) * (fly.x() - moves[i].x()) + (fly.y() - moves[i].y()) * (fly.y() - moves[i].y()));
                if (len < min){
                    min = len;
                    min_now = moves[i];
                }
            }
        min_p.append(min_now);
        ant_move = min_now;
    }
    repaint();
}



bool MainWindow::contains(Circle c, QPoint p)
{
    QPoint c1(c.center - p);
    return (c.radius * c.radius > QPoint::dotProduct(c1, c1));
}
