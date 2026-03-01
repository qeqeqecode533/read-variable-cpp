#ifndef READVAR_H
#define READVAR_H

#include <string>
#include <limits>

using ll = long long;
namespace readvar {
    int readInt(int min, int max, const std::string& prompt, const std::string& reprompt);
    int readInt(int min, const std::string& prompt, const std::string& reprompt);
    int readInt(const std::string& prompt, const std::string& reprompt);
    int readInt(const std::string& prompt);
    int readInt();
    ll readLongLong(ll min, ll max, const std::string& prompt, const std::string& reprompt);
    ll readLongLong(ll min, const std::string& prompt, const std::string& reprompt);
    ll readLongLong(const std::string& prompt, const std::string& reprompt);
    ll readLongLong(const std::string& prompt);
    ll readLongLong();
    float readFloat(float min, float max, const std::string& prompt, const std::string& reprompt);
    float readFloat(float min, const std::string& prompt, const std::string& reprompt);
    float readFloat(const std::string& prompt, const std::string& reprompt);
    float readFloat(const std::string& prompt);
    float readFloat();
    double readDouble(double min, double max, const std::string& prompt, const std::string& reprompt);
    double readDouble(double min, const std::string& prompt, const std::string& reprompt);
    double readDouble(const std::string& prompt, const std::string& reprompt);
    double readDouble(const std::string& prompt);
    double readDouble();
    std::string readString(const std::string& prompt, const std::string& reprompt);
    std::string readString(const std::string& prompt);
    std::string readString();
    bool readBool(const std::string& prompt, const std::string& reprompt);
    bool readBool(const std::string& prompt);
    bool readBool();
}

#endif // READVAR_H
