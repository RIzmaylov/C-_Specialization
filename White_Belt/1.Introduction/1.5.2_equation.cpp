#include <iostream>
#include <algorithm>
#include <math.h>

int main()
{
    double EPSILON = 1e-6;
    double a, b, c;
    std::cin >> a >> b >> c;
    double answer1 = 0;
    if (std::abs(a - 0.0) <= EPSILON && std::abs(b - 0.0) > EPSILON && std::abs(c - 0.0) > EPSILON) { 
        answer1 = (-c) / b; std::cout << answer1; 
    }
    //else if (c == 0) std::cout << (-b) / a;
    else if (std::abs(a - 0.0) > EPSILON) {
        double discriminant = b * b - 4 * a * c;
        if (std::abs(discriminant - 0.0) <= EPSILON) {
            answer1 = (-b) / (2 * a);
            std::cout << answer1;
        } else if (discriminant > 0) {
            answer1 = ((-b) + sqrt(discriminant)) / (2 * a);
            double answer2 = ((-b) - sqrt(discriminant)) / (2 * a);
            std::cout << answer1 << ' ' << answer2;
        }
    }
    return 0;
}

