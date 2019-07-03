with Ada.Text_IO, filter_n;
procedure Main is
   type A is array (Integer range <>) of Integer;
   A1 : A(1..10) := (5,2,4,2,6,2,1,6,3,1);
   A2 : A(1..10);
   function Cond (I: Integer) return Boolean is
   begin
      return I < 5;
   end;

   function Cond2 (I: Integer) return Boolean is
   begin
      return I >= 5;
   end;

   procedure myfilter is new filter_n(Size       => 3,
                            Item       => Integer,
                            Index      => Integer,
                            Item_Array => A,
                                      Condition  => Cond);
   procedure myfilter2 is new filter_n(Size       => 3,
                            Item       => Integer,
                            Index      => Integer,
                            Item_Array => A,
                                      Condition  => Cond2);
   n:Natural:=0;
begin
   myfilter(A1,A2,n);
   for I in 1..n loop
      Ada.Text_IO.Put(Integer'Image(A2(I)));
   end loop;
   myfilter2(A1,A2,n);
   for I in 1..n loop
      Ada.Text_IO.Put(Integer'Image(A2(I)));
   end loop;

end Main;
