#include <iostream>
#include <mutex>
#include "../WarehouseStateManager.h"


template<typename T> WarehouseStateManager<T>* WarehouseStateManager<T>::instance = nullptr;

template<typename T> std::mutex WarehouseStateManager<T>::mutex;

template <typename T>
WarehouseStateManager<T>* WarehouseStateManager<T>::getInstance()
{
    std::lock_guard<std::mutex> lock(mutex);

    if (!instance)
    {
        instance = new WarehouseStateManager;
    }

    return instance;
}

template<typename T> void WarehouseStateManager<T>::pushLifoPackage(const T& genericPackageObject)
{
    std::lock_guard<std::mutex> lock(mutex);
    lifoStorageQueue.push(genericPackageObject);
}

template<typename T> void WarehouseStateManager<T>::pushFifoPackage(const T& genericPackageObject)
{
    std::lock_guard<std::mutex> lock(mutex);
    fifoStorageQueue.push(genericPackageObject);
}

template<typename T> T WarehouseStateManager<T>::popLifoPackage()
{
    std::lock_guard<std::mutex> lock(mutex);

    if (!lifoStorageQueue.empty())
    {
        T frontState = lifoStorageQueue.front();
        lifoStorageQueue.pop();
        return frontState;
    } else {
        throw std::out_of_range("Queue is empty");
    }
}

template<typename T> T WarehouseStateManager<T>::popFifoPackage()
{
    std::lock_guard<std::mutex> lock(mutex);
    if (!fifoStorageQueue.empty())
    {
        T frontState = fifoStorageQueue.front();
        fifoStorageQueue.pop();
        return frontState;
    } else {
        throw std::out_of_range("Queue is empty");
    }
}

template<typename T> WarehouseStateManager<T>::~WarehouseStateManager()
{
    delete instance;
}
