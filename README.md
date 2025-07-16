# readVar (C++) - Simple C++ Input Validation Library

`readVar` is a lightweight C++ library designed to simplify reading and validating user input from the console. It provides functions to read various data types (`int`, `string`, `double`, `float`, `bool`) with customizable prompts, reprompts, and range constraints. This library is ideal for console-based applications where robust input handling is needed without built-in detailed error messaging—users are expected to define their own feedback through reprompts.

## Features
- **Standard Input**: Uses `std::cin` with `getline` for reliable input handling, including spaces.
- **Flexible Overloads**: Multiple function variants allow control over minimum/maximum values and prompts.
- **Minimal Feedback**: Reprompts are user-configurable, keeping the library lightweight and adaptable.
- **Data Types Supported**: Handles integers, strings, doubles, floats, and booleans with validation.
- **Robust Error Handling**: Catches invalid inputs (e.g., non-numeric strings for numbers) and loops until valid input is provided.
- **Boolean Flexibility**: Accepts case-insensitive `"true"`, `"false"`, `"yes"`, `"y"`, `"no"`, or `"n"` for boolean input.

## Requirements
- C++11 or higher (uses `stoi`, `stod`, `stof`, and `numeric_limits`).
- No external dependencies.

## Installation
1. Download the `ReadVar.h` and `ReadVar.cpp` files from this [repository](https://github.com/qeqeqecode533/read-variable-cpp).
2. Place them in your C++ project directory (e.g., `src/` for CMake projects).
3. Include the header in your code:
   ```cpp
   #include "ReadVar.h"
   ```
4. Compile both files with your program. For build tools like CMake, add them to your source files:
   ```cmake
   add_executable(my_program main.cpp ReadVar.cpp)
   ```
5. If using a custom namespace or directory, adjust the include path and namespace accordingly.

## Usage
The library provides functions for reading input. Each function requires a `prompt` (initial message) and a `reprompt` (message shown after invalid input). If `reprompt` is empty, it defaults to `prompt`. Users must configure reprompts to provide context-specific feedback.

### Functions
Below are the primary functions and their overloads. All functions loop until valid input is received.

#### `readLine`
Reads a non-empty string.
- **Signature**: `std::string readLine(const std::string &prompt, std::string reprompt)`
- **Overloads**:
  - `readLine(const std::string &prompt)` - Same prompt/reprompt (reprompt defaults to prompt).

#### `readInt`
Reads an integer within a specified range.
- **Signature**: `int readInt(int min, int max, const std::string &prompt, std::string reprompt)`
- **Overloads**:
  - `readInt(int min, const std::string &prompt, const std::string &reprompt)` - Minimum value, max is `std::numeric_limits<int>::max()`.
  - `readInt(const std::string &prompt, const std::string &reprompt)` - Full integer range (`std::numeric_limits<int>::lowest()` to `max()`).

#### `readDouble`
Reads a double within a specified range.
- **Signature**: `double readDouble(double min, double max, const std::string &prompt, std::string reprompt)`
- **Overloads**: Similar to `readInt`, with `std::numeric_limits<double>::lowest()` and `max()` defaults.

#### `readFloat`
Reads a float within a specified range.
- **Signature**: `float readFloat(float min, float max, const std::string &prompt, std::string reprompt)`
- **Overloads**: Similar to `readInt`, with `std::numeric_limits<float>::lowest()` and `max()` defaults.

#### `readBool`
Reads a boolean, accepting case-insensitive `"true"`, `"false"`, `"yes"`, `"y"`, `"no"`, or `"n"`.
- **Signature**: `bool readBool(const std::string &prompt, std::string reprompt)`
- **Overloads**:
  - `readBool(const std::string &prompt)` - Same prompt/reprompt (reprompt defaults to prompt).

## Examples

### Reading an Integer with Range
```cpp
#include "ReadVar.h"
#include <iostream>

int main() {
    int age = readInt(1, 100, "Enter your age (1-100): ", "Invalid input, enter a number between 1 and 100: ");
    std::cout << "Your age is: " << age << std::endl;
    return 0;
}
```
- **Behavior**: Prompts for an age between 1 and 100. If the user enters a non-integer or number outside the range, it displays the custom reprompt.

### Reading a String
```cpp
std::string name = readLine("What's your name? ", "Name cannot be empty, try again: ");
std::cout << "Hello, " << name << "!" << std::endl;
```
- **Behavior**: Ensures a non-empty name is entered, using the reprompt for empty inputs.

### Reading a Boolean
```cpp
bool likesCoffee = readBool("Do you like coffee? (true/false/yes/no): ", "Please enter 'true', 'false', 'yes', 'y', 'no', or 'n': ");
std::cout << "Likes coffee: " << (likesCoffee ? "true" : "false") << std::endl;
```
- **Behavior**: Accepts case-insensitive `"true"`, `"false"`, `"yes"`, `"y"`, `"no"`, or `"n"`, reprompting otherwise.

## Notes
- **Reprompt Customization**: The library does not provide detailed error messages (e.g., "Not a number" or "Out of range"). Users must include specific instructions in the `reprompt` parameter to guide the user (e.g., "Enter a number between 0 and 10: ").
- **Input Validation**: Methods reject invalid formats (e.g., non-numeric input for numbers, invalid boolean inputs) and loop until valid input is provided.
- **Boolean Input**: Unlike some input libraries, `readBool` supports multiple formats (`"true"`, `"false"`, `"yes"`, `"y"`, `"no"`, `"n"`) for flexibility.
- **Thread Safety**: The library uses `std::cin`, which is thread-safe in standard C++ implementations, but ensure proper synchronization in multi-threaded applications.
- **No Resource Cleanup**: Unlike some languages, no explicit cleanup is needed for `std::cin`, as it is managed by the C++ runtime.

## Contributing
Contributions are welcome! To contribute:
1. Fork the repository.
2. Create a new branch for your feature or bug fix.
3. Follow standard C++ coding conventions (e.g., consistent indentation, clear variable names, avoid `using namespace std;` in headers).
4. Submit a pull request with a clear description of your changes.
5. For bugs or feature requests, open an issue with detailed information.

## License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details. Use at your own risk—no warranty is provided.

---
