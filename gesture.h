#ifndef GESTURE_H
#define GESTURE_H

#include "gesturelibrary.h"
#include <QObject>

class Gesture : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString gestureID READ gestureID )
public:
    explicit Gesture(QObject *parent = nullptr);
    QString gestureID();
};

#endif // GESTURE_H
