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
    string genre;
    double price;
    int numofpages;
    string review;
    int quantity;
    string path;
    bool isAvailable;
    Book(string _title, string _author, string _description, string _type, string _status, double _price, int _numofpages, string _review, int _quantity);
    Book();
};
class readersbooks {
public:
    string username;
    string title;
    float price;
    int quantity;
    readersbooks();

    readersbooks(string name,string username, float cost, int quantity);

};

