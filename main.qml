import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 400
    height: 300
    title: "Webpage with Buttons"
    color: "#add8e6"

    Column {
        anchors.fill: parent
        spacing: 10

        Text {
            text: "Title of the Webpage"
            font.pointSize: 24
            horizontalAlignment: Text.AlignHCenter
        }

        Row {
            spacing: 10

            Button {
                objectName: "button1"
                text: "Button 1"

            }
            Button { text: "Button 2" }
            Button { text: "Button 3" }
            Button { text: "Button 4" }
            Button { text: "Button 5" }
        }
    }
}
