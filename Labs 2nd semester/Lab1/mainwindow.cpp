#include "mainwindow.h"
#include "ui_mainwindow.h"
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
    vector_ab = QPoint(b - a);
    vector_ba = QPoint(a - b);
    normal_a1 = QPoint(-vector_ab.y(), vector_ab.x());
    normal_a2 = QPoint(vector_ab.y(), -vector_ab.x());
    normal_b1 = QPoint(-vector_ba.y(), vector_ba.x());
    normal_b2 = QPoint(vector_ba.y(), -vector_ba.x());
    normal_vector_b = QPoint(normal_b2 - normal_b1);
    normal_normal = QPoint(normal_vector_b.y(), -normal_vector_b.x());
    if (!a.isNull() && !b.isNull()){
        QPainter painter(this);
        QBrush brush(Qt::yellow);
        painter.setBrush(brush);
        painter.drawLine(a, b);
        QPoint triangle[3] = {b, b + normal_b1 + normal_normal, b + normal_b2 + normal_normal};
        painter.drawPolygon(triangle, 3);

    }
}



void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (i == 0)
        a = event->pos();
    if (i == 1)
        b = event->pos();
    if (i >= 2){
        int t = classify(QLine(a, b), event->pos());
        int t1 = classify(QLine(b + normal_b2, b + normal_b1), event->pos());
        int t2 = classify(QLine(a + normal_a1, a + normal_a2), event->pos());
        int t3 = classify(QLine(b + normal_b2 + normal_normal, b + normal_b1 + normal_normal), event->pos()); //Дальняя сторона луча
        int t4 = classify(QLine(b, b + normal_b1 + normal_normal), event->pos()); //Верхняя сторона луча
        int t5 = classify(QLine(b, b + normal_b2 + normal_normal), event->pos()); //Нижняя сторона луча
        qDebug("%s %s %s", t1 == RIGHT ? "Front" : t2 == LEFT ? "Back" : (t1 == LEFT && t2 == RIGHT) ? "Side" : "Undefined", t == LEFT ? "Left" : t == RIGHT ? "Right" : "Undefined", t3 == LEFT && t4 == RIGHT && t5 == LEFT ? "In" : "Out");
    }
    i++;
    repaint();
}



int MainWindow::classify(QLine n, QPoint m)
{   //для перевернутой декартовой системы
    QPoint z = n.p2() - n.p1();
    QPoint x = m - n.p1();
    int c = z.x() * x.y() - x.x() * z.y();
    if(c > 0)
        return RIGHT;
    if(c < 0)
        return LEFT;
    if(c == 0)
        return UNDEFINED;
}
