#include <stdio.h>
#include <string.h>
struct account
{
   struct
   {
      char lastName[10];
      char firstName[10];
   } names;
   int accountNum;
   double balance;
};
void nextCustomer(struct account *acct);
void printCustomer(struct account acct);
int main()
{
   struct account record;
   int flag = 0;

   do
   {
      nextCustomer(&record);
      if ((strcmp(record.names.firstName, "End") == 0) &&
          (strcmp(record.names.lastName, "Customer") == 0))
         flag = 1;
      if (flag != 1)
         printCustomer(record);
   } while (flag != 1);
}
void nextCustomer(struct account *acct)
{
   /*edit*/
   char dummy[80];
   printf("Enter names (firstName lastName): \n");
   scanf("%s %s", &acct->names.firstName, &acct->names.lastName); // adr of acct(->) then afterwards is (.)
   fgets(dummy, 80, stdin);                                       // used to get rid of newline

   printf("Enter account number: \n");
   scanf("%d", &acct->accountNum);
   fgets(dummy, 80, stdin);

   printf("Enter balance: \n");
   scanf("%lf", &acct->balance); // lf needed for reading double
   fgets(dummy, 80, stdin);
   /*end_edit*/
}
void printCustomer(struct account acct)
{
   /*edit*/
   printf("Customer record: \n");
   printf("%s %s %d %.2f \n", acct.names.firstName, acct.names.lastName, acct.accountNum, acct.balance);
   /*end_edit*/
}