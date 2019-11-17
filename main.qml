import QtQuick 2.10
import QtQuick.Window 2.10
import gesture 1.0


Window {
    visible: true
    width: 640
    height: 480

    Gesture{
        id:ges
    }
    Timer {
        interval: 1000
        repeat:true
        running: true
        onTriggered: {
            t1.text = ges.gestureID;
        }
    }
    Text{
      id:t1
      anchors.centerIn: parent

      text:"test"
    }
}
