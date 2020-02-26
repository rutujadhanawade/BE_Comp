#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<iostream>
int x1,x2,y1,y2,thickness;

QImage image(351,341,QImage::Format_RGB888);
QRgb green=qRgb(0,255,0);
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
void MainWindow::DDA(int x1,int x2,int y1,int y2){
    float dx,dy,steps,xinc,yinc;
      dx=x2-x1;
      dy=y2-y1;

      steps=abs(dx)>abs(dy)?abs(dx):abs(dy);
      xinc=dx/steps;
      yinc=dy/steps;

      float x=x1;
      float y=y1;

      for(int i=0;i<=steps;i++){
          image.setPixel(x,y,green);
          x=x+xinc;
          y=y+yinc;
      }
     // ui->label->setPixmap(QPixmap::fromImage(image));
      ui->label->setPixmap(QPixmap::fromImage(image));
      ui->label->show();
}

void MainWindow::on_textEdit_textChanged()
{
    QString str= ui->textEdit->toPlainText();
    x1=str.toInt();

}
void MainWindow::on_textEdit_2_textChanged()
{
    QString str= ui->textEdit->toPlainText();
    x2=str.toInt();
}


void MainWindow::on_textEdit_3_textChanged()
{

    QString str= ui->textEdit->toPlainText();
    y1=str.toInt();
}

void MainWindow::on_pushButton_clicked()
{
    //SOLID LINE
      //cout<<x1<<","<<y1<<","<<x2<<","<<y2<<endl;
      float dx,dy,steps,xinc,yinc;
      dx=x2-x1;
      dy=y2-y1;

      steps=abs(dx)>abs(dy)?abs(dx):abs(dy);
      xinc=dx/steps;
      yinc=dy/steps;

      float x=x1;
      float y=y1;

      for(int i=0;i<=steps;i++){
          image.setPixel(x,y,green);
          x=x+xinc;
          y=y+yinc;
          //cout<<x<<y<<endl;
      }
      ui->label->setPixmap(QPixmap::fromImage(image));
  ui->label->show();
}

void MainWindow::on_textEdit_4_textChanged()
{

    QString str= ui->textEdit->toPlainText();
    y2=str.toInt();
}

void MainWindow::on_pushButton_3_clicked()
{
    //thicc line
    //error for slope = infinite
    for(int i=0;i<thickness/2;i++){
       DDA( x1, y1-i, x2, y2-i);
       DDA( x1, y1+i, x2, y2+i);
    }
}
