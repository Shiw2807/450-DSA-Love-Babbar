

void rearrange(long long *arr, int n)
    {
    int* temp = new int[n]; // Dynamically allocate memory for the temp array
  
    int small = 0, large = n - 1;
    int flag = true;
  
    for (int i = 0; i < n; i++) {
        if (flag)
            temp[i] = arr[large--];
        else
            temp[i] = arr[small++];
  
        flag = !flag;
    }
  
    // Copy temp[] to arr[]
    for (int i = 0; i < n; i++)
        arr[i] = temp[i];
    
    delete[] temp; // Deallocate the memory allocated for temp
}