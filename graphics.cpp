#include "graphics.h"
#include <QPainter>
#include <math.h>
#include <unistd.h>
#include <Windows.h>
#include<dos.h>   //for delay()
#include<conio.h>

graphics::graphics(QWidget *parent) :
    QWidget(parent)
{
    position = 800;
    position1 = 0;
    timerId = startTimer(8);


}

void graphics::paintEvent(QPaintEvent *){
    QPainter painter(this);
    //Ve nen troi
    painter.setBrush(QBrush("ffffff"));//Set màu nền bầu trời
    painter.setPen(Qt::black);
    nen_troi(painter);

    phaohoa(painter,200,60);
    phaohoa(painter,480,80);
    phaohoa(painter,100,70);
    phaohoa(painter,550,200);
    phaohoa(painter,900,50);
    phaohoa(painter,620,100);
    phaohoa(painter,530,150);
    phaohoa(painter,457,170);
    phaohoa(painter,380,70);
    //-------------------------------

    nhatho(painter, 650, 550, 90);
    int h = height();
    int w = width();
    house_chungcu(painter, 20, 400, 70);
    house_chungcu(painter, 100, 450, 105);
    house_nocbang(painter, 0, 550, 50);
    house_nocbang(painter, 300, 500 + 50, 75);
    house_chungcu(painter, 750, 340, 210);
    house_nocbang(painter, 600, 550, 50);
    house_nocnhon(painter, 950, 300,80);
    house_nocnhon(painter, 250, 500,60);
    house_nocnhon(painter, 150, 300,120);
    painter.setBrush(QBrush("#1C1C1C"));
    house_nocnhon(painter, 550, 350,80);
    house_chungcu(painter, 280, 550, 75);
    house_chungcu(painter, 450, 450, 105);
    house_chungcu(painter, 340, 350, 140);


    drawExample(painter);


}

QPoint graphics::tinhtien(QPoint p, int tx, int ty){
    QPoint pnew;
    pnew.setX(p.x() + tx);
    pnew.setY(p.y() + ty);
    return pnew;
}

QPoint graphics::TrungDiem(QPoint a, QPoint b){
    return QPoint((a.x()+b.x())/2,(a.y()+b.y())/2);
}

//Ve nha
void graphics::house_nocnhon(QPainter& painter, int x, int y, int size){
    int h = height();
    int w = width();
    painter.setPen(Qt::black);
    painter.setBrush(QBrush("#000000"));
    QPolygon mainha;
    // Vẽ noc nhà cần 3 điểm
    QPoint p1, p2, p3;
    p1.setX(x);
    p1.setY(y);
    p2.setX(x + (size/2));
    p2.setY(y - (size/2));
    p3.setX(x + size);
    p3.setY(y);
    mainha << p1;
    mainha << p2;
    mainha << p3;
    //----------------------------------------

    // Ve than nha noc bang can 4 diem
    QPolygon thannha;
    QPoint p5,p6,p7,p8;
    p5.setX(x + (size/8));
    p5.setY(y);
    p6.setX(x+ 7*(size/8));
    p6.setY(y);
    p7.setX(x+ 7*(size/8));
    p7.setY(h);
    p8.setX(x + (size/8));
    p8.setY(h);
    thannha << p5;
    thannha << p6;
    thannha << p7;
    thannha << p8;
    painter.drawPolygon(thannha);
    painter.drawPolygon(mainha);
    painter.setBrush(QBrush("#8A4B08"));
    // cua so
    int width_cs = size/8;
    int height_cs = 2 * size/8;
    QPoint cuaso_trai, cuaso_phai;
    cuaso_trai.setX(x + 2*(size/8));
    cuaso_trai.setY(y + (size/8));
    QRect cuaso_tr(cuaso_trai.rx(), cuaso_trai.ry(), width_cs, height_cs);
    painter.drawRect(cuaso_tr);
    cuaso_phai.setX(x + 5*(size/8));
    cuaso_phai.setY(y + size/8);
    QRect cuaso_ph(cuaso_phai.rx(), cuaso_phai.ry(), width_cs, height_cs);
    painter.drawRect(cuaso_ph);
    for (int i = 0; i <= 20; i++){
        cuaso_trai = tinhtien(cuaso_trai, 0, 5*(size/8));
        QRect cuaso_tr(cuaso_trai.rx(), cuaso_trai.ry(), width_cs, height_cs);
        painter.drawRect(cuaso_tr);
        cuaso_phai = tinhtien(cuaso_phai, 0, 5*(size/8));
        QRect cuaso_ph(cuaso_phai.rx(), cuaso_phai.ry(), width_cs, height_cs);
        painter.drawRect(cuaso_ph);
    }
}

