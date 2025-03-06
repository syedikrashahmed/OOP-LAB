/*Write a program that uses composition to implement a game engine. A game engine is made up of several components. For example:
a) Graphics rendering engine
b) Input handler
c) Physics engine
You don’t have to write the logicforhow these individual components work.*/

#include <iostream>
using namespace std;

class GraphicsRenderingEngine {
    public:
    void runRenderingEngine() {
        cout << "graphics rendering engine is running" << endl;
    }
};

class InputHandler {
    public:
    void runInputHandler() {
        cout << "input handler is running" << endl;
    }
};

class PhysicsEngine {
    public:
    void runPhyEngine() {
        cout << "physics engine is running" << endl;
    }
};

class GameEngine {
    private:
    GraphicsRenderingEngine grEngine;  
    InputHandler inputHandler;          
    PhysicsEngine physicsEngine;        
    
    public:
    GameEngine() {
        cout << "game engine created" << endl;
    }
    
    void run() {
        cout << "game engine running" << endl;
        inputHandler.runInputHandler();
        physicsEngine.runPhyEngine();
        grEngine.runRenderingEngine();
    }

    ~GameEngine() {
        cout << "game engine destroyed" << endl;
    }
};

int main() {
    GameEngine gameEngine;
    gameEngine.run();
}