/*   DwyaneTalk@gmail.com
 *   by lutao
 *   leetCode278 : First Bad Version
 *            	 : https://leetcode.com/problems/first-bad-version/
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

int firstBadVersion(int n) {
    if(n <= 0)   return 0;
    int lo = 0, hi = n, mid;
    while(lo + 1 < hi) {
        mid = lo + (hi - lo) / 2;
        if(isBadVersion(mid)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    return hi;
}

