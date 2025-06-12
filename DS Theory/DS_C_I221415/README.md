# 2D Maze Game

Welcome to the **2D Maze Game**! This is a console-based game where players navigate through a dark maze, seeking to find a hidden key and escape through a door. Along the way, players can collect coins, avoid bombs, and utilize a limited undo feature to backtrack their movements. The game features three difficulty levels, adding to the challenge and excitement.

## Table of Contents

- [Features](#features)
- [Requirements](#requirements)
- [Installation](#installation)
- [Controls](#controls)
- [Game Mechanics](#game-mechanics)
- [Contribution](#contribution)
- [License](#license)
- [Contact](#contact)

## Features

- **Dynamic Maze Generation**: Randomly generated maze for each game session with hidden keys and doors.
- **Player Movement**: Navigate using keyboard controls (WASD).
- **Collectibles**: Collect coins for points and a key to unlock the exit door.
- **Bombs**: Avoid bombs that will end the game immediately if encountered.
- **Undo Moves**: Limited undo functionality to backtrack to previous positions.
- **Difficulty Levels**: Choose from easy, medium, and hard levels that affect the game experience.
  
## Requirements

To build and run this game, you need:

- A C++ compiler (such as g++, clang++, etc.)
- The [Ncurses](https://invisible-island.net/ncurses/) library for Linux or [PDCurses](https://pdcurses.sourceforge.io/) for Windows.

## Installation

1. **Clone the repository**:

   ```bash
   git clone https://github.com/SaimMukhtar/maze-game.git
   cd maze-game
