package body simulation_base is

   task body Base is
      Ships: Integer;
      
   begin
      loop
         select
            --Lehet loop ele kell
            accept Send_Out_Ships(I: Integer) do
               Ships := I;
               Ada.Text_IO.Put("Created " & Faction'Image(Side) & Integer'Image(Ships) & " Ships");
            end Send_Out_Ships;
         or
            accept Ship_Lost do
               Ships := Ships - 1;
               Ada.Text_IO.Put("Ships Lost, Remaining: "& Integer'Image(Ships));
            end Ship_Lost;
         or
            accept Destroy  do
               Ships := 0;
               Ada.Text_IO.Put("Base Destroyed");  
               --terminate TODO
            end Destroy;
         end select;
         
      end loop;
   end Base;

end simulation_base;
