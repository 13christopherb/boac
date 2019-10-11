#include <math.h>
#include <stdlib.h>
#include "helpers.h"

/**
 * Finds the index of the closest value in a sorted array
 * @param arr sorted array
 * @param l index of the left most value of interest
 * @param r index of the right most value of interest
 * @param x value to search for
 * @return index of the closest value in the array
 */
int findClosestValue(int arr[], int l, int r, int x)
{
    int mid = l + (r - l) / 2;
    if (r >= l) {
        if (arr[mid] == x)
            return mid;

        if (arr[mid] > x)
            return findClosestValue(arr, l, mid - 1, x);

        return findClosestValue(arr, mid + 1, r, x);
    }

    return mid;
}

void swap(double *a, double *b) {
    double t = *a;
    *a = *b;
    *b = t;
}

int partition(double arr[], int low, int high) {
    double pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(double* arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

double median(const double arr[], int length) {
    double *copy = (double *)malloc(length * sizeof(double));
    double median;
    for (int i = 0; i < length; i++) {
        copy[i] = arr[i];
    }

    quickSort(copy, 0, length - 1);
    if (length % 2 == 0) {
        median = (copy[((length-1) / 2) - 1] + copy[(length-1) / 2]) / 2;
    } else {
        median = copy[(int) round((length-1) / 2.0)];
    }
    free(copy);
    return median;
}
