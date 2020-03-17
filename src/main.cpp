#include <iostream>
#include "vector.h"
#include <vector>

//using namespace containers;

class TestClass
{
public:
	int x;
	TestClass(int t = 0) { x = t; }
};

int main(){

	std::vector<TestClass> vec1;
	//TestClass t1(5);
	//std::cout << &TestClass(5) << std::endl;

	containers::vector<TestClass> *vec2 = new containers::vector<TestClass>();

	std::cout << "push.." << std::endl;
	for (int i = 0; i < 10; ++i) {
		TestClass t(i);
		//vec1.push_back(t);
		vec2->Add(t);
		//std::cout << vec1.size() << " , " << vec1.capacity() << std::endl;
		std::cout << vec2->size() << " , " << vec2->capacity() << std::endl;
		for (int i = 0; i < vec2->capacity(); ++i) {
			std::cout << vec2->Get(i).x << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "pop.." << std::endl;
	for (int i = 0; i < 10; ++i) {
		//vec1.pop_back();
		vec2->Pop_Back();
		//std::cout << vec1.size() << " , " << vec1.capacity() << std::endl;
		std::cout << vec2->size() << " , " << vec2->capacity() << std::endl;
		for (int i = 0; i < vec2->capacity(); ++i) {
			std::cout << vec2->Get(i).x << " ";
		}
		std::cout << std::endl;
	}
	



	//
	//for (int i = 0; i < 10; ++i) {
	//	TestClass t(i);
	//	vec2->Add(t);
	//	//vec2->Add(TestClass(i));
	//}
	//
	//for (int i = 0; i < vec2->size(); ++i) {
	//	std::cout << vec2->Get(i).x << " ";
	//}

	//std::cout << std::endl;

	//for (int i = 0; i < vec2->size(); ++i) {
	//	vec2->Set(i, TestClass(i+10));
	//}

	//for (int i = 0; i < vec2->size(); ++i) {
	//	std::cout << vec2->Get(i).x << " ";
	//}
	//std::cout << std::endl;

	//std::cout << "capacity = " << vec2->capacity() << " size = " << vec2->size() << std::endl;
	//
	//std::cout << "removing... " << vec2->Get(4).x << std::endl;
	//vec2->Remove(vec2->Get(4));

	//std::cout << "capacity = " << vec2->capacity() << " size = " << vec2->size() << std::endl;

	//for (int i = 0; i < vec2->size(); ++i) {
	//	std::cout << vec2->Get(i).x << " ";
	//}
	//std::cout << std::endl;
	//
	//std::cout << "clearing... " << std::endl;
	//vec2->Clear();

	//for (int i = 0; i < vec2->size(); ++i) {
	//	std::cout << vec2->Get(i).x << " ";
	//}
	//std::cout << "capacity = " << vec2->capacity() << " size = " << vec2->size() << std::endl;

	//std::cout << std::endl;
  	return 0; 
}