void graphics::house_nocbang(QPainter& painter, int x, int y, int size){
    int h = height();
    int w = width();
    painter.setPen(Qt::black);
    painter.setBrush(QBrush("#000000"));
    QPolygon mainha;
    // Vẽ noc nhà cần 4 điểm
    QPoint p1, p2, p3, p4;
    p1.setX(x);
    p1.setY(y);
    p2.setX(x + (size/5));
    p2.setY(y - (size/5));
    p3.setX(x + 4*(size/5));
    p3.setY(y - (size/5));
    p4.setX(x + size);
    p4.setY(y);
    mainha << p1;
    mainha << p2;
    mainha << p3;
    mainha << p4;
    //----------------------------------------

    // Ve than nha noc bang can 4 diem
    QPolygon thannha;
    QPoint p5,p6,p7,p8;
    p5.setX(x);
    p5.setY(y);
    p6.setX(x+size);
    p6.setY(y);
    p7.setX(x+size);
    p7.setY(h);
    p8.setX(x);
    p8.setY(h);
    mainha << p5;
    mainha << p6;
    mainha << p7;
    mainha << p8;

    //Ve cua so nha noc bang
    QRect   cuaso1(x + size/5, y + (size/5), size/5, 2 * (size/5));
    QRect   cuaso2(x + 3*(size/5), y + (size/5), size/5, 2 * (size/5));

//    QPolygon cuaso;
//    QPoint p9,p10,p11,p12;
//    p9.setX(x + size/5);
//    p9.setY(y + size/5);
//    p10.setX(x + 2*(size/5));
//    p10.setY(y + size/5);
//    p11.setX(x + 2*(size/5));
//    p11.setY( y + 3*(size/5));
//    p12.setX(x + size/5);
//    p12.setY(y + 3*(size/5));
//    cuaso << p9;
//    cuaso << p10;
//    cuaso << p11;
//    cuaso << p12;
    painter.drawPolygon(thannha);
    painter.drawPolygon(mainha);
    painter.setBrush(QBrush("#3B170B"));
    painter.drawRect(cuaso1);
    painter.drawRect(cuaso2);

}

