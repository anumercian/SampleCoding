/* Author: Anu Mercian
 * Sample code to emulate an Utopian Tree 
 * (Question obtained from Hacker Rank Website) 
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int T /*Number of lines*/, cycle, N[10] /*Growth cycles*/;
    int growth=1;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    printf("Enter the number of lines \n");
    scanf("%d", &T);
    for (int i=0; i<T; i++){
        scanf("%d", &cycle);
	N[i]= cycle;
    }
    for (int i=0; i<T; i++){
        if (N[i] == 0){
            printf("%d \n", growth);
            break;
        }   
	else {
	  for(int j=1; j<=N[i]; j++){
            if (j % 2 == 0)
                growth += 1;
            else
                growth *= 2;
          }
          printf("%d \n", growth);
	}
        growth=1;
    }
    return 0;
}

