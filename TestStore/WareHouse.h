#pragma once
#include <iostream>
#include <iomanip>
#include "Tovar.h"

using namespace std;



class WareHouse {

	struct ListProducts {
		Product* p;
		ListProducts* next;
	};

	ListProducts* listProducts = nullptr;
	ListProducts* delListProduct = nullptr;

public:
	Product* GetProduct(string name, int count) {

		cout << "Получить со склада товар " << name << " в количестве "
			<< count << endl;

		ListProducts* getProduct = listProducts;
		Product* returnProduct;

		while (getProduct != nullptr && getProduct->p->name != name) {
			getProduct = getProduct->next;
		}

		if (getProduct != nullptr && getProduct->p->name == name) {
			if (getProduct->p->count > count)
			{
				returnProduct = new Product(getProduct->p->name,
					getProduct->p->price, count);
				getProduct->p->count -= count;
			}
			else
			{
				returnProduct = new Product(getProduct->p->name,
					getProduct->p->price, getProduct->p->count);
				getProduct->p->count = 0;
			}

			if (getProduct->p->count == 0) DelProduct(getProduct->p->name,
				getProduct->p->price);

		}
		else {
			cout << "Товара " << name << " нет на складе " << endl;	
			return nullptr;
		}
	
	}
	
	void AddProduct(string name, double price, int count) {
		// Ищем товар с указанным именем в списке
		ListProducts* newProduct = new ListProducts;
		newProduct->p = new Product(name, price, count);
		newProduct->next = nullptr;	
		
		if (listProducts == nullptr) {
			listProducts = newProduct;
			return;
		}

		ListProducts* current = listProducts;
		while (current != nullptr && current->next != nullptr) {
			if (current->p->name == name) break;
			current = current->next;
		}
		if (current->p->name == name) current->p->count += count;
		else current->next = newProduct;
	}

	void DelProduct(string name, int count) {
		ListProducts* currentActiv = listProducts;
		ListProducts* prevActiv = listProducts;
		ListProducts* currentDel = delListProduct;

		while (currentActiv->p->name != name)
		{
			prevActiv = currentActiv;
			currentActiv = currentActiv->next;
		}

		if (currentDel == nullptr) {
			prevActiv->next = currentActiv->next;
			currentDel = currentActiv;
			currentActiv->next = nullptr;
		}
		else {
			while (currentDel->next != nullptr)
			{
				currentDel = currentDel->next;
			}
			prevActiv->next = currentActiv->next;
			currentDel->next = currentActiv;
			currentActiv->next = nullptr;
		}
	}
	void PrintProduct() {
		ListProducts* current = listProducts;
		while (current != nullptr && current != delListProduct) {
			cout << "Товар: " << current->p->name << " "
				<< "Цена: " << fixed << setprecision(2) << current->p->price << "  "
				<< "Количество: " << current->p->count << endl;
			current = current->next;
		}
		cout << endl;
		if (delListProduct != nullptr) {
			ListProducts* missing = delListProduct;
			cout << "Товары, отсутствующие на складе = >" << endl;
			while (missing != nullptr) {
				cout << "Товар: " << missing->p->name << " "
					<< "Цена: " << fixed << setprecision(2) << missing->p->price << endl;
				missing = missing->next;
			}

		}
	}

	
};

