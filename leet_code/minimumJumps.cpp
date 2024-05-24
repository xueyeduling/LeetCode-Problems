#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_set>
using namespace std;

int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
    queue<tuple<int, int, int>> q;
    unordered_set<int> visited;
    q.emplace(0, 1, 0);
    visited.emplace(0);
    int lower = 0, upper = max(*max_element(forbidden.begin(), forbidden.end()) + a, x) + b;
    unordered_set<int> forbiddenSet(forbidden.begin(), forbidden.end());
    while (!q.empty()) {
        auto [position, direction, step] = q.front();
        q.pop();
        if (position == x) {
            return step;
        }
        int nextPosition = position + a;
        int nextDirection = 1;
        if (lower <= nextPosition && nextPosition <= upper && !visited.count(nextPosition * nextDirection) && !forbiddenSet.count(nextPosition)) {
            visited.emplace(nextPosition * nextDirection);
            q.emplace(nextPosition, nextDirection, step + 1);
        }
        if (direction == 1) {
            nextPosition = position - b;
            nextDirection = -1;
            if (lower <= nextPosition && nextPosition <= upper && !visited.count(nextPosition * nextDirection) && !forbiddenSet.count(nextPosition)) {
                visited.emplace(nextPosition * nextDirection);
                q.emplace(nextPosition, nextDirection, step + 1);
            }
        }
    }
    return -1;
}

int main() {
    /*vector<int> forbidden = {727,470,748,594,1621,395,1734,1835,535,559,1207,336,935,1425,204,1147,1482,225,1513,1289,196,1748,1324,1859,1924,1928,1776,1214,1898,1452,537,320,1131,1305,1588,723,499,1540,1462,1909,1299,275,577,87,288,82,461,959,1829,61,1463,1521,162,149,1261,1284,876,888,1701,1424,818,802,595,1827,1404,5,1209,1380,821,1860,890,67,1346,1901,1352,1552,833,1531,561,1627,1834,1213,59,74,1940,523,1343,1276,1303,208,89,776,1942,1517,722,913,1368,1671,738,1222,1386,1381,120,1906,1166,1405,891,985,1221,1418,1168,385,123,739,1704,1159,1597,1045,1053,647,1936,1700,1960,1051,822,1353,715,393,1809,1345,1486,1882,1831,1753,585,1581,800,1431,1144,880,503,1549,1232,831,1598,1488,714,1828,1524,521,392,1837,1456,325,318,801,1796,790,761,545,572,1728,772,414,173,287,852,823,794,77,1656,927,52,904,1782,765,990,1406,1709,1537,659,1192,215,1461,1203,1600,1541,936,1451,1798,1319,221,1439,375,1681,1391,1951,1262,1179,440,428,1908,1453,910,297,903,1125,812,1442,1732,1548,402,416,1401,295,1616,1632,982,1475,388,1295,1400,508,532,899,1706,1769,185,211};
    int a = 13;
    int b = 14;
    int x = 1149;*/

    vector<int> forbidden = {100};
    int a = 3;
    int b = 1;
    int x = 9;

    int result = minimumJumps(forbidden, a, b, x);

    cout << result;

    return 0;
}