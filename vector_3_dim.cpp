//
// Created by 刘日亮 on 2023/3/19.
//
#include "leetcode.h"
int main(){
   vector<vector<int>> vector1;
   for(int i = 0;i< 3;++i){
      vector1.push_back(vector<int>());
       for(int j = 0;j<5;++j){
           vector1.back().push_back(j+1);
       }
   }
   vector<vector<vector<int>>> vector2;//三维数组
   for(int i =  0;i< 5;++i){
       vector2.push_back(vector<vector<int>>());
           for(int j = 0;j<5;++j){
               vector2.back().push_back(vector<int>());
               for(int k = 0;k<10;++k)
                   vector2.back().back().push_back(k+1);
           }
   }


   cout<<vector2[1][1][1]<<endl<<"ddd";
    return 0;
}
