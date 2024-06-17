#pragma once
#include <iostream>
#include <sstream>
#include "Tovar.h"

using namespace std;


// ������ �� 0% �� 100%
	// ���� ����� ����� ������� �� 1000 ---> ������ 2%
	// ���� ����� ����� ������� �� 1000 �� 5000 �� ������ 5%
	// ���� ����� ����� ������� �� 5000 �� 10000 �� ������ 10%
	// ���� ����� ����� ������� �� 10000 �� 20000 � ����� ������ 20%
	// ���� ������ ��� VIP ��������

enum DiscountType {
	No_diskont = 0,
	�ustomer1000 = 2,
	�ustomer5000 = 5,
	�ustomer10000 = 10,
	�ustomer20000 = 20,
	VIP_CUSTOMER = 30
};

class Customer
{
private:
	Basket* head;
	Basket* tail;
	int last_idBasket;
	int idCount;
	float balance;
	float all_price_order;
	string name;
	string surname;
	string email;
	string phone;
	float discount;
	float all_order = 0; // ����� ������� ���������� (����� ��� ������� ������)
	
public:	
	// ����������� 
	Customer(string name, string surname, string email, string phone, float balance) :
		name{ name },
		surname{ surname },
		email{ email },
		phone{ phone },
		balance{ balance }
	{
		discount = No_diskont;
		all_price_order = 0;
		head = nullptr;
		tail = nullptr;
		last_idBasket = 0;
		Basket* ptr_basket = new Basket;
		//ptr_basket->quantity = 0;
		//ptr_basket->totalprice = 0;
		ptr_basket->product = nullptr;
		ptr_basket->idBasket = last_idBasket;
	}

	
	// �������
	string getName() const { return name; }
	string getSurname() const { return surname; }
	string getEmail() const { return email; }
	string getPhone() const { return phone; }

	float getDiscount() { return discount; }

	
	// �������
	void setName(string newName) { name = newName; }
	void setSurname(string surname) { name = surname; }
	void setEmail(string email) { name = email; }
	void setPhone(string phone) { name = phone; }


	/// <summary>
	/// ���������� ������� � ������� (��������� ���������) 
	/// </summary>
	/// <param name="id_product">id ������������</param>
	bool AddToBasket(Product* product_obj);

	/// <summary>
	/// ����������� �������� � �������
	/// </summary>
	/// <param name="delNode"></param>
	string displayBasketNode(Basket* dispNode);

	/// <summary>
	/// ����������� ���� ������� �������
	/// </summary>
	string displayBasket();

	/// <summary>
	/// ����� ������� � ������� �� id
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	Basket* searchIdBasket(int id);

	/// <summary>
	/// �������������� ��������� ������� � �������
	/// </summary>
	/// <param name="index"></param>
	bool EditBasket(int idBasket, Product*, int quantity);

	/// <summary>
	/// �������� ������� �� �������, ���������� 0 - ���� �� ������� �������(������� �� �������); 1 - ��������� ��������
	/// </summary>
	/// <param name="delNode"></param>
	bool RemovePos_FromBasket(int id);

	/// <summary>
	/// �������� �� ������� ���� �������, ���������� 0 - ���� �� ������� �������; 1 - ��������� ��������
	/// </summary>
	/// <param name="index"></param>
	void RemoveAllFromBasket();





	/// <summary>
	/// ���������� ����� ����� ������ (���������� ����� ����� ������, �������� total_dis - ����� � ������ ������)
	/// </summary>
	/// <returns></returns>
	float AllBasket_Price(float& total_dis);

	/// <summary>
	/// ����������� ������ ��� ����������
	/// </summary>
	double CalculateDiscount(string name);


	/// <summary>
	/// ����� ������, ���� ������� �������� (���� ������� ������ �� ������)
	/// �� �������� ��� ������� ������
	/// </summary>
	/// <param name="id_product"></param>
	/// <param name=""></param>
	/// <returns></returns>
	bool Byu();

	/// <summary>
	/// ����������� ����������
	/// </summary>
	string displayCustomer();

	/// <summary>
	/// ��������� ���� �������, �������� ���� ������ �� ������ �������
	/// </summary>
	/// <returns></returns>
	Basket* GetBusket();

	/// <summary>
	/// �������� ������� �� � ���������� �� ������� ���. ������� ��� ������ �������  ���� �� �������, �� ������������ ������ ������
	/// </summary>
	/// <param name="cash"></param>
	/// <returns></returns>
	float GetCash(float cash);
};


Customer::~Customer() {
	Basket* current = head;
	Basket* temp = nullptr;

	while (current != nullptr) {
		temp = current;
		current = current->next;
		delete temp;
	}
}

