#include <iostream>
#include <vector>
#include <immintrin.h>

template<typename T>
void check_align()
{
	unsigned long long mask = ~0;
	std::vector<std::vector<T>> tab;
	for (int i = 0; i < 1000; i++)
	{
		std::vector<T> v(i+1);
		v[0] = T();
		unsigned long long p = (unsigned long long)(&v[0]);
		mask = mask & (~p);
		//std::cout << v.size() << " " << &v[0] << std::endl;
		tab.push_back(v);
	}
	unsigned long long align = 1;
	while (mask & 1)
	{
		align *= 2;
		mask = mask >> 1;
	}
	std::cout << typeid(T).name() << ", sizeof: " << sizeof(T) <<  " align: " << align << " ("<< align *8 << ")"<<  std::endl;
}

int main(int argc, char** argv)
{
	check_align<char>();
	check_align<int>();
	check_align<long long>();
	check_align< __m128i>();
	check_align< __m256i>();

#if defined(__AVX512F__)
	check_align< __m512i>();
#endif

}