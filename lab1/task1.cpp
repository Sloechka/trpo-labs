/*
 * Вариант: 6
 * Опишите параметризованную функцию сортировки вставкой. Продемонстрируйте использование функции для разных типов данных.
 */

#include <iostream>

template<typename T>
void insert_sort(T* array, unsigned int len)
{
	if (len < 2)
		return;

	for (unsigned int i = 2; i < len; i++)
	{
		T x = array[i];
		int j = i - 1;
		while (j >= 0 && array[j] > x)
		{
			array[j + 1] = array[j];
			j = j - 1;
		}
		array[j + 1] = x;
	}
}

template<typename T>
void print_sorted(T* array, std::string name, unsigned int size)
{
	insert_sort(array, size);

	std::cout << name << "[] = ";
	for (unsigned int i = 0; i < size; i++)
		std::cout << array[i] << ' ';
	std::cout << std::endl;
}

int main() {
	// Integer
	int int_array[] = { 5, 6, 7, 9, 3 };
	print_sorted(int_array, "int_array", 5);

	// Char
	char char_array[] = { 'a', 'c', '0', 'e', 'a' };
	print_sorted(char_array, "char_array", 5);

	// std::string
	std::string str_array[] = { "some_string", "very_long_string", "short_str" };
	print_sorted(str_array, "str_array", 3);

	return 0;
}