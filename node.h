//this is the a list structucture with nodes
struct lnode{

  struct lnode *next;//a pointer to the next node
  struct lnode *prev;//a pointer to the previous node
  char *name;         //name of the person
  char *lastName;     //last name of the person
  double transaction;    //transaction maount
  int day;            //day of the transaction
  int month;          //month of the transaction
  int year;           // year of the transaction
};

struct lnode *sortList(struct lnode *theList);

struct lnode *createRecord(char *name, char *lastName, double transaction,
			   int month, int day, int year);

struct lnode *addRecord(struct lnode *theList, struct lnode *theRecord);

int findRecord(struct lnode *theList, struct lnode *theRecord);
  
void printList(struct lnode *theList);
