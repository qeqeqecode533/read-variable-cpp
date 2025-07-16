#ifndef READVAR_H
#define READVAR_H

#include <string>

// === Output functions ===
template <typename T>
void pt(T msg);

template <typename T>
void ptl(T msg);

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

#endif // READVAR_H