void graphics::house_chungcu(QPainter& painter, int x, int y, int size){
    int h = height();
    int w = width();
    painter.setPen(Qt::black);
    painter.setBrush(QBrush("#000000"));
    QPolygon mainha;
    // Vẽ noc nhà cần 4 điểm
    QPoint p1, p2, p3, p4, p5, p6, p7, p8;
    p1.setX(x);
    p1.setY(y);
    p2 = tinhtien(p1, 0, size/14);
    p3 = tinhtien(p1, size/14, 0);
    p4 = tinhtien(p1, size, 0);
    p5 = tinhtien(p4, -size/14, 0);
    p6 = tinhtien(p4, 0, size/14);
    p7.setX(x + size);
    p7.setY(h);
    p8.setX(x);
    p8.setY(h);
    mainha << p2;
    mainha << p3;
    mainha << p5;
    mainha << p6;
    mainha << p7;
    mainha << p8;
    
    painter.drawPolygon(mainha);
    painter.setBrush(QBrush("#3B170B"));
    //----------------------------------------

    //Ve cua so nha chung cu (n cua so - chay for)
    int width, height;
    width = size/7;
    height = size/7;
    QPoint cs;
    cs.setX(x+size/7);
    cs.setY(y+size/7);
    QRect cuaso(cs.rx(), cs.ry(), width, height);
    painter.drawRect(cuaso);
    QPoint cs1 = cs;
    for (int i=0; i<= 100; i++){
        cs1 = tinhtien(cs1,2*(size/7),0);
        if(cs1.rx()>=x+size){
            cs1 = tinhtien(cs, 0, 2*(size/7));
            cs = tinhtien(cs,0, 2*(size/7));
            QRect cuaso(cs1.rx(), cs1.ry(), width, height);
            QPoint w1,w2,w3,w4;
            w1 = tinhtien(cs1,(1/2)*width,0);
            w2 = tinhtien(cs1, width, (1/2)*height);
            w3 = tinhtien(cs1, (1/2)*width, height);
            w4 = tinhtien(cs1, 0, (1/2)*height);
            painter.drawRect(cuaso);
            painter.setPen(Qt::black);
            painter.drawLine(w1,w3);
            painter.drawLine(w2,w4);
        }else{
            QRect cuaso(cs1.rx(), cs1.ry(), width, height);
            QPoint w1,w2,w3,w4;
            w1 = tinhtien(cs1,(1/2)*width,0);
            w2 = tinhtien(cs1, width, (1/2)*height);
            w3 = tinhtien(cs1, (1/2)*width, height);
            w4 = tinhtien(cs1, 0, (1/2)*height);
            painter.drawRect(cuaso);
            painter.setPen(Qt::black);
            painter.drawLine(w1,w3);
            painter.drawLine(w2,w4);

        }

    }

}

//Ve nha tho
void graphics::nhatho(QPainter &painter, int x, int y, int size){
    int h = height();
    int w = width();
    painter.setPen(Qt::black);
    painter.setBrush(QBrush("#000000"));
    QPolygon mainha;
    // Vẽ noc nhà cần 3 điểm
    QPoint p1, p2, p3;
    p1.setX(x);
    p1.setY(y);
    p2.setX(x + (size/2));
    p2.setY(y - size);
    p3.setX(x + size);
    p3.setY(y);
    mainha << p1;
    mainha << p2;
    mainha << p3;
    //----------------------------------------

    // ---------------------------------------
    // Ve than nha noc bang can 4 diem
    QPolygon thannha;
    QPoint p5,p6,p7,p8,p9,p10,p11,p12,p13,p14;
    p5.setX(x + (size/8));
    p5.setY(y);
    p6.setX(x + 7*(size/8));
    p6.setY(y);
    p7.setX(x + 7*(size/8));
    p7.setY(y + size/8);
    p8.setX(x+ 24*(size/8));
    p8.setY(y + size/8);
    p9.setX(x+ 24*(size/8));
    p9.setY(h);
    p10.setX(x + (size/8));
    p10.setY(h);
    thannha << p5;
    thannha << p6;
    thannha << p7;
    thannha << p8;
    thannha << p9;
    thannha << p10;
    painter.drawPolygon(thannha);
    painter.drawPolygon(mainha);
    painter.setBrush(QBrush("#3B170B"));
    // cua so
    int width_cs = 2*size/8;
    int height_cs = 3 * size/8;
    QPoint cuaso_trai, cuaso_phai;
    cuaso_trai.setX(x + 3*(size/8));
    cuaso_trai.setY(y + (size/8));
    QRect cuaso_tr(cuaso_trai.rx(), cuaso_trai.ry(), width_cs, height_cs);
    painter.drawRect(cuaso_tr);
}



