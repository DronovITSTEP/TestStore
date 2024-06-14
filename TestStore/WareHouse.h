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

		cout << "�������� �� ������ ����� " << name << " � ���������� "
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
			cout << "������ " << name << " � ������� �� ������ ������, ��� �������� � ���������." << endl
				<< "������� �������� ���� �����, ��������� � �������? y/n => ";
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
			cout << "����� " << getProduct->p->name << " ��� ����������� � �������." << endl;
		}
		
	}

	//// ������� �� ������ ����������, ��������� � ������ �������������
	//void DelListProducts(string name, double price, int count) {
	//	ListProducts* delListProduct = new ListProducts;
	//	delListProduct->p = new Product(name, price, count);
	//	delListProduct->next = nullptr;
	//}
	
	void AddProduct(string name, double price, int count) {
		// ���� ����� � ��������� ������ � ������
		ListProducts* current = listProducts;
		ListProducts* prev = nullptr;

		while (current != nullptr && current->p->name != name) {
			prev = current;
			current = current->next;
		}

		if (current != nullptr) {
			// ����� � ��������� ������ ��� ����������, ����������� ����������
			current->p->count += count;
			cout << "���������� ������ " << current->p->name << " ��������� �� " << count << " ����." << endl;
		}
		else {
			// ����� � ��������� ������ �� ������, ��������� ����� �����
			ListProducts* newProduct = new ListProducts;
			newProduct->p = new Product(name, price, count);
			newProduct->next = nullptr;
			//listProducts = newProduct; 

			if (prev != nullptr) {
				// ��������� ����� ����� ����� ���������� ������
				prev->next = newProduct;
			}
			else {
				// ���� ��� ����������� ������, ��������� � ������ ������
				listProducts = newProduct;
			}

			cout << "����� " << name << " �������� � ������." << endl;
		}
	}
	ListProducts* DelProduct(string name, int count) {
		ListProducts* current = listProducts;
		while (current != nullptr && current->p->name != name) {
			current = current->next;
		}
		if (current != nullptr || current != delListProduct) {
			// ������ ����� � ��������� ������, ��������� ����������
			if (current->p->count > count) {
				current->p->count -= count;
				cout << "���������� ������ " << current->p->name << " ��������� �� "
					<< count << endl;
			}
			else if (current->p->count == count) {
				cout << "�� �������� ���� �����, ��������� �� ������" << endl;
				delListProduct = current;
				current = current->next;
				return delListProduct;
			}
			else {
					cout << "����� " << current->p->name << " ��� ����������� � �������." << endl;
					delListProduct = current;
					return delListProduct;
				}
		}
		else {
			cout << "����� � ������ " << name << " �� ������." << endl;
		}
	}
	void PrintProduct() {
		ListProducts* current = listProducts;
		while (current != nullptr && current != delListProduct) {
			cout << "�����: " << current->p->name << " "
				<< "����: " << fixed << setprecision(2) << current->p->price << "  "
				<< "����������: " << current->p->count << endl;
			current = current->next;
		}
		cout << endl;
		if (delListProduct != nullptr) {
			ListProducts* missing = delListProduct;
			cout << "������, ������������� �� ������ = >" << endl;
			while (missing != nullptr) {
				cout << "�����: " << missing->p->name << " "
					<< "����: " << fixed << setprecision(2) << missing->p->price << endl;
				missing = missing->next;
			}

		}
	}

	
};

