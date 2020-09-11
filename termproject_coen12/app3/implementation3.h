# ifndef FINAL_H 
# define FINAL_H

typedef struct list LIST; 

extern LIST *createDataSet(); 

extern void destroyDataSet(LIST *lp); 

extern int searchAge(LIST *lp, int inputAge); 

extern int searchID(LIST *lp, int inputID); 

extern void insertion(LIST *lp, int inputAge, int inputID); 

extern void deletion(LIST *lp, int inputAge);

extern int maxAgeGap(LIST *lp); 

# endif

