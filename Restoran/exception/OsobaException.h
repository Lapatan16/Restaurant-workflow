#ifndef OSOBA_EXCEPTION_H    
#define OSOBA_EXCEPTION_H

#include"iostream"
using namespace std;
#include"exception"

class OsobaException : exception
{
    private:
        const string msg;
    
    public:
        OsobaException(const string &msg)
        :msg("\033[1;31m" + msg + "\033[0m")
        {

        }
        virtual const char *what() const throw()
        {
            return msg.c_str();
        }
};

#endif