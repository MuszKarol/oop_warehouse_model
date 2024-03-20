#pragma once

#include <map>
#include <queue>
#include <mutex>

template<typename T> class WarehouseStateManager
{
private:
    WarehouseStateManager();
    WarehouseStateManager(const WarehouseStateManager&) = delete;
    WarehouseStateManager& operator = (const WarehouseStateManager&) = delete;

    static WarehouseStateManager* instance;
    static std::mutex mutex;

    std::queue<T> lifoStorageQueue; //TODO to remove
    std::queue<T> fifoStorageQueue; //TODO to remove

    std::map<int, std::queue<T>> internalStorage; //TODO target internal storage

public:
    static WarehouseStateManager* getInstance();

    void pushLifoPackage(const T& genericPackageObject); //TODO to remove - test method
    void pushFifoPackage(const T& genericPackageObject); //TODO to remove - test method

    T popLifoPackage(); //TODO to remove - test method
    T popFifoPackage(); //TODO to remove - test method

    ~WarehouseStateManager();
};
