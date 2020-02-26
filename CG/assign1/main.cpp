#include<bits/stdc++.h>
using namespace std;
#include "mainwindow.h"

#include <QApplication>
#include<QtGui>
int Sign(int x){
    if(x>0) return 1;

    else if(x<0) return -1;
    else if(x==0) return 0;
}

QImage BA(int ,int,int,int,QImage);
QImage DDA(int x1, int x2, int y1, int y2,QImage);
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QImage image(300, 300, QImage::Format_RGB888);

 QLabel l;
    image=DDA(50,100,100,150,image);
                                //shows pixel on screen
    l.setPixmap(QPixmap::fromImage(image));
    l.show();

    image=DDA(100,150,150,100,image);
    l.setPixmap(QPixmap::fromImage(image));
    l.show();
   image=DDA(50,100,100,50,image);
    l.setPixmap(QPixmap::fromImage(image));
    l.show();

    image=BA(100,50,150,100,image);
    l.setPixmap(QPixmap::fromImage(image));
    l.show();


    image=BA(50,50,50,150,image);
    QLabel l1;                              //shows pixel on screen
    l1.setPixmap(QPixmap::fromImage(image));
    l1.show();
     image=BA(50,50,150,50,image);
     l1.setPixmap(QPixmap::fromImage(image));
     l1.show();
      image=BA(150,50,150,150,image);
      l1.setPixmap(QPixmap::fromImage(image));
      l1.show();
       image=BA(50,150,150,150,image);
       l1.setPixmap(QPixmap::fromImage(image));
       l1.show();

       image=BA(75,75,125,75,image);
       l1.setPixmap(QPixmap::fromImage(image));
       l1.show();
       image=BA(125,75,125,125,image);
       l1.setPixmap(QPixmap::fromImage(image));
       l1.show();

       image=BA(75,75,75,125,image);
       l1.setPixmap(QPixmap::fromImage(image));
       l1.show();


       image=BA(125,125,75,125,image);
       l1.setPixmap(QPixmap::fromImage(image));
       l1.show();





    return a.exec();
}
QImage DDA(int x1,int x2,int y1,int y2,QImage image){
     int dx,dy,steps,Xi,Yi,x,y;
     QRgb value;
     value=qRgb(0,255,0);

     dx=x2-x1;
     dy=y2-y1;

     steps=max(dx,dy);

     Xi=dx/steps;
    Yi=dy/steps;

    x=x1; y=y1;
    do{
         image.setPixel(x,y,value);
        x+=Xi;
        y+=Yi;
    }while(x!=x2 &&y!=y2);

  return image;
}

QImage BA(int x1,int y1,int x2,int y2,QImage image){
    int dx,i,dy,x,y,e1,temp,s1,s2,inter;
    x=x1;y=y1;

    dx=abs(x2-x1);
    dy=abs(y2-y1);
    e1=(2*dy)-dx;
    s1=Sign(x2-x1);
    s2=Sign(y2-y1);
    QRgb value;
    value=qRgb(0,255,0);


   if(dy>dx) {
       temp=dx;
       dx=dy;
       dy=temp;
       inter=1;}

   else inter=0;

   e1=2*dy-dx;

   for(i=0;i<dx;i++){
       image.setPixel(x,y,value);

   while(e1>0){

        if(inter==1) x=x+s1;
        else y=y+s2;

        e1=e1-(2*dx);
        }

   if(inter==1) y=y+s2;
   else x+=s1;
   e1=e1+(2*dy);
  }
 return image;
}
