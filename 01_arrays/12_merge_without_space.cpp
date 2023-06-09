   
   
   
   void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            int total_len=n+m;
            int merged_array[total_len];
            int pos = 0;
            
             /* merging two arrays into one single array */
              for (int i = 0; i < n; i++) {
                     merged_array[pos++] = arr1[i];
             }
            for (int i = 0; i < m; i++) {
                merged_array[pos++] = arr2[i];
           }
              /*sorting the merged array */
                sort(merged_array,merged_array+total_len);
                 pos = 0;
    
    /* Putting the first (n) elements in the first array. */
             for (int i = 0; i < n; i++) {
                arr1[i] = merged_array[pos++];
    }
   
         /* Putting last  (m) elements in second array */
                for (int i = 0; i < m; i++) {
                     arr2[i] = merged_array[pos++];
    }
        
 }