//Ve nen
void graphics::nen_troi(QPainter &painter){
    painter.setBrush(QBrush("#2a0a1b"));
    double h=height();
    double w=width();
    painter.drawRect(0,0,w,h);//Set kích thước màu nền toàn màn hình
//    int h=height()/2;
//    int w=width()/2;
//    QRadialGradient grad1(h/4,position, 100);
//    grad1.setColorAt(0.2, QColor("#FF6600"));//khai báo dải màu 1
//    grad1.setColorAt(0.4, QColor("#FF3333"));//khai báo dải màu 2
//    grad1.setColorAt(1, QColor("#CCFFFF"));//khai báo dải màu 3
//    for (int i=1; i<=50;i++){
//        painter.setPen(Qt::NoPen);
//        painter.setBrush(QColor(random(255), random(255), random(255)));
//        painter.drawEllipse(random(1000),random(1000), 3,3);
//    }
//    int x = 200;
//    int y = 50;
    int x = 1200;
    int y = 450;
    for(int i; i <= 30; i++){
    painter.setPen(Qt::NoPen);
    painter.setBrush(QColor(random(255),random(255),random(255)));
    painter.drawEllipse(random(x),random(y),3,3);

    }
//    painter.setBrush(QColor(random(255),random(255),random(255)));//định nghĩa màu
//    painter.drawEllipse(x,4*y,4,4);//vẽ ellipse đổi màu liên tục tại vị trí cho trước
//    painter.drawEllipse(x,y,4,4);//vẽ ellipse đổi màu liên tục tại vị trí cho trước
//    painter.drawEllipse(x+100,3*y,4,4);//vẽ ellipse đổi màu liên tục tại vị trí cho trước
//    painter.drawEllipse(x+200,y,4,4);//vẽ ellipse đổi màu liên tục tại vị trí cho trước
//    painter.drawEllipse(x+300,3*y,4,4);//vẽ ellipse đổi màu liên tục tại vị trí cho trước
//    painter.drawEllipse(x+500,2*y+15,4,4);//vẽ ellipse đổi màu liên tục tại vị trí cho trước
//    painter.drawEllipse(4*x,y+20,4,4);//vẽ ellipse đổi màu liên tục tại vị trí cho trước
//    painter.drawEllipse(3*x+50,3*y+10,4,4);//vẽ ellipse đổi màu liên tục tại vị trí cho trước
//    painter.drawEllipse(x+120,4*y,4,4);//vẽ ellipse đổi màu liên tục tại vị trí cho trước
//    painter.drawEllipse(2*x+150,3*y+30,4,4);//vẽ ellipse đổi màu liên tục tại vị trí cho trước
//    painter.drawEllipse(x+70,2*y+30,4,4);//vẽ ellipse đổi màu liên tục tại vị trí cho trước
//    painter.drawEllipse(x-150,y-30,4,4);//vẽ ellipse đổi màu liên tục tại vị trí cho trước
//    painter.drawEllipse(x-130,y,4,4);//vẽ ellipse đổi màu liên tục tại vị trí cho trước
//    painter.drawEllipse(4*x+100,y-10,4,4);//vẽ ellipse đổi màu liên tục tại vị trí cho trước
//    painter.drawEllipse(5*x,y+10,4,4);//vẽ ellipse đổi màu liên tục tại vị trí cho trước
//    painter.drawEllipse(2*x+100,y-20,4,4);//vẽ ellipse đổi màu liên tục tại vị trí cho trước

//    painter.drawEllipse(4.34*x,y+75,4,4);//vẽ ellipse đổi màu liên tục tại vị trí cho trước
//    painter.drawEllipse(3*x+10,3*y+60,4,4);//vẽ ellipse đổi màu liên tục tại vị trí cho trước
//    painter.drawEllipse(x+70,3.2*y,4,4);//vẽ ellipse đổi màu liên tục tại vị trí cho trước
//    painter.drawEllipse(2*x+110,3.34*y+30,4,4);//vẽ ellipse đổi màu liên tục tại vị trí cho trước
//    painter.drawEllipse(x+170,2*y+70,4,4);//vẽ ellipse đổi màu liên tục tại vị trí cho trước
//    painter.drawEllipse(x-120,y-60,4,4);//vẽ ellipse đổi màu liên tục tại vị trí cho trước
//    painter.drawEllipse(x-230,y+40,4,4);//vẽ ellipse đổi màu liên tục tại vị trí cho trước
//    painter.drawEllipse(4*x+160,y-20,4,4);//vẽ ellipse đổi màu liên tục tại vị trí cho trước
//    painter.drawEllipse(4.7*x,y+110,4,4);//vẽ ellipse đổi màu liên tục tại vị trí cho trước
//    painter.drawEllipse(2*x+10,y-50,4,4);//vẽ ellipse đổi màu liên tục tại vị trí cho trước
}


