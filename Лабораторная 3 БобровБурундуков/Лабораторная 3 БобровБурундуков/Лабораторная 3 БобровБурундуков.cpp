#include <iostream>
#include <list>
#include <string>

#pragma region НОМЕРА
#define MOBILNIYNOMER 0
#define RABOCHIYNOMER 1
#define DOMASHNIYNOMER 2
#pragma endregion

using namespace std;

class Nomer
{
public:
    Nomer(string number, int tip)
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
    Contact(string name, list<Nomer> list)
    {
        this->name = name;
        this->numbers = list;
    }
    string name;
    list<Nomer> numbers;
};

class ContactnayaKniga
{
private:
    list<Contact> contacts;
public:
    list<Contact> find(string);
    list<Nomer> view(string);
    void add(Contact);
    void change(string, string, string);
    void remove(string);
};

list<Contact> ContactnayaKniga::find(string str)
{
    list<Contact> list;

    for (auto i = contacts.begin(); i != contacts.end(); i++)
    {
        auto postroka = i->name.find(str);
        if (postroka != string::npos)
        {
            list.push_back(*i);
        }
        for (auto j = i->numbers.begin(); j != i->numbers.end(); j++)
        {
            auto substr = j->number.find(str);
            if (substr != string::npos)
            {
                list.push_back(*i);
            }
        }

    }

    return list;
}

list<Nomer> ContactnayaKniga::view(string name)
{
    list<Nomer> list;

    auto i = contacts.begin();
    for (i; i != contacts.end(); i++)
    {
        if (i->name == name)
        {
            list = i->numbers;
            break;
        }
    }
    if (i == contacts.end()) throw exception("Не нашёл контакт");
    return list;
}

void ContactnayaKniga::add(Contact contact)
{
    contacts.push_back(contact);
}

void ContactnayaKniga::change(string name, string stariyNomer, string noviyNomer)
{
    auto i = contacts.begin();
    for (i; i != contacts.end(); i++)
    {
        if (i->name == name) break;
    }

    if (i == contacts.end()) throw exception("Не нашёл контакт");

    for (auto it = i->numbers.begin(); it != i->numbers.end(); it++)
    {
        if (it->number == stariyNomer)
        {
            it->number = noviyNomer;
            return;
        }
    }

    throw exception("Не нашёл заменяемого номера");
}

void ContactnayaKniga::remove(string name)
{
    auto i = contacts.begin();
    for (i; i != contacts.end(); i++)
    {
        if (i->name == name)
        {
            contacts.remove(*i);
        }
    }
}

int main()
{
    ContactnayaKniga book;
    Nomer* mobil1 = new Nomer("12321314241", MOBILNIYNOMER);
    Nomer* domashniy1 = new Nomer("75674567", DOMASHNIYNOMER);
    list<Nomer> list1;
    list1.push_back(*mobil1);
    list1.push_back(*domashniy1);
    Contact sasha("Саша", list1);
    book.add(sasha);
    Nomer* mobil2 = new Nomer("1523453245", RABOCHIYNOMER);
    Nomer* domashniy2 = new Nomer("879679865", DOMASHNIYNOMER);
    list<Nomer> list2;
    list1.push_back(*mobil2);
    list1.push_back(*domashniy2);
    Contact pasha("Паша", list2);
    book.add(pasha);
    book.view("Паша");
    book.remove("Паша");
    book.change("Саша", "12321314241", "654331231221");
}