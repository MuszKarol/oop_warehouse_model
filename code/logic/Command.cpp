#include <iostream>
#include <iomanip>
#include <thread>
#include "../Command.h"

void StorageManagerCommand::execute()
{
    std::cout<<"Existing storages"<<std::endl;

}

void DefineStorageCommand::execute()
{
    std::cout<<"setupNewStorage()"<<std::endl;
}

void DeleteStorageCommand::execute()
{
    std::cout << "deleteStorage()" << std::endl;
}

void RemovePackageCommand::execute()
{
    std::cout << "removePackage()" << std::endl;
}

void AddPackageCommand::execute()
{
    std::cout << "addPackage()" << std::endl;
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