void graphics::thap_dongho(QPainter &painter, int x, int y, int size){
     int width = size;
     QPolygon tru_nhon_to;
     QPoint p1,p2,p3,p4,p5;
     p1.setX(x);
     p1.setY(y);
     p2 = tinhtien(p1, (1/5)*width, (2/5)*width);
     p3 = tinhtien(p2, 0, (2/5)*width);
     p4 = tinhtien(p3, (-2/5)*width, 0);
     p5 = tinhtien(p4, 0, -(2/5)*width);
     tru_nhon_to << p1;
     tru_nhon_to << p2;
     tru_nhon_to << p3;
     tru_nhon_to << p4;
     tru_nhon_to << p5;


     // Ve 2 tru 2 ben
     QPolygon tru_nho_trai, tru_nho_phai;
     QPoint p6,p7,p8,p9,p10,p11,p12,p13,p14,p15;
     p6.setX(x - (2/5)*width);
     p6.setY(y + (4/5)*width);
     p7.setX(p6.rx());
     p7.setY(p6.ry() - (1/10)*width);
     p8.setX(p6.rx() + (1/10)*width);
     p8.setY(p6.ry() - (1/5)*width);
     p9.setX(p6.rx() + (1/5)*width);
     p9.setY(p6.ry() - (1/10)*width);
     p10 = p1;
     tru_nho_trai << p6;
     tru_nho_trai << p7;
     tru_nho_trai << p8;
     tru_nho_trai << p9;
     tru_nho_trai << p10;
     p11 = tinhtien(p6, (3/5)*width, 0);
     p12 = tinhtien(p7, (3/5)*width, 0);
     p13 = tinhtien(p8, (3/5)*width, 0);
     p14 = tinhtien(p9, (3/5)*width, 0);
     p15 = tinhtien(p10, (3/5)*width, 0);
     tru_nho_phai << p11;
     tru_nho_phai << p12;
     tru_nho_phai << p13;
     tru_nho_phai << p14;
     tru_nho_phai << p15;

     // Ve mat vuong toa thap
     QPolygon mat_vuong;
     QPoint p16, p17, p18, p19, p20;
     p16.setX(x - (1/2)*width);
     p16.setY(y + (9/5)*width);
     p17 = tinhtien(p16, 0, -width);
     p18 = tinhtien(p17, width, 0);
     p19 = tinhtien(p18, 0, width);
     mat_vuong << p16;
     mat_vuong << p17;
     mat_vuong << p18;
     mat_vuong << p19;

     painter.setBrush(QBrush("#000000"));
//     painter.setPen(Qt::black);
     painter.drawPolygon(tru_nhon_to);
//     painter.drawLine(p3,p1);
//     painter.drawPoint(p1.rx(),p1.ry());
//     painter.drawPolygon(tru_nho_trai);
//     painter.drawPolygon(tru_nho_phai);
//     painter.drawPolygon(mat_vuong);y

}


