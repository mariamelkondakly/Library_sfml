#pragma once
#include<iostream>
#include<vector>
#include <utility>
using namespace std;

class User
{
public:
    string usertype;
    string username;
    string password;
    float totalPrice;
    bool isAdmin;
    vector <pair<string, int>>cart_vector;
    float calculateTotalPrice();
};

