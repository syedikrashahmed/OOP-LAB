/*Task 7:
Create a class for a stationary shop. The stationary shop maintains a list for all the items that it sells (hint: array of
strings), and another list with the prices of the items (hint: array of prices).
Create a menu-driven program to:
1. Allow the shop owner to add the items and their prices.
2. Fetch the list of items
3. Edit the prices of the items
4. View all the items and their prices
Create a receipt that the shopkeeper can share with their customers. The receipt can only be created after the
shopkeeper inputs the items and their amounts bought by the customer.*/

#include <iostream>
using namespace std;

class Stationary {
    string items[100];
    float prices[100];
    static int nextIndex;

    public:
    Stationary() {
        for (int i = 0; i < 100; i++) {
            items[i] = "";
            prices[i] = 0.00;
        }
    }

    void addItem(string item, float price) {
        if (nextIndex < 100) {
            items[nextIndex] = item;
            prices[nextIndex] = price;
            nextIndex++;
            cout << "Item Added Successfully" << endl;
        }
        else {
            cout << "Inventory Full " << endl;
        }
    }

    void searchItem (string item) {
        bool found = false;
        for (int i = 0; i < 100; i++) {
            if (items[i] == item) {
                found = true;
                break;
            }
        }
        if (found == true) {
            cout << "Item Found" << endl; 
        }
        else {
            cout << "Item Not Found" << endl; 
        }
    }

    void editPrice(string item, float newprice) {
        bool found = false; int index;
        for (int i = 0; i < 100; i++) {
            if (items[i] == item) {
                found = true;
                index = i;
                break;
            }
        }
        if (found == true) {
            prices[index] = newprice;
        }
        else {
            cout << "Item Not Found" << endl; 
        }
    }

    void displayAll() {
        cout << "Displaying All Items In Inventory" << endl;
        cout << "    Items\tPrices" << endl;
        for (int i = 0; i < nextIndex; i++) {
            cout << i + 1 << ".   " << items[i]<< " \t   " << prices[i] << endl;
        }
    }

    void receipt() {
        int bought[100], choice, totalItems = 0; 
        float totalprice = 0.0;
        for (int i = 0; i < 100; i++) {
            bought[i] = -1;
        }
        while(1) { //user buying
            cout << "enter index of item you want to purchase (-1 to exit):";
            cin >> choice;
            if (choice == -1) {
                break;
            }
            else if (choice < 1 && choice > nextIndex) {
                cout << "Invalid Index" << endl;
            }
            else {
                bought[choice - 1] = 1;
                cout << "Item bought" << endl;
                totalprice = totalprice + prices[choice - 1];
                totalItems++;
            }
        }
        //receipt
        cout << endl << "Receipt: " << endl;
        cout << "Items\tPrices" << endl;
        for (int i = 0; i < 100; i++) {
            if (bought[i] == 1) {
                cout << items[i] << "\t" << prices[i] << endl;
            }
        }
        cout << "Total Price: $" << totalprice << endl;
    }
};

int Stationary:: nextIndex = 0; 

int main() {
    Stationary shop;
    string item; float price;
    int choice;
    while(1) {
        cout << endl << "Press 1 to Add Item" << endl << "Press 2 to Fetch Item" << endl << "Press 3 to Edit Price of Item" << endl << "Press 4 to View All Items In Inventory" << endl << "Press 5 to Print Receipt" << endl << "Press -1 to Exit" << endl << "Enter Choice: ";
        cin >> choice;
        if (choice == -1) {
            break;
        }

        switch(choice) {
            case 1: 
                cout << "Enter Item to Add: ";
                cin >> item;
                cout << "Enter Price: ";
                cin >> price;
                shop.addItem(item, price);
            break;
            case 2: 
                cout << "Enter Item to Fetch: ";
                cin >> item;
                shop.searchItem(item);
            break;
            case 3: 
                cout << "Enter Item to Edit: ";
                cin >> item;
                cout << "Enter New Price: ";
                cin >> price;
                shop.editPrice(item, price);
            break;
            case 4: 
                shop.displayAll();
            break;
            case 5: 
                shop.receipt();
            break;
            default:
                cout << "Invalid Choice" << endl;
        }
    }
}