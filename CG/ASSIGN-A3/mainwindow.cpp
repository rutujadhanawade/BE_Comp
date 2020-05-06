#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "math.h"
#include "QMouseEvent"
#define pi 3.14
QImage Image(941,671,QImage::Format_RGB888);
QRgb value=qRgb(255,55,0);
QRgb value1=qRgb(255,155,0);
QRgb value2=qRgb(200,0,200);
QRgb value3=qRgb(87,55,255);
float start_pts[1][2];
float end_pts[1][2];
float mat[2][2];
int i = 0;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label->setPixmap(QPixmap::fromImage(Image));
    ui->label->show();
}

void MainWindow::DDA(float x1,float y1,float x2,float y2)
{
    int i=1;
      float x=x2-x1;
      float y=y2-y1;
      float steps;
      float xinc,yinc;
      if(abs(x) > abs(y))
      {
          steps=abs(x);
      }
      else
      {
          steps=abs(y);
      }
      xinc= (x/steps);
      yinc=(y/steps);
      for(i=1;i<=steps;i++)
      {
          Image.setPixel(x1,y1,value);
          x1=x1+xinc;
          y1=y1+yinc;
      }
}
void MainWindow::DDA2(float x1,float y1,float x2,float y2)
{
    int i=1;
      float x=x2-x1;
      float y=y2-y1;
      float steps;
      float xinc,yinc;
      if(abs(x) > abs(y))
      {
          steps=abs(x);
      }
      else
      {
          steps=abs(y);
      }
      xinc= (x/steps);
      yinc=(y/steps);
      for(i=1;i<=steps;i++)
      {
          Image.setPixel(x1,y1,value2);
          x1=x1+xinc;
          y1=y1+yinc;
      }
}
void MainWindow::DDA3(float x1,float y1,float x2,float y2)
{
    int i=1;
      float x=x2-x1;
      float y=y2-y1;
      float steps;
      float xinc,yinc;
      if(abs(x) > abs(y))
      {
          steps=abs(x);
      }
      else
      {
          steps=abs(y);
      }
      xinc= (x/steps);
      yinc=(y/steps);
      for(i=1;i<=steps;i++)
      {
          Image.setPixel(x1,y1,value3);
          x1=x1+xinc;
          y1=y1+yinc;
      }
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::mousePressEvent(QMouseEvent *event)
{
     float X,Y;
    if(i==0)
    {
        X=event->pos().x()-10;
        Y=event->pos().y()-45;
        arr[i][0]=X;
        arr[i][1]=Y;
        Image.setPixel(arr[i][0],arr[i][1],value1);
        ui->label->setPixmap(QPixmap::fromImage(Image));
        ui->label->show();
        i++;
        return;

    }
    if(i<10)
    {
        if(event->button()==Qt::LeftButton)
        {
            X=event->pos().x()-10;
            Y=event->pos().y()-45;
            arr[i][0]=X;
            arr[i][1]=Y;
           Image.setPixel(arr[i][0],arr[i][1],value1);
           DDA(arr[i-1][0],arr[i-1][1],arr[i][0],arr[i][1]);
           ui->label->setPixmap(QPixmap::fromImage(Image));
            ui->label->show();
            i++;
        }
        else
        {
            X=event->pos().x()-10;
            Y=event->pos().y()-45;
            arr[i][0]=X;
            arr[i][1]=Y;
            Image.setPixel(arr[i][0],arr[i][1],value1);
             DDA(arr[i-1][0],arr[i-1][1],arr[i][0],arr[i][1]);
             DDA(arr[0][0],arr[0][1],arr[i][0],arr[i][1]);
             ui->label->setPixmap(QPixmap::fromImage(Image));
              ui->label->show();
               i++;
              return;
        }

    }
}
void MainWindow::on_pushButton_clicked() // ROTATION FUNCTION
{
    int rotated[10][2]; // MATRIX FOR STORING ROTATED COORDINATES
    QString str = ui->textEdit->toPlainText();
    float angle = str.toFloat();  // SCANNING ANGLE FOR ROTATION
    angle = (angle*pi)/180;  // ANGLE CALCULATION IN DEGREES

    int pivot_x = arr[0][0]; // PIVOT POINT IS THE 1ST X COORDINATE OF POLYGON
    int pivot_y = arr[0][1]; // PIVOT POINT IS THE 1ST Y COORDINATE OF POLYGON
    int count = i-1;
    int k;
    for( k=0;k<=count;k++)
    {
        rotated[k][0] = pivot_x + ((arr[k][0] - pivot_x) * cos(angle) - (arr[k][1] - pivot_y) * sin(angle));
        rotated[k][1] = pivot_y + ((arr[k][0] - pivot_x) * sin(angle)+ (arr[k][1] - pivot_y) *cos(angle));
    }
    for( k=0 ; k<count ;k++)
    {
        DDA2(rotated[k][0],rotated[k][1],rotated[k+1][0],rotated[k+1][1]);
    }
    if(k == count)
    {
        DDA2(rotated[k][0],rotated[k][1],rotated[0][0],rotated[0][1]);
    }
    ui->label->setPixmap(QPixmap::fromImage(Image));

}

void MainWindow::on_pushButton_2_clicked() // TRANSLATION FUNCTION
{

   QString str = ui->textEdit_2->toPlainText();
    float tx = str.toFloat();
    str = ui->textEdit_3->toPlainText();
    float ty = str.toFloat();
    //DDA(x1,y1,x2,y2);
    int k;
    int count = i-1;
    for(k=0;k<count;k++)
    {
        DDA3(arr[k][0]+tx,arr[k][1]+tx,arr[k+1][0]+tx,arr[k+1][1]+ty);
    }
    if(k == count)
    {
        DDA3(arr[k][0]+tx,arr[k][1]+ty,arr[0][0]+tx,arr[0][1]+ty);
    }
    ui->label->setPixmap(QPixmap::fromImage(Image));
}

void MainWindow::on_pushButton_3_clicked() //SCALING FUNCTION
{
    int scaled[10][2];
    int count = i-1;
    int k;
    QString str = ui->textEdit_4->toPlainText();
    float Sx = str.toFloat();
    str = ui->textEdit_5->toPlainText();
    float Sy = str.toFloat();
    for(k=0;k<=count;k++)
    {
        scaled[k][0]=arr[k][0]*Sx;
        scaled[k][1]=arr[k][1]*Sy;
    }
    for( k=0 ; k<count ;k++)
    {
        DDA(scaled[k][0],scaled[k][1],scaled[k+1][0],scaled[k+1][1]);
    }
    if(k == count)
    {
        DDA(scaled[k][0],scaled[k][1],scaled[0][0],scaled[0][1]);
    }
    ui->label->setPixmap(QPixmap::fromImage(Image));
}


