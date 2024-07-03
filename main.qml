import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 600
    height: 400
    title: "MCP System"
    color: "#D6EAF8"

    property string currentComboBoxText: ""

    signal selectionChanged(string newValue)

    Rectangle {
        width: parent.width
        height: parent.height
        color: "#D6EAF8"

        Column {
            anchors.centerIn: parent
            spacing: 20

            Text {
                text: "MCP System"
                font.pixelSize: 36
                font.bold: true
                color: "#333333"
                horizontalAlignment: Text.AlignHCenter
            }




            ComboBox {
                    id: comboBox
                    objectName: "directoryComboBox"
                    width: 200
                    model: ["abalone", "accent", "balance-scale", "balloons", "banknote", "bean", "breast-cancer-wisconsin", "car", "divorce", "forest-fire", "iris", "monk", "mushroom", "nursery", "optdigits", "rice", "shuttle", "vote"]
                    onCurrentTextChanged: {
                        currentComboBoxText = comboBox.currentText;
                        selectionChanged(currentComboBoxText);
                    }
                }


            Row {
                spacing: 20

                Button {
                    objectName: "make"
                    text: "Make"
                    font.bold: true
                    width: 100
                    height: 40
                    background: Rectangle {
                        color: "#F1C40F"
                        radius: 10
                    }

                }

                Button {
                    objectName: "guess"
                    text: "Guess"
                    font.bold: true
                    width: 100
                    height: 40
                    background: Rectangle {
                        color: "#2ECC71"
                        radius: 10
                    }

                }

                Button {
                    objectName: "trans"
                    text: "Trans"
                    font.bold: true
                    width: 100
                    height: 40
                    background: Rectangle {
                        color: "#16A085"
                        radius: 10
                    }

                }

                Button {
                    objectName: "uniq"
                    text: "Uniq"
                    font.bold: true
                    width: 100
                    height: 40
                    background: Rectangle {
                        color: "#3498DB"
                        radius: 10
                    }

                }

                Button {
                    objectName: "split"
                    text: "Split"
                    font.bold: true
                    width: 100
                    height: 40
                    background: Rectangle {
                        color: "#2980B9"
                        radius: 10
                    }

                }
            }

            Row {
                spacing: 20

            Column {
            Item {
                id: menu1

                Popup {
                    id: popup1
                    y: seqbutton.height
                    width: 150

                    contentItem: ListView {
                    id: menuItems1

                            width: popup1.width
                            implicitHeight: contentHeight
                            model:["hrn", "bij", "cnf"]


                            delegate: MenuItem {
                                text: modelData
                                onClicked: {
                                    if (popup1) {
                                        popup1.close()
                                        ButtonClickHandler.seq(modelData)

                                                }
                                }
                            }
                        }
                    }


            }
            }

                Button {
                    objectName: "seq"
                    text: "Seq/PThread"
                    id: seqbutton
                    font.bold: true
                    width: 150
                    height: 40
                    background: Rectangle {
                        color: "#8E44AD"
                        radius: 10
                    }

                    onClicked: {
                        popup1.open()
                    }

                }


                Column {
                Item {
                    id: menu

                    Popup {
                        id: popup
                        y: checkbutton.height
                        width: 150

                        contentItem: ListView {
                            id: menuItems

                            width: popup.width
                            implicitHeight: contentHeight
                            model: comboBox.currentText === "mushroom" ? ["edible", "poisonous"] :
                                               comboBox.currentText === "abalone" ? ["24", "25"] :
                                               comboBox.currentText === "accent" ? ["ES", "FR", "GE", "IT", "UK", "US"] :
                                               comboBox.currentText === "balance-scale" ? ["B", "L", "R"] :
                                               comboBox.currentText === "banknote" ? ["genuine", "forged"] :
                                               comboBox.currentText === "bean" ? ["BARBUNYA", "BOMBAY", "CALI", "DERMASON", "HOROZ", "SEKER", "SIRA"] :
                                               comboBox.currentText === "breast-cancer-wisconsin" ? ["benign", "malignant"] :
                                               comboBox.currentText === "car" ? ["vgood"] :
                                               comboBox.currentText === "divorce" ? ["yes", "no"] :
                                               comboBox.currentText === "forest-fire" ? ["sep", "jul", "aug"] :
                                               comboBox.currentText === "iris" ? ["setosa", "versicolor", "virginica"] :
                                               comboBox.currentText === "monk" ? ["1_1", "2_1", "3_1"] :
                                               comboBox.currentText === "nursery" ? ["spec_prior", "not_recom"] :
                                               comboBox.currentText === "rice" ? ["cammeo", "osmancik"] :
                                               comboBox.currentText === "shuttle" ? ["1", "4", "5"] :
                                               comboBox.currentText === "vote" ? ["democrat", "republican"] :
                                               []

                            delegate: MenuItem {
                                text: modelData
                                onClicked: {
                                    if (popup) {
                                        popup.close()
                                        ButtonClickHandler.check(modelData)

                                                }
                                }
                            }
                        }
                    }


                }

                Button {
                    objectName: "chk"
                    text: "Check"
                    id: checkbutton
                    font.bold: true
                    width: 150
                    height: 40
                    background: Rectangle {
                        color: "#E54BD0"
                        radius: 10
                    }

                    onClicked: {
                        popup.open()
                    }

                }
                }

                Button {
                    objectName: "clean"
                    text: "Clean"
                    font.bold: true
                    width: 100
                    height: 40
                    background: Rectangle {
                        color: "#E74C3C"
                        radius: 10
                    }

                }
            }
        }
    }
}

