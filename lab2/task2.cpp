/*
 * Вариант: 23
 * Дана строка символов и некоторый символ n. Сформируйте новую строку, вставив после каждого вхождения символа n 
 * запятую. Определите самое большое слово в строке.
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::vector<std::string> split_words(const std::string& s)
{
    std::vector<std::string> v;
    std::string::size_type prev_pos = 0, pos = 0;

    while((pos = s.find_first_of(" ,", pos)) != std::string::npos)
    {
        std::string substring = s.substr(prev_pos, pos-prev_pos);
        if(substring.size() > 0)
            v.push_back(substring);

        prev_pos = ++pos;
    }

    return v;
}

int main()
{
    char delimiter = 'D';
    std::string s = "aboba belibobaD ddddDddDd DDDsome text, agaDaga";

    std::string::size_type pos = s.find(delimiter);
    while((pos = s.find(delimiter, pos)) != std::string::npos)
    {
        s.replace(pos, 1, ",");
    }

    std::cout << s << std::endl;

    std::vector<std::string> res = split_words(s);
    std::sort(res.begin(), res.end(), [] (const std::string &l, const std::string &r) { return l.size() < r.size(); });
    for(auto const& w : res)
    {
        std::cout << '"' << w << '"' << ' ';
    }
    std::cout << "\nShortest word: " << res[0] << std::endl;

    return 0;
}