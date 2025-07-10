#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        //Each element in gaps will be {startTime, endTime, and duration}
        vector<vector<int>> gaps;
        const int gStart = 0;
        const int gEnd = 1;
        const int gSize = 2;

        //Find all gaps and store biggest size gap index
        int biggestGap = 0;
        for(int i = 0; i < startTime.size(); i++) { 
            if(i == 0) {
                if(startTime[i] != 0) {
                    gaps.push_back({0, startTime[i], startTime[i]});
                }
            }
            else {
                if(startTime[i] - endTime[i-1] != 0) {
                    gaps.push_back({endTime[i-1], startTime[i], startTime[i] - endTime[i-1]});
                }
            }
            if (gaps.size() > 0 && gaps[biggestGap][gSize] < gaps[gaps.size()-1][gSize]) {
                biggestGap = gaps.size() - 1;
            }
        }

        //Include possible gap from final meeting to eventTime
        if(endTime[endTime.size() - 1] != eventTime) {
            gaps.push_back({endTime[endTime.size() - 1], eventTime, eventTime - endTime[endTime.size() - 1]});
            if (gaps[biggestGap][gSize] < gaps[gaps.size()-1][gSize]) {
                biggestGap = gaps.size()-1;
            }
        }
        //no gaps = no freetime
        if(gaps.size() == 0) return 0; 

        //All meetings with durations < biggestGap size can go in biggestGap except the 2 meetings adjacent to the gaps
        //Special case these 2 meetings
        int leftSpecialMeetingEnd = gaps[biggestGap][gStart];
        int rightSpecialMeetingStart = gaps[biggestGap][gEnd];
        int ans = 0;
        //Calculate the expected freeTime removing each meeting would generate
        for(int i = 0; i < startTime.size(); i++) {
            int leftGap = 0;
            if(i == 0) {
                leftGap = startTime[i];
            }
            else {
                leftGap = startTime[i] - endTime[i-1];    
            }

            int rightGap = 0;
            if(i == startTime.size() - 1) {
                rightGap = eventTime - endTime[i];
            }
            else {
                rightGap = startTime[i+1] - endTime[i];
            }
            int freeTime = leftGap + rightGap;
            //Now check if we can add meeting duration to it
            int meetingDuration = endTime[i] - startTime[i];
            if(startTime[i] == rightSpecialMeetingStart || endTime[i] == leftSpecialMeetingEnd) {
                for(int j = 0; j < gaps.size(); j++) {
                    if(startTime[i] != gaps[j][gEnd] && endTime[i] != gaps[j][gStart] && meetingDuration <= gaps[j][gSize]) {
                        freeTime += meetingDuration;
                        break;
                    }
                }
            }
            else if(meetingDuration <= gaps[biggestGap][gSize]) {
                freeTime += meetingDuration;
            }

            ans = max(ans, freeTime);
        }
        return ans;
    }
};
