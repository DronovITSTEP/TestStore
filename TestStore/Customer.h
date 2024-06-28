#pragma once
#include <iostream>
#include <vector>
#include <sstream>
#include "Tovar.h"

using namespace std;


// скидка от 0% до 100%
	// если общая сумма заказов до 1000 ---> скидка 2%
	// если общая сумма заказов от 1000 до 5000 то скидка 5%
	// если общая сумма заказов от 5000 до 10000 то скидка 10%
	// если общая сумма заказов от 10000 до 20000 и более скидка 20%
	// спец скидка для VIP клиентов

enum DiscountType {
	No_diskont = 0,
	Сustomer1000 = 2,
	Сustomer5000 = 5,
	Сustomer10000 = 10,
	Сustomer20000 = 20,
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
	// Конструктор 
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

	
	// Геттеры
	string getName() const { return name; }
	string getSurname() const { return surname; }
	string getEmail() const { return email; }
	string getPhone() const { return phone; }

	float getDiscount() { return discount; }

	
	// Сеттеры
	void setName(string newName) { name = newName; }
	void setSurname(string surname) { name = surname; }
	void setEmail(string email) { name = email; }
	void setPhone(string phone) { name = phone; }


	/// <summary>
	/// Добавление позиции в корзину (указываем указатель) 
	/// </summary>
	/// <param name="id_product">id наименования</param>
	bool AddToBasket(Product* product_obj);

	/// <summary>
	/// Отображение позииции в корзине
	/// </summary>
	string displayBasket();

	/// <summary>
	/// Поиск позиции в корзине по name
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	vector<Product*>::iterator searchIdBasket(string name);

	/// <summary>
	/// Редактирование выбранной позиции в корзине
	/// </summary>
	/// <param name="index"></param>
	bool EditBasket(string name, int count, Product* product);

	/// <summary>
	/// Удаление позиции из корзины, возвращает 0 - если не удалось удалить(позиция не найдена); 1 - произошло удаление
	/// </summary>
	/// <param name="delNode"></param>
	bool RemovePos_FromBasket(string name);

	/// <summary>
	/// Удаление из корзины всех позиций, возвращает 0 - если не удалось удалить; 1 - произошло удаление
	/// </summary>
	/// <param name="index"></param>
	void RemoveAllFromBasket();





	/// <summary>
	/// Вычисление общей суммы заказа (возвращает общую сумму заказа, параметр total_dis - сумма с учетом скидки)
	/// </summary>
	/// <returns></returns>
	float AllBasket_Price(float& total_dis);

	/// <summary>
	/// Определение скидки для покупателя
	/// </summary>
	double CalculateDiscount(string name);


	/// <summary>
	/// метод КУПИТЬ, если покупка возможна (есть наличие товара на складе)
	/// то передаем все позиции заказа
	/// </summary>
	/// <param name="id_product"></param>
	/// <param name=""></param>
	/// <returns></returns>
	bool Byu();

	/// <summary>
	/// Отображение покупателя
	/// </summary>
	string displayCustomer();

	/// <summary>
	/// Получение всей корзины, передаем пока ссылку на первую позицию
	/// </summary>
	/// <returns></returns>
	Basket* GetBusket();

	/// <summary>
	/// Проверка хватает ли у покупателя на балансе ден. средств для оплаты покупки  если не хватает, то возвращается полный баланс
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


// Подсчет суммы всего заказа
//float Customer::AllBasket_Price(float& total_dis) {
//	float total = 0;
//	Basket* temp = head;
//
//	while (temp != nullptr) {
//		//total += temp->product->price * temp->count; // без учета скидки
//		//total_dis += temp->product->price * temp->count * ((100-(this->discount)) / 100.0); // с учетом скидки;
//		temp = temp->next;
//	}
//
//	return total;
//}

// Редактирование позиции в корзине по idBasket 
bool Customer::EditBasket(string name, int count, Product* product) {
	
	vector<Product*>::iterator iter = searchIdBasket(product->name);

	if (iter != basket->products.end()) {
		(*iter)->name = name;
		(*iter)->count = count;
		return 1;
	}
	return 0;
}

// Удаление позиции из корзины
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


//Отображение позиции в корзине
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



// Взаимодействие с кассиром
bool Customer::Byu() {
	//	Basket* obj = head;
	//	if (head == nullptr) return 0;
	//	else {
	//		while (obj->next != nullptr) {
	//			 передаем выбранные продукты продавцу
	//			/*
	//			obj->product->name;
	//			obj->count
	//			*/
	//
	//			obj = obj->next;
	//		}
	//		 если подтверждено то уменьшаем баланс у покупателя на сумму заказа
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

// Получение информации о ден. средствах на балансе для совершения покупки
// если есть деньги, то передаем полную сумму, если нет, то доступное кол-во средств
float Customer::GetCash(float cash) {
	return (cash > balance) ? balance : cash;
}


