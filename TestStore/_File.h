#pragma once
#include <iostream>
#include "Tovar.h"

using namespace std;

class _File
{
public:
	string path = "";
	string name = "";

	bool Open(string namefile, string path);
	void Save(string path, string namefile, char* type_of_access, Product* products);
	Product* GetProducts();
};

