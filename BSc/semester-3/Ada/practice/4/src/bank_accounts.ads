with Ada.Text_IO;
generic
   type Transaction is private;
   type Transaction_Array is array (Positive range <>) of Transaction;
   Max_Transactions: Positive;
   with function Create_Transaction(From:Natural;To:Natural;Value:Natural) return Transaction;
package Bank_Accounts is
   type Bank_Account(ID:Positive) is limited private;
   
   Limit_Reach: exception;
   
   procedure Deposit(Acc: in out Bank_Account; Value:Positive);
   procedure Withdraw(Acc: in out Bank_Account; Value:Positive);
   function  Get_Balance(Acc: Bank_Account) return Natural;
   function Get_Transactions(Acc:Bank_Account) return Transaction_Array;
   function Get_C(Acc:Bank_Account) return Natural;
   
   procedure Send(From: in out Bank_Account; To: in out Bank_Account; Value: Positive);
   
   
private
   type Bank_Account(ID:Positive) is 
      record
         Balance:Natural := 0;         
         Transaction_Count: Natural := 0;
         Transactions: Transaction_Array(1..Max_Transactions);
      end record;
      

end Bank_Accounts;
