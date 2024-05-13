#include <mutex>
#include <stdexcept>
#include "../WarehouseStateManager.h"


WarehouseStateManager *WarehouseStateManager::instance = nullptr;
std::mutex WarehouseStateManager::mutex;
std::map<WarehouseStorage, std::queue<WarehousePackage>> WarehouseStateManager::internalStorage;

WarehouseStateManager *WarehouseStateManager::getInstance() {
    if (!instance) {
        instance = new WarehouseStateManager;
    }

    return instance;
}

std::vector<WarehouseStorage> WarehouseStateManager::getStorages() {
    std::vector<WarehouseStorage> storageVector;

    for (const auto &pair: internalStorage) {
        storageVector.push_back(pair.first);
    }

    return storageVector;
}

std::vector<WarehousePackage> WarehouseStateManager::getStoragePackages(const WarehouseStorage &storage) {
    std::vector<WarehousePackage> packageVector;

    for (const auto &pair: internalStorage) {
        if (pair.first == storage) {
            const std::queue<WarehousePackage> &packages = pair.second;
            std::queue<WarehousePackage> tempPackages = packages;

            while (!tempPackages.empty()) {
                packageVector.push_back(tempPackages.front());
                tempPackages.pop();
            }

            break;
        }
    }

    return packageVector;
}

void WarehouseStateManager::addNewPackage(const WarehouseStorage &storage, const WarehousePackage &warehousePackage) {
    std::lock_guard<std::mutex> lock(mutex);

    for (auto &pair: internalStorage) {
        if (pair.first.id == storage.id) {
            pair.second.push(warehousePackage);
            return;
        }
    }

    throw std::runtime_error("Storage not found");
}

void WarehouseStateManager::defineNewStorage(const WarehouseStorage &storage) {
    std::lock_guard<std::mutex> lock(mutex);

    if (internalStorage.find(storage) == internalStorage.end()) {
        internalStorage[storage] = std::queue<WarehousePackage>();
    }
}

void WarehouseStateManager::modifyExistingPackage(const WarehouseStorage &storage,
                                                  const WarehousePackage &warehousePackage) {
    std::lock_guard<std::mutex> lock(mutex);

    if (auto it = internalStorage.find(storage); it != internalStorage.end()) {
        std::queue<WarehousePackage> &packages = it->second;

        while (!packages.empty()) {
            WarehousePackage &currentPackage = packages.front();

            if (currentPackage.packageId == warehousePackage.packageId) {
                currentPackage.productId = warehousePackage.productId;
                currentPackage.type = warehousePackage.type;
                currentPackage.weight = warehousePackage.weight;
                currentPackage.axisX = warehousePackage.axisX;
                currentPackage.axisY = warehousePackage.axisY;
                currentPackage.axisZ = warehousePackage.axisZ;
                break;
            }

            packages.pop();
        }
    }
}

void WarehouseStateManager::deleteExistingPackage(const WarehouseStorage &storage) {
    std::lock_guard<std::mutex> lock(mutex);

    if (auto it = internalStorage.find(storage); it != internalStorage.end()) {
        std::queue<WarehousePackage> &packages = it->second;
        packages.pop();
        return;
    }
}

void WarehouseStateManager::deleteExistingStorage(const WarehouseStorage &storage) {
    std::lock_guard<std::mutex> lock(mutex);

    if (auto it = internalStorage.find(storage); it != internalStorage.end()) {
        internalStorage.erase(it);
        return;
    }

    throw std::runtime_error("Storage not found");
}

double WarehouseStateManager::getStorageCapacityStatistics(const WarehouseStorage &storage) {
    auto actualSize = (double) instance->getStoragePackages(storage).size();
    if (actualSize == 0.0) {
        return 0;
    } else {
        return actualSize / storage.size;
    }
}

WarehouseStateManager::WarehouseStateManager() {}

WarehouseStateManager::~WarehouseStateManager() {
    delete instance;
}
