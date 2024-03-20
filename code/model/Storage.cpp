#include "../Models.h"

WarehouseStorage::WarehouseStorage(std::string id, int size, bool active, std::string queueMode)
    : id(id), size(size), active(active), queueMode(queueMode)
{
}
