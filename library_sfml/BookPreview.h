#pragma once
#include "Materials.h"
#include "Book.h"
#include "ScrollableView.h"
#include "navbar.h"
#include <string>
#include <vector>
using namespace std;

class BookPreview {
public:
    photos image;
    string bookName, path;
    BookPreview();
    BookPreview(Book& book, string photoPath, float posx, float posy);
    static void booksDraw(RenderWindow& window, BookPreview& book);
};

class Books_page {
public:
    static texts title;
    static bool isBookspageVisible;
    static vector<BookPreview*> BookPreviewVector;
    static float posy;
    static void enableScrolling();
    static void drawBooksPage(RenderWindow& window, vector<Book> genre, string genreName);
    static void genreSelection(RenderWindow& window);
    static bool isFantasyClicked;
    static bool isMysteryClicked;
    static bool isScifiClicked;
    static bool isNonfictionClicked;
    static bool isRomanceClicked;
    // Destructor to manage memory
    ~Books_page();
};