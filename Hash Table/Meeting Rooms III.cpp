//Array , Hash Table , Sorting , Heap (Priority Queue) , Simulation

/*The problem:
You are given an integer n. There are n rooms numbered from 0 to n - 1.

You are given a 2D integer array meetings where meetings[i] = [starti, endi] means that a meeting will be held during the half-closed time interval [starti, endi). All the values of starti are unique.

Meetings are allocated to rooms in the following manner:

Each meeting will take place in the unused room with the lowest number.
If there are no available rooms, the meeting will be delayed until a room becomes free. The delayed meeting should have the same duration as the original meeting.
When a room becomes unused, meetings that have an earlier original start time should be given the room.
Return the number of the room that held the most meetings. If there are multiple rooms, return the room with the lowest number.

A half-closed interval [a, b) is the interval between a and b including a and not including b.*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        
        vector<int> countMeetings(n, 0); //store count of meetings held in each room
        priority_queue< int , vector<int> , greater<int> > availableRooms; //store indices of available rooms
        priority_queue< pair<long long,int> , vector<pair<long long,int>> , greater<pair<long long,int>> > busyRooms; //store pairs of end times and room indices for currently busy rooms

        for (int i = 0; i < n; i++){
            availableRooms.push(i);
        }
        // Sort meetings based on start times
        sort(meetings.begin(), meetings.end());

        for(auto meeting : meetings){

            int start = meeting[0], end = meeting[1];
            // Update room availability based on current meeting start time
            while( busyRooms.size() > 0 && busyRooms.top().first <= start){ // removes these rooms from busy queue and adds them back to the available queue
                availableRooms.push( busyRooms.top().second );
                busyRooms.pop();
            }

            if(availableRooms.size() > 0){  //If there are available rooms, it assigns current meeting to the room with the lowest index among available rooms
                int top = availableRooms.top();
                countMeetings[top]++;
                availableRooms.pop();
                busyRooms.push({end,top});
            }
            else{   // if all rooms are busy, finds the room whose meeting ending soonest (busy.top()), assigns the meeting to that room.
                auto top = busyRooms.top();
                int endSoon = top.first , soonIndx = top.second;
                countMeetings[soonIndx]++;

                busyRooms.pop();
                busyRooms.push({top.first+end-start , soonIndx});
            }
        }

        return max_element(countMeetings.begin() , countMeetings.end()) - countMeetings.begin();

        // unordered_map<int, int> rooms; // {room_number: meeting_count}
        // priority_queue<int, vector<int>, greater<int>> availableRooms; // Available rooms

        // for (const auto& meeting : meetings) {
        //     int start = meeting[0], end = meeting[1];

        //     // Find an available room or delay the meeting
        //     if (!availableRooms.empty() && availableRooms.top() <= start) {
        //         // Use an available room
        //         int room = availableRooms.top();
        //         availableRooms.pop(); // Remove from available rooms
        //         rooms[room]++; // Increment meeting count
        //         availableRooms.push(end); // Update room's end time
        //     } else {
        //         // Delay the meeting
        //         int room = rooms.size(); // Use a new room
        //         rooms[room] = 1; // Initialize meeting count
        //         availableRooms.push(end); // Update room's end time
        //     }
        // }

        // // Find the room with the maximum meeting count
        // int maxMeetings = 0, maxRoom = -1;
        // for (const auto& room : rooms) {
        //     if (room.second > maxMeetings) {
        //         maxMeetings = room.second;
        //         maxRoom = room.first;
        //     }
        // }

        // return maxRoom;
    }
};

int main() {
    Solution solution;
    int n = 2;
    vector<vector<int>> meetings = {{0, 10}, {1, 5}, {2, 7}, {3, 4}};
    cout << solution.mostBooked(n, meetings) << endl; // Output: 0

    n = 3;
    meetings = {{1, 20}, {2, 10}, {3, 5}, {4, 9}, {6, 8}};
    cout << solution.mostBooked(n, meetings) << endl; // Output: 1

    return 0;
}
