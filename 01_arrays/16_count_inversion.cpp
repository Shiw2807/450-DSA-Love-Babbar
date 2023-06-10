  //merging of two sorted subarrays and counts the inversions during the merging process.
    long long mergeAndCount(long long arr[], long long temp[], long long left, long long mid, long long right) {
    long long invCount = 0;
    long long i = left; // Index for left subarray
    long long j = mid; // Index for right subarray
    long long k = left; // Index for merged array

    while (i <= mid - 1 && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
            invCount += mid - i;
        }
    }

    while (i <= mid - 1) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }

    return invCount;
}
    
    /*/divide-and-conquer approach of Merge Sort to recursively divide the array into two halves until 
    the base case of a single element is reached/*/
    long long mergeSortAndCount(long long arr[], long long temp[], long long left, long long right) {
    long long invCount = 0;

    if (right > left) {
        long long mid = (left + right) / 2;
        invCount += mergeSortAndCount(arr, temp, left, mid);
        invCount += mergeSortAndCount(arr, temp, mid + 1, right);
        invCount += mergeAndCount(arr, temp, left, mid + 1, right);
    }

    return invCount;
}
    
    
    
    // Function to count inversions in the array.
    long long int inversionCount(long long arr[], long long N)
    {
        long long temp[N];
        return mergeSortAndCount(arr, temp, 0, N - 1);
    }