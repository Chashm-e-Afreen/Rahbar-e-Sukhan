import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls.Styles 1.4
import QtGraphicalEffects 1.15


    ColumnLayout {
        id: landing
        anchors.fill: parent
        anchors.topMargin: root.height * 0.25
        spacing: 30
        Rectangle {
            color: "#1a1a1a"
            id: card
            
            property font myFont: Qt.font({
                family: "Mehr Nastaliq Web",
                //        pointSize: 10
                fontSizeMode: Text.Fit,
            });
            layer.enabled: true
            layer.effect: DropShadow {
                color: "#5268f4"
                transparentBorder: true
                horizontalOffset: 1
                verticalOffset: 1
                radius: 7
            }
            //        width: 750
            Layout.preferredWidth: 0.8 * parent.width
            Layout.preferredHeight: 0.6 * parent.height
            radius: 10


            Layout.alignment: Qt.AlignHCenter
            

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
                anchors.fill: parent
                cursorShape: Qt.PointingHandCursor
                onContainsMouseChanged: {
                    card.state = containsMouse ? "mouseIn" : "mouseOut"
                }

            }

            ColumnLayout {
                anchors.fill: parent
                spacing: 20
            Text {
                id: eng
                text: "Fast, Multithreaded Automaton for Rhythm Detection and Correction in Urdu Poetry"
                color: "#fff"
                font.family: "Economica"
                wrapMode: Text.WordWrap
                Layout.preferredWidth: 400
                font.pixelSize: 30
                Layout.alignment: Qt.AlignHCenter
                // anchors.horizontalCenter: card.horizontalCenter
                // anchors.verticalCenter: root.verticalCenter
                // topPadding: 0.15 * root.height
            }

            Text {
                id: urd
                
                text: "عروض کے اصولوں کے مطابق اردو اشعار کے اوزان کی برق رفتار پشمائش۔"
                color: "#fff"
                font.family: "Mehr Nastaliq Web"
                font.pixelSize: 20
                font.wordSpacing: 6
                Layout.alignment: Qt.AlignHCenter
                // anchors.horizontalCenter: card.horizontalCenter
                // anchors.top: eng.bottom
            }

             Text {
                id: urd2
                // topPadding: 50
                text: "من جانب محمد ریحان قریشی"
                color: "#fff"
                font.family: "Mehr Nastaliq Web"
                font.pixelSize: 20
                font.wordSpacing: 6
                Layout.alignment: Qt.AlignHCenter
                // anchors.horizontalCenter: card.horizontalCenter
                // anchors.top: urd.bottom
            }
            
            }

        }

        Button {
                id: homeButton
                // anchors.horizontalCenter: root.horizontalCenter
                // anchors.top: card.bottom
                // anchors.topMargin: 10
                
                hoverEnabled: true
                text: "<font color='#ffe'>" + "Let's Go" + "</font>"
                font.family: "Economica"
                // font.wordSpacing: 4
                font.pointSize: 12
                Layout.preferredWidth : 200
                Layout.preferredHeight: 50
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
                        stack.pop(landing)
                        stack.push("home.qml")
                        
                    }

                }

            }

            Item { Layout.fillHeight: true }  
    }




