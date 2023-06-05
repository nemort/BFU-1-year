#include <stdio.h>
#include <math.h>

float traverse_clockwise(float coord[], int n) {
    float count1 = 0, count2 = 0;
    float radians[50] = {4};
    float radiansx[50] = { 0 };
    float radiansy[50] = { 0 };
    float count = 0;
    float oldmax = 99;
    float newmax = 0;
    float newcoordx[50] = { 4 };
    float newcoordy[50] = { 4 };
    int j = 0;
    for (int i = 0; i != n * 2; i++) {
        if (i % 2 == 0)
            count1 += coord[i];
        else
            count2 += coord[i];
    }
    for (int i = 0; i != n * 2; i++) {
        if (i % 2 != 0) 
            coord[i] = coord[i] - count2 / n;
        else 
            coord[i] = coord[i] - count1 / n;
    }
    for (int i = 0; i != 2 * n; i += 2) {
        radians[j] = atan2(coord[i + 1], coord[i]);
        radiansx[j] = coord[i];
        radiansy[j] = coord[i + 1];
        j++;
    }
    for (int i = 0; i != n; i++) {
        for (int j = 0; j != n; j++)
            if (newmax < radians[j] && radians[j] < oldmax) {
                newmax = radians[j];
                newcoordx[i] = radiansx[j];
                newcoordy[i] = radiansy[j];
            }
        oldmax = newmax;
        newmax = 99;
    }
    for (int i = 0; i != n; i++) 
        count += sqrt(pow(newcoordx[i + 1] - newcoordx[i], 2) + pow(newcoordx[i + 1] - newcoordx[i], 2));
    return count;
    return 0;
}

int main() {
    float rect[] = { 1,5,7,1,7,5,1,1 };
    float star[] = { 3.97, 0.82, 2.26, 3.69, 5.39, 2.16, 2.03, 2.11, 5.36, 4.06 };
    float enneagon[] = { 76, 67.1, -8.3, 18, 55, 93.3, 77, 33, 21.3, 99, -20, 50, -8.3, 82, 55, 6.7,  21.3, 0.76 };
    int n1 = 4;
    int n2 = 5;
    int n3 = 9;
    printf("%f\n", traverse_clockwise(rect, n1));
    printf("%f\n", traverse_clockwise(star, n1));
    printf("%f", traverse_clockwise(enneagon, n1));
    return 0;
}