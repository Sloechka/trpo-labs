/* 
 * Вариант: 23
 * Создать класс-интерфейс пространственной фигуры, который содержит три элемента с модификатором доступа protected. 
 * Создать производные классы: шаровой сегмент, эллипсоид, прямой круговой цилиндр. Для каждой из фигур предусмотреть 
 * вывод ее названия и вычисление объема. Случайным образом выбрать фигуру и с помощью оператора dynamic_cast 
 * произвести конвертацию типа из класса-интерфейса в производный.
 */

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

#define PI 3.14159235

class Figure
{
    protected:
        double _d1, _d2, _d3;

    public:
        Figure(double d1 = 0, double d2 = 0, double d3 = 0): _d1(d1), _d2(d2), _d3(d3) {}

        void set_dim(double d1, double d2, double d3 = 0)
        {
            this->_d1 = d1;
            this->_d2 = d2;
            this->_d3 = d3;
        }

        void get_dim(double &d1, double &d2, double &d3)
        {
            d1 = this->_d1;
            d2 = this->_d2;
            d3 = this->_d3;
        }

        virtual void name() = 0;
        virtual double volume() = 0;
};

class SphereCap: public Figure
{
    // _d1 - радиус, _d2 - высота, _d3 = 0
    double volume() override 
    {
        return PI * _d2*_d2 * (_d1 - _d2 / 3);
    }
    
    void name()
    {
        std::cout << "I am sphere cap" << std::endl;
    }
};

class Ellipsoid: public Figure
{
    // _d1, _d2, _d3 - полуоси
    double volume() override
    {
        return 4 * PI / 3.0 * _d1 * _d2 * _d3;
    }

    void name()
    {
        std::cout << "I am ellipsoid" << std::endl;
    }
};

class Cylinder: public Figure
{
    // _d1 - радиус, _d2 - высота
    double volume() override
    {
        return 2 * _d1 * _d2;
    }

    void name()
    {
        std::cout << "I am cylinder" << std::endl;
    }
};

Figure* random_object()
{
    switch(std::rand() % 3)
    {
        case 0: return new SphereCap;
        case 1: return new Ellipsoid;
        default: return new Cylinder;
    }
}

int main()
{
    std::srand(std::time(0));

    Figure *fig = random_object();
    fig->name();

    if(dynamic_cast<Ellipsoid*>(fig) != nullptr)
    {
        double d1, d2, d3;
        std::cout << "Input three semi-axes values:" << std::endl;
        std::cin >> d1 >> d2 >> d3;
        fig->set_dim(d1, d2, d3);
    }
    else
    {
        double r, h;
        std::cout << "Input radius and height:" << std::endl;
        std::cin >> r >> h;
        fig->set_dim(r, h); 
    }

    std::cout << "Volume of figure: " << fig->volume() << std::endl;

    return 0;
}