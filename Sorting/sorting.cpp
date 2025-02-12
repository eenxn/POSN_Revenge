#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

void bubbleSort(vector<int> &vect)
{
    bool is_swap = false;
    for(int i=0; i<vect.size(); i++)
    {
        for(int j=0; j<vect.size() - 1; j++)
        {
            if(vect[j] > vect[j+1])
            {
                std::swap(vect[j], vect[j+1]);
                is_swap = true;
            }
        }
        if(!is_swap)
        {
            break;
        }
    }
}
void selectionSort(vector<int> &vect)
{
    int key;
    for(int i=0; i<vect.size(); i++)
    {
        int min = INT_MAX;
        for(int j=i; j<vect.size(); j++)
        {
            if(vect[j] < min)
            {
                min = vect[j];
                key = j;
            }
        }
        std::swap(vect[i], vect[key]);
    }
}

void insertionSort(vector<int> &vect)
{
    for(int i=1; i<vect.size(); i++)
    {
        int key = vect[i];
        int left_index = i-1;
        while(left_index >= 0 && vect[left_index] > key)
        {
            vect[left_index + 1] = vect[left_index];
            left_index--;
        }
        vect[left_index +1] = key;
    }
}

int partition(vector<int> &vect, int low, int high)
{
    int pivot = vect[high];
    int pivotIndex = low - 1;

    for (int i = low; i < high; i++)
    {
        if (vect[i] < pivot)
        {
            std::swap(vect[i], vect[++pivotIndex]);
        }
    }

    std::swap(vect[++pivotIndex], vect[high]);

    return (pivotIndex);
}

void quickSort(vector<int> &vect, int low, int high)
{
    if (low < high)
    {
        int pivotPos = partition(vect, low, high);
        quickSort(vect, low, pivotPos - 1);
        quickSort(vect, pivotPos + 1, high);
    }
}