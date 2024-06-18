#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <sstream>
#include <string>
#include <iomanip>
#include <cctype>
using namespace std;

bool is_number(const std::string &str) {
    if(str.size() == 0) return false;
    for (char const &c : str) {
        if (!std::isdigit(c)) return false; // 如果字符不是数字则返回false
    }
    return true; // 所有字符都是数字则返回true
}

std::string toStringWithTwoDecimalPlaces(double value) {
    std::ostringstream streamObj;
    // Set Fixed -Point Notation
    streamObj << std::fixed;
    // Set precision to 2 digits
    streamObj << std::setprecision(2);
    //Add double to stream
    streamObj << value;
    // Get string from output string stream
    return streamObj.str();
}

string discountPrices(string sentence, int discount) {
    string ans = "";
    istringstream iss(sentence);
    string word;
    while (iss >> word) {
        if(word[0] == '$' && is_number(word.substr(1, word.size() - 1))) {
            cout << word.substr(1, word.size() - 1) << endl;
            long long n = stoll(word.substr(1, word.size() - 1));
            ans += ("$" + toStringWithTwoDecimalPlaces(n * (1 - (double)discount / 100)));
        }
        else ans += word;
        ans += " ";
    }

    return ans.substr(0, ans.size() - 1);
}

int main() {
    string sentence = "$76111 ab $6 $";
    int discount = 48;
    string ans = discountPrices(sentence, discount);

    cout << ans << endl;
    
    return 0;
}
