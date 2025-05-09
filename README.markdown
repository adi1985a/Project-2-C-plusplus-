# Random Array Generator

## Overview
This C++ program generates an array of 10 random integers within a user-defined range [p, k]. It includes functions `losuj` to fill the array with random values and `wyswietl` to display the array. The user inputs the range bounds, and the program outputs the generated array.

## Features
- **Random Array Generation**:
  - `losuj` function: Fills an array with random integers in the range [p, k].
  - Uses `rand()` seeded with current time for randomness.
- **Array Display**:
  - `wyswietl` function: Prints array elements with tab separation.
- **User Input**:
  - Prompts for range bounds `p` (lower) and `k` (upper).
- **Main Program**:
  - Initializes a fixed-size array (10 elements).
  - Generates and displays the array based on user input.

## Requirements
- C++ compiler (e.g., g++, clang++)
- Standard C++ libraries: `<iostream>`, `<ctime>`
- Operating system: Any supporting a C++ compiler (e.g., Windows, Linux, macOS)

## Setup
1. Clone the repository:
   ```bash
   git clone <repository-url>
   cd <repository-directory>
   ```
2. Save the corrected code as `random_array.cpp`.
3. Compile the program:
   ```bash
   g++ random_array.cpp -o random_array
   ```
4. Run the program:
   ```bash
   ./random_array
   ```

## Usage
1. Compile and run the program using the steps above.
2. **Input**:
   - Enter the lower bound `p` when prompted.
   - Enter the upper bound `k` when prompted.
3. **Output**:
   - Displays the generated array of 10 random integers in the range [p, k], separated by tabs.
4. **Actions**:
   - Observe the console output for the random array.
   - Modify `N` in the code to change the array size or adjust the range inputs during runtime.

## File Structure
- `random_array.cpp`: Main C++ source file with program logic.
- `README.md`: This file, providing project documentation.

## Notes
- The program uses Polish prompts (e.g., "Podaj przedzial p") but is functional in any C++ environment.
- Corrected the random number formula to `rand() % (k - p + 1) + p` for accurate range [p, k].
- Fixed syntax errors: missing `const int N`, incorrect `wyswietl` parameter, and typo in loop variable (`ubt` to `int`).
- No input validation; assumes valid integers for `p` and `k` (add checks for robustness).
- Extend by adding multiple arrays (e.g., `Y`, `Q` as in original code) or sorting/display options.
- No external dependencies; uses only standard C++ libraries.

## Contributing
Contributions are welcome! To contribute:
1. Fork the repository.
2. Create a new branch (`git checkout -b feature-branch`).
3. Make changes and commit (`git commit -m "Add feature"`).
4. Push to the branch (`git push origin feature-branch`).
5. Open a pull request.

## License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Contact
For questions or feedback, open an issue on GitHub or contact the repository owner.