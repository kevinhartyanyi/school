with Ada.Text_IO;
package simulation_base is

   type Faction is (Rebel, Imperial);
   
   task type Base(Side: Faction) is
      entry Send_Out_Ships(I: Integer);
      entry Ship_Lost;
      entry Destroy;
   end Base;
   
end simulation_base;
