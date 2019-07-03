separate (simulation)

protected body Printer is 
   procedure Out_Text(O: String) is
   begin
      Ada.Text_IO.Put_Line(O);
   end;
   procedure Out_Map(O: in Matrix) is
   begin
      for I in 1..Max loop
         for J in 1..Max loop
            if J <= (Max/2) then
               if O.Stats(I,J) then
                  Ada.Text_IO.Put("I ");
               else
                  Ada.Text_IO.Put(" ");
               end if;            
            else
               if O.Stats(I,J) then
                  Ada.Text_IO.Put("R ");
               else
                  Ada.Text_IO.Put(" ");
               end if;
            end if;            
         end loop;
         Ada.Text_IO.Put_Line("");
      end loop;
   end;
end Printer;
