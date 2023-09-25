#include <stdio.h>
#include <stdlib.h>

int past(int hours, int minutes, int seconds) {

    //  <----  hajime!

    //1 segundo == 1000 milisegungos

    int miliseconds = ((hours * 3600) + (minutes * 60) + seconds) * 1000;
  
    return miliseconds;
}

int main(){
    int result = past(0,1,1);
    printf("result: %d", result);

}
