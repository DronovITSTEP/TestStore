#pragma once
#include<iostream>
#include "Tovar.h"
using namespace std;

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
		name = name;
		lastname = lastname;
		post = post;
		payment = payment;
	}

	//����������� ����� ��������� �������� ������
	virtual Product GetProduct(string name, int num) = 0;
};

