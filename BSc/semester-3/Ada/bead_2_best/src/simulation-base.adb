separate (simulation)

task body Base is
   Ships: Integer;
      
begin
   accept Send_Out_Ships(I: Integer) do
      Ships := I;
      Printer.Out_Text("Created " & Faction'Image(Side) & Integer'Image(Ships) & " Ships");
      --Ada.Text_IO.Put_Line("Created " & Faction'Image(Side) & Integer'Image(Ships) & " Ships");
   end Send_Out_Ships;
   while(Ships > 0) loop
      select           
         accept Ship_Lost do
            Ships := Ships - 1;
            Printer.Out_Text("Ships Lost " & Faction'Image(Side) &" Remaining: "& Integer'Image(Ships));
            --Ada.Text_IO.Put_Line("Ships Lost " & Faction'Image(Side) &" Remaining: "& Integer'Image(Ships));
         end Ship_Lost;
      or
         accept Destroy  do
            Ships := 0;
            Printer.Out_Text("Base "& Faction'Image(Side) & " Destroyed");
            --Ada.Text_IO.Put_Line("Base "& Faction'Image(Side) & " Destroyed"); 
            
         end Destroy;
      or
           terminate;
      end select;         
   end loop;
   Printer.Out_Text("Terminate Base");
   --Ada.Text_IO.Put_Line("Terminate Base");
   if Side = Rebel then
      Printer.Out_Text("Winner: Imperial");
      --Ada.Text_IO.Put_Line("Winner: Imperial");
   else
      Printer.Out_Text("Winner: Rebel");
      --Ada.Text_IO.Put_Line("Winner: Rebel");
   end if;
   Map.End_Fight;
end Base;