void graphics::nen_dat(QPainter &painter){
    double h=height();
    double w=width();
    //Set kích thước màu nền toàn màn hình
    painter.drawRect(0,4 *(h/5),w,h);//Set kích thước màu nền toàn màn hình
//    int h=height()/2;
//    int w=width()/2;
//    QRadialGradient grad1(h/4,position, 100);
//    grad1.setColorAt(0.2, QColor("#FF6600"));//khai báo dải màu 1
//    grad1.setColorAt(0.4, QColor("#FF3333"));//khai báo dải màu 2
//    grad1.setColorAt(1, QColor("#CCFFFF"));//khai báo dải màu 3
}

//QPointF graphics::dichuyen(QPointF p, double kc, float huong){
//    QPointF pnew;
//    pnew.setX(p.x()+kc*cos(M_PI*huong/180.0));
//    pnew.setY(p.y()+kc*sin(M_PI*huong/180.0));
//    return pnew;
//}


void graphics::timerEvent(QTimerEvent *){
    position = position -1;
    position1 += 5;
    if (position == 0) position = 800;

    if (position1 > 1000){
        position1 = 0;
    }
    repaint();
}

int graphics::random(int n){
    return rand() %n;
}


QPointF graphics::dichuyen(QPointF p, double kc, float huong){
    QPointF pnew;
    pnew.setX(p.x()+kc*cos(M_PI*huong/180.0));
    pnew.setY(p.y()+kc*sin(M_PI*huong/180.0));
    return pnew;
}
void graphics::phaohoa(QPainter &painter, int bdau, int no){
    QPointF a(bdau,position);
    painter.setPen(QColor("#0000000"));
    painter.setBrush(QBrush("#664d4b"));
    BD.setX(bdau);
    BD.setY(no);
    QPointF pnew;
    float huong = -90.0;
    if (position > no) {
        painter.drawEllipse(a,3,3);
        float huong = 85;
        if ((position <= (no*9))&&(position > no*4/3)){
//            for (int i = 0;i < 4; i++) {
//                pnew=dichuyen(a,position1 - no*2, huong);
//                painter.drawEllipse(pnew,3,3);
//            }
//            for (int i = 0;i < 3; i++) {
//                painter.setBrush(QBrush("#f28f17"));
//                pnew=dichuyen(a,position - no*2, huong + 35);
//                painter.drawEllipse(pnew,3,3);
//            }
            for (int i = 0;i < 25; i++) {
                    painter.setBrush(QBrush("#f28f17"));
                    pnew=dichuyen(a,position1 - no*i, huong + 35);
                    painter.drawEllipse(pnew,3,3);

                }
        }
    }
    if (position <= no*4/3)
        for (int i=0; i <3 ; i++){
        hieuungphaohoa1(painter,bdau+2*no*tan(20)/3,no*4/3,50,position - no-no/3 +i/2);
        }
   if (position <= no){
        for (int i=0; i <3 ; i++){
            hieuungphaohoa2(painter,bdau,no,25,position - no +i/2);
        }
        for (int i=0; i <3 ; i++){
            hieuungphaohoa1(painter,bdau,no,40,position - no +i/2);
            hieuungphaohoa3(painter,bdau,no,40,position - no +i/2);
        }
        for (int i=0; i <3 ; i++){
            hieuungphaohoa3(painter,bdau,no,40,position - no +i/2);
        }
   }
}
void graphics::hieuungphaohoa1(QPainter &painter,int a, int b, float n, int x){
    painter.setPen(QColor(random(255),random(255),random(255)));
//    painter.setBrush(QColor(random(255),random(255),random(255)));
    painter.setBrush(QColor("#ffa200"));
    BD.setX(a);
    BD.setY(b);
    QPointF pnew;
    float huong=-90;
    for (int i=0;i<n;i++) {
        pnew = dichuyen(BD,-x,huong);
        huong += 360/n;
        painter.drawEllipse(pnew,3,3);
    }
}
void graphics::hieuungphaohoa2(QPainter& painter, int a, int b, float n, int x){
    painter.setPen(QColor("#efed33"));
    painter.setBrush(QColor("#ad6d0e"));
    QPointF BD1(a,b);
    QPointF pnew;
    float huong=-90;
    for (int i=0;i<n;i++) {
        pnew = dichuyen(BD1,-x,huong);
        bongtuyet(painter,pnew,20);
        huong += 360.0/n;
    }

}
void graphics::hieuungphaohoa3(QPainter& painter, int a, int b, float n, int x){
    painter.setPen(QColor(random(255),random(255),random(10)));

    BD.setX(a);
    BD.setY(b);
    QPointF pnew;
    float huong=-60;
    for (int i=0;i<n;i++) {
        pnew = dichuyen(BD,-x*3,huong);
        huong += 360/n;
        painter.drawEllipse(pnew,2,2);
    }

}

