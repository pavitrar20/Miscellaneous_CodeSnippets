/* Atleast one 1 and one zer0 Leet Code Problem**/

int maxDistToClosest(int* seats, int seatsSize){
    
    int maxDistance = 0;
    int numSetBits = 0;
   

    for (int i=0;i<=seatsSize-1;i++) {
      printf("The element at Index %d is %d\n",i,*(seats+i));
        if (*(seats+i) == 1) 
            numSetBits++;
    }
    
    printf("The number of set bits is %d\n",numSetBits);
    
    // retreive indices of set bits in binary array
    int IndxArr[numSetBits];
    numSetBits=0;
    for (int i=0;i<=seatsSize-1;i++) {
     
        if (*(seats+i) == 1)  {
            IndxArr[numSetBits]=i;
             printf("The index of 1 %d\n",i);
            numSetBits++;
            }
        
        
    }
   // calculate distance both on right and left
    
    int rightDist=0,leftDist=0;
    
    for (int i=0;i<=numSetBits-1;i++) {
         if (i==0) leftDist = 0;
            if (i== numSetBits-1) rightDist = 0;
        if (i > 0 && i< numSetBits-1)
        maxDistance = (IndxArr[i]-IndxArr[i-1]) < (IndxArr[i+1] -IndxArr[i]) ? (IndxArr[i]-IndxArr[i-1]):(IndxArr[i+1] -IndxArr[i]);
        else {
           
            if (i==0)
                maxDistance = IndxArr[i+1]-IndxArr[i];
            
        }
    }
    
    printf("Closest Distance is %d\n",maxDistance);
    return maxDistance;
}