#pragma once

#include <list>
#include "WarehouseStateManager.h"
#include "Models.h"


class Command {

protected:
    WarehouseStateManager<WarehousePackage>* instance;
public:
    virtual void execute() = 0;
    virtual ~Command() = default;
};

class StorageManagerCommand : public Command
{
public:
    void execute() override;
};

class DefineStorageCommand : public Command
{
public:
    void execute() override;
};

class DeleteStorageCommand : public Command
{
public:
    void execute() override;
};

class DisplayCapacityCommand : public Command
{
public:
    void execute() override;
};

class RemovePackageCommand : public Command
{
public:
    void execute() override;
};

class AddPackageCommand : public Command
{
public:
    void execute() override;
};
