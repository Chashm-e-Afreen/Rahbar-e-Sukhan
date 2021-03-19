import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls.Styles 1.4
//import Dummy 1.0

ApplicationWindow {
    id: root
    visible: true
    minimumWidth : 800
    minimumHeight: 600
    color: "#1c1e21"

    FontLoader{ name: "Mehr Nastaliq Web";  source: "qrc:/Files/mehr.ttf"}
    FontLoader{ name: "Economica";  source: "qrc:/Files/Economica.ttf"}
    //    header: ToolBar {
    //        height: 0.05 * root.height
    //        background: Rectangle {
    //            implicitWidth: parent.width
    //            color: "#1c1e21"
    //        }
    //        RowLayout {

    //            anchors.fill: parent
    //            Label {
    //                text: "اختیارات"
    //                elide: Label.ElideRight
    //                horizontalAlignment: Qt.AlignRight
    //                Layout.fillWidth: true
    //                rightPadding: 20
    //                font.family: "Mehr Nastaliq Web"
    //                font.wordSpacing: 4
    //                font.pointSize: 12
    //                color: "#99a3ba"
    //            }
    //            Button {
    //                text: "<font color='#ffe'>" + "اختیارات" + "</font>"
    //                font.family: "Mehr Nastaliq Web"
    //                font.wordSpacing: 4
    //                font.pointSize: 12
    //                background: Rectangle {
    //                    color: "#3e24a4"
    //                    radius: 3
    //                }
    //            }
    //        }
    //    }

    StackView {
        id: stack
        initialItem: Qt.resolvedUrl("home.qml")
        anchors.fill: parent

        pushEnter: Transition {
            id: pushEnter
            ParallelAnimation {
                PropertyAction {
                    property: "x";value: pushEnter.ViewTransition.item.pos
                }
                NumberAnimation {
                    property: "opacity";from: 0;to: 1;duration: 400;easing.type: Easing.OutCubic
                }
            }
        }
        popExit: Transition {
            id: popExit
            ParallelAnimation {
                PropertyAction {
                    property: "x";value: popExit.ViewTransition.item.pos
                }
                NumberAnimation {
                    property: "opacity";from: 1;to: 0;duration: 400;easing.type: Easing.OutCubic
                }
            }
        }

        pushExit: Transition {
            id: pushExit
            PropertyAction {
                property: "x";value: pushExit.ViewTransition.item.pos
            }
            PropertyAction {
                property: "y";value: pushExit.ViewTransition.item.pos
            }
        }
        popEnter: Transition {
            id: popEnter
            PropertyAction {
                property: "x";value: popEnter.ViewTransition.item.pos
            }
            PropertyAction {
                property: "y";value: popEnter.ViewTransition.item.pos
            }
        }
    }


}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
