#pragma once
#include<iostream>
#include "Tovar.h"
using namespace std;

class Employ
{
protected:
	string name;
	string lastname;
	string post;
	double payment;

public:
	//инициализация сотрудника
	Employ(string a, string b, string c, double i) {
		name = a;
		lastname = b;
		post = c;
		payment = i;
	}

	//виртуальный образ основного действия класса
	virtual Product GetProduct(Product* name) = 0;
};

