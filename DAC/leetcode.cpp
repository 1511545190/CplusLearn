#include <iostream>
#include <map>
using namespace std;
class Solution {
public:
    int value(){
        int value;
        return value;
    }
    int romanToInt(string s) {
        map<char,int> mapp;

        for(int i = 0;s[i];i++){
            mapp.insert(make_pair(s[i],value(s[i])));

        }

    }
};
int main()
{
    return 0;
}