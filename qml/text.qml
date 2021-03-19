import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls.Styles 1.4
//import Dummy 1.0

ColumnLayout {
    property font myFont: Qt.font({
        family: "Mehr Nastaliq Web",
        pixelSize: 17,
        fontSizeMode: Text.Fit,
        //                                              pixelSize: 10000, // maximum height of the font
        minimumPixelSize: 8
    });
    id: text_column
    Text {
        id: word
        color: "#2f855a"
        font: text_column.myFont
        //                    text: "اب"
    }

    Text {
        id: taqti
        color: "#2f855a"
        font: text_column.myFont
    }
    Text {
        id: islah
        color: "#2f855a"
        font: text_column.myFont
    }

    Component.onCompleted: {
        var word_list = Dummy.send_word_list(line_no, index2);

        word.text = word_list[0];
        taqti.text = word_list[1];
        islah.text = word_list[2];

        var problematic = word_list[1] !== word_list[2] || word_list[1] === "N/A";

        word.color = problematic ? "#c53030" : "#38a32a"
        taqti.color = problematic ? "#c53030" : "#38a32a"

    }

}
