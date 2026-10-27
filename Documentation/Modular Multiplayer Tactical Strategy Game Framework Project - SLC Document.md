1 

# **Modular Multiplayer Tactical Strategy Game Framework Project** 

Louis J D’Agusto 

Aug 22, 2026 

2 

# **Modular Multiplayer Tactical Strategy Game Framework Project** 

# **Iteration 1 (Planning)** **_Introduction_** 

The planning phase of the Modular Multiplayer Tactical Strategy Game Framework project will examine the Agile Software Development Life Cycle (SDLC) methodology (Beck et al., 2001) and project requirements necessary to create a timeline. Proper planning will reduce the possibility of development challenges and maintain project scope to avoid project delays. Each system is dependent on others so careful planning for the project’s development order is essential to ensure efficient progression throughout the project lifecycle. 

A Game Framework was chosen as a capstone project due to the many different systems that must be made to work together to ensure functionality. This project will cover major software development concepts such as object-oriented programming, data structures and algorithms, modular software architecture, version control, state machines, replication, and design patterns like observer, state, and factory (Gamma et al., 1994). This will act as a proper examination of the developer’s skillset while both challenging the developer and keeping realistic expectations. 

# **Project Development Plan** 

The development of this project will be created as a framework for building reusable systems and architecture. Simple assets will be used to maintain focus on game systems as the project is not a fully developed game. Plans are to focus on keeping functionality and features simple to develop a minimum viable product known as an MVP. This MVP will be created with the intention that each system will support multiplayer functionality. 

Each gameplay system will undergo development as an Agile milestone, following the full iterative development methodology. These milestones will act as mini projects by going through design, development, testing, and deployment processes. This allows each system to build upon the previous systems while maintaining separate architecture. 

3 

This project is planned for a 13-week development timeline with approximately 15 hours dedicated to development each week. Although a total of 15 weeks is available for completion of the project, the additional two weeks are reserved as extra time to address unexpected development challenges. Due to the complexity networking can add to a project, the multiplayer networking functionality will act as the final Milestone for the project and may be removed if necessary for the timeline. This will allow for development to focus on the core systems for the project 

# **_Hardware Requirements_** 

A personal computer (PC) and laptop will be used to house the software needed for development. The laptop will allow for work on code during times of travel, while the home PC will allow the use of multiple screens and stronger hardware specifications for more demanding software. 

# **_Development Software_** 

Visual Studio Code (Microsoft, 2021) with C++ and Unreal Engine development packages are needed for code development. Unreal Engine (Epic Games, n.d.-g) will act as middleware between gameplay systems and hardware allowing development to focus on the implementation of game systems, instead of code for rendering graphics or taking input from mouse and keyboard. GitHub and GitHub Desktop (Microsoft, 2026) are used for version control, synchronization of project files between devices, and repository management. 

# **_Documentation and planning tools_** 

Microsoft Word (Microsoft, n.d.) and GitHub (Microsoft, 2026) are both used for documentation, GitHub for commit tracking and Word for reports and papers. LibreOffice Draw (LibreOffice, n.d.) is free open-source software used to create flow charts that will assist in designing the interconnection between gameplay systems. Monday.com (Monday.com Ltd, n.d.) website’s free project management features allow for the creation of GANTT charts and will allow access to the chart from either device during development. 

# **_Additional Requirements_** 

4 

As the project is a framework, stand-in assets for UI elements and game entities will be used. The project will utilize free assets from the Unreal Engine Fab Marketplace (Epic Games, n.d.-c) along with any assets for which licenses are already owned. This will allow us to add visualization to the framework without incurring additional costs for development. Research for the project will come from public sources such as the Unreal Engine Documentation page, game development forums, and online tutorials such as the ones seen on YouTube. 

# **_Project Staffing_** 

This project is being developed by a single developer. The developer will take on the role of designer, programmer, project manager, tester, and technical writer. With the multiple roles they will need to fulfill, there will be a utilization of hardware, software, and research resources to develop the project along with maintaining documentation and timeline adherence. 

# **_Project Timeline_** 

The project will follow a structured timeline ensuring proper planning and project requirements are met. Development will start with a design and planning process followed by iterative development for each game system using Agile SDLC methodology. Testing will be conducted as each system is completed with a final testing phase to ensure all systems work together. Only after testing is completed will the project be deployed to the public. After deployment the project will enter a bug fix and maintenance phase. No additional features are planned for this project. 

1. Week 1: Creation of Project Outline 

2. Week 2: Analysis of project requirements and creation of Project Plan document (This document) 

3. Week 3-10: Agile project development (design, development, and testing of each game system) 

   1. Week 3: Unreal Engine and C++ Environment set-up and initial testing 

   2. Week 4: Creation of player UI systems and assets 

5 

   3. Week 5: Creation of Battle Map grid and generation 

   4. Week 6: Creation of playable unit structures 

   5. Week 7: Creation of pathfinding and range finding systems 

   6. Week 8: Creation of combat systems and unit actions 

   7. Week 9: Creation of game round and player turns 

   8. Week 10: Implementation of multiplayer network integration 

4. Week 11: External Testing in small groups and MVP completion 

5. Week 12: Deployment of project into a public platform (Steam/Itch.io) 

6. Week 13: Project enters bug fix and maintenance phase 

# **_Development Milestone Completion Criteria_** 

Each milestone will have measurable criteria to confirm its completion. When all criteria are 

met, the milestone is considered complete and further progress in the project can be made. Each 

milestone will also follow clean code (Martin, 2008) best practices along with noted milestone 

criteria below. 

1. Unreal Engine and C++ Environment set-up and initial testing 

   1. Unreal Engine starts without crashes or errors 

   2. Developer is able to create new Unreal Engine project and connect the FAB library to the project 

   3. Developer is able to create C++ classes in Unreal Engine 

   4. Visual Studio Code can see, edit, and save changes to Unreal Engine C++ classes 

   5. Visual Studio Code can compile and run C++ code 

   6. Visual Studio Code can recognize Unreal Engine classes, methods, and variables via the IntelliSense system. 

6 

   7. GitHub Desktop can detect changes made to C++ files 

   8. GitHub Desktop is connected to and is able to make commits and push commits to GitHub. 

2. Creation of player UI systems and assets 

   1. Creation or discovery of the following assets: 

      1. Menu button and highlighted menu button 

      2. Unit action button and highlighted unit action button 

      3. Menu background and outline 

      4. Text font 

   2. Menu system is opened via a predetermined button. 

      1. Menu must support keyboard, mouse, and controller input. 

      2. Able to navigate menu as expected. (selected menu options perform the expected action) 

      3. Menu can open, close, save option changes, update display to match menu items. 

   3. If time allows, an options menu with the ability to remap controls 

   4. Gameplay overlay that displays information during battle gameplay 

3. Creation of Battle Map grid and generation 

   1. Creation of separate battle map and tile classes 

   2. Battle map can create a grid of variable sizes using the tile class objects 

   3. Battle map generation randomizes tile placement 

   4. Battle map information is accessible through class interfaces 

   5. If time allows, able to edit which tiles are in the grid to create 

      - predetermined maps. This includes the saving and loading of maps 

4. Creation of playable unit structures 

7 

   1. Units are able to deal and receive damage 2. Units can move across the battle map 

   3. Units have a defined movement cost matrix. This is later used in the pathfinding phase. 

   4. Units can be defeated 

   5. If time allows, create items that units can equip to modify their attributes 

5. Creation of pathfinding and range finding systems 

   1. Pathfinding logic must be able to accurately navigate to two separate tiles in the battle map 

   2. Pathfinding logic must take tile type and unit movement matrix into account 

   3. Range finding must be able to determine tile distance between two tiles 

   4. Range finding must be able to consider blocking units and terrain types 

6. Creation of combat systems and unit actions 1. Units must be able to use actions from player UI panel in order to move and attack. 

   2. Interactions from UI, Units, and Battle map must all update together to player actions 

   3. Player must be able to select units in order to give commands 

   4. Player must be able to select tiles for tile information 

   5. UI must update to match selected unit or tile 

   6. UI must update to match command player is giving to a unit. Example: highlight available tiles when commanding unit to move. 

   7. If time allows, implement a generic command system to allow expansion of capabilities for the combat system. 

7. Creation of game round and player turns 

8 

1. Allow units to only activate once per round 2. Have round end when all units have activated 3. Have unit activations reset at the end of a round 4. Have players take turns with activations 5. Allow command for a unit to skip their activation. This counts as activating the unit, but the unit does not take any action. 

6. Ensure players cannot control units owned by the other player. 7. If time allows, implement simple computer AI (check range, move, attack. No combat logic) 

8. Optional Implementation of multiplayer network integration 1. Players can create a lobby room to host a game 2. Other player can join the hosted room 3. Game host can start the game and play a battle 4. All game actions are synced between players 5. Change player UI when waiting for opponent to take their turn 6. If time allows, implementation that allows more than two players per game 

**Figure 1** 

9 

# **_GANTT project table_** 

![GANTT project table](<images/GANNT project Table.png>)

<!-- Start of picture text -->
Gantt x<br> Typeto fiter @ People 7 Fiter ~ SZ oaseine GB Autort Monts v - + GB @ =<br>x < 222026 32026<br>Project Outine Mey-7 GB prot ontine<br>AgiProjectproject Pan Documentdevelopment MayMay 25 18-24Ju 19 Oy Oy ProjectPan Document Ale project development<br>Creation of pathtincing an. Jun 22-28 CM creation of pants anc ange ning syst<br>(Creation of game round an. wul6-12 Q ] Craton of game round an player tun<br>External Testing in smal gr Jul20-26 - External Testing in small groups and MVP completion<br>Deployment of project int. Ju27 -Aug2 Oy Deploymentof project nto a public platform<br>© Done © NotStarted @ Workingon t<br><!-- End of picture text -->

