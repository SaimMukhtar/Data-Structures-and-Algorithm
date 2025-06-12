#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <stack>
#include <cmath>
#include <unistd.h> // for sleep function on UNIX systems

#define MAX_UNDO 6

class Node {
public:
    bool isEmpty;
    bool hasKey;
    bool hasDoor;
    bool hasCoin;
    bool hasBomb;
    Node* up;
    Node* down;
    Node* left;
    Node* right;

    Node() : isEmpty(true), hasKey(false), hasDoor(false), hasCoin(false), hasBomb(false), up(nullptr), down(nullptr), left(nullptr), right(nullptr) {}
};

class Game {
private:
    Node*** grid;
    int playerX, playerY;
    int keyX, keyY;
    int doorX, doorY;
    int movesLeft;
    int undoCount;
    int score;
    std::vector<std::pair<int, int>> coinsCollected;
    std::stack<std::pair<int, int>> moveStack;

    void initializeGrid(int size);
    void placeElements(int size);
    void displayGrid(int size);
    void displayStatus();

public:
    Game(int difficulty);
    ~Game();
    void movePlayer(char direction);
    void senseKey();
    void collectCoin();
    void checkGameOver();
    void undoMove();
    int calculateManhattanDistance(int x1, int y1, int x2, int y2);
    void start();
};

#endif // GAME_H
