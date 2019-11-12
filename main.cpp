#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "../mediapipe/mediapipe/landmarks_to_shm/landmarks_to_shm.h"

int main(int argc, char *argv[])
{
/*
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
*/
    //***********************************************************************//
    //# Gesture Library
    //* Discription:
    //  * screen as 256*256, u-v coordinate system
    //  * x= bounding box central u, y= bounding box central v, z= gestureID

    //* Create gesture a object:
    landmarks_to_shm::gesture ges;

    //* Get share memory array from shared library
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

    //* define gesture by command line interface
    ges.store_gestures3d(landmarks_datatype::gesture_path);
    //***********************************************************************//

    return 0;
}
