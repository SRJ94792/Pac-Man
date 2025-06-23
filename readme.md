# Pac-Man Game in Assembly Language

This is an implementation of the classic Pac-Man game written in x86 Assembly Language using the Irvine32 library. The game features multiple levels, a menu system, high score display, and basic gameplay mechanics such as collecting dots, avoiding ghosts, and progressing through levels.

## Table of Contents
- [Features](#features)
- [Requirements](#requirements)
- [Setup and Compilation](#setup-and-compilation)
- [How to Play](#how-to-play)
- [File Structure](#file-structure)
- [Code Overview](#code-overview)
- [Limitations](#limitations)
- [Contributing](#contributing)
- [Author](#author)

## Features
- **Menu System**: Includes options to play the game, view instructions, check high scores, or exit.
- **Multiple Levels**: Three distinct levels with different maze layouts.
- **Gameplay Mechanics**:
  - Control Pac-Man using W (up), S (down), A (left), and D (right) keys.
  - Collect dots (1 point each) and fruits (5 points each) to increase your score.
  - Avoid ghosts that move through predefined paths.
  - Three lives per game session; lose a life upon ghost collision.
- **Graphical Interface**: ASCII-based graphics for the maze, Pac-Man, ghosts, and UI elements.
- **Scoring System**: Tracks and displays the player's score and level progress.
- **High Score Screen**: Displays a static list of top scores.
- **End Screen**: Shows the player's name, level reached, and final score upon game completion.

## Requirements
- **Operating System**: Windows (32-bit or 64-bit with 32-bit compatibility).
- **Assembler**: MASM (Microsoft Macro Assembler).
- **Irvine32 Library**: Required for console I/O and graphics functions.
- **Development Environment**: Visual Studio or a similar IDE configured for MASM.

## Setup and Compilation
1. **Install MASM**:
   - Ensure MASM is installed and configured in your development environment.
2. **Download Irvine32 Library**:
   - Obtain the Irvine32 library from the official source or Kip Irvine's website.
   - Place `Irvine32.inc` and `Irvine32.lib` in your project directory or a directory included in your assembler's path.
3. **Project Setup**:
   - Create a new MASM project in Visual Studio or your preferred IDE.
   - Add `20I-2610.asm` to the project.
   - Link the Irvine32 library in your project settings.
4. **Compile and Run**:
   - Build the project to generate the executable.
   - Run the executable in a Windows command prompt or through the IDE.

## How to Play
1. **Start the Game**:
   - Launch the executable.
   - Enter your name on the opening screen and press Enter.
2. **Main Menu**:
   - **G**: Start the game.
   - **I**: View instructions.
   - **H**: View high scores.
   - **E**: Exit the game.
3. **Gameplay**:
   - Use **W**, **S**, **A**, **D** to move Pac-Man through the maze.
   - Collect all dots (`.`) to progress to the next level.
   - Avoid ghosts (represented by colored blocks).
   - Collect fruits (`~`) for bonus points.
   - Press **X** to exit the game at any time.
4. **Game Over**:
   - The game ends when you lose all three lives or press **X**.
   - The end screen displays your name, level reached, and final score.

## File Structure
- `20I-2610.asm`: The main source code file containing all game logic and UI elements.
- `Irvine32.inc`: Irvine32 library include file (required, not included).
- `Irvine32.lib`: Irvine32 library file (required, not included).

## Code Overview
The code is structured into multiple procedures to handle different aspects of the game:
- **Main Menu and UI**:
  - `drawfrontpage`: Displays the opening screen for name input.
  - `drawmenupage`: Renders the main menu and handles user input.
  - `drawinspage`: Shows the instructions screen.
  - `drawhpage`: Displays the high score screen.
  - `drawengpage`: Renders the game over screen with final stats.
- **Gameplay**:
  - `d2`, `d4`, `d6`: Initialize and draw levels 3, 2, and 1, respectively.
  - `d3`, `d5`, `d7`: Handle the game loop for each level, including player and ghost movement.
  - `DrawPlayer`, `UpdatePlayer`: Render and update Pac-Man's position.
  - `d8`, `d11`, `d16`: Draw ghosts at their respective positions.
  - `d10`, `d13`, `d18`: Update ghost positions based on predefined paths.
  - `d15`: Check for collisions with dots or fruits and update the score.
  - `d19`, `d20`, `d21`: Detect collisions with ghosts.
  - `d22`: Check if all dots are collected to advance to the next level.
  - `d23`, `d24`: Handle Pac-Man's wrap-around movement at maze edges.
- **Graphics**:
  - `drawcharg`: Custom procedure to render ASCII characters with specific colors and symbols (e.g., walls, corners).

**Key Variables**:
- `xPos`, `yPos`: Pac-Man's current position.
- `bx1`, `by1`, `bx2`, `by2`, `bx3`, `by3`: Ghost positions.
- `score`: Player's current score.
- `liv`: Number of remaining lives.
- `level`: Current game level.
- `nameste`: Buffer for player's name.
- `lvl1`, `lvl2`, `lvl3`: ASCII maps for the three levels.

## Limitations
- **Static High Scores**: The high score table is hardcoded and not saved between sessions.
- **Ghost AI**: Ghosts follow fixed paths without intelligent pursuit of Pac-Man.
- **Single Player**: No multiplayer or additional game modes.
- **No Sound**: The commented-out `libwinmm.inc` suggests sound support was planned but not implemented.
- **Limited Levels**: Only three levels are available.
- **Error Handling**: Minimal error checking for invalid inputs or edge cases.

## Contributing
Contributions are welcome! To contribute:
1. Fork the repository.
2. Create a new branch for your feature or bug fix.
3. Make changes and test thoroughly.
4. Submit a pull request with a clear description of your changes.

Potential improvements:
- Add dynamic high score saving/loading.
- Implement smarter ghost AI.
- Add sound effects using the Windows multimedia library.
- Expand the number of levels or add difficulty settings.
- Improve error handling and input validation.

## Author
- **Muhammad Saad Raza**

---

For any issues or questions, please open an issue on the repository or contact the author.