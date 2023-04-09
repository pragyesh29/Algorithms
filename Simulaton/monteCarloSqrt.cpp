#include<iostream>
using namespace std;

double monteCarloSqrt(int num, int n = 100000000){
    int count = 0;

    for(int i = 0; i < n; i++){
        double x = rand()/(double)RAND_MAX*num;
        if(x < num) count++;
    }
    return n/(double)count;
}

int main(){
    cout << "Enter number : ";
    int num; cin >> num;
    cout << monteCarloSqrt(num);
    return 0;
}