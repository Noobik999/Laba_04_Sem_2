#include <iostream>
using namespace std;

class Square {
protected:
    double a;

public:
    Square(double x) {
        a = x;
    }

    virtual double P() {
        return 4 * a;
    }

    virtual void Print() {
        cout << "Квадрат: сторона = " << a << ", периметр = " << P() << endl;
    }
};

class Rectangle : public Square {
private:
    double b;

public:
    Rectangle(double x, double y) : Square(x) {
        b = y;
    }

    double P() {
        return 2 * (a + b);
    }

    void Print() {
        cout << "Прямоугольник: стороны = " << a << " и " << b << ", периметр = " << P() << endl;
    }
};

int main() {
    Square obj1(5);
    Rectangle obj2(4, 7);

    cout << "Статический полиморфизм (обычные объекты)" << endl;
    obj1.Print();
    obj2.Print();

    cout << endl << "Динамический полиморфизм (указатели базового класса)" << endl;

    Square *p;

    p = &obj1;
    p->Print();

    p = &obj2;
    p->Print();

    cout << endl << "Без virtual вызвался бы метод Square для Rectangle" << endl;

    return 0;
}