/*
 * Edward Cruz, October 17, 2019
 * Lab 6 of Fundamental Programming
 */

#include <iostream>

using namespace std;

void printIt(int a[], int size)
{
    for(int i = 0; i < size; i++)
        cout << a[i] << ", ";
}

void shellSort(int x[], int size)
{
    bool flag;
    int temp;
    int gapSize = size;
    do {
        flag = false;
        gapSize = (gapSize+1)/2;
        for (int i = 0; i < (size - gapSize); i++) {
            if (x[i] > x[i + gapSize]) {
                temp = x[i + gapSize];
                x[i + gapSize] = x[i];
                x[i] = temp;
                flag = true;
            }
        }
    } while(gapSize > 1 || flag);
}

int binarySearch(int x[], int l, int r, int temp)
{
    /*
     * COURTESY OF -
     * https://www.geeksforgeeks.org/binary-search/
     */
    if (r >= l) {
        int mid = l + (r - l) / 2;
        // If the element is present at the middle itself
        if (x[mid] == temp)
            return mid;
        // If element is smaller than mid, the it can only be present in left subarray
        if (x[mid] > temp)
            return binarySearch(x, l, mid - 1, temp);
        // Else the element can only be present in right subarray
        return binarySearch(x, mid + 1, r, temp);
    }
    // We reach here when element is not present in array
    return -1;
}

int main()
{
    int x[] = {25, 16, 92, 81, 65, 59, 48, 31, 67, 27, 14, 9, 52, 38, 61};
    int size = sizeof(x)/ sizeof(*x), num;
    char more;

    cout << "Unsorted Seq: ";
    printIt(x, size);
    cout << "\n  Sorted Seq: ";
    shellSort(x, size);
    printIt(x, size);

    do {
        cout << "\n\t\tInput a number: ";
        cin  >> num;

        if (binarySearch(x, 0, size-1,  num) == -1)
            cout << "\n\t\t" << num << " is not found";
        else
            cout << "\n\t\t" << num << " is found at position " << binarySearch(x, 0, size-1, num)+1;

        cout << "\n\t\t\t\tDo more (Y/N) ?";
        cin >> more;
    } while (more == 'y' || more == 'Y');

    return 0;
}