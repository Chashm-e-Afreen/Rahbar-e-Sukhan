import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls.Styles 1.4

ColumnLayout {
    width: root.width
    height: 450
    spacing: 10

    id: edit
    property var myArray: []
    children: [outerFlow, row, button1]

    Button {
        id: button1
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
        Layout.alignment: Qt.AlignHCenter
        MouseArea {
            id: mouse
            anchors.fill: parent
            hoverEnabled: true
            cursorShape: Qt.PointingHandCursor
            onClicked: {
                // card.Layout.alignment = Qt.AlignHCenter
                myArray = Array.from(canvas.children);
                myArray.splice(line_no+1,0,outerFlow);
                canvas.children = myArray;
                stack.pop();
            }

        }

    }


    RowLayout{
        id: row
        layoutDirection: Qt.RightToLeft
        Layout.alignment: Qt.AlignHCenter
        TextField {
            id: editField
            placeholderText: "تدوین"
            // placeholderTextColor: "#c9caca"
            color: "#fff"
            font.family: "Mehr Nastaliq Web"
            font.wordSpacing: 6
            background: Rectangle {
                implicitWidth: 400
                // implicitHeight: 60
                color: "#252729"
                border.color: "#434c5e";
                radius: 4
            }
        }
        Button {
            id: submitButton
            hoverEnabled: true
            text: "<font color='#ffe'>" + "ارسال" + "</font>"
            font.family: "Mehr Nastaliq Web"
            font.wordSpacing: 4
            font.pixelSize: 16
            
            width: 100
            height: 60
            background: Rectangle {
                color: "#616beb"
                radius: 3
            }
            MouseArea {
                id: mouse1
                anchors.fill: parent
                hoverEnabled: true
                cursorShape: Qt.PointingHandCursor
                onClicked: {
                    var anim = Qt.createComponent("busy.qml");
                    anim.createObject();
//                    stack.push(anim);
                    Dummy.edit_line(editField.text,line_no);
                    var a = Dummy.send_meter(line_no);
                    behr_name.text = a[0];
                    afaeel.text = a[1];
                    ravani_score.text = Dummy.ravani_score(line_no);
                    var no_of_words = Dummy.no_of_words(line_no);
                    outputText.children = [];
                    for (let j=0; j<no_of_words; ++j) {
                        index2 = j;
                        var text = Qt.createComponent("text.qml");
                        text.createObject(outputText);
                    }
//                    stack.pop();
                }

            }
        }
    }
}


