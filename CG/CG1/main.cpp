#include "mainwindow.h"
#include <QApplication>
#include<QtGui>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QImage image(300, 300, QImage::Format_RGB888);
    QRgb value;
    value=qRgb(0,255,0);   //set color of pixel as green
    image.setPixel(250,250,value);  //draws pixel with value
    image.setPixel(150,150,qRgb(255,255,255)); //draws pixel in white color at x,y
                                    //position.
    QLabel l;                              //shows pixel on screen
    l.setPixmap(QPixmap::fromImage(image));
    l.show();



    //draws a line using setPixel() function
    for(int x=50;x<250;++x){
    image.setPixel(x,50,value);
   }

    l.setPixmap(QPixmap::fromImage(image));
    l.show();

    for(int y=50;y<250;++y){
    image.setPixel(50,y,value);
   }
    l.setPixmap(QPixmap::fromImage(image));
    l.show();

    for(int x=50;x<250;++x){
    image.setPixel(x,250,value);
   }
    l.setPixmap(QPixmap::fromImage(image));
    l.show();

    for(int y=50;y<250;++y){
    image.setPixel(250,y,value);
   }
    l.setPixmap(QPixmap::fromImage(image));
    l.show();

    for(int y=50;y<150;++y){
        int x;
        x=y+100;
    image.setPixel(x,y,value);
   }
    l.setPixmap(QPixmap::fromImage(image));
    l.show();

    for(int y=50;y<150;++y){
        int x;
        x=y+100;
    image.setPixel(y,x,value);
   }
    l.setPixmap(QPixmap::fromImage(image));
    l.show();

    for(int y=50;y<150;++y){
        int x;
        x=200-y;
    image.setPixel(y,x,value);
   }
    l.setPixmap(QPixmap::fromImage(image));
    l.show();

    for(int y=150;y<250;++y){
        int x;
        x=400-y;
    image.setPixel(x,y,value);
   }
    l.setPixmap(QPixmap::fromImage(image));
    l.show();

    for(int x=100;x<200;++x){
    image.setPixel(x,100,value);
   }

    l.setPixmap(QPixmap::fromImage(image));
    l.show();

    for(int x=100;x<200;++x){
    image.setPixel(x,200,value);
   }

    l.setPixmap(QPixmap::fromImage(image));
    l.show();

    for(int y=100;y<200;++y){
    image.setPixel(100,y,value);
   }
    l.setPixmap(QPixmap::fromImage(image));
    l.show();

    for(int y=100;y<200;++y){
    image.setPixel(200,y,value);
   }
    l.setPixmap(QPixmap::fromImage(image));
    l.show();


    return a.exec();
}
