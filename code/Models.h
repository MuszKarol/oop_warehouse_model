# pragma once

#include <string>

struct WarehousePackage
{
    std::string packageId;
    std::string productId;
    double axisX;
    double axisY;
    double axisZ;
    std::string type;
    double weight;

    WarehousePackage(std::string packageId, std::string productId, double axisX, double axisY, double axisZ,
        std::string type, double weight);
};

struct WarehouseStorage
{
    std::string id;
    int size;
    bool active;
    std::string queueMode;

    bool operator<(const WarehouseStorage& other) const;
    bool operator==(const WarehouseStorage& other) const;

    WarehouseStorage(std::string id, int size, bool active, std::string queueMode);
};