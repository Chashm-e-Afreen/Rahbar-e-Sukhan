import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls.Styles 1.4
//import Dummy 1.0


Item {

    ColumnLayout {
        anchors.fill: parent
        id: col

        Flickable {
            id: flickable
            Layout.alignment: Qt.AlignCenter
            Layout.preferredHeight: 0.3 * col.height
            Layout.preferredWidth: 0.65 * col.height
            flickableDirection: Flickable.VerticalFlick

            ScrollBar.vertical: ScrollBar {}

            TextArea.flickable: TextArea {
                id: textArea
                objectName: "txt"
                textMargin: 10
                font.family: "Mehr Nastaliq Web"
                font.wordSpacing: 6
                font.pointSize: 13
                Layout.maximumHeight: 0.3 * col.height
                color: "#f3f7fd"
                horizontalAlignment: TextEdit.AlignRight

                background: Rectangle {
                    implicitWidth: parent.width
                    radius: 4
                    height: 0.3 * col.height
                    color: "#18191b"
                    border.color: "#434c5e";
                }
                selectByMouse: true
            }

        }

    }

    Button {
        id: button
        //        objectName: button
        anchors.horizontalCenter: col.horizontalCenter
        y: col.height - 0.3*col.height
        hoverEnabled: true
        //        signal qmlSignal(msg: string)
        //        property alias TextArea: textArea.text
        text: "<font color='#ffe'>" + "ارسال" + "</font>"
        font.family: "Mehr Nastaliq Web"
        font.wordSpacing: 4
        font.pointSize: 12
        width: 100
        background: Rectangle {
            color: "#5268f4"
            radius: 3
        }



        MouseArea {
            id: mouse
            anchors.fill: parent
            hoverEnabled: true
            cursorShape: Qt.PointingHandCursor


            onClicked: {
                var anim = Qt.createComponent("busy.qml");
                anim.createObject();
                stack.push(anim);
                Dummy.con_init(textArea.text);
                var output_canvas = Qt.createComponent("output.qml");
                stack.pop();
                stack.push(output_canvas);
            }

        }



    }

}



