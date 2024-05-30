import QtQuick
import image2ct

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
    property string filePath: "file:///usr/share/wallpapers/deepin/wallpaper-light.jpg"

    Image {
        id: background
        source: filePath
        fillMode: Image.Stretch
        anchors.fill: parent
    }

    Image {
        id: rect
        width: 1
        height: 1
        visible: true
        source: filePath
        fillMode: Image.Stretch
        Component.onCompleted: {
            rect.grabToImage(function(result) {
                Helper.calcColorType(result.image);
            });
        }
    }

    Image {
        id: rect2
        width: 2
        height: 2
        visible: true
        source: filePath
        fillMode: Image.Stretch
        Component.onCompleted: {
            rect2.grabToImage(function(result) {
                Helper.calcColorType(result.image);
            });
        }
    }
}
