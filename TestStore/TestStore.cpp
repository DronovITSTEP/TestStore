#include <iostream>
#include "Employ.h"
#include "Customer.h"
#include "WareHouse.h"
#include "Tovar.h"



enum Eployees {SELLER, STOREKEEPER, CASHIER };

int main()
{

    Customer customer{ "Ivan", "Ivanov", "ivan@ivanov.ru", "899997777" };
    WareHouse stock;
    Employee* empl = new Employee[3]{
        new Seller{"Petr", "Petrov", "Saler", 47555},
        new Storekeeper{"Sidr", "Sidorov", "Storekeeper", 36500},
        new Cashier{"Elena", "Elenova", 60000}
    };

    _File file;
    Product* products = classFile.GetProducts();
    for (int i = 0; i < 10; i++) {
        stock.AddProduct(products[i]->name, products[i]->price, products[i]->count);
    }

    customer.AddToBasket(empl[SELLER]->GetProduct("молоко", 2));
    customer.AddToBasket(empl[SELLER]->GetProduct("хлеб", 1));
    customer.AddToBasket(empl[SELLER]->GetProduct("яйца", 4));

    float totalPrice = empl[CASHIER].GetTotalPrice(customer.GetBasket(), 
        customer.GetDiscount());
    if (empl[CASHIER].Pay(customer.GetCash(totalPrice))) {
        cout << "Ok";
    }
    else cout << "Not Ok";

}
