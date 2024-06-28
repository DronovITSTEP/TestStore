#pragma once
#include <iostream>
#include <vector>

using namespace std;

struct Product {
	string name;
	float price;
	int count = 0;
};
//int Product::id = 0;

struct Basket {
	vector<Product*> products;
	unsigned int quantity;
	float price_order;
};