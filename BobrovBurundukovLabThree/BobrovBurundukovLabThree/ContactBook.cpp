#include <list>
#include <string>
#include "ContactBook.h"

list<Contact> ContactBook::find(string str)
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

list<Number> ContactBook::view(string name)
{
    list<Number> list;

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

void ContactBook::add(Contact contact)
{
    contacts.push_back(contact);
}

void ContactBook::change(string name, string stariyNomer, string noviyNomer)
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

void ContactBook::remove(string name)
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
