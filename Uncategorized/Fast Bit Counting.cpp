int setbits(unsigned long long x){
    return __builtin_popcountll(x);
}