#include <iostream>
#include <cmath>


//#####################################Merge Begin###################################################
/*
 * Merge:  Merge left and right sub-arrays into sorted array
 */
void Merge(int *array, int start, int endArray, int midPoint) {

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
} // End Merge function
//#####################################Merge End#####################################################


//#####################################Mergesort Begin################################################
/*
 * Merge Sort:  Break unsorted array into left and right sub-arrays
 */
void MergeSort(int *array, int leftSubArray, int rightSubArray) {

    //  If there exists only one element array is already sorted
    if (leftSubArray < rightSubArray) {

        // Find the midPoint of array
        int midPoint = (leftSubArray + rightSubArray) / 2;

        // Perform Merge sort on the left side of sub-array recursively
        MergeSort(array, leftSubArray, midPoint);

        // Perform Merge sort on the right side of sub-array recursively
        MergeSort(array, midPoint + 1, rightSubArray);

        //  Merge the left and right sub-arrays
        Merge(array, leftSubArray, rightSubArray, midPoint);
    }

}  // End Merge sort function
//#####################################Mergesort End#################################################


//#####################################Begin Main Method#############################################
int main() {

    clock_t tStart = clock();

    int start, end;

    start = 1;
    end = pow(2,16);

    int array[end];

    /*for (int i = start; i < end; i++) {
        array[i] = start + rand() % (end - start + 1);
    }

    MergeSort(array, start, end);

    for (int i = 1; i < end; i++) {
        std::cout << array[i] << ' ';
    }*/

    for(int i = 0; i < end; i++) {
        array[i] = i+1;
    }

    MergeSort(array, start, end - 1);

    for (int i : array) {
        std::cout << i << ' ';
    }

    printf("\nTime taken: %.9fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

    return 0;
}
//#####################################End Main Method###############################################