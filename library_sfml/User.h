#pragma once
#include<iostream>
#include<vector>
#include <stack>
#include <utility>
#include "Book.h"
using namespace std;

class User
{
public:
    string username;
    string password;
    int totalPrice;
    bool isAdmin;
    vector <readersbooks>cart_vector;
    vector<readersbooks>boughtBooks;
    void calculateTotalPrice();
};

