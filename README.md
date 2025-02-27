# Corner Grocer Tracker

## Overview
The **Corner Grocer Tracker** is a C++ program that tracks how many times each grocery item is purchased. It allows users to:
- Look up the frequency of a specific item.
- Display a list of all item frequencies.
- Print a histogram of item purchases.
- Store frequencies in a backup file (`frequency.dat`) for future reference.

This project showcases file I/O, object-oriented programming, and efficient data storage using C++.

## Features
- **Menu-Driven Interface**: Simple text-based menu for user interaction.
- **Data Persistence**: Reads from an item list and writes results to `frequency.dat`.
- **Efficient Data Handling**: Uses maps to track frequencies efficiently.
- **Histogram Output**: Displays item purchase counts visually using asterisks (`*`).

## What I Did Well
- Implemented **OOP principles** by encapsulating logic within the `GroceryTracker` class.
- Used **file I/O** effectively for data persistence.
- Designed a **user-friendly interface** with intuitive menu options.
- Ensured **efficient item lookup** using a map data structure.

## Areas for Improvement
- **Error Handling**: Could improve handling of missing files or invalid inputs.
- **Performance Optimization**: Using an unordered map may improve lookup speed.
- **Expanded Features**: Adding sorting or a graphical interface would enhance usability.

## Challenges and Solutions
- **File I/O Complexity**: Handling file reading and writing required careful debugging.
  - Solution: Used `ifstream` and `ofstream` with checks to ensure files existed before reading.
- **Histogram Formatting**: Displaying a clear histogram without misalignment took some tweaking.
  - Solution: Adjusted spacing and alignment logic for clarity.

## Transferable Skills
- **Object-Oriented Programming**: Applied encapsulation and modular design.
- **Data Persistence**: Used file I/O for saving and retrieving data.
- **Menu-Driven UI**: Built structured user interactions.
- **Debugging Skills**: Learned to troubleshoot file-handling errors.

## Code Maintainability & Readability
- Used **consistent naming conventions** for clarity.
- Added **comments** explaining core logic.
- Designed functions to be **modular and reusable**.
