/*   DwyaneTalk@gmail.com
 *   by lutao
 *   hihocoder : 4Sum
 *             : https://leetcode.com/problems/4sum/
*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > ans;
        vector<int> four;
        int size = num.size();
        int i, j, lo, hi, twoSum, sum;
        sort(num.begin(), num.end());
        for(i = 0; i < size - 3; ++i) {
            if(i && num[i] == num[i - 1])   continue;
            for(j = i + 1; j < size - 2; ++j) {
                if(j != i + 1 && num[j] == num[j - 1]) continue;
                lo = j + 1;
                hi = size - 1;
                sum = target - num[i] - num[j];
                while(lo < hi) {
                    twoSum = num[lo] + num[hi];
                    if(twoSum < sum) {
                        lo++;
                        while(lo < hi && num[lo - 1] == num[lo])    lo++;
                    } else if(twoSum > sum) {
                        hi--;
                        while(lo < hi && num[hi + 1] == num[hi])    hi--;
                    } else{
                        four.push_back(num[i]);
                        four.push_back(num[j]);
                        four.push_back(num[lo]);
                        four.push_back(num[hi]);
                        ans.push_back(four);
                        four.clear();
                        lo++;
                        hi--;
                        while(lo < hi && num[lo - 1] == num[lo])    lo++;
                        while(lo < hi && num[hi + 1] == num[hi])    hi--;
                    }
                }
            }
        }
        return ans;
    }
};

int main() {
    int num[] = {1, 0, -1, 0, -2, 2};
    int target = 0, i;
    vector<int> vec;
    Solution solution;
    for(i = 0; i < sizeof(num)/ sizeof(int); i++)
        vec.push_back(num[i]);
    vector<vector<int> > ans = solution.fourSum(vec, target);
    vector<int> four;
    int size = ans.size();
    for(i = 0; i < size; i++) {
        four = ans[i];
        cout << four[0] << " " << four[1] << " " << four[2] << " " << four[3] << endl;
    }
    return 0;
}
