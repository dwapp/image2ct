#ifndef HELPER_H
#define HELPER_H

#include <QObject>
#include <QImage>
#include <QRgb>
#include <QQmlEngine>
#include <DGuiApplicationHelper>

class Helper : public QObject{
    Q_OBJECT
    QML_SINGLETON
    QML_ELEMENT
public:
    explicit Helper (QObject* parent = nullptr) : QObject(parent) {}
    Q_INVOKABLE int calcColorType(const QImage &img) {

        if (img.width() == 1 && img.height() == 1) {
            qDebug() << "1*1: " << Dtk::Gui::DGuiApplicationHelper::toColorType(img.pixel(0,0));
            return 1;
        }

        if (img.width() == 2 && img.height() == 2) {
            int r = 0, g = 0, b = 0;
            for (int i = 0; i < 2; i++)
                for (int j = 0; j < 2; j++) {
                    r += qRed(img.pixel(i, j));
                    g += qGreen(img.pixel(i, j));
                    b += qBlue(img.pixel(i, j));
                }
            qDebug() << "2*2: " << Dtk::Gui::DGuiApplicationHelper::toColorType(QColor(r/4, g/4, b/4));
            return 1;
        }

        qDebug() << "Error size!";
        return 0;
    }
};

#endif // HELPER_H
