separate (simulation)

task body Ship is    
   Fight: Boolean := True;
   P: P_Access;
begin
   if ID /= 0 then
      while(Fight) loop
         select
            accept Hit do
               Printer.Out_Text("Hit");
               --Ada.Text_IO.Put_Line("Hit");
               Side.Ship_Lost;
               Fight := False;
            end Hit;
         or
            accept Call_Back  do
               Printer.Out_Text("Call Back");
               --Ada.Text_IO.Put_Line("Call Back");
               Fight := False;
            end Call_Back;
         or
            delay 0.5;            
            if ID < 0 then
               P := new Projectile(Rebel);
            else
               P := new Projectile(Imperial); 
            end if;
         
            --Printer.Out_Text("Shoot");
            --Ada.Text_IO.Put("Shoot");
         end select;         
      end loop;
   else
      delay 5.0;
      while(Fight) loop
         select
            accept Call_Back  do
               Printer.Out_Text("Call Back Luke");
               --Ada.Text_IO.Put_Line("Call Back");
               Fight := False;
            end Call_Back;
         or
              delay 1.0;         
         Printer.Out_Text("Luke Shoot");        
         declare
            C: Cord;
         begin
            Safe_Random.Get_Random(C);
            if C.X = C.Y then
               Printer.Out_Text("Luke feels the Force");
               Fight := False;
               Side.Destroy;  
            end if;
         end;                 
            
         end select;
         
      end loop;
   end if;   

end Ship;
