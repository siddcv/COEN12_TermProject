# ifndef FINAL_H
# define FINAL_H

#define maxstudents 1000

typedef struct set SET; 

SET *createDataSet(int maxElts); 

void destoryDataSet(SET *sp); 

int searchAge(SET *sp, int inputAge, bool *found); 

void second_searcher(SET *sp, int inputAge); 

void insertion(SET *sp, int inputAge, int inputID); 

void deletion(SET *sp, int inputAge, int inputID); 

int maxAgeGap(SET *sp); 

# endif
