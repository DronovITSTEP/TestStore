#pragma once
#include <iostream>

using namespace std;

struct Product {
	int id = 0;
	string name;
	float price;
	int count = 0;
	
};
//int Product::id = 0;

struct Basket {
public: Basket* next;
		int idBasket;
	   	Product* product;
		unsigned int quantity;
		float price_order;
};