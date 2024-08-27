#include <iostream>
#include <iomanip>
#include "../Command.h"

WarehouseStorage Command::selectWarehouseStorage() {
    int i = 0;
    std::vector<WarehouseStorage> storages = instance->getStorages();

    for (const WarehouseStorage &storage: storages) {
        std::cout << "Storage (" << storage.id << ") number: " << i << std::endl;
        i++;
    }

    std::cout << "Enter number: ";
    int index;
    std::cin >> index;

    if (index < 0 || index > (storages.size())) {
        std::cout << "Invalid parameter!" << std::endl;
        throw std::invalid_argument("Invalid parameter: storage number");
    }

    return storages.at(index);
}

void StorageManagerCommand::execute() {
    WarehouseStorage warehouseStorage = selectWarehouseStorage();

    std::cout << "1). Change size of storage." << std::endl;
    std::cout << "2). Modify active status." << std::endl;

    int option;
    std::cout << "Select option: ";
    std::cin >> option;

    switch (option) {
        case 1:
            int size;
            std::cout << "Enter new size: ";
            std::cin >> size;
            warehouseStorage.size = size;
            break;
        case 2:
            bool active;
            std::cout << "Enter new storage status (0 - false, 1 - true): ";
            std::cin >> active;
            warehouseStorage.active = active;
            break;
        default:
            std::cout << "No action selected." << std::endl;
            break;
    }
}

void DefineStorageCommand::execute() {
    std::cout << "Enter storage id: ";
    std::string id;
    std::cin >> id;

    std::cout << "Enter storage size: ";
    int size;
    std::cin >> size;

    std::cout << "Enter storage activation status (0 - disabled, 1 - active): ";
    bool active;
    std::cin >> active;

    std::cout << "Enter storage purpose: ";
    std::string queueMode;
    std::cin >> queueMode;

    instance->defineNewStorage(WarehouseStorage(id, size, active, queueMode));
}

void DeleteStorageCommand::execute() {
    WarehouseStorage warehouseStorage = selectWarehouseStorage();
    instance->deleteExistingStorage(warehouseStorage);
    std::cout << "Storage removed" << std::endl;
}

void RemovePackageCommand::execute() {
    WarehouseStorage warehouseStorage = selectWarehouseStorage();
    instance->deleteExistingPackage(warehouseStorage);
    std::cout << "Package removed" << std::endl;
}

void AddPackageCommand::execute() {
    WarehouseStorage warehouseStorage = selectWarehouseStorage();

    if (!warehouseStorage.active) {
        std::cout << "Storage is inactive!" << std::endl;
        return;
    }

    if (instance->isStorageFull(warehouseStorage)) {
        std::cout << "Storage is full!" << std::endl;
        return;
    }

    std::cout << "Enter package ID: ";
    std::string packageId;
    std::cin >> packageId;

    std::cout << "Enter product ID: ";
    std::string productId;
    std::cin >> productId;

    std::cout << "Define package dimensions." << std::endl << "Enter axisX (cm): ";
    double axisX;
    std::cin >> axisX;

    std::cout << "Enter axisY (cm): ";
    double axisY;
    std::cin >> axisY;

    std::cout << "Enter axisZ (cm): ";
    double axisZ;
    std::cin >> axisZ;

    std::cout << "Enter package type: ";
    std::string type;
    std::cin >> type;

    std::cout << "Enter package weight (kg): ";
    double weight;
    std::cin >> weight;

    instance->addNewPackage(warehouseStorage,
                            WarehousePackage(packageId, productId, axisX, axisY, axisZ, type, weight));
}

void DisplayCapacityCommand::execute() {
    std::cout << "Storages capacity list: " << std::endl;
    for (const WarehouseStorage &storage: instance->getStorages()) {
        std::cout << "Storage " << storage.id << "\t";
        printProgressBar(instance->getStorageCapacityStatistics(storage));
    }
}

void DisplayCapacityCommand::printProgressBar(double progress) {
    constexpr int progressBarWidth = 50;
    progress = std::min(1.0, std::max(0.0, progress));
    auto progressChars = static_cast<int>(progress * progressBarWidth);

    std::cout << "[";

    for (int i = 0; i < progressBarWidth; ++i) {
        std::cout << (i < progressChars ? "=" : " ");
    }

    std::cout << "] " << std::fixed << std::setprecision(1) << (progress * 100.0) << "%" << std::endl;
}
