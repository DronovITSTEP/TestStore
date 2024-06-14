#pragma once
#include"Storekeeper.h"
#include <iostream>

using namespace std;

class Seller : public Employ
{
	Storekeeper storekeeper{ "a", "b", "c", 1 };
public:
	Seller(string name, string lastname, string post, double payment) : Employ(name, lastname, post, payment) {}
	//��������� � ������ ������ "Storekeeper"
	Product GetProduct(Product* name) {
		return storekeeper.GetProduct(name);
	}
};
