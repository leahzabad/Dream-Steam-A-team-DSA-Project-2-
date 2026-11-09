# Game Dreamer

**COP3530 — Project 2 | Dream Steam A-team**

Game Dreamer is a Steam game recommendation application that recommends games based on a user's selected genre, category, and platform preferences.

The application loads Steam game data, calculates recommendation scores, compares sorting algorithms, and displays the top recommendations using a graphical user interface built with SFML and TGUI.

## How to Run the Project

### Prerequisites

Before running the application, make sure:

- The project has been successfully built using CLion and CMake.
- The required dependencies (SFML, TGUI, and Catch2) have been installed during the build.
- The `datafiles` folder contains `all_applications.csv`.
- The required assets and font files are available.

### Step 1: Locate the Executables

1. Open Windows File Explorer.
2. Navigate to the folder where the Game Dreamer project is stored.
3. Open the `cmake-build-debug` or `cmake-build-release` folder.
4. Locate the following executable files:

	- `Dream_Steam_A_team_DSA_Project_2_.exe` — Main application
	- `unit_tests.exe` — Automated test cases

### Step 2: Run Game Dreamer

1. Double-click `Dream_Steam_A_team_DSA_Project_2_.exe`.
2. The Game Dreamer interface should open.
3. Select the desired preferences using the dropdown menus:

	- Genre
	- Category
	- Platform

4. The application calculates similarity scores for games based on the selected preferences.
5. Games are sorted according to their recommendation scores.
6. The highest-ranked games are displayed in the application.

### Required Files

The application requires the following files:

- `datafiles/all_applications.csv` — Steam game dataset
- `assets/mainbg.png` — Application background image
- `Milkyway DEMO.ttf` — Application font

The dataset path is configured during the CMake build.

The background image and font are loaded using relative paths, so they must be accessible from the application's working directory.

## How to Run the Test Cases

The project uses Catch2 to automatically test the functionality of its components.

The tests are compiled into a separate executable named `unit_tests.exe`.

### Method 1: Run Using File Explorer

1. Open Windows File Explorer.
2. Navigate to the project's `cmake-build-debug` or `cmake-build-release` folder.
3. Locate `unit_tests.exe`.
4. Double-click the executable.
5. The test cases will run automatically.

A console window will display the test results.

**Note:** The console window may close immediately after execution. Run the code in an IDE or use a Command Prompt if you want to avoid this. 

### Method 2: Run Using Command Prompt

1. Open the folder containing `unit_tests.exe` in File Explorer.
2. Click the address bar at the top of File Explorer.
3. Type `cmd` and press Enter.
4. Enter the following command: unit_tests.exe

5. The tests will execute, and the results will remain visible in Command Prompt.

### Running Specific Test Categories

Catch2 allows users to execute tests based on their tags.

To run only sorting tests: unit_tests.exe "[sort]"


To run only data-loading tests: unit_tests.exe "[data]"

### Saving Test Results

To save test results to a text file, run: unit_tests.exe > test_results.txt 2>&1

This creates a file named `test_results.txt` containing the test output.

## Test Case Overview

The automated tests are designed to verify the correctness of Game Dreamer's primary components.

### Dataset Loading

Tests verify that:

- The Steam dataset loads successfully.
- Games contain valid IDs and names.
- Game metadata is properly loaded.
- Genres and categories are successfully retrieved.

### Sorting Algorithms

The project implements Merge Sort and Quick Sort to rank games by recommendation score.

Tests verify that:

- Games are sorted from highest to lowest score.
- Games with identical scores are sorted alphabetically.
- Empty vectors and single-game vectors are handled.
- Already sorted and reverse-sorted vectors are handled.
- Duplicate and negative scores are handled.
- All game information remains associated with the correct game after sorting.

### Recommendation System

Tests verify that:

- Recommendations are successfully generated.
- Different genre, category, and platform combinations are handled.
- Games matching the selected preferences receive appropriate rankings.
- Recommendation results contain valid game titles.

### User Interface Data

Tests verify that:

- Available genres are successfully loaded.
- Available categories are successfully loaded.
- Dropdown options contain valid entries.

## Project Structure

```text
Dream-Steam-A-team-DSA-Project-2-/
│
├── main.cpp
├── datasets.cpp
├── datasets.h
├── mergesort.cpp
├── mergesort.h
├── quicksort.cpp
├── quicksort.h
├── userinterface.cpp
├── userinterface.h
├── tests.cpp
├── CMakeLists.txt
│
├── datafiles/
│   └── all_applications.csv
│
├── assets/
│   └── mainbg.png
│
├── cmake-build-debug/
│   ├── Dream_Steam_A_team_DSA_Project_2_.exe
│   └── unit_tests.exe
│
└── README.md
```

The executable locations shown above are examples. Actual locations depend on the CMake generator and build configuration.

## Technologies Used

- **C++** — Primary programming language
- **CMake** — Build configuration
- **SFML** — Graphics and window management
- **TGUI** — Graphical user interface
- **Catch2** — Automated testing framework
- **Merge Sort** — Sorting algorithm
- **Quick Sort** — Sorting algorithm

## GitHub Repository

[Game Dreamer GitHub Repository](https://github.com/leahzabad/Dream-Steam-A-team-DSA-Project-2-)