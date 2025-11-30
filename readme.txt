# Space Shooter (SFML C++)

A classic 2D space shooter built using C++ and SFML. Control a
spaceship, dodge enemy attacks, destroy alien fleets, and collect
power‑ups.

## Visual Overview

``` mermaid
graph TD
    A[Game Orchestrator] -->|Manages| B[Player Spaceship]
    A -->|Spawns & Coordinates| C[Enemy Entities]
    A -->|Holds Pointers| D[Collectibles / Add-ons]
    A -->|Renders & Checks| E(Collision Detection)
    B -->|Fires| F[Player Bullet]
    C -->|Fires| G[Enemy Bomb]
    F -->|Destroys| C
    G -->|Damages| B
    D -->|Buffs / Debuffs| B
```

## Features

-   Player Control with smooth movement and firing.
-   Diverse Enemies:
    -   Invaders: Alpha, Beta, Gamma.
    -   Bosses: Monster and Dragon.
-   Dynamic Combat:
    -   Player Bullets.
    -   Enemy Bombs.
-   Power-up System:
    -   Random Surprise Boxes granting buffs or debuffs.
-   Scoring and Player Health System.

## Project Structure

  -----------------------------------------------------------------------
  File                   Description
  ---------------------- ------------------------------------------------
  game.h                 Orchestrates game loop, input, collisions,
                         rendering, progression.

  player.h               Player spaceship logic: move(), fire(), lives.

  enemy.h                Base class + Alpha, Beta, Gamma, Monster, Dragon
                         behaviors.

  bullet.h               Player projectile moving upwards.

  bomb.h                 Enemy projectile moving downwards.

  add_ons.h              Powerups: Powerup_A, Lives_A, Fire_A, Danger_A.
  -----------------------------------------------------------------------

## Gameplay Mechanics

### Player

-   Starts with 3 lives.
-   Keyboard-controlled movement.
-   Fires bullets upwards.
-   Can gain temporary invincibility.

### Enemies

-   Inherit from Enemy base class.
-   Invaders drop bombs periodically.
-   Monster fires horizontal lasers.
-   Dragon tracks player to aim.

### Collectibles (Add-ons)

  Icon   Name        Effect
  ------ ----------- ------------------------------
  ⚡     Powerup_A   Invincibility + speed boost.
  ❤️     Lives_A     +1 life.
  🔥     Fire_A      Stronger fireball bullets.
  ⚠️     Danger_A    −1 life.

## Build & Run

### Prerequisites

-   C++ compiler (g++, clang, MSVC)
-   SFML 2.5+

### Compile

    g++ main.cpp -o space-shooter -lsfml-graphics -lsfml-window -lsfml-system
    ./space-shooter

Ensure the *img/* assets folder is beside the executable.

## Controls

  Key           Action
  ------------- ------------
  Up Arrow      Move Up
  Down Arrow    Move Down
  Left Arrow    Move Left
  Right Arrow   Move Right
  Space         Fire

## License

Open‑source. Tutorial reference: space-shooter-sfml.
