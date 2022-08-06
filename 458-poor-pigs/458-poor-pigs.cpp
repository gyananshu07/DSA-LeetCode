class Solution {
public:
    int poorPigs(int N, int Die, int Test) {
        return ceil(log(N) / log(Test / Die + 1));
    }
};