#include "User.h"

float User::calculateTotalPrice()
{
	float price = 0;
	for (int i = 0; i < cart_vector.size(); i++) {
		totalPrice += stof(cart_vector[i].price);
	}
	return price;
}
