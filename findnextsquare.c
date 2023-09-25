// Make a program that filters a list of strings and returns a list with only your friends name in it.

// If a name has exactly 4 letters in it, you can be sure that it has to be a friend of yours! Otherwise, you can be sure he's not...

// Ex: Input = ["Ryan", "Kieran", "Jason", "Yous"], Output = ["Ryan", "Yous"]

// i.e.

// friend ["Ryan", "Kieran", "Mark"] `shouldBe` ["Ryan", "Mark"]
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long int findNextSquare(long int sq)
{
    long int nsqrt = floor((double)sqrt(sq));
    
    if(nsqrt * nsqrt == sq){
        long int next = nsqrt + 1;
        next *= next;
        printf("%d", next);
        return next;
    }else{
        return -1;
    }
}

int main(int argc, char const *argv[])
{
    findNextSquare(121);
}

