/* ����� - �������� ������ ��-93
   ���������� ���� ����� service_center
*/

#pragma once
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class service_center
{
protected:
	string name; 
	string manufacturer; 
	int date; // �� ����������� ������
	float price; // ���� ������ � �������
public: 
	service_center();
	service_center(string name_, string manufacturer_, int date_, float price_);

	// ������ ����� service center
	void set_name(string name_);
	void set_manufacturer(string manufacturer_);
	void set_date(int date_);
	void set_price(int price_);
	
	// ������ ����� service center
	string get_name()const;
	string get_manufacturer()const;
	int get_date()const;
	float get_price()const;

	virtual void print(ostream& _Q) const;
	virtual ~service_center();

	//�������������� ��������� �����/������ � ������� �� � ����
	friend ostream& operator << (ostream& out, service_center& _Q);
	friend istream& operator >> (istream& in, service_center& _Q);
	friend ofstream& operator << (ofstream& file, service_center& _Q);
	friend ifstream& operator >> (ifstream& file, service_center& _Q);


};