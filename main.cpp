#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "../mediapipe/mediapipe/landmarks_to_shm/landmarks_to_shm.h"
#include "gesturelibrary.h"
#include "gesture.h"
#include <QDebug>

int main(int argc, char *argv[])
{

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    //qDebug()<<GestureLibrary::instance()->GetgestureID();
    qmlRegisterType<Gesture>("gesture",1,0,"Gesture");

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    engine.load(url);
    return app.exec();

}
