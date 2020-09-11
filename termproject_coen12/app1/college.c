#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 
#include <stdbool.h> 
#include <time.h> 
#include "implementation1.h"

#define maxElts 1000

int main(void){ 
    
    SET *sp; 
    
    int inputAge;
    int inputID = 0; 
    
    sp = createDataSet(maxElts); 
    
    srand(time(NULL));
    
    int i; 
    
    for(i = 0; i < 3000; i++){ 
	inputID = 1+rand()%2 + inputID; 
	inputAge = 18 + rand()%13; 
	insertion(sp,inputAge,inputID); 
    }
    
    bool found = false; 
 
    int chooseAge = 18 + rand()%13;   
    
    second_searcher(sp, chooseAge);
    
    chooseAge = 18 + rand()%13;    

    deletion(sp, inputAge, inputID);   
    
    int agegap = maxAgeGap(sp); 
    
    printf("%d is the max age gap\n", agegap); 
    
    destroyDataSet(sp); 
}
