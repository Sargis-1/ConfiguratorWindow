#include "pinmanager.h"


bool PinManager::saveToJson(const QVector<Pin*>& pins, const QString& filePath) const
{
    QJsonArray jsonarr;
    for (const auto& pin : pins) {
        jsonarr.append(pinToJson(*pin));
    }

    QJsonDocument jsonDoc(jsonarr);
    QFile jsonFile(filePath);
    if (!jsonFile.open(QIODevice::WriteOnly)) {
        qWarning() << "Couldn't open file for writing" << jsonFile.errorString();
        return false;
    }

    jsonFile.write(jsonDoc.toJson());

    jsonFile.close();
    return true;
}

bool PinManager::loadFromJson(QVector<Pin*>& pins, const QString& filePath) const
{
    QFile jsonFile(filePath);
    if (!jsonFile.open(QIODevice::ReadOnly)) {
        qWarning() << "Could not open file for reading:" << jsonFile.errorString();
        return false;
    }

    QByteArray jsonData = jsonFile.readAll();
    jsonFile.close();

    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData);

    pins.clear();
    QJsonArray jsonArray = jsonDoc.array();
    for (const QJsonValue& value : jsonArray) {
        if (value.isObject()) {
            Pin pin = std::move(jsonToPin(value.toObject()));
            pins.push_back(new Pin(std::move(pin)));
        }
    }

    return true;
}

QJsonObject PinManager::pinToJson(const Pin& pin) const
{
    QJsonObject jsonObject;
    jsonObject["name"] = pin.getName();
    jsonObject["direction"] = pin.getDirection();
    jsonObject["enableBusRange"] = pin.hasBusRange();
    jsonObject["range"] = pin.getRange();
    return jsonObject;
}

Pin PinManager::jsonToPin(const QJsonObject& jsonObject) const
{
    Pin pin;
    pin.setName(jsonObject["name"].toString());
    pin.setDirection(jsonObject["direction"].toString());
    pin.setBusRange(jsonObject["enableBusRange"].toString());
    pin.setRange(jsonObject["range"].toString());
    return std::move(pin);
}
