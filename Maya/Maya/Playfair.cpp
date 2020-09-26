#include "pch.h"
#include <algorithm>
#include <string>
#include "Playfair.hpp"

Playfair::Playfair(const std::string& key) :
    Playfair(key, false, DEFAULT_ODD_SUFFIX_LETTER, false, true)
{}

Playfair::Playfair(const std::string& key, bool replaceJI, char oddSuffixLetter, bool keepDoubleLetters, bool keepSpecialChars) :
    replaceJI(replaceJI),
    keepDoubleLetters(keepDoubleLetters),
    oddSuffixLetter(oddSuffixLetter),
    keepSpecialChars(keepSpecialChars),
    table()
{
    std::string keyUp(key);
    std::transform(keyUp.begin(), keyUp.end(), keyUp.begin(), ::toupper);

    if (keyUp.length() < 1)
        keyUp = "KEYWORD";
    keyUp += "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    std::string fixedKey = "";
    for (std::string::iterator it = keyUp.begin(); it != keyUp.end(); ++it) {
        if (*it < 65 || *it > 90)
            continue;
        if ((*it == 'J' && replaceJI) || (*it == 'Q' && !replaceJI))
            continue;
        if (fixedKey.find(*it) == -1)
            fixedKey += *it;
    }
    std::copy(fixedKey.begin(), fixedKey.end(), &table[0][0]);
}

std::string Playfair::encrypt(const std::string& message)
{
    return excrypt(message, true);
}

std::string Playfair::decrypt(const std::string& message)
{
    return excrypt(message, false);
}

std::string Playfair::excrypt(const std::string& message, bool isEncrypt)
{
    std::string fixedMessage = fixText(message, isEncrypt);

    int j, k, p, q;
    bool skipPrevious = false;
    const int direction = isEncrypt ? 1 : -1;
    std::string temp;
    // CR: (GB) use string builder..
    std::string newMessage;
    for (std::string::const_iterator it = fixedMessage.begin(); it != fixedMessage.end(); ++it)
    {
        if (!skipPrevious)
        {
            const char previous = *it;
            if (!getPos(previous, j, k))
            {
                newMessage += temp;
                newMessage += previous;
                temp = "";
                continue;
            }
            skipPrevious = true;
            ++it;
        }

        if (it == fixedMessage.end())
        {
            newMessage += getChar(j, k);
            newMessage += temp;
            skipPrevious = false;
            break;
        }

        const char current = *it;
        if (!getPos(current, p, q))
        {
            temp += current;
            continue;
        }

        skipPrevious = false;

        //for same row
        int a1 = p, a2 = j, b1 = k, b2 = q;
        if (j == p)
        {
            a1 = j;
            b1 = k + direction;
            a2 = p;
            b2 = q + direction;
        }
        //for same column
        else if (k == q) {
            a1 = j + direction;
            b1 = k;
            a2 = p + direction;
            b2 = q;
        }

        newMessage += getChar(a1, b1);
        newMessage += temp;
        newMessage += getChar(a2, b2);

        temp = "";
    }

    if (skipPrevious)
    {
        newMessage += getChar(j, k);
        newMessage += temp;
    }

    return newMessage;
}

std::string Playfair::fixText(const std::string& text, bool shouldEncrypt) const
{
    std::string fixedText;

    for (std::string::const_iterator it = text.begin(); it != text.end(); ++it)
    {
        //to choose J = I or no Q in the alphabet.
        char letter = *it;
        if (letter >= 'a' && letter <= 'z')
            letter += 'A' - 'a';

        if (letter < 'A' || letter > 'Z')
        {
            if (!keepSpecialChars)
            {
                continue;
            }
            fixedText += letter;
            continue;
        }

        if (letter == 'J' && replaceJI)
            letter = 'I';
        else if (letter == 'Q' && !replaceJI)
            continue;
        fixedText += letter;
    }

    if (shouldEncrypt)
    {
        std::string nmsg = "";
        for (int x = 0; x < fixedText.length(); x += 2)
        {
            nmsg += fixedText[x];
            if (x < fixedText.length() - 1)
            {
                if (keepDoubleLetters && fixedText[x] == fixedText[x + 1])
                {
                    nmsg += 'X';
                }
                nmsg += fixedText[x + 1];
            }
        }
        fixedText = nmsg;
    }

    if (fixedText.length() & 1)
    {
        fixedText += oddSuffixLetter;
    }

    return fixedText;
}

char Playfair::getChar(int a, int b)
{
    return table[(b + 5) % 5][(a + 5) % 5];
}

bool Playfair::getPos(char l, int& c, int& d)
{
    for (int y = 0; y < 5; y++)
    {
        for (int x = 0; x < 5; x++)
        {
            if (table[y][x] != l)
            {
                continue;
            }

            c = x;
            d = y;

            return true;
        }
    }

    return false;
}
