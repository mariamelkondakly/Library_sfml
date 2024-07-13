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
    if (!file.is_open()) {
        cout << "Error opening file for writing: " << selectedFile << endl;
        return;
    }

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
    cout << "Finished writing to file: " << selectedFile << endl;
}

void file_management::file_to_vector(string selectedFile, vector<Book>& selectedv, int size) {
    ifstream file(selectedFile);
    if (!file.is_open()) {
        cout << "Error opening file for reading: " << selectedFile << endl;
        return;
    }

    selectedv.clear(); // Clear the vector before populating
    selectedv.reserve(size); // Reserve space to avoid reallocations

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
    cout << "Finished reading from file: " << selectedFile << endl;
}

void file_management::files_to_vectors() {
    file_management::file_to_vector("fantasy.txt", file_management::fantasy, file_management::fantasy_size);
    file_management::file_to_vector("romance.txt", file_management::romance, file_management::romance_size);
    file_management::file_to_vector("non_fiction.txt", file_management::non_fiction, file_management::non_fiction_size);
    file_management::file_to_vector("science_fiction.txt", file_management::science_fiction, file_management::science_fiction_size);
    file_management::file_to_vector("mystery.txt", file_management::mystery, file_management::mystery_size);
}

void file_management::vectors_to_files() {
    file_management::vector_to_file("fantasy.txt", file_management::fantasy);
    file_management::vector_to_file("romance.txt", file_management::romance);
    file_management::vector_to_file("non_fiction.txt", file_management::non_fiction);
    file_management::vector_to_file("science_fiction.txt", file_management::science_fiction);
    file_management::vector_to_file("mystery.txt", file_management::mystery);
}

void file_management::file_to_sizes() {
    ifstream file("bookssize.txt");
    if (!file.is_open()) {
        cout << "Error opening sizes file for reading" << endl;
        return;
    }

    file >> fantasy_size >> mystery_size >> romance_size >> non_fiction_size >> science_fiction_size;
    file.close();
    cout << "Finished reading sizes" << endl;
}

void file_management::sizes_to_file() {
    ofstream file("bookssize.txt");
    if (!file.is_open()) {
        cout << "Error opening sizes file for writing" << endl;
        return;
    }

    file << fantasy.size() << endl;
    file << mystery.size() << endl;
    file << romance.size() << endl;
    file << non_fiction.size() << endl;
    file << science_fiction.size() << endl;
    file.close();
    cout << "Finished writing sizes" << endl;
}

void file_management::file_to_users() {
    ifstream read("users.txt");
    if (!read.is_open()) {
        cout << "Error opening users file for reading" << endl;
        return;
    }

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
    cout << "Finished reading users" << endl;
}

void file_management::users_to_file() {
    ofstream read("users.txt");
    if (!read.is_open()) {
        cout << "Error opening users file for writing" << endl;
        return;
    }

    for (const auto& user : users) {
        read << user.usertype << endl;
        read << user.username << endl;
        read << user.password << endl;
    }
    read.close();
    cout << "Finished writing users" << endl;
}
