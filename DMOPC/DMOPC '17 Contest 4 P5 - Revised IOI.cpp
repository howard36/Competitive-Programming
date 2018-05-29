#include <cstdio>

int main(){
    int N; char c;
    scanf("%d", &N);
    for (int i=0; i<N; i++){
        scanf(" %c", &c);
        printf("%c", c);
    }
    return 0;
}