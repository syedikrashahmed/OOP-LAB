#include <iostream>
using namespace std;
#include <string>

// TASK # 02
// An E-commerce website provides multiple ways to calculate the total price of a customer&#39;s
// order based on the type of product. There are two main product categories:
// 1. Electronics: Tax rate 15%
// 2. Clothing: Tax rate 5%
// The website supports different discount methods based on the type of user (Regular or
// Premium). Additionally, the website allows combining multiple carts and applying arithmetic
// operations to calculate total prices dynamically.
// Task Requirements:
// 1. Create a base class Product with attributes like productID, price, and a virtual function
// calculatePrice().
class Product {
    protected:
    string productID;
    double price;

    public:
    Product(string productID, double price) : productID(productID), price(price) {}

    Product() : productID(""), price(0.0) {}
    virtual void calculatePrice() {}

    // 3. Overload the applyDiscount method to handle different discount types:
    // o Percentage discount (e.g., 10% off)
    // o Fixed discount (e.g., $20 off)
    // o Buy One Get One Free
    void applyDiscount(double percentage) {
        price -= price * percentage / 100;
    }
    void applyDiscount(const double fixedAmount) {
        price -= fixedAmount;
    }
    void applyDiscount() {
        cout << "Buy One Get One Free" << endl;
    }
    
};

// 2. Implement two derived classes:
// o Electronics (Applies 15% tax)
class Electronics : public Product {
    float taxRate;
    public:
    Electronics(string productID, double price) : Product(productID, price) {}

    Electronics() : Product(), taxRate(0.15) {}
    // 4. Override the calculatePrice method to apply category-specific tax rates.
    void calculatePrice() {
        price += price * taxRate;
    }
};

// o Clothing (Applies 5% tax)
class Clothing : public Product {
    float taxRate;
    public:
    Clothing(string productID, double price) : Product(productID, price) {}

    Clothing() : Product(), taxRate(0.05) {}

    void calculatePrice() {
        price += price * taxRate;
    }
};

class ShoppingCart {
    Product* products;
    int numProducts;

    public:
    ShoppingCart() : products(nullptr), numProducts(0) {}

    ~ShoppingCart() {
        delete[] products;
    }

    friend ShoppingCart operator+(const ShoppingCart& cart1, const ShoppingCart& cart2);
    friend ShoppingCart operator-(const ShoppingCart& cart1, Product& product);
};
// 5. Implement operator overloading for the ShoppingCart class:
// o + to merge two shopping carts
ShoppingCart operator+(const ShoppingCart& cart1, const ShoppingCart& cart2) {
    ShoppingCart result;
    result.numProducts = cart1.numProducts + cart2.numProducts;
    result.products = new Product[result.numProducts];
    for (int i = 0; i < cart1.numProducts; i++) {
        result.products[i] = cart1.products[i];
    }
    for (int i = 0; i < cart2.numProducts; i++) {
        result.products[cart1.numProducts + i] = cart2.products[i];
    }
    return result;
}

// o - to remove an item from the cart
    ShoppingCart operator-(const ShoppingCart& cart1, Product& product) {
        ShoppingCart result;
    }

// o * to apply bulk discounts
// o / to split cart total among multiple users

// 6. Create objects for Electronics and Clothing categories, demonstrate method overloading,
// overriding, and operator overloading by simulating an online shopping experience.



