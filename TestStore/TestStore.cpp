#include <iostream>
#include "Employ.h"
#include "Seller.h"
#include "Storekeeper.h"
#include "Cashier.h"
#include "Customer.h"
#include "WareHouse.h"
#include "Tovar.h"
#include "_File.h"



enum Eployees {SELLER, STOREKEEPER, CASHIER };

int main()
{

    Customer customer{ "Ivan", "Ivanov", "ivan@ivanov.ru", "899997777", 12400 };
    WareHouse stock;
    Employ* empl[3]{
        new Seller("Petr", "Petrov", "Saler", 47555),
    new Storekeeper("Sidr", "Sidorov", "Storekeeper", 36500),
    new Cashier("Elena", "Elenova","Dou", 60000)
    };

    _File file;
    file.Open("Products.txt");
    Product* products = file.GetProducts();
    for (int i = 0; i < 10; i++) {
        stock.AddProduct(products[i].name, products[i].price, products[i].count);
    }

    customer.AddToBasket(empl[SELLER]->GetProduct("молоко", 2));
    customer.AddToBasket(empl[SELLER]->GetProduct("хлеб", 1));
    customer.AddToBasket(empl[SELLER]->GetProduct("яйца", 4));

    float totalPrice = empl[CASHIER]->GetTotalPrice(customer.GetBusket(),
        customer.GetDiscount());
    if (empl[CASHIER].Pay(customer.GetCash(totalPrice))) {
        cout << "Ok";
    }
    else cout << "Not Ok";

}
