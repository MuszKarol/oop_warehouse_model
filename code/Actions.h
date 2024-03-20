#pragma once

#include "WarehouseStateManager.h"
#include "Models.h"


class Command {
private:
    WarehouseStateManager<WarehousePackage>* instance = WarehouseStateManager<WarehousePackage>::getInstance(); //TODO

public:
    virtual void execute() = 0;
    virtual ~Command() = default;
};

class StorageManagerCommand : public Command
{
    void execute() override;
};

class DefineStorageCommand : public Command
{
    void execute() override;
};

class DisplayCapacityCommand : public Command
{
    void execute() override;
};

class UpdatePackageCommand : public Command
{
    void execute() override;
};

class RemovePackageCommand : public Command
{
    void execute() override;
};

class AddPackageCommand : public Command
{
    void execute() override;
};
