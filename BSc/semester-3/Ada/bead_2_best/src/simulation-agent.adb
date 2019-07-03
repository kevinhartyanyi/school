separate (simulation)

task body Agent is
   begin
      select
         Ship.Call_Back;
      or
         delay 1.0;
      end select;
   end;
