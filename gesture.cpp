#include "gesture.h"
#include <QDebug>
Gesture::Gesture(QObject *parent):
    QObject(parent)
{

}

float *Gesture::Get(float *array){
    //# Gesture Library
    //* Discription:
    //  * screen as 256*256, u-v coordinate system
    //  * x= bounding box central u, y= bounding box central v, z= gestureID

    //* Create gesture a object:
    landmarks_to_shm::gesture ges;

    //* Get share memory array rom shared library
    //  * open the managed segment

    boost::interprocess::managed_shared_memory segment(
        boost::interprocess::open_or_create,
        landmarks_datatype::shm_name,
        landmarks_datatype::shm_size);

    //  * find the share memory array
    landmarks_datatype::coordinate3d_t *_bbCentral_ptr = segment.find<landmarks_datatype::coordinate3d_t>(
        landmarks_datatype::bbCentral_name).first;

    //* get bounding box central u
    float u = _bbCentral_ptr[0].x;

    //* get bounding box central v
    float v = _bbCentral_ptr[0].y;

    //* Get gestureID
    //  * if id=-1 not a predefined gesture
    //  * else id=0~31 is a predefined gesture
    int gestureID = (int)_bbCentral_ptr[0].z;

    array[0] = u;
    array[1] = v;
    array[2] = (float)gestureID;
    return array;

}
QString Gesture::gestureID(){

    float msg[3];
    Gesture::Get(msg);

    QString u = QString::number(msg[0]);
    QString v = QString::number(msg[1]);
    QString ID = QString::number((int)msg[2]);
    QString Message = "u: "+u+"\nv: "+v+"\nID:"+ID;

    return Message;
}
