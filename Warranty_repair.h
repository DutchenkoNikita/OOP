/* Автор - Дутченко Микита БС-93
   Заголовний файл класу warranty_repair
*/

#pragma once
#include "Service_center.h"
#include <iostream>
using namespace std;

//Перелічення типів пошкодження техніки
enum breakage_type
{
	mechanical_damage, manufacturing_defect, incorrect_operation, another // типы повреждений
};


class warranty_repair : public service_center
{
private:
	int ticket_number = 0;
	breakage_type Breakage_type;
	string string_breaktype(breakage_type type) const;
public:
	warranty_repair();
	warranty_repair(string name_, string manufacturer_, int date_, float price_, int ticket_number_, breakage_type Breakage_type_);

	void set_ticket(int ticket_number_);
	void set_type(breakage_type Breakage_type_);

	int get_ticket()const;
	breakage_type get_type()const;

	void print(ostream& _Q)const;
	friend ostream& operator << (ostream& out, warranty_repair& _Q);
	friend istream& operator >> (istream& in, warranty_repair& _Q);
	friend ofstream& operator << (ofstream& file, warranty_repair& _Q);
	friend ifstream& operator >> (ifstream& file, warranty_repair& _Q);


	~warranty_repair();
	


};