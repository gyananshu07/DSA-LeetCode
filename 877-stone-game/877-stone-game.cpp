class Solution {

private:

    int stoneGameHelper(int playerToPlay, vector<int> &piles, int start, int end, vector<vector<int>>& dp) {
        if (start > end) {  // Base case for bounds
            return 0;
        }

        if (start == end) {  // only remaining pile
            return piles[start];
        }

        if (dp[start][end] != -1) return dp[start][end]; // Already computed window

        int stones;
        if (playerToPlay == 0) { // '0' is Alex
            stones = max(piles[start] + stoneGameHelper(1, piles, start + 1, end, dp),
                    piles[end] + stoneGameHelper(1, piles, start, end - 1, dp));
        } else { // Lee plays and deducts our points, since its optimal play we take the most negative value
            stones = min(-piles[start] + stoneGameHelper(0, piles, start + 1, end, dp),
                    -piles[end] + stoneGameHelper(0, piles, start, end - 1, dp));
        }
        dp[start][end] = stones;
        return stones;
    }


public:
    bool stoneGame(vector<int>& piles) {
        
        int n = piles.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));


        stoneGameHelper(0, piles, 0, piles.size() - 1, dp);

        return dp[0][n - 1] > 0;
    }
};