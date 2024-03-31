#include "../UiDecorator.h"

namespace ui
{
    void ConcreteUIComponent::display()
    {
        std::cout << "User menu\n\n";
    }

    StorageManagementMenuDecorator::StorageManagementMenuDecorator(UIComponent& component,
                                                                   std::vector<Command>& commands)
            : wrappedComponent(component), commands(commands)
    {

    }

    void StorageManagementMenuDecorator::display()
    {
        wrappedComponent.display();
        std::cout << "1.  Add new storage" << std::endl;
        std::cout << "2.  Configure existing storage" << std::endl;
        std::cout << "3.  Remove existing storage" << std::endl;
    }

    void StorageManagementMenuDecorator::setupNewStorage()
    {
        std::cout << "setupNewStorage()" << std::endl; //TODO run command pattern impl.
    }

    void StorageManagementMenuDecorator::setupStorage()
    {
        std::cout << "setupStorage()" << std::endl; //TODO run command pattern impl.
    }

    void StorageManagementMenuDecorator::deleteStorage()
    {
        std::cout << "setupStorage()" << std::endl; //TODO run command pattern impl.
    }

    PackageManagementMenuDecoratorDecorator::PackageManagementMenuDecoratorDecorator(UIComponent& component,
                                                                                     std::vector<Command>& commands)
            : wrappedComponent(component), commands(commands)
    {
    }

    void PackageManagementMenuDecoratorDecorator::display()
    {
        wrappedComponent.display();
        std::cout << "4.  Add new package" << std::endl;
        std::cout << "5.  Pop existing package" << std::endl;
    }

    void PackageManagementMenuDecoratorDecorator::addPackage()
    {
        std::cout << "addPackage()" << std::endl; //TODO run command pattern impl.
    }

    void PackageManagementMenuDecoratorDecorator::removePackage()
    {
        std::cout << "removePackage()" << std::endl; //TODO run command pattern impl.
    }

    BaseUiDecorator::BaseUiDecorator(UIComponent& component, std::vector<Command>& commands)
            : wrappedComponent(component), commands(commands)
    {
    }

    void BaseUiDecorator::display()
    {
        std::cout << "\n=================================\n" << std::endl;
        wrappedComponent.display();
        std::cout << "6.  Exit" << std::endl;
        std::cout << "\n=================================" << std::endl;
    }
}
