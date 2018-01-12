#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "node.h"

/*lalloc function
 *creates, dinamicaly, space to be used by a lnode structure
 *@return a pointer to a lnode structure
 */
struct lnode *lalloc(void){

  return (struct lnode *) malloc(sizeof(struct lnode));
  
}

/*createRecord function
 *takes all the data needed to create the record of a transaction
 *@return a pointer to a node which is the record
 *@param name is a pointer to an array of chars
 *@param lastName is a pointer to an array of chars
 *@param transaction is an integer that contains the transaction amount
 *@param day is an integer that contain the day of the transaction
 *@param month is an integer that contain the month of the transaction
 *@param year is an integer that contains the year of the transaction
 */
struct lnode *createRecord(char *name, char *lastName, double transaction,
			   int month, int day, int year){

  struct lnode *theRecord;

  theRecord = lalloc();
  
  theRecord->name = strdup(name);
  theRecord->lastName = strdup(lastName);
  theRecord->transaction = transaction;
  theRecord->day = day;
  theRecord->month = month;
  theRecord->year = year;
  theRecord->next = NULL;
  theRecord->prev = NULL;

  return theRecord;
  
}

/*addRecord fuction
 *takes a record and add it to a list of records
 *@return a pointer to a lnode, which would be the begining of the list
 *@param theList is a pointer to the begining of the list structure 
 *@param theRecord is a pointer to the node record that is going to be added
 */
struct lnode *addRecord(struct lnode *theList, struct lnode *theRecord){
  
  if(theList == NULL)
    theList = theRecord;
  
  else{
    
    //temp to travers the list.
    struct lnode *temp = theList;
  
    while(temp->next != NULL)
      temp = temp->next;
    
    temp->next = theRecord;
    theRecord->prev = temp;
  }
  return theList;
}

/*compareRecord
 *it compare to record, if they are the same return 1, 0 otherwise.
 *@param theNode1 is a pointer to a lnode(a record)
 *@param theNode2 is a pointer to a lnode(another record)
 *@return an integer 1 if they are the same or 0 if they are not.
 */
int compareRecord(struct lnode *record1, struct lnode *record2){
  //this checks for the person to be exactly the same
  if((strcmp(record1->name, record2->name)) == 0 && 
  (strcmp(record1->lastName, record2->lastName)) == 0 && 
  (record1->transaction) == (record2->transaction) && 
  (record1->day) == (record2->day) && 
  (record1->month) == (record2->month) && 
  (record1->year) == (record2->year)) 
    return 1;
  
  else
    return 0;
  
}

/*findRecord
 *It indicates whether the record is in the list of record or not
 *@return an integer, 1 if is there or 0 otherwise.
 *@param theList is a pointer to the begining of the list
 *@param theRecord is the record to be found 
 */
int findRecord(struct lnode *theList, struct lnode *theRecord){

  struct lnode *temp = theList;

  while(temp != NULL){

    if((compareRecord(temp, theRecord)) == 1)
      return 1;
      
    //traversing the list
    temp = temp->next;
  }

  return 0; //not found, is in file2, but not in file1
}

/*sortList function
 *this function takes a pointer to the beggining of the list that is going
 *to be sorted.
 *NOTE: This function is highly inefficient, is just used for the pourposes
 *of this project.
 *@return a pointer to a lnode
 *@param theList is the pointer to the first node of the lnode linked list
 */
struct lnode *sortList(struct lnode *theList){

  //This is to traverse theList and keep track
  //of the lowest value of whatever is being compare
  //date, name, lastname or transaction. 
  struct lnode *temp, *theLowest = theList;
     //this is going to be the sorted list
  struct lnode *newList = NULL;
  //keep looping until there is just 
  while(theList != NULL){
    //finding the lowest
    while(temp != NULL){
      //this is all the conditions in order to sort by date, lastname, name,
      //and transaction respectively.
      if((temp->year) < (theLowest->year))
	theLowest = temp;
      
      else if((temp->year == theLowest->year) &&
	      (temp->month < theLowest->month))
	theLowest = temp;
      
      else if((temp->month == theLowest->month) &&
	      (temp->year == theLowest->year) &&
	      (temp->day < theLowest->day))
	theLowest = temp;
      
      else if((temp->day == theLowest->day) &&
	      (temp->month == theLowest->month) &&
	      (temp->year == theLowest->month) &&
	      (strcmp(temp->lastName, theLowest->lastName)) < 0)
	theLowest = temp;
      
      else if((strcmp(temp->lastName, theLowest->lastName) == 0) &&
	      (temp->day == theLowest->day) &&
	      (temp->month == theLowest->month) &&
	      (temp->year == theLowest->month) &&
	      (strcmp(temp->name, theLowest->name) < 0))
	theLowest = temp;
      
      else if((temp->day == theLowest->day) &&
	      (temp->month == theLowest->month) &&
	      (temp->year == theLowest->month) &&
	      (strcmp(temp->lastName, theLowest->lastName) == 0) &&
	      (strcmp(temp->name, theLowest->name) == 0) &&
	      (temp->transaction < theLowest->transaction))
	theLowest = temp;
      
      temp = temp->next; //traversing the list
    }

    //if newList is empty
    if(newList == NULL){
      newList = theLowest;
      //Setting the first node into newList
      (newList->prev)->next = theLowest->next;

      //avoiding segmentation fault
      if(newList->next != NULL)
      (newList->next)->prev = theLowest->prev;
      
      newList->prev = NULL;
      newList->next = NULL;
    }

    //there is just one more node in theList
    else if(theList->next == NULL){
      
      temp = newList;
      while(temp->next != NULL)
	temp = temp->next;

      temp->next = theList;
      theList->prev = temp;
      theList = NULL;
      
    }
    
    else{
      //so temp can travers newList
      temp = newList;

      //traversing newList
      while(temp->next != NULL)
	temp = temp->next;
	
      temp->next = theLowest;
      (theLowest->prev)->next = theLowest->next;

      //avoiding segmentation fault
      if(theLowest->next != NULL)
      (theLowest->next)->prev = theLowest->prev;

      //pointing backwards
      (theLowest->prev) = temp;
      //setting the next node to 
      theLowest->next = NULL;
    }
    
    temp = theLowest = theList;
    
  }//mainWhile
  return newList;
}//sortList
 
/*printList
 *this will print all the records in the list by date, last name, firstname
 and transaction repectively
 *@param theList is the list of the records
 */
void printList(struct lnode *theList){

  //to travers the list
  struct lnode *temp;
  temp = theList;

  while(temp != NULL){
    printf("%02d/%02d/%02d %s %s $%.2f\n", temp->month, temp->day, temp->year,
	   temp->lastName, temp->name, temp->transaction);
    temp = temp->next;
  }
}
