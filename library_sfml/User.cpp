#include "User.h"

float User::calculateTotalPrice()
{
	float price = 0;
	for (int i = 0; i < cart_vector.size(); i++) {
		totalPrice += cart_vector[i].second;
	}
	return price;
}
