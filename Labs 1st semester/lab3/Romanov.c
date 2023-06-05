#include <stdio.h>
#include <string.h>

int abba(int mas[8]) {
    int count = 0;
    char abba[8][8] = { '0' };
    char aplphabet[] = "0123456789ABCDEF";
    int x;
    int k = 0;
    char newabba[73] = { '0' };
    int variants[] = {-1, 1, 9, -9}; //Варианты перемещения лево, право, вниз, вверх (9, а не 8 потому что я добавлю далее 0 в конце строк)
    for (int i = 0; i <= 7; i++) {
        for (int j = 0; j <= 7; j++) {
            x = aplphabet[(mas[i] >> (4 * j)) & 0xF];
            abba[i][7 - j] = x;
        }
    }
    for (int i = 0; i <= 7; i++) {
        for (int j = 0; j <= 7; j++) {
            newabba[k] = abba[i][j];
            k++;
        }
        newabba[k] = '0'; // добавляю 0, чтобы не считались последний и первый символ на разных строках
        k++;
    }
    newabba[k] = 'Z';
    for (int i = 0; newabba[i] != 'Z'; i++) {
        for (int j = 0; j <= 3; j++)
            for (int k = 0; k <= 3; k++)
                for (int l = 0; l <= 3; l++) {
                    if (newabba[i] == 'A' && newabba[i + j] == 'B' && newabba[i + k] == 'B' && newabba[i + l] == 'A')                        count++;
                    }
    }
    printf("%d\n", count / 2); //делю на 2, потому что не учитываю в цикле, что может посчитать обратно
    return 0;
}
int main() {
    int sample1[8] = {-1413863686, -1146374827, -1162027246, -1442185216, 184549376, 11534336, 655360, 179026592};
    int sample2[8] = { -1430650880, -1157627904, 3145728, -1442185216, 184549376, 11534336, 655360, 3840 };
    abba(sample1);
    return 0;
}