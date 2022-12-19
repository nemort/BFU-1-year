#include <stdio.h>
#include <string.h>

//x = 1 + 2  	x = 1 - 2	x = 1 * 2	x = 2 / 2	x = 3 % 2  var1
//x + 1 = 2  	x - 1 = 2	x * 1 = 2	x / 4 = 2	           var2
//
//1 = 2 + x  	1 = 2 - x	4 = 2 * x	4 = 8 / x	           var3
//1 + 2 = x 	1 - 2 = x	1 * 2 = x	4 / 2 = x	3 % 2 = x  var1
//
//1 = x + 2  	1 = x - 2	4 = x * 2	4 = x / 2	           var3
//1 + x = 2 	1 - x = 2	1 * x = 2	4 / x = 2	           var2

int Calc(char* exp) {
    int number1, number2, var, minus = 1;
    char sym;
    if (exp[0] == 'x') {
        number1 = (exp[2] - '0');
        number2 = (exp[4] - '0');
        if (exp[1] == '=') {
            sym = (exp[3]);
            var = 1;
        }
        else {
            sym = (exp[1]);
            var = 2;
        }
    }
    if (exp[4] == 'x') { 
        if (exp[3] == '-')
            minus = -1;
        number1 = (exp[0] - '0');
        number2 = (exp[2] - '0');
        if (exp[1] == '=') {
            sym = exp[3];
            var = 3;
        }
        else {
            sym = (exp[1]);
            var = 1;
        }
    }
    if (exp[2] == 'x') {
        if (exp[1] == '-')
            minus = -1;
        number1 = (exp[0] - '0');
        number2 = (exp[4] - '0');
        if (exp[1] == '=') {
            sym = exp[3];
            var = 3;
        }
        else {
            sym = (exp[1]);
            var = 2;
        }
    }
    if (var == 1) {
        switch (sym) {
        case '+': return (number1 + number2); break;
        case '-': return (number1 - number2); break;
        case '*': return (number1 * number2); break;
        case '/': return (number1 / number2); break;
        case '%': return (number1 % number2); break;
        }
    }
    if (var == 2) {
        switch (sym){
        case '+': return (number2 - number1); break;
        case '-': return (minus * (number2 + number1)); break;
        case '*': return (number2 / number1); break;
        }
    }
    if (var == 3) {
        switch (sym) {
        case '+': return (number1 - number2); break;
        case '-': return (minus * (number1 + number2)); break;
        case '*': return (number1 / number2); break;
        }
    }
    if (var == 3 && exp[4] == 'x' && sym == '/')
        return (number2 / number1);
    if (var == 2 && exp[2] == 'x' && sym == '/')
        return (number1 / number2);
    else
        return (number1 * number2);
    return 0;
}
int main() {
    char* expression[] = {"x=1+2","x=1-2","x=1*2","x=2/2","x=3%2","x+1=2","x-1=2","x*1=2","x/4=2","1=2+x","1=2-x","4=2*x","4=8/x","1+2=x","1-2=x","1*2=x","4/2=x","3%2=x","1=x+2","1=x-2","4=x*2","4=x/2","1+x=2","1-x=2","1*x=2","4/x=2"};
    
    int len = sizeof(expression) / sizeof(char*);

    for (int i = 0; i < len; i++)
        printf("%s x=%d\n", expression[i], Calc(expression[i]));
    return 0;
}