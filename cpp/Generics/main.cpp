#include <iostream>
#include <stdio.h>

using namespace std;

template <class T>
class Arithmetic
{
private:
    T a;
    T b;

public:
    Arithmetic(T a, T b);
    T add();
    T sub();
};

// The following implementations are separated in case I want to put this code into a separate file.
// Need to use scope resolution: xyz::xyz
template <class T>
Arithmetic<T>::Arithmetic(T a, T b)
{
    this->a = a;
    this->b = b;
}

template <class T>
T Arithmetic<T>::add()
{
    return a + b;
}

template <class T>
T Arithmetic<T>::sub()
{
    return a - b;
}

int main(int argc, char **argv)
{
    Arithmetic<int> ar = Arithmetic(100, 25);
    cout << ar.add() << endl;
    cout << ar.sub() << endl;

    Arithmetic<double> arf = Arithmetic(1.1, 2.2);
    cout << arf.add() << endl;

    return 0;
}