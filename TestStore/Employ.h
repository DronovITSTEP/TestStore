#pragma once
#include<iostream>
#include "Tovar.h"

class Employ
{
protected:
	string name;
	string lastname;
	string post;
	double payment;

public:
	//������������� ����������
	Employ(string name, string lastname, string post, double payment) {
		this->name = name;
		this->lastname = lastname;
		this->post = post;
		this->payment = payment;
	}

	//����������� ����� ��������� �������� ������
	virtual Product GetProduct(string name, int num) = 0;
};

