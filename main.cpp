#include <iostream>
#include <vector>
#include <immintrin.h>

template<typename T>
void check_align()
{
	
	unsigned long long mask = (1<<8)-1;
	std::vector<std::vector<T>> tab;
	for (int i = 0; i < 1000; i++)
	{
		std::vector<T> v(1);
		unsigned long long p = (unsigned long long)(&v[0]);
		mask = mask & (~p);
		//std::cout << v.size() << " " << &v[0] << std::endl;
		tab.push_back(v);
	}
	std::cout << typeid(T).name() << ": " << (mask + 1) * 8 << std::endl;
}

int main(int argc, char** argv)
{
	check_align<char>();
	check_align<int>();
	check_align< __m256i>();
	check_align< __m128i>();
}