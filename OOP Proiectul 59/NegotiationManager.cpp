#include "NegotiationManager.h"
#include "Negotiation.h"
#include <iostream>
#include <cstdlib>

void clearScreen() {
#ifdef _WIN32
    system("cls"); // Command for Windows
#else
    system("clear"); // Command for Linux/macOS
#endif
}

void NegotiationManager::displayMenu(const vector<Buyer>& buyers, const vector<Seller>& sellers, const vector<Product>& products) {
    int choice;
    do {
        clearScreen(); // Clear the screen before displaying the menu
        cout << "\nMenu:\n";
        cout << "1. Show Sellers\n";
        cout << "2. Show Buyers\n";
        cout << "3. Show Products\n";
        cout << "4. Show Possible Negotiations\n";
        cout << "5. Start a Negotiation\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        clearScreen(); // Clear the screen before displaying the selected option's content

        switch (choice) {
        case 1: {
            cout << "Sellers:\n";
            for (const auto& seller : sellers) {
                cout << "- " << seller.getName() << " (Style: " << seller.getStyle() << ")\n";
            }
            cout << "\nPress Enter to return to the menu...";
            cin.ignore();
            cin.get();
            break;
        }
        case 2: {
            cout << "Buyers:\n";
            for (const auto& buyer : buyers) {
                cout << "- " << buyer.getName() << " (Style: " << buyer.getStyle() << ", Preferred Category: " << buyer.getPreferredCategory() << ")\n";
            }
            cout << "\nPress Enter to return to the menu...";
            cin.ignore();
            cin.get();
            break;
        }
        case 3: {
            cout << "Products:\n";
            for (const auto& product : products) {
                cout << "- " << product.getName() << " (Price: " << product.getPrice() << ", Seller: " << product.getOwner()->getName() << ")\n";
            }
            cout << "\nPress Enter to return to the menu...";
            cin.ignore();
            cin.get();
            break;
        }
        case 4: {
            cout << "Possible Negotiations:\n";
            for (const auto& buyer : buyers) {
                cout << "For Buyer: " << buyer.getName() << "\n";
                for (const auto& product : products) {
                    if (product.getCategory() == buyer.getPreferredCategory()) {
                        cout << "  - " << product.getName() << " (Price: " << product.getPrice() << ", Seller: " << product.getOwner()->getName() << ")\n";
                    }
                }
            }
            cout << "\nPress Enter to return to the menu...";
            cin.ignore();
            cin.get();
            break;
        }
        case 5: {
            int buyerIndex;
            cout << "Select a buyer (1-" << buyers.size() << "): ";
            cin >> buyerIndex;

            if (buyerIndex < 1 || buyerIndex > buyers.size()) {
                cout << "Invalid buyer selection!\n";
                cout << "\nPress Enter to return to the menu...";
                cin.ignore();
                cin.get();
                break;
            }

            const Buyer& selectedBuyer = buyers[buyerIndex - 1];
            vector<const Product*> matchingProducts;

            for (const auto& product : products) {
                if (product.getCategory() == selectedBuyer.getPreferredCategory()) {
                    matchingProducts.push_back(&product);
                }
            }

            if (matchingProducts.empty()) {
                cout << "No matching products found for " << selectedBuyer.getName() << "'s preferred category: "
                    << selectedBuyer.getPreferredCategory() << ".\n";
                cout << "\nPress Enter to return to the menu...";
                cin.ignore();
                cin.get();
                break;
            }

            cout << "Matching products for " << selectedBuyer.getName() << ":\n";
            for (size_t i = 0; i < matchingProducts.size(); ++i) {
                const auto& product = matchingProducts[i];
                cout << i + 1 << ". " << product->getName()
                    << " (Price: " << product->getPrice()
                    << ", Seller: " << product->getOwner()->getName() << ")\n";
            }

            int productIndex;
            cout << "Select a product (1-" << matchingProducts.size() << "): ";
            cin >> productIndex;

            if (productIndex < 1 || productIndex > matchingProducts.size()) {
                cout << "Invalid product selection!\n";
            }
            else {
                const Product* selectedProduct = matchingProducts[productIndex - 1];
                startNegotiation(selectedBuyer, *selectedProduct->getOwner(), *selectedProduct);
            }
            cout << "\nPress Enter to return to the menu...";
            cin.ignore();
            cin.get();
            break;
        }
        case 6:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
            cout << "\nPress Enter to return to the menu...";
            cin.ignore();
            cin.get();
        }
    } while (choice != 6);
}

void NegotiationManager::startNegotiation(const Buyer& buyer, const Seller& seller, const Product& product) {
    // logic to be implemented
    cout << "Starting negotiation for " << product.getName() << " between " << buyer.getName() << " and " << seller.getName() << ".\n";
    cout << "Negotiation successful! " << buyer.getName() << " has purchased " << product.getName() << " for " << product.getPrice() << ".\n";
}