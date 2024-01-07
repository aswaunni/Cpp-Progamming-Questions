/******************************************************************************
[EASY]

This problem was asked by Slack.

You are given a string formed by concatenating several words corresponding to the integers zero through nine and then anagramming.

For example, the input could be 'niesevehrtfeev', which is an anagram of 'threefiveseven'. Note that there can be multiple instances of each integer.

Given this string, return the original integers in sorted order. In the example above, this would be 357.

*******************************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<char, pair<string, string>> convert {
    {'z', {"0", "zero"}}, 
    {'o', {"1", "one"}},
    {'w', {"2", "two"}}, 
    {'h', {"3", "three"}}, 
    {'u', {"4", "four"}},
    {'f', {"5", "five"}}, 
    {'x', {"6", "six"}}, 
    {'s', {"7", "seven"}}, 
    {'g', {"8", "eight"}}, 
    {'i', {"9", "nine"}}
};

int main(){
    string s {"onetwofour"};
    unordered_map<char, int> cnt;
    string ans;
    
    for (auto& a : s)
        cnt[a]++;
        
    for (auto& a : "zwuxg") {
        if (cnt[a] > 0) {
            ans += convert[a].first;
            for (auto& b : convert[a].second)
                cnt[b]--;
        }
    }
    
    for (auto& a : "ohfsi") {
        if (cnt[a] > 0) {
            ans += convert[a].first;
            for (auto& b : convert[a].second)
                cnt[b]--;
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans;
	    
	return 0;
}
