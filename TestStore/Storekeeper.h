#pragma once
#include"Employ.h"
#include"WareHouse.h"
#include "_File.h"
#include <iostream>

using namespace std;

class Storekeeper : public Employ
{
	_File f;
	WareHouse w;
public:

	Storekeeper(string name, string lastname, string post, double payment) : Employ(name, lastname, post, payment) {
	f.Open("Products.txt");
	vector<Product*> prod = f.GetProducts();
	for (auto p : prod) {
		//cout << p->name << " " << p->count  << " " << p->price << endl;
		w.AddProduct(p->name, p->price, p->count);
		w.AddProduct(p->name, p->price, p->count);
	}
	w.PrintProduct();
	};
	//Обращаение к складу на наличие товара
	Product* GetProduct(string name, int num) {
		return w.GetProduct(name, num);
	}
};

