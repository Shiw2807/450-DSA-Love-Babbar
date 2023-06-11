class Solution {
public:
    // this function takes k to multiply with array (array here is whole digit with first digit at 0th of array)
    int mul(vector<int>& arr, int k, int size) {
        int carry = 0;
        for (int i = 0;i < size;i++) {
            int curr_mul = k * arr[i] + carry;
            arr[i] = curr_mul % 10;
            carry = curr_mul / 10;
        }
        // if carry is not zero then we have to push_back at the end.
        while (carry) {
            arr.push_back(carry % 10);
            carry /= 10;
            size++;
        }
        return size;
    }
    vector<int> factorial(int n) {
        // code here
        vector<int> arr = { 1 };
        int size = 1;
        for (int i = 2;i <= n;i++) {
            // updating size and array everytime
            size = mul(arr, i, size);
        }

        // we have first digit at 0th place hence we have to reverse
        // eg. for 5 it will be {0, 2, 1} => {1, 2, 0}
        reverse(arr.begin(), arr.end());
        return arr;
    }
};