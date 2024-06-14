#pragma once
#include"Storekeeper.h"
#include <iostream>

using namespace std;

class Seller : public Employ
{
	Storekeeper storekeeper{ "Petr", "Akimov", "storekeeper", 25500 };
public:
	Seller(string name, string lastname, string post, double payment) : Employ(name, lastname, post, payment) {}
	//Обращение к методу класса "Storekeeper"
	Product GetProduct(string name, int num) {
		return storekeeper.GetProduct(name, num);
	}
};
