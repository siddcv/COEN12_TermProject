//Rishabh Shyamsunder
//Application Three 
//COEN 12: MWF: 10:30 - 11:35 Session
//Professor Yuhong Liu 

#include <stdio.h>  
#include <stdlib.h> 
#include <assert.h> 
#include <stdbool.h> 
#include <time.h> 
#include "implementation3.h"

typedef struct node{ 
    struct node *prev; 
    struct node *next; 
    int age; 
    int id;  
}NODE; 

typedef struct list{ 
    NODE *head; 
    int count; 
}LIST; 

LIST *createDataSet(){ 
    LIST *lp = malloc(sizeof(LIST)); 
    assert(lp != NULL); 
    lp->head = malloc(sizeof(NODE));//creation of the head node  
    assert(lp->head != NULL);
    lp->head->next = lp->head;//creating the circular link from the next 
    lp->head->prev = lp->head;//creating the circular link from the prev  
    lp->head->age = 0; 
    lp->head->id = 0;
    lp->count = 0;   
    return lp;//creation of the list 
}

void destroyDataSet(LIST *lp){ 
    assert(lp != NULL);
    NODE *temp2; 
    NODE *temp = lp->head->prev; 
    while(temp->next != lp->head){ 
	temp2 = temp->prev; 
	free(temp); //freeing the node
	temp = temp2;
    } 
    free(temp);//freeing the node after the traversal 
    free(lp);//deleting of the list   
} 

int searchAge(LIST *lp, int inputAge){ 
    assert(lp != NULL); 
    NODE *temp = lp->head; 
    while(temp->next != lp->head){ 
	if(temp->age == inputAge){ //condition to check for the email 
	    printf("Age Successfully Found: %d\n", inputAge);//prints the age 
	    printf("ID Successfully Found: %d\n", temp->id);//prints the ID associated with that particular age       
	} 
	temp = temp->next; 
    }
    if(temp->age == inputAge){
	printf("Age Successfully Found: %d\n", inputAge);
	printf("ID Sucessfully Found: %d\n", temp->id);  
	return inputAge; 
    } 
    return -1; 
} 

int searchID(LIST *lp, int inputID){ 
    assert(lp != NULL); 
    NODE *temp = lp->head; 
    while(temp->next != lp->head){ 
	if(temp->id == inputID){//comparison of the ID inputted 
	    printf("ID Successfully Found: %d and the Age is %d\n", inputID, temp->age);//prints out the ID and the Age associated with the ID  
	    return inputID; 
	} 
	temp = temp->next; 
    } 
    if(temp->id == inputID){ 
	printf("ID Sucessfully Found: %d and the Age is %d\n", inputID, temp->age);
	return inputID; 
    }
    printf("ID not found\n");//if it is not found the ID is not found then  
    return -1; 
} 

void insertion(LIST *lp, int inputAge, int inputID){ 
    assert(lp != NULL); 
    NODE *pNew = malloc(sizeof(NODE));//allocation of new node  
    assert(pNew != NULL); 
    pNew->age = inputAge;//inputted age at the new node age 
    pNew->id = inputID;//inputted ID at the new node id 
    NODE *temp = lp->head; 
    while(temp->next != lp->head){//traversal
	if(temp->next->age >= inputAge){//comparison of the ages to put in order  
	    pNew->next = temp->next; 
	    pNew->prev = temp; 
	    temp->next->prev = pNew; 
	    temp->next = pNew;
	    return; 
	}
	temp = temp->next; 
    }
    //if we dont insert then we insert at the end of the linked list   
    pNew->next = temp->next; 
    pNew->prev = temp; 
    temp->next->prev = pNew; 
    temp->next = pNew; 
    lp->count++;//incremention of counnt 
    return; 
}    

//deletes the node according to the ID because cant delete by age 
void deletion(LIST *lp, int inputID){ 
    assert(lp != NULL); 
    NODE *temp = lp->head; 
    while(temp->next != lp->head){ 
	if(temp->id == inputID){ 
	    temp->prev->next = temp->next; 
	    temp->next->prev = temp->prev;
	    free(temp);//freeing of the node 
	    printf("ID Sucessfully Deleted: %d with the Age of %d\n", inputID,temp->age); 
	    return;  
	} 
	temp = temp->next;
	lp->count--;//decrementation of count 
    } 
    if(temp->id == inputID){//if we dont delete from the iteration from the previous loop 
	temp->prev->next = temp->next; 
	temp->next->prev = temp->prev; 
	free(temp);//freeing of the node 
	printf("ID Successfully Deleted: %d with the Age of %d\n", inputID,temp->age);
	return;  
    }
    printf("ID Not Found\n"); 
} 
//returns the max age gap
int maxAgeGap(LIST *lp){ 
    assert(lp != NULL); 
    printf("The max age gap is %d\n",(lp->head->prev->age) - (lp->head->next->age)); 
} 

    
