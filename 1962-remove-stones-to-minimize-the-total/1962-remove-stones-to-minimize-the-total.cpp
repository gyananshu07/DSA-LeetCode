class Solution {
public:
    int minStoneSum(vector<int>& piles, int k)
    {
    int total = accumulate(begin(piles), end(piles), 0);
    priority_queue<int> p(begin(piles), end(piles));
        
    while (--k >= 0) 
    {
        auto st = p.top();
        p.pop();
        total -= st / 2;
        p.push((st + 1) / 2);
    }
    return total;
}
};