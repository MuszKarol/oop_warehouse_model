cmake_minimum_required(VERSION 3.10)

project(oop_warehouse_model)

set(SOURCES
        main.cpp
        ui/UiDecorator.cpp
        logic/Command.cpp
        model/Package.cpp
        model/Storage.cpp
        logic/WarehouseStateManager.cpp
        UiDecorator.h
        Command.h
        Models.h
        WarehouseStateManager.h
)

add_executable(main ${SOURCES})