#include "mainwindow.h"
#include "ui_mainwindow.h"

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

QImage img = QImage(500, 500, QImage::Format_RGB888);
QImage blank = QImage(500, 500, QImage::Format_RGB888);


int MainWindow::sign(int x)
{
    if(x==0)
    {
        return 0;
    }
    if(x>0)
    {
        return 1;
    }
    return -1;
}
void MainWindow::bres(int x1,int y1,int x2,int y2)
{
    QRgb val=qRgb(255,255,0);
    int dx=x2-x1,dy=y2-y1,sx=sign(dx),sy=sign(dy);
    int inte=0,e;
    int x=x1,y=y1;
    dx=abs(dx);
    dy=abs(dy);
    if(dy>dx)
    {
        int temp=dy;
        dy=dx;
        dx=temp;
        inte=1;
    }
    e=2*dy-dx;

    for(int i=0;i<dx;i++)
     {
         img.setPixel(x+400,300-y,val);
         while(e>=0)
         {
             if(inte)
             {
                 x+=sx;
             }
             else
             {
                 y+=sy;
             }
             e-=2*dx;

         }
         if(inte)
         {
             y+=sy;
         }
         else
         {
             x+=sx;
         }
         e+=2*dy;
     }

ui->label->setPixmap(QPixmap::fromImage(img));
}
void MainWindow::move(int &x, int &y, int h, char direction)
{
    int x1 = x, y1 = y;
    switch (direction)
    {
    case 'U':
        y = y-h;
        break;
    case 'D':
        y = y+h;
        break;
    case 'L':
        x = x+h;
        break;
    case 'R':
        x = x-h;
        break;
    default:
        break;
    }
    bres(x, y, x1, y1);
}
void MainWindow::hilbert(int &x, int &y, int h, int level, char direction)
{
    if (level == 1)
    {
        switch (direction)
        {
        case 'U':
            move(x, y, h, 'D');
            move(x, y, h, 'R');
            move(x, y, h, 'U');
            break;
        case 'D':

            move(x, y, h, 'U');
            move(x, y, h, 'L');
            move(x, y, h, 'D');

            break;
        case 'L':
            move(x, y, h, 'R');
            move(x, y, h, 'D');
            move(x, y, h, 'L');
            break;
        case 'R':
            move(x, y, h, 'L');
            move(x, y, h, 'U');
            move(x, y, h, 'R');
            break;
        }
    }
    else
    {
        switch (direction)
        {
        case 'U':
            hilbert(x, y, h, level - 1, 'L');
            move(x, y, h, 'D');
            hilbert(x, y, h, level - 1, 'U');
            move(x, y, h, 'R');
            hilbert(x, y, h, level - 1, 'U');
            move(x, y, h, 'U');
            hilbert(x, y, h, level - 1, 'R');
            break;
        case 'L':
            hilbert(x, y, h, level - 1, 'U');
            move(x, y, h, 'R');
            hilbert(x, y, h, level - 1, 'L');
            move(x, y, h, 'D');
            hilbert(x, y, h, level - 1, 'L');
            move(x, y, h, 'L');
            hilbert(x, y, h, level - 1, 'D');
            break;
        case 'R':
            hilbert(x, y, h, level - 1, 'D');
            move(x, y, h, 'L');
            hilbert(x, y, h, level - 1, 'R');
            move(x, y, h, 'U');
            hilbert(x, y, h, level - 1, 'R');
            move(x, y, h, 'R');
            hilbert(x, y, h, level - 1, 'U');
            break;
        case 'D':
            hilbert(x, y, h, level - 1, 'R');
            move(x, y, h, 'U');
            hilbert(x, y, h, level - 1, 'D');
            move(x, y, h, 'L');
            hilbert(x, y, h, level - 1, 'D');
            move(x, y, h, 'D');
            hilbert(x, y, h, level - 1, 'L');
            break;
        }
    }
}
void MainWindow::on_pushButton_clicked()
{
    img=blank.copy();
    int level=1;
    level = ui->textEdit->toPlainText().toInt();
    int h = 50 / 2/ level;
    int x=-40;
    int y=-40;
    hilbert(x, y, h, level, 'U');

}


void MainWindow::on_pushButton_2_clicked()
{
    img.fill(qRgb(0,0,0));
    ui->label->setPixmap(QPixmap::fromImage(img));

}
