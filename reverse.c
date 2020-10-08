void reverseString(char* s, int sSize){

    char tmp;
    for (int i=0; i<=((sSize)/2)-1;i++)
    {
        printf("The element at index %d is %c\n",i,s[i]);
      tmp =  s[i];
      s[i] = s[sSize-1-i];
      s[sSize-1-i] = tmp;
        
    }
}