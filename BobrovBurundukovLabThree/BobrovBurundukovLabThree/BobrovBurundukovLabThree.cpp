#include <iostream>
#include "ContactBook.h"

int main()
{
    ContactBook book;
    Number* mobil1 = new Number("12321314241", MobilNumber);
    Number* home1 = new Number("75674567", HomeNumber);
    list<Number> list1;
    list1.push_back(*mobil1);
    list1.push_back(*home1);
    Contact sasha("Саша", list1);
    book.add(sasha);
    Number* mobil2 = new Number("1523453245", WorkNumber);
    Number* home2 = new Number("879679865", HomeNumber);
    list<Number> list2;
    list1.push_back(*mobil2);
    list1.push_back(*home2);
    Contact pasha("Паша", list2);
    book.add(pasha);
    book.view("Паша");
    book.remove("Паша");
    book.change("Саша", "12321314241", "654331231221");
}