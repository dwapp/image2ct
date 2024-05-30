#ifndef HELPER_H
#define HELPER_H

#include <QObject>
#include <QImage>
#include <QRgb>
#include <QQmlEngine>
#include <DGuiApplicationHelper>
/*
DGuiApplicationHelper::ColorType DGuiApplicationHelper::toColorType(const QColor &color)
{
    if (!color.isValid())
        return UnknownType;

    QColor rgb_color = color.toRgb();
    // 获取rgb颜色的亮度(转换为YUV格式)
    float luminance = 0.299 * rgb_color.redF() + 0.587 * rgb_color.greenF() + 0.114 * rgb_color.blueF();

    if (qRound(luminance * 255) > 191) {
        return LightType;
    }

    return DarkType;
}
*/


class Helper : public QObject{
    Q_OBJECT
    QML_SINGLETON
    QML_ELEMENT
public:
    explicit Helper (QObject* parent = nullptr) : QObject(parent) {}
    Q_INVOKABLE int calcColorType(const QImage &img) {

        if (img.width() == 1 && img.height() == 1) {
            // 获取rgb颜色的亮度(转换为YUV格式)
            float luminance = 0.299 * qRed(img.pixel(0, 0))
                              + 0.587 * qRed(img.pixel(0, 0))
                              + 0.114 * qBlue(img.pixel(0, 0));
            qDebug() << "1*1 rgb: " << qRed(img.pixel(0, 0)) << qRed(img.pixel(0, 0)) << qBlue(img.pixel(0, 0));
            qDebug() << "1*1: " << luminance << " is Light: " << (qRound(luminance) > 170);
            return qRound(luminance) > 170;
        }

        if (img.width() == 2 && img.height() == 2) {
            int r = 0, g = 0, b = 0;
            for (int i = 0; i < 2; i++)
                for (int j = 0; j < 2; j++) {
                    r += qRed(img.pixel(i, j));
                    g += qGreen(img.pixel(i, j));
                    b += qBlue(img.pixel(i, j));
                }
            float luminance = 0.299 * r / 4 + 0.587 * g / 4 + 0.114 * b / 4;
            qDebug() << "1*1 rgb: " << r/4 << g/4 << b/4;
            qDebug() << "2*2: " << luminance << " is Light: " << (qRound(luminance) > 170);
            return qRound(luminance) > 170;
        }

        qDebug() << "Error size!";
        return 0;
    }
};

#endif // HELPER_H
