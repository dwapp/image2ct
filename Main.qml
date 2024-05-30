import QtQuick
import QtQuick.Dialogs
import QtQuick.Controls
import image2ct

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Row {
        anchors.top: parent.top
        width: parent.width
        Button {
            text: qsTr("Choose Image...")
            onClicked: fileDialog.open()
        }

        Text {
            id: ret
            text: "Unknow"
        }
    }

    Image {
        id: image
        anchors.fill: parent
        fillMode: Image.PreserveAspectFit
    }

    FileDialog {
        id: fileDialog
        currentFolder: "file:///usr/share/wallpapers/deepin"
        //StandardPaths.standardLocations(StandardPaths.PicturesLocation)[0]
        onAccepted: {
            image.source = selectedFile
            rect.source = selectedFile
            rect2.source = selectedFile
        }
    }

    Image {
        id: rect
        width: 1
        height: 1
        source: filePath
        fillMode: Image.Stretch
        onSourceChanged: {
            rect.grabToImage(function(result) {
                Helper.calcColorType(result.image);
            });
        }
    }

    Image {
        id: rect2
        width: 2
        height: 2
        source: filePath
        fillMode: Image.Stretch
        onSourceChanged: {
            rect2.grabToImage(function(result) {
                ret.text = Helper.calcColorType(result.image) ? "Light" : "Dark";
            });
        }
    }
}
