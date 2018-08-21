import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Rectangle {
        width: 360
        height: 360

        MouseArea {
            anchors {fill: parent; margins: 40}
            onClicked: console.log("hello from below");
        }

        MouseArea {
            id: mouseArea
            anchors.fill: parent

            onClicked: {
                console.log("hello from top")
                forwardEvent(mouse, "clicked");
            }

            function forwardEvent(event, eventType) {
                mouseArea.visible = false
                var item = parent.childAt(event.x, event.y)
                mouseArea.visible = true
                if (item && item != mouseArea && typeof(item[eventType]) == "function") {
                    item[eventType](event);
                }
            }
        }
    }
}
