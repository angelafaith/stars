#include "starrynight.h"

const int W=1200,H=800;

Star::Star()
{
    x=rand()%W;
    y=rand()%H;
    s=rand()%50+10;
    starcolor=new QColor(rand()%80+175,rand()%80+175,rand()%80+175);

}

void Star::draw(QPainter* paint)
{
    paint->setPen(*starcolor);
    paint->drawLine(x-s/2,y-s/2,x+s/2,y+s/2);
    paint->drawLine(x+s/2,y-s/2,x-s/2,y+s/2);
    paint->drawLine(x,y-s/2,x,y+s/2);
    paint->drawLine(x-s/2,y,x+s/2,y);
}

//constructor:
//runs once at beginning of program
StarryNight::StarryNight(QWidget *parent)
    : QMainWindow(parent)
{
    //initialization stuff here
    for(int starnum=0; starnum<100; starnum++)
        stars[starnum]=new Star();

    resize(W,H);
}

void StarryNight::mousePressEvent(QMouseEvent * event )
{
    int x=event->x();
    int y=event->y();
    cout << "mouse click at "<<x<<" "<<y<<endl;
}


//called by OS,
void StarryNight::paintEvent(QPaintEvent* event)
{
    cout<<"paint event just ran"<<endl;
    //redraw your window here
    QPainter* paint=new QPainter(this);
    //this == pointer to object I'm acting on
    cout<<"this is "<<this<<endl;

    paint->fillRect(0,0,W,H,QColor(0,0,0));

   for(int starnum=0; starnum<100; starnum++)
        stars[starnum]->draw(paint);

//    paint->drawLine()
/*    for(int starnum=0; starnum<100; starnum++)
    {
        int x=rand()%W;
        int y=rand()%H;
        int s=rand()%50+10;
        QColor starcolor(rand()%80+175,rand()%80+175,rand()%80+175);
        paint->setPen(starcolor);
        paint->drawLine(x-s/2,y-s/2,x+s/2,y+s/2);
        paint->drawLine(x+s/2,y-s/2,x-s/2,y+s/2);
        paint->drawLine(x,y-s/2,x,y+s/2);
        paint->drawLine(x-s/2,y,x+s/2,y);
    }*/
}

StarryNight::~StarryNight()
{

}
