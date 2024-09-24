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

Connection* file_management::initConnection()
{
    mysql::MySQL_Driver* driver;
    Connection* con;

    driver = mysql::get_mysql_driver_instance();
    con = driver->connect("tcp://127.0.0.1:3306", "root", "Mariam2004");
    con->setSchema("library_management_system");

    return con;
}


void file_management::loadUsersFromDataBase(sql::Connection* con) {
    users.clear();
    string queryAllUsers = "SELECT * From users";
    unique_ptr<PreparedStatement> pstmt(con->prepareStatement(queryAllUsers));
    unique_ptr<sql::ResultSet> res(pstmt->executeQuery());

    while (res->next()) {
        User user;
        user.username= res->getString("username");
        user.isAdmin = res->getBoolean("isAdmin");
        user.password = res->getString("password");
        user.totalPrice = res->getDouble("totalPrice");
        loadReadersBooksFromDataBase(con, user);
        users[user.username] = user;
    }
}

void file_management::loadReadersBooksFromDataBase(sql::Connection* con, User& user) {
    user.boughtBooks.clear();
    user.cart_vector.clear();

    string queryAllBooks = "SELECT * FROM readersbooks WHERE username = ?";
    unique_ptr<PreparedStatement> pstmt(con->prepareStatement(queryAllBooks));

    // Set the username parameter before executing the query
    pstmt->setString(1, user.username);

    unique_ptr<sql::ResultSet> res(pstmt->executeQuery());

    while (res->next()) {
        readersbooks book;
        book.quantity = res->getDouble("amount");
        book.username = res->getString("username");
        book.title = res->getString("title");
        book.price = res->getDouble("totalPrice");

        if (res->getBoolean("is_cart") == true) {
            user.cart_vector.push_back(book);
        }
        else {
            user.boughtBooks.push_back(book);
        }
    }
}


void file_management::saveReadersBooksToDatabase(sql::Connection* con, User user) {
    std::unique_ptr<sql::PreparedStatement> pstmt(con->prepareStatement(
        "REPLACE INTO readersbooks (title, username, amount,totalPrice, is_cart) VALUES (?, ?, ?, ?, ?)"));

    for (const auto& books : user.boughtBooks) {
        const readersbooks& book = books;
        pstmt->setString(1, book.title);
        pstmt->setString(2, book.username);
        pstmt->setDouble(3, book.quantity);
        pstmt->setDouble(4, book.price);
        pstmt->setBoolean(5, false);

        pstmt->execute();
       
    }

    for (const auto& books : user.cart_vector) {
        const readersbooks& book = books;
        pstmt->setString(1, book.title);
        pstmt->setString(2, book.username);
        pstmt->setDouble(3, book.quantity);
        pstmt->setDouble(4, book.price);
        pstmt->setBoolean(5, true);

        pstmt->execute();
    }
}

void file_management::saveUsersIntoDatabase(sql::Connection* con) {
    std::unique_ptr<sql::PreparedStatement> pstmt(con->prepareStatement(
        "REPLACE INTO users (username, password, totalPrice, isAdmin) VALUES (?, ?, ?, ?)"));
    for (const auto& pair : users) {
        const User& user = pair.second;
        pstmt->setString(1, user.username);
        pstmt->setString(2, user.password);
        pstmt->setDouble(3, user.totalPrice);
        pstmt->setBoolean(4, user.isAdmin);
        saveReadersBooksToDatabase(con, user);
        pstmt->execute();
    }
}

void file_management::loadBooksFromDatabase(sql::Connection* con, string genre, map<string, Book>& map) {

    map.clear();

 string queryByGenre = "SELECT * FROM Books WHERE genre = ?";

 if (con == nullptr) {
     std::cerr << "Error: Connection object is null in getMapsFromDatabase." << std::endl;
     return;
 }

 unique_ptr<sql::PreparedStatement> pstmt(
     con->prepareStatement(queryByGenre));
 pstmt->setString(1, genre);  
unique_ptr<sql::ResultSet> res(pstmt->executeQuery());


    while (res->next()) {
        Book book;
        book.title = res->getString("title");
        book.author = res->getString("author");
        book.description = res->getString("description");
        book.genre = res->getString("genre");
        book.price = res->getDouble("price");
        book.numofpages = res->getInt("numofpages");
        book.review = res->getString("review");
        book.quantity = res->getInt("quantity");
        book.path = res->getString("path");
        book.isAvailable = res->getBoolean("isAvailable");

        map[book.title] = book;
    }
}
void file_management::saveBooksToDatabase(sql::Connection * con, map<string, Book>&selectedm) {
    std::unique_ptr<sql::PreparedStatement> pstmt(con->prepareStatement(
        "REPLACE INTO Books (title, author, description, genre, price, numofpages, review, quantity, path, isAvailable) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?)"));

    for (const auto& pair : selectedm) {
        const Book& book = pair.second;
        pstmt->setString(1, book.title);
        pstmt->setString(2, book.author);
        pstmt->setString(3, book.description);
        pstmt->setString(4, book.genre);
        pstmt->setDouble(5, book.price);
        pstmt->setInt(6, book.numofpages);
        pstmt->setString(7, book.review);
        pstmt->setInt(8, book.quantity);
        pstmt->setString(9, book.path);
        pstmt->setBoolean(10, book.isAvailable);

        pstmt->execute();
    }
}
void file_management::saveMapsToDatabase(sql::Connection* con) {
    saveBooksToDatabase(con, fantasy);
    saveBooksToDatabase(con, mystery);
    saveBooksToDatabase(con, non_fiction);
    saveBooksToDatabase(con, science_fiction);
    saveBooksToDatabase(con, romance);
}
void file_management::getMapsFromDatabase(sql::Connection* con) {
    try {
        loadBooksFromDatabase(con, "fantasy", fantasy);
    }
    catch (sql::SQLException& e) {
        std::cerr << "Error loading fantasy books: " << e.what() << std::endl;
    }

    try {
        loadBooksFromDatabase(con, "mystery", mystery);
    }
    catch (sql::SQLException& e) {
        std::cerr << "Error loading mystery books: " << e.what() << std::endl;
    }

    try {
        loadBooksFromDatabase(con, "non_fiction", non_fiction);
    }
    catch (sql::SQLException& e) {
        std::cerr << "Error loading non-fiction books: " << e.what() << std::endl;
    }

    try {
        loadBooksFromDatabase(con, "romance", romance);
    }
    catch (sql::SQLException& e) {
        std::cerr << "Error loading romance books: " << e.what() << std::endl;
    }

    try {
        loadBooksFromDatabase(con, "scifi", science_fiction);
    }
    catch (sql::SQLException& e) {
        std::cerr << "Error loading science fiction books: " << e.what() << std::endl;
    }
}




/*void file_management::map_to_file(const string& selectedFile, const map<string, Book>& selectedm) {
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
*/