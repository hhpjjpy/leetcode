/*
*思路维护一个不包含重复字符的窗口，(left,right],遍历字符串，当前遍历到的字符上一个位置，不在区间内时，
*说明当前字符满足窗口条件，right++（更新maxlen） 。若当前字符上一个出现的位置在区间内，则当前区间,不能再扩大。
*更新区间初始位置即为当前节点的上一个位置。重复以上过程，直到最后。
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> pos(256,-1);
        int left = -1;
        int maxlen = 0;
        for(int i=0;i<s.size();i++){
            if(pos[s[i]] > left)
                left = pos[s[i]];
            pos[s[i]] = i;
            maxlen = maxlen>(i-left)?maxlen:(i-left);
        }
        
        return maxlen;
    }
};
