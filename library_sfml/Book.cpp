#include "Book.h"

Book::Book(string _title, string _author, string _description, string _type, string _status, double _price, int _numofpages, string _review, int _quantity)
{
		title = _title;
		author = _author;
		description = _description;
		genre = _type;
		price = _price;
		numofpages = _numofpages;
		review = _review;
		quantity = _quantity;
}
// Default constructor
Book::Book() {

}

readersbooks::readersbooks()
{
}

readersbooks::readersbooks(string name, string username, float cost, int quantity)
{
	this->username = username;
	this->price = quantity;
	title = name;
	price = cost;
}
