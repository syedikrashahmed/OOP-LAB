/*Implement a restaurant ordering system that holds information about the restaurant’s menus, menu items, orders, and payments. Identify the relationship between the five entities mentioned. Keep in mind the following information as well:
a) Menu Items hold two things: food name and food price.
b) Menu is a class that holds an array of menu items. You can have different functions to add and remove items, or  display the entire menu.
c) Restaurant ordering system has one menu.
d) Any staff member can place an order to the system on behalf of a customer. The order class consists of one or more menu items and a payment.
e) Payment is a class that holds the amount of money that a customer needs to pay.This is generated when the order is placed.*/

#include <iostream>
#include <string>
using namespace std;

class MenuItem {
private:
    string foodName;
    float foodPrice;

public:
    MenuItem(string name, float price) : foodName(name), foodPrice(price) {}

    MenuItem() {
        foodName = "";
        foodPrice = 0.0;
    }

    string getFoodName() const {
        return foodName;
    }
    float getFoodPrice() const {
        return foodPrice;
    }
    void setFoodName(const string& name) {
        foodName = name;
    }
    void setFoodPrice(float price) {
        foodPrice = price;
    }

    void display() const {
        cout << "item: " << foodName << ", price: " << foodPrice << endl;
    }
};

class Menu {
private:
    MenuItem items[5];
    int itemCount;

public:
    Menu() {
        itemCount = 0;
    }

    int getItemCount() const {
        return itemCount;
    }

    void displayMenu() const {
        if (itemCount == 0) {
            cout << "menu contains no items" << endl;
        } else {
            cout << "menu items:" << endl;
            for (int i = 0; i < itemCount; i++) {
                items[i].display();
            }
        }
    }

    void addItem(const MenuItem& item) {
        if (itemCount >= 10) {
            cout << "cannot add more items." << endl;
            return;
        }
        for (int i = 0; i < itemCount; i++) {
            if (items[i].getFoodName() == item.getFoodName()) {
                cout << "item already exists in the menu." << endl;
                return;
            }
        }
        items[itemCount] = item;
        itemCount++;
        cout << "item added: " << item.getFoodName() << endl;
    }

    void removeItem(const string& foodName) {
        bool found = false;
        for (int i = 0; i < itemCount; i++) {
            if (items[i].getFoodName() == foodName) {
                for (int j = i; j < itemCount - 1; j++) {
                    items[j] = items[j + 1];
                }
                itemCount--;
                found = true;
                cout << "Item removed: " << foodName << endl;
                break;
            }
        }
        if (!found) {
            cout << "Item not found: " << foodName << endl;
        }
    }

    MenuItem getItem(int index) const {
        return items[index];
    }
};

class Payment {
private:
    float amount;

public:
    Payment(float amount) : amount(amount) {}

    Payment() {
        amount = 0;
    }

    float getAmount() const {
        return amount;
    }
    void setAmount(float amount) {
        this->amount = amount;
    }

    void displayPaymentDetails() const {
        cout << "payment amount: " << amount << endl;
    }
};

class Order {
private:
    MenuItem items[10];
    int itemCount;
    Payment payment;

public:
    Order() : itemCount(0), payment(0.0) {}

    void addItem(const MenuItem& item) {
        if (itemCount < 10) {
            items[itemCount] = item;
            itemCount++;
            cout << "item added to order: " << item.getFoodName() << endl;
        } else {
            cout << "cannot add more items." << endl;
        }
    }

    void calculatePayment() {
        float total = 0.0;
        for (int i = 0; i < itemCount; i++) {
            total += items[i].getFoodPrice();
        }
        payment.setAmount(total);
        cout << "Total payment calculated: " << total << endl;
    }

    void displayOrder() const {
        cout << "order details:" << endl;
        for (int i = 0; i < itemCount; i++) {
            items[i].display();
        }
        payment.displayPaymentDetails();
    }
};

class Restaurant {
private:
    Menu menu;

public:
    void displayMenu() const {
        menu.displayMenu();
    }

    void addMenuItem(const MenuItem& item) {
        menu.addItem(item);
    }

    void removeMenuItem(const string& foodName) {
        menu.removeItem(foodName);
    }

    Order placeOrder() {
        Order order;
        int choice;
        do {
            cout << "enter the index of the item to add, -1 to finish: ";
            cin >> choice;
            if (choice >= 0 && choice < menu.getItemCount()) {
                order.addItem(menu.getItem(choice));
            } else if (choice != -1) {
                cout << "invalid choice" << endl;
            }
        } while (choice != -1);
        order.calculatePayment();
        return order;
    }
};

int main() {
    Restaurant restaurant;

    restaurant.addMenuItem(MenuItem("pulao", 220.00));
    restaurant.addMenuItem(MenuItem("zinger cheese shawarma", 600.50));
    restaurant.addMenuItem(MenuItem("mayo roll", 350.00));
    restaurant.displayMenu();
    Order order = restaurant.placeOrder();
    order.displayOrder();
}