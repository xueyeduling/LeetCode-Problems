#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
using namespace std;

bool reachingPoints(int sx, int sy, int tx, int ty) {
    while(true) {
        if(sx == tx && sy == ty) return true;
        if(sx > tx || sy > ty) return false;
        if(tx < 1 || ty < 1) return false;
        if(tx > ty) {
            if((tx - sx) / ty == 0) return false;
            tx = tx - ((tx - sx) / ty * ty);
        }
        else {
            if((ty - sy) / tx == 0) return false;
            ty = ty - ((ty - sy) / tx * tx);
        }
    }
}

int main() {
    bool ans = reachingPoints(3, 7, 3, 4);

    return 0;
}