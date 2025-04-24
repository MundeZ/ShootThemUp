# ShootThemUp Game

## Overview
This is my first educational project created while learning Unreal Engine 4 game development. ShootThemUp is a shooter game where players can use various weapons, manage ammunition, and engage in combat with visual effects and health management.

## Project Features
- Modular weapon system with base weapon class
- Ammunition management (bullets, clips, infinite ammo)
- Health system with damage handling
- Visual effects using Niagara system and decals
- Game mode configuration (players, rounds, time limits)
- **AI-controlled bot opponents with custom behavior trees**

## Technologies Used
- Unreal Engine 4.26.2
- C++
- **Unreal Engine AI and Behavior Tree system**

## Learning Context
This project was developed as part of learning game development through the Udemy course:
[Unreal Engine — Full C++ Developer Course](https://www.udemy.com/course/unrealengine/)

## Project Structure
The main components include:
- Core type definitions (STUCoreTypes.h)
- Base weapon implementation (STUBaseWeapon.h/cpp)
- Game mode setup (STUGameModeBase.cpp)
- **AI controllers and behavior tree components**
- **Navigation mesh for AI movement**

## AI Features
The game includes AI-controlled bots with the following capabilities:
- Pathfinding using Unreal's navigation system
- Enemy detection and targeting
- Combat behavior with weapon usage
- Custom behavior trees for decision making
- State-based actions (patrol, pursuit, attack)
- Perception system for detecting players

## Build and Installation Instructions for Windows

### Prerequisites
1. **Unreal Engine 4.26.2**
   - Download and install the Epic Games Launcher from [Epic Games website](https://www.epicgames.com/store/en-US/download)
   - In the Epic Games Launcher, go to the Unreal Engine tab and install version 4.26.2

2. **Visual Studio 2019**
   - Download and install Visual Studio 2019 from [Microsoft's website](https://visualstudio.microsoft.com/vs/older-downloads/)
   - During installation, select the "Game development with C++" workload
   - Make sure to include the Windows 10 SDK

### Building the Project
1. **Clone the repository**
   ```
   git clone https://github.com/yourusername/ShootThemUp.git
   cd ShootThemUp
   ```

2. **Generate Visual Studio project files**
   - Right-click on the ShootThemUp.uproject file
   - Select "Generate Visual Studio project files"

3. **Build the solution**
   - Open the generated .sln file with Visual Studio 2019
   - Set the configuration to Development Editor and Win64
   - Build the solution (F7 or Ctrl+Shift+B)

### Running the Game
1. **Open the project in Unreal Engine**
   - Double-click the ShootThemUp.uproject file
   - If prompted to rebuild modules, click "Yes"

2. **Play the game in the editor**
   - Click the Play button in the editor toolbar

### Packaging the Game
1. **Open the project in Unreal Engine**
2. **From the main menu, select File > Package Project > Windows > Windows (64-bit)**
3. **Choose a destination folder for the packaged game**
4. **After packaging completes, navigate to the destination folder and run the executable to play the game**

## Note
This is a learning project and represents my first steps in game development with Unreal Engine. The code structure and implementation reflect the educational nature of the project.
