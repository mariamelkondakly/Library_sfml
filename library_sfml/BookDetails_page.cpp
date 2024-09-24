#include "BookDetails_page.h"
photos* BookDetails_page::bookCover;
texts BookDetails_page::bookTitle; 
texts BookDetails_page::description;
texts BookDetails_page::rating; 
texts BookDetails_page::authorName; 
texts BookDetails_page::amountAvailable; 
texts BookDetails_page::cost;
texts BookDetails_page::warning;
TextField BookDetails_page::quantity;
buttons BookDetails_page::AddToCart, BookDetails_page::GoBack;
bool BookDetails_page::isBookDetailsVisible=false;
bool BookDetails_page::isWarningVisible = false;
bool drawField = false;
BookDetails_page::BookDetails_page(){}

//TODO: enable the quantity textfield to accept data, 
//check on cart click if the field is empty and if so display a new warning saying so.

void BookDetails_page::enableScrolling() {
	Scrollable::setLowerBound(AddToCart.button.getPosition().y + AddToCart.button.getScale().y + 300);
}

Book BookDetails_page::setBookDetails_page(map<string, Book> genre) {
	Book book;
	isBookDetailsVisible = false;
	book = genre[file_management::selectedBook];
	string desc=description.wrapText(book.description, 1000);
	bookCover = new photos(book.path, 100, 200, 0.75, 0.75);
	bookTitle = texts(700, 200, book.title, 't', colors::title);
	authorName = texts(700, 350, book.author, 'n', colors::warning);
	description = texts(700, 450,desc , 'w', colors::ntexts);
	FloatRect descriptionBounds = description.text.getGlobalBounds();
	float desEnd = descriptionBounds.top + descriptionBounds.height;
	rating = texts(300, 1000, book.review, 'n', colors::success);
	quantity = TextField(700, desEnd + 120);
	String amountAvailableText;
	if (book.isAvailable) {
		drawField = true;
		isWarningVisible = false;
		amountAvailableText = to_string(book.quantity) + " of the book available.";
		cost = texts(700, desEnd + 210, "Cost per book: " + to_string(book.price) + "$", 'n', colors::success);
		AddToCart = buttons(1000, desEnd + 320, "Add to cart", false);
		GoBack = buttons(700, desEnd + 320, "Go Back", false);
	}
	else {
		drawField = false;
		amountAvailableText = "This book isn't available now.";
		cost = texts(700, desEnd + 140, "Cost per book: " + to_string(book.price) + "$", 'n', colors::success);
		AddToCart = buttons(1000, desEnd + 260, "Add to cart", false);
		GoBack = buttons(700, desEnd + 260, "Go Back", false);
		warning = texts(700, desEnd+360, "Unfortunatley, the book is currently unavailable", 'w', colors::warning);

		             
	}
	amountAvailable = texts(700, desEnd + 40,amountAvailableText, 'n', colors::ntexts);
	return book;
}

void BookDetails_page::onAddToCartClicked(Vector2f pos,map<string, Book> genre)
{
	if (AddToCart.button.getGlobalBounds().contains(pos)&& genre[file_management::selectedBook].isAvailable) {
		readersbooks book(genre[file_management::selectedBook].title, file_management::selectedUser, (float)genre[file_management::selectedBook].price,stoi(quantity.data));
		file_management::users[file_management::selectedUser].cart_vector.push_back(book);
		BookDetails_page::isBookDetailsVisible = false;
		Cart_page::isCartVisible = true;
		isWarningVisible = false;

		
	}
	else if (AddToCart.button.getGlobalBounds().contains(pos) && !genre[file_management::selectedBook].isAvailable) {
		isWarningVisible = true;
	}
}
void BookDetails_page::onGoBackClicked(Vector2f pos, map<string, Book> genre)
{
	if (GoBack.button.getGlobalBounds().contains(pos)) {
		BookDetails_page::isBookDetailsVisible = false;
		Books_page::isBookspageVisible = true;
		isWarningVisible = false;
	}
}
void BookDetails_page::drawBookDetailspage(RenderWindow& window) {
    if (file_management::users[file_management::selectedUser].isAdmin) {
        navbar::adminNavDraw(window, false);
    }
    else {
        navbar::readerNavDraw(window, false);
    }
	if (drawField) {
		quantity.fieldDraw(window);
	}

    window.draw(bookCover->pic);
    AddToCart.buttonDraw(window);
    GoBack.buttonDraw(window);
    window.draw(bookTitle.text);
    window.draw(description.text);
    window.draw(cost.text);
    window.draw(authorName.text);
    window.draw(rating.text);
	window.draw(amountAvailable.text);
	if (isWarningVisible) {		window.draw(warning.text);}
	//window.draw(type.text);

}

