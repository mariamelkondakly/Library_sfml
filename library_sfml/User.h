#pragma once
#include<iostream>
#include<vector>
#include <utility>
#include "Book.h"
using namespace std;

class User
{
public:
    string usertype;
    string username;
    string password;
    float totalPrice;
    bool isAdmin;
    vector <readersbooks>cart_vector;
    float calculateTotalPrice();
};

