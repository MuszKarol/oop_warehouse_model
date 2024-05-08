#include "../UiDecorator.h"
#include <list>
#include <utility>

namespace ui {
    void ConcreteUIComponent::display() {
        std::cout << "User menu\n\n";
    }

    template<typename CommandType>
    void UIComponent::runCommand(std::list<Command *> commands) {
        for (Command *command: commands) {
            auto *typedCommand = dynamic_cast<CommandType *>(command);
            if (typedCommand != nullptr) {
                typedCommand->execute();
            }
        }
    }

    StorageManagementMenuDecorator::StorageManagementMenuDecorator(UIComponent &component,
                                                                   std::list<Command *> commands)
            : wrappedComponent(component), commands(std::move(commands)) {

    }

    void StorageManagementMenuDecorator::display() {
        wrappedComponent.display();
        std::cout << "1.  Add new storage" << std::endl;
        std::cout << "2.  Configure existing storage" << std::endl;
        std::cout << "3.  Remove existing storage" << std::endl;
        std::cout << "4.  Display warehouse capacity" << std::endl;
    }

    void StorageManagementMenuDecorator::setupNewStorage() {
        runCommand<DefineStorageCommand>(commands);
    }

    void StorageManagementMenuDecorator::manageStorage() {
        runCommand<StorageManagerCommand>(commands);
    }

    void StorageManagementMenuDecorator::deleteStorage() {
        runCommand<DeleteStorageCommand>(commands);
    }

    void StorageManagementMenuDecorator::displayWarehouseCapacity() {
        runCommand<DisplayCapacityCommand>(commands);
    }

    PackageManagementMenuDecoratorDecorator::PackageManagementMenuDecoratorDecorator(UIComponent &component,
                                                                                     std::list<Command *> commands)
            : wrappedComponent(component), commands(std::move(commands)) {
    }

    void PackageManagementMenuDecoratorDecorator::display() {
        wrappedComponent.display();
        std::cout << "5.  Add new package" << std::endl;
        std::cout << "6.  Pop existing package" << std::endl;
    }

    void PackageManagementMenuDecoratorDecorator::addPackage() {
        runCommand<AddPackageCommand>(commands);
    }

    void PackageManagementMenuDecoratorDecorator::removePackage() {
        runCommand<RemovePackageCommand>(commands);
    }

    BaseUiDecorator::BaseUiDecorator(UIComponent &component, std::list<Command *> commands)
            : wrappedComponent(component), commands(std::move(commands)) {

    }

    void BaseUiDecorator::display() {
        std::cout << "\n=================================\n" << std::endl;
        wrappedComponent.display();
        std::cout << "7.  Exit" << std::endl;
        std::cout << "\n=================================" << std::endl;
    }
}
