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

    static buttons signup_submit, login_submit;
    static TextField signup_field_username, signup_field_password, login_field_username, login_field_password;
    static Circle reader_check, admin_check;
    static String userInput, passInput;
    static string userInput_, passInput_, message;
    static texts userText, passText, warning, signup,login;
    static photos decoration, decoration2;
    static void draw_signup_page(RenderWindow& window);
    static void draw_login_page(RenderWindow& window);
    static void resetInputFlags();
    static bool onSignUpSubmit(User& user, String username, String password, texts& warning);
    static bool onLoginSubmit(User& user, String username, String password, texts& warning);

    static bool isSignupVisible;
    static bool isLoginVisible;
    static bool isWarning;
   
};

