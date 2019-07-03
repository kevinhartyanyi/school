with Ada.Text_IO;
procedure Main is
   type Matrix is array (Integer range <>, Integer range <>) of Integer;
   M:Matrix(1..3,1..2) := ((1,2),(1,2),(1,2));
begin
   for I in M'Range(1) loop
      for J in M'Range(2) loop
      Ada.Text_IO.Put_Line(Integer'Image(M(I,J)));
      end loop;
   end loop;
end Main;
