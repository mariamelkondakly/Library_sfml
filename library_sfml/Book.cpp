#include "Book.h"

Book::Book(string _title, string _author, string _description, string _type, string _status, string _price, string _numofpages, string _review, string _quantity)
{
		title = _title;
		author = _author;
		description = _description;
		type = _type;
		status = _status;
		price = _price;
		numofpages = _numofpages;
		review = _review;
		quantity = _quantity;
}
// Default constructor
Book::Book() {
}
