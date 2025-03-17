#include <iostream>
#include <string>
#include <cmath>
using namespace std;

const double PI = 3.14159;

class Shape {
protected:
    string location;
    string fillColor;
    int borderSize;

public:
    Shape(string loc, string col, int border = 0) : location(loc), fillColor(col), borderSize(border) {}

    virtual void render() {
        cout << "Rendering a shape at location " << location 
             << " with fill color " << fillColor 
             << " and border size " << borderSize << endl;
    }

    virtual double computeArea() {}; 
    virtual double computeCircumference() {}; 
    virtual ~Shape() {}
};

class Circle : public Shape {
private:
    double radius;
    string centerLocation;

public:
    Circle(string loc, string col, double r, int border = 0) : Shape(loc, col, border), radius(r), centerLocation(loc) {}

    void render() override {
        cout << "drawing a circle at center location " << centerLocation  << " with fill color " << fillColor  << ", border size " << borderSize  << ", and radius " << radius << endl;
    }

    double computeArea() override {
        return PI * radius * radius;
    }

    double computeCircumference() override {
        return 2 * PI * radius;
    }
};

class Rectangle : public Shape {
private:
    double length;
    double breadth;
    string topLeftLocation;

public:
    Rectangle(string loc, string col, double l, double b, int border = 0) : Shape(loc, col, border), length(l), breadth(b), topLeftLocation(loc) {}

    void render() override {
        cout << "Rendering a rectangle at top-left location " << topLeftLocation  << " with fill color " << fillColor  << ", border size " << borderSize  << ", length " << length << ", and breadth " << breadth << endl;
    }

    double computeArea() override {
        return length * breadth;
    }

    double computeCircumference() override {
        return 2 * (length + breadth);
    }
};

class Triangle : public Shape {
private:
    double edge1, edge2, edge3;

public:
    Triangle(string loc, string col, double e1, double e2, double e3, int border = 0) : Shape(loc, col, border), edge1(e1), edge2(e2), edge3(e3) {}

    void render() override {
        cout << "Rendering a triangle at location " << location  << " with fill color " << fillColor  << ", border size " << borderSize  << ", and edges " << edge1 << ", " << edge2 << ", " << edge3 << endl;
    }

    double computeArea() override {
        double semiPerimeter = (edge1 + edge2 + edge3) / 2;
        return sqrt(semiPerimeter * (semiPerimeter - edge1) * (semiPerimeter - edge2) * (semiPerimeter - edge3));
    }

    double computeCircumference() override {
        return edge1 + edge2 + edge3;
    }
};

class Polygon : public Shape {
private:
    int numberOfSides;
    double* sideLengths; 

public:
    Polygon(string loc, string col, int numSides, double* lengths, int border = 0) : Shape(loc, col, border), numberOfSides(numSides) {
        sideLengths = new double[numberOfSides];  
        for (int i = 0; i < numberOfSides; i++) {
            sideLengths[i] = lengths[i];
        }
    }

    void render() override {
        cout << "Rendering a polygon at location " << location 
             << " with fill color " << fillColor 
             << ", border size " << borderSize 
             << ", and " << numberOfSides << " sides of lengths: ";
        for (int i = 0; i < numberOfSides; i++) {
            cout << sideLengths[i] << " ";
        }
        cout << endl;
    }

    double computeArea() override {
        double perimeter = computeCircumference();
        double apothem = sideLengths[0] / (2 * tan(PI / numberOfSides));
        return (perimeter * apothem) / 2;
    }

    double computeCircumference() override {
        double perimeter = 0;
        for (int i = 0; i < numberOfSides; i++) {
            perimeter += sideLengths[i];
        }
        return perimeter;
    }

    ~Polygon() {
        delete[] sideLengths; 
    }
};

int main() {
    Circle circle("50, 50", "Black", 30.0);
    Rectangle rectangle("100,100", "white", 5.0, 10.0);
    Triangle triangle("150,150", "Green", 2.0, 4.0, 5.0);

    double polygonSides[] = {4.0, 4.0, 4.0, 3.0}; 
    Polygon polygon("400,400", "Yellow", 4, polygonSides);

    Shape* shapes[] = {&circle, &rectangle, &triangle, &polygon};

    for (int i = 0; i < 4; i++) {
        shapes[i]->render();
        cout << "Area: " << shapes[i]->computeArea() << endl;
        cout << "Circumference: " << shapes[i]->computeCircumference() << endl;
        cout << endl;
    }
}
