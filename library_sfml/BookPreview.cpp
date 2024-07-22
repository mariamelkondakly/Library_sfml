#include "BookPreview.h"

texts Books_page::title(200, 100, "The books you experienced", 't', colors::title);
float Books_page::posy;
bool Books_page::isBookspageVisible = false;
vector<BookPreview*> Books_page::BookPreviewVector;
bool Books_page::isFantasyClicked = false;
bool Books_page::isMysteryClicked = false;
bool Books_page::isScifiClicked = false;
bool Books_page::isNonfictionClicked = false;
bool Books_page::isRomanceClicked = false;

BookPreview::BookPreview() {
    bookName = "";
}

BookPreview::BookPreview(Book& book, float posx, float posy) :
    image(book.path, posx, posy, 0.5, 0.5), bookName(book.title) {
}

void Books_page::enableScrolling() {
    Scrollable::setLowerBound(posy + 500);
}

void BookPreview::booksDraw(RenderWindow& window, BookPreview& book) {
    window.draw(book.image.pic);
}

void Books_page::drawBooksPage(RenderWindow& window, vector<Book> genre) {

    // Clear existing BookPreview pointers
    for (BookPreview* bookPreview : BookPreviewVector) {
        delete bookPreview;
    }
    BookPreviewVector.clear();

    float posx;
    int counter = 1;
    posy = 300;

    for (int i = 0; i < 3; i++) {
        posx = 150;
        for (int j = 0; j < 4 && counter <= genre.size(); j++) {
            BookPreview* book = new BookPreview(genre[counter - 1], posx, posy);
            BookPreviewVector.push_back(book);

            posx += 400;
            counter++;
        }
        posy += 600;
    }

    if (file_management::selectedUser.usertype == "Admin") {
        navbar::adminNavDraw(window, false);
    }
    else {
        navbar::readerNavDraw(window, false);
    }

    for (BookPreview* bookPreview : BookPreviewVector) {
        BookPreview::booksDraw(window, *bookPreview);
    }
    window.draw(title.text);

}

void Books_page::genreSelection(RenderWindow& window)
{
    if (Books_page::isFantasyClicked) {
        Books_page::drawBooksPage(window, file_management::fantasy);
    }
    else if (Books_page::isMysteryClicked) {
        Books_page::drawBooksPage(window, file_management::mystery);
    }
    else if (Books_page::isNonfictionClicked) {
        Books_page::drawBooksPage(window, file_management::non_fiction);
    }
    else if (Books_page::isScifiClicked) {
        Books_page::drawBooksPage(window, file_management::science_fiction);
    }
    else if (Books_page::isRomanceClicked) {
        Books_page::drawBooksPage(window, file_management::romance);
    }
}

void Books_page::BookSelected(Vector2f pos, vector<Book>genre)
{
    Book BookToBeReturned;
    for (int i = 0; i < BookPreviewVector.size(); i++) {
        if (BookPreviewVector[i]->image.pic.getGlobalBounds().contains(pos)) {
            file_management::selectedBook = BookPreviewVector[i]->bookName;
        }
    }
    BookDetails_page::setBookDetails_page(Books_page::selectGenre());
    Books_page::isBookspageVisible = false;
    BookDetails_page::isBookDetailsVisible = true;
}

vector<Book> Books_page::selectGenre() {
    if (isFantasyClicked) {
        return file_management::fantasy;
    }
    else if (isMysteryClicked) {
        return file_management::mystery;
    }
    else if (isScifiClicked) {
        return file_management::science_fiction;
    }
    else if (isRomanceClicked) {
        return file_management::romance;
    }
    else if (isNonfictionClicked) {
        return file_management::non_fiction;
    }
}

// Destructor to manage memory
Books_page::~Books_page() {
    for (BookPreview* bookPreview : BookPreviewVector) {
        delete bookPreview;
    }
}
