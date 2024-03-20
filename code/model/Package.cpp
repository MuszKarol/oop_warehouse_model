#include "../Models.h"

WarehousePackage::WarehousePackage(std::string packageId, std::string productId, double axisX, double axisY,
                                   double axisZ, std::string type, double weight)
    : packageId(packageId), productId(productId), axisX(axisX), axisY(axisY), axisZ(axisZ), type(type),
      weight(weight)
{
}
