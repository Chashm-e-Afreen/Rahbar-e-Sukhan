import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls.Styles 1.4
import QtGraphicalEffects 1.15


RowLayout{
    TextField {
        placeholderText: "تدوین"
        placeholderTextColor: "#c9caca"
        color: "#c9caca"
        font: card.myFont
        background: Rectangle {
            implicitWidth: 200
            implicitHeight: 40
            color: "#252729"
            border.color: "#434c5e";
            radius: 10
        }
    }
    Button {
        id: button
        hoverEnabled: true
        text: "<font color='#ffe'>" + "ارسال" + "</font>"
        font.family: "Mehr Nastaliq Web"
        font.wordSpacing: 4
        font.pointSize: 12
        width: 100
        background: Rectangle {
            color: "#49a2d1"
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
                Dummy.edit_line(editField.text,line_no);
                var a = Dummy.send_meter(line_no);
                behr_name.text = a[0];
                afaeel.text = a[1];
                ravani_score.text = Dummy.ravani_score(line_no);
               var no_of_words = Dummy.no_of_words(line_no);
                for (let j=0; j<no_of_words; ++j) {
                    index2 = j;
                    var text = Qt.createComponent("text.qml");
                    text.createObject();
//                    outputText.children[j] = text;
                }
                stack.pop();
            }

        }
    }
}


