#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
    const char* expr = "x^4+15*x^3-3*x^2+x-2";
    double x = 3.14;
    double newx;
    double counts[99] = { 0 };
    double koef = 0; 
    int j = 0;
    char znak = ' ';
    double count = 0;
    for (int i = 0; expr[i] != 0; i++) {
        newx = x;
        if (expr[i] == '/')
            znak = '/';
        if (expr[i] == '*')
            znak = '*';
        if (expr[i] == '+' || expr[i] == '-' || expr[i + 1] == 'x')
            znak = ' ';
        if (expr[i] >= '0' && expr[i] <= '9') //Если нашли коэффициент или число
            koef = koef * 10 + (expr[i] - '0');
        if (expr[i - 1] == '-')
            koef *= -1;
        if (expr[i] == 'x') {
            if (expr[i + 2] >= '0' && expr[i + 2] <= '9' && expr[i + 1] == '^') {
                newx = pow(x, ((expr[i + 2]) - '0'));
                i += 2;
            }
            if (koef != 0)
                koef *= newx;
            if (koef == 0) {
                koef = newx;
                if (expr[i - 3] == '-')
                    koef *= -1;
            }
            counts[j] = koef;
            j++;
            koef = 0;
        }
        if ((expr[i] < '0' && expr[i] > '9') || (expr[i+1] == 0)) {
            counts[j] = koef;
            koef = 0;
            j++;    
        }
        if (znak == '/') {
            counts[j - 1] = counts[j - 1] / counts[j];
            counts[j] = 0;
        }
        if (znak == '*') {
            counts[j - 1] = counts[j - 1] * counts[j];
            counts[j] = 0;
        }
    }
    for (int i = 0; counts[i] != 0; i++) {
        count += counts[i];
    }
    printf("%lf", count);
    return 0;
}