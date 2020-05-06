#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMouseEvent"
#include "math.h"



const int inside = 0;
const int left = 1;
const int right = 2;
const int bottom = 4;
const int top = 8;
int ymin=100;
int xmin=100;
int xmax=400;
int ymax=400;
QImage image(500,500,QImage::Format_RGB888);




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}
MainWindow::~MainWindow()
{
    delete ui;
}




int xcol[10],ycol[10];
int i=0,j=0;
int n=1;

void MainWindow :: mousePressEvent(QMouseEvent *event) {
    int x,y;
    if(event->pos().x()<=500&&event->pos().y())
    {
        if(event->button() == Qt::RightButton) {
            n = i;
            drawPolygon();
            i=0;
            j=0;
            n=1;
        }
        else {
            x=event->pos().x();
            y=event->pos().y();
            image.setPixel(x,y,qRgb(0,216,0));
            ui->label->setPixmap(QPixmap::fromImage(image));
            xcol[i]=x;
            ycol[i]=y;
            i++;
        }
    }
}
void MainWindow :: drawPolygon() {

    i=0;
    j=1;
    for(int k=0;k<n;k++) {
        cohenSutherlandClip(xcol[i],ycol[i],xcol[j],ycol[j]);
        i++;
        j=(j+1)%n;
    }
}
void MainWindow :: DDA(float x1, float x2, float y1, float y2, QRgb value) {
    float dx,dy;
    float steps;
    float x,y;
    dx=x2-x1;
    dy=y2-y1;
    if(abs(dx)>abs(dy)){
        steps = abs(dx);
    }else{
        steps = abs(dy);
    }
    float xinc=dx/steps;
    float yinc=dy/steps;
    x=x1;
    y=y1;
    for(int i=0;i<steps;i++) {
        image.setPixel(int(x),int(y),value);
        x+=xinc;
        y+=yinc;
    }
    ui->label->setPixmap(QPixmap::fromImage(image));
}

int MainWindow::calcCode(int x,int y) {
   int code = inside;
   if(x<xmin) {
       code |= left;        //1
   }
   else if(x>xmax) {
       code |= right;       //2
   }
   if(y<ymin) {
       code |= bottom;      //4
   }
   else if(y>ymax) {
       code |= top;         //8
   }
   return code;
}
void MainWindow :: cohenSutherlandClip(double x1, double y1, double x2, double y2)
{
    int code1 = calcCode(x1, y1);
    int code2 = calcCode(x2, y2);

    bool accept = false;

    while (true)
    {
        if ((code1 == 0) && (code2 == 0))
        {
            accept = true;
            break;
        }
        else if (code1 & code2)
        {
            break;
        }
        else
        {
            int code_out;
            double x, y;
            if (code1 != 0)
                code_out = code1;
            else
                code_out = code2;
            if (code_out & top)
            {
                x = x1 + (x2 - x1) * (ymax - y1) / (y2 - y1);
                y = ymax;
            }
            else if (code_out & bottom)
            {
                x = x1 + (x2 - x1) * (ymin - y1) / (y2 - y1);
                y = ymin;
            }
            else if (code_out & right)
            {
                y = y1 + (y2 - y1) * (xmax - x1) / (x2 - x1);
                x = xmax;
            }
            else if (code_out & left)
            {
                y = y1 + (y2 - y1) * (xmin - x1) / (x2 - x1);
                x = xmin;
            }

            if (code_out == code1)
            {
                x1 = x;
                y1 = y;
                code1 = calcCode(x1, y1);
            }
            else
            {
                x2 = x;
                y2 = y;
                code2 = calcCode(x2, y2);
            }
        }
    }
    if(accept)
        DDA(x1,x2,y1,y2,qRgb(0,216,0));
}
void MainWindow::on_pushButton_clicked() {
    DDA(xmin,xmax,ymin,ymin,qRgb(255,255,255));
    DDA(xmin,xmax,ymax,ymax,qRgb(255,255,255));
    DDA(xmin,xmin,ymin,ymax,qRgb(255,255,255));
    DDA(xmax,xmax,ymin,ymax,qRgb(255,255,255));
    ui->label->setPixmap(QPixmap::fromImage(image));
}

void MainWindow::on_pushButton_2_clicked()
{

    image.fill(qRgb(0,0,0));
    DDA(xmin,xmax,ymin,ymin,qRgb(255,255,255));
    DDA(xmin,xmax,ymax,ymax,qRgb(255,255,255));
    DDA(xmin,xmin,ymin,ymax,qRgb(255,255,255));
    DDA(xmax,xmax,ymin,ymax,qRgb(255,255,255));
    ui->label->setPixmap(QPixmap::fromImage(image));

}
