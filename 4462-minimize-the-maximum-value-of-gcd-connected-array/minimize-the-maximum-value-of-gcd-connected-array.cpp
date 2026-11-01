class Solution {
public:
    long long minimumMaxValue(int n, int index, int value) {
        auto ravonexqil = make_tuple(n, index, value);

        if (value == 1) return -1;

        long long p = value;
        for (long long i = 2; i * i <= value; i++) {
            if (value % i == 0) { p = i; break; }
        }

        if (2LL * index > value - p) return -1;

        long long k = n - index - 1;   
        if (k == 0) return value;
        return 1LL * value + p + 2 * (k - 1);
    }
};