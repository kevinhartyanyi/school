with Ada.Text_IO, Bank_Accounts;
procedure Main is
   type myTransaction is
      record
         From: Natural;
         To:Natural;
         Value:Natural;
      end record;
   function myCreate(From:Natural;To:Natural;Value:Natural) return myTransaction is
      newTransaction: myTransaction;
   begin
      newTransaction.From := From;
      newTransaction.To := To;
      newTransaction.Value := Value;
      return newTransaction;
   end;
   type myArray is array (Positive range <>) of myTransaction;
   package bank is new Bank_Accounts(myTransaction, myArray, 5, myCreate);
   Customer1: bank.Bank_Account(1);
   --Customer2: bank.Bank_Account(2);
begin
   Ada.Text_IO.Put(Natural'Image(bank.Get_Balance(Customer1)));
   bank.Deposit(Customer1, 100);
   Ada.Text_IO.Put(Natural'Image(bank.Get_Balance(Customer1)));
   bank.Withdraw(Customer1, 110);
   Ada.Text_IO.Put(Natural'Image(bank.Get_Balance(Customer1)));




end Main;
