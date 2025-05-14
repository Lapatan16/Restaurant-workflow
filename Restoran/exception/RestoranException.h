#ifndef RESTORAN_EXCEPTION_H    
#define RESTORAN_EXCEPTION_H

#include"iostream"
using namespace std;
#include"exception"

class RestoranException : exception
{
    private:
        const string msg;
    
    public:
        RestoranException(const string &msg)
        :msg("\033[1;31m" + msg + "\033[0m")
        {

        }
        virtual const char *what() const throw()
        {
            return msg.c_str();
        }
};

#endif