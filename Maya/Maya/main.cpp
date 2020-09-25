#include "pch.h"
#include <iostream>
#include <stdexcept>

#include "AES.hpp"
#include "ProjectException.hpp"
#include "Challenger.hpp"

void aes_example()
{
    unsigned char plain[] = { 0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff }; //plaintext example
    unsigned char key[] = { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f }; //key example
    unsigned int plainLen = 16 * sizeof(unsigned char);  //bytes in plaintext
    unsigned int outLen = 0;  // out param - bytes in сiphertext

    AES aes(128);  //128 - key length, can be 128, 192 or 256
    unsigned char* c = aes.EncryptECB(plain, plainLen, key, outLen);

    for (int i = 0; i < plainLen; ++i)
    {
        std::cout << c[i] << " ";
    }
    std::cout << std::endl;

    delete[] c;
}

int main()
{
    try
    {
        aes_example();

        Challenger challenger;
        challenger.run_challenge();
        std::cout << "Hello World!\n";
        return static_cast<int>(ProjectStatus::Success);
    }
    catch (const ProjectException& e)
    {
        std::cerr << "Caught ProjectException status " << e.get_string_status() << ": " << e.what() << std::endl;
        return static_cast<int>(e.status);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Caught Exception: " << e.what() << std::endl;
        return static_cast<int>(ProjectStatus::StandardExceptionThrown);
    }
    catch (...)
    {
        std::cerr << "Unknown Error." << std::endl;
        return static_cast<int>(ProjectStatus::UnknownExceptionThrown);
    }
}

