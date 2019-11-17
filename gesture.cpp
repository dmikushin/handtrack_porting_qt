#include "gesture.h"
#include <QDebug>
Gesture::Gesture(QObject *parent):
    QObject(parent)
{

}


QString Gesture::gestureID(){
    QString ID = QString::number(GestureLibrary::instance()->GetgestureID() );
    qDebug()<<ID;
    return ID;
}
