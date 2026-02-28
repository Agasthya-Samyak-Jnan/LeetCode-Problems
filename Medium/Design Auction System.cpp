#include<bits/stdc++.h>

using namespace std;

// Link to the Problem : https://leetcode.com/problems/design-auction-system/
// Difficulty : Medium 

/* HASH TABLE AND PRIORITY QUEUE (MAX HEAPS) */
class AuctionSystem {
public:

    unordered_map<int,unordered_map<int,int>> BidAmount;
    unordered_map<int,priority_queue<pair<int,int>>> itemBids;

    AuctionSystem() {
    
    }
    
    void addBid(int userId, int itemId, int bidAmount) {
        BidAmount[itemId][userId] = bidAmount;
        itemBids[itemId].push({bidAmount,userId});
    }
    
    void updateBid(int userId, int itemId, int newAmount) {
        BidAmount[itemId][userId] = newAmount;
        itemBids[itemId].push({newAmount,userId});
    }
    
    void removeBid(int userId, int itemId) {
        BidAmount[itemId][userId] = 0;
    }
    
    int getHighestBidder(int itemId) {
        while (!itemBids[itemId].empty()) {
            auto [currTopBid,TopUser] = itemBids[itemId].top();
            if (BidAmount[itemId][TopUser] != currTopBid) {
                itemBids[itemId].pop();
            }
            else { break; }
        }
        return (itemBids[itemId].empty()) ? -1 : itemBids[itemId].top().second;
    }
};

// Same above logic, a bit more compact code
class AuctionSystem {
public:

    unordered_map<int,unordered_map<int,int>> BidAmount;
    unordered_map<int,priority_queue<pair<int,int>>> itemBids;

    AuctionSystem() {
    
    }
    
    void addBid(int userId, int itemId, int bidAmount) {
        BidAmount[itemId][userId] = bidAmount;
        itemBids[itemId].push({bidAmount,userId});
    }
    
    void updateBid(int userId, int itemId, int newAmount) {
        addBid(userId,itemId,newAmount); // Equivalent to two lines implementation in above solution
    }
    
    void removeBid(int userId, int itemId) {
        BidAmount[itemId][userId] = 0;
    }
    
    int getHighestBidder(int itemId) {
        while (!itemBids[itemId].empty() and BidAmount[itemId][itemBids[itemId].top().second] != itemBids[itemId].top().first) {
                itemBids[itemId].pop();
        }
        return (itemBids[itemId].empty()) ? -1 : itemBids[itemId].top().second;
    }
};