#pragma once

#include <fstream>
#include <iostream>
using namespace std;

class Message
{
    private:
        string _text;
        string _sender;
        string _receiver;
    public:
        Message(string txt, string sender, string receiver) : _text(txt), _sender(sender), _receiver(receiver) {}
        
        friend fstream& operator >>(fstream& is, Message& msg);
	    friend ostream& operator <<(ostream& os, const Message& msg);
        
}; 

fstream& operator >>(fstream& is, Message& msg)
{
	is >> msg._text;
	is >> msg._sender;
	is >> msg._receiver;
	return is;
}
ostream& operator <<(ostream& os, const Message& msg)
{
	os << msg._text;
	os << ' ';
	os << msg._sender;
	os << ' ';
	os << msg._receiver;
	return os;
}