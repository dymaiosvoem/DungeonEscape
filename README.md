# DungeonEscape



DungeonEscape is a learning Unreal Engine C++ project focused on building core gameplay systems through code.



The current goal of the project is to practice Unreal Engine C++ architecture, interaction logic, components, interfaces, and basic gameplay object communication.



## Current Features



* First-person player setup

* Interaction trace from the player camera

* `IInteractable` interface for interactable actors

* `UInventoryComponent` for storing collected item IDs

* Collectable item actor that adds an item to the inventory

* Prototype lock actor with inventory-based key interaction

* Mover component for moving actors

* Trigger component for activating mover logic

* Basic pressure plate / door-style interaction flow



## Technical Focus



This project is intentionally focused on C++ gameplay architecture rather than visual polish.



Main Unreal Engine concepts practiced in this project:



* Actors

* Actor Components

* Interfaces

* Collision and trace channels

* `UPROPERTY`

* `UFUNCTION`

* `TObjectPtr`

* `TSet`

* Runtime component lookup

* Initial separation of responsibilities between player interaction, inventory storage, and interactable world actors



## Project Structure



Important folders:



* `Source/` — C++ source code

* `Content/` — Unreal Engine assets, Blueprints, maps, materials

* `Config/` — project configuration files



Generated folders such as `Binaries/`, `Intermediate/`, `Saved/`, `DerivedDataCache/`, and `.vs/` are intentionally ignored by Git.



## Git LFS



This repository uses Git LFS for Unreal Engine binary assets such as:



* `.uasset`

* `.umap`

* `.ubulk`

* `.uexp`



Before cloning or working with the project, make sure Git LFS is installed:



```bash

git lfs install

```



## Requirements



* Unreal Engine 5.6

* Visual Studio 2022 with C++ tools

* Git

* Git LFS



## Status



This is a completed learning milestone project.



The code is not intended to represent a finished production game. The focus is on gradually improving Unreal Engine C++ architecture and building gameplay systems in a clean, understandable way.



