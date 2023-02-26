

#include <iostream> // номер 1
#include <cmath>

using namespace std;

class Triangle {
private:
    double a, b, c;

public:
    bool exst_tr()
    {
        return ((a + b > c) && (b + c > a) && (a + c > b));
    }
    void set(double a1, double b1, double c1)
    {
        a = a1;
        b = b1;
        c = c1;
    }
    void show() {
        cout << "side 1: " << a << endl;
        cout << "side 2: " << b << endl;
        cout << "side 3: " << c << endl;
    }
    double perimetr()
    {
        double p = a + b + c;
        return p;
    }
    double square()
    {
        double p = (a + b + c) / 2;
        double s = sqrt(p * (p - a) * (p - b) * (p - c));
        return s;
    }
};

int main()
{
    Triangle mas[3];
    double a, b, c;
    for (int i = 0; i < 3; i++)
    {
        cout << "Enter a, b, c for triangle № " << i + 1 << endl;
        cin >> a >> b >> c;
        mas[i].set(a, b, c);
        if (!(mas[i].exst_tr()))
        {
            mas[i].show();
            cout << "this triangle doesn't exist, try again" << endl;
            i--;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        mas[i].show();
        cout << "perimeter: " << mas[i].perimetr() << endl;
        cout << "square: " << mas[i].square() << endl;
    }
    return 0;
}
