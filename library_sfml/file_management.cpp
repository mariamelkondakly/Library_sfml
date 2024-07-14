#include "file_management.h"
#include <fstream>
#include <iostream>
using namespace std;

vector<Book> file_management::fantasy;
vector<Book> file_management::mystery;
vector<Book> file_management::romance;
vector<Book> file_management::non_fiction;
vector<Book> file_management::science_fiction;
vector<User> file_management::users;

int file_management::fantasy_size;
int file_management::mystery_size;
int file_management::romance_size;
int file_management::non_fiction_size;
int file_management::science_fiction_size;
User file_management::selectedUser;

void file_management::vector_to_file(string selectedFile, vector<Book> selectedv) {
    ofstream file(selectedFile);
    for (const auto& book : selectedv) {
        file << book.title << endl;
        file << book.author << endl;
        file << book.description << endl;
        file << book.type << endl;
        file << book.status << endl;
        file << book.price << endl;
        file << book.numofpages << endl;
        file << book.review << endl;
        file << book.quantity << endl;
    }
    file << "##";
    file.close();
}

void file_management::file_to_vector(string selectedFile, vector<Book>& selectedv, int size) {
    ifstream file(selectedFile);
    selectedv.clear(); 
    selectedv.reserve(size); 

    string line;
    while (getline(file, line)) {
        if (line == "##") break;

        Book book;
        book.title = line;
        getline(file, book.author);
        getline(file, book.description);
        getline(file, book.type);
        getline(file, book.status);
        getline(file, book.price);
        getline(file, book.numofpages);
        getline(file, book.review);
        getline(file, book.quantity);

        selectedv.push_back(book);
    }
    file.close();
}

void file_management::files_to_vectors() {
    file_management::file_to_vector("files/fantasy.txt", file_management::fantasy, file_management::fantasy_size);
    file_management::file_to_vector("files/romance.txt", file_management::romance, file_management::romance_size);
    file_management::file_to_vector("files/non_fiction.txt", file_management::non_fiction, file_management::non_fiction_size);
    file_management::file_to_vector("files/science_fiction.txt", file_management::science_fiction, file_management::science_fiction_size);
    file_management::file_to_vector("files/mystery.txt", file_management::mystery, file_management::mystery_size);
}

void file_management::vectors_to_files() {
    file_management::vector_to_file("files/fantasy.txt", file_management::fantasy);
    file_management::vector_to_file("files/romance.txt", file_management::romance);
    file_management::vector_to_file("files/non_fiction.txt", file_management::non_fiction);
    file_management::vector_to_file("files/science_fiction.txt", file_management::science_fiction);
    file_management::vector_to_file("files/mystery.txt", file_management::mystery);
}

void file_management::file_to_sizes() {
    ifstream file("files/bookssize.txt");
    file >> fantasy_size >> mystery_size >> romance_size >> non_fiction_size >> science_fiction_size;
    file.close();
}

void file_management::sizes_to_file() {
    ofstream file("files/bookssize.txt");
    file << fantasy.size() << endl;
    file << mystery.size() << endl;
    file << romance.size() << endl;
    file << non_fiction.size() << endl;
    file << science_fiction.size() << endl;
    file.close();
}

void file_management::file_to_users() {
    ifstream read("files/users.txt");
    users.clear();
    string userType, user_name, password_;
    while (getline(read, userType)) {
        User newUser;
        getline(read, user_name);
        getline(read, password_);
        newUser.usertype = userType;
        newUser.username = user_name;
        newUser.password = password_;
        users.push_back(newUser);
    }
    read.close();
}

void file_management::users_to_file() {
    ofstream read("files/users.txt");
    for (const auto& user : users) {
        read << user.usertype << endl;
        read << user.username << endl;
        read << user.password << endl;
    }
    read.close();
}
