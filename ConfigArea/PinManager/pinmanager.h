#ifndef PINMANAGER_H
#define PINMANAGER_H

#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QFile>
#include <QDebug>
#include "../Pin/pin.h"

class PinManager {
public:
    bool saveToJson(const QVector<Pin*>& pins, const QString& filePath) const;

    bool loadFromJson(QVector<Pin*>& pins, const QString& filePath) const;
private:
    QJsonObject pinToJson(const Pin& pin) const;

    Pin jsonToPin(const QJsonObject& jsonObject) const;
};

#endif // PINMANAGER_H
