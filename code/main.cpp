#include <iostream>
#include <vector>
#include <unistd.h>
#include "Actions.h"
#include "UiDecorator.h"

class WarehouseModelApplication
{
public:
    static int run()
    {
        std::vector<Command> commands;

        ui::ConcreteUIComponent component;
        ui::StorageManagementMenuDecorator storageDecorator(component, commands);
        ui::PackageManagementMenuDecoratorDecorator packageDecorator(storageDecorator, commands);
        ui::BaseUiDecorator finalUI(packageDecorator, commands);

        int choice;

        do
        {
            finalUI.display();
            std::cout << "Enter choice: ";
            std::cin >> choice;

            switch (choice)
            {
            case 1:
                storageDecorator.setupNewStorage();
                break;
            case 2:
                storageDecorator.setupStorage();
                break;
            case 3:
                storageDecorator.deleteStorage();
                break;
            case 4:
                packageDecorator.addPackage();
                break;
            case 5:
                packageDecorator.removePackage();
                break;
            case 6:
                std::cout << "Exiting program." << std::endl;
                break;
            default:
                std::cout << "Try again." << std::endl;
                break;
            }

            sleep(1);
        }
        while (choice != 6);


        return 0;
    }
};

int main()
{
    return WarehouseModelApplication::run();
}

