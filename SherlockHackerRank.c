/* Author: Anu Mercian 
 * Problem Statement (From Hacker Rank): Watson gives Sherlock an array A of N elements and two arrays B and C, of M elements each. Then he asks Sherlock to perform an algorithm program. Can you help Sherlock and tell him the resulting array A? You should print all the array elements modulo (10^9+7).
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int i, N, M, a, A[100000], b, B[100000], c, C[100000];
    int MOD = 1000000007;
    scanf("%d%d", &N, &M);
    if(N>=1 && N<= 100000 && M>=1 && M<= 100000){
        for(i=1; i<= N; i++){
            scanf("%d", &a);
            if(a>=1 && a<= 100000)
                A[i] = a;
            else
                A[i] = 0;
        }
        for(i=1; i<= M; i++){
            scanf("%d", &b);
            if(b>=1 && b<= N)
                B[i] = b;
            else
                B[i] = 0;
        }
        for(i=1; i<= M; i++){
            scanf("%d", &c);
            if(c>=1 && c<= 100000)
                C[i] = c;
            else
                C[i] = 0;
        }

        for(i=1; i<=M; i++){
            for(int j=1; j<=N; j++){
              if(j % B[i] == 0)
                A[j] = (A[j] * C[i]) % MOD;
            }
        }

        for(i=1; i<=N; i++)
            printf("%d ",A[i]);
        printf("\n");

    }
    
    return 0;
}
