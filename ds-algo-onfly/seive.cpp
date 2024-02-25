#include <vector>
using namespace std;

// prime and spf will be populated
// prime[i] will be 1 if i is prime
// spf[i] will give spf of i
//__________________________________________________________________________//

vector<int> prime;
vector<int> spf;

// Seive and smallest prime factor [spf]
vector<int> SPF(int n){
    prime.resize(n+1, 1);
    for(int i = 0; i <= n; i++) spf.push_back(i);
    prime[0] = prime[1] = 0;

    for(int i = 2; i <= n; i++){
        if(prime[i]){
            for(int j = i*i; j <= n; j+=i){
                if(prime[j]) spf[j] = i;
                prime[j] = 0;
            }
        }
    }
    return spf;
}