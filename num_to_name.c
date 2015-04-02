/* Author: Anu Mercian
 * write a function that takes in an int and returns a string that would be how one would say that number (ex: 123 -> one hundred twenty three; 50019 -> five thousand nineteen)
 */

#include<stdio.h>
#include<stdlib.h>

/* Alternate solution, instead of struct, a direct array can be used since index matches the names*/
struct message {
  int val;
  const char *msg;
}

void conv_int_to_string(int n)
{
    int iteration;
    char name[];
    struct message messages_ones[] = {
        {1, "one"},
        {2, "two"},
        {3, "three"},
        {4, "four"},
        {5, "five"},
        {6, "six"},
        {7, "seven"},
        {8, "eight"},
        {9, "nine"}
    };

    struct message messages_tens[] = {
	{10, "ten"},
	{100, "hundred"},
	{1000, "thousand"}
    };   

    struct message messages_twos[] = {
	{11, "eleven"},
	{12, "twelve"},
	{13, "thirteen"},
	{14, "fourteen"},
	{15, "fifteen"},
	{16, "sixteen"},
	{17, "seventeen"},
	{18, "eighteen"},
	{19, "nineteen"}
    };

    struct message messages_multiple[] = {
	{20, "twenty"},
	{30, "thirty"},
	{40, "forty"},
	{50, "fifty"},
	{60, "sixty"},
	{70, "seventy"},
	{80, "eighty"},
	{90, "ninety"}
    };

    /* the number of components in each struct */
    size_t nmessages = sizeof messages / sizeof messages[0];
    size_t i;

    while(n>0)
    {
	iteration++;
	if(iteration == 1){
	   num = n/10;
	   /* Avoid eleven to nineteen */
	   if (n/100 != 1){
	      for(i=1; i<= nmessages_ones; i++){
		if(num == messages_ones[i].val)
		    name[iteration] = messages_ones[i].msg;
	      }
	   }
	}
	if(iteration == 2){
	   num = n/10;
	   if(num == 1){
	     for(i=1; i<= nmessages_twos; i++){
		if(num == messages_twos[i].val)
		    name[iteration] = messages_twos[i].msg;
	     }
	   }
	   if(num > 1)
	     for(i=1; i<= nmessages_multiple; i++){
		if(num == messages_multiple[i].val)
		    name[iteration] = messages_multiple[i].msg;
	     }
	}
	

	n = n/10;
    }
}
int main()
{
  int n;
  print("enter number to convert to string \n");
  scanf("%d", &n);
  
  conv_int_to_string(n);
  return 0;
}
