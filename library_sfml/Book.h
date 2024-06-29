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
    string status;
    string price;
    string numofpages;
    string review;
    string quantity;
    Book (string _title, string _author, string _description, string _type, string _status, string _price, string _numofpages, string _review, string _quantity);
    Book();
};

