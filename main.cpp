// ============================================================================
//  Array Tool – Random‑Number Utility Console (English version)
//  Author: Adrian Lesniak
//  Description: Generate, display, sort, save and load integer arrays with a
//               colourful ASCII menu. Includes exception‑safe file I/O, simple
//               logging, and cross‑platform ANSI colour handling.
// ============================================================================
//  * Menu Options *
//    1 – Generate new random array  (size + value range)
//    2 – Display current array      (fancy row of numbers)
//    3 – Sort array (asc/desc)      (std::sort)
//    4 – Save array to file         (array.txt)
//    5 – Load array from file       (array.txt)
//    6 – Exit program
// ---------------------------------------------------------------------------
//  After each action press <Enter> to return to the menu.
// ============================================================================

#include <iostream>
#include <vector>
#include <random>
#include <fstream>
#include <iomanip>
#include <chrono>
#include <ctime>
#include <exception>
#include <limits>
#include <algorithm>

#ifdef _WIN32
#  define NOMINMAX
#  include <windows.h>
   // fallback for older MinGW headers
#  ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
#     define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
#  endif
#endif

// --------------------------------------------------------
//  ANSI colour codes – bright variants
// --------------------------------------------------------
#define CLR_RESET   "\033[0m"
#define CLR_CYAN    "\033[96m"
#define CLR_YELLOW  "\033[93m"
#define CLR_MAGENTA "\033[95m"
#define CLR_GREEN   "\033[92m"

// --------------------------------------------------------
//  Logger – writes time‑stamped messages to app.log
// --------------------------------------------------------
class Logger {
    std::ofstream log;
public:
    explicit Logger(const std::string& file = "app.log") {
        log.open(file, std::ios::app);
        if (!log) std::cerr << "Cannot open log file!\n";
    }
    ~Logger() { if (log) log.close(); }

    template <typename T>
    void info(const T& msg) {
        if (!log) return;
        auto now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        std::tm tm{};
#ifdef _WIN32
        localtime_s(&tm, &now);
#else
        localtime_r(&now, &tm);
#endif
        log << std::put_time(&tm, "%F %T") << " | " << msg << '\n';
    }
};

Logger logger; // global instance (tiny app)

// --------------------------------------------------------
//  Utility: enable ANSI colours on Windows 10+ consoles
// --------------------------------------------------------
void enableColours() {
#ifdef _WIN32
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    if (h == INVALID_HANDLE_VALUE) return;
    DWORD mode = 0;
    if (!GetConsoleMode(h, &mode)) return;
    mode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(h, mode);
#endif
}

// --------------------------------------------------------
//  Array operations encapsulated in a class (business logic)
// --------------------------------------------------------
class IntArray {
    std::vector<int> data;
public:
    bool empty() const noexcept { return data.empty(); }
    std::size_t size() const noexcept { return data.size(); }
    const std::vector<int>& get() const noexcept { return data; }

    void generate(std::size_t n, int low, int high) {
        if (low > high) std::swap(low, high);
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> dist(low, high);
        data.resize(n);
        std::generate(data.begin(), data.end(), [&] { return dist(gen); });
        logger.info("Generated array of " + std::to_string(n) + " elements in range [" +
                    std::to_string(low) + ", " + std::to_string(high) + "]");
    }

    void sortAsc() {
        std::sort(data.begin(), data.end());
        logger.info("Array sorted ascending");
    }
    void sortDesc() {
        std::sort(data.begin(), data.end(), std::greater<>());
        logger.info("Array sorted descending");
    }

    void save(const std::string& file = "array.txt") const {
        std::ofstream out(file);
        if (!out) throw std::ios_base::failure("Cannot open file for writing");
        for (int v : data) out << v << '\n';
        logger.info("Saved array to " + file);
    }

    void load(const std::string& file = "array.txt") {
        std::ifstream in(file);
        if (!in) throw std::ios_base::failure("Cannot open file for reading");
        data.clear();
        int value;
        while (in >> value) data.push_back(value);
        logger.info("Loaded array of " + std::to_string(data.size()) + " elements from " + file);
    }
};

