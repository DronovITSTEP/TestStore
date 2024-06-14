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
		
		while (getProduct != nullptr && getProduct->p->name != name) {
			getProduct = getProduct->next;
		}
		
		if (getProduct != delListProduct) {

		if (getProduct != nullptr && getProduct->p->count >= count) {
			//getProduct->p->count -= count;
			
			DelProduct(getProduct->p->name, count);
			
			/*if (getProduct->p->count = 0) {
				DelListProducts(getProduct->p->name, getProduct->p->price, 0);
			}*/
			
			return getProduct->p;
		}
		else {
			cout << "Товара " << name << " в наличии на складе меньше, чем заявлено к получению." << endl
				<< "Желаете получить весь товар, имеющийся в наличии? y/n => ";
			char choice;
			cin >> choice;
			if(choice == 'y') {
				if (getProduct != nullptr) {
					count = getProduct->p->count;
					DelProduct(getProduct->p->name, count);
					
					return getProduct->p;
				}
			}
			else if (choice == 'n') {

				return nullptr;
			}
		}
		//return (getProduct != nullptr && getProduct->p->count != 0) ? getProduct->p : nullptr;
		}
		else {
			cout << "Товар " << getProduct->p->name << " уже отсутствует в наличии." << endl;
		}
		
	}

	//// продукт на складе закончился, добавляем в список отсутствующих
	//void DelListProducts(string name, double price, int count) {
	//	ListProducts* delListProduct = new ListProducts;
	//	delListProduct->p = new Product(name, price, count);
	//	delListProduct->next = nullptr;
	//}
	
	void AddProduct(string name, double price, int count) {
		// Ищем товар с указанным именем в списке
		ListProducts* current = listProducts;
		ListProducts* prev = nullptr;

		while (current != nullptr && current->p->name != name) {
			prev = current;
			current = current->next;
		}

		if (current != nullptr) {
			// Товар с указанным именем уже существует, увеличиваем количество
			current->p->count += count;
			cout << "Количество товара " << current->p->name << " увеличено на " << count << " штук." << endl;
		}
		else {
			// Товар с указанным именем не найден, добавляем новый товар
			ListProducts* newProduct = new ListProducts;
			newProduct->p = new Product(name, price, count);
			newProduct->next = nullptr;
			//listProducts = newProduct; 

			if (prev != nullptr) {
				// Вставляем новый товар после найденного товара
				prev->next = newProduct;
			}
			else {
				// Если нет предыдущего товара, добавляем в начало списка
				listProducts = newProduct;
			}

			cout << "Товар " << name << " добавлен в список." << endl;
		}
	}
	ListProducts* DelProduct(string name, int count) {
		ListProducts* current = listProducts;
		while (current != nullptr && current->p->name != name) {
			current = current->next;
		}
		if (current != nullptr || current != delListProduct) {
			// Найден товар с указанным именем, уменьшаем количество
			if (current->p->count > count) {
				current->p->count -= count;
				cout << "Количество товара " << current->p->name << " уменьшено на "
					<< count << endl;
			}
			else if (current->p->count == count) {
				cout << "Вы получили весь товар, имеющийся на складе" << endl;
				delListProduct = current;
				current = current->next;
				return delListProduct;
			}
			else {
					cout << "Товар " << current->p->name << " уже отсутствует в наличии." << endl;
					delListProduct = current;
					return delListProduct;
				}
		}
		else {
			cout << "Товар с именем " << name << " не найден." << endl;
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

