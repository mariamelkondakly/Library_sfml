#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "Materials.h"
#include "User.h"
#include "file_management.h"

using namespace std;
using namespace sf;
class signup_page
{
public:
    signup_page();

    buttons signup_submit, login_submit;
    TextField signup_field_username, signup_field_password, login_field_username, login_field_password;
    Circle reader_check, admin_check;
    String userInput, passInput;
    string userInput_, passInput_, message;
    texts userText, passText, warning, signup,login;
    photos decoration, decoration2;
    void draw_signup_page(RenderWindow& window);
    void draw_login_page(RenderWindow& window);
    void resetInputFlags(signup_page& signup);
    bool onSignUpSubmit(User& user, String username, String password, texts& warning);
    bool onLoginSubmit(User& user, String username, String password, texts& warning);

    bool isSignupVisible;
    bool isLoginVisible;
    bool isWarning;
   
};

