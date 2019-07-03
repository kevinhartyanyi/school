with simulation_safe_random, Ada.Text_IO;
use simulation_safe_random;
procedure Simulation is


   I:Integer;
begin
   Safe_Random.Get_Random(I);
   Ada.Text_IO.Put(Integer'Image(I));
end Simulation;
