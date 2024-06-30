#include "file_management.h"

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
User* file_management::selectedUser = nullptr;


void file_management::vector_to_file(string selectedFile, vector<Book> selectedv)
{
    ofstream file;
    file.open(selectedFile);

    for (int i = 0; i < selectedv.size(); i++)
    {
        file << selectedv[i].title << endl;
        file << selectedv[i].author << endl;
        file << selectedv[i].description << endl;
        file << selectedv[i].type << endl;
        file << selectedv[i].status << endl;
        file << selectedv[i].price << endl;
        file << selectedv[i].numofpages << endl;
        file << selectedv[i].review << endl;
        file << selectedv[i].quantity << endl;
    }
    file << "##";
    file.close();
}

void file_management::file_to_vector(string selectedFile, vector<Book>& selectedv, int size)
{
    string line;
    int index;

    ifstream file(selectedFile);

    if (file.is_open()) {
        selectedv.resize(size); // Ensure the vector is resized to the correct size
        for (int i = 0; i < size; i++) {
            index = 0;
            while (getline(file, line)) {
                if (index == 0)         selectedv[i].title = line;
                else if (index == 1)    selectedv[i].author = line;
                else if (index == 2)    selectedv[i].description = line;
                else if (index == 3)    selectedv[i].type = line;
                else if (index == 4)    selectedv[i].status = line;
                else if (index == 5)    selectedv[i].price = line;
                else if (index == 6)    selectedv[i].numofpages = line;
                else if (index == 7)    selectedv[i].review = line;
                else if (index == 8)    selectedv[i].quantity = line;
                index++;
                if (line == "##") { break; }
                if (index == 9)    break;
            }
        }
    }
    file.close();
}


void file_management::files_to_vectors(){

    file_management::file_to_vector("fantasy.txt",file_management::fantasy,file_management::fantasy_size);
    file_management::file_to_vector("romance.txt", file_management::romance, file_management::romance_size);
    file_management::file_to_vector("non_fiction.txt", file_management::non_fiction, file_management::non_fiction_size);
    file_management::file_to_vector("science_fiction.txt", file_management::science_fiction, file_management::science_fiction_size);
    file_management::file_to_vector("mystery.txt", file_management::mystery, file_management::mystery_size);
}

void file_management::vectors_to_files()
{
    file_management::vector_to_file("fantasy.txt", file_management::fantasy);
    file_management::vector_to_file("romance.txt", file_management::romance);
    file_management::vector_to_file("non_fiction.txt", file_management::non_fiction);
    file_management::vector_to_file("science_fiction.txt", file_management::science_fiction);
    file_management::vector_to_file("mystery.txt", file_management::mystery);
}

void file_management::file_to_sizes() {
    ifstream file("bookssize.txt");
    int i = 0;
    string line;
    while (getline(file, line))
    {
        if (i == 0) { fantasy_size = stoi(line); }
        else if (i == 1) { mystery_size = stoi(line); }
        else if (i == 2) { romance_size = stoi(line); }
        else if (i == 3) { non_fiction_size = stoi(line); }
        else if (i == 4) { science_fiction_size = stoi(line); }
        i++;
    }

    file.close();
}

void file_management::sizes_to_file()
{
    ofstream file("bookssize.txt");
    file << file_management::fantasy.size() << endl << file_management::mystery.size() << endl << file_management::romance.size() << endl;
    file << file_management::non_fiction.size() << endl << file_management::science_fiction.size() << endl;
    file.close();
}

void file_management::file_to_users()
{
    string userType, user_name, password_;
    ifstream read("users.txt");

    if (read.is_open()) {
        while (getline(read, userType)) {
            User newUser;
            getline(read, user_name);
            getline(read, password_);
            newUser.usertype = userType;
            newUser.username = user_name;
            newUser.password = password_;
            file_management::users.push_back(newUser);
        }
    }

    read.close();
}

void file_management::users_to_file()
{
    ofstream read("users.txt");
    for (int i = 0; i < file_management::users.size(); i++) {
        read << file_management::users[i].usertype << endl << file_management::users[i].username << endl << file_management::users[i].password << endl;
    }
}