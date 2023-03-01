/* 
 * Вариант: 23
 * Дан целочисленный список. Используя функцию transform умножить каждый элемент списка, являющийся степенью двойки, 
 * на масштабирующий коэффициент.
 */

#include <iostream>
#include <algorithm>
#include <functional>
#include <list>

struct Func
{
    int _k;
    Func(int k): _k(k) {}
    int operator()(int x) const
    {
        if(!(x & (x - 1)))
            return x * x;
        return x;
    }
};

int main()
{
    std::list<int> l = {1, 4, 2, 0, 16, 3, 2};
    std::function<int(int)> f = Func(3);
    std::transform(l.cbegin(), l.cend(), l.begin(), f);

    for(auto const &i : l)
    {
        std::cout << i << " ";
    }

    return 0;
}



