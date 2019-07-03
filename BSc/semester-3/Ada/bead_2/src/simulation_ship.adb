package body simulation_ship is

   task body Ship is
      
   begin
      loop
         select
            accept Hit do
               Ada.Text_IO.Put("Hit");
            end Hit;
         or
            accept Call_Back  do
               Ada.Text_IO.Put("Call Back");
               -- terminate TODO
            end Call_Back;
         or
            delay 0.5;
            Ada.Text_IO.Put("Shoot");
         end select;
         
      end loop;
      
   end Ship;

end simulation_ship;
