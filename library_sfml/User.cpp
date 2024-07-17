#include "User.h"

void User::calculateTotalPrice()
{
	float price = 0;
	for (int i = 0; i < cart_vector.size(); i++) {
		totalPrice += stoi(cart_vector[i].price);
	}
	

}
