#include <iostream>
#include <cmath>

class Point
{
    friend double distance(const Point &from, const Point &to);

public:
    // methods
    // Point() = default;
    Point() = delete;
    // Point()
    // {
    //     m_x = 0;
    //     m_y = 0;
    // }
    Point(double x, double y) : m_x(x), m_y(y)
    {
    }
    double distance_to(Point target)
    {
        return sqrt(pow(target.m_x - m_x, 2) + pow(target.m_y - m_y, 2) * 1.0);
    }
    void print_info()
    {
        std::cout << "Point [ x : " << m_x << ", y: " << m_y << "]" << std::endl;
    }
    // member variables
private:
    double m_x{1};
    double m_y{1};
};

double distance(const Point &from, const Point &to)
{
    return std::sqrt(pow(to.m_x - from.m_x, 2) + pow(to.m_y - from.m_y, 2) * 1.0);
}
int main()
{
    Point p1;
    p1.print_info();
    return 0;
}