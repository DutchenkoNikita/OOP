/* Автор - Дутченко Микита БС-93
   Реалізація класу warranty_repair
*/

#include "Warranty_repair.h"
using namespace std;

//функія для виводу перелічення у консоль
//=======================================================================
string warranty_repair::string_breaktype(breakage_type type) const
{
	if (type == mechanical_damage)
		return "mechanical_damage";
	else if (type == manufacturing_defect)
		return "manufacturing_defect";
	else if (type == incorrect_operation)
		return "incorrect_operation";
	else if (type == another)
		return "another";
	else
		return "Unknown";

}
//конструктор за замовчуванням
//=======================================================================
warranty_repair::warranty_repair()
{

}

//конструктор з параметрами
//=======================================================================
warranty_repair::warranty_repair(string name_, string manufacturer_, int date_, float price_, int ticket_number_, breakage_type Breakage_type_):
service_center(name_,manufacturer_,date_,price_),ticket_number(ticket_number_),Breakage_type(Breakage_type_)
{
}


//сетери класу warranty_repair
//=======================================================================
void warranty_repair::set_ticket(int ticket_number_)
{
	ticket_number = ticket_number_;
}

void warranty_repair::set_type(breakage_type Breakage_type_)
{
	Breakage_type = Breakage_type_;
}

//гетери класу warranty_repair
//=======================================================================
int warranty_repair::get_ticket()const 
{
	return ticket_number;
}

breakage_type warranty_repair::get_type()const
{
	return Breakage_type;
}

//Функыя виводу у консоль
//=======================================================================
void warranty_repair::print(ostream& _Q) const
{
	cout << "Warranty repair: " << endl;
	service_center::print(_Q);
	cout << "Ticket number: ";
	_Q << ticket_number;
	cout << endl;
	cout << "Breakage type: ";
	_Q << string_breaktype(Breakage_type);
	cout << endl;
}


//деструктор
//=======================================================================
warranty_repair::~warranty_repair() {}

//Перевантаження операторів вводу/виводу у консоль та у файл
//=======================================================================
ostream& operator<<(ostream& out, warranty_repair& _Q)
{
	_Q.print(out);
	return out;

}

istream& operator>>(istream& in, warranty_repair& _Q)
{
	in >> (service_center&)_Q;
	cout << "Input ticket number: ";
	while (!(in >> _Q.ticket_number) && _Q.ticket_number < 0)
	{
		cout << "Incorrect, try again: ";
		in.clear();
		rewind(stdin);
	}
	int type = -1;
	cout << "What a type:" << endl;
	cout << "(0) mechanical_damage" << endl;
	cout << "(1) manufacturing_defect" << endl;
	cout << "(2) incorrect_operation" << endl;
	cout << "(3) another" << endl;
	while (!(in >> type) && (type < 0))
	{
		cout << "Incorrect, try again: ";
		in.clear();
		rewind(stdin);
	}
	_Q.Breakage_type = static_cast<breakage_type>(type);
	return in;
}

ofstream& operator<<(ofstream& file, warranty_repair& _Q)
{
	file << (service_center&)_Q ;
	file << _Q.get_ticket() << "\n" << _Q.get_type() << "\n";
	return file;
}

ifstream& operator>>(ifstream& file, warranty_repair& _Q)
{
	file >> (service_center&)_Q;
	file >> _Q.ticket_number;
	int type = -1;
	file >> type;
	_Q.Breakage_type = static_cast<breakage_type>(type);
	return file;
}
