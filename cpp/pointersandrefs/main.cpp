#include <iostream>

using namespace std;

struct Rectangle
{
    int length;
    int breadth;
};

void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

struct Rectangle *mkrect()
{
    // Create object in heap memory C++ way:
    struct Rectangle *p = new Rectangle;
    // Same but C way:
    // p = (struct Rectangle *)malloc(sizeof(struct Rectangle));
    //free(p);

    p->breadth = 21;
    p->length = 17;

    return p;
}

int main(int argc, char **argv)
{
    int a[5] = {0, 1, 2, 3, 4};
    int *p = &a[0];

    cout << "Pointer p is " << sizeof(p) << " bytes." << endl;
    cout << "The address of p: " << p << endl;

    /*
        for(int i = 0; i < 5; i++){
            cout << p[i] << endl;
        }
    */
    for (int i = 0; i < 5; i++)
    {
        cout << *p++ << endl;
    }

    cout << "All pointers are 8-bytes long" << endl;
    int *p1;
    char *p2;
    double *p3;
    long *p4;
    cout << sizeof(p1) << endl;
    cout << sizeof(p2) << endl;
    cout << sizeof(p3) << endl;
    cout << sizeof(p4) << endl;

    cout << "use reference/alias:" << endl;
    int b = 10;
    int &r = b; // r is an alilas
    b = 44;
    cout << b << endl
         << r << endl;

    cout << "Create a dynamic object to store in heap via pointer - The C Way:" << endl;
    struct Rectangle *pr;
    pr = (struct Rectangle *)malloc(sizeof(struct Rectangle));
    pr->length = 10;
    pr->breadth = 22;
    cout << pr->length << " " << pr->breadth << " " << "pr: " << pr << " &pr: " << &pr << endl;
    free(pr);

    cout << "Fun with integers" << endl;
    int x = 10, y = 20;
    cout << "Before swap()" << endl;
    cout << x << " " << y << endl;
    cout << "Swapping two variables using pass by reference (C++)" << endl;
    swap(x, y);
    cout << x << " " << y << endl;

    // loop throuogh array using cool shorthand:
    int arr[] = {1, 2, 3, 4, 5};
    for (int x : arr)
        cout << x << " ";

    cout << "\nMaking a rectangle via pointers" << endl;
    Rectangle *r2 = mkrect();
    cout << r2->length << " " << r2->breadth << endl;

    return 0;
}
