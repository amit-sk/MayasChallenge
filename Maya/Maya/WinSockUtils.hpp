#pragma once
class WinSockUtils
{
public:
    WinSockUtils();
    virtual ~WinSockUtils();

private:
    static void initialize_winsock();
};

