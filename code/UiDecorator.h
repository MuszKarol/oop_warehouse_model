#pragma once

#include <iostream>
#include <list>
#include "Command.h"

namespace ui
{
    class UIComponent
    {
    public:
        template <typename T> void runCommand(std::list<Command*> commands);
        virtual void display() = 0;
        virtual ~UIComponent() = default;
    };

    class ConcreteUIComponent : public UIComponent
    {
    public:
        void display() override;
    };

    class StorageManagementMenuDecorator : public UIComponent
    {
        UIComponent& wrappedComponent;
        std::list<Command*> commands;

    public:
        StorageManagementMenuDecorator(UIComponent& component, std::list<Command*> commands);

        void display() override;
        void setupNewStorage();
        void manageStorage();
        void deleteStorage();
        void displayWarehouseCapacity();
    };

    class PackageManagementMenuDecoratorDecorator : public UIComponent
    {
        UIComponent& wrappedComponent;
        std::list<Command*> commands;

    public:
        PackageManagementMenuDecoratorDecorator(UIComponent& component, std::list<Command*> commands);

        void display() override;
        void addPackage();
        void removePackage();
    };

    class BaseUiDecorator : public UIComponent
    {
        UIComponent& wrappedComponent;
        std::list<Command*> commands;

    public:
        BaseUiDecorator(UIComponent& component, std::list<Command*> commands);

        void display() override;
    };
}
