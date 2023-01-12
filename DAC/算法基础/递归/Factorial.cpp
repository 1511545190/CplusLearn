#include <iostream>
#include <vector>
using namespace std;
int facotrial(int n,int result)
{
    if(n==1)
        return result;
    else
        return facotrial(n-1,result*n);
}
int main()
{

    cout<< facotrial(3,1);
    
    return 0;

}