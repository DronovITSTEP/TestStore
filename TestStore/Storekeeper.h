#pragma once
#include"Employ.h"
#include"WareHouse.h"
#include <iostream>

using namespace std;

class Storekeeper : public Employ
{
	WareHouse store;
public:

	Storekeeper(string name, string lastname, string post, double payment) : Employ(name, lastname, post, payment) {};
	//���������� � ������ �� ������� ������
	Product GetProduct(Product* name) {
		return store.GetProduct(name);
	}

};

