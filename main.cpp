#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>

//инициализация двумерного массива
int** initArray(int** array, const int row, const int col)
{
    array = (int**) calloc(sizeof(int*), row);
    for (int i = 0; i < row; ++i)
    {
        *(array + i) = (int*) calloc(sizeof(int), col);
    }
    return array;
}
//вывод двумерного массива на экран
void printArray(int** array, const int row, const int col)
{
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            printf("%4d", *((*(array + i)) + j));
        }
        printf("\n");
    }
}
//заполнение псевдослучайными значениями двумерного массива
void fillArray(int** array, const int row, const int col, int border)
{
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            (*((*(array + i)) + j)) = rand()%border;
        }
    }
}
//обмен значениями двух переменных
void swapInt(int &a, int &b)
{
    a = a ^ b;
    b = b ^ a;
    a = a ^ b;
}
//освобождение памяти после завершения работы с двумерным массивом
//Вы писали, что принимаете предложения для расширения библиотеки.
//отсутвие освобождения памяти - это то чего не хватает во всех видео по алгоритмам
void freeMem(int** array,const int row)
{
    for (int i = 0; i <row; i++)
    {
        free(array[i]);
    }
    free(array);
}
//пузырьковая сортировка двумерного массива
void buble2Sort(int** array, const int row, const int col)
{
    for(int k=0;k<row*col;k++)
    {
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                //тут наверняка можно сделать проще или более читаемо,
                //особенно если инициализировать массив иначе - как одномерный и
                //поботом общаться с ним как-будто с двумерным,
                if((j==(col-1))&&(i!=(row-1)))
                {
                    if ( *((*(array + i)) + j) > *(*(array + i+1) ) )
                        swapInt((*((*(array + i)) + j)) , (*((*(array + i+1)) )));
                }
                else if(j!=(col-1))
                {
                    if ( *((*(array + i)) + j) > *((*(array + i)) + j+1) )
                        swapInt(*((*(array + i)) + j) , *((*(array + i)) + j+1));
                }
            }
        }
    }
}
//функция вычисления математического выражения для алгоритма ТПК
double f(double x)
{
    return (sqrt(fabs(x)) + 5 * pow(x, 3));
}
//алгоритм ТПК
void algorithmTPK()
{
    double arr[11], rezult;
    int i=0;
    printf("Введите 11 чисел: \n");
    for(i=0;i<11;i++)
        scanf("%lf",&arr[i]);
    int k=1;
    for(i=10;i>=0;i--,k++)
    {
        printf ("%d: ",k);
        rezult=f(arr[i]);
        if (rezult>400)
        printf ("Значение выражения sqrt(fabs(%.3f)) + 5 * pow(%.3f, 3) ПРЕВЫШАЕТ 400\n",arr[i],arr[i]);
        else
            printf ("sqrt(fabs(%.3f)) + 5 * pow(%.3f, 3) = %f\n",arr[i],arr[i],rezult);
    }
}
int main()
{
    const int row = 4;
    const int col = 4;
    int** arr=initArray(arr,row,col);
    fillArray(arr,row,col,100);
    printArray(arr,row,col);
    buble2Sort(arr,row,col);
    printf("\n-------------------------\n\n");
    printArray(arr,row,col);
    freeMem(arr,row);
    printf("\n");
    algorithmTPK();
    return 0;
}
