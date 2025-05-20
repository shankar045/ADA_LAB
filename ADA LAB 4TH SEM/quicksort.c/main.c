#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 5000

void quicksort(int[], int, int);
int partition(int[], int, int);

int main() {
    int i, n, a[MAX], ch = 1;
    clock_t start, end;

    srand(time(0));

    while (ch) {
        printf("\nEnter the number of elements: ");
        scanf("%d", &n);

        if (n <= 0 || n > MAX) {
            printf("Invalid input! Please enter a number between 1 and %d.\n", MAX);
            continue;
        }

        for (i = 0; i < n; i++)
            a[i] = rand() % 200;

        printf("The randomly generated array is:\n");
        for (i = 0; i < n; i++)
            printf("%d ", a[i]);

        start = clock();
        quicksort(a, 0, n - 1);
        end = clock();

        printf("\n\nThe sorted array elements are:\n");
        for (i = 0; i < n; i++)
            printf("%d\n", a[i]);

        printf("\nTime taken = %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

        printf("\nDo you wish to continue? (0 for No, 1 for Yes): ");
        scanf("%d", &ch);
    }

    return 0;
}

void quicksort(int a[], int low, int high) {
    if (low < high) {
        int mid = partition(a, low, high);
        quicksort(a, low, mid - 1);
        quicksort(a, mid + 1, high);
    }
}

int partition(int a[], int low, int high) {
    int key = a[low], i = low + 1, j = high, temp;

    while (i <= j) {
        while (i <= high && a[i] <= key) i++;
        while (a[j] > key) j--;

        if (i < j) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    temp = a[j];
    a[j] = a[low];
    a[low] = temp;

    return j;
}

