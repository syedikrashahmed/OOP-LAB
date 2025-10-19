/*Question 02. Football Game Simulation*/
/*The Robot class represents a robot and should have two key attributes: name, which holds the name of the robot as a string, and hits, which keeps track of the number of hits made by the robot. The class must include a method hitBall(int &ballX, int &ballY, const string &direction). This method will update the ball’s position based on the direction given by the robot (either up, down, left, or right), and it will also increment the robot’s hit count each time the ball is hit*/

#include <iostream>
using namespace std;
#include <string>

class Robot {
    string name;
    int hitCount;

    public:
    Robot() {
        name = "";
        hitCount = 0;
    }

    Robot(string n) {
        name = n;
        hitCount = 0;
    }

    string getName() {
        return name;
    }

    int getHits() {
        return hitCount;
    }

    void hitBall(int &ballX, int &ballY, const string &direction) {
        hitCount++;
        if (direction == "up") {
            ballY++;
            return;
        }
        else if (direction == "down") {
            ballY--;
            return;
        }
        else if (direction == "left") {
            ballX--;
            return;
        }
        else if (direction == "right") {
            ballX++;
            return;
        }
        else {
            cout << "Incorrect direction" << endl;
        }
    }
};

/*For ball position on the field specify by x and y, representing the ball's current position on the field. The class should provide methods such as getX() and getY() to return the current x and y coordinates of the ball, respectively. Additionally, the method move(int dx, int dy) will update the ball’s position based on the movement made by the robot, and the method getPosition() will return the ball's position as a tuple (x, y) formate..*/

struct ballPos {
    int x; 
    int y;
};

class Ball {
    int x;
    int y;

    public:
    Ball() {
        x = 0; 
        y = 0;
    }

    Ball(int xi, int yi) {
        x = xi; 
        y = yi;
    }

    void resetBall() {
        x = 0; 
        y = 0;
    }

    int getX() {
        return x;
    }

    int getY() {
        return y;
    }

    void move(int dx, int dy) {
        x += dx;
        y += dy;
    }

    ballPos getPosition() {
        return {x, y};
    }
};

/*Goal's position on the field designed by x and y, which define the coordinates of the goal (set to
(3, 3) for this assignment. isGoalReached(int ballX, int ballY), which will check whether the ball's
position matches the goal’s coordinates*/

class Goal {
    int x; 
    int y;

    public:
    Goal() {
        x = 3; 
        y = 3;
    }

    bool isGoalReached(int ballX, int ballY) {
        if (ballX == x && ballY == y) {
            return true;
        }
        return false;
    }

    void display() {
        cout << "position of goal is (" << x << ", " << y << ")" << endl;
    }
};

/*The Team class represents a football team, which consists of robot player. The team has a
teamName attribute to store the name of the team and a robot attribute that holds a pointer to a
Robot object, which represents the player.*/

class Team {
    string name;
    Robot *player;

    public:
    Team() {
        name = "";
        player = nullptr;
    }

    Team(string n, Robot *r) {
        name = n;
        player = r;
    }

    string getName() {
        return name;
    }

    Robot * getPlayer() {
        return player;
    }
};

/*The Game class manages the entire game flow. It holds two Team objects (teamOne and teamTwo), a Ball object, and a Goal object. The class includes the method startGame(), which starts the game, letting each team play its turn. The play(Team *team) method simulates the game for a given team, moving the ball towards the goal and counting the number of hits made by the robot. After both teams have played, the declareWinner() method compares the number of hits made by each robot and declares the team with the fewer hits as the winner.*/

class Game {
    Team *teamOne;
    Team *teamTwo;
    Ball *ball;
    Goal *goal;

    public:
    Game() {
        teamOne = nullptr;
        teamTwo = nullptr;
        ball = new Ball;
        goal = new Goal;
    }
    
    Game(Team *t1, Team *t2) {
        teamOne = t1;
        teamTwo = t2;
        ball = new Ball;
        goal = new Goal;
    }

    void startGame() {
        goal->display();
        play(teamOne);
        ball->resetBall();
        play(teamTwo);
        declareWinner();
    }

    void play(Team *team) {
        string dir;
        Robot *p = team->getPlayer();
        while(!(goal->isGoalReached(ball->getX(), ball->getY()))) {
            cout << "Enter direction for team " << team->getName() << ": ";
            cin >> dir; 

            int ballX = ball->getX();
            int ballY = ball->getY();

            p->hitBall(ballX, ballY, dir);

            ball->move(ballX - ball->getX(), ballY - ball->getY());

            cout << "Ball Position: (" << ball->getX() << ", " << ball->getY() << ")" << endl;
        }
    }

    void declareWinner() {
        Robot *p1 = teamOne->getPlayer();
        Robot *p2 = teamTwo->getPlayer();
        if (p1->getHits() < p2->getHits()) {
            cout << teamOne->getName() << " is the winner!!" << endl;
        }
        else if (p1->getHits() > p2->getHits()) {
            cout << teamTwo->getName() << " is the winner!!" << endl;
        }
        else {
            cout << "It is a draw!!" << endl;
        }
    }

    ~Game() {
        delete ball;
        delete goal;
    }
};

int main() {
    Robot robot1("Alpha");
    Robot robot2("Beta");
    Team team1("Team A", &robot1);
    Team team2("Team B", &robot2);
    Game game(&team1, &team2);
    game.startGame();
}
