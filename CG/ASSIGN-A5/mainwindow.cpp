#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>
#include "math.h"

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
QImage img(600, 600, QImage::Format_RGB888);


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
void MainWindow::Bresenham(int x1,int y1,int x2,int y2)
{
    QRgb val=qRgb(255,255,255);
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
         img.setPixel(x,y,val);
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


void seedfill(int x, int y, QRgb old, QRgb  col)
{
    QRgb curr=img.pixel(x,y);
    if(curr!=col)
    {
        qDebug()<<x<<" "<<y<<endl;
        img.setPixel(x,y,col);
        seedfill(x,y+1,old,col);
        seedfill(x-1,y,old,col);
        seedfill(x,y-1,old,col);
        seedfill(x+1,y,old,col);
    }
}
void MainWindow::draw(int l, int s)
{
    int ox=300, oy=300;
    //img.setPixel(ox, oy, qRgb(0, 255, 0));
    int up_x=ox, up_y=oy-l/2;
    int left_x = ox-l/2, left_y = oy;
    int right_x = up_x + l/2, right_y = left_y;
    int down_x = up_x, down_y = up_y+l;
    img.setPixel(up_x, up_y, qRgb(255, 255, 255));
    img.setPixel(left_x, left_y, qRgb(255, 255, 255));
    img.setPixel(right_x, right_y, qRgb(255, 255, 255));
    img.setPixel(down_x, down_y, qRgb(255, 255, 255));

    Bresenham(up_x, up_y, left_x, left_y);
    Bresenham(up_x, up_y, right_x, right_y);
    Bresenham(down_x, down_y, left_x, left_y);
    Bresenham(down_x, down_y, right_x, right_y);
    QRgb old=qRgb(0,0,0);
    QRgb new_col=qRgb(255, 255, 255);

    float halfl=l/2;
    for(int i=1; i<s; i++)
    {
        int x_start=up_x + i*halfl/s, y_start=up_y + i*halfl/s;
        int x_end=left_x + i*halfl/s, y_end=left_y + i*halfl/s;

        Bresenham(x_start, y_start, x_end, y_end);
    }
    for(int i=1; i<s; i++)
    {
        int x_start=up_x - i*halfl/s, y_start=up_y + i*halfl/s;
        int x_end=right_x - i*halfl/s, y_end=right_y + i*halfl/s;

        Bresenham(x_start, y_start, x_end, y_end);
    }


    int start_fillx = left_x+halfl/s, start_filly = left_y;
    seedfill(start_fillx, start_filly, old, new_col);
    int end;
    if(s%2==1)
    {
        end=s/2+1;
    } else
    {
        end=s/2;
    }
    for(int i=0; i<end; i++)
    {
        int basex=start_fillx+i*l/s;
        int basey=start_filly+i*l/s;
        seedfill(basex, basey, old, new_col);

        for(int j=0; j<end; j++)
        {
            int fiy=basey - j*l/s;
            int fix=basex + j*l/s;
            seedfill(fix, fiy, old, new_col);
        }
    }
    start_fillx = left_x+halfl/s+l/s;
    start_filly = left_y;
    seedfill(start_fillx, start_filly, old, new_col);
    for(int i=0; i<s/2; i++)
    {
        int basex=start_fillx+i*l/s;
        int basey=start_filly+i*l/s;
        seedfill(basex, basey, old, new_col);

        for(int j=0; j<s/2; j++)
        {
            int fiy=basey - j*l/s;
            int fix=basex + j*l/s;
            seedfill(fix, fiy, old, new_col);
        }
    }


}


void MainWindow::on_pushButton_clicked()
{
    int s=ui->textEdit_2->toPlainText().toInt();
    int l = ui->textEdit->toPlainText().toInt();
    draw(l,s);

}


void MainWindow::on_pushButton_2_clicked()
{
    for(int i=0;i<600;i++)
    {
        for(int j=0;j<600;j++)
            img.setPixel(i,j,qRgb(0,0,0));
    }
    ui->label->setPixmap(QPixmap::fromImage(img));
}



