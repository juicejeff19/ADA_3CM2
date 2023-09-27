#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int quantity, int pInt[quantity]);

void insertionSort(int quantity, int pInt[quantity]);

void selectionSort(int quantity, int pInt[quantity]);

void mergeSort(int quantity, int pInt[quantity]);

int main() {
    printf("Welcome\n");
    printf("How many random numbers do you want to generate?\n");
    int quantity;
    scanf("%d", &quantity);
    int numbers[quantity];
    for (int i = 0; i < quantity; ++i) {
        numbers[i] = rand() % 1000;
    }
    int option;
    while (1) { // Infinite loop
        printf("What ordination algorithm do you wish to measure the time of?\n");
        printf("1 - Bubble Sort\n");
        printf("2 - Insertion Sort\n");
        printf("3 - Selection Sort\n");
        printf("4 - Merge Sort\n");
        printf("5 - Exit\n");
        scanf("%d", &option); // Read the user's choice inside the loop

        if (option == 5) {
            printf("Exit\n");
            break; // Exit the loop if the user selects option 6
        }

        switch(option) {
            case 1:
                printf("Bubble Sort\n");
                bubbleSort(quantity, numbers);
                break;
            case 2:
                printf("Insertion Sort\n");
                insertionSort(quantity, numbers);
                break;
            case 3:
                printf("Selection Sort\n");
                selectionSort(quantity, numbers);
                break;
            case 4:
                printf("Merge Sort\n");
                int mergearray[quantity];
                for(int i=0; i<quantity; i++){
                    mergearray[i] = numbers[i];
                }
                clock_t begin = clock();
                mergeSort(quantity, mergearray);
                clock_t end = clock();
                double time = (double)(end - begin) / CLOCKS_PER_SEC;
                printf("The time it took to sort the array was: %f\n", time);
                printf("The sorted array is: \n");
                int i;
                for(i=0; i<quantity; i++){
                    printf("%d\n", mergearray[i]);
                }
                break;
        }
    }

    return 0;
}
void merge(int arr[], int left[], int leftSize, int right[], int rightSize) {
    int i = 0, j = 0, k = 0;

    while (i < leftSize && j < rightSize) {
        if (left[i] < right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < leftSize) {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < rightSize) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(int quantity, int pInt[quantity]) {
    if (quantity <= 1) {
        return; // Base case: if the array has 1 or fewer elements, it's already sorted
    }

    int mid = quantity / 2;
    int left[mid];
    int right[quantity - mid];

    // Split the array into two halves
    for (int i = 0; i < mid; i++) {
        left[i] = pInt[i];
    }
    for (int i = mid; i < quantity; i++) {
        right[i - mid] = pInt[i];
    }

    // Recursively sort the left and right halves
    mergeSort(mid, left);
    mergeSort(quantity-mid, right);

    // Merge the sorted halves back together
    merge(pInt, left, mid, right, quantity - mid);

}

void selectionSort(int quantity, int pInt[quantity]) {
    //ordenate the given array using selection sort and measure the time it takes, don't modify the original array
    int selectionarray[quantity];
    for(int i=0; i<quantity; i++){
        selectionarray[i] = pInt[i];
    }
    int i;
    int j;
    clock_t begin = clock();
    for(i=0; i<quantity; i++){
        int min = i;
        for(j=i+1; j<quantity; j++){
            if(selectionarray[j]<selectionarray[min]){
                min = j;
            }
        }
        if(min != i){
            int temp = selectionarray[i];
            selectionarray[i] = selectionarray[min];
            selectionarray[min] = temp;
        }
    }
    clock_t end = clock();
    double time = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("The time it took to sort the array was: %f\n", time);
    printf("The sorted array is: \n");
    for(i=0; i<quantity; i++){
        printf("%d\n", selectionarray[i]);
    }
}

void insertionSort(int quantity, int pInt[quantity]) {
    //ordenate the given array using insertion sort and measure the time it takes, don't modify the original array
    int insertionarray[quantity];
    for(int i=0; i<quantity; i++){
        insertionarray[i] = pInt[i];
    }
    int i;
    int j;
    clock_t begin = clock();
    for(i=0; i<quantity; i++){
        int temp = insertionarray[i];
        j = i-1;
        while(temp<insertionarray[j] && j>=0){
            insertionarray[j+1] = insertionarray[j];
            j--;
        }
        insertionarray[j+1] = temp;
    }
    clock_t end = clock();
    double time = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("The time it took to sort the array was: %f\n", time);
    printf("The sorted array is: \n");
    for(i=0; i<quantity; i++){
        printf("%d\n", insertionarray[i]);
    }
}

void bubbleSort(int quantity, int numbubble[quantity]){
    //ordenate the given array using bubble sort and measure the time it takes, don't modify the original array
    int bubblearray[quantity];
    for(int i=0; i<quantity; i++){
        bubblearray[i] = numbubble[i];
    }
    int i;
    int j;
    clock_t begin = clock();
    for(i=0; i<quantity; i++){
        for(j=i+1; j<quantity; j++){
            if(bubblearray[i]>bubblearray[j]){
                int temp = bubblearray[i];
                bubblearray[i] = bubblearray[j];
                bubblearray[j] = temp;
            }
        }
    }
    clock_t end = clock();
    double time = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("The time it took to sort the array was: %f\n", time);
    printf("The sorted array is: \n");
    for(i=0; i<quantity; i++){
        printf("%d\n",bubblearray[i]);
    }

}
