#include <iostream>
#include <iomanip>
#include <thread>
#include "../Command.h"


WarehouseStorage Command::selectWarehouseStorage() {
    int i = 0;
    std::vector<WarehouseStorage> storages = instance->getStorages();

    for (const WarehouseStorage & storage : storages) {
        std::cout << i << "). Storage id: " << storage.id << std::endl;
        i++;
    }

    std::cout << "Enter id: ";
    int index;
    std::cin >> index;

    if (index < 0 || index > (storages.size() - 1)) {
        std::cout << "Invalid parameter!" << std::endl;
        throw std::runtime_error("Invalid parameter: Storage id");
    }

    WarehouseStorage warehouseStorage = storages.at(index);
    return warehouseStorage;
}

void StorageManagerCommand::execute()
{
    WarehouseStorage warehouseStorage = selectWarehouseStorage();

    std::cout << "1). Change size of storage." << std::endl;
    std::cout << "2). Modify active status." << std::endl;

    int option = 0;
    std::cout << "Select option: ";
    std::cin >> option;

    switch (option) {
        case 1:
            int size;
            std::cin >> size;
            warehouseStorage.size = size;
            break;
        case 2:
            bool active;
            std::cin >> active;
            warehouseStorage.active = active;
            break;
        default:
            std::cout << "No action selected." << std::endl;
            break;
    }
}

void DefineStorageCommand::execute()
{
    std::cout << "Enter storage id: ";
    std::string id;
    std::cin >> id;

    std::cout << "Enter storage size: ";
    int size;
    std::cin >> size;

    std::cout << "Enter storage status: ";
    bool active;
    std::cin >> active;

    std::cout << "Enter storage mode: ";
    std::string queueMode;
    std::cin >> queueMode;

    instance->defineNewStorage(WarehouseStorage(id, size, active, queueMode));
}

void DeleteStorageCommand::execute()
{
    WarehouseStorage warehouseStorage = selectWarehouseStorage();
    instance->deleteExistingStorage(warehouseStorage);
    std::cout << "Storage removed" << std::endl;
}

void RemovePackageCommand::execute()
{
    WarehouseStorage warehouseStorage = selectWarehouseStorage();
    instance->deleteExistingPackage(warehouseStorage);
    std::cout << "Package removed" << std::endl;
}

void AddPackageCommand::execute()
{
    WarehouseStorage warehouseStorage = selectWarehouseStorage();

    std::cout << "Enter package id: ";
    std::string packageId;
    std::cin >> packageId;

    std::cout << "Enter product id: ";
    std::string productId;
    std::cin >> productId;

    std::cout << "Define package dimensions." << std::endl << "Enter axisX: ";
    double axisX;
    std::cin >> axisX;

    std::cout << "Enter axisY: ";
    double axisY;
    std::cin >> axisY;

    std::cout << "Enter axisZ: ";
    double axisZ;
    std::cin >> axisZ;

    std::cout << "Enter package type: ";
    std::string type;
    std::cin >> type;

    std::cout << "Enter package weight: ";
    double weight;
    std::cin >> weight;

    instance->addNewPackage(warehouseStorage, WarehousePackage(packageId, productId, axisX, axisY, axisZ, type, weight));
}

void DisplayCapacityCommand::execute()
{
    std::cout << "Lista zajetosci magazynow: " << std::endl;
    for (const WarehouseStorage & storage : instance->getStorages()) {
        printProgressBar(instance->getStorageCapacityStatistics(storage));
        std::cout << std::endl;
    }
}

void DisplayCapacityCommand::printProgressBar(double progress) {
    constexpr int progressBarWidth = 50;
    progress = std::min(1.0, std::max(0.0, progress));
    int progressChars = static_cast<int>(progress * progressBarWidth);

    std::cout << "[";
    for (int i = 0; i < progressBarWidth; ++i) {
        std::cout << (i < progressChars ? "=" : " ");
    }
    std::cout << "] " << std::fixed << std::setprecision(1) << (progress * 100.0) << "%" << std::flush;
    std::cout << "\r";
}