void graphics::bongtuyet(QPainter& painter,QPointF Q,int L){
    QPointF P;
    float huong1=-30;
    for(int i=0;i<=5;i++){
        P=dichuyen(Q,L/25,huong1);
        BD=P;
        P=dichuyen(P,L*4/10,huong1+30);
        painter.drawLine(BD,P);
        BD=P;
        P=dichuyen(P,L*3/10,huong1-30);
        painter.drawLine(BD,P);
        BD=P;
        P=dichuyen(P,L/40,huong1+60);
        painter.drawLine(BD,P);
        BD=P;
        P=dichuyen(P,(L*3/10)-(L/40/sqrt(3)),huong1+150);
        painter.drawLine(BD,P);
        BD=P;
        P=dichuyen(P,L*2/10,huong1+30);
        painter.drawLine(BD,P);
        BD=P;
        P=dichuyen(P,L*2/10,huong1-30);
        painter.drawLine(BD,P);
        BD=P;
        P=dichuyen(P,L/40,huong1+60);
        painter.drawLine(BD,P);
        BD=P;
        P=dichuyen(P,(L*2/10)-(L/40/sqrt(3)),huong1+150);
        painter.drawLine(BD,P);
        BD=P;
        P=dichuyen(P,L*2/10,huong1+30);
        painter.drawLine(BD,P);
        BD=P;
        P=dichuyen(P,L/40,huong1+75);
        painter.drawLine(BD,P);
        huong1+=-360.0/6;
    }
    huong1=30;
    for (int i=0;i<=5;i++){
        P=dichuyen(Q,L/25,huong1);
        BD=P;
        P=dichuyen(P,L*4/10,huong1-30);
        painter.drawLine(BD,P);
        huong1+=-360.0/6;
        BD=P;
        P=dichuyen(P,L*3/10,huong1+90);
        painter.drawLine(BD,P);
        BD=P;
        P=dichuyen(P,L/40,huong1);
        painter.drawLine(BD,P);
        BD=P;
        P=dichuyen(P,(L*3/10)-(L/40/sqrt(3)),huong1-90);
        painter.drawLine(BD,P);
        BD=P;
        P=dichuyen(P,L*2/10,huong1+30);
        painter.drawLine(BD,P);
        BD=P;
        P=dichuyen(P,L*2/10,huong1+90);
        painter.drawLine(BD,P);
        BD=P;
        P=dichuyen(P,L/40,huong1);
        painter.drawLine(BD,P);
        BD=P;
        P=dichuyen(P,(L*2/10)-(L/40/sqrt(3)),huong1-90);
        painter.drawLine(BD,P);
        BD=P;
        P=dichuyen(P,L*2/10,huong1+30);
        painter.drawLine(BD,P);
        BD=P;
        P=dichuyen(P,L/40,huong1-15);
        painter.drawLine(BD,P);
    }
}


void graphics::drawExample(QPainter& painter){
    int r = 100;
    int h = height();
    painter.setBrush(QBrush("#b40000"));
    QString link6 = "D://roadd.png";
    painter.drawPixmap(0, h, 9.4*r, 6*r, QPixmap(link6));

}
