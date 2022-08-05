/* ����� - �������� ������ ��-93
   ��������� ����� MENU
*/
#include "Menu.h"

//����������� �� ������������
//=======================================================================
MENU::MENU()
{
}

// ����������
//=======================================================================
MENU::~MENU()
{
	PQ->delAll();
}

//������� ��������� ���������� ���� �����������
//=======================================================================
void MENU::start()
{
    int choice = 0;
    PQ = new Priority_Queue();
    do
    {
        cout << "#===================Menu===================#" << endl;
        cout << "1.Insert regulated service\n";
        cout << "2.Insert warranty repair\n";
        cout << "3.Print queue\n";
        cout << "4.Delete product in queue\n";
        cout << "5.Delete queue\n";
        cout << "6.Input queue in file\n";
        cout << "7.Output queue from file\n";
        cout << "8.Sort\n";
        cout << "9.Output warranty product with one manufacturer\n";
        cout << "10.Exit\n";
        cout << "#==========================================#" << endl;
        cout << "Enter your choice : ";
        cin >> choice;
        cout << endl;
        switch (choice)
        {
        case 1:
            regulated_object();
            break;
        case 2:
            warranty_object();
            break;
        case 3:
            print_queue();
            break;
        case 4:
            delete_object();
            break;
        case 5:
            delete_all();
            break;
        case 6:
            input_file();
            break;
        case 7:
            output_file();
            break;
        case 8:
            sort();
            break;
        case 9:
            mission();
            break;
        case 10:
            break;
        default:
            cout << "Wrong choice\n";
            cin.clear();
        }
    } while (choice != 10);
}

//������� ��������� ��'���� ����� warranty_repair
//=======================================================================
void MENU::warranty_object()
{
    warranty_repair* wr_product = new warranty_repair();
    int priority = 0;
    cin >> *wr_product;
    cout << "Enter its priority : ";
    cin >> priority;
    PQ->insert(wr_product, priority);
}

//������� ��������� ��'���� ����� regulated_service
//=======================================================================
void MENU::regulated_object()
{
    regulated_service* rs_product = new regulated_service();
    int priority = 0;
    cin >> *rs_product;
    cout << "Enter its priority : ";
    cin >> priority;
    PQ->insert(rs_product, priority);
}

//������� ���������� ���� ��� ������ ���������� �� �����
//=======================================================================
void MENU::print_queue()
{
    PQ->display();
}


//������� ���������� ���� ��� ��������� ��'����
//=======================================================================
void MENU::delete_object()
{
    PQ->del();
}

//������� ���������� ���� ��� �������� ����������
//=======================================================================
void MENU::delete_all()
{
    PQ->delAll();
}

//������� ���������� ���� ��� ������ ���������� � ����
//=======================================================================
void MENU::input_file()
{
    PQ->input_file();
}

//������� ���������� ���� ��� ������ ����� � ����� �� ����� �� � ���������
//=======================================================================
void MENU::output_file()
{
    PQ->output_file();
}

//������� ���������� ���� ��� ���������� ����������
//=======================================================================
void MENU::sort()
{
    PQ->sort();
}

//������� ���������� ���� ��� ��������� ������ �����������
//=======================================================================
void MENU::mission()
{
    PQ->mission();
}
