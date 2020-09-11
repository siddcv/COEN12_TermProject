//Rishabh Shyamsunder
//MWF: COEN 12: 10:30 AM - 11:35 AM
//Final Project
//Professor Liu 
//Implementation 1

#include <stdio.h> 
#include <assert.h>  
#include <stdlib.h> 
#include <stdbool.h> 
#include "implementation1.h"
#include <time.h>  


typedef struct set{ 
    int *age; 
    int *id;
    int length; 
    int count; 
}SET; 

SET *createDataSet(int maxElts){ //creation of the whole set 
    SET *sp = malloc(sizeof(SET)); 
    assert(sp!=NULL);  
    sp->length = maxElts;//the length of the set  
    sp->age = malloc(sizeof(int)*maxElts); //allocation of memory for age
    sp->id = malloc(sizeof(int)*maxElts); //allocation of memory for id 
    assert(sp->age != NULL && sp->id != NULL);
    sp->count = 0;  
    return sp;//creation of the set  
} 

void destroyDataSet(SET *sp){ 
    assert(sp!= NULL); 
    free(sp);//deletes the whole set  
    return; 
} 

int searchAge(SET *sp, int inputAge, bool *found){
    int low, high, mid;//binary search  
    low = 0; 
    high = sp->count-1;
    while(low <= high){ 
	mid = (low + high)/2;
	if(inputAge < sp->age[mid]){ 
	    high = mid -1; 
	} 
	else if(inputAge > sp->age[mid]){ 
	    low = mid+1; 
	} 
	else{ 
	    *found = true;
	    return mid;  
	} 
    } 
   *found = false; 
    return low; 
}

void second_searcher(SET *sp, int inputAge){ 
    int i; 
    bool found = false;
    for(i = 0; i < sp->count; i++){ 
	if(sp->age[i] == inputAge){//checker of the age if it is the same  
	    printf("Age is sucecssfully found and it is %d and the ID was successfully found and it is %d\n", sp->age[i], sp->id[i]);
	} 
    } 
}  
 
void insertion(SET *sp, int inputAge, int inputID){ 
     assert(sp != NULL); 
    if(sp->count == sp->length){ //statement to cap off the lmax amount of insertions that are possible  
	return; 
    } 
    bool found = false; 
    int index = searchAge(sp, inputAge, &found);//index from the age searched 
    int i = sp->count-1;
    while(i >= index){//traversal of the place to insert  
	sp->age[i+1] = sp->age[i]; 
	sp->id[i+1] = sp->id[i];
	i--; 
    } 
    sp->age[index] = inputAge;//inserting the age at the index
    sp->id[index] = inputID;//inserting the ID at the index 
    sp->count++;//incrementation of count  
    return;
}

void deletion(SET *sp, int inputAge, int inputID){ 
    bool found = true;
    int i;
    for(i = 0; i < sp->count; i++){ //traversal of the set
	int index = searchAge(sp, inputAge,&found);
	if(found == true){ //if we find the element we want to delete 
	    int j;
	    printf("Age Successully Deleted: %d\n", inputAge); 
	    printf("ID Successfully Deleted: %d\n", sp->id[index]);  
	    for(j = index + 1; j < sp->count; j++){//the deletion process 
		sp->age[j-1] = sp->age[j]; 
		sp->id[j-1] = sp->id[j];
	    } 
	    sp->count--;//decrementation of the count of the set     
	} 
    }
} 
/*This method returns the max age gap. 
I entered the last element in the set and subtracted that amount 
by the first element since it was a sorted array*/
int maxAgeGap(SET *sp){ 
    int gap = (sp->age[sp->count-1] - sp->age[0]); 
    return gap; 
} 


