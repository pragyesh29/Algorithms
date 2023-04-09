#include<iostream>
using namespace std;

double piValue(int n = 100000000){
    long long count = 0;

    for(int i = 0; i < n; i++){
        double x = rand()/(double)RAND_MAX;
        double y = rand()/(double)RAND_MAX;

        if((x*x + y*y) < 1){
            count++;
        }
    }
    return ((count/(double)n)*(double)4);
}

int main(){
    cout << piValue();
    return 0;
}