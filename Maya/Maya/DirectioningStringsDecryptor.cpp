#include "pch.h"
#include "Playfair.hpp"
#include "DirectioningStringsDecryptor.hpp"


DirectioningStringsDecryptor::DirectioningStringsDecryptor() :
    directioning_strings(get_directioning_strings())
{}

std::vector<std::string> DirectioningStringsDecryptor::get_directioning_strings()
{
    return {
        "NYXSDVCPDGSUICDV",
        "KCVDJBUTBTTOLPABRRZDCPGNZY",
        "JCSTDOUCKJXSBONGXMBUUCBSDUTPUASRLZBU",
        "UBDHUAUBUASUNJUBOSFEEBPBDKCNPJGJMTXGDPBOUCENCUBFGTMOJJCY",
        "FCZAZNZJZASTJJKDTNEBUMTFOL",
        "KCVDPTAEUNESSIBULZMIDFSW",
        "KCVDMKZAPCTNKCMR",
        "NINITYAZDOLOLZZNSEDKHMDKJBSIADKMLUXHJCOCNTTPGRHNCZ",
        "KCVDENCUTYFCZAFABUZDYSDOTHZAPDTUDJONPTHD",
        "JCJKTOIYJCDOENIPJCPBNTELXY",
        "NXEATYHTYYBOMROCSIDPHMBZNTLGTGAMTHPXBUWDBEJKTWUZSUJJSI",
        "NYENCUTYUMTOBNFNDUFCRYGNOBZAWGJUONDYPBZARRHTSY",
        "SICUOKXBKZBUAEVFSI",
        "XMABRBDVXXUAFPTUMJHNNTBKUZAYNJDA",
        "UMOCYNOCTHTUBPABPDENLULUBVBKMW",
        "SIAJMZNTSIDUKUFCRYIJTRBUAENTUNSIJJBPKJSIBUBCDGSY",
        "NYFCECJJMTHYUDDOEBXTTHMDDUJCEULCJDPHGTTUDPPDAMAE",
        "FKUDUBVSMKTGLISIABCBTIKOAEERGNINLIJCTUBPUDIYLEBOJDZANTHIMUUT",
        "IJTHSSDOUCKBYJODXXVBTHMTTFPBYNKOBKUNNUJCST",
    };
}

std::string DirectioningStringsDecryptor::decrypt_directioning_string(size_t index, uint8_t key) const
{
    Playfair decryptor(std::to_string(key), false);
    return decryptor.decrypt(directioning_strings.at(index));
}
