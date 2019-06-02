#include <iostream>
using namespace std;
int main() {
    int a = 11,b=15;
    int count=0;
    
    while(a>0 || b>0){
        if((a&1)!=(b&1))
            count++;
        a=a>>1;
        b=b>>1;
    }
    cout<<count;
}

