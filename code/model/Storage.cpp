#include <utility>
#include "../Models.h"

WarehouseStorage::WarehouseStorage(std::string id, int size, bool active, std::string queueMode)
        : id(std::move(id)), size(size), active(active), queueMode(std::move(queueMode)) {}

bool WarehouseStorage::operator<(const WarehouseStorage &other) const {
    return this->id < other.id;
}

bool WarehouseStorage::operator==(const WarehouseStorage &other) const {
    return this->id == other.id;
}
