/*
 * Вариант: 6
 * Опишите оператор [] для разработанного класса-массива, обработайте ошибку выхода за границы массива.
 */

#include <iostream>
#include <stdexcept>

template<typename T, size_t N>
class MyArray {
	T arr[N];

public:
	T& operator[](size_t idx);
};

template<typename T, size_t N>
inline T& MyArray<T, N>::operator[](size_t idx)
{
	if (idx >= N)
		throw std::out_of_range("Index is out of range.");

	return arr[idx];
}

int main() {
	MyArray<int, 10> a;
	
	try
	{
		a[10] = 1;
	}
	catch (const std::out_of_range &e)
	{
		std::cerr << e.what();
	}

	return 0;
}