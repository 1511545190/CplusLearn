#include "leetcode.h"
vector<int> getRow(int rowIndex) {
    int n  = rowIndex+ 1;
    vector<int> YangHuiAngle(n);
    for(int i = 0;i<= rowIndex; ++i){
        YangHuiAngle[0] = YangHuiAngle[rowIndex] = 1;
        for(int j = 1;j<= rowIndex -1;++j){
            YangHuiAngle[j] = YangHuiAngle[j-1] + YangHuiAngle[j];
        }
    }
    return YangHuiAngle;
}
int main(){
    getRow(3);

    return 0;
}