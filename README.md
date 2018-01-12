# Record-Filter
This is a Simple C filter tool that takes two files with records in it. The program would filter the records outputting the records that are listed in file2, but not in file1.

ALGORITHM:
2 dynamic lists of records are created using array of nodes. theList1 for the records in "thefile1" and theList2 for the records to be outputed. Then, records in "thefile2" are compared with records in theList1. If the record is not in theList1, then is copied into theList2. finally, theList2 is printed with the printList function.

FORMAT:
the format of the records in the file should be the following: [month/day/year last, name $transaction-amount]

ISSUES:
- sortList fuction does not work properly. It was supposed to sort the list in a specific order. Because of this, the output is   displayed in no organized order.

POSSIBLE IMPROVEMENTS:
- The program could take an imput of the order in which the user wants to sort the output. That would make it more practical.
- Efficiency, as it is always something that can improve.

PS:
I added 2 files to test the program.

Franklin Nunez
