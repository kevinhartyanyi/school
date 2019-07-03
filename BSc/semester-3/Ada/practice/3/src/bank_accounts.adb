package body Bank_Accounts is

   procedure Deposit(Acc: in out Bank_Account; Value:Positive) is
   begin
      Acc.Balance := Acc.Balance + Value;
      Acc.Transactions(Acc.Transaction_Count+1) := Create_Transaction(Acc.ID,0,Value);
      Acc.Transaction_Count := Acc.Transaction_Count + 1;
   end;
   
   procedure Withdraw(Acc: in out Bank_Account; Value:Positive) is
   begin
      if Value > Acc.Balance then
         Acc.Balance := 0;
         Acc.Transactions(Acc.Transaction_Count) := Create_Transaction(0,Acc.ID,Acc.Balance);
      else
         Acc.Balance := Acc.Balance - Value;
         Acc.Transactions(Acc.Transaction_Count) := Create_Transaction(0,Acc.ID,Value);
         
      end if;
      Acc.Transaction_Count := Acc.Transaction_Count + 1;
   end;
   
   function  Get_Balance(Acc: Bank_Account) return Natural is
   begin
      return Acc.Balance;
   end;
   

end Bank_Accounts;
