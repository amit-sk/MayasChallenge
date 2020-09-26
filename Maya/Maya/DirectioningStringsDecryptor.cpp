#include "pch.h"
#include "Playfair.hpp"
#include "DirectioningStringsDecryptor.hpp"


DirectioningStringsDecryptor::DirectioningStringsDecryptor() :
    directioning_strings(get_directioning_strings())
{}

std::vector<std::string> DirectioningStringsDecryptor::get_directioning_strings()
{
    return {
        "NY'X SDVC'P DGSUICDV!",
        "KCVD JBUT BTTOL PABRRZ DCPGNY",
        "JCS TDOUC KJ XSBON GX MBU UCBSDU TPUAS RLZBU",
        "UBDHUA UBUASUNJUB: OSFEEBPB DKC NPJGJMT. XGDP BOUC ENCU B FGTM OJJD?",
        "FCZA ZNZ JZAS TJJK DT NEB UM TFOL?",
        "KCVD PTAE UN ESS IBU LZM IDFR",
        "KCVD MKZAP CTNKCMR",
        "N INIT'Y AZDO LOLZ ZNS EDK HMDKJB SIA DKMLUXHJCOC NT TPGRHNE",
        "KCVD ENCUT'Y FCZA F ABUZ DYSDOTHZA PDTUD JO NPTHD",
        "JC JKTOI YJC DOE NI PJC PBNTELW",
        "NX EATYHTY YBOMR OC SIDP HMBZNTL GTGAMT HP XBUW DBE JKT WUZS UJJSI.",
        "NY ENCUT'Y UMTOB NFND UFCR YGNO BZAW GJ UO ND YPBZAR RHTT.",
        "SIC UOKX-BKZBUAE VFSI",
        "XMA BRBDVX XUAFPT UM JHN NT B KUZA YNJDA",
        "UMOCYNOCT H TUBPA BP D ENLU LU B VBKL",
        "SIA JMZ NT SID UKUFCR YIJTRBUAE NTUN SIJ JBP KJ SIB UBCDGT.",
        "NY FCE CJJM THYUDDO EBXT THMDD UJC EULCJDP HGTTU DPPDAMAE.",
        "FKUDU BVSMKTGLI SIA BCBTIKOAE ERGNINLI, JC TUBPUDI YL EBOJDZA NT HIMUUT.",
        "IJT HSSDOUC KBYJODXX VBT HMTTFPBYNKOBK UN NUJCST",
    };
}

std::string DirectioningStringsDecryptor::decrypt_directioning_string(size_t index, uint8_t key) const
{
    Playfair decryptor(std::to_string(key));
    return decryptor.decrypt(directioning_strings.at(index % directioning_strings.size()));
}
