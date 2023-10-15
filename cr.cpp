#include<iostream>
#include<vector>
using namespace std;
class Solution{
public:
    int nCr(int n, int r){
        // code here
        if(n<r) 
        return 0;
        const int moduloulo =1e9+7;
        vector<long long> fac(1001, 1);
        for(int i = 2; i < 1001; i++){
            fac[i] = (i * fac[i - 1]) % moduloulo;
        }
        auto expo = [](long long x, long long y, long long moduloulo) -> int {//lamda function... It calculates x^y % mod using binary exponentiation.integer(result).
            long long ans = 1;
            while(y){
                if(y & 1)
                    ans = (ans * x) % moduloulo;
                x = (x * x) % moduloulo;
                y >>= 1;
            }
            return ans;
        };
        int den = (fac[n - r] * fac[r]) % moduloulo;
        int inv = expo(den, moduloulo - 2, moduloulo);//multiplicative inverse
        int ans = (fac[n] * inv) % moduloulo;
        return ans;
    }
};