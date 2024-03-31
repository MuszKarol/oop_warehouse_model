#pragma once

#include <iostream>
#include <vector>
#include "Actions.h"

namespace ui
{
    class UIComponent
    {
    public:
        virtual void display() = 0;
        virtual ~UIComponent() = default;
    };

    class ConcreteUIComponent final : public UIComponent
    {
    public:
        void display() override;
    };

    class StorageManagementMenuDecorator final : public UIComponent
    {
        UIComponent& wrappedComponent;
        std::vector<Command>& commands;

    public:
        StorageManagementMenuDecorator(UIComponent& component, std::vector<Command>& commands);

        void display() override;
        void setupNewStorage();
        void setupStorage();
        void deleteStorage();
    };

    class PackageManagementMenuDecoratorDecorator final : public UIComponent
    {
        UIComponent& wrappedComponent;
        std::vector<Command>& commands;

    public:
        PackageManagementMenuDecoratorDecorator(UIComponent& component, std::vector<Command>& commands);

        void display() override;
        void addPackage();
        void removePackage();
    };

    class BaseUiDecorator final : public UIComponent
    {
        UIComponent& wrappedComponent;
        std::vector<Command>& commands;

    public:
        BaseUiDecorator(UIComponent& component, std::vector<Command>& commands);

        void display() override;
    };
}