# **_Project Completion Milestones_** 

After core development has been completed, the project will undergo testing stages by 

testing major gameplay interactions. These tests are to ensure the systems are working together as expected and to find any missed bugs before external testing. 

After internal testing a fully compiled version of the project will go out to select trusted individuals to test framework features. They will provide feedback and report any missed bugs. Any bugs will be worked on and removed while feedback will be considered if time allows for implementation. 

The project will then undergo deployment. Pages for the project with details and screenshots will be created along with a fully compiled version of the project. This will be a public release of the project. Public users can try out the framework and provide additional feedback and bug reports. 

After deploying the project, work will be done to fix any reported bugs and make minor changes that improve the user experience. No major changes will be made to the project at this time. 

# **_Risk / Contingency Planning_** 

10 

As this project has many individual parts that all must work properly in order for the framework to be successful, risk assessment and contingency planning is required. Software projects can face unforeseen delays and large amounts of time can end up dedicated to fixing a single bug. The project developer also has obligations outside of the project that may cause development delays. 

For this project one of the major risks is the solo development workload. The developer currently has a full time job that takes up 40 hours a week. They are also a student who has obligations and assignments outside of this project. This leaves very limited opportunities to work on the project. 

To mitigate this risk, the developer is dedicating 15 hours a week for the project. Additionally, the planned 13-week timeline has a two-week contingency buffer available. The scope management and focus on an MVP also mitigates possible feature creep and allows for the addition or removal of optional systems. 

The project is designed around flexibility to mitigate any difficulties that may arise during this project. This flexibility also allows for extra features to be implemented if the progress of the project allows. This focus will give the developer the greatest opportunity to create the best possible MVP-focused framework and still make the release window. 

# **_Planning Conclusion_** 

The planning for this project examines all requirements for its completion and considers the risks involved with having a single developer. Without this process the project could suffer from systems being developed in the wrong order, causing delays in system completion or temporary workarounds becoming permanent problems. This full Agile development plan will ensure that each milestone is met, with room to shrink or grow project scope as needed. Milestones set in this project plan establish realistic expectations in the project’s life cycle and the developer is confident that completion criteria are met. 

11 

# **Iteration 2 (Analysis)** **_Introduction_** 

The analysis phase for the Modular Multiplayer Tactical Strategy Game Framework project is intended to identify potential users, system requirements to meet users’ needs, and refine overall scope. During this phase research was conducted on existing tactical strategy games, existing Unreal Engine projects found on Epic Games FAB marketplace (Epic Games, n.d.-c), and the Unreal Engine Documentation  (Epic Games, n.d.-g). The information gathered was used to refine the project’s milestones and establish the functional and non-functional requirements of the project. 

# **_Analysis Activities_** 

Research for the project started by researching potential users and stakeholders of the 

project. It was determined that the project has two main groups of stakeholders. Project Developers, including the solo developer making this framework, would want to use this framework to save time and money during the development of their game, and Player End Users who would be able to play games made using this framework. 

After establishing stakeholders, comparisons of several popular tactical games such as Final Fantasy Tactics (Square Enix, 2025) and BattleTech (Paradox Interactive, 2018) were used to identify stakeholders’ expectations by finding common systems and standards in tactical games.  As this framework will focus on the battle sequences of these games, aspects outside of combat for these games were not considered. From this research it was determined that a Tile-based grid system for the map, Tile terrain system, Individual Unit system that can occupy map Tiles, Unit Command and Combat System, Player Turn System, User Interface system, and battle end check system are all common in these successful games. The research also revealed a few noteworthy aspects of these systems that expanded the scope of some of the planned systems. 

Finally, the planned milestones were examined based on online resources to determine whether each system could be completed within the available development timeline. It was determined that each system should be modular and made with multiplayer functionality from the 

12 

beginning and converting from a single player framework to multiplayer would push the project outside the 15-week timeline. Several planned aspects to systems have been removed and reserved as stretch goals including progression and Equipment Systems. 

# **_IT Specialist Roles_** 

Due to the project being developed by a single individual, the IT roles of systems analyst, software architect, software developer, project manager and tester are all performed by the project’s developer. The analysis activities involved in identifying stakeholder needs, researching existing tactical strategy games, documenting project requirements, and evaluating the requirements associated to project’s completion were all performed by the solo developer. 

# **_Stakeholders and End Users_** 

This project has two stakeholder groups: project developers and end users. Each of the two groups have different expectations that influenced the design and scope of the framework. 

Project developers are the primary Stakeholders of the framework. This group is made up of game developers who would benefit from the framework such as small development teams, game developer hobbyists, computer science students, the framework developer themselves, and any other group or individual interested in creating a tactical strategy game. These stakeholders are interested in reducing the development time and costs of their games by utilizing a modifiable framework that provides systems expected of a tactical strategy game. 

These project developers require systems that are maintainable and scalable. A tactical strategy game has many interconnected systems, and this framework will reflect that. It must be built with modularity to allow designers to add mechanics without forcing major redesign as redesigns would not save these Stakeholders any time or money. This saving of time and money is a key reason multiplayer functionality is being built into the system from the beginning. 

A secondary stakeholder group are the end users. These users will not interact with the framework directly like the developers but will interact with the projects these developers make 

13 

with this framework. Therefore, decisions made in the framework’s development will affect the games they will end up purchasing and playing. These users will expect responsive controls, clear user interfaces, reliable combat systems, and consistent game rules. It is this reason that the framework must provide developers with systems capable of supporting these expectations. 

By identifying these two groups, and their expectations of a Tactical Game Framework, the developer was able to refine the goals for the framework and update milestones for the project to match expectations of both groups of stakeholders. 

# **_Functional Requirements_** 

The analysis of the framework project led to several functional requirements necessary for the framework to support the development of tactical strategy games. Players must be able to interact with game systems which will require a user interface system to display game information and take in user input. Tactical battles must have a location to take place and thus a battle map system is required to act as the battlefield for tactical combat and will require methods to create or generate battlefields for the game. Players will need the ability to control their teams’ units via a unit management system that will allow players to issue commands and can process combat actions between units. For units to have the ability to move and act on the battle map, pathfinding and range systems are required otherwise each unit would have no restriction on commands and there would not be a challenge for players to strategize around. 

Further restrictions such as actions per unit activation or phases known as game rounds, a system is needed to track actions economy and reset action restrictions for units to allow combat to progress. Each combat requires end conditions such as defeating all enemy units, and thus the framework requires a resolution system to determine how combat ends and how the actions of combat affect parts of the game outside the battle map. 

An optional feature of multiplayer, networking, and synchronization systems will allow players to play together locally or over the internet. Even though multiplayer functionality is 

14 

optional, it is part of the design of this framework as not designing each system of the framework with multiplayer functionality will cause multiplayer to not be an option later in development. 

# **_Non-Functional Requirements_** 

As the framework will act as a foundation for other game projects, it will be important that the framework not require stakeholders to directly modify the framework to make or play a game. The framework must be stable. Bugs or other failures in the framework would cause failures in any project made with the framework. 

Developers will also need freedom to create their game as they wish, which would require the framework to be developed with modularity. Developers should be able to modify or replace assets and systems as needed to build their game. 

Near the end of the framework’s development life cycle, some changes may need to be made to fit the needs of future developers and thus the framework must have maintainable architecture to allow changes and updates without requiring major rewrites of systems. 

Developers will need the ability to make small or large projects with this framework. This would require the framework to scale with developer needs and support large maps, multiple teams with many units, additional game mechanics through modularity, and any game AI system for nonplayer opponents. 

# **_Similar Existing Solutions_** 

During the analysis research for the Modular Multiplayer tactical strategy game framework, several existing tactical game frameworks were found in the Epic Games Unreal Engine market known as FAB. Some of the solutions discovered were examined further for additional research. 

A software solution provided by Epic Games simply known as “Turn Based Strategy” (Epic Games, 2025) is a free project on the FAB website. This project features randomly generated maps, player turns and operations, unit and team controls. These features are similar to the ones required by this framework project. Examining the methods used in this free project can act as a jumping 

15 

point to learn from in order to develop this framework without having to build the systems from scratch. This however, will not be an immediate conversion as the project was done in Unreal Engine 4. Since the framework is being developed in Unreal Engine 5, the changes in versions may prevent some of the systems from working. The “Turn Based Strategy” project was also developed using the Unreal Engine Blueprints, not C++ and therefore will act more as reference materials to build ideas from. 

Another solution by the name “Turn-Based Strategy RPG Template” (Phoenix Market, 2025) was also discovered on the Fab marketplace. This project is made using Unreal Engine 5 using Unreal Engine blueprints. This solution costs $99 in order to obtain the rights putting it outside the budget for this project. However, the trailer videos show the capabilities of the solution. The takeaway from this solution is the UI system showing unit turn orders, sound and unit actions, range and pathfinding calculations, and the way the UI provides information for the player. These are wonderful takeaways from this solution even if we are unable to investigate the methods the solution provides these features due to budget constraints. The trailer videos show how important these features are as the developers of the solution made the main part of their showcase videos. This shows that multiple developers are willing to purchase a tactical strategy framework rather than develop those systems internally. 

