#ifndef GESTURE_H
#define GESTURE_H

#include "../mediapipe/mediapipe/landmarks_to_shm/landmarks_to_shm.h"
#include <QObject>

class Gesture : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString gestureID READ gestureID )
public:
    explicit Gesture(QObject *parent = nullptr);
    float *Get(float *array);
    QString gestureID();
};

#endif // GESTURE_H