// --------------------------------------------------------
//  UI helpers
// --------------------------------------------------------
void clearScreen() {
#ifdef _WIN32
    std::system("cls");
#else
    std::system("clear");
#endif
}

void waitForKey() {
    std::cout << "\nPress <Enter> to return to menu...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

void printHeader() {
    std::cout << CLR_GREEN
              << " ========================================================\n"
              << " *          Adrian Lesniak  Array Tool Console          *\n"
              << " ========================================================\n"
              << " Generate, sort, save and load random integer arrays.\n\n"
              << CLR_RESET;
}

void printMenu() {
    std::cout << CLR_YELLOW
              << "******************* MENU *******************\n"
              << " 1  Generate new random array\n"
              << " 2  Display current array\n"
              << " 3  Sort array (ascending / descending)\n"
              << " 4  Save array to file\n"
              << " 5  Load array from file\n"
              << " 6  Exit\n"
              << "*********************************************\n"
              << CLR_RESET;
}

void displayArray(const IntArray& arr) {
    if (arr.empty()) {
        std::cout << CLR_MAGENTA << "\nArray is empty.\n" << CLR_RESET;
        return;
    }
    std::cout << CLR_CYAN << "\n[ ";
    std::size_t count = 0;
    for (int v : arr.get()) {
        std::cout << std::setw(5) << v << ' ';
        if (++count % 10 == 0) std::cout << "\n  ";
    }
    std::cout << "]" << CLR_RESET << "\n";
}

// --------------------------------------------------------
//  Main loop
// --------------------------------------------------------
int main() {
    enableColours();
    IntArray arr;

    try {
        char opt{};
        do {
            clearScreen();
            printHeader();
            printMenu();
            std::cout << "Choose an option > ";
            std::cin >> opt;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            switch (opt) {
                case '1': { // generate
                    std::size_t n;
                    int low, high;
                    std::cout << "\nHow many numbers? ";
                    std::cin >> n;
                    std::cout << "Lower bound: ";
                    std::cin >> low;
                    std::cout << "Upper bound: ";
                    std::cin >> high;
                    arr.generate(n, low, high);
                    std::cout << CLR_GREEN << "\nArray generated successfully." << CLR_RESET;
                    waitForKey();
                    break;
                }
                case '2': { // display
                    displayArray(arr);
                    waitForKey();
                    break;
                }
                case '3': { // sort
                    if (arr.empty()) {
                        std::cout << CLR_MAGENTA << "\nArray is empty." << CLR_RESET;
                    } else {
                        char s;
                        std::cout << "\nSort (a)sc or (d)esc? ";
                        std::cin >> s;
                        if (s == 'a' || s == 'A') arr.sortAsc();
                        else if (s == 'd' || s == 'D') arr.sortDesc();
                        std::cout << CLR_GREEN << "\nArray sorted." << CLR_RESET;
                    }
                    waitForKey();
                    break;
                }
                case '4': { // save
                    try {
                        arr.save();
                        std::cout << CLR_GREEN << "\nSaved to array.txt." << CLR_RESET;
                    } catch (const std::exception& ex) {
                        std::cerr << "Error: " << ex.what() << '\n';
                        logger.info(std::string("Save error: ") + ex.what());
                    }
                    waitForKey();
                    break;
                }
                case '5': { // load
                    try {
                        arr.load();
                        std::cout << CLR_GREEN << "\nLoaded from array.txt." << CLR_RESET;
                    } catch (const std::exception& ex) {
                        std::cerr << "Error: " << ex.what() << '\n';
                        logger.info(std::string("Load error: ") + ex.what());
                    }
                    waitForKey();
                    break;
                }
                case '6':
                    std::cout << "\nExiting... Goodbye!\n";
                    break;
                default:
                    std::cout << "Invalid choice.";
                    waitForKey();
            }
        } while (opt != '6');
    }
    catch (const std::exception& ex) {
        std::cerr << "Fatal error: " << ex.what() << '\n';
        logger.info(std::string("Fatal: ") + ex.what());
    }
    return 0;
}