bool Customer::AddToBasket(Product* product_obj) {
	if (product_obj == nullptr) return 0;

	Basket* ptr_basket = new Basket;

	if (head == nullptr) {
		head = tail = ptr_basket;
		head->next = nullptr;
	}
	else {
		// ��������� ���� �� � ������� ��� ����������� ������� ���� ����, �� ��������� ������ ���-��
		Basket* temp = head;

		while (temp != nullptr) {
			if (temp->product->name == product_obj->name) {
				temp->product->count += product_obj->count;
				return 1;
			}
			temp = temp->next;
		}

		tail->next = ptr_basket;
		ptr_basket->next = nullptr;
		tail = ptr_basket;
	}


	ptr_basket->idBasket = last_idBasket;
	ptr_basket->product = product_obj;
	//ptr_basket->quantity = quantity;
	//ptr_basket->totalprice = ptr_basket->product->price * ptr_basket->quantity;
	last_idBasket++;
	return 1;

}


// ������� ����� ����� ������
float Customer::AllBasket_Price(float& total_dis) {
	float total = 0;
	Basket* temp = head;

	while (temp != nullptr) {
		//total += temp->product->price * temp->quantity; // ��� ����� ������
		//total_dis += temp->product->price * temp->quantity * ((100-(this->discount)) / 100.0); // � ������ ������;
		temp = temp->next;
	}

	return total;
}

// �������������� ������� � ������� �� idBasket 
bool Customer::EditBasket(int idBasket, Product* product_obj, int quantity) {
	Basket* temp = head;
	while (temp != nullptr) {
		if (temp->idBasket == idBasket) {
			temp->product = product_obj;
			//temp->quantity = quantity;
			//temp->totalprice = product_obj->price * quantity;
			return 1;
		}
		temp = temp->next;
	}
	return 0;
}

// �������� ������� �� �������
bool Customer::RemovePos_FromBasket(int id) {
	Basket* delbasket = searchIdBasket(id);
	if (head == nullptr) return 0;
	Basket* temp, * prev;
	temp = delbasket;
	prev = head;

	if (temp == prev) {
		head = head->next;
		if (tail == temp) {
			tail = tail->next;
		}
		delete temp;
	}
	else {
		while (prev->next != temp) {
			prev = prev->next;
		}
		prev->next = temp->next;
		if (tail == temp) {
			tail = prev;
		}
		delete temp;
	}
	return 0;
}


void Customer::RemoveAllFromBasket() {
	Basket* temp = head;
	while (temp != nullptr) {
		head = head->next;
		delete temp;
		temp = head;
	}

}


//����������� ������� � �������
string Customer::displayBasketNode(Basket* dispNode) {

	if (dispNode != nullptr) {
		stringstream ss;
		ss << "\033[0m" << "BasketId: " << "\033[1;31m" << dispNode->idBasket
			<< "\033[0m" << "; name product: " << "\033[1;31m" << dispNode->product->name
			<< "\033[0m" << "; price :" << "\033[1;31m" << dispNode->product->price
			//		<< "\033[0m" << "; quantity: " << "\033[1;31m" << dispNode->quantity 
			<< "\033[0m" << "; quantity: " << "\033[1;31m" << dispNode->product->quantity
			//		<< "\033[0m" << "; total price: " << "\033[1;31m" << dispNode->totalprice 
			<< "\033[0m" << endl;
		return ss.str();
	}
}

//����������� ���� ������� � ������� � �������� �������� �� ��������
string Customer::displayBasket() {
	Basket* temp = head;
	float total_dis = 0;
	string s_totalBasket;
	stringstream ss;
	ss << "\033[1;33mBasket: \033[0m";
	while (temp != nullptr) {
		s_totalBasket += " " + displayBasketNode(temp);
		temp = temp->next;
	}
	//	ss <<"\033[1;33mBusket total:\033[0m" << "\033[1;31m" << AllBasket_Price(total_dis) << "\033[0m" << "  " 
	//		 << "\033[1;33mwith diskount:\033[0m" << "\033[1;31m" << total_dis << "\033[0m" << endl;
	//s_totalBasket += " " + ss.str();
}

Basket* Customer::searchIdBasket(int id_Basket) {
	Basket* temp = head;
	while (temp->idBasket != id_Basket) {
		temp = temp->next;
		if (temp == nullptr) break;
	}
	return temp;
}



// �������������� � ��������
bool Customer::Byu() {
	//	Basket* obj = head;
	//	if (head == nullptr) return 0;
	//	else {
	//		while (obj->next != nullptr) {
	//			 �������� ��������� �������� ��������
	//			/*
	//			obj->product->name;
	//			obj->quantity
	//			*/
	//
	//			obj = obj->next;
	//		}
	//		 ���� ������������ �� ��������� ������ � ���������� �� ����� ������
	//
	//	}
	return 1;
}

string Customer::displayCustomer() {
	stringstream ss;
	ss << "Display Customer : " << endl;
	ss << "Name: " << name << endl;
	ss << "Surname: " << surname << endl;
	ss << "Email: " << email << endl;
	ss << "Phone: " << phone << endl;
	ss << "Balance: " << balance << endl;
	ss << "Discount: " << discount << "%" << endl;
	return ss.str();
}



Basket* Customer::GetBusket() {
	return head;
}

// ��������� ���������� � ���. ��������� �� ������� ��� ���������� �������
// ���� ���� ������, �� �������� ������ �����, ���� ���, �� ��������� ���-�� �������
float Customer::GetCash(float cash) {
	return (cash > balance) ? balance : cash;
}


