#ifndef STARRYNIGHT_H
#define STARRYNIGHT_H

#include <QMainWindow>
#include <iostream>
#include <QPainter>
#include <QMouseEvent>
using namespace std;

class Star
{
public:
    Star();
    void draw(QPainter*);
private:
    int x,y,s;
    QColor* starcolor;
};

class StarryNight : public QMainWindow
{
    Q_OBJECT

public:
    StarryNight(QWidget *parent = 0);
    void paintEvent(QPaintEvent* event);
    void mousePressEvent(QMouseEvent * event);

    ~StarryNight();

    Star* stars[100];
};

#endif // STARRYNIGHT_H
