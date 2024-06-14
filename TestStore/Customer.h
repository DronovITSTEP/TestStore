#pragma once
#include <iostream>
#include "\\Teacher\общая папка\БВ311\Tovar.h"

using namespace std;


class Customer
{
public:
	Basket* basket;
	static int сustomerId;
	string name;
	string surname;
	string email;
	string phone;
	float discount;
	float all_order = 0; // сумма заказов покупателя (нужно для расчета скидки)

	
	
	
	// Конструктор 
	Customer(string name, string surname, string email, string phone) :
		name{ name },
		surname{ surname },
		email{ email },
		phone{ phone },
		discount{ 0 } {
		сustomerId++;
	}

	// Конструктор копирования
	Customer(const Customer& other): 
		name{ other.name },
		surname{ other.surname },
		email{ other.email },
		phone{ other.phone },
		discount{ other.discount}
	{
		сustomerId++;
	}

	// Геттеры
	string getName() const {return name;}
	string getSurname() const { return surname; }
	string getEmail() const {return email;}
	string getPhone() const { return phone; }
	
	// Сеттеры
	void setName(string newName) {name = newName;}
	void setSurname(string surname) { name = surname; }
	void setEmail(string email) { name = email; }
	void setPhone(string phone) { name = phone; }

	/// <summary>
	/// Получение id покупателя по имени
	/// </summary>
	/// <returns></returns>
	int getCustomerId(string name);
	
	/// <summary>
	/// Получение id покупателя по email
	/// </summary>
	/// <returns></returns>
	int getCustomerId(string email);
		
		
	/// <summary>
	/// Добавление товара в корзину (предварительно запрашиваем наличие товара на складе)
	/// </summary>
	/// <param name="id_product">id наименования</param>
	/// <param name="quantity">кол-во товаров</param>
	void AddToBasket(int id_product, int quantity);
	
	/// <summary>
	/// Редактирование выбранной позиции в корзине
	/// </summary>
	/// <param name="index"></param>
	void EditBasket(int index, int id_product, int quantity);
	/// <summary>
	/// Удаление из корзины позиции
	/// </summary>
	/// <param name="id_product"></param>
	/// <param name="quantity"></param>
	void RemoveFromBasket(int index);

	/// <summary>
	/// Удаление из корзины всех позиций
	/// </summary>
	/// <param name="index"></param>
	void RemoveAllFromBasket(int index);

	/// <summary>
	/// Показ выбранной позиции в корзине
	/// </summary>
	void ShowCart(int index);
	
	/// <summary>
	/// Вычисление общей суммы заказа
	/// </summary>
	/// <returns></returns>
	double TotalPrice();

	/// <summary>
	/// Определение скидки для покупателя
	/// </summary>
	double Discount(int сustomerID);

	
	/// <summary>
	/// метод КУПИТЬ, если покупка возможно (есть наличие товара на складе)
	/// то передаем все позиции заказа
	/// </summary>
	/// <param name="id_product"></param>
	/// <param name=""></param>
	/// <returns></returns>
	bool Byu(Basket* basket_obj);
};

int Customer::сustomerId = 0;

