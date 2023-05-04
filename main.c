#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "testingFuncs.h"




/*======== Function Declarations =========*/


int main(){
    struct timeval start, end;
    gettimeofday(&start, NULL);
    /*Insert Function Here*/
    forward_Propagation();
    gettimeofday(&end, NULL);
    printf("Duration of program: %ld microseconds\n", (((end.tv_sec-start.tv_sec)*1000000)+end.tv_usec-start.tv_usec));
    return 0;
}


