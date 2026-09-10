#include <iostream>
using namespace std;
int powerProblem(int num){
    //to check if the number is a power of 2 we can use the fact that any number that is a power of 2 has only
    //one set bit i.e. 1 as the leftmost bit and if we substract 1 from the decimal form than the bits
    //get totally reversed, so performing bitwise AND gives 0 on the number and number-1... and if the number aint
    //power of two then it will simply not give a whole 0 binary bit
    // if(num & num - 1){
    //     cout<<num<<" is not a power of 2"<<endl;
    // }else{
    //     cout<<num<<" is a power of 2"<<endl;
    // };

    while( num > 1 && num % 2 == 0){
        num = num >> 1;
    }
    if (num==1)
    {
       cout<<"Power of 2"<<endl;
    }else{
        cout<<"Not a power of 2"<<endl;
    }
    
    return 0;
};

//function to reverse a number 
int reverseNum(int num2){
    int rev = 0;
    while(num2 >0){
        int digit = num2 % 10;
        rev = rev * 10 + digit;
        num2/=10;
    }
    cout<<rev<<endl;
    return 0;
};

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

    powerProblem(7);
    reverseNum(12345);
};

