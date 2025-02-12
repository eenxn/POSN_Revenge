#include <iostream>
#include <time.h>
#include <random>
#include "sorting.cpp"

using namespace std;

void display(vector<int> &vect)
{
    for (vector<int>::iterator it = vect.begin(); it != vect.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    srand(time(0));
    vector<int> v = {5, 4, 3, 12, 5, 10, 14, 6, 7, 1};
    cout << "Data: ";
    display(v);

    cout << "Bubble sort" << endl;
    bubbleSort(v);
    display(v);

    v = {5, 4, 3, 12, 5, 10, 14, 6, 7, 1};
    cout << "Selection sort" << endl;
    selectionSort(v);
    display(v);

    v = {5, 4, 3, 12, 5, 10, 14, 6, 7, 1};
    cout << "Insertion sort" << endl;
    insertionSort(v);
    display(v);

    v = {5, 4, 3, 12, 5, 10, 14, 6, 7, 1};
    cout << "Quick sort" << endl;
    quickSort(v, 0, v.size() - 1);
    display(v);
    
    return (0);
}