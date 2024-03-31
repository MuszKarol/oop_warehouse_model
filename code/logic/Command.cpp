#include <iostream>
#include "../Command.h"

void StorageManagerCommand::execute()
{
    std::cout<<"manageStorage()"<<std::endl;
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
    std::cout << "displayWarehouseCapacity()" << std::endl;
}
