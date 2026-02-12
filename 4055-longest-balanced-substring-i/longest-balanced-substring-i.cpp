class Solution {
public:
    int longestBalanced(string s) {
        int n = s.length();

        int freq[26];
        int cnt = 1;

        for(int l=0; l<n; l++){// l as left pointer
    memset(freq, 0, sizeof(freq));// reset freq
    int uniq=0, maxF=0, cntMax=0;// set local variables
    for(int r=l; r<n; r++){// r as right pointer
        int f=++freq[s[r]-'a'];// add 1 to freq[s[r]-'a'] stored in f
        uniq+=(f==1);// if f==1 add 1 to uniq
        // if f>maxF, reset cntMax=1, set maxF=f
        if (f>maxF){ maxF=f; cntMax=1; }
        else if (f==maxF) cntMax++;// if f==maxF add 1 to cntMax
        if (uniq==cntMax) //when uniq==cntMax
            cnt=max(cnt, r-l+1);// update cnt  the max with r-l+1
    }
}
return cnt;// answer
    }
};