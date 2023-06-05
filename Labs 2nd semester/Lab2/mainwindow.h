#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

struct Circle {
    QPoint center;
    int radius;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);

private:
    Ui::MainWindow *ui;
    QImage grass = QImage("C:/Qt/Projects/Laba2-pull/img/grass16x16.GIF"), flower = QImage("C:/Qt/Projects/Laba2-pull/img/flower.jpg");
    QVector<QRect> clumbs;
    QVector<Circle> c_clumbs;
    QRect pool = QRect(QPoint(200,150), QSize(400,300));
    bool intersects(Circle c1, Circle c2);
    bool contains(Circle c, QPoint p);
    bool intersects_circle(Circle c, QRect r);
};
#endif // MAINWINDOW_H
