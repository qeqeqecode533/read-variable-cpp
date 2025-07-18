#ifndef READVAR_H
#define READVAR_H

#include <iostream> // Added for pt and ptl
#include <string>

// === Output functions ===
template <typename T> void pt(T msg) {
    std::cout << msg;
}
inline void pt(const std::string &msg) {
    std::cout << msg;
}
inline void pt(const char *msg) {
    std::cout << msg;
}

template <typename T> void ptl(T msg) {
    std::cout << msg << std::endl;
}
inline void ptl(const std::string &msg) {
    std::cout << msg << std::endl;
}
inline void ptl(const char *msg) {
    std::cout << msg << std::endl;
}

// === Input reading functions ===
std::string readLine(const std::string &prompt = "", std::string reprompt = "");

int readInt(int min, int max, const std::string &prompt = "", std::string reprompt = "");
int readInt(int min, const std::string &prompt = "", const std::string &reprompt = "");
int readInt(const std::string &prompt = "", const std::string &reprompt = "");

double readDouble(double min, double max, const std::string &prompt = "", std::string reprompt = "");
double readDouble(double min, const std::string &prompt = "", const std::string &reprompt = "");
double readDouble(const std::string &prompt = "", const std::string &reprompt = "");

float readFloat(float min, float max, const std::string &prompt = "", std::string reprompt = "");
float readFloat(float min, const std::string &prompt = "", const std::string &reprompt = "");
float readFloat(const std::string &prompt = "", const std::string &reprompt = "");

bool equalsIgnoreCase(const std::string &a, const std::string &b);
bool readBool(const std::string &prompt = "", std::string reprompt = "");

char readChar(const std::string &prompt = "", std::string reprompt = "");

#endif // READVAR_H
