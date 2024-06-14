#pragma once
#include"Employ.h"
#include <iostream>

using namespace std;

class Storekeeper : public Employ
{
	Warehouse store;
public:

	Storekeeper(string name, string lastname, string post, double payment) : Employ(name, lastname, post, payment) {};
	//Обращаение к складу на наличие товара
	Product GetProduct(Product* name) {
		return store.GetProduct(name);
	}

};

