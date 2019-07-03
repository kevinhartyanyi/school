with Ada.Numerics.Discrete_Random;
package simulation_safe_random is

   package Random_Int is new Ada.Numerics.Discrete_Random(Result_Subtype => Integer);
   
   type Map is record
      X: Integer;
      Y: Integer;
   end record;
   
   protected Safe_Random is
      procedure Get_Random(R: out Map);
      procedure Initalise;
   private
      Ready: Boolean := False;
      G: Random_Int.Generator;      
   end Safe_Random;
   
   


end simulation_safe_random;
