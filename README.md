# MMTSGFramework
Modular Multiplayer Tactical Strategy Game Framework

The Modular Multiplayer Tactical Strategy Game Framework is a reusable Unreal Engine 5 (C++) framework designed to provide the core systems required to build grid-based tactical strategy games. It is not intended to be a finished game, but rather a foundation that other developers can extend into their own projects.

The framework follows an object-oriented, manager-based architecture that emphasizes modularity, separation of responsibilities, and low coupling. Major gameplay systems communicate through well defined interfaces, events, and command structures instead of directly depending on one another. The long-term goal is to allow new mechanics to be added with minimal modification to existing code.

Although multiplayer is not fully implemented in the MVP, the architecture has been designed with multiplayer in mind. Commands are represented as data rather than direct object references wherever practical, allowing future replication without requiring significant refactoring.

Primary Goals

The framework is designed around several objectives:
- Create reusable tactical strategy systems instead of game-specific logic.
- Allow developers to extend existing functionality through inheritance and composition.
- Minimize dependencies between gameplay systems.
- Support both Blueprint and C++ development.
- Keep gameplay logic centralized and authoritative.
- Provide an architecture suitable for future multiplayer support.

Current Architecture

The framework is organized into specialized managers that each own a specific responsibility.
Player
   │
Player Controller
┌─┴──────────────────── Battle HUD / Widgets
Battle Manager
 ┌─┴─────────────┐
 │               │
Grid Manager   Unit Manager
 │               │
Battle Tiles   Base Units

Player Controller

Responsible for:

Receiving player input
Selecting units and tiles
Sending gameplay commands to the Battle Manager

The Player Controller intentionally avoids implementing game rules. It serves primarily as the interface between the player and the gameplay systems.

Battle Manager

The Battle Manager is the central authority of the framework.

Responsibilities include:

Turn validation
Action validation
Processing tactical commands
Coordinating communication between managers
Maintaining battle state

Most gameplay decisions flow through the Battle Manager to prevent individual systems from becoming tightly coupled.

Grid Manager

Responsible for the battlefield.

Current responsibilities include:

Grid generation
Square and hex grid support
Tile lookup
Tile highlighting
Terrain information
Tile occupancy
Future pathfinding

Battle Tiles are independent actors that contain terrain and occupancy information while remaining reusable across different maps.

Unit Manager

Acts as the owner of all units.

Responsibilities include:

Unit spawning
Tracking unit locations
Unit lookup
Issuing movement requests
Receiving movement completion events

Movement itself is performed by the unit, while the Unit Manager coordinates unit state.

Base Unit

Represents the common functionality shared by every unit.

Current functionality includes:

Health
Damage
Movement
Turn state
Terrain movement costs
Death events
Movement completion events

Developers are expected to inherit from BaseUnit to implement custom unit types.

User Interface

The UI is intentionally modular.

Current widgets include:

Battle HUD
Action Selection Bar
Unit interaction controls

UI widgets communicate upward through delegates and events rather than directly manipulating gameplay objects.


Command Flow

Gameplay follows a command-driven workflow.

Player Input
      │
Player Controller
      │
 Tactical Command
      │
Battle Manager ( Validation)
      │
Grid / Unit Managers
      │
Base Unit
      │
Command Complete Event

This architecture makes future networking significantly easier because player intent can eventually be replicated as commands rather than replicated object references.
