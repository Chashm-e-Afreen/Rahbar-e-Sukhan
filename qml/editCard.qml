import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls.Styles 1.4
import QtGraphicalEffects 1.15


Flow {
    height: canvas.height
    width: canvas.width
    id: outerFlow
    property int line_no;
    property int index2;
    // property int count;

    Layout.alignment: Qt.AlignHCenter

    ColumnLayout {
        height: canvas.height
        width: canvas.width
        Rectangle {
            color: "#1a1a1a"
            id: card

            property font myFont: Qt.font({
                family: "Mehr Nastaliq Web",
                fontSizeMode: Text.Fit,
            });
            layer.enabled: true
            layer.effect: DropShadow {
                color: "#000"
                transparentBorder: true
                horizontalOffset: 1
                verticalOffset: 1
                radius: 3
            }
            //        width: 750
            width: 0.95 * canvas.width
            height: 250
            radius: 10


            Layout.alignment: Qt.AlignHCenter


            Flow {
                id: myFlow
                topPadding: 20
                leftPadding: 20
                rightPadding: 20
                spacing: 0.075 * parent.width
                width: 0.9 * parent.width
                Layout.alignment: Qt.AlignCenter

                // anchors.centerIn: parent
                LayoutMirroring.enabled: true
                LayoutMirroring.childrenInherit: true
                Flow {
                    spacing: 30
                    //  
                    objectName: "outputText"
                    id: outputText
                }
                ColumnLayout {
                    Text {
                        Layout.alignment: Qt.AlignHCenter
                        color: "#5a67d8"
                        font: card.myFont
                        text: "بحر"
                    }
                    Text {
                        Layout.alignment: Qt.AlignHCenter
                        id: behr_name
                        color: "#fff"
                        //            text: "ہزج مثمن سالم"
                        font: card.myFont
                    }
                }
                ColumnLayout {
                    Text {
                        Layout.alignment: Qt.AlignHCenter
                        color: "#5a67d8"
                        font: card.myFont
                        text: "افاعیل"
                    }
                    Text {
                        id: afaeel
                        color: "#fff"
                        //            text: "ہزج مثمن سالم"
                        font: card.myFont
                    }
                }

                ColumnLayout {
                    Text {
                        Layout.alignment: Qt.AlignHCenter
                        color: "#5a67d8"
                        font: card.myFont
                        text: "روانی سکور"
                    }
                    Text {
                        Layout.alignment: Qt.AlignCenter
                        id: ravani_score
                        color: "#fff"
                        font.family: "Economica"
                        font.pixelSize: 18
                    }
                }
                

            }

            states: ["mouseIn", "mouseOut"]
            state: "mouseOut"

            transitions: [
                Transition {
                    from: "*"
                    to: "mouseIn"
                    NumberAnimation {
                        target: card
                        properties: "scale"
                        from: 1
                        to: 1.02
                        duration: 400
                        easing.type: Easing.InOutQuint
                    }
                },
                Transition {
                    from: "mouseIn"
                    to: "mouseOut"
                    NumberAnimation {
                        target: card
                        properties: "scale"
                        from: 1.02
                        to: 1
                        duration: 400
                        easing.type: Easing.InOutQuint
                    }
                }
            ]

            MouseArea {
                id: im1MouseArea
                hoverEnabled: true
                // anchors.fill: 
                width: parent.width
                height: parent.height
                cursorShape: Qt.PointingHandCursor
                onContainsMouseChanged: {
                    card.state = containsMouse ? "mouseIn" : "mouseOut"
                }
           
            }

        }

    }
}