The analysis of existing solutions confirmed several feature requirements noted during the planning phase of the project while also shining light on several other aspects missed during planning. These findings support the functional and non-functional requirements of the framework and will act as references during the development phase of the project. 

# **_Potential Commercial Interest_** 

The analysis phase for the Modular Multiplayer Tactics Game Framework revealed potential interest from independent game studios, educational institutions, solo developers, and other development teams looking to save time and money on development of strategy games. As discovered when researching other solutions, there is a demand for strategy game frameworks and 

16 

many of these frameworks have features in common. A possible missing outlier is the multiplayer features that this framework will possibly provide. Mentions of this demand were discovered on public game development forum sites such as Reddit. (DragonWarrior008, 2024) 

Rather than selling this framework to a single company, customers would be independent developers who would purchase a license to use the framework in their games without the right to repackage and sell the framework themselves. This would make a modular reusable framework particularly valuable for educational institutions teaching game development as each student could hop into learning how each system works together without having to learn how to program every line of code. 

# **_Project Analysis Reflection_** 

During the analysis phase, several discoveries were made. By researching tactical games and similar projects, many assumptions made during the planning phase were confirmed. However, it was also apparent that some changes would be needed to have the project meet the feature standards shown in similar projects. By focusing on stakeholders’ needs, it was seen how important creating a maintainable architecture for this framework would be. Maintainable architecture would support future changes and reduce the impact of any project defects. Any defects in the project would affect not just the development teams using the framework, but the gaming experience of the players. Taking time to research other solutions and taking time to understand stakeholders’ needs revealed to the developer how best to create this project. The findings during analysis are now incorporated into the development of future iterations of the project. 

# **Iteration 3 (Design)** 

During the design phase time was taken to refine the software architecture and determine how it would best support the minimum viable product (MVP) for the Modular Multiplayer Tactical Strategy Game Framework. This was an important step as the framework is intended for reuse by other developers. With the framework being designed to be modular and maintainable, multiple systems must work together while minimizing coupling between them. Incorporating design 

17 

patterns such as the Observer pattern (Gamma et al., 1994), along with object-oriented class associations, was selected to achieve this goal. This approach allows each subsystem to 

communicate while minimizing direct dependencies, resulting in a framework that is easier to maintain and extend for future projects. 

# **_Technical Architecture_** 

# **System Requirements.** 

The framework has several development requirements that must be met before it can be 

integrated into a project. Developers will need a computer with hardware capable of meeting the recommended requirements for Unreal Engine 5. (Epic Games, n.d.-d). A mouse and keyboard are also required to interact with Unreal Engine while developing with the framework. Unreal Engine 5 will need to be properly installed prior to integrating the framework into a project. Projects utilizing the framework’s multiplayer functionality will require integration with appropriate networking or hosting infrastructure. However, these integrations are not required for single-player projects. 

# **Framework Architecture.** 

The framework needs a modular architecture built from independent system managers. Each manager has a single responsibility and communicates with each other subsystem during gameplay. The major systems are Player Controller which handles all player input; and the UI (User Interface) which handles information displayed as an overlay for the player; the Battle Manager to control game flow; Grid Manager to generate and manage the battle map; the Unit Manager which generates, tracks, and commands units. Unit Manager will use a BaseUnit class that future developers can create child classes that inherit from the BaseUnit class, which will allow all systems to continue to function without reworking the Unit Manager. A similar style is used with the Grid Manager, where the BattleTile class is used for each tile in the battle map grid. This structure allows developers to add functionality without affecting preexisting systems, simplifies the testing of each subsystem, and makes future multiplayer functionality easier. 

**Use Cases.** 

18 

As the framework is intended to act as a foundation for the development of tactical strategy 

games, the primary use cases focus on how developers interact with and extend the framework 

during game development. These use cases describe the intended methods of using the framework 

and reflect the design goals for the minimum viable product (MVP) of the project. 

# **_Use Case 1: Create a New Tactical Strategy Game._** 

**Actor:** Game Developer 

**Goal:** Create a new tactical strategy game using the framework as a foundation. 

# **Preconditions:** 

- Unreal Engine 5 is installed on supported hardware. 

- The framework has been integrated into the project. 

# **Main Flow:** 

1. Create a new Unreal Engine project. 

2. Integrate the framework into the project. 

3. Configure the Battle Manager. 

4. Configure the Grid Manager. 

5. Create custom units by inheriting from the BaseUnit class. 

6. Configure game-specific rules. 

7. Compile and test the project. 

**Outcome:** A functional tactical strategy game has been created using the framework. 

# **_Use Case 2: Extend framework capabilities._** 

**Actor:** Framework Developer and Game Developer 

**Goal:** Extend framework functionality while maintaining compatibility with existing 

architecture. 

19 

# **Preconditions:** 

- Unreal Engine 5 is installed on supported hardware. 

- The framework project files are installed onto supported hardware. 

- C++ development environment is configured. 

- Version Control system (e.g., Git). 

# **Main Flow:** 

1. Plan, analysis, and design new functionality for the framework. 

2. Create new branch in repository for new functionality. 

3. Develop and test new functionality. 

4. Compile and test the full project. 

5. Merge the development branch into the main branch following successful testing. 

**Outcome:** The framework is extended while maintaining compatibility with the existing architecture. 

# **_Supporting End-User Needs_** 

The end users of this framework need to justify the cost and time for teams to integrate the framework into their project and workflow. This framework is designed as a foundational piece of any game project and is not meant to be integrated into an existing project. This means using the framework correctly; a developer must start using this framework with a new project. Supporting the end user’s needs therefore assumes the creation of a new project. 

Developers can save a large amount of development time by using this framework. 

Researching, writing, designing, developing, and testing systems can take a very long time. By using the framework, developers can focus on developing the unique aspects of their game and build more content as the framework covers all the underlying systems. 

20 

When it comes to cost, the value of the framework is in the development time saved by development teams not having to create the base functionality that the framework provides. Since the framework can save teams months of development time, that time gained back is not just for the initial, but future projects can continue to provide value far above the initial cost of the framework. This is feasible for developers as it is built on the Unreal Engine 5 platform and uses standard C++ development practices. This allows developers to integrate the framework into projects alongside their available tools and establish workflows. 

The modular design of the framework also allows developers to expand on the initial functionality and create unique games that meet their project's requirements. Developers may also expand on the framework and create their own internal versions with additional features that are best suited for their development process. 

# **_Software Engineering Best Practices_** 

During the design phase of the project, several software engineering best practices were used to improve the maintainability and extensibility of the framework. The framework follows a modular architecture where each manager is responsible for a single subsystem, reducing the coupling between the systems. The framework also uses Object-oriented principles such as inheritance and class associations which allows developers to extend functionality of the framework without modifying the core systems. The project also utilizes version control using GitHub, which supports the incremental development process using feature branches. This allows for systems to develop on a separate branch and be tested before integrating directly into the main framework. This also allows for an easy rollback if a particular system does not function properly. Rolling back a system is considerably more efficient than manually removing malfunctioning systems from the project. 

# **_Ethical Considerations_** 

As this project is an MVP framework used as a foundation for game development, there are relatively few ethical considerations as the project does not directly handle any data. There is 

21 

however a small consideration for the use of third-party assets that will act as placeholders in the project. The development team has licenses for several assets that would make for excellent placeholders. The use of these assets would make for a greater appeal of the framework to potential users. Developers however, may unknowingly leave placeholder assets in their final projects. Because the licenses for these assets do not permit redistribution, only open source and royalty free assets are used in the development of the framework. 

# **_UI Wireframe Layouts_** 

As the project’s scope is that of an MVP, it does not cover anything outside of a battle. Therefore, only two user interfaces (UI) are required for the MVP. The first is the Team Selection Screen, where each player will select what units they are taking to the battle to form their team. 

**Figure 2** 

_Team Selection Screen UI_ 



<!-- Start of picture text -->
Highlighted Current Selected Unit<br>Start Battle<br>Unit qUnit Team SelectionUnit Unit [sesa<br>a<br>Selected Unit scrollbar for<br>Information units<br>Unit Unit Unit Unit<br>Unit Unit Unit Unit<br>Icon Icon Icon Icon<br>Selected unl} Selected unl} Selected uniQ¢’ Selected unt<br>For Team For Team For Team For Team<br>icon con icon con<br><!-- End of picture text -->

Note: This is a wireframe of the proposed design for the Team Selection Screen 

The Team Selection Screen allows players to assemble their team rosters before entering the Battle Screen. This screen allows players to review each unit’s statistics and abilities before 

22 

selecting what units they are taking into the battle. Unit information will be updated on the left side of the screen based on what unit the player has selected. The selected unit Icon will be highlighted for quick recognition by players. Players may add the selected unit to the team roster displayed at the bottom of the screen. Players can then select the ‘start battle’ button at the top right of the screen. The button’s location is positioned away from other buttons and icons to reduce the risk of accidental selection by the player while building their team roster. 

**Figure 3** _Battle Screen UI_ 



