#pragma once
#include <iostream>
#include <vector>
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
	Basket* basket;

	string name;
	string surname;
	string email;
	string phone;
	float discount;
	float balance;

public:	
	// ����������� 
	Customer(string name, 
			string surname, 
			string email, 
			string phone, 
			float balance) :
		name{ name },
		surname{ surname },
		email{ email },
		phone{ phone },
		balance{ balance }
	{
		discount = No_diskont;
		basket = new Basket;
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
	string displayBasket();

	/// <summary>
	/// ����� ������� � ������� �� name
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	vector<Product*>::iterator searchIdBasket(string name);

	/// <summary>
	/// �������������� ��������� ������� � �������
	/// </summary>
	/// <param name="index"></param>
	bool EditBasket(string name, int count, Product* product);

	/// <summary>
	/// �������� ������� �� �������, ���������� 0 - ���� �� ������� �������(������� �� �������); 1 - ��������� ��������
	/// </summary>
	/// <param name="delNode"></param>
	bool RemovePos_FromBasket(string name);

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
	~Customer();
};


Customer::~Customer() {
	basket->products.clear();
	if (basket)
		delete basket;
	
}

bool Customer::AddToBasket(Product* product_obj) {
	if (product_obj == nullptr) return 0;
	basket->products.push_back(product_obj);	
	return 1;
}


// ������� ����� ����� ������
//float Customer::AllBasket_Price(float& total_dis) {
//	float total = 0;
//	Basket* temp = head;
//
//	while (temp != nullptr) {
//		//total += temp->product->price * temp->count; // ��� ����� ������
//		//total_dis += temp->product->price * temp->count * ((100-(this->discount)) / 100.0); // � ������ ������;
//		temp = temp->next;
//	}
//
//	return total;
//}

// �������������� ������� � ������� �� idBasket 
bool Customer::EditBasket(string name, int count, Product* product) {
	
	vector<Product*>::iterator iter = searchIdBasket(product->name);

	if (iter != basket->products.end()) {
		(*iter)->name = name;
		(*iter)->count = count;
		return 1;
	}
	return 0;
}

// �������� ������� �� �������
bool Customer::RemovePos_FromBasket(string name) {
	vector<Product*>::iterator iter = searchIdBasket(name);
	if (iter != basket->products.end()) 
	{
		basket->products.erase(iter);
		return 1;
	}
	return 0;
	
}


void Customer::RemoveAllFromBasket() {
	basket->products.clear();
}


//����������� ������� � �������
string Customer::displayBasket() {

		stringstream ss;
	for (auto p : basket->products) {
		ss << "\033[0m" << "; name product: " << "\033[1;31m" << p->name
			<< "\033[0m" << "; price :" << "\033[1;31m" << p->price
			//		<< "\033[0m" << "; count: " << "\033[1;31m" << dispNode->count 
			<< "\033[0m" << "; count: " << "\033[1;31m" << p->count
			//		<< "\033[0m" << "; total price: " << "\033[1;31m" << dispNode->totalprice 
			<< "\033[0m" << endl;
	}
		return ss.str();
}

vector<Product*>::iterator Customer::searchIdBasket(string name) {
	
	vector<Product*>::iterator iter =
		find_if(basket->products.begin(), basket->products.end(),
			[name](Product* p) {return p->name == name; });
	return iter;
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
	//			obj->count
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
	return basket;
}

// ��������� ���������� � ���. ��������� �� ������� ��� ���������� �������
// ���� ���� ������, �� �������� ������ �����, ���� ���, �� ��������� ���-�� �������
float Customer::GetCash(float cash) {
	return (cash > balance) ? balance : cash;
}


