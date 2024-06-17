#pragma once
#include"Employ.h"
#include"WareHouse.h"
#include "_File.h"
#include <iostream>

using namespace std;

class Storekeeper : public Employ
{
	WareHouse stock;
	void Method(WareHouse& stock) {
		_File file;
		if (file.Open("Products.txt", "")) {
			Product* products = file.GetProducts();
			for (int i = 0; i < 10; i++) {
				stock.AddProduct(products[i].name, products[i].price, products[i].count);
			}
			stock.PrintProduct();
		}
	}
public:

	Storekeeper(string name, string lastname, string post, double payment) : Employ(name, lastname, post, payment) {
		Method(stock);
	};
	//Обращаение к складу на наличие товара
	Product* GetProduct(string name, int num) {
		return stock.GetProduct(name, num);
	}

};

