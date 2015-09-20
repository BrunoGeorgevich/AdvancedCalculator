import QtQuick 2.0
import QtQuick.Controls 1.2

ApplicationWindow {
    title:"Advanced Calculator"
    visible: true
    height: 600
    width: 400

    Rectangle {
        id:displayRect
        anchors {
            fill:parent
            bottomMargin: parent.height*(0.7)
            margins: parent.height*(0.02)
        }

        Text {

            signal clear;
            signal erase;

            id: displayText
            text: ""

            anchors {
                right:parent.right
                bottom:parent.bottom
                margins:parent.height*(0.1)
            }

            font {
                bold:true
                pixelSize: parent.height/5
            }

            onClear: {
                text = "";
            }

            onErase: {
                text = text.substring(0, text.length - 1);
            }
        }

        Rectangle {
            anchors{
                fill: parent
                rightMargin: parent.width*(0.85)
                bottomMargin:parent.height*(0.70)
                leftMargin:parent.width*(0.02)
                topMargin:parent.height*(0.02)
            }

            Text {
                anchors.fill: parent

                font {
                    bold:true
                    pixelSize: height*(0.8)
                }

                text:"C"
            }

            MouseArea {
                anchors.fill: parent

                onClicked: {
                    displayText.erase()
                }

                onPressAndHold: {
                    displayText.clear()
                }
            }

        }
    }
    Rectangle{

        anchors {
            top:displayRect.bottom
            left:parent.left
            right:parent.right
            bottom:parent.bottom

            margins:parent.height*(0.02)
        }

        color:"transparent"

        Grid {
            id:buttonGrid

            anchors{
                fill: parent
                leftMargin: parent.width/20
                topMargin: parent.height/30
            }

            columns:4

            columnSpacing: anchors.leftMargin
            rowSpacing: anchors.topMargin

            Repeater {
                model:ListModel {
                    ListElement { label:"/" }
                    ListElement { label:"*" }
                    ListElement { label:"+" }
                    ListElement { label:"-" }
                    ListElement { label:"1" }
                    ListElement { label:"2" }
                    ListElement { label:"3" }
                    ListElement { label:"^" }
                    ListElement { label:"4" }
                    ListElement { label:"5" }
                    ListElement { label:"6" }
                    ListElement { label:"R" }
                    ListElement { label:"7" }
                    ListElement { label:"8" }
                    ListElement { label:"9" }
                    ListElement { label:"." }
                    ListElement { label:"(" }
                    ListElement { label:"0" }
                    ListElement { label:")" }
                    ListElement { label:"=" }
                }

                delegate:Rectangle {
                    width:buttonGrid.width/5
                    height:buttonGrid.height/6
                    color: "#DD0"

                    radius: 10

                    Text {
                        id:textButton
                        anchors.fill: parent

                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter

                        font {
                            bold:true
                            pixelSize: height*(0.7)
                        }

                        color: "black"
                        text: label
                    }

                    MouseArea {
                        anchors.fill: parent

                        onClicked: {
                            if(textButton.text == "=") {
                                displayText.text = _calc.calculate(displayText.text).toFixed(2);
                            } else {
                                displayText.text += textButton.text;
                            }
                        }
                    }
                }
            }
        }
    }
}

