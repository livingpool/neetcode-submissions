/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        auto comp = [](const Interval& i1, const Interval& i2) {
            return i1.start < i2.start;
        };    
        sort(intervals.begin(), intervals.end(), comp);

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i - 1].end > intervals[i].start) return false;
        }
        return true;
    }
};
