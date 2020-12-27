#pragma once
#include "ContactBook.cpp"

enum TypeNumber
{
    MobilNumber, WorkNumber, HomeNumber
};

using namespace std;

class Number
{
public:
    Number(string number, int tip)
    {
        this->number = number;
        this->typeNumber = tip;
    }
    string number;
    int typeNumber;
};

class Contact
{
public:
    Contact(string name, list<Number> list)
    {
        this->name = name;
        this->numbers = list;
    }
    string name;
    list<Number> numbers;
};

class ContactBook
{
private:
    list<Contact> contacts;
public:
    list<Contact> find(string);
    list<Number> view(string);
    void add(Contact);
    void change(string, string, string);
    void remove(string);
};