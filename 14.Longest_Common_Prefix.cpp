#include <string>
#include <vector>
#include <algorithm>
class Solution_Of_Transverse_Scan {
public:
    std::string longestCommonPrefix(std::vector<std::string> strs) {
        if(!strs.size())
            return "";
        std::string prefix = strs[0];
        int length = strs.size();
        for(int i = 1; i < length; ++i) {
            prefix = longestCommonPrefix(prefix, strs[i]);
            if(!prefix.size())
                break;
        }
        return prefix;
    }
    std::string longestCommonPrefix(const std::string& str1, const std::string& str2) {
        int count = std::min(str1.size(), str2.size());
        int index = 0;
        while(index < count && str1[index] == str2[index]) {
            ++index;
        }
        return str1.substr(0, index);
    }
};

class Solution_Of_Lengthways_Scan {
public:
    std::string longestCommonPrefix(std::vector<std::string> strs) {
        if(!strs.size())
            return "";
        int length = strs[0].size();    //所有字符串的长度不会超过第一个字符串
        int count = strs.size();
        for(int i = 0; i < length; ++i) {
            char c = strs[0][i];
            for(int j = 1; j < count; ++j) {
                if(i == strs[j].size() || strs[j][i] != c)  //1. 最小字符串的长度决定了最长公共前缀的长度；2. 如果出现这一列的“异类”字符则返回之前已遍历的字符串
                    return strs[0].substr(0, i);
            }
        }
        return strs[0]; //如果所有字符串通过遍历则返回第一个字符串
    }
};