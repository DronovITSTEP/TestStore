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
	float GetTotalPrice(Basket* basket, float discount) {
		if (basket != nullptr) {
			for(auto p: basket->products)
			{
				TotalPrice += (p->price * p->count); //�������� ����
			}
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

