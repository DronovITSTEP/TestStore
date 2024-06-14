#pragma once
#include <iostream>
#include "Tovar.h"

using namespace std;

class _File
{
private:
	string path = "";
	string name = "";
public:
	bool Open(string namefile, string path="/");
	bool Save(string path, string namefile, char* type_of_access, Product* products);
	Product* GetProducts();
};

