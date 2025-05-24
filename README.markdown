# 🎲🔢 SimpleRand ArrayGen: C++ Random Integer Array Generator 🇵🇱
_A C++ console program that generates and displays a fixed-size array of 10 random integers within a user-specified range [p, k]._

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![C++](https://img.shields.io/badge/Language-C%2B%2B-blue.svg)](https://isocpp.org/)
[![Platform: Cross-platform](https://img.shields.io/badge/Platform-Cross--platform-lightgrey.svg)]()

## 📋 Table of Contents
1.  [Overview](#-overview)
2.  [Key Features](#-key-features)
3.  [Screenshots (Conceptual Output)](#-screenshots-conceptual-output)
4.  [System Requirements](#-system-requirements)
5.  [Installation and Setup](#️-installation-and-setup)
6.  [Usage Guide](#️-usage-guide)
7.  [File Structure](#-file-structure)
8.  [Technical Notes](#-technical-notes)
9.  [Contributing](#-contributing)
10. [License](#-license)
11. [Contact](#-contact)

## 📄 Overview

**SimpleRand ArrayGen**, developed by Adrian Lesniak, is a concise C++ console application designed to generate an array of 10 random integers. Users are prompted to define a lower bound `p` and an upper bound `k` for the range of these random numbers. The program then populates the array using the `losuj` function and displays its contents using the `wyswietl` function. It features basic random number generation seeded by the current time. While the prompts are in Polish (e.g., "Podaj przedzial p"), the core logic is standard C++.

## ✨ Key Features

*   🎲 **Random Array Generation (`losuj` function)**:
    *   Fills a fixed-size array (10 elements) with pseudo-random integers.
    *   The numbers generated are within the inclusive range `[p, k]` specified by the user.
    *   Uses `rand()` for random number generation, seeded with `srand(time(NULL))` once at the start for variability.
*   🖥️ **Array Display (`wyswietl` function)**:
    *   Prints the elements of the generated array to the console.
    *   Elements are typically separated by tabs for clear readability.
*   ⌨️ **User Input for Range**:
    *   Prompts the user to enter the lower bound `p` and the upper bound `k` for the random number range.
*   ⚙️ **Simple Main Program Flow**:
    *   Initializes an array (e.g., `int T[N]` where `N` is 10).
    *   Collects range inputs `p` and `k` from the user.
    *   Calls `losuj` to populate the array.
    *   Calls `wyswietl` to display the array.
    *   The program then terminates.

## 🖼️ Screenshots (Conceptual Output)

The program produces direct console output.

**Example Console Interaction & Output:**
*Podaj przedzial p: 5
Podaj przedzial k: 15
Wygenerowana tablica:
12 7 15 5 9 11 6 14 8 10*

*(The Polish prompts "Podaj przedzial p/k" and "Wygenerowana tablica:" are part of the described program's output.)*

## ⚙️ System Requirements

*   **Operating System**: Any OS supporting a standard C++ compiler (e.g., Windows, Linux, macOS).
*   **C++ Compiler**: A C++ compiler (e.g., g++, clang++, MSVC). C++11 or later is good practice for `time(NULL)` with `srand`.
*   **Standard C++ Libraries**: `<iostream>` (for console I/O), `<ctime>` (for `time` to seed `srand`), `<cstdlib>` (for `rand`, `srand`).

## 🛠️ Installation and Setup

1.  **Clone the Repository (if applicable)**:
    ```bash
    git clone <repository-url>
    cd <repository-directory>
    ```
    *(Replace `<repository-url>` and `<repository-directory>` if this code is part of a larger repository).*

2.  **Save Main Code**:
    Ensure your C++ source code (containing the `losuj` and `wyswietl` functions, and the `main` function) is saved as `random_array.cpp` (or your chosen file name) in your project directory. The description notes that corrections were made (e.g., defining `const int N`, correct `wyswietl` parameter, loop variable type), so ensure these are incorporated.

3.  **Compile the Program**:
    Open a terminal (Command Prompt, PowerShell, Bash, etc.) in the project directory.
    **Example using g++:**
    ```bash
    g++ random_array.cpp -o random_array -std=c++11
    ```
    *(Add `-static-libgcc -static-libstdc++` on Windows with MinGW if desired for standalone executables. Add optimization flags like `-O2` for release builds if needed).*

4.  **Run the Program**:
    *   On Windows: `.\random_array.exe` or `random_array.exe`
    *   On Linux/macOS: `./random_array` (ensure execute permissions: `chmod +x random_array`)

## 💡 Usage Guide

1.  Compile `random_array.cpp` as detailed in the "Installation and Setup" section.
2.  Run the compiled executable (`random_array` or `random_array.exe`).
3.  **Input**:
    *   The program will first prompt you to "Podaj przedzial p: " (Enter range p:). Type the integer for the lower bound of your desired random number range and press Enter.
    *   Next, it will prompt "Podaj przedzial k: " (Enter range k:). Type the integer for the upper bound and press Enter.
4.  **Output**:
    *   The program will then display "Wygenerowana tablica:" (Generated array:) followed by 10 random integers.
    *   These integers will be within the inclusive range `[p, k]` you specified, separated by tabs.
5.  The program terminates after displaying the array. To generate a new array with a different range, you need to run the program again.

## 🗂️ File Structure

*   `random_array.cpp`: The main (and likely only) C++ source file containing the `losuj` and `wyswietl` functions, and the `main()` function.
*   `README.md`: This documentation file.

*(No external data files, log files, or user-provided header files are indicated for this specific program as described.)*

## 📝 Technical Notes

*   **Polish Prompts**: The program uses Polish language prompts for user input (e.g., "Podaj przedzial p"). The core functionality is language-agnostic C++.
*   **Random Number Generation**:
    *   Uses `srand(time(NULL));` (or `srand(static_cast<unsigned int>(time(0)));`) called once at the beginning of `main()` to seed the pseudo-random number generator.
    *   The formula `rand() % (k - p + 1) + p` is used within `losuj` to generate random numbers within the inclusive range `[p, k]`.
*   **Fixed Array Size**: The array size is fixed at 10 elements (e.g., via `const int N = 10;`). To change this, the constant `N` in the code needs to be modified and the program recompiled.
*   **Input Validation (Lacking)**: The description notes "No input validation; assumes valid integers for p and k." For robustness, checks should be added to ensure:
    *   `p` and `k` are indeed integers.
    *   `k` is greater than or equal to `p`.
*   **Potential Enhancements**:
    *   Implement input validation.
    *   Allow the user to specify the array size at runtime.
    *   Add options for further operations on the generated array (e.g., sorting, finding min/max, calculating sum/average).
    *   Use C++11 `<random>` library for more advanced and better-quality random number generation.

## 🤝 Contributing

Contributions to **SimpleRand ArrayGen** are welcome, especially if they aim to:

*   Implement robust input validation for `p` and `k`.
*   Allow dynamic array sizing.
*   Add more array operations or statistical functions.
*   Transition to using the C++11 `<random>` library.

1.  Fork the repository.
2.  Create a new branch for your feature (`git checkout -b feature/ArrayEnhancements`).
3.  Make your changes and commit them (`git commit -m 'Feature: Add input validation'`).
4.  Push to the branch (`git push origin feature/ArrayEnhancements`).
5.  Open a Pull Request.

Please ensure your code is well-commented and adheres to good C++ practices.

## 📃 License

This project is licensed under the **MIT License**.
(If you have a `LICENSE` file in your repository, refer to it: `See the LICENSE file for details.`)

## 📧 Contact

Created by **Adrian Lesniak**.
For questions, feedback, or issues, please open an issue on the GitHub repository or contact the repository owner.

---
✨ _Generating random numbers, one array at a time!_
