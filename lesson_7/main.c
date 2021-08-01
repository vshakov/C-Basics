/*Написать программу, которая просит пользователя ввести 2 десятичных числа 
и в качестве результата выводит сумму, произведение, разность и частное этих двух чисел.
Реализовать с помощью ОДНОЙ функции(указатели)

пример заголовка функции: void multi_ariphmetics(int *summ, int *diff, int *mult, int *div)

пример:
ввод:
123
456
вывод:
summ 579
diff -333
mult 56088
div 0*/

#include <stdio.h>

void multi_arifmetics(int number_a, int number_b, int *psumm, int *pdiff, int *pmult, int *pdivv);

int main(int argc, char **argv)

{
    int a,b,summ,diff,mult,divv,*psumm,*pdiff,*pmult,*pdivv;
    psumm = &summ;
    pdiff = &diff;
    pmult = &mult;
    pdivv = &divv;
    printf("Enter two decimal numbers:\n");
    scanf("%d%d", &a, &b);
    printf("a=%d\nb=%d\n",a,b);
    multi_arifmetics(a,b,psumm,pdiff,pmult,pdivv);
    printf("summ=%d\ndiff=%d\nmult=%d\ndiv=%d",summ,diff,mult,divv);
    return 0;
}

void multi_arifmetics(int number_a, int number_b, int *psumm, int *pdiff, int *pmult, int *pdivv)
{
    *psumm=number_a+number_b;
    *pdiff=number_a-number_b;
    *pmult=number_a*number_b;
    *pdivv=number_a/number_b;
}
