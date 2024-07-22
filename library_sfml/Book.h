#pragma once
#include <iostream>
#include <string>
using namespace std;
class Book
{
public:
    string title;
    string author;
    string description;
    string type;
    string price;
    string numofpages;
    string review;
    string quantity;
    string path;
    bool isAvailable;
    Book (string _title, string _author, string _description, string _type, string _status, string _price, string _numofpages, string _review, string _quantity);
    Book();
};
class readersbooks {
public:
    string title;
    string status;
    string price;
    string quantity;
    readersbooks();

    readersbooks(string name, string cost, string quantity);

};

