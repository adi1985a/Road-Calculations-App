# 🚗💨 RoadTrip Calculator Pro 🛣️
_A C++ console application for essential road travel calculations, featuring a colorful UI, input validation, and error logging._

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![C++](https://img.shields.io/badge/Language-C%2B%2B-blue.svg)](https://isocpp.org/)
[![Platform: Windows](https://img.shields.io/badge/Platform-Windows-lightgrey.svg)](https://www.microsoft.com/windows)

## 📝 Project Description

**RoadTrip Calculator Pro** is a handy C++ console application designed to assist with common road travel calculations. Users can easily determine essential parameters such as **travel time**, **minimum required speed**, or **total road length** based on provided inputs. The application features a user-friendly, colorful interface for better interaction, robust input validation to ensure data integrity (accepting only positive numerical values), and an error logging mechanism that records any issues to `error_log.txt`. It's a practical tool for quick estimations related to journey planning.

![Demo GIF](screenshots/1.gif)

## ✨ Key Features

*   ⏱️ **Calculate Travel Time**: Determine the estimated time a journey will take based on a given average speed and total distance.
*    speedometer**Calculate Minimum Speed**: Find out the minimum average speed required to cover a certain distance within a specified time frame.
*   ↔️ **Calculate Road Length (Distance)**: Estimate the total distance of a journey based on the average speed and travel time.
*   📄 **Error Logging**: Logs operational errors (e.g., invalid input, calculation issues) with timestamps to `error_log.txt` for review.
*   🌈 **Colorful Console Interface**: Enhanced user experience with colored text for menus, prompts, and results, leveraging a `colors.h` file (Windows-specific for full effect).
*   ✔️ **Input Validation**: Strictly accepts only positive numerical values for speed, distance, and time inputs, prompting the user for re-entry if invalid data is provided.
*   📋 **Menu-Driven Operation**: Simple and intuitive menu for selecting the desired calculation.

## 🖼️ Screenshots

_Screenshots showcasing the main menu, input prompts for each calculation type, and example results._

<p align="center">
  <img src="screenshots\1.jpg" width="300"/>
  <img src="screenshots\2.jpg" width="300"/>
  <img src="screenshots\3.jpg" width="300"/>
  <img src="screenshots\4.jpg" width="300"/>
  <img src="screenshots\5.jpg" width="300"/>
</p>


## ⚙️ System Requirements

*   **Operating System**: Windows is recommended for full color functionality as the color system likely relies on Windows-specific console manipulation (e.g., via `SetConsoleTextAttribute` which would be abstracted in `colors.h`). It might run on other OSes without color if `colors.h` provides fallbacks.
*   **C++ Compiler**: Any modern C++ compiler that supports C++11 or newer (e.g., g++, MinGW, Clang, MSVC).
*   📄 **`colors.h` Header File (User-Provided)**: This project **requires** a header file named `colors.h`. **This file is not included in the repository and must be created by the user.** It should define color constants and potentially a function to set console colors. See the "Installation and Running" section for more details.

## 🛠️ Installation and Running

1.  **Clone the Repository**:
    ```bash
    git clone <repository-url>
    ```
    (Replace `<repository-url>` with the actual URL of your repository)

2.  **Navigate to the Project Directory**:
    ```bash
    cd <repository-directory>
    ```
    (Replace `<repository-directory>` with the name of the cloned folder)

3.  **Create `colors.h`**:
    Before compiling, you **must** create a file named `colors.h` in the project's root directory. This file should define color constants and a function to apply them. Here's an example:
    ```cpp
    #ifndef COLORS_H
    #define COLORS_H

    #ifdef _WIN32
    #include <windows.h>
    #endif

    // Define color constants (these are just examples, match them to your program)
    // For Windows, these could be arguments to SetConsoleTextAttribute
    // FOREGROUND_RED | FOREGROUND_INTENSITY, etc.
    // Or simply numbers if you have a setColor function that maps them.
    const int COL_DEFAULT = 7; // Standard white on black
    const int COL_RED = 12;    // Light Red
    const int COL_GREEN = 10;  // Light Green
    const int COL_CYAN = 11;   // Light Cyan
    const int COL_YELLOW = 14; // Yellow
    // Add other colors as needed

    // Function to set console text color
    // This is a simplified example; your actual implementation might differ
    inline void applyConsoleColor(int colorCode) {
    #ifdef _WIN32
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, colorCode);
    #else
        // Basic ANSI escape codes for other terminals (limited support)
        // This part is optional and depends on how cross-platform you want it to be
        // without full ncurses or similar.
        switch (colorCode) {
            // case COL_RED: std::cout << "\033[1;31m"; break; // Bright Red
            // ... and so on for other colors
            // default: std::cout << "\033[0m"; break; // Reset
        }
    #endif
    }

    // You might also have utility functions from previous projects here like:
    // void drawLine(char c = '=', int length = 40);
    // void logMessage(const std::string& message, const std::string& logFilePath = "error_log.txt");
    // void waitForKeyPress(const std::string& message = "Press any key to continue...");


    #endif // COLORS_H
    ```
    *Adjust the constants and the `applyConsoleColor` function (or however you manage colors) to match your `main.cpp`'s usage. You might also have a corresponding `colors.cpp` if the functions are more complex.*

4.  **Compile the Program**:
    Open a terminal (like Command Prompt or PowerShell) in the project directory.
    **Example using g++ (MinGW):**
    ```bash
    g++ main.cpp -o road_calculations.exe -static-libgcc -static-libstdc++
    ```
    *(This assumes `colors.h` is primarily for constants and inline functions, or that any separate `.cpp` for `colors.h` is also included in the compilation if needed).*

5.  **Run the Application**:
    After successful compilation, execute the generated program:
    ```bash
    ./road_calculations.exe
    ```
    or simply in CMD:
    ```bash
    road_calculations.exe
    ```

## ▶️ How to Use

Upon launching the application, you will be presented with a main menu. Enter the number corresponding to your desired calculation:

1.  **Calculate travel time**:
    *   Prompts you to enter the **distance** (e.g., in km or miles) and the average **speed** (e.g., in km/h or mph).
    *   Displays the calculated travel time (e.g., in hours and minutes).
2.  **Calculate minimum speed**:
    *   Prompts you to enter the **distance** and the desired **travel time** (e.g., in hours).
    *   Displays the minimum average speed required.
3.  **Calculate road length**:
    *   Prompts you to enter the average **speed** and the **travel time**.
    *   Displays the calculated total distance.
4.  **Exit**:
    *   Terminates the application.

*All inputs (speed, distance, time) must be positive numbers. The program will validate this and prompt for re-entry if invalid data is given. Errors are logged to `error_log.txt`.*

## 💡 Technical Details & Program Logic

*   **Core Formulas**:
    *   Time = Distance / Speed
    *   Speed = Distance / Time
    *   Distance = Speed × Time
*   **Input Validation**: The program rigorously checks that all user-provided numerical inputs (distance, speed, time) are positive values. Non-positive or non-numeric inputs trigger an error message and a re-prompt.
*   **`colors.h`**: This crucial user-provided header file is responsible for defining color constants (e.g., `RED`, `CYAN`, `GREEN`) and likely includes a function (e.g., `applyConsoleColor` or `setColor`) that uses Windows API calls (`SetConsoleTextAttribute`) to change the text color in the console.
*   **Error Logging**: When an error occurs (e.g., invalid user input that persists, or potential calculation errors though less likely with basic arithmetic), a descriptive message along with a timestamp is written to `error_log.txt`.
*   **Console I/O**: Standard C++ `iostream` is used for interacting with the user. Windows-specific console functions might be used for clearing the screen or handling keypresses if implemented beyond basic color changes.

## 🤝 Contributing

Contributions to **RoadTrip Calculator Pro** are welcome! If you have ideas for additional calculations (e.g., fuel consumption, ETA with breaks), UI improvements, or enhanced unit conversions:

1.  Fork the repository.
2.  Create a new branch for your feature: `git checkout -b feature/your-travel-enhancement`
3.  Implement your changes and commit them: `git commit -m "Feature: Add your travel enhancement"`
4.  Push your changes to your branch: `git push origin feature/your-travel-enhancement`
5.  Open a Pull Request.

Please ensure your code is well-commented and maintains the existing style.

## ✍️ Author

**Adrian Lesniak**
_C++ Developer & Utility Application Enthusiast_

## 📃 License

This project is licensed under the **MIT License**.
The full text of the license is available at: [https://opensource.org/licenses/MIT](https://opensource.org/licenses/MIT)

---
🗺️ _Plan your journeys with precision and ease!_
