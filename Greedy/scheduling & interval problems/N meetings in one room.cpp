class Solution {
   public:
    // Comparator function to sort meetings based on end times
    static bool comparator(pair<int, int>& a, pair<int, int>& b) {
        // Sort by end time in ascending order
        if (a.second < b.second) {
            return true;
        }
        return false;
    }

    // Function to find the maximum number of meetings that can be held
    int maxMeetings(vector<int>& start, vector<int>& end) {
        int n = start.size();

        vector<pair<int, int>> meetings;

        for (int i = 0; i < n; i++) {
            meetings.push_back({start[i], end[i]});
        }

        // Sort the meetings based on the custom comparator
        sort(meetings.begin(), meetings.end(), comparator);

        int endTime = meetings[0].second;

        int count = 1;

        for (int i = 1; i < n; i++) {
            if (endTime < meetings[i].first) {
                endTime = meetings[i].second;
                count++;
            }
        }

        return count;
    }
};