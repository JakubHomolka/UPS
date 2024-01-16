#include "Utils.h"


vector<string> Utils::split(const string str, const string delim) {
    vector<string> tokens;
    size_t prev = 0, pos = 0;

    size_t valid = str.find(delim, prev);
    int max_size_of_first_part = 20;
    if (valid > max_size_of_first_part || valid <= 0) {
        return tokens;
    }

    do {
        pos = str.find(delim, prev);
        if (pos == string::npos) pos = str.length();
        string token = str.substr(prev, pos - prev);
        if (!token.empty()) tokens.push_back(token);
        prev = pos + delim.length();

    } while (pos < str.length() && prev < str.length());

    return tokens;
}

string Utils::left_trim(string s) {
    return regex_replace(s, regex("^\\s+"), std::string(""));
}

string Utils::right_trim(string s) {
    return regex_replace(s, regex("\\s+$"), std::string(""));
}

string Utils::trim(string s) {
    return left_trim(right_trim(s));
}

bool Utils::isAlpha(string str){
    for(int i = 0; i < str.size(); i++) {
        if (!isalpha(str[i])) return false;
    }
    return true;
}

