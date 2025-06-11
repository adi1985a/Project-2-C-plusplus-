# 🎲🔢 Array Tool Console: C++ Random Integer Array Utility

_A C++ console application for generating, displaying, sorting, saving, and loading integer arrays with a colorful, user-friendly menu interface._

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![C++](https://img.shields.io/badge/Language-C%2B%2B-blue.svg)](https://isocpp.org/)
[![Platform: Cross-platform](https://img.shields.io/badge/Platform-Cross--platform-lightgrey.svg)]()

## 📋 Table of Contents
1. [Overview](#-overview)
2. [Key Features](#-key-features)
3. [Screenshots (Conceptual Output)](#-screenshots-conceptual-output)
4. [System Requirements](#-system-requirements)
5. [Installation and Setup](#️-installation-and-setup)
6. [Usage Guide](#️-usage-guide)
7. [File Structure](#-file-structure)
8. [Technical Notes](#-technical-notes)
9. [Contributing](#-contributing)
10. [License](#-license)
11. [Contact](#-contact)

## 📄 Overview

**Array Tool Console**, developed by Adrian Lesniak, is a modern C++ console application for working with integer arrays. The program allows users to generate arrays of random integers within a specified range, display them in a formatted style, sort them (ascending or descending), and save/load arrays to/from a file. It features a colorful ASCII menu, robust exception-safe file I/O, simple logging, and cross-platform ANSI color support.

![Demo GIF](screenshots/1.gif)

## ✨ Key Features

*   🎲 **Random Array Generation**:
    *   Generate arrays of any size with random integers in a user-defined range.
    *   Uses modern C++ `<random>` for high-quality randomness.
*   🖥️ **Array Display**:
    *   Nicely formatted, colorized output for easy reading.
*   🔃 **Sorting**:
    *   Sort the array in ascending or descending order.
*   💾 **File Operations**:
    *   Save the current array to a file.
    *   Load an array from a file.
    *   Exception-safe file I/O with error messages and logging.
*   🎨 **Colorful Menu**:
    *   Cross-platform ANSI color support for a pleasant user experience.
*   📝 **Logging**:
    *   All actions are logged with timestamps to `app.log` for easy troubleshooting.

## 🖼️ Screenshots (Conceptual Output)

The program produces direct, colorized console output.

<p align="center">
  <img src="screenshots/1.jpg" width="300"/>
  <img src="screenshots/2.jpg" width="300"/>
  <img src="screenshots/3.jpg" width="300"/>
  <img src="screenshots/4.jpg" width="300"/>
  <img src="screenshots/5.jpg" width="300"/>
  <img src="screenshots/6.jpg" width="300"/>
  <img src="screenshots/7.jpg" width="300"/>
  <img src="screenshots/8.jpg" width="300"/>
</p>

## ⚙️ System Requirements

*   **Operating System**: Windows, Linux, or macOS.
*   **C++ Compiler**: Any modern C++ compiler (g++, clang++, MSVC). C++11 or later required.
*   **Standard C++ Libraries**: `<iostream>`, `<vector>`, `<random>`, `<fstream>`, `<iomanip>`, `<chrono>`, `<ctime>`, `<exception>`, `<limits>`, `<algorithm>`.

## 🛠️ Installation and Setup

1.  **Clone the Repository**:
    ```bash
    git clone <repository-url>
    cd <repository-directory>
    ```
2.  **Build the Program**:
    ```bash
    g++ main.cpp -o array_tool -std=c++11
    ```
    *(On Windows with MinGW, you may add `-static-libgcc -static-libstdc++` for a standalone executable.)*
3.  **Run the Program**:
    *   On Windows: `.\array_tool.exe`
    *   On Linux/macOS: `./array_tool`

## 💡 Usage Guide

1.  Run the program.
2.  Use the menu to:
    *   Generate a new random array (specify size and value range).
    *   Display the current array.
    *   Sort the array (ascending or descending).
    *   Save the array to a file.
    *   Load an array from a file.
    *   Exit the program.
3.  Follow on-screen prompts. All actions are logged to [app.log](http://_vscodecontentref_/0).

## 🗂️ File Structure

*   [main.cpp](http://_vscodecontentref_/1): Main C++ source file with all logic.
*   `README.md`: This documentation file.
*   [app.log](http://_vscodecontentref_/2): Log file (created at runtime).
*   [array.txt](http://_vscodecontentref_/3): Default file for saving/loading arrays.

## 📝 Technical Notes

*   Uses modern C++11 features and `<random>` for robust random number generation.
*   Exception handling for file I/O.
*   Cross-platform color support (Windows 10+ and UNIX-like systems).
*   No external dependencies.

## 🤝 Contributing

Contributions are welcome! Feel free to fork, open issues, or submit pull requests for improvements such as:
*   Enhanced input validation.
*   Additional array operations or statistics.
*   UI/UX improvements.

## 📃 License

This project is licensed under the **MIT License**.  
See the LICENSE file for details.

## 📧 Contact

Created by **Adrian Lesniak**.  
For questions or feedback, please open an issue on the GitHub repository.

---

✨ _Generating, sorting, and managing random arrays with style!_
