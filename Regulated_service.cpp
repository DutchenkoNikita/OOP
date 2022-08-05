/* ����� - �������� ������ ��-93
   ��������� ����� regulated_service
*/

#include "Regulated_service.h"
using namespace std;

//����� ��� ������ ���������� � �������
//=======================================================================
string regulated_service::string_type(service_type type) const
{
	if (type == full_inspection)
		return "full_inspection";
	else if (type == replacement_consumables)
		return "replacement_consumables";
	else if (type == replacement_parts)
		return "replacement_parts";
	else if (type == other)
		return "other";
	else
		return "Unknown";
}

//����������� ��� ���������
//=======================================================================
regulated_service::regulated_service()
{
}

//����������� � �����������
//=======================================================================
regulated_service::regulated_service(string name_, string manufacturer_, int date_, float price_, service_type Service_type_):
	service_center(name_,manufacturer_,date_,price_),Service_type(Service_type_)
{

}


//������ ����� regulated_service
//=======================================================================
void regulated_service::set_type(service_type Service_type_)
{
	Service_type = Service_type_;
}

//������ ����� regulated_service
//=======================================================================
service_type regulated_service::get_type() const
{
	return Service_type;
}

//������� ������ � �������
//=======================================================================
void regulated_service::print(ostream& _Q) const
{
	cout << "Regulated service: " << endl;
	service_center::print(_Q);
	cout << "Service type: ";
	_Q << string_type(Service_type);
	cout << endl;
}


//����������
//=======================================================================
regulated_service::~regulated_service(){}


//�������������� ��������� �����/������ � ������� �� � ����
//=======================================================================
ostream& operator<<(ostream& out, regulated_service& _Q)
{
	_Q.print(out);
	return out;

}

istream& operator>>(istream& in, regulated_service& _Q)
{
	in >> (service_center&)_Q;
	int type = -1;
	cout << "What a type:" << endl;
	cout << "(0) full inspection" << endl;
	cout << "(1) replacement consumables" << endl;
	cout << "(2) replacement parts" << endl;
	cout << "(3) other" << endl;
	while (!(in >> type) && (type < 0))
	{
		cout << "Incorrect, try again: ";
		in.clear();
		rewind(stdin);
	}
	_Q.Service_type = static_cast<service_type>(type);
	return in;

}

ofstream& operator<<(ofstream& file, regulated_service& _Q)
{
	file << (service_center&)_Q; // ��������� ���� �������� ����� � ����
	file << _Q.get_type() << "\n";
	return file;

}

ifstream& operator>>(ifstream& file, regulated_service& _Q)
{
	file >> (service_center&)_Q; // ��� ���� �������� �����
	int type = -1;
	file >> type;
	_Q.Service_type = static_cast<service_type>(type);
	return file;

}
