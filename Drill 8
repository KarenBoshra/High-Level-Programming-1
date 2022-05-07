#include "std_lib_facilities.h"

void print (int a, int b)
{
    cout << "After Swap: " << a << '\t' << b << endl;
}

void swap_v (int a, int b)
{
    int temp;
    temp = a, a = b;
    b = temp;
    print(a,b);
}

void swap_r (int& a, int& b)
{
    int temp;
    temp = a, a = b;
    b = temp;
    print(a,b);
}

void swap_cr (const int& a, const int& b)
{
    int temp, temp2;
    temp = a;
    temp2 = b;
    swap_r(temp, temp2);
}
int main()
{
    int x = 7;
    int y = 9;
    swap_v(x, y);
    swap_v(7, 9);
    const int cx = 7;
    const int cy = 9;
    swap_cr(cx, cy);
    swap_cr(7.7, 9.9);
    double dx = 7.7;
    double dy = 9.9;
    swap_v(dx, dy);
    swap_v(7.7, 9.9);

    cout << "x: " << x << '\n'
         << "y: " << y << '\n'
         << "cx: " << cx << '\n'
         << "cy: " << cy << '\n'
         << "dx: " << dx << '\n'
         << "dy: " << dy << '\n';
}
