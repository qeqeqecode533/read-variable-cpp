#include "ReadVar.h"
#include <cctype>
#include <iostream>
#include <limits>
#include <string>

using namespace std;

// Making robust input handling functions here
string readLine(const string &prompt, string reprompt) {
    reprompt = reprompt.empty() ? prompt : reprompt;
    string in;
    pt(prompt);
    getline(cin, in);
    while (in.empty()) {
        pt(reprompt);
        getline(cin, in);
    }
    return in;
}
int readInt(int min, int max, const string &prompt, string reprompt) {
    reprompt = reprompt.empty() ? prompt : reprompt;
    int in;
    pt(prompt);
    string input;
    getline(cin, input);
    while (true) {
        try {
            in = stoi(input);
            if (in < min || in > max) {
                throw out_of_range("Input out of range");
            }
            break; // Valid input
        } catch (const invalid_argument &) {
            pt(reprompt);
            getline(cin, input);
        } catch (const out_of_range &) {
            pt(reprompt);
            getline(cin, input);
        }
    }
    return in;
}
int readInt(int min, const string &prompt, const string &reprompt) {
    return readInt(min, numeric_limits<int>::max(), prompt, reprompt);
}
int readInt(const string &prompt, const string &reprompt) {
    return readInt(numeric_limits<int>::lowest(), numeric_limits<int>::max(), prompt, reprompt);
}
double readDouble(double min, double max, const string &prompt, string reprompt) {
    reprompt = reprompt.empty() ? prompt : reprompt;
    double in;
    pt(prompt);
    string input;
    getline(cin, input);
    while (true) {
        try {
            in = stod(input);
            if (in < min || in > max) {
                throw out_of_range("Input out of range");
                ; // Out of range, reprompt
            }
            break; // Valid input
        } catch (const invalid_argument &) {
            pt(reprompt);
            getline(cin, input);
        } catch (const out_of_range &) {
            pt(reprompt);
            getline(cin, input);
        }
    }
    return in;
}
double readDouble(double min, const string &prompt, const string &reprompt) {
    return readDouble(min, numeric_limits<double>::max(), prompt, reprompt);
}
double readDouble(const string &prompt, const string &reprompt) {
    return readDouble(numeric_limits<double>::lowest(), numeric_limits<double>::max(), prompt, reprompt);
}
float readFloat(float min, float max, const string &prompt, string reprompt) {
    reprompt = reprompt.empty() ? prompt : reprompt;
    float in;
    pt(prompt);
    string input;
    getline(cin, input);
    while (true) {
        try {
            in = stof(input);
            if (in < min || in > max) {
                throw out_of_range("Input out of range");
                ; // Out of range, reprompt
            }
            break; // Valid input
        } catch (const invalid_argument &) {
            pt(reprompt);
            getline(cin, input);
        } catch (const out_of_range &) {
            pt(reprompt);
            getline(cin, input);
        }
    }
    return in;
}
float readFloat(float min, const string &prompt, const string &reprompt) {
    return readFloat(min, numeric_limits<float>::max(), prompt, reprompt);
}
float readFloat(const string &prompt, const string &reprompt) {
    return readFloat(numeric_limits<float>::lowest(), numeric_limits<float>::max(), prompt, reprompt);
}
bool equalsIgnoreCase(const string &a, const string &b) {
    if (a.length() != b.length())
        return false;
    for (size_t i = 0; i < a.length(); ++i) {
        if (std::tolower(a[i]) != std::tolower(b[i]))
            return false;
    }
    return true;
}
bool readBool(const string &prompt, string reprompt) {
    reprompt = reprompt.empty() ? prompt : reprompt;
    string input;
    pt(prompt);
    getline(cin, input);
    while (true) {
        if (equalsIgnoreCase(input, "yes") || equalsIgnoreCase(input, "y") || equalsIgnoreCase(input, "true")) {
            return true;
        } else if (equalsIgnoreCase(input, "no") || equalsIgnoreCase(input, "n") || equalsIgnoreCase(input, "false")) {
            return false;
        } else {
            pt(reprompt);
            getline(cin, input);
        }
    }
}
char readChar(const string &prompt, string reprompt) {
    reprompt = reprompt.empty() ? prompt : reprompt;
    string input;
    pt(prompt);
    getline(cin, input);
    while (true) {
        try {
            return input.at(0);
        } catch (const out_of_range &) {
            pt(reprompt);
            getline(cin, input);
        }
    }
}
