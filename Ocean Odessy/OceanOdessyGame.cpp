#include <ctime>
#include <graphics.h>
#include <iostream>
#include "gameObjects.h"
using namespace std;


int main() {
    // Initialization
    srand(static_cast<unsigned>(time(0)));
    initwindow(SCREEN_WIDTH, SCREEN_HEIGHT);
    setbkcolor(CYAN);
    int page = 0;

    // Creating objects
    Fish fish;
    Jellyfish jellyfish;
    Starfish starfish;
    Shark shark;
    Prey prey;

    // Game loop
    while (true) {
        // Game setup
        Gamesetup gameSetup;
        gameSetup.gameworking();

        setactivepage(page);
        setvisualpage(1 - page);
        cleardevice();

        // User input handling
        if (kbhit()) {
            char key = getch();
            if (key == 0 || key == 224) {
                key = getch(); // Read the extended key code
                switch (key) {
                    case 72: fish.move(0, -10); break; // Up arrow
                    case 80: fish.move(0, 10); break;  // Down arrow
                    case 75: fish.move(-10, 0); break; // Left arrow
                    case 77: fish.move(10, 0); break;  // Right arrow
                }
            }
        }

        // Drawing objects
        fish.draw();
        jellyfish.draw();
        starfish.draw();
        shark.draw();
        prey.draw();

        // Moving objects
        jellyfish.move();
        starfish.move();
        shark.move();
        prey.move();

        // Checking collisions
        checkCollision(fish, jellyfish);
        checkCollision(fish, starfish);
        checkCollision(fish, shark);
        checkCollision(fish, prey);

        // Displaying score
        stringstream ss;
        ss << "Score: " << score;
        string scoreString = ss.str();
        char *scoreText = &scoreString[0];
        outtextxy(10, 10, scoreText);

        delay(10);
        page = 1 - page;
    }

    closegraph();
    return 0;
}
