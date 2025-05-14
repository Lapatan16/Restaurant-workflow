#ifndef JELO_EXCEPTION_H
#define JELO_EXCEPTION_H

#include"iostream"
using namespace std;
#include"exception"

class JeloException : exception
{
    private:
        const string msg;
    
    public:
        JeloException(const string &msg)
        :msg("\033[1;31m" + msg + "\033[0m")
        {
            
        }
        virtual const char *what() const throw()
        {
            return msg.c_str();
        }
};

#endif