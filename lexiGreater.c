/*
 *  Author: Anu Mercian
 */


#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

string lexico(string W[i]){
    /*create another string s lexicogaphically greater*/
    char s[100];
    for(int i=1; i<=t; i++){
        for(int j=1; j<=length[i]; j++){
            /*Make a new string by modifying from the end*/
            
        }
    }
}

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int t, length[100000];
    char string[100], W[100000][100] /*An array of strings*/;
    scanf("%d", &t);
    for (int i=1; i<=t; i++){
        scanf("%s", &string);
        W[i] = string;
        /*finding length of string*/
        for(char j=0; j!='\0'; ++j);
        length[i]=j;
    }
    
    for (int i=1; i<=t; i++){
        printf("%s", lexico(W[i]));
    }
    return 0;
}

