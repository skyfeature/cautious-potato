vector<int> Solution::sieve(int A) {
    vector<int> V(A+1);
    for (int i = 0 ; i < A+1; i++){
        V[i] = 1;
    }
    V[0] = 0;
    V[1] = 0;
    for (int i = 2; i <= sqrt(A); i++){
        if (V[i] == 1){
            for (int j = 2; i*j <= A; j++){
                V[i*j] = 0;
            }
        }
    }
    vector<int> primes;
    for (int i = 0; i < A+1; i++){
        if (V[i] == 1)
            primes.push_back(i);
    }
    return primes;
}
