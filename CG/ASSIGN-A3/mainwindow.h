#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
        void DDA(float x1,float y1,float x2,float y2);
        void DDA2(float x1,float y1,float x2,float y2);
        void DDA3(float x1,float y1,float x2,float y2);
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();


    void on_pushButton_3_clicked();



private:
    Ui::MainWindow *ui;
    float start_pts[1][2];
    float end_pts[1][2];
    int arr[10][2];
    void mousePressEvent(QMouseEvent *event);
};

#endif // MAINWINDOW_H
