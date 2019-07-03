with Ada.Numerics.Discrete_Random;
package body simulation_safe_random is


protected body Safe_Random is
   procedure Get_Random(R: out Map) is
      begin
         if not Ready then
            Initalise;
         end if;
         R.X := Random_Int.Random(G); 
         R.Y := Random_Int.Random(G); 
      end;
      procedure Initalise is
      begin
         Random_Int.Reset(G);
      end;
   end Safe_Random;
   

begin
   --  Insert code here.
   null;
end simulation_safe_random;
