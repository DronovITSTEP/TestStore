#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include "Tovar.h"

using namespace std;

class WareHouse {
	vector<Product*> addProducts;
	vector<Product*> deleteProducts;


public:
	Product* GetProduct(string name, int count) {

		cout << "Получить со склада товар " << name << " в количестве "
			<< count << endl;
		Product* getProd = new Product();

		vector<Product*>::iterator iter;
		iter = find_if(addProducts.begin(), addProducts.end(), 
			[name](Product* p){
				return p->name == name; 
			});
		if (iter != addProducts.end())
		{
			if ((*iter)->count > count)
			{
				getProd->count = count;
				(*iter)->count -= count;
			}
			else
			{
				getProd->count = (*iter)->count;
				(*iter)->count = 0;
				DelProduct(name);
			}

			getProd->name = name;
			return getProd;
		}
		throw runtime_error("Нет товара. " + name);
	
	}
	
	void AddProduct(string name, float price, int count) {
		vector<Product*>::iterator addIter = 
			find_if(addProducts.begin(), addProducts.end(),
				[name](Product* p) {return p->name == name; });
		vector<Product*>::iterator delIter =
			find_if(deleteProducts.begin(), deleteProducts.end(),
				[name](Product* p) {return p->name == name; });

		if (delIter != deleteProducts.end()) deleteProducts.erase(delIter);

		if (addIter == addProducts.end())
			addProducts.push_back(new Product{
				name,
				price,
				count
				});
		else
			(*addIter)->count += count;
	}

	void DelProduct(string name) {
		vector<Product*>::iterator iter =
			find_if(addProducts.begin(), addProducts.end(),
				[name](Product* p) {return p->name == name; });
		if (iter != addProducts.end()) {
			deleteProducts.push_back(*iter);
			addProducts.erase(iter);
		}
	}
	void PrintProduct() {
		for (auto prod : addProducts)
			cout << "Товар: " << prod->name << " "
				<< "Цена: " << fixed << setprecision(2) << prod->price << "  "
				<< "Количество: " << prod->count << endl;		
	}	
};

