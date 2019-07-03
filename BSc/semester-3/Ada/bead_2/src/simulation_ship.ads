with Ada.Text_IO;
package simulation_ship is

   type Faction is (Rebel, Imperial); --Ebbol most ketto van

   task type Ship(ID: Integer; Side: Faction) is
      entry Hit;
      entry Call_Back;
   end Ship;

end simulation_ship;
