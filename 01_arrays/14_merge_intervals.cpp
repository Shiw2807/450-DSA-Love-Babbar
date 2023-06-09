

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> mergedIntervals;
    if (intervals.size() == 0) {
        return mergedIntervals;
    }

    sort(intervals.begin(), intervals.end());
    vector<int> tempInterval = intervals[0];

    for (auto it : intervals) {

        /*/ If the condition is true, it means the current interval overlaps with the temporary interval. 
        In this case, the code updates the end value of the temporary interval to the maximum of the current interval's end 
        value and the temporary interval's end value using tempInterval[1] = max(it[1], tempInterval[1]). 
        This ensures that the temporary interval expands to include the overlapping intervals./*/

        if (it[0] <= tempInterval[1]) {
            tempInterval[1] = max(it[1], tempInterval[1]);
        } else {

            /*/ This branch is executed when the current interval does not overlap with the temporary interval. 
            In this case, the code adds the temporary interval to the mergedIntervals vector using mergedIntervals.push_back(tempInterval). 
            Then, it assigns the current interval it to the temporary interval tempInterval in order to 
            start a new temporary interval for the next potential merge.*/
            
            mergedIntervals.push_back(tempInterval);
            tempInterval = it;
        }
    }
    mergedIntervals.push_back(tempInterval);
    return mergedIntervals;
}
