#define BOOST_TEST_MODULE mytests
#include <boost/test/included/unit_test.hpp>
#include "Priority_Queue.h"


BOOST_AUTO_TEST_SUITE(TestCase)

//Тестування створення об'єкта warranty_repair 
BOOST_AUTO_TEST_CASE(create_warrantyTest)
{
	Priority_Queue* PQ = new Priority_Queue();
	BOOST_CHECK(!PQ->display());
	warranty_repair* wr = new warranty_repair("fen", "LG",200,300,12314, static_cast<breakage_type>(3));
	PQ->insert(wr,1);
	BOOST_CHECK(PQ->display());
}

//Тестування створення об'єкта regulated_service
BOOST_AUTO_TEST_CASE(create_regulatedTest)
{
	Priority_Queue* PQ = new Priority_Queue();
	BOOST_CHECK(!PQ->display()); 
	regulated_service* rs = new regulated_service("phone","apple",2018,40999, static_cast<service_type>(3));
	PQ->insert(rs,2);
	BOOST_CHECK(PQ->display());
}

//Тестування видалення елементу з голови контейнера
BOOST_AUTO_TEST_CASE(del_objectTest)
{
	Priority_Queue* PQ = new Priority_Queue();
	BOOST_CHECK(!PQ->display());
	regulated_service* rs = new regulated_service("phone", "apple", 2018, 40999, static_cast<service_type>(3));
	PQ->insert(rs, 2);
	BOOST_CHECK(PQ->display());
	PQ->del();
	BOOST_CHECK(!PQ->display()); 
}

//Тестування завантаження даних з файлу
BOOST_AUTO_TEST_CASE(fromfileTest)
{
	Priority_Queue* PQ = new Priority_Queue();
	BOOST_CHECK(!PQ->display()); 
	PQ->output_file();
	BOOST_CHECK(PQ->display()); 
}

//Тестування очищення контейнера
BOOST_AUTO_TEST_CASE(delAllTest)
{
	Priority_Queue* PQ = new Priority_Queue();
	BOOST_CHECK(!PQ->display()); 
	PQ->output_file();
	BOOST_CHECK(PQ->display()); 
	PQ->delAll();
	BOOST_CHECK(!PQ->display()); 
}

BOOST_AUTO_TEST_SUITE_END()
