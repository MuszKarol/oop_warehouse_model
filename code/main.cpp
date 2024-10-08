#include <iostream>
#include "Command.h"
#include "UiDecorator.h"


class WarehouseModelApplication {
public:
    static int run() {
        std::list<Command *> commands;
        initCommands(commands);

        ui::ConcreteUIComponent component;
        ui::StorageManagementMenuDecorator storageDecorator(component, commands);
        ui::PackageManagementMenuDecoratorDecorator packageDecorator(storageDecorator, commands);
        ui::BaseUiDecorator finalUI(packageDecorator, commands);

        int selection;

        do {
            finalUI.display();
            std::cout << "Enter number: ";
            std::cin >> selection;
            std::cout << std::endl;

            switch (selection) {
                case 1:
                    storageDecorator.setupNewStorage();
                    break;
                case 2:
                    storageDecorator.manageStorage();
                    break;
                case 3:
                    storageDecorator.deleteStorage();
                    break;
                case 4:
                    storageDecorator.displayWarehouseCapacity();
                    break;
                case 5:
                    packageDecorator.addPackage();
                    break;
                case 6:
                    packageDecorator.removePackage();
                    break;
                case 7:
                    cleanCommands(commands);
                    std::cout << "Exiting program." << std::endl;
                    break;
                default:
                    std::cout << "Try again." << std::endl;
                    break;
            }
        } while (selection != 7);

        return 0;
    }

    static void initCommands(std::list<Command *> &commands) {
        commands.push_back(new StorageManagerCommand());
        commands.push_back(new DefineStorageCommand());
        commands.push_back(new DeleteStorageCommand());
        commands.push_back(new DisplayCapacityCommand());
        commands.push_back(new AddPackageCommand());
        commands.push_back(new RemovePackageCommand());
    }

private:
    static void cleanCommands(std::list<Command *> const &commands) {
        for (auto cmd: commands) {
            delete cmd;
        }
    }
};

int main() {
    return WarehouseModelApplication::run();
}