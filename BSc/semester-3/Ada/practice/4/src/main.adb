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
   Customer2: bank.Bank_Account(2);
   Test: myArray(1..5);
begin
   Ada.Text_IO.Put_Line(Natural'Image(bank.Get_Balance(Customer1)));
   bank.Deposit(Customer1, 100);
   Test := bank.Get_Transactions(Customer1);
   for I in 1..bank.Get_C(Customer1) loop
      Ada.Text_IO.Put_Line("From: " &  Natural'Image(Test(I).From));
      Ada.Text_IO.Put_Line("To: " &  Natural'Image(Test(I).To));
      Ada.Text_IO.Put_Line("Value: " &  Natural'Image(Test(I).Value));
   end loop;
   Ada.Text_IO.Put_Line(Natural'Image(bank.Get_Balance(Customer1)));
   bank.Withdraw(Customer1, 110);
   Test := bank.Get_Transactions(Customer1);
   for I in 1..bank.Get_C(Customer1) loop
      Ada.Text_IO.Put_Line("From: " &  Natural'Image(Test(I).From));
      Ada.Text_IO.Put_Line("To: " &  Natural'Image(Test(I).To));
      Ada.Text_IO.Put_Line("Value: " &  Natural'Image(Test(I).Value));
   end loop;


   Ada.Text_IO.Put_Line(Natural'Image(bank.Get_Balance(Customer1)));





end Main;
