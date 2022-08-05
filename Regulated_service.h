/* Автор - Дутченко Микита БС-93
   Заголовний файл класу regulated_service
*/

#pragma once
#include "Service_center.h"
#include <string>
using namespace std;

//перелічення типів сервісного обслуговування техніки
enum service_type
{
	full_inspection, replacement_consumables, replacement_parts, other
};

class regulated_service : public service_center
{
private:
	service_type Service_type;
	string string_type(service_type type) const;
public:
	regulated_service();
	regulated_service(string name_, string manufacturer_, int date_, float price_, service_type Service_type_);

	void set_type(service_type Service_type_);
	service_type get_type()const;
	void print(ostream& _Q)const;


	~regulated_service();

	friend ostream& operator << (ostream& out, regulated_service& _Q);
	friend istream& operator >> (istream& in, regulated_service& _Q);
	friend ofstream& operator << (ofstream& file, regulated_service& _Q);
	friend ifstream& operator >> (ifstream& file, regulated_service& _Q);

};