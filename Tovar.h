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
private: Basket* ptr_Basket;
	   Basket* ptr_head;
	   Basket* ptr_next;
	   Basket* ptr_prev;
	   Basket* ptr_tail;
public:
	Product product;
	unsigned int quantity;
	float price_order;

};