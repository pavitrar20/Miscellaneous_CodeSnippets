#include <stdio.h>
#include <stdlib.h>
#include<string.h>

char * reverseVowels(char * s){
    char* reverse;
    reverse = (char *)malloc(sizeof(char *)*strlen(s+1));
    
    if (reverse == NULL)
        return reverse;
        
        printf("Length of reverse is %d\n",strlen(reverse));
     int len = strlen(s); // account for array arithmetic starting at 0
     printf("Length of input is %d\n",len);
    for(int i=0;i<len/2;i++) {
    
             printf("The element at index %d is %c and at %d is %c\n",i,s[i],len-1-i,s[len-1-i]);
           // reverse only if Vowels
          if (((s[i] == 'a') || (s[i] == 'e') || (s[i] == 'i') || (s[i] == 'o') || (s[i] == 'u')) &&
            ((s[len-1-i] == 'a') || (s[len-1-i] == 'e') || (s[len-1-i] == 'i') || (s[len-1-i] == 'o') || (s[len-1-i] == 'u')) )
            {
            reverse[(len-1)-i] = s[i];
            reverse[i] = s[(len-1)-i];
            }
            else {
            reverse[i] = s[i];
            reverse[(len-1)-i] = s[(len-1)-i];
            }
    }
    
    printf("Length of reverse is %d\n",strlen(reverse));
    return reverse;
}
int main() {
	//code
	
	char *strs = "leetcode\0";
    char* reverse = reverseVowels(strs);
    
    printf("Length is %d\n",strlen(reverse));
    printf("The reversed Array is :\n");
    
    for(int i=0;i<strlen(reverse);i++) {
        printf("The char at Index %d is %c\n",i,reverse[i]);
    }
	return 0;
}