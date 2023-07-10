#include "starrynight.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StarryNight w;  //calls StarryNight::StarryNight

    cout<<"w is at address "<<&w<<endl;

    w.show();


//    StarryNight w2;

//    cout<<"w2 is at address "<<&w2<<endl;

//    w2.show();

    return a.exec();
}
