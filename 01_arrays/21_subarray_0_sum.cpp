 bool subArrayExists(int arr[], int n)
     {
    unordered_set<int> prefixSums;
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        // If the current sum is zero or it has been encountered before,
        // it means there is a subarray with sum zero.
        if (sum == 0 || prefixSums.count(sum) > 0)
            return true;

        prefixSums.insert(sum);
    }

    return false;
}
