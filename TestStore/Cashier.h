#pragma once
#include"Tovar.h"
#include"Employ.h"
#include<iostream>

using namespace std;

class Cashier : public Employ
{

	float TotalPrice = 0;
public:
	Cashier(string name, string lastname, string post, double payment) : Employ(name, lastname, post, payment) {}
	//������� ����� ��������� ���� ����� � �������
	float GetToatalPrice(Basket* basket, float discount) {
		while (basket != nullptr) {
			
			TotalPrice += (basket->product->price * basket->product->count); //�������� ����
			basket = basket->next;
		}
		return TotalPrice * (1 - discount / 100);
	}
	//�������� ���������� ������ �� ������� ����������
	bool Pay(float sum) {
		if (sum == TotalPrice) {
			return true;
		}
		return false;
	}
	Product* GetProduct(string name, int count) {
		return nullptr;
	}
};

