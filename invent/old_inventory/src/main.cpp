#include <iostream>
#include <fstream>
#include <vector>
#include <string>

struct Item {
    std::string name;
    std::string description;
    int quantity;
};

std::vector<Item> inventory;

void addItem() {
    Item newItem;
    std::cout << "Enter item name: ";
    std::getline(std::cin, newItem.name);
    std::cout << "Enter item description: ";
    std::getline(std::cin, newItem.description);
    std::cout << "Enter quantity: ";
    std::cin >> newItem.quantity;
    std::cin.ignore(); // Ignore the newline character after entering quantity
    inventory.push_back(newItem);
    std::cout << "Item added successfully.\n\n";
}

void saveInventory() {
    std::ofstream file("inventory.txt");
    for (const auto& item : inventory) {
        file << item.name << "," << item.description << "," << item.quantity << std::endl;
    }
    file.close();
    std::cout << "Inventory saved to file.\n";
}

void generateReport() {
    std::ofstream report("report.txt");
    report << "Inventory Report\n\n";
    for (const auto& item : inventory) {
        report << "Name: " << item.name << "\nDescription: " << item.description << "\nQuantity: " << item.quantity << "\n\n";
    }
    report.close();
    std::cout << "Report generated.\n";
}

int main() {
    int choice = 0;
    do {
        std::cout << "1. Add item\n2. Save inventory\n3. Generate report\n4. Exit\nEnter your choice: ";
        std::cin >> choice;
        std::cin.ignore(); // Ignore the newline character after entering choice

        switch (choice) {
            case 1:
                addItem();
                break;
            case 2:
                saveInventory();
                break;
            case 3:
                generateReport();
                break;
            case 4:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 4);

    return 0;
}
