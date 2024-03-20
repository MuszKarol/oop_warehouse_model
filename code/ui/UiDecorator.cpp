#include <iostream>
#include <vector>
#include "../Actions.h"

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
        void display() override
        {
            std::cout << "User menu\n\n";
        }
    };

    class StorageManagementMenuDecorator final : public UIComponent
    {
        UIComponent& wrappedComponent;
        std::vector<Command>& commands;

    public:
        StorageManagementMenuDecorator(UIComponent& component, std::vector<Command>& commands)
            : wrappedComponent(component), commands(commands)
        {

        }

        void display() override
        {
            wrappedComponent.display();
            std::cout << "1.  Add new storage" << std::endl;
            std::cout << "2.  Configure existing storage" << std::endl;
            std::cout << "3.  Remove existing storage" << std::endl;
        }

        void setupNewStorage() const
        {
            std::cout << "setupNewStorage()" << std::endl; //TODO run command pattern impl.
        }

        void setupStorage() const
        {
            std::cout << "setupStorage()" << std::endl; //TODO run command pattern impl.
        }

        void deleteStorage() const
        {
            std::cout << "setupStorage()" << std::endl; //TODO run command pattern impl.
        }
    };

    class PackageManagementMenuDecoratorDecorator final : public UIComponent
    {
        UIComponent& wrappedComponent;
        std::vector<Command>& commands;

    public:
        PackageManagementMenuDecoratorDecorator(UIComponent& component, std::vector<Command>& commands)
            : wrappedComponent(component), commands(commands)
        {

        }

        void display() override
        {
            wrappedComponent.display();
            std::cout << "4.  Add new package" << std::endl;
            std::cout << "5.  Pop existing package" << std::endl;
        }

        void addPackage() const
        {
            std::cout << "addPackage()" << std::endl; //TODO run command pattern impl.
        }

        void removePackage() const
        {
            std::cout << "removePackage()" << std::endl; //TODO run command pattern impl.
        }
    };

    class BaseUiDecorator final : public UIComponent
    {
        UIComponent& wrappedComponent;
        std::vector<Command>& commands;

    public:
        BaseUiDecorator(UIComponent& component, std::vector<Command>& commands)
            : wrappedComponent(component), commands(commands)
        {
        }

        void display() override
        {
            std::cout << "\n=================================\n" << std::endl;
            wrappedComponent.display();
            std::cout << "6.  Exit" << std::endl;
            std::cout << "\n=================================" << std::endl;
        }
    };
}
