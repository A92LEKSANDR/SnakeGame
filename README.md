```markdown
# Snake Game

This is a simple Snake game implemented in C++ using the SFML library.

### Prerequisites

- C++17 compiler
- CMake
- SFML 2.6.1

## Installation

### Building the Game on Linux

1. **Install SFML using a package manager**:

   For Debian-based systems (e.g., Ubuntu):
   sudo apt update
   sudo apt install libsfml-dev
  
   For Red Hat-based systems (e.g., Fedora):
   sudo dnf install SFML-devel

   For Arch Linux:
   sudo pacman -S sfml
   
2. **Clone the repository**:
   git clone https://github.com/A92LEKSANDR/SnakeGame.git
   cd SnakeGame

3. **Create a build directory and build the project**:
   mkdir build
   cd build
   cmake ..
   make

4. **Run the game**:
   ./SnakeGame

 ### Building the Game on Windows

1. **Install SFML**:
   Download the SFML library from the SFML website and follow the instructions for your compiler.

2. **Clone the repository**:
   git clone https://github.com/A92LEKSANDR/SnakeGame.git
   cd SnakeGame

3. **Create a build directory and build the project**:
   mkdir build
   cd build
   cmake ..
   cmake --build .

4. **Run the game**:
   ./Debug/SnakeGame.exe
