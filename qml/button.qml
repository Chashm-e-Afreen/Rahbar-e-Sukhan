import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Button {
    id: backButton
    anchors.horizontalCenter: canvas.horizontalCenter
    hoverEnabled: true
    text: "<font color='#ffe'>" + "واپس جائیں" + "</font>"
    font.family: "Mehr Nastaliq Web"
    font.wordSpacing: 4
    font.pointSize: 12
    width: 100
    background: Rectangle {
        color: "#5268f4"
        radius: 3
    }
    // Layout.alignment: Qt.AlignHCenter
    MouseArea {
        id: mouse
        anchors.fill: parent
        hoverEnabled: true
        cursorShape: Qt.PointingHandCursor
        onClicked: {
            if (stack.children.length === 3) {
                stack.push(canvas);
                stack.pop(col1);
            } else {
                stack.pop();
            }
        }

    }

}
