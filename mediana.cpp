/* 
   Медиана в массив из n чисел 
   с плавающей запятой.'
*/
#include <Windows.h>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;
void fast_sort(double* , int);
void median(double* , int);
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
    int size;
    cout << "Введите кол-во элементов в массиве: ";
    cin >> size;
    double* arr = new double[size];
    srand(time(0));
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() / static_cast<double>(rand());
        cout << "arr[" << i << "] = " << arr[i] << endl;
    }
    fast_sort(arr, size);
    cout << endl;
    median(arr, size);
    delete[] arr;
	system("pause");
	return 0;
}
void fast_sort(double* arr, int size)
{
    double hold;
    int i = 0;
    int j = size - 1;
    double mid = arr[size / 2];
    do
    {
        while (arr[i] < mid)
            i++;
        while (arr[j] > mid)
            j--;
        if (i <= j)
        {
            hold = arr[i];
            arr[i] = arr[j];
            arr[j] = hold;

            i++;
            j--;
        }
    } while (i <= j);
    if (j > 0)
        fast_sort(arr, j + 1);
    if (i < size)
        fast_sort(&arr[i], size - i);
}
void median(double* arr, int size)
{
    double mediana;
    if (size % 2 == 1)
    {
        mediana = arr[size / 2];
        cout << endl << mediana << " - медиана" << endl;
    }
    else
    {
        mediana = (arr[size / 2 - 1] + arr[size / 2]) / 2;
        cout << endl << mediana << " - медиана" << endl;
    }
}
