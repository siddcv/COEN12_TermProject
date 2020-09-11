#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 
#include <time.h> 
#include <stdbool.h> 
#include "implementation3.h"

int main(void){ 
    LIST *lp; 
    int inputAge, inputID = 0;
    lp = createDataSet(); 
    srand(time(NULL)); 
    int i; 
    for(i = 0; i < 1000; i++){ 
	inputID = 1+rand()%2 + inputID; 
	inputAge = 18 + rand()%13; 
	insertion(lp,inputAge,inputID); 
    } 

    int chooseID = 1+rand()%inputID;  
    
    bool found = false; 
    
    searchAge(lp, inputAge); 

    searchID(lp,chooseID);
    
    deletion(lp,chooseID); 
    
    int agegap = maxAgeGap(lp);  
    
    destroyDataSet(lp); 

}  
