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
    bool isAdmin;
    vector <pair<int, int>>cart_vector;
};

