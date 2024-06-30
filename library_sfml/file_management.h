#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <fstream>
#include "Book.h";
#include "User.h"
using namespace std;
using namespace sf;

class file_management
{
public:
	static vector<Book> fantasy;
	static vector<Book> mystery;
	static vector<Book> romance;
	static vector<Book> non_fiction;
	static vector<Book> science_fiction;
	static vector<User> users;

	static int fantasy_size;
	static int mystery_size;
	static int romance_size;
	static int non_fiction_size; 
	static int science_fiction_size;

	static User* selectedUser;

	static void file_to_vector(string file, vector<Book>& selectedv,int size);
	static void vector_to_file(string selectedFile, vector<Book> selectedv);

	static void file_to_sizes();
	static void sizes_to_file();
	
	static void files_to_vectors();
	static void vectors_to_files();

	static void users_to_file();
	static void file_to_users();
};

