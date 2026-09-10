#include <iostream>
using namespace std;
int main(){
    int a =6, b = 10;
    cout<<"Is it working ??"<<endl;

    //bitwise operators check
    cout<<(a & b)<<endl ; //bitwise and git
    cout<<(a | b)<<endl ; //bitwise OR
    cout<<(a ^ b)<<endl ; //bitwise XOR

    int n = 8, i = 1;
    cout<<(n << i)<<endl ; //left shift <<, a*2powerb
    cout<<(n >> i)<<endl ; //right shift >> a/2powerb

    //data type modifiers
    cout<<sizeof(int)<<"bytes"<<endl;
    cout<<sizeof(long int)<<"bytes"<<endl;
    cout<<sizeof(short int)<<"bytes"<<endl;
    cout<<sizeof(long long int)<<"bytes"<<endl;
    cout<<sizeof(unsigned int)<<"bytes"<<endl;
}