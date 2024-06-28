#include <iostream>
#include "Employ.h"
#include "Seller.h"
#include "Storekeeper.h"
#include "Cashier.h"
#include "Customer.h"
#include "WareHouse.h"
#include "Tovar.h"
#include "_File.h"



enum Eployees { SELLER, STOREKEEPER, CASHIER };

int main()
{
	setlocale(LC_ALL, "");

	Customer customer{ "Ivan", "Ivanov", "ivan@ivanov.ru", "899997777", 12400 };
	Employ* empl[3]{
		new Seller("Petr", "Petrov", "Saler", 47555),
	new Storekeeper("Sidr", "Sidorov", "Storekeeper", 36500),
	new Cashier("Elena", "Elenova","Dou", 60000)
	};
	try {
		customer.AddToBasket(empl[SELLER]->GetProduct("Meat", 2));
		customer.AddToBasket(empl[SELLER]->GetProduct("Bread", 1));
		customer.AddToBasket(empl[SELLER]->GetProduct("Orange", 4));
	}
	catch (exception e) {
		cout << e.what();
	}

	float totalPrice = (dynamic_cast<Cashier*>(empl[CASHIER]))->GetTotalPrice(customer.GetBusket(),
		customer.getDiscount());
	if ((dynamic_cast<Cashier*>(empl[CASHIER]))->Pay(customer.GetCash(totalPrice))) {
		cout << "Ok";
	}
	else cout << "Not Ok";
}
