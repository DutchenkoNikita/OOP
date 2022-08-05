/* Автор - Дутченко Микита БС-93
   Реалізація класу service_center	
*/

#include "Service_center.h"

//конструктор за замовчуванням
service_center::service_center()
{
}

//конструктор з параметрами
service_center::service_center(string name_, string manufacturer_, int date_, float price_) : 
	name(name_), manufacturer(manufacturer_), date(date_), price(price_)
{
}

//гетери класу service cener
//=======================================================================
void service_center::set_name(string name_)
{
	name = name_;
}

void service_center::set_manufacturer(string manufacturer_)
{
	manufacturer = manufacturer_;
}

void service_center::set_date(int date_)
{
	date = date_;
}

void service_center::set_price(int price_)
{
	price = price_;
}

string service_center::get_name()const
{
	return name;
}

//гетери класу service cener
//=======================================================================
string service_center::get_manufacturer()const
{
	return manufacturer;
}

int service_center::get_date()const
{
	return date;
}

float service_center::get_price()const
{
	return price;
}

//функція виводу у консоль
//=======================================================================
void service_center::print(ostream& _Q) const
{
	cout << "Name: ";
	_Q << name;
	cout << endl;
	cout << "Manufacturer: ";
	_Q << manufacturer;
	cout << endl;
	cout << "Date: ";
	_Q << date;
	cout << endl;
	cout << "Price: ";
	_Q << price;
	cout << endl;
}

//деструктор
service_center::~service_center(){}


//перевантаження операторів
//=======================================================================
ostream& operator<<(ostream& out, service_center& _Q)
{
	_Q.print(out);
	return out;

}

istream& operator>>(istream& in, service_center& _Q)
{
	in.ignore(32767, '\n');
	cout << "Name: ";
	getline(in, _Q.name);
	cout << "Manufacturer: ";
	getline(in, _Q.manufacturer);
	cout << "Input year: ";
	int _date = 0;
	in >> _date;
	while (_date <= 0)
	{
		cout << "Incorrect, try again: ";
		cin.clear();
		rewind(stdin);
		in >> _date;
	}
	_Q.date = _date;
	int _price = 0;
	cout << "Input price of product: ";
	in >> _price;
	while (_price <= 0)
	{
		cout << "Incorrect, try again: ";
		in.clear();
		rewind(stdin);
		in >> _price;
	}
	_Q.price = _price;
	return in;

}

ofstream& operator<<(ofstream& file, service_center& _Q)
{
	file << _Q.get_name() <<
		"\n" << _Q.get_manufacturer() <<
		"\n" << _Q.get_date() <<
		"\n" << _Q.get_price() << "\n";
	return file;

}

ifstream& operator>>(ifstream& file, service_center& _Q)
{
	getline(file,_Q.name);
	getline(file, _Q.manufacturer);
	file >> _Q.date;
	file >> _Q.price;
	return file;

}
