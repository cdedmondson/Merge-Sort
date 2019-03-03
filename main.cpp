#include <iostream>


//#####################################Merge Begin###################################################
/*
 * Merge:  Merge left and right sub-arrays into sorted array
 */
void merge(int *array, int start, int endArray, int midPoint) {

    int low, mid, index;
    low = start;
    mid = midPoint + 1;
    index = 0;
    int tempArray[endArray - start + 1];

    while (low <= midPoint && mid <= endArray) {
        if (array[low] < array[mid]) {
            tempArray[index++] = array[low++];
        } else {
            tempArray[index++] = array[mid++];
        }
    }

    for (int i = low; i <= midPoint; i++) {
        tempArray[index++] = array[low++];
    }

    for (int j = mid; j <= endArray; j++) {
        tempArray[index++] = array[mid++];
    }

    for (low = start; low <= endArray; low++) {
        array[low] = tempArray[low - start];
    }
} // End merge function
//#####################################Merge End#####################################################


//#####################################Mergesort Begin################################################
/*
 * Merge Sort:  Break unsorted array into left and right sub-arrays
 */
void mergeSort(int *array, int leftSubArray, int rightSubArray) {

    //  If there exists only one element array is already sorted
    if (leftSubArray < rightSubArray) {

        // Find the midPoint of array
        int midPoint = (leftSubArray + rightSubArray) / 2;

        // Perform merge sort on the left side of sub-array recursively
        mergeSort(array, leftSubArray, midPoint);

        // Perform merge sort on the right side of sub-array recursively
        mergeSort(array, midPoint + 1, rightSubArray);

        //  Merge the left and right sub-arrays
        merge(array, leftSubArray, rightSubArray, midPoint);
    }

}  // End merge sort function
//#####################################Mergesort End#################################################


//#####################################Begin Main Method#############################################
int main() {

    int array[] = {10, 5, 1, 20, 2, 15, 3, 4, 60};

    mergeSort(array, 0, 8);

    for (int i : array) {
        std::cout << i << ' ';
    }

    return 0;
}
//#####################################End Main Method###############################################