package body Bank_Accounts is

   procedure Deposit(Acc: in out Bank_Account; Value:Positive) is
   begin
      Acc.Balance := Acc.Balance + Value;
      Acc.Transactions(Acc.Transaction_Count+1) := Create_Transaction(Acc.ID,0,Value);
      Acc.Transaction_Count := Acc.Transaction_Count + 1;
      if Value > 10 then
         raise Limit_Reach;
      end if;
   end;
   
   procedure Withdraw(Acc: in out Bank_Account; Value:Positive) is
   begin
      if Value > Acc.Balance then         
         Acc.Transactions(Acc.Transaction_Count+1) := Create_Transaction(0,Acc.ID,Acc.Balance);
         Acc.Balance := 0;
      else
         Acc.Balance := Acc.Balance - Value;
         Acc.Transactions(Acc.Transaction_Count+1) := Create_Transaction(0,Acc.ID,Value);
         
      end if;
      Acc.Transaction_Count := Acc.Transaction_Count + 1;
   end;
   
   function  Get_Balance(Acc: Bank_Account) return Natural is
   begin
      return Acc.Balance;
   end;
   function Get_Transactions(Acc:Bank_Account) return Transaction_Array is
   begin
      return Acc.Transactions;
   end;
   function Get_C(Acc:Bank_Account) return Natural is
   begin
      return Acc.Transaction_Count;
   end;
   
   procedure Send(From: in out Bank_Account; To: in out Bank_Account; Value: Positive) is
   begin
      if Value > From.Balance then
         To.Balance := To.Balance + From.Balance;
         From.Transactions(From.Transaction_Count) := Create_Transaction(From.ID,To.ID,From.Balance);
         To.Transactions(To.Transaction_Count) := Create_Transaction(From.ID,To.ID,From.Balance);
         From.Balance := 0;           
      else
         To.Balance := To.Balance + Value;
         From.Balance := From.Balance - Value;  
         To.Transactions(To.Transaction_Count) := Create_Transaction(From.ID,To.ID,Value);
         From.Transactions(From.Transaction_Count) := Create_Transaction(From.ID,To.ID,Value);
      end if;
      From.Transaction_Count := From.Transaction_Count + 1;
      To.Transaction_Count := To.Transaction_Count + 1;
   end;
   

end Bank_Accounts;
