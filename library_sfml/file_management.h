#pragma once
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset.h>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include "Book.h"
#include "User.h"
using namespace std;
using namespace sf;
using namespace sql;


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

    static Connection* initConnection();
    static void loadBooksFromDatabase(sql::Connection* con, string genre, map<string, Book>& map);
    static void saveBooksToDatabase(sql::Connection* con, map<string, Book>& selectedm);
    static void saveMapsToDatabase(sql::Connection* con);
    static void getMapsFromDatabase(sql::Connection* con);
    static void loadUsersFromDataBase(sql::Connection* con);
    static void saveUsersIntoDatabase(sql::Connection* con);
    static void loadReadersBooksFromDataBase(sql::Connection* con, User& user);
    static void saveReadersBooksToDatabase(sql::Connection* con, User user);


};