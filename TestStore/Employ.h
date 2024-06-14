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
	Employ(string name, string lastname, string post, double payment) {
		name = name;
		lastname = lastname;
		post = post;
		payment = payment;
	}

	//виртуальный образ основного действия класса
	virtual Product GetProduct(string name, int num) = 0;
};

