/* Автор - Дутченко Микита БС-93
   Реалізація класу Priority_Queue
*/
#include "Priority_Queue.h"

//конструктор за замовчування
//=======================================================================
Priority_Queue::Priority_Queue()
{
	front = NULL;
}

//деструктор
//=======================================================================
Priority_Queue::~Priority_Queue()
{
    del();
}

//функія створення елементу контейнера
//=======================================================================
void Priority_Queue::insert(service_center * item, int priority)
{
    node* tmp, * q;
    tmp = new node;
    tmp->info = item;
    tmp->priority = priority;
    if (front == NULL || priority < front->priority)
    {
        tmp->link = front;
        front = tmp;
    }
    else
    {
        q = front;
        while (q->link != NULL && q->link->priority <= priority)
            q = q->link;
        tmp->link = q->link;
        q->link = tmp;
    }
}

//функія видалення елементу контейнера з голови черги
//=======================================================================
void Priority_Queue::del()
{
    node* tmp;
    if (front == NULL)
        cout << "Queue is clear\n";
    else
    {
        tmp = front;
        cout << "Deleted item is: " << *(tmp->info) << endl;
        front = front->link;
        free(tmp);
    }
}

//функія для виводу контейнера у консоль
//=======================================================================
int Priority_Queue::display()
{
    node* ptr;
    ptr = front;
    if (front == NULL)
    {
        cout << "Queue is clear\n";
        return 0;
    }
    else
    {
        cout << "Queue is :\n";
        while (ptr != NULL)
        {
            cout << "------------------------------------------" << endl;
            cout << "Priority: " << ptr->priority << endl << *(ptr->info) << endl;
            cout << endl;
            ptr = ptr->link;
        }
        return 1;
    }
}

//функія видалення усіх елементів контейнера
//=======================================================================
void Priority_Queue::delAll()
{
    while (front != NULL)
    {
        node* tmp;
        if (front == NULL)
            cout << "Queue is clear\n";
        else
        {
            tmp = front;
            front = front->link;
            free(tmp);
        }
    }
        
}

//функія для запису контейнера у файл
//=======================================================================
void Priority_Queue::input_file()
{
    if (front != NULL)
    {
        ofstream out("service.dat");

        if (!out.is_open()) //Перевірка можливості роботи з файлом
        {
            cout << "Error opening file!" << endl;
            return;
        }
        node* tmp = front;
        while (front != NULL)
        {
            if (typeid(*(front->info)) == typeid(warranty_repair))
            {
                out << "warranty:" << ' ';
                out << front->priority << ' ';
                out << (*((warranty_repair*)(front->info)));
            }
            if (typeid(*(front->info)) == typeid(regulated_service))
            {
                out << "regulate:" << ' ';
                out << front->priority << ' ';
                out << (*((regulated_service*)(front->info)));
            }
            front = front->link;
        }
        out.close();
        cout << "Data is in file!" << endl;
        front = tmp;
    }
    else
        cout << "Queue is clear \n";

}

//функія для виводу даних з файлу та запис їч у контейнер
//=======================================================================
void Priority_Queue::output_file()
{
    ifstream file;
    file.open("service.dat");
    warranty_repair* wr;
    regulated_service* rs;

    if (!file.is_open()) //Перевірка можливості роботи з файлом
    {
        cout << "Error opening file!" << endl;
        return;
    }
    cout << "File is open!" << endl;
    string object = " ";
    int prior = 0;
    while (!file.eof())
    {
        file >> object;
        file >> prior;
        if (object == "warranty:")
        {
            wr = new warranty_repair;
            file >> *wr;
            if(wr->get_ticket() != 0)
                insert(wr,prior);
        }
        else if (object == "regulate:")
        {
            rs = new regulated_service;
            file >> *rs;
            if (rs->get_date() != 0)
                insert(rs, prior);
        }
    }
    file.close();
    cout << "Data loaded from file!" << endl;
    return;


}

//сортування елементів контейнера
//=======================================================================
void Priority_Queue::sort()
{
    {
        if (front == NULL)
            cout << "Queue is clear \n";
        else
        {
            int PQ_length = 0, wr_length = 0;
            node* tmp = front;

            while (front != NULL)
            {
                if (typeid(*(front->info)) == typeid(warranty_repair))
                    wr_length++;
                PQ_length++;
                front = front->link;
            }
            front = tmp;

            warranty_repair** warranty_list = new warranty_repair * [wr_length];
            int i = 0;
            for (int k = 0; k < PQ_length; ++k)
            {
                if (typeid(*(front->info)) == typeid(warranty_repair))
                {
                    warranty_list[i] = (warranty_repair*)(front->info);
                    i++;
                    del();
                }
                else
                {
                    regulated_service* regulated_object = new regulated_service();
                    regulated_object = (regulated_service*)(front->info);
                    del();
                    insert(regulated_object, front->priority);
                }
            }

            for (int i = 1; i < wr_length; i++)
            {
                for (int j = i; j > 0 && warranty_list[j - 1]->get_manufacturer() > warranty_list[j]->get_manufacturer(); j--)
                {
                    warranty_repair* tmp = warranty_list[j - 1];
                    warranty_list[j - 1] = warranty_list[j];
                    warranty_list[j] = tmp;
                }
            }

            for (int i = 0; i < wr_length; i++)
                insert(warranty_list[i], i);
            cout << "Sorted" << endl;

        }
        return;
    }

}


//функія виконання запиту користувачв
//=======================================================================
void Priority_Queue::mission()
{
    cout << endl;
    if (front == NULL)
        cout << "Queue is clear" << endl;
    else
    {
        int count = 0;
        node* tmp = front;
        string request;
        cout << "Input manufacturer: ";
        cin >> request;
        while (front != NULL)
        {
            if (typeid(*(front->info)) == typeid(warranty_repair))
            {
                if (((warranty_repair*)(front->info))->get_manufacturer() == request)
                {
                    count++;
                }
            }
            front = front->link;
        }
        cout << "Technicians with a given manufacturer: " << count;
        front = tmp;
    }
    cout << endl;
    return;


}
