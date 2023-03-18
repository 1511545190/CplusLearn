//
// Created by 刘日亮 on 2023/3/18.
//
#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;
class Solution {
public:
    int isMatch(char right, char left){
        int assert = 0;
        switch (right) {
            case '(':
                return left == ')';
            case '{':
                return left == '}';
            case '[':
                return left == ']';
        }

        return 0;
    }
    bool isValid(string s) {
        stack<char> stack1;
        for(auto i: s){
            if(i == ']'|| i =='}' || i== ')'){
                if(stack1.empty()|| !isMatch(stack1.top(),i))
                    return false;//不符合时
                else
                    stack1.pop();
            } else
                stack1.push(i);
        }
        return stack1.empty();

    }

};

int main(){
    string input;

    cin>> input;
    Solution solution;
    cout<<endl<<":"<< solution.isValid(input)<<endl;


    return 0;
}
