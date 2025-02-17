#ifndef PROTOCOL_H
#define PROTOCOL_H

#include<string>

using namespace std;

class Protocol {
    public:
        virtual void sendData(const string& data) = 0;
        virtual string receiveData() = 0;
        virtual ~Protocol() {}
};


#endif
