
 int getPairsCount(int arr[], int n, int k) {
         sort(arr, arr + n);
         int x = 0, c = 0, y, z;
        for (int i = 0; i < n - 1; i++) {
        x = k - arr[i];
 
        // Lower bound from i+1
        int y = lower_bound(arr + i + 1, arr + n, x) - arr;
 
        // Upper bound from i+1
        int z = upper_bound(arr + i + 1, arr + n, x) - arr;
        c = c + z - y;
    }
    return c;
    }