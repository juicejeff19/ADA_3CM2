#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void quciksort1(int n, int A[n], int p, int r);

int partition1(int n, int A[n], int p, int r);

void quciksort2(int n, int A[n], int p, int r);

int partition2(int n, int A[n], int p, int r);

int cmpfunc (const void * a, const void * b);

int main() {
    printf("Bienvenido, cuantos numeros deseas generar\n");
    int n;
    scanf("%d", &n);
    //generate n random numbers and store them in an array
    int i;
    int arr[n];
    int arr2[n];
    srand(time(NULL));
    for (i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
    //copy arr to arr2
    for (i = 0; i < n; i++) {
        arr2[i] = arr[i];
    }

    qsort(arr, n, sizeof(int), (void *) cmpfunc);
    qsort(arr2, n, sizeof(int), (void *) cmpfunc);
    //mergeSort(n, arr);
    //mergeSort(n, arr2);
    int option;
    clock_t start, end;
    while (1){
        printf("\nQue tipo de quicksort deseas usar?\n");
        printf("1. Quicksort con pivote al ultimo\n");
        printf("2. Quicksort con pivote aleatorio\n");
        printf("3. Salir\n");
        scanf("%d", &option);
        if (option == 3) {
            break;
        }
        switch (option) {
            case 1:
                /*printf("El arreglo original es: \n");
                for (i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }*/
                start = clock();
                quciksort1(n, arr, 0, n - 1);
                end = clock();
                //print the ordered array array2
                if(n<20) {
                    printf("El arreglo ordenado es: \n");
                    for (i = 0; i < n; i++) {
                        printf("%d ", arr[i]);
                    }
                }
                printf("El tiempo de ejecucion fue: %f\n", ((double) (end - start)) / CLOCKS_PER_SEC);
                break;
            case 2:
                /*printf("El arreglo original es: \n");
                for (i = 0; i < n; i++) {
                    printf("%d ", arr2[i]);
                }*/
                start = clock();
                quciksort2(n, arr2, 0, n - 1);
                end = clock();
                //print the ordered array array2
                if(n<20){
                    printf("\nEl arreglo ordenado es: \n");
                    for (i = 0; i < n; i++) {
                        printf("%d ", arr2[i]);
                    }
                }
                printf("El tiempo de ejecucion fue: %f\n", ((double) (end - start)) / CLOCKS_PER_SEC);
                break;
        }
    }
}

int cmpfunc (const void * a, const void * b) {
    return ( *(int*)a - *(int*)b );
}

void quciksort2(int n, int A[n], int p, int r) {
    //write a function that implements quicksort with random pivot
    if (p < r) {
        int q = partition2(n, A, p, r);
        quciksort2(n, A, p, q - 1);
        quciksort2(n, A, q + 1, r);
    }
}

int partition2(int n, int A[n], int p, int r) {
    int i = rand() % (r - p + 1) + p;
    int temp = A[r];
    A[r] = A[i];
    A[i] = temp;
    return partition1(n, A, p, r);
}

void quciksort1(int n, int A[n], int p, int r) {
    if (p < r) {
        int q = partition1(n, A, p, r);
        quciksort1(n, A, p, q - 1);
        quciksort1(n, A, q + 1, r);
    }
}

int partition1(int n, int A[n], int p, int r) {
    int x = A[r];
    int i = p - 1;
    int j;
    for (j = p; j <= r - 1; j++) {
        if (A[j] <= x) {
            i = i + 1;
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }
    int temp = A[i + 1];
    A[i + 1] = A[r];
    A[r] = temp;
    return i + 1;
}