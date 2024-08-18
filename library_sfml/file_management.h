#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include "Book.h"
#include "User.h"
using namespace std;
using namespace sf;

class file_management
{
public:
    static map<string, Book> fantasy;
    static map<string, Book> mystery;
    static map<string, Book> romance;
    static map<string, Book> non_fiction;
    static map<string, Book> science_fiction;
    static map<string, User> users;

    static int fantasy_size;
    static int mystery_size;
    static int romance_size;
    static int non_fiction_size;
    static int science_fiction_size;

    static string selectedUser;
    static string selectedBook;

    static void file_to_map(const string& selectedFile, map<string, Book>& selectedm, int& size);
    static void map_to_file(const string& selectedFile, const map<string, Book>& selectedm);

    static void file_to_sizes();
    static void sizes_to_file();

    static void files_to_maps();
    static void maps_to_files();

    static void users_to_file();
    static void file_to_users();
};