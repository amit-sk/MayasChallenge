#include "pch.h"
#include "FileDescriptor.h"


FileDescriptor::FileDescriptor(int _fd) :
    fd(_fd)
{}


FileDescriptor::~FileDescriptor()
{
    // close(fd);
}
