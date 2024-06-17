#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "_File.h"

Product* products = new Product[30];

bool _File::Open(string namefile, string path) {
	std::ifstream file(path + namefile);
	if (file.is_open()) {
		int i = 0;
		string line;
		while (std::getline(file, line)) {
			istringstream iss(line);
			iss >> products[i].name
				>> products[i].price
				>> products[i].count;
			i++;
		}
		file.close();
		return true;
	}
	else
		cout << "no file";
	return false;
}

bool _File::Save(string path, string namefile, char* type_of_access, Product* products) {
	FILE* outfile;
	fopen_s(&outfile, (path + namefile).c_str(), type_of_access);

	if (outfile) {
		for (int i = 0; i < products->id; i++) {
			fprintf(outfile, "%s %f %d\n", products[i].name.c_str(), products[i].price, products[i].count);
		}

		fclose(outfile);
	}
	return true;
}

Product* _File::GetProducts() {
	return products;
}

