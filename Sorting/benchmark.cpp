#include <iostream>
#include <chrono>
#include <vector>
#include <random>
#include <algorithm>
#include "sorting.cpp"

using namespace std;

template <typename Func>
double measureTime(Func f)
{
    auto start = std::chrono::high_resolution_clock::now();
    f();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_time = end - start;
    
    return elapsed_time.count();
}

vector<int> generateRandomVector(size_t size, int minVal = 0, int maxVal = 100000)
{
    static std::mt19937_64 rng(std::random_device{}());
    std::uniform_int_distribution<int> dist(minVal, maxVal);

    vector<int> vec(size);
    for (size_t i = 0; i < size; ++i)
    {
        vec[i] = dist(rng);
    }
    return (vec);
}

int main()
{
    vector<int> testSize = {5, 50, 100, 500, 1000, 5000, 10000, 50000};

    int trial = 5;


    for (int size: testSize)
    {
        double totalStdSort = 0.0;
        double totalBubbleSort = 0.0;
        double totalSelectionSort = 0.0;
        double totalInsertionSort = 0.0;
        double totalQuickSort = 0.0;

        for (int i = 1; i <= trial; i++)
        {
            std::vector<int> data = generateRandomVector(size);

            auto data4StdSort = data;
            auto data4BubbleSort = data;
            auto data4SelectionSort = data;
            auto data4InsertionSort = data;
            auto data4QuickSort = data;

            double timeStd = measureTime([&]
            {
                std::sort(data4StdSort.begin(), data4StdSort.end());
            });

            totalStdSort += timeStd;

            double timeBubble = measureTime([&]
            {
                bubbleSort(data4BubbleSort);
            }
            );

            totalBubbleSort += timeBubble;

            double timeSelection = measureTime([&]
            {
                selectionSort(data4SelectionSort);
            }
            );

            totalSelectionSort += timeSelection;

            double timeInsertion = measureTime([&]
            {
                insertionSort(data4InsertionSort);
            }
            );

            totalInsertionSort += timeInsertion;

            double timeQuickSort = measureTime([&]
            {
                quickSort(data4QuickSort, 0, data4QuickSort.size() - 1);
            });

            totalQuickSort += timeQuickSort;
        }

        cout << "Array Size:" << size << endl;
        cout << "std::sort:      " << totalStdSort / trial * 1000 << " ms" << endl;
        cout << "Bubble sort:    " << totalBubbleSort / trial * 1000 << " ms" << endl;
        cout << "Selection sort: " << totalSelectionSort / trial * 1000 << " ms" << endl;
        cout << "Insertion sort: " << totalInsertionSort / trial * 1000 << " ms" << endl;
        cout << "Quick sort:     " << totalQuickSort / trial * 1000 << " ms" << endl;
        cout << "-------------------------------------" << endl;
    }


    return (0);
}