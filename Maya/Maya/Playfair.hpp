#pragma once

#include <iostream>
#include <string>

class Playfair final
{
public:
    static const char DEFAULT_ODD_SUFFIX_LETTER = ' ';

public:
    Playfair() = delete;
    explicit Playfair(const std::string& key);
    Playfair(const std::string& key, bool replaceJI, char oddSuffixLetter, bool keepDoubleLetters, bool keepSpecialChars);
    ~Playfair() = default;

    std::string encrypt(const std::string& message);
    std::string decrypt(const std::string& message);

    std::string excrypt(const std::string& message, bool isEncrypt);

private:
    const bool replaceJI;
    const bool keepDoubleLetters;
    const char oddSuffixLetter;
    const bool keepSpecialChars;
    char table[5][5];


    char getChar(int a, int b);
    bool getPos(char l, int& c, int& d);
    std::string fixText(const std::string& text, bool shouldEncrypt) const;
};
