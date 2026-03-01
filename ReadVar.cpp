#include "readvar.h"
#include <iostream>
#include <limits>
#include <string>
#include <stdexcept>
#include <algorithm>
#include <cctype>

using ll = long long;
namespace readvar {
void ptl(const std::string& text) {
    std::cout << text << std::endl;
}

void ptl() {
    std::cout << std::endl;
}

void pt(const std::string& text) {
    std::cout << text;
}

int readInt(int min, int max, const std::string& prompt, const std::string& reprompt) {
    if (min > max) {
        throw std::invalid_argument("Minimum value cannot be greater than maximum value.");
    }
    std::string line;
    int value;
    bool first = true;
    while (true) {
        pt(first ? prompt : reprompt);
        std::getline(std::cin, line);
        size_t idx;
        try {
            value = std::stoi(line, &idx);
            if (idx == line.length() && value >= min && value <= max) {
                return value;
            }
        } catch (const std::invalid_argument &e) {
            // invalid input, continue to reprompt
        } catch (const std::out_of_range &e) {
            // input is out of range for int, continue to reprompt
        }
        first = false;
    }
}
int readInt(int min, const std::string& prompt, const std::string& reprompt) {
    return readInt(min, std::numeric_limits<int>::max(), prompt, reprompt);
}
int readInt(const std::string& prompt, const std::string& reprompt) {
    return readInt(std::numeric_limits<int>::min(), std::numeric_limits<int>::max(), prompt, reprompt);
}
int readInt(const std::string& prompt) {
    return readInt(std::numeric_limits<int>::min(), std::numeric_limits<int>::max(), prompt, prompt);
}
int readInt() {
    return readInt(std::numeric_limits<int>::min(), std::numeric_limits<int>::max(), "", "");
}
ll readLongLong(ll min, ll max, const std::string& prompt, const std::string& reprompt) {
    if (min > max) {
        throw std::invalid_argument("Minimum value cannot be greater than maximum value.");
    }
    std::string line;
    ll value;
    bool first = true;
    while (true) {
        pt(first ? prompt : reprompt);
        std::getline(std::cin, line);
        size_t idx;
        try {
            value = std::stoll(line, &idx);
            if (idx == line.length() && value >= min && value <= max) {
                return value;
            }
        } catch (const std::invalid_argument &e) {
            // invalid input, continue to reprompt
        } catch (const std::out_of_range &e) {
            // input is out of range for long long, continue to reprompt
        }
        first = false;
    }
}
ll readLongLong(ll min, const std::string& prompt, const std::string& reprompt) {
    return readLongLong(min, std::numeric_limits<ll>::max(), prompt, reprompt);
}
ll readLongLong(const std::string& prompt, const std::string& reprompt) {
    return readLongLong(std::numeric_limits<ll>::min(), std::numeric_limits<ll>::max(), prompt, reprompt);
}
ll readLongLong(const std::string& prompt) {
    return readLongLong(std::numeric_limits<ll>::min(), std::numeric_limits<ll>::max(), prompt, prompt);
}
ll readLongLong() {
    return readLongLong(std::numeric_limits<ll>::min(), std::numeric_limits<ll>::max(), "", "");
}
float readFloat(float min, float max, const std::string& prompt, const std::string& reprompt) {
    if (min > max) {
        throw std::invalid_argument("Minimum value cannot be greater than maximum value.");
    }
    std::string line;
    float value;
    bool first = true;
    while (true) {
        pt(first ? prompt : reprompt);
        std::getline(std::cin, line);
        try {
            value = std::stof(line);
            if (value >= min && value <= max) {
                return value;
            }
        } catch (const std::invalid_argument &e) {
            // invalid input, continue to reprompt
        } catch (const std::out_of_range &e) {
            // input is out of range for float, continue to reprompt
        }
        first = false;
    }
}
float readFloat(float min, const std::string& prompt, const std::string& reprompt) {
    return readFloat(min, std::numeric_limits<float>::max(), prompt, reprompt);
}
float readFloat(const std::string& prompt, const std::string& reprompt) {
    return readFloat(std::numeric_limits<float>::min(), std::numeric_limits<float>::max(), prompt, reprompt);
}
float readFloat(const std::string& prompt) {
    return readFloat(std::numeric_limits<float>::min(), std::numeric_limits<float>::max(), prompt, prompt);
}
float readFloat() {
    return readFloat(std::numeric_limits<float>::min(), std::numeric_limits<float>::max(), "", "");
}
double readDouble(double min, double max, const std::string& prompt, const std::string& reprompt) {
    if (min > max) {
        throw std::invalid_argument("Minimum value cannot be greater than maximum value.");
    }
    std::string line;
    double value;
    bool first = true;
    while (true) {
        pt(first ? prompt : reprompt);
        std::getline(std::cin, line);
        try {
            value = std::stod(line);
            if (value >= min && value <= max) {
                return value;
            }
        } catch (const std::invalid_argument &e) {
            // invalid input, continue to reprompt
        } catch (const std::out_of_range &e) {
            // input is out of range for double, continue to reprompt
        }
        first = false;
    }
}
double readDouble(double min, const std::string& prompt, const std::string& reprompt) {
    return readDouble(min, std::numeric_limits<double>::max(), prompt, reprompt);
}
double readDouble(const std::string& prompt, const std::string& reprompt) {
    return readDouble(std::numeric_limits<double>::min(), std::numeric_limits<double>::max(), prompt, reprompt);
}
double readDouble(const std::string& prompt) {
    return readDouble(std::numeric_limits<double>::min(), std::numeric_limits<double>::max(), prompt, prompt);
}
double readDouble() {
    return readDouble(std::numeric_limits<double>::min(), std::numeric_limits<double>::max(), "", "");
}
std::string readString(const std::string& prompt, const std::string& reprompt) {
    std::string line;
    pt(prompt);
    std::getline(std::cin, line);
    while (line.empty()) {
        pt(reprompt);
        std::getline(std::cin, line);
    }
    return line;
}
std::string readString(const std::string& prompt) {
    return readString(prompt, prompt);
}
std::string readString() {
    return readString("", "");
}
bool readBool(const std::string& prompt, const std::string& reprompt) {
    std::string line;
    pt(prompt);
    std::getline(std::cin, line);
    while (true) {
        line.erase(std::remove(line.begin(), line.end(), ' '), line.end());
        for (char& c : line) c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
        if (line == "y" || line == "yes" || line == "true" || line == "t" || line == "1") return true;
        else if (line == "n" || line == "no" || line == "false" || line == "f" || line == "0") return false;
        else {
            pt(reprompt);
            std::getline(std::cin, line);
        }
    }
}
bool readBool(const std::string& prompt) {
    return readBool(prompt, prompt);
}
bool readBool() {
    return readBool("", "");
}
} // namespace readvar
