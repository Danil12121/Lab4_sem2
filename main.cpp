#include <iostream>
#include <cmath>
#include <string>

using namespace std;
class MyException : public invalid_argument {
    double a, b, c;

public:
    MyException(double a, double b, double c, double D, const string& message): invalid_argument(message), a(a), b(b), c(c) {}

    void print() const {
        cout << what() << endl;
        cout  << a << "x^2 + " << b << "x + " << c << " = 0  have no roots" << endl;
    }
};

class Quadratic {
    double a, b, c;

public:
    Quadratic(double a, double b, double c) : a(a), b(b), c(c) {}

    pair<double, double> solve() const {
        double discriminant = b * b - 4 * a * c;

        if (discriminant < 0) {
            throw MyException(a, b, c, discriminant,"critical failure");
        }
        double x1 = (-b + sqrt(discriminant)) / (2 * a);
        double x2 = (-b - sqrt(discriminant)) / (2 * a);

        return make_pair(x1, x2);
    }

    void print() const {
        cout << a << "x^2 + " << b << "x + " << c << " = 0\n";
    }
};

int main() {
    try {
        Quadratic eq0(1, -5, 6);
        eq0.print();

        auto roots0 = eq0.solve();
        cout << "x1 = " << roots0.first<< ", x2 = " << roots0.second << "\n\n";

        Quadratic eq1(4, -5, 6);
        eq1.print();

        auto roots1 = eq1.solve();
        cout << "x1 = " << roots1.first<< ", x2 = " << roots1.second << "\n\n";
    }
    catch (MyException& e) {
        cerr << "Exception: " << e.what() << endl;
        e.print();
    }

    return 0;
}
