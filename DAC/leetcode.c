#include <stdio.h>
#include <string.h>
int main()
{
    char s[100] = "1233345654311";
    int count = 1;
    int max=0;
    int size = strlen(s);
    int i,j;
    int index;
    for(i = 0;i<size;i++){
        count=1;
        for(j = 1;j<i-1&&j<size - i -1;j++){
            if(s[i-j]==s[i+j])
                count+=2;
        }
        if(count>max){
            index = i;
            max^=count;
            count^=max;
            max^=count;
        }
    }
    char b = &s[index];

    return 0;
}