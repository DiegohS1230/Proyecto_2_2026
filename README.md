# Proyecto_2_2026
Project 2 – Hero Has Returned Simulation
Description

This project is a turn-based simulation inspired by the Hero Has Returned universe.
The simulation represents the collapse and defense of South Korea after the return of several corrupted heroes.

The player controls the Return Hero, while enemy heroes use different combat strategies to destroy zones, spread corruption, and eliminate civilians.

The project was developed in C++ using:

Object-Oriented Programming
Design Patterns
Smart Pointers
File Management
Polymorphism
Generic Data Structures
Main Features
Turn-based simulation engine
Multiple enemy hero strategies
Zone destruction and corruption system
Civilian management
Hero abilities
Logging system (log.txt)
Final simulation report (report.txt)
Generic linked list implementation
Smart pointer usage (unique_ptr)
Heroes
Player Hero
Return Hero
Uses healing and restoration abilities
Enemy Heroes
Sword Hero
Deals massive destruction to zones
Attacks the player directly
Time Hero
Sacrifices health to temporarily increase attack power
Faith Hero
Spreads corruption and reduces civilians
Design Patterns Used
Strategy Pattern

Enemy heroes use interchangeable combat strategies.

Examples:

SwordStrategy
TimeStrategy
FaithStrategy
Polymorphism

Abstract base classes:

Hero
Ability
HeroStrategy
Delegation

EnemyHero delegates combat behavior to HeroStrategy.
