#include "file_management.h"
// Initialize static members
map<string, Book> file_management::fantasy;
map<string, Book> file_management::mystery;
map<string, Book> file_management::romance;
map<string, Book> file_management::non_fiction;
map<string, Book> file_management::science_fiction;
map<string, User> file_management::users;

int file_management::fantasy_size;
int file_management::mystery_size;
int file_management::romance_size;
int file_management::non_fiction_size;
int file_management::science_fiction_size;
string file_management::selectedUser;
string file_management::selectedBook = "";

void file_management::map_to_file(const string& selectedFile, const map<string, Book>& selectedm) {
    ofstream file(selectedFile);
    if (!file) {
        cerr << "Error opening file: " << selectedFile << endl;
        return;
    }

    for (const auto& pair : selectedm) {
        const string& key = pair.first;
        const Book& book = pair.second;
        file << key << endl;
        file << book.author << endl;
        file << book.description << endl;
        file << book.type << endl;
        file << book.price << endl;
        file << book.numofpages << endl;
        file << book.review << endl;
        file << book.quantity << endl;
        file << book.path << endl;
    }
    file << "##";
    file.close();
}

void file_management::file_to_map(const string& selectedFile, map<string, Book>& selectedm, int& size) {
    ifstream file(selectedFile);
    if (!file.is_open()) {
        cerr << "Failed to open file: " << selectedFile << endl;
        return;
    }
    selectedm.clear();
    string line;
    while (getline(file, line)) {
        if (line == "##") break;

        Book book;
        string key = line;
        getline(file, book.author);
        getline(file, book.description);
        getline(file, book.type);
        getline(file, book.price);
        getline(file, book.numofpages);
        getline(file, book.review);
        getline(file, book.quantity);
        getline(file, book.path);
        book.title = key;

        book.isAvailable = (stoi(book.quantity) != 0);

        selectedm[key] = book;
    }
    size = selectedm.size();
    file.close();
}

void file_management::files_to_maps() {
    file_to_map("files/fantasy.txt", fantasy, fantasy_size);
    file_to_map("files/romance.txt", romance, romance_size);
    file_to_map("files/non_fiction.txt", non_fiction, non_fiction_size);
    file_to_map("files/science_fiction.txt", science_fiction, science_fiction_size);
    file_to_map("files/mystery.txt", mystery, mystery_size);
}

void file_management::maps_to_files() {
    map_to_file("files/fantasy.txt", fantasy);
    map_to_file("files/romance.txt", romance);
    map_to_file("files/non_fiction.txt", non_fiction);
    map_to_file("files/science_fiction.txt", science_fiction);
    map_to_file("files/mystery.txt", mystery);
}

void file_management::file_to_sizes() {
    ifstream file("files/bookssize.txt");
    if (!file.is_open()) {
        cerr << "Failed to open file: files/bookssize.txt" << endl;
        return;
    }
    file >> fantasy_size >> mystery_size >> romance_size >> non_fiction_size >> science_fiction_size;
    file.close();
}

void file_management::sizes_to_file() {
    ofstream file("files/bookssize.txt");
    if (!file.is_open()) {
        cerr << "Failed to open file: files/bookssize.txt" << endl;
        return;
    }
    file << fantasy_size << endl;
    file << mystery_size << endl;
    file << romance_size << endl;
    file << non_fiction_size << endl;
    file << science_fiction_size << endl;
    file.close();
}

void file_management::file_to_users() {
    ifstream read("files/users.txt");
    if (!read.is_open()) {
        cerr << "Failed to open file: files/users.txt" << endl;
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
        users[user_name] = newUser;
    }
    read.close();
}

void file_management::users_to_file() {
    ofstream read("files/users.txt");
    for (const auto& pair : users) {
        const User& user = pair.second;
        read << user.usertype << endl;
        read << user.username << endl;
        read << user.password << endl;
    }
    read.close();
}