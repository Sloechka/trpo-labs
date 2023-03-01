/*
 * Вариант: 23
 * Сформировать динамический список символов. Описать функцию, которая удаляет из списка каждый символ ‘e’ и 
 * заменяет его на символ ‘g’.
 */

#include <iostream>
#include <list>

void repl(std::list<char> &in_list)
{
    for(auto it = in_list.begin(); it != in_list.end(); ++it)
    {
        if(*it == 'e')
        {
            it = in_list.erase(it);
            in_list.insert(it, 'g');
        }
    }
}

int main()
{
    std::list<char> l = {'a', 'e', 'c', 'e', 'e', 'z', 'e'};
    repl(l);

    for(auto const &it : l)
        std::cout << it << ' ';
    std::cout << std::endl;
    
    return 0;
}