#include <iostream>

void fillIntRandom(int* array, int size, int border)
{
//заполнение массива псевдослучайными числами
    for (int i = 0; i < size; ++i)
        *(array + i) = rand() % border;
}

void printArr(int *array, int len)
{
    //вывод массива на печать
    for (int i=0;i<len;i++)
        printf("%d ",*(array + i));
    printf ("\n");
}
void swapInt(int *a, int *b)
{
    //обмен значений двух переменных
    int t = *a;
    *a = *b;
    *b = t;
}
void insertSort (int *a, int startIndex, int finishIndex)
{
    //сортировка вставками
    int temp,pos;
    for(int i=startIndex+1; i<=finishIndex;i++)
    {
       temp=a[i];
       pos=i-1;
       while (pos>=0 && a[pos]>temp)
       {
           a[pos+1]=a[pos];
           pos--;
       }
       a[pos+1] = temp;
    }
}
int findMedian(int *a, int firsrt, int mid,  int fin)
{
    //поиск среднего из трех значений массива
    if (((a[firsrt] > a[mid]) && (a[firsrt] < a[fin]))||
        ((a[firsrt] > a[fin]) && (a[firsrt] < a[mid])))
        return firsrt;
    else if (((a[fin] > a[mid]) && (a[fin] < a[firsrt])) ||
        ((a[fin] > a[firsrt]) && (a[fin] < a[mid])))
        return fin;
    return mid;

}

void busketEvenSort(int *a, int len)
{
//блочная сортировка только честных чисел последовательности
    const int max = len;
    const int countOfBusket = 10;
    int buskets[countOfBusket][max+1];

    for (int i = 0; i<countOfBusket;i++)
    {
        buskets[i][max] = 0;
    }

    for (int digit =1; digit<1000000000;digit*=10)
    {

        for(int i=0;i<max;i++)
        {
            int d = (a[i]/digit)%countOfBusket;
            if (a[i]%2==0)
            //толькочетные числа учавствуют в сортировке
                buskets[d][buskets[d][max]++]=a[i];
        }
        int index =0;
        for (int i=0;i<countOfBusket;i++)
        {
            for (int j=0;j<buskets[i][max];)
            {
                if(a[index]%2==0)
                    //если было четное на месте индекса забираю
                    //его из корзины и счетчик индекса в корзине увеличиваю
                    a[index]=buskets[i][j++];
                //иначе - если из корзины ничего не забрала, то и счетчик не увеличиваю
                //только индекс в исходном массиве
                index++;

            }
            buskets[i][max]=0;
        }
    }

}

void improveQuickSort(int *a, int startIndex, int finishIndex)
{
    //улучшеная быстрая сортировка
    int len=finishIndex-startIndex;
    //для массиба из больше, чем 10 элементов - сортировка Хоара с изменениями
    if (len>10)
    {
        int midIndex= (finishIndex+startIndex)/2;
        int swapIndex= findMedian(a, startIndex, midIndex, finishIndex);
        swapInt(&a[midIndex], &a[swapIndex]);

        // в качестве опроного беру средний  по значеню из
        //начального, последнего и среднего по счету элементов
        int i = startIndex;
        int j = finishIndex;
        int x = a[midIndex];
        //делю массив на две части  - с элементами меньшн и больше медианного
        do {
            while (a[i] < x) i++;
            while (a[j] > x) j--;

            if (i <= j)
            {
                swapInt(&a[i], &a[j]);
                i++;
                j--;
            }
        } while (i <= j);
        //оба их снова сортирую
        if (i < finishIndex) improveQuickSort(a, i, finishIndex);
        if (startIndex < j) improveQuickSort(a, startIndex, j);
    }
    else
    {//если 10 и меньше элементов в массиве - сортировка вставками
       insertSort(a, startIndex,  finishIndex);

    }

}
int main()
{
    const int len=45;
    int arr[len], arr2[len];
    fillIntRandom(arr, len, 100);
    fillIntRandom(arr2,len,100);
    printArr(arr, len);
    improveQuickSort(arr,0,len);
    printArr(arr,len);
    printArr(arr2,len);
    busketEvenSort(arr2,len);
    printArr(arr2,len);
    return 0;
}
