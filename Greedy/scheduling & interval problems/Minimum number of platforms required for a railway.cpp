class Solution {
public:
//  To find number of platforms
    int findPlatform(vector<int>& Arrival, vector<int>& Departure) {
        int n = Arrival.size();
        
        // Sort both arrival and departure arrays
        sort(Arrival.begin(), Arrival.end());
        sort(Departure.begin(), Departure.end());

        int ans = 1;
        int count = 1;
        int i = 1, j = 0;
        
        // Iterate through the arrays
        while (i < n && j < n) {
            if (Arrival[i] <= Departure[j]) {
                // Increment count
                count++;
                i++;
            } else {
                // Decrement Count
                count--;
                j++;
            }
            // Find maximum
            ans = max(ans, count);
        }
        return ans;
    }
};