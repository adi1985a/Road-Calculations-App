# Road Calculations App

## Description
A C++ console application for calculating road travel parameters including travel time, minimum speed, and road length based on user inputs. Features a colorful interface, input validation, and error logging. Created by Adrian Lesniak.

## Features
- Calculate travel time (using speed and distance)
- Calculate minimum speed (using time and distance)
- Calculate road length (using speed and time)
- Log errors to `error_log.txt`
- Colorful console interface

## Requirements
- C++ compiler (e.g., g++)
- Header file: `colors.h` (not provided)
- Windows OS for full color functionality (via `colors.h`)

## Installation
1. Clone the repository:
   ```bash
   git clone <repository-url>
   ```
2. Ensure `colors.h` is in the project directory.
3. Compile the program:
   ```bash
   g++ main.cpp -o road_calculations
   ```

## Usage
1. Run the program:
   ```bash
   ./road_calculations
   ```
2. Choose options 1-4 from the menu:
   - 1: Calculate travel time
   - 2: Calculate minimum speed
   - 3: Calculate road length
   - 4: Exit
3. Enter valid positive numbers for inputs (speed, distance, or time).

## Notes
- Requires `colors.h` for console color constants (e.g., `RED`, `CYAN`, `GREEN`).
- Errors are logged to `error_log.txt` with timestamps.
- Input validation ensures only positive numbers are accepted.

## Author
Adrian Lesniak

## License
MIT License