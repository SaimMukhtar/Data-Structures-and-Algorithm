#include "game.h"

// Constructor
Game::Game(int difficulty) {
    srand(static_cast<unsigned>(time(0))); // Seed for random number generation
    score = 0;

    switch (difficulty) {
        case 1: // Easy
            movesLeft = 6 + (rand() % 10); // Base moves plus random
            undoCount = MAX_UNDO;
            initializeGrid(10);
            break;
        case 2: // Medium
            movesLeft = 2 + (rand() % 10);
            undoCount = 4;
            initializeGrid(15);
            break;
        case 3: // Hard
            movesLeft = rand() % 10;
            undoCount = 1;
            initializeGrid(20);
            break;
    }
    placeElements(gridSize);
}

Game::~Game() {
    // Free up allocated memory
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            delete grid[i][j];
        }
        delete[] grid[i];
    }
    delete[] grid;
}

// Initialize grid with nodes
void Game::initializeGrid(int size) {
    gridSize = size;
    grid = new Node**[gridSize];
    for (int i = 0; i < gridSize; i++) {
        grid[i] = new Node*[gridSize];
        for (int j = 0; j < gridSize; j++) {
            grid[i][j] = new Node();
        }
    }

    // Connect nodes
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            if (i > 0) grid[i][j]->up = grid[i - 1][j];
            if (i < gridSize - 1) grid[i][j]->down = grid[i + 1][j];
            if (j > 0) grid[i][j]->left = grid[i][j - 1];
            if (j < gridSize - 1) grid[i][j]->right = grid[i][j + 1];
        }
    }
}

// Place player, key, door, coins, and bombs
void Game::placeElements(int size) {
    // Place player at random start position
    playerX = rand() % size;
    playerY = rand() % size;

    // Place key and door
    do {
        keyX = rand() % size;
        keyY = rand() % size;
    } while (keyX == playerX && keyY == playerY);

    do {
        doorX = rand() % size;
        doorY = rand() % size;
    } while ((doorX == playerX && doorY == playerY) || (doorX == keyX && doorY == keyY));

    // Place bombs and coins randomly
    for (int i = 0; i < 5; i++) {
        int bombX, bombY;
        do {
            bombX = rand() % size;
            bombY = rand() % size;
        } while ((bombX == playerX && bombY == playerY) || (bombX == keyX && bombY == keyY) || (bombX == doorX && bombY == doorY));

        grid[bombX][bombY]->hasBomb = true;
    }

    for (int i = 0; i < 5; i++) {
        int coinX, coinY;
        do {
            coinX = rand() % size;
            coinY = rand() % size;
        } while ((coinX == playerX && coinY == playerY) || (coinX == keyX && coinY == keyY) || (coinX == doorX && coinY == doorY));

        grid[coinX][coinY]->hasCoin = true;
    }
}

// Move player in the specified direction
void Game::movePlayer(char direction) {
    int nextX = playerX, nextY = playerY;

    if (direction == 'w') nextX--; // up
    else if (direction == 's') nextX++; // down
    else if (direction == 'a') nextY--; // left
    else if (direction == 'd') nextY++; // right

    if (nextX < 0 || nextX >= gridSize || nextY < 0 || nextY >= gridSize) {
        std::cout << "You can't move outside the maze!" << std::endl;
        return;
    }

    // Save current position to stack for undo
    moveStack.push({playerX, playerY});
    playerX = nextX;
    playerY = nextY;
    movesLeft--;

    if (grid[playerX][playerY]->hasCoin) {
        collectCoin();
    }

    // Check if the player stepped on a bomb
    if (grid[playerX][playerY]->hasBomb) {
        std::cout << "Game Over! You hit a bomb." << std::endl;
        exit(0);
    }

    senseKey();
    checkGameOver();
}

// Sense the distance to the key
void Game::senseKey() {
    int distance = calculateManhattanDistance(playerX, playerY, keyX, keyY);
    if (distance == 0) {
        std::cout << "You found the key!" << std::endl;
        grid[playerX][playerY]->hasKey = true; // Player obtains the key
    } else {
        std::cout << "Distance to key: " << distance << std::endl;
        std::cout << (distance < 2 ? "Getting Closer" : "Further Away") << std::endl;
    }
}

// Collect coin and update score
void Game::collectCoin() {
    score += 2; // Add points for coin collection
    movesLeft++; // Grant additional undo move
    coinsCollected.push_back({playerX, playerY});
    grid[playerX][playerY]->hasCoin = false; // Remove coin from grid
}

// Calculate Manhattan Distance
int Game::calculateManhattanDistance(int x1, int y1, int x2, int y2) {
    return std::abs(x1 - x2) + std::abs(y1 - y2);
}

// Check for game over conditions
void Game::checkGameOver() {
    if (playerX == doorX && playerY == doorY && grid[playerX][playerY]->hasKey) {
        std::cout << "Congratulations! You escaped the maze!" << std::endl;
        std::cout << "Your score: " << score << std::endl;
        exit(0);
    }

    if (movesLeft <= 0) {
        std::cout << "Game Over! You ran out of moves." << std::endl;
        exit(0);
    }

    displayStatus();
}

// Display game status
void Game::displayStatus() {
    std::cout << "Moves Left: " << movesLeft << std::endl;
    std::cout << "Undo Moves Left: " << undoCount << std::endl;
    std::cout << "Score: " << score << std::endl;
}

// Undo last move
void Game::undoMove() {
    if (moveStack.empty() || undoCount <= 0) {
        std::cout << "Cannot undo!" << std::endl;
        return;
    }

    auto lastMove = moveStack.top();
    moveStack.pop();
    playerX = lastMove.first;
    playerY = lastMove.second;
    undoCount--;
}

// Start the game loop
void Game::start() {
    char input;
    while (true) {
        displayGrid(gridSize);
        std::cout << "Enter your move (w/a/s/d) or 'u' to undo: ";
        std::cin >> input;

        if (input == 'u') {
            undoMove();
        } else {
            movePlayer(input);
        }
    }
}

// Display the current state of the grid
void Game::displayGrid(int size) {
    system("clear"); // Clear console for Linux, use system("CLS") for Windows
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == playerX && j == playerY) {
                std::cout << "P "; // Player
            } else if (i == keyX && j == keyY) {
                std::cout << "K "; // Key
            } else if (i == doorX && j == doorY) {
                std::cout << "D "; // Door
            } else if (grid[i][j]->hasCoin) {
                std::cout << "C "; // Coin
            } else if (grid[i][j]->hasBomb) {
                std::cout << "B "; // Bomb
            } else {
                std::cout << ". "; // Empty space
            }
        }
        std::cout << std::endl;
    }
}
