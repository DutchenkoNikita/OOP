/* Автор Дутченко Микита БС-93
   Заголовний файл класу Priority_Queue
   Містить структуру node - елемент контейнера
*/

#include "Service_center.h"
#include "Regulated_service.h"
#include "Warranty_repair.h"
using namespace std;

struct node
{
    int priority;
    service_center* info;
    struct node* link;
};

class Priority_Queue
{
private:
    node* front;
public:
    Priority_Queue();
    ~Priority_Queue();
    void insert(service_center* item, int priority);
    void del();
    int display();
    void delAll();
    void input_file();
    void output_file();
    void sort();
    void mission();
}; 
