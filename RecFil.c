
/** 
 * Author:        Franklin Nunez
 *                
 * Name:          RecFil 
 *                
 * Email:         fn7420@rit.edu
 *                
 * Description:   This is a Simple C filter tool that takes two files with 
 *                records in it. The program would filter the records 
 *                outputting the records that are listed in file2, but not 
 *                in file1. Records must be in the format of
 *                
 * Format:        The records in the files must be in the following format:
 *                "month/day/year last, name $transaction-amount"
 *                
 * Colaboration:  
 * 
 */

#include "node.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

  if(argc == 3){
    
    struct lnode *theList = NULL;
    struct lnode *theList2 = NULL;
    struct lnode *theRecord;
  
    FILE *theFile1;
    FILE *theFile2;
  
    int month;
    int year;
    int day;
    char lastName[100];
    char name[100]; 
    double transaction;

    theFile1 = fopen(argv[1], "r");
    theFile2 = fopen(argv[2], "r");
  
  
    //scanning theFile1 and populating a list of records
    while(fscanf(theFile1, "%d/%d/%d %s %s $%lf",
		 &day, &month, &year, lastName, name, &transaction) != EOF){
      //creating the record
      theRecord = createRecord(name, lastName, transaction, day, month, year);
      // adding the record to theList
      theList = addRecord(theList, theRecord);    
    }//while1    

    //this is comparing the records from the second file to the records 
    //of the first file and putting the records that are in 
    //theFile2 but not in theFile on a second list, "theList2"
    while(fscanf(theFile2, "%d/%d/%d %s %s $%lf",
		 &day, &month, &year, lastName, name, &transaction) != EOF){
      
      theRecord = createRecord(name, lastName, transaction, day, month, year);
      
      if((findRecord(theList, theRecord)) == 0)
        theList2 = addRecord(theList2, theRecord);
      
    }//while2

    printf("These are the records that are in theFile2 but not in thefile1:\n");
    printList(theList2);
    return 0;
  }//if

  else{
    printf("Usage: [program] [theFile1] [theFile2]\n");
    return 1;
  }
}//main
