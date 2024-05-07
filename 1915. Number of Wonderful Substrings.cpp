class Solution {
public:
    typedef long long ll;
    long long wonderfulSubstrings(string word) {
        unordered_map<ll,ll> map;
        map[0]=1;
        int cumulative_xor = 0;
        ll res=0;
        for(char &ch:word){
            int shift=ch-'a';
            cumulative_xor^=(1<<shift);
            res+=map[cumulative_xor];
            for(char ch1='a'; ch1<='j'; ch1++){
                shift=ch1-'a';
                ll check_xor(cumulative_xor^(1<<shift));
                res+=map[check_xor];
            }
            map[cumulative_xor]++;
        }
        return res;
    }
};