<!-- Start of picture text -->
Unit Information a 7 {ferrain Information<br>—<br>» BattleTile| mena<br>; | Vv ann Movement Cost<br>Unit stats and wn<br>> j<br>related Terrain effects<br>information vs / and benefits<br>Nery<br>on<br> eaee ."<br><!-- End of picture text -->

Note: The Battle Screen serves as the primary interface through which players interact with the 

framework's core gameplay systems. Background image taken directly from project. 

The Battle Screen will serve as the primary interface for the players during the MVP of the project. Players will take turns giving commands to units by selecting a unit on screen and then selecting an action to take. Some actions require the player to select a target before executing the action. The left and right information panels update dynamically based on the player’s current 

23 

selection, ensuring that only the relevant unit and terrain information is displayed. When a unit is selected, the Terrain Information panel also displays the information for the terrain tile currently occupied by that unit. 

**Figure 4** **_System Architecture Diagram_** 



<!-- Start of picture text -->
Pieyes MGass/Object<br>Interfaces<br>1 with a a<br>Gass/Object ———> Class/Object<br>Player Ul ayAssocioies wh Player Controller Connection<br>rN a a<br>' ‘lass/Objact ~~ ~ > Ciass/Object<br>1 Sends Player Actions to<br>1\ | Observer Pattern Connection<br>\ a a<br>i Battle Manager Gass/Object —--—B> Class/Object<br>\<br>} | | Inheritance Connection<br>1 Coordinates with Coordinates with<br>{t<br>\<br>\<br>\Grid Manager Unit Manager<br>\<br>'! ManagesI ManagesI<br>1t+<br>\| custom tie <nInherits from Bale Tie Base Unit © "BeInherits from Custom Unit<br>\ ' i<br>\ i<br>i\<br>'<br>\.—~-~-|—— f ;<br>Broadcasts Update Event -— + —---~---—<br>Creates<br>Developer<br><!-- End of picture text -->

Note: The Framework System Architecture Diagram illustrates the relationships between the framework's primary components, along with player and developer interactions. 

The System Architecture Diagram illustrates how player input is processed through the Player Controller and coordinated by the Battle Manager, which delegates its responsibilities to the Grid Manager and Unit Manager. These managers control the battle map and units while each Unit and Tile broadcasts update events to the Player UI. Developers can extend the framework by creating custom classes that inherit from the BaseUnit and BattleTile classes to create custom units and terrain without modifying the framework's core systems. 

24 

# **Figure 5** **_Class/Object Relationship Diagram_** 



<!-- Start of picture text -->
Key<br>M<br>Class/Object<br>a a<br>Class/Object ———— Class/Object<br>Player UI ——— Player Controller Association<br>J a a<br>Class/Object — — > Class/Object<br>Battle Manager<br>Composition<br>a a<br>Class/Object ---------> Class/Object<br>Inheritance<br>Grid Manager <—— — Unit Manager<br>1i<br>|\<br>Custom Tile <t---- Battle Tile Base Unit "P| Custom Unit<br><!-- End of picture text -->

Note: Uses hollow diamonds to represent composition because the diagramming software does not support a filled diamond symbol. 

Unlike the System Architecture Diagram, this figure focuses on the structural relationships between the framework's classes rather than the communication flow between systems. This relationship diagram illustrates how the framework's subsystems relate to one another while maintaining modularity through limited interdependencies. The association from Unit Manager to Grid Manager allows the Unit Manager to utilize functions provided by the Grid Manager for range and pathfinding calculations. 

# **Figure 6** 

_Gameplay Process Flow_ 

25 



<!-- Start of picture text -->
No<br>No<br>Tie No. Yes End Turn Button<br>Unit<br>‘Action Button<br>Yes<br>targettile thetheunit<br>‘occupies<br>No<br>No<br>= ==<br>Player Cancels Selection<br>7<br><!-- End of picture text -->

**Note:** The Gameplay Interaction Flowchart illustrates the primary decision-making process during a 

player's turn. The flow begins when the framework waits for player input 

The Gameplay Process Flow illustrates the primary gameplay loop. The Framework 

facilitates each player’s turn by continuously waiting for input, updates the user interface based on 

unit and terrain selections, validates player actions, executes valid actions, and advances play to the next participant when the turn ends. 

**Table 1** 

_Data Dictionary_ 

|**Class**|**Type**|**Description**|**Responsibilities**|
|---|---|---|---|
|PlayerController|Controller|Handles player input.|Selection, command processing.|
|PlayerUI|UI|Displays game information.|Unit info, terrain info, action menus.|
|BattleManager|Manager|Coordinates gameplay<br>systems.|Turn management, subsystem<br>coordination.|
|GridManager|Manager|Manages the battle grid.|Grid generation, pathfinding, tile<br>management.|
|BattleTile|Base Class|Parent class for all terrain|Terrain data, occupancy.|



26 

|**Class**|**Type**|**Description**|**Responsibilities**|
|---|---|---|---|
|||tiles.||
|UnitManager|Manager|Manages all units.|Spawning, movement, tracking.|
|BaseUnit|Base Class|Parent class for all units.|Combat, movement, statistics.|



Note: This table summarizes the primary framework classes included in the minimum viable product (MVP). 

# **_Design Phase Reflection_** 

Designing the project became a longer task than originally anticipated. In order to achieve the modularity intended for the framework, many of the functions had to be designed to support expansion after the framework’s initial development. As it is impossible to know what any developer may want out of the framework, each part had to be created with expandability and readability in mind. It became more important to design with future developers in mind than to simply have a working product, as parts of the project created only with the goal of providing a working feature could cause bottlenecks and roadblocks for future expansion. 

This focus on modularity and expandability added more development time to the project than a simple working framework would have required. The additional time cost for added modularity is acceptable however, as it will make the final product more flexible for developers while also making future development of the framework easier. This is an example of putting additional time into a project now in order to save much more time later in development. 

# **Iteration 4 (Develop)** 

During project planning, the development phase was scheduled to span eight weeks. Each week was to focus on a particular milestone so that testing could begin following the completion of each milestone. These milestones were updated and refined during the analysis and design phases prior to the start of implementation. As the goal of the project is to produce a minimum viable product (MVP), the development phase focused on implementing the framework's core systems rather than a feature-complete product. During development, it was determined that the scope of 

27 

several features had to be reduced to meet development timelines. The Agile development cycle helped ensure that this discovery did not hold back development as each part of the framework was made and tested to stand on its own, thus preventing this scope change from creating further delays. 

To help maintain the planned development timeline, a journal (D'Agusto, 2026a) and project checklist (D'Agusto, 2026b) were kept to document the progress of framework development. These tracked completed work, architectural decisions, technical challenges, and milestone progress. These documents helped ensure that implementation remained aligned with the project schedule and provided a record of the development process. 

# **_Development Environment_** 

The first week of development was dedicated to setting up and testing the development environment. This was a foundational step in development as any problems with the development environment would cause constant delays during the development phase. 

The OMEN 16 laptop was obtained to use for development. As the laptop was originally acquired for personal use, it did not add any expenses to the project. The Epic Games Launcher was installed to download and install Unreal Engine 5.5 (UE) as the framework is to be built as part of the Unreal Engine. Unreal Engine requires Microsoft Visual Studio to compile C++ projects, which made Visual Studio 2022 the recommended IDE. IntelliSense and Windows SDK were set up for Visual Studio to sync with UE. GitHub Desktop was installed to connect to the development repository to set up version control and give the ability to move the project to another computer if needed, such as if the laptop was damaged. 

After all programs were installed, testing of the UE and Visual Studio compilers began and there was an issue with the compilers failing or taking several minutes to compile small changes. After some configuration and research on the Unreal Engine Forums it was discovered that Windows 11 was limiting UE to only use 3GB of memory. The Windows virtual memory settings 

28 

were adjusted to allow UE access to additional memory. This had the desired effect, and UE was able to compile quickly without any further issues. 

Final testing verified that Unreal Engine launched correctly, C++ classes could be created and compiled, IntelliSense recognized Unreal Engine classes, and GitHub Desktop successfully detected repositories and synchronized project changes. Completion of this testing confirmed that the development environment met all planned requirements and was ready for the implementation of the framework's core systems. This testing verified the framework's integration with Unreal Engine's C++ API and Blueprint system, ensuring reliable communication between the engine and framework classes. GitHub Desktop was used to integrate version control into the development workflow. 

# **Figure 7** **_Working Visual Studio Environment_** 



<!-- Start of picture text -->
0 MNTSGFamework<br>s eop = Wins a> Ape Soa «<br>= | a<br>ED reasy 10/0= 70 man= WB iisctament= ><br><!-- End of picture text -->

# **_Framework Development_** 

# **User Interface Development** 

The User Interface (UI) is the interaction framework between the user and the program. For 

this stage of development, the functionality to allow users to interact with the framework systems 

29 

and the visual details to give users feedback on their actions were required. This realization brought a significant change to the originally planned UI milestone as both player interaction and the interface would need to be developed together to ensure a user could interact with the systems of the framework. This meant writing a new milestone and requirements focused on user controls from mouse and keyboard, and displaying game feedback for the user via the UI. 

Development began with the UI, as starting with player input would leave nothing to test input feedback against. Using information from GGameDev on YouTube (GGameDev, 2023), the UI was initially built from smaller widgets, which are UE’s display layer objects, that represent repeatable sections such as text boxes for displaying information or buttons to allow user interactions. Then a larger widget called a Heads-Up Display (HUD) was created using the smaller widgets. This allowed changes to be made as needed throughout development without having to modify every individual widget. If an update to the text boxes were needed (which did occur), only the base widget would need the update, and then all other text boxes would be updated along with it. This made the creation and updating of the wireframe designs from the design phase of this project much easier to implement. 

**Figure 8** 



<!-- Start of picture text -->
Early work on HUD<br><!-- End of picture text -->

After the HUD was completed, work on the user controls was implemented. In UE this 

meant creating an Input Mapping Context (IMC) and individual Input Actions (IA). Input Actions 

30 

define the actions performed by the game, while the Input Mapping Context maps the player's physical inputs, such as a mouse click, to those actions. These actions were assigned to a default IMC and added to the Player Controller class which acts as the manager for user input and screenrelated interactions. Plans to create a main menu screen and implement custom or third-party UI assets were deferred due to the time constraints of the MVP development schedule. 

# **Battle Grid Development** 

Creating the game map designated as the Battle Grid required the creation of grid sections designated as Battle Tiles. The Battle Tiles represent each location on a grid that a unit could occupy and the terrain that location represented. Each Battle Tile class was created in C++ and held related information such as a randomly chosen terrain type and grid location represented as X and Y coordinates. Randomly generating the terrain type provided a fast method for repeatedly testing grid creation and gameplay systems without requiring manual map creation. 

An Actor Blueprint, which is an Unreal Engine object represented in 3D space, is used as a child of Battle Tile so the actor inherits the functions and values from the C++ class. This allows the tiles to exist in the Unreal Engine’s 3D environment while allowing coding using C++. This follows Unreal Engine's recommended C++ and Blueprint development workflow (Epic Games, n.d.-a). Implementing classes and blueprints this way allows C++ to handle the back-end functions of objects while the blueprints are used to more easily change front-end aspects of an object such as the 3D model. This approach makes future changes that do not affect the core mechanics easier for team members who are not programmers. 

# **Figure 9** 

31 

# **_Battle Tile Actor in Unreal Engine_** 



<!-- Start of picture text -->
ad » 7 @v.@u @ x a<br>~~ @ Te Mesh (TileMesh) ait —<br>en<br>&<br>°<br><!-- End of picture text -->

After the creation of the tiles, the battle grid itself was implemented using the same C++ and Actor Blueprint pattern of the Tiles. The battle grid and tiles are handled by the Battle Grid Manager object. This object accepts three primary parameters: Max X, Max Y, and Tile Shape (square or hexagonal). It uses this information to generate a grid using the size of the tiles to offset each new tile creation along with algorithms for the offset of hex tiles due to the hexagonal shape (Patel A. J., 2013). 

Research into developers designing their own predetermined maps instead of the random terrain generation currently built into the Grid Manager revealed that it would require more systems such as development tools, save and load states, and dedicated terrain editor UI. It was determined to defer this development for a future date and remove it from the MVP. 

After the Battle Grid Manager’s map generation and tiles were tested and functioning 

correctly, it was determined that effective camera controls were required to test and interact with the framework. Thus, camera controls were created using the Player-Controlled Cameras in Unreal Engine CPP documentation from Epic’s community (Epic Games, n.d.-f). The implementation of a Player Camera C++ class and actor Blueprint allowed the player to move the camera around following the actor in the 3D space, but without a model for the actor the player would seem to be floating in the air of the game looking down at the battle grid. This implementation provided an effective method for viewing the map during testing and establishing the foundations for camera control for the game framework. 

32 

# **Unit System Development** 

Units represent the player- and AI-controllable actors which are the focus of any game 

created with the framework. This would mean that developers will want to allow Units to have unique attributes, abilities, and possible customizations. Therefore, a Base Unit C++ and Actor combination was implemented, allowing development teams to create child classes for the Base Unit to allow unique Units and unit types to function with the core mechanics of the framework. 

The Base Unit required functionality that every Unit needs including attributes and functions for dealing and receiving damage, handling death when health reaches zero, movement costs, and movement. Dealing and receiving damage are simple functions that use the Unit’s attributes and updates values as needed. A Unit Manager class was created to handle actual calculations (mentioned later). When a Unit’s health reaches zero during the receive damage function, it calls the death function which broadcasts an event using the Observer Pattern (Gamma et al., 1994) to allow other functions such as UI updates to trigger on the death of a Unit. 

Originally, Unit movement was designed to be handled by the Unit Manager. During implementation, it became apparent that having Units manage their own movement supported future unit-specific movement behaviors such as flight. The Unit movement function uses the ‘tick’ function from Unreal Engine to update the location of the Unit every frame making a smooth transition in movement. This tick turns on after the move function is called, then the tick is turned off when the unit reaches its destination. This architecture is used alongside pathfinding (mentioned later) to create a set of locations for a unit to move to. The movement cost matrix attribute is used by the pathfinding to determine possible paths the Unit can travel across different terrain types. 

Like the Grid Manager managing Battle Tiles, the Unit Manager manages all Units on the battle grid. The Unit Manager is responsible for creating, destroying, tracking grid positions, and directing actions for each Unit. This acts as a separation from management duties that individual Units do not need control over. Units are tracked by the Unit Manager along with their grid position by using a Map container called TMap built into Unreal Engine (Epic Games, n.d.-e). When a unit 

33 

is created a Transform, which is an Unreal Engine structure which stores an Actor's location, rotation which determines the Actor's facing direction, and scale in 3D space, is passed to the unit creation function as an argument. Unit Manager uses the information to generate a Unit using the Unreal Engine’s Spawn Actor function to generate the Unit object in 3D space. This information is passed to the Unit Manager via the Battle Manager (mentioned later). Destroying a Unit is done by removing the unit from the TMap and calling the Actor destroy function from Unreal Engine that handles the necessary cleanup of the Actor and its associated memory. Unit actions are passed through from the Player Controller or AI to Battle Manager to Unit Manager and lastly to the Unit which takes the action. Passing actions through each manager allows each step to take any necessary intermediate actions. An example would be for the Player Controller to confirm the correct input or Battle Manager to check if the action is valid to take. Although this introduces additional processing steps, it ensures that each subsystem performs only the responsibilities assigned to it, preserving the modular architecture established during the design phase. 

# **Battle Management** 

The Battle Manager acts as the main controller for the game. It connects Player Controller to Grid Manager and Unit Manager and is the authoritative manager for later multiplayer functionality. The Battle Manager’s responsibility is to facilitate Input Actions initiated by players and AI, confirm their validity, and then pass on the relevant information to the Grid and Unit Managers. For example, when a player selects a Unit and chooses to move, the Battle Manager validates that the action is permitted before forwarding the request to the Unit Manager for execution. This is done through validation functions that call other functions within the Unit and Grid Managers to verify the requested action. This separation of responsibilities promotes modularity while maintaining centralized game control, simplifying future multiplayer implementation. 

# **Figure 10** 

34 



<!-- Start of picture text -->
BattleManager Code Example<br>ry MMTSGFamework<br><!-- End of picture text -->

# **Pathfinding Foundation** 

Pathfinding was built into the Grid Manager to facilitate Unit movement, range finding, and 

similar functions. When a Unit is selected by a player, the Battle Manager will pass on the Unit information to the Pathfinding functions of the Grid Manager to find possible Tiles the Unit is able to move to. This is done by finding each Tile’s neighbors using a formula described by Patel (Hexagonal grids, 2013). Each neighbor is checked against the Unit’s movement costs based on the terrain of the Tile to ensure it is a valid tile for movement. Range finding was implemented using a modified breadth-first search (Wikipedia contributor, 2026), that incorporates concepts from Dijkstra's algorithm (Wikipedia contributor, 2026) to account for terrain movement costs. These algorithms were discovered during research in pathfinding algorithms on the Red Blob Games website (Patel A. J., 2024). The valid tiles are highlighted by calling the Tile’s SetHighlightState function. This displays to the player valid Tiles for movement. Then when a Move Action is selected by a player, the Battle Manager uses Pathfinding to validate the Move Action and create a path of Tiles for the unit to move to. Path generation was implemented using a modified A* algorithm (Wikipedia contributor, 2026) that also incorporates movement costs when selecting the 

35 

optimal route. The Battle Manager then instructs the Unit to traverse the generated path one Tile at a time. 

# **Current Project Progress** 

Three milestones of Combat System, Game Round (including Player Turns and Battle End functionality), and Multiplayer are still in progress at this stage of development. Due to time constraints Multiplayer functionality was deferred until after the completion of the MVP. This decision prioritized the completion of the framework's core gameplay loop while preserving the architecture necessary to support multiplayer in a future iteration. However, core systems will still be designed for multiplayer compatibility to allow its implementation at a later date. The Combat and Game Round systems were in active development and were planned for completion before the testing phase. Due to the project timeline, development was limited to the core functionality required for the MVP. 

# **_Technical Performance_** 

The framework uses multiple managers with single responsibility to facilitate a separation of responsibilities. This, along with the use of the Observer Pattern, keeps each system decoupled from the others. This allows for greater flexibility when modifying existing systems or creating new functionality. These managers also function for reliability by implementing individual validation functions to ensure data passing to and from the managers is usable by the function calls. This helps prevent project crashes and unexpected behavior caused by invalid data. Inheritance through the Base Unit and Battle Tile classes allows developers to expand existing functionality without redeveloping the framework's core systems. This enables the framework to scale to meet the needs of individual game projects. 

Implementation of player inputs, camera controls, and context-sensitive UI allows for a smooth gameplay experience. As this project is a game development framework, inheritance through the Base Unit and Battle Tile classes improves the developer experience by allowing a 

36 

developer to create child classes. This design allows these child classes to integrate directly with the core systems without modifying them. The framework runs locally on individual machines without the need for external services and is designed to support future functionality expansions such as controller support, control remapping, and multiplayer. 

# **_Development Reflection_** 

Throughout development, the Agile methodology proved beneficial by allowing 

implementation to evolve as new information became available. Rather than delaying development, system architectural refactoring and scope adjustments were made to the project plan while maintaining progress toward the MVP. The previous phases created the foundational work for the development phase and created a goal-focused development cycle. As each core system was created and tested, it became apparent that many gaps were not discovered during the previous phases on this project. The flexibility of Agile development allowed these changes to take place as new features, such as player camera controls, and architectural changes, such as redefining class responsibilities. 

This project has shown the value of goal-focused development. Each change that came about from new discoveries during development was weighed against the goal of a complete MVP of this project. This goal led to the deferment of several lower-priority systems, including the Multiplayer milestone, allowing development effort to remain focused on delivering a complete and functional MVP. 

# **Iteration 5 (Testing)** 

Normally, a project enters a dedicated testing phase in which its features are evaluated to ensure they align with the project's goals. However, this project was developed using Agile methodology. This methodology develops software through iterative milestones. Each milestone’s features are tested before the development of the next milestone begins. Each of the project’s milestones underwent functional testing, integration testing, and regression testing. 

37 

Upon completion of the development phase, the project was submitted for external code 

review and testing. A request was made for a member of the Philly Game Mechanics organization to conduct the review. They were able to provide valuable feedback on the project's architecture, Unreal Engine best practices, and overall implementation. 

# **_Testing Methodology_** 

Following the Agile methodology, each milestone was tested during development. Testing included ensuring the functionality of each feature in the milestone met the requirements laid out during the design phase, integration testing to ensure new features worked with previously developed milestones, and regression testing to ensure changes made to existing classes and features performed as expected after refactoring. The final stage of testing consisted of an external peer code review. 

# **_Functional Testing_** 

During the development of each milestone the functions, classes, and Unreal Engine 

integration were tested to ensure that the features met with the goals of each milestone. These tests were performed to verify that each milestone satisfied its functional requirements before work 

began on the next iteration. Table 2 below summarizes the functional testing performed during development. 

# **Table 2** 

# _Project Functional Testing_ 

|**Feature Tested **|**Test Procedure**|**Expected Result**|**Actual Result**|**Status**|
|---|---|---|---|---|
|Development<br>Environment|Launch Unreal Engine,<br>create a C++ project,<br>compile code, verify<br>IntelliSense, and<br>synchronize project<br>with GitHub Desktop.|<br>Development<br>environment functions<br>correctly and supports<br>C++ development.|<br>All components operated<br>successfully and met<br>development<br>requirements.|<br>Pass|
|User Interface|Create UI widgets,<br>assign input actions,<br>navigate menus, and<br>verify HUD updates.|User input is accepted<br>and the interface<br>updates to reflect<br>player actions.|Core UI systems<br>functioned correctly.<br>Controller support and<br>menu polish were<br>deferred beyond the<br>MVP.|Partial<br>Pass|



38 

|**Feature Tested **|**Test Procedure**|**Expected Result**|**Actual Result**|**Status**|
|---|---|---|---|---|
|Battle Grid<br>Generation|Generate battle maps<br>of different sizes and<br>verify tile creation,<br>terrain assignment, and<br>grid accessibility.|<br>Grid generates<br>correctly with<br>accessible tile<br>information.|Battle maps generated<br>successfully with<br>randomized terrain and<br>accessible tile data.|Pass|
|Unit Systems|Spawn units, move<br>units, apply damage,<br>defeat units, and verify<br>movement costs.|<br>Units perform all core<br>gameplay functions<br>correctly.|<br>Unit creation, movement,<br>combat attributes, and<br>defeat functionality<br>operated as expected.|<br>Pass|
|Pathfinding and<br>Range Finding|Select a unit, calculate<br>movement range,<br>generate paths across<br>multiple terrain types,<br>and verify movement<br>restrictions.|Valid movement<br>ranges and paths are<br>generated based on<br>terrain costs.|Pathfinding and range<br>calculations correctly<br>considered terrain<br>movement costs and<br>blocking conditions.|Pass|
|Combat and<br>Unit Actions|Select a unit, issue<br>movement and attack<br>commands, and verify<br>UI and gameplay<br>updates.|Commands execute<br>correctly and all<br>affected systems<br>update together.|Unit actions executed<br>successfully with<br>synchronized UI, grid,<br>and unit updates.|Pass|
|Round and Turn<br>System|<br>Activate units, perform<br>Skip Turn, and verify<br>activation tracking.|<br>Units may activate<br>once per round and<br>skipped turns consume<br>an activation.|<br>Core activation and Skip<br>Turn functionality<br>operated correctly.<br>Round completion and<br>multiplayer turn<br>management were<br>deferred.|<br>Partial<br>Pass|
|Multiplayer|Attempt multiplayer<br>feature verification.|Multiplayer lobby,<br>synchronization, and<br>gameplay function<br>correctly.|Testing was not<br>performed because<br>multiplayer was<br>intentionally deferred<br>until after MVP<br>completion.|Deferred|



# **_Integration Testing_** 

Integration between features was tested to verify that the independently developed systems communicated correctly once combined into the overall framework. Unlike functional testing, integration testing ensured that information flowed correctly between the framework's managers, user interface, and Unreal Engine gameplay systems. 

Successful integration testing demonstrated that each subsystem communicated with other 

related systems properly. The Player Controller, Battle Manager, Grid Manager, Unit Manager, Base 

39 

Unit, Battle Tile, and Battle HUD were able to exchange information as designed without 

introducing unintended behavior or dependencies. This testing also verified the event-driven communication used in the framework. 

**Table 3** 

_Project Integration Testing_ 

|Systems<br>Integrated|Test Procedure|Expected Result|Actual Result|Status|
|---|---|---|---|---|
|Player<br>Controller →<br>Battle Manager|Select a unit and issue a<br>command.|<br>Player commands are<br>received and validated<br>by the Battle Manager.|Commands were<br>successfully validated<br>and forwarded.|Pass|
|Battle Manager<br>→ Grid<br>Manager|Request movement<br>range and pathfinding.|Grid Manager returns<br>valid movement range<br>and path.|Range and path<br>information were<br>returned correctly.|Pass|
|Battle Manager<br>→ Unit|Pass a movement<br>command to the Unit|Unit Manager receives<br>and processes the|Movement commands<br>are processed|Pass|
|Manager|Manager.|movement request.|successfully.||
|Unit Manager<br>→ Base Unit|Move command sent to<br>unit to move along the<br>generated path.|Unit follows the<br>generated path and<br>reports completion.|Units completed<br>movement and broadcast<br>completion events.|<br>Pass|
|Player<br>Controller →<br>Battle HUD|UI updates when new<br>selection of units, tiles,<br>and actions.|UI reflects current game<br>state and player<br>selections.|HUD and gameplay<br>remained synchronized.|<sup>Pass</sup>|



# **_Regression Testing_** 

Performing regression testing whenever architectural changes were made during 

development ensured that features created earlier in development still worked as intended. Since the 

project followed the Agile methodology, class responsibilities evolved as new features were 

implemented and architecture matured. After each refactor, previously completed functionality was 

re-tested to ensure that changes made during refactoring did not introduce new bugs or break existing features. 

# **Table 4** 

_Project Regression Testing_ 

40 

|Refactored<br>Feature|Change Made|Regression Test Performed|Result|
|---|---|---|---|
|Unit Movement|Movement responsibility transferred to<br>BaseUnit from UnitManager|Verified units still moved<br>correctly and completed<br>movement events.|Pass|
|Battle Manager|Centralized command validation within<br>the BattleManager|Verified player commands<br>continued to execute correctly.|<sup>Pass</sup>|
|Grid Manager|Moved pathfinding and range calculations<br>into the Grid Manager.|<br>Re-tested movement,<br>highlighting, and tile selection.|<sup>Pass</sup>|
|HUD/UI|Moved user interface responsibilities into<br>dedicated HUD widgets.|Verified UI updates and player<br>commands continued<br>functioning.|<br>Pass|
|Player Controller|Added command processing and selection<br>logic instead of PlayerController<br>controlling commands directly.|<br>Re-tested unit selection, tile<br>selection, and command<br>execution.|Pass|
|Class<br>Responsibilities|Responsibilities redistributed between<br>managers and gameplay classes during<br>development|Verified existing gameplay<br>systems continued functioning<br>after refactoring.|<br>Pass|



# **_External Code Review_** 

At the completion of the final development milestone’s testing, the entire project was presented to the Philly Game Mechanics organization, and a request was made for a programmer to conduct a peer review of the project. The review was performed by Jerry Mras-Swan (personal communication, July 27, 2026), another Unreal Engine developer and member of the Philly Game Mechanics community. He reviewed the class responsibilities, architecture, coding practices, and Unreal Engine API integration. Jerry summarized his overall impression by stating, _"It works well!"_ He further described the overall architecture as well organized and functional. Jerry also noted there were opportunities for improvement that would better align the framework with Unreal Engine’s best practices. These recommendations primarily focused on reducing coupling between classes, improving Unreal Engine API usage, and enhancing the framework’s designer workflow. 

As the project focuses on a functional minimum viable product (MVP), the recommendations were deferred as post-MVP improvements rather than immediate corrections. 

41 

Implementing these recommendations at this time would introduce additional delays to the project's timeline with the possibility of missing the project deadlines. 

# **_Unresolved Issues_** 

The Functional, integration, and regression testing verified that milestones satisfied the requirements established during the Analysis phase. Framework functionality including, user interaction, battle grid systems, unit systems, pathfinding, combat actions, and player turn management, were successfully implemented and tested. Some requirements were intentionally deferred from the MVP and remained outside of the scope of this iteration as they were not required for a functional framework. 

# **Table 5** 

_Project_ Unresolved Issues 

|**Issue**|**Impact**|**Planned Resolution**|
|---|---|---|
|Multiplayer functionality<br>deferred|Multiplayer gameplay could not be<br>tested.|Implement after MVP is<br>complete.|
|Round completion/player<br>turn system incomplete|Battles cannot yet progress through a<br>complete match.|Complete remaining turn<br>management milestone post-<br>MVP.|
|AI opponents not<br>implemented|Battles currently require manual control<br>of all units.|Add simple AI after core<br>gameplay loop is complete.|
||Framework currently supports mouse||
|Controller support not<br>implemented|and keyboard only. Preventing the<br>framework from supporting controller-<br>based gameplay and console games.|Add Enhanced Input<br>mappings after post-MVP.|
|Control remapping/options<br>menu deferred|Players cannot customize controls.|Planned as a post-MVP<br>usability feature.|
|||Develop a dedicated map|
|Map editor/save-load<br>system deferred|Only randomly generated battle maps<br>are available.|editor and save/load system<br>as a future expansion of the<br>framework.|
|UI polish incomplete|Interface is functional but lacks final<br>visual polish and planned widgets.|Improve after gameplay<br>systems are finalized.|



# **_Testing Reflection_** 

Ensuring testing was completed throughout the development processes prevented bugs 

introduced earlier in development from causing cascading issues throughout the project. Preventing 

42 

these cascades helped ensure that the project kept to a reasonable schedule, even as delays were encountered. A cascading event such as leaving unit movement in Unit Manager could have caused issues with pathfinding or other ability systems. This then would cause Unit Manager to need to act on every possible ability instead of forwarding commands. 

Testing revealed that several classes required major refactoring to better align with the architecture design of the project. These refactors made future milestones easier to implement, allowing development to focus on the current milestone rather than reworking past development steps. One such refactor that occurred during the development was the change to have Units handle their own movement instead of the Unit Manager. This change helped prevent an issue that would have occurred with commands that was developed later. 

Some important lessons were learned via the submission of the project for external peer review. Having other developers examine the project revealed that there was still much to learn outside of Unreal Engine’s documentation. Discussing the project with an experienced developer brought insight that independent research could not provide. They were able to point out dependencies between classes that were not intended. These dependencies will need to be fixed after the project is moved beyond the MVP. 

The completion of the MVP project also provided a better understanding of project scope and timeline estimations. Projects of this scale take more time to develop than originally estimated. Even with the additional time planned for possible delays, the project still fell close to a week behind schedule which resulted in a delayed testing phase. Learning about scope management and revising estimations on larger projects was an important takeaway from this project. 

# **Iteration 6 (Implement and Maintenance)** 

This framework project was designed as a Minimum Viable Product (MVP) to validate its design and architecture before initiating full-scale development. The project is not a self-contained software application, but a reusable framework that other developers can extend upon to create their 

43 

own tactical strategy games. Due to these distinctions, the implementation and maintenance phase of the project does not follow the standard expectations of deploying completed software. At this stage, the framework provides the fundamentals for all the core mechanics required for a tactical strategy game. Therefore, this phase focuses on preparing the framework for long-term development, future distribution, and continued documentation beyond the completion of the capstone project. 

# **_Current MVP State_** 

At the completion of this MVP project, the framework contains a functional battle-grid generation and pathfinding system, Unit Management system, command-focused action system, working camera and camera movement system, Player Controller and UI/HUD system, and a Battle Manager that ties all these systems together with validation checks. 

Testing shows that all these systems are in working order and work well together. There is, however, much to improve within these systems, including a more in-depth player turn and game round system, multiplayer implementation, developer tools for Unit and Tile creation, map creation systems, AI opponents, and controller support. 

# **_Framework Distribution_** 

The project will continue to be distributed through a GitHub repository (Microsoft, 2026). This repository will be the primary platform for future development, third-party testing, collaboration, and version control. As the framework transitions from an MVP into active development, the repository may be cloned and made private to protect intellectual property while continuing to use GitHub for version control. The original MVP repository will remain publicly available as an open-source contribution and a record of the completed capstone project. 

# **Figure 11** 

44 

# **_GitHub Repository for Project_** 



<!-- Start of picture text -->
© Keynsham - seco | Game Farm Uel Eng<br>=<br>Releases<br>MMTSGFramework °<br><!-- End of picture text -->

Following the continued development, the framework is intended to be released onto the 

FAB marketplace hosted by Epic Games. The FAB marketplace will simplify licensing and royalty management for the framework. Consideration will also be given to other marketplaces. However, the administrative overhead with royalty tracking and reporting may make FAB Marketplace the main distribution strategy. (Epic Games, n.d.-b). 

# **_Documentation_** 

Documentation for the framework is essential for future developers to understand how to 

extend and maintain changes to the framework. As the project is currently in an MVP state, documentation is primarily focused on the development process, software architecture, and project management not end-user documentation. Therefore, additional documentation and guides will be developed as the framework transitions beyond the MVP. 

# **Table 6** 

# **_Framework Documentation_** 

|**Document**|**Purpose**|
|---|---|
|Capstone Project Overview and<br>SDLC Plan|Outline the requirements and workflow for the project|
|Development Journal|Records implementation decisions, technical challenges, and<br>progress throughout development.|
|Project Checklist|Tracks milestone completion, feature status, and deferred|



45 

# **Document** 

# **Purpose** 

functionality. GitHub Repository Maintains source code, version history, and project organization. Document class responsibilities, function behavior, and Source Code Comments implementation details directly within the code. Illustrate relationships between the framework's managers, Architecture Diagrams gameplay systems, and user interface components. 

# **Figure 12** **_Project Checklist_** 



<!-- Start of picture text -->
Modular Multiplayer Tactical Strategy. @ Share te +<br>Modular Multiplayer Tactical<br>Strategy Game Framework =<br>3) Project Notes<br>Project Requirements<br>key<br><!-- End of picture text -->

