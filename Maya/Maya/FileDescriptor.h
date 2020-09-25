#pragma once

class FileDescriptor
{
public:
    explicit FileDescriptor(int);
    virtual ~FileDescriptor();

private:
    int fd;
};

