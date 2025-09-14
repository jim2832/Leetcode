#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 把字串轉小寫
    string toLower(const string& input) {
        string result = input;
        transform(result.begin(), result.end(), result.begin(),
                  [](unsigned char c){ return tolower(c); });
        return result;
    }

    // 把字串轉成「母音通用」版本
    string devowel(const string& input) {
        string result = toLower(input);
        for (char& c : result) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                c = '*'; // 用 * 表示母音
            }
        }
        return result;
    }

    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exact(wordlist.begin(), wordlist.end()); // 完全匹配用
        unordered_map<string, string> caseInsensitive; // 小寫 -> 原字
        unordered_map<string, string> devowelMap;      // devowel -> 原字

        // 建立 hash 表
        for (const string& word : wordlist) {
            string lower = toLower(word);
            string dv = devowel(word);

            // 保留第一個出現的單字
            if (!caseInsensitive.count(lower)) {
                caseInsensitive[lower] = word;
            }
            if (!devowelMap.count(dv)) {
                devowelMap[dv] = word;
            }
        }

        vector<string> result;
        for (const string& query : queries) {
            if (exact.count(query)) {
                result.push_back(query);
            }
            else {
                string lower = toLower(query);
                if (caseInsensitive.count(lower)) {
                    result.push_back(caseInsensitive[lower]);
                }
                else {
                    string dv = devowel(query);
                    if (devowelMap.count(dv)) {
                        result.push_back(devowelMap[dv]);
                    }
                    else {
                        result.push_back("");
                    }
                }
            }
        }

        return result;
    }
};
