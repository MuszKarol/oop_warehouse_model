#pragma once

#include <map>
#include <queue>
#include <mutex>
#include "Models.h"

class WarehouseStateManager {
private:
    WarehouseStateManager();

    WarehouseStateManager(const WarehouseStateManager &) = delete;

    WarehouseStateManager &operator=(const WarehouseStateManager &) = delete;

    static WarehouseStateManager *instance;
    static std::mutex mutex;
    static std::map<WarehouseStorage, std::queue<WarehousePackage>> internalStorage;

public:
    static WarehouseStateManager *getInstance();

    std::vector<WarehouseStorage> getStorages();

    std::vector<WarehousePackage> getStoragePackages(const WarehouseStorage &storage);

    void addNewPackage(const WarehouseStorage &storage, const WarehousePackage &warehousePackage);

    void defineNewStorage(const WarehouseStorage &storage);

    void modifyExistingPackage(const WarehouseStorage &storage, const WarehousePackage &warehousePackage);

    void deleteExistingPackage(const WarehouseStorage &storage);

    void deleteExistingStorage(const WarehouseStorage &storage);

    double getStorageCapacityStatistics(const WarehouseStorage &storage);

    bool isStorageFull(const WarehouseStorage &storage);

    ~WarehouseStateManager();
};
