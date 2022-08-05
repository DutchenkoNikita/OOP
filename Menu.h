/* Автор Дутченко Микита БС-93
   Заголовний файл класу MENU
*/

#include "Priority_Queue.h"
#include "Regulated_service.h"
#include "Warranty_repair.h"

class MENU
{
private:
	Priority_Queue* PQ;
public:
	MENU();
	~MENU();
	void start();
	void warranty_object();
	void regulated_object();
	void print_queue();
	void delete_object();
	void delete_all();
	void input_file();
	void output_file();
	void sort();
	void mission();

};
