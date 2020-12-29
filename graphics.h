#ifndef GRAPHICS_H
#define GRAPHICS_H
#include <QWidget>
#include <math.h>

class graphics : public QWidget
{
    Q_OBJECT
public:
//    explicit graphics(QWidget *parent = nullptr);
    explicit graphics(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    //ham tinh tien
    QPoint tinhtien(QPoint p, int tx, int ty);
    QPoint TrungDiem(QPoint a, QPoint b);
    //Ham ve nen troi
    void nen_troi(QPainter& painter);
    //Ham ve nen dat
    void nen_dat(QPainter& painter);
    //Ham ve nha
    void house_nocbang(QPainter& painter, int x, int y, int size);
    void house_nocnhon(QPainter& painter, int x, int y, int size);
    void house_chungcu(QPainter& painter, int x, int y, int size);
    void nhatho(QPainter& painter, int x, int y, int size);
    void thap_dongho(QPainter& painter, int x, int y, int size);
    QPointF dichuyen(QPointF p, double kc, float huong);
    int random(int n);
    double timerId;
    void timerEvent(QTimerEvent *);
    double position, position1;
    int a,b;
    double b1;
    QPointF BD;
    void phaohoa(QPainter& painter, int bdau, int no);
    void bongtuyet(QPainter& painter,QPointF Q,int L);
    void hieuungphaohoa1(QPainter &painter, int a, int b, float n, int x);
    void hieuungphaohoa2(QPainter &painter, int a, int b, float n, int x);
    void hieuungphaohoa3(QPainter &painter, int a, int b, float n, int x);
    void drawExample(QPainter& painter);

signals:

public slots:

};

#endif // GRAPHICS_H
