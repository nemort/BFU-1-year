#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

enum{LEFT, RIGHT, UNDEFINED};

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
    int i = 0;
    QPoint a, b, vector_ab, vector_ba, normal_a1, normal_a2, normal_b1, normal_b2, normal_vector_b, normal_normal;
    int classify(QLine n, QPoint m);
};
#endif // MAINWINDOW_H
