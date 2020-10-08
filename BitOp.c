#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/********Concept of XOR gives sum of the two numbers
 * Carry is accounted for by bit wise AND which gives position of set bits in the two numbers
 * That is shifted left by one position and added to the result
 * 
 * x  y  add carry
 * 0  0   0   0
 * 0   1  1   0
 * 1   0  1   0
 * 1   1  0   1   
 * *************************************************************************/
int add(int x,int y) {
    
    int res=0;
    
    
    while(y != 0) {
        int carry = x & y; // common set bits in both numbers
       x = x ^ y;  // addition
       y=carry<<1;
       
    }
    res=x;
    return res;
}

/*****************Sunbtractor again uses XOR. Borrow is simulated with 
 * ~x & y. The only place where borrow is set is where denominator and numerator
 * are opposite of each other and where denominiator is 1 
 * 
 * x  y  diff borrow
 * 0  0   0    0
 * 0  1   1    1 
 * 1 0    1    0   
 * 1 1    0    0
 * ****************************************************************************/
int sub(int x,int y) {
    
    int res=0;
    
    
    
    
    while (y!= 0) {
        // borrow contains common set bit of y and unset bits of x
        int borrow = ~x & y;
        x = x ^ y;
        y = borrow << 1; 
    }
    res=x;
    return res;
}
/************Mulitply numnerator by 2 and divide denom by 1 using << and >>
 * when denom = 1 stop
 * 
 * ****************************************************************************/
int multiply(int x,int y) {
    
    int res=0;
    
    while (y > 0) {
        // when second number becomes odd add first to second
        if (y&1) 
           res = res+x;
           
           x = x<<1;
           y = y>>1;
        
    }
    return res;
}

/*******************************Dividend/divisor = quotient+remainder*************
*Keep subtractng dividend from divisor until divident becomes less than divisor
* When this happens number of times of subtraction becomes quotient and divident becomes remainder
* 
***********************************************************************************/
int divide(int x,int y) {
    
    int res=0;
    
    // sign of the operation is negative only if either is less then zero 
    
    int sign = ((x<0) ^ (y<0)) ? -1:1;
    
    // take absolute value of each number
    
    x = abs(x);
    y = abs(y);
    
    while(x>=y) {
        x -=y;
        ++res;
    }
    return (res*sign);
}

int main(void) {
    
    int x= 9;
    int y = 3;
    int result =0;
    
    result = add(x,y);
    printf("Addition without operators is %d\n",result);
    
    result = sub(x,y);
    printf("Subtraction without operators is %d\n",result);
    
    result = multiply(x,y);
    printf("Multiply without operators is %d\n",result);
    
    result = divide(x,y);
    printf("Multiply without operators is %d\n",result);
}