Note: Project Checklist kept on Notion to ensure project kept on track and milestone requirements 

were met 

# **Figure 13** **_Project Work Notes_** 

46 



<!-- Start of picture text -->
Modular Multiplayer Tc... Project Notes Qs te<br>June 15 — June 21: Creation of Unit structure and<br>systems<br>Goals:<br>* Units can deal and receive damage - Done 7<br>* Units can move across the battle map -Done<br>* Units have a defined movement cost matrix. Tiss later used in the pathfinding phase, - Done<br>* Units can be defeated -Done<br>«If time allows, create items that units can equip to modity<br>their attributes<br>Possible combat flow<br>BattleManager<br>|<br>[+ GridManager<br>[-unitManager<br>—CombatManager<br>Battle manager gets the action details rom the confirm(uit action, target)<br>battle manager processes the action (in this exampleattack)<br>unit managers called to get the needed unit info<br>combat manager does all the base calculation + gid or simitar modifiers<br>as needed 7)<br><!-- End of picture text -->

Note: Project work notes used as reference for documentation. These notes were used to 

look back upon between work sessions and between milestones to keep work organized. 

The documents provide the required information for continued development of the 

framework. As additional features are implemented, new documents will be created to include all information required to use and extend the framework. 

47 

# **Table 7** 

# **_Planned Future Framework Documentation_** 

|**Document**|**Purpose**|
|---|---|
|README|Will provide general information regarding the project|
|Developer Setup Guide|Installation instructions, software requirements, and general tool<br>configurations|
|API Documentation|Will document public classes and interfaces for the framework.|
|Developer Guide|Will describe how to extend the framework by creating new units,<br>tiles, commands, and gameplay systems.|



# **_Developer Support and Maintenance_** 

Unlike traditional software applications, this game development framework is intended for software developers who are expected to be familiar with their development environment. As a result, there are no plans for formal training for this project. Instead, comprehensive documentation will be created as the framework matures beyond the MVP. This documentation will be provided alongside the distribution of the framework. This approach is consistent with common practices used by commercial game development frameworks distributed through the Epic Games FAB marketplace (Epic Games, 2025). 

Likewise, the framework will not include a traditional help desk. Following common practices of the FAB marketplace, the team will not provide any Help Desk support either (Epic Games, 2025). Developers will instead be able to submit questions, bug reports, feature requests, and general feedback through the framework's FAB Marketplace page. This feedback will be reviewed throughout future development and may be incorporated into later releases to resolve bugs, improve usability, and add additional features to the framework. This strategy follows the Agile development methodology by allowing community feedback to influence future iterations of the framework (Beck et al., 2001). 

48 

# **_Future Development Roadmap_** 

Following the completion of this project, the framework will continue development using the Agile methodology. There are several planned features remaining before the framework can be considered for public distribution. Future iterations on the framework will continue to build upon the existing architecture, adding additional features while maintaining the modular design established during this project. 

|**Table 8**|||
|---|---|---|
|**_Planned Features_**<br>**Planned Feature**|**Priority**|**Purpose**|
|Complete Round & Turn Syste|m High|Finish the core gameplay loop required for a complete<br>tactical battle.|
|Multiplayer Support|High|Implement networked gameplay using the architecture<br>established during the MVP.|
|AI Opponents|High|Allow single-player battles against computer-<br>controlled opponents.|
|Controller Support|Medium|Expand accessibility beyond keyboard and mouse.|
|Map Editor & Save/Load|Medium|Allow developers to create and reuse custom battle<br>maps.|
|Documentation Expansion|Medium|Produce API documentation, setup guides, and<br>developer tutorials.|
|Unreal Engine Best Practice<br>Improvements|Medium|Implement recommendations from the external code<br>review.|
|Marketplace Release|Low|Prepare the framework for publication on the Epic<br>Games FAB Marketplace.|



# **_Implementing and Maintenance Reflection_** 

Completing the MVP of the framework demonstrated that the project was built on a solid 

architectural foundation that supports the core game mechanics. Throughout development, many of the original design plans were modified and evolved as new challenges were encountered. The modular architecture allowed these changes to be made without requiring a complete redesign, validating the decision to develop flexibility into the project early in the development. 

49 

The implementation phase demonstrated that completing an MVP project is not the end of development, but the beginning of the framework's transition out of the MVP. Many planned features remain before the framework is ready for public release, establishing clear milestones for future development. By successfully validating the framework as a proof of concept the MVP enables future development to focus on expanding functionality and usability of the framework rather than designing core systems. 

Maintenance for this framework begins during development, not after the project is finished. Updating documentation throughout the project’s life cycle along with the uploads to the GitHub repository provided a clear record of work throughout the project. There was also effort to deal with technical debt as it was discovered to ensure it did not cause problems later in development. At this point in the development of the MMTSG Framework, the core mechanics are developed, and the remaining focus is on cleaning up systems, quality of life features, additional functionality on existing systems, and built-in tools for developers. After these improvements to the framework, it will be ready for additional external testing and a possible 1.0 release. 

# **Compliance with Ethical Considerations in System Development** 

Ethical considerations were included in the development of the MMTSG Framework. The Software Engineering Code of Ethics and Professional Practice establishes several principles for responsible software development, including producing quality software, maintaining professional judgment, respecting intellectual property, and ensuring that software development remains consistent with the public interest (ACM/IEEE-CS Joint Task Force on Software Engineering Ethics and Professional Practices, 1999). These considerations guided decisions made during the planning and design phases of this project. 

The main ethical focus for this project was producing quality reusable software and respecting intellectual property. Every aspect of the framework was designed and developed to meet the high standard of software quality, even though it was intended as an MVP project. This included changes made to ensure reusability, framework functionality, and expandability, along with 

50 

improving code readability through comments and variable/function naming conventions. These practices are consistent with principles described in Clean Code (Martin, 2008). A major design choice was also made early regarding intellectual property. As the framework will eventually be distributed to other developers, it became apparent that using assets with this project could cause issues concerning rights and ownership. These assets would have made the project look and feel cleaner and more complete. However, improvements to the visual presentation of the MVP were not worth the risk of future developers unknowingly using assets in ways that could violate the assets’ licensing requirements. 

Future development will continue to keep these and other ethical concerns in consideration to ensure the framework meets a high standard of ethical responsibility. Maintaining these ethical standards is particularly important as the MMTSG Framework moves toward public distribution. As the first large software project the developer intends to distribute, maintaining software quality, respecting intellectual property, and being transparent about the framework’s capabilities and limitations will be important in establishing trust with developers who may use the framework. 

51 

# **References** 

- ACM/IEEE-CS Joint Task Force on Software Engineering Ethics and Professional Practices. 

   - (1999). _The Software Engineering Code of Ethics and Professional Practice_ . Association for Computing Machinery. https://www.acm.org/code-of-ethics/software-engineering-code 

- Beck, K., Beedle, M., Cockburn, A., Cunningham, W., Fowler, M., Marick, B., Kern, J., Jeffries, R., Hunt, A., Highsmith, J., Grenning, J., Martin, R. C., Mellor, S., Schwaber, K., Sutherland, J., Thomas, D., & Van Bennekum, A. (2001). _Manifesto for Agile software development._ Agile Manifesto. https://agilemanifesto.org/ 

D'Agusto, L. J. (2026a). MMTSGF: Development journal [Unpublished manuscript]. 

D'Agusto, L. J. (2026b). MMTSGF: Project milestone checklist [Unpublished manuscript]. 

- DragonWarrior008. (2024). _Best engine / framework for turn-based multiplayer 2D web game_ . 

   - Retrieved June 12, 2026, from 

https://www.reddit.com/r/gamedev/comments/1aj24sy/best_engine_framework_for_turnbas ed_multiplayer/ 

- Epic Games. (2025, March 12). _Turn Based Strategy_ . Retrieved June 12, 2026, from FAB. from https://www.fab.com/listings/3efedfe9-f1e8-4b33-9bdc-14155dbfebbe 

- Epic Games. (n.d.-a). _CPP and Blueprints_ . Retrieved July 10, 2026, from Epic Games Developer. https://dev.epicgames.com/documentation/unreal-engine/cpp-and-blueprints-example 

- Epic Games. (n.d.-b). _FAB Documentation_ . Retrieved August 09, 2026, from Epic Games. 

   - https://dev.epicgames.com/documentation/fab/fab-documentation 

- Epic Games. (n.d.-c). _FAB the creator-first marketplace._ Retrieved May 19, 2026, from FAB. https://www.fab.com 

52 

- Epic Games. (n.d.-d). _Hardware and software specifications for Unreal_ . Retrieved June 23, 2026, 

   - from Epic Games Developer. 

https://dev.epicgames.com/documentation/unreal-engine/hardware-and-software- 

specifications-for-unreal-engine?lang=en-US 

- Epic Games. (n.d.-e). _Map Containers in Unreal Engine._ Retrieved July 10, 2026, from Epic Games Developer. https://dev.epicgames.com/documentation/unreal-engine/map-containers-inunreal-engine?lang=en-US 

- Epic Games. (n.d.-f). _Player-Controlled Cameras in Unreal Engine CPP_ . Retrieved July 10, 2026, from Epic Games Developer. 

   - https://dev.epicgames.com/documentation/unreal-engine/quick-start-guide-to-playercontrolled-cameras-in-unreal-engine-cpp?application_version=5.5 

- Epic Games. (n.d.-g). _Unreal Engine 5.7 Documentation | EPIC Developer Community. Epic Games Developer._ Retrieved May 19, 2026, from 

https://dev.epicgames.com/documentation/unreal-engine/unreal-engine-5-7-documentation 

- Gamma, E., Helm, R., Johnson, R., & Vli, J. (1994, Oct 31). _Design patterns: elements of reusable Object-Oriented Software_ . (Addison-Wesley) Retrieved June 23, 2026, from InformIT. https://www.informit.com/store/design-patterns-elements-of-reusable-objectoriented-9780201633610 

- GGameDev. (2023, November 11). _Getting into C++ with Unreal Engine - Part 6 - User Interface (A) [Video]_ . Retrieved July 10, 2026, from YouTube.. https://www.youtube.com/watch? v=ErVcuQXTm_c 

- LibreOffice. (n.d.). _LibreOffice is an open source office suite created by you, for you._ Retrieved May 19, 2026, from https://www.libreoffice.org/ 

53 

- Martin, R. C. (2008). _Clean Code: A Handbook of Agile Software Craftsmanship._ Pearson 

   - Education. www.pearson.com/en-us/subject-catalog/p/clean-code-a-handbook-of-agilesoftware-craftsmanship/P200000009044/9780136083252 

- Microsoft. (2021, November 3). _Visual Studio Code - Your home for development_ . visualstudio. https://code.visualstudio.com/ 

Microsoft. (2026). _Change is constant. GitHub keeps you ahead_ . GitHub . https://github.com/ 

- Microsoft. (n.d.). _Microsoft Word for the Web. Microsoft Word Online_ . Retrieved May 19, 2026, from https://word.cloud.microsoft/ 

- Monday.com Ltd. (n.d.). _The AI work platform for people & agents_ . Retrieved May 19, 2026, from Monday.com. https://Monday.com/ 

Paradox Interactive. (2018, April 24). _BattleTech_ . paradoxinteractive. 

https://www.paradoxinteractive.com/games/battletech/about 

Patel, A. J. (2013). _Hexagonal grids_ . redblobgames. 

https://www.redblobgames.com/grids/hexagons/ 

- Patel, A. J. (2024). _Introduction to the A* algorithm._ redblobgames. 

https://www.redblobgames.com/pathfinding/a-star/introduction.html 

- Phoenix Market. (2025, November 20). _Turn-Based Strategy RPG Template_ . Retrieved June 12, 2026, from FAB. https://www.fab.com/listings/f3fe31dd-85f7-4720-b485-301bd77996e8 

- Square Enix. (2025). _FINAL FANTASY TACTICS The Ivalice Chronicles_ . Square Enix Games. https://final-fantasy-tactics-the-ivalice-chronicles.square-enix-games.com/en-us 

- Wikipedia contributor. (2026, July 9). _A* search algorithm_ . Retrieved July 10, 2026, from 

   - Wikipedia. https://en.wikipedia.org/wiki/A*_search_algorithm 

54 

Wikipedia contributor. (2026, July 8). _Breadth-first search_ . Retrieved July 10, 2026, from 

Wikipedia. https://en.wikipedia.org/wiki/Breadth-first_search 

Wikipedia contributor. (2026, June 2). _Dijkstra’s algorithm_ . Retrieved July 10, 2026, from Wikipedia. https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm 

