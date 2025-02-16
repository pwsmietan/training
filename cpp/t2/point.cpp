#include <iostream>

struct Point
{
    double x, y;
};

struct Rect
{
    double x, y, w, h;

    bool contains(const Point &p)
    {
        return p.x >= x && p.y >= y && p.x <= x + w && p.y <= y + h;
    }
};

int main()
{
    Point pts;
    std::cout << "Type in your x location:\n";
    std::cin >> pts.x;
    std::cout << "Type in your y location:\n";
    std::cin >> pts.y;

    Rect r({0, 0, 20, 10});
    bool isSurrounded = r.contains(pts);  //{pts.x, pts.y});

    if(isSurrounded)
        std::cout << "You are completely surrounded. Don't move!\n";
    else
        std::cout << "You're out of reach!\n";
        
    return 0;
}