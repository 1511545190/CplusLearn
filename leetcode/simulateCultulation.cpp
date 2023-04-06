class Solution {
public:
    string baseNeg2(int n) {
        if(n == 0){
            return "0";
        }
      // https://leetcode.cn/problems/convert-to-base-2/
/*         其实本题想让我们得到的解题结果只包含0或者1，
        但是我们数学运算出来的结果却是0或-1；所以我们对结果进行修正
        比如数学运算 (-3)/(-2)等于1余-1，
        但是题目想让我们得到的结果是(-3)/(-2)等于2余1;我们看到把余数修正为1，
        需要我们把商加1;
        现在我们把描述一般化：
        把算式写成a-(-2)*b=c，其实a是被除数，b是商，c是余数
        等式两边同时减去(-2),得到a-(-2)b-(-2)=c-(-2)
        进行化简：a-(-2)(b+1)=c+2;
        此时 a是被除数，b+1是商，c+2是余数。
        所以当余数是-1时候，如果我们想把余数变为1，也就是变成了c+2；我们正确的商应该是b+1；原来的商加1 */
        string answer;
        while(n){
            int ret = n %(-2);
            n/=-2;
            if(ret == -1)
            {
                answer.insert(0,"1");
                //
                ++n;
            }else
                answer.insert(0,to_string(ret));
        }
        return answer;

    }
};
