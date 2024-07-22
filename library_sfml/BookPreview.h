#pragma once
#include "Materials.h"
#include "Book.h"
#include "ScrollableView.h"
#include "navbar.h"
#include "book.h"
#include <string>
#include <vector>
#include "BookDetails_page.h"
using namespace std;

class BookPreview {
public:
    photos image;
    string bookName;
    BookPreview();
    BookPreview(Book& book, float posx, float posy);
    static void booksDraw(RenderWindow& window, BookPreview& book);
};

class Books_page {
public:
    static texts title;
    static bool isBookspageVisible;
    static vector<BookPreview*> BookPreviewVector;
    static float posy;
    static void enableScrolling();
    static void drawBooksPage(RenderWindow& window, vector<Book> genre);
    static void genreSelection(RenderWindow& window);
    static void BookSelected(Vector2f pos, vector<Book> genre);
    static bool isFantasyClicked;
    static bool isMysteryClicked;
    static bool isScifiClicked;
    static bool isNonfictionClicked;
    static bool isRomanceClicked;
    static vector<Book> selectGenre();
    // Destructor to manage memory
    ~Books_page();
};