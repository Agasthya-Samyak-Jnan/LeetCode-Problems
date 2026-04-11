#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/get-watched-videos-by-your-friends/
// Difficulty : Medium

/* GRAPH (RELATION BETWEEN FRIENDS) + BREADTH-FIRST SEARCH (LEVEL ORDER TRAVERSAL) + HASH TABLE (FREQUENCY TABLE) + SORTING (ORDERING BY FREQUENCY) */
class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {

        // Find k-th level friends of 'id', Collect them in the queue.

        queue<int> q;
        unordered_map<int,int> visited;

        q.push(id);
        visited[id] = 1;

        while (!q.empty() and level) {
            int l = q.size();
            for (int i=0;i<l;i++) {
                int  curr = q.front(); q.pop();
                for (auto next : friends[curr]) {
                    if (!visited[next]) {
                        q.push(next);
                        visited[next] = 1;
                    }
                }
            }
            level--;
        }

        // Calculate frequencies of all videos watched by k-th level friends of 'id', go through them, they are all in the queue.

        unordered_map<string,int> freq;

        while (!q.empty()) {
            int i = q.front(); q.pop();
            for (auto vid : watchedVideos[i]) { freq[vid]++; }
        }

        // sort all watched videos by k-th level friends of 'id' by frequency - least watched first, most watched last.

        vector<pair<int,string>> temp; // {frequency, video title}
        for (auto p : freq) { temp.push_back({p.second,p.first}); } // Reverse the pair while adding to this vector, so that sorting happens by frequency first, alphabet order of title second.
        sort(temp.begin(),temp.end());

        // Extract only video titles from sorted list in the same order.
        vector<string> watchedVideosSorted;
        for (auto p : temp) { watchedVideosSorted.push_back(p.second); } // {frequency, video title}, so get video title only here.

        return watchedVideosSorted;
    }
};