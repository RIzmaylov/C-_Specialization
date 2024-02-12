#include <iostream>
#include <cmath>

void equation(double a, double b, double c, double& x1, double& x2) {
    if (a == 0.0) {
        x1 = x2 = -c / b;
        return;
    }
    if (b == 0.0 && -c / a >= 0) {
        x1 = sqrt(-c / a);
        x2 = -x1;
        return;
    }
    double D = b * b - 4 * a * c;
    if (D < 0) return;
    if (D == 0.0) {
        x1 = -b / (2 * a);
        x2 = x1;
        return;
    }
    if (D > 0.0) {
        x1 = (-b + sqrt(D)) / (2 * a);
        x2 = (-b - sqrt(D)) / (2 * a);
        return;
    } 
}

int main() {
    double a, b, c;
    std::cin >> a >> b >> c;
    double x1, x2;
    equation(a, b, c, x1, x2);
    if (x1 == x2 && x1 != 0 && x2 != 0)
        std::cout << x1 << std::endl;
    else if (x1 != 0 && x2 != 0)
        std::cout << x1 << ' ' << x2 << std::endl;
    return 0;
}