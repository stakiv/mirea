// pr2.2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream> // номер 2
#include <cmath>

using namespace std;

class Circle
{
private:
    float radius, x_center, y_center;
    float const PI = 3.1415926535;
public:

    void set_circle(float r, float x, float y)
    {
        radius = r;
        x_center = x;
        y_center = y;
    }
    float square()
    {
        return PI * radius * radius;
    }
    bool triangle_around(float a, float b, float c)
    {
        float s = PI * radius * radius;
        return a * b * c / (4 * s) == radius;
    }
    bool triangle_in(float a, float b, float c)
    {
        float s = PI * radius * radius;
        return 2 * s / (a + b + c) == radius;
    }
    bool check_circle(float r1, float x1, float y1)
    {
        return sqrt((x1 - x_center) * (x1 - x_center) + (y1 - y_center) * (y1 - y_center)) < r1 + radius;
    }
};
int main()
{
    Circle mas[3];
    float r, x, y, a, b, c;
    float r1, x1, y1;
    for (int i = 0; i < 3; i++)
    {
        cout << "Enter r, x, y for circle № " << i + 1 << endl;
        cin >> r >> x >> y;
        mas[i].set_circle(r, x, y);
    }
    cout << "Enter a, b, c for triangle " << endl;
    cin >> a >> b >> c;
    cout << "Enter r, x, y for another circle " << endl;
    cin >> r1 >> x1 >> y1;
    cout << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << "circle " << i + 1 << endl;
        cout << "Square: " << mas[i].square() << endl;

        if (mas[i].triangle_around(a, b, c))
        {
            cout << "circle can be described around a triangle" << endl;
        }
        else
        {
            cout << "circle can't be described around a triangle" << endl;
        }
        if (mas[i].triangle_in(a, b, c))
        {
            cout << "triangle can be inscribed with circle" << endl;
        }
        else
        {
            cout << "triangle can't be inscribed with circle" << endl;
        }
        if (mas[i].check_circle(r1, x1, y1))
        {
            cout << "the circles intersect" << endl;
        }
        else
        {
            cout << "the circles don't intersect" << endl;
        }
        cout << endl;

    }
}