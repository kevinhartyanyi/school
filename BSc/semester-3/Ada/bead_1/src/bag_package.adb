package body Bag_Package is
   
   procedure Empty(B: in out Bag) is
   begin
      for E of B.MT loop
         E := Counter'First;
      end loop;
   end;
   
   procedure Add(B: in out Bag; I:Index) is
   begin      
      B.MT(I) := Counter'Succ(B.MT(I));
   end;
   
   procedure Remove(B: in out Bag; I:Index) is
   begin
      if B.MT(I) /= Counter'First then
         B.MT(I) := Counter'Pred(B.MT(I));
      end if;      
   end;
   
   function Has_Any (B:Bag; I:Index) return Boolean is
   begin
      return (B.MT(I) > Counter'First);
   end;
   
   procedure write(B: Bag) is
   begin
      for E in B.MT'Range loop
         Ada.Text_IO.Put_Line(Index'Image(E) & ": " & Counter'Image(B.MT(E)));
      end loop;
   end;
   

end Bag_Package; 
