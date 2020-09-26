#include "pch.h"
#include "Playfair.hpp"
#include "DirectioningStringsDecryptor.hpp"


DirectioningStringsDecryptor::DirectioningStringsDecryptor() :
    directioning_strings(get_directioning_strings())
{}

std::vector<std::string> DirectioningStringsDecryptor::get_directioning_strings()
{
    return {
        "It’s Maya’s birthday!",
        "Maya gets drunk really easily",
        "Her sense of smell is her secret super power",
        "Recipe repertoire: mujadara and muffins. What else does a girl need?",
        "Have you ever seen an IDA so pink?",
        "Maya used to cut her own hair",
        "Maya loves animals",
        "I didn’t even know you can change the colorscheme in sublime",
        "Maya doesn’t have a very extensive taste in music",
        "He found the end of the rainbow",
        "My dentist tells me that chewing bricks is very bad for your teeth.",
        "It doesn't sound like that will ever be on my travel list.",
        "The snow-covered path",
        "She always speaks to him in a loud voice",
        "Sometimes I stare at a door or a wall",
        "The fox in the tophat whispered into the ear of the rabbit.",
        "It had been sixteen days since the zombies first attacked.",
        "After exploring the abandoned building, he started to believe in ghosts.",
        "His immense laziness was inspirational to others",
    };
}

std::string DirectioningStringsDecryptor::encrypt_directioning_string(size_t index, uint8_t key)// const
{
    Playfair decryptor(std::to_string(key));
    directioning_strings.at(index) = decryptor.encrypt(directioning_strings.at(index));
    return directioning_strings.at(index);
}

std::string DirectioningStringsDecryptor::decrypt_directioning_string(size_t index, uint8_t key)// const
{
    Playfair decryptor(std::to_string(key));
    directioning_strings.at(index) = decryptor.decrypt(directioning_strings.at(index)); // TODO don't subsitute the string, just return it
    return directioning_strings.at(index);
}
