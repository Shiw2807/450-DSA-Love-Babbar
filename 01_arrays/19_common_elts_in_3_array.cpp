 vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
    set<int> ans;
    int i = 0, j = 0, k = 0;
    while (i < n1 and j < n2 and k < n3) {
        if (A[i] == B[j] && A[i] == C[k]) {
            ans.insert(A[i]);
            i++;
            j++;
            k++;
        }
        else if (A[i] < B[j] || A[i] < C[k]) i++;
        else if (B[j] < A[i] || B[j] < C[k]) j++;
        else if (C[k] < B[j] || C[k] < A[i]) k++;
    }
    vector<int> nn;
    for (ele : ans) {
        nn.push_back(ele);
    }
    return nn;
}