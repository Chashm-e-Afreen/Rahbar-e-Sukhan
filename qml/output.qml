import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls.Styles 1.4
//import Dummy 1.0

ScrollView {
    property int index;
    property int no_of_lines;
    width: availableWidth

        Column {
            id: canvas
            width: 800
            height: 270


            spacing: 20
            topPadding: 10
            x: (root.width - 800)/2
            Component.onCompleted: {
                var no_of_lines = Dummy.no_of_lines();
                for (let i = 0; i < no_of_lines; ++i) {
                    index = i;
                    let no_of_words = Dummy.no_of_words(i);
                    var card = Qt.createComponent("card.qml");
                    card.createObject(canvas);
                }
                var item = Qt.createComponent("button.qml");
                item.createObject(canvas);

            }


        }
    

}
