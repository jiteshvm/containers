#include <iostream>
#include "vector.h"
#include <vector>
#include <windows.h>

//using namespace containers;

class TestClass
{
public:
	int x;
	TestClass(int t = 0) { x = t; }
};

void test_add() {
	long num_additions = 1000000;
	LARGE_INTEGER StartingTime, EndingTime, ElapsedMicroseconds;
	LARGE_INTEGER Frequency;
	std::vector<TestClass> vec_add1;
	containers::vector<TestClass> vec_add2;
	//vec_add1.reserve(num_additions);

	QueryPerformanceFrequency(&Frequency);
	QueryPerformanceCounter(&StartingTime);
	
	for (int i = 0; i < num_additions; ++i) {
		vec_add1.push_back(TestClass(i));
	}
	QueryPerformanceCounter(&EndingTime);

	ElapsedMicroseconds.QuadPart = EndingTime.QuadPart - StartingTime.QuadPart;
	ElapsedMicroseconds.QuadPart *= 1000000;
	ElapsedMicroseconds.QuadPart /= Frequency.QuadPart;
	double t = double(ElapsedMicroseconds.QuadPart) / 1000000.0f;
	std::cout << num_additions << " additions in std::vector took : " << t << " microseconds " << std::endl;
	std::cout << "size : " << vec_add1.size() << " , capacity : " << vec_add1.capacity() << std::endl;
	QueryPerformanceFrequency(&Frequency);
	QueryPerformanceCounter(&StartingTime);
	for (int i = 0; i < num_additions; ++i) {
		vec_add2.Push_Back(TestClass(i));
	}
	QueryPerformanceCounter(&EndingTime);

	ElapsedMicroseconds.QuadPart = EndingTime.QuadPart - StartingTime.QuadPart;
	ElapsedMicroseconds.QuadPart *= 1000000;
	ElapsedMicroseconds.QuadPart /= Frequency.QuadPart;
	t = double(ElapsedMicroseconds.QuadPart) / 1000000.0f;
	std::cout << num_additions << " additions in containers::vector took : " << t << " microseconds " << std::endl;
	std::cout <<"size : " << vec_add2.size() << " , capacity : " << vec_add2.capacity() << std::endl;
}

int main(){
	test_add();
  	return 0; 
}
