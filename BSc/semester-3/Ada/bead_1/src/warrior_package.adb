with Ada.Text_IO; with Ada.Numerics.Discrete_Random;
package body Warrior_Package is

   procedure Init(W: in out Warrior) is      
   begin
      Empty(W.Inventory);
      for I in Resource'Range loop
         Add(W.Inventory,I);
      end loop;
   end;
   
   procedure Fight(W: in out Warrior; O: in out Obstacle) is
   begin
      Ada.Text_IO.Put_Line("Fight: " &  Obstacle'Image(O));
      if Has_Any(W.Inventory, Tool(O)) then
                    Ada.Text_IO.Put_Line("Win");
                    Remove(W.Inventory, Tool(O));
                 else
                    Ada.Text_IO.Put_Line("Lose");
                    W.Status := False;
      end if;
      Ada.Text_IO.Put_Line("Inventory:");  
      write(W.Inventory);
   end;
   
   procedure Collect(W: in out Warrior; R: in Resource) is
   begin
      Ada.Text_IO.Put_Line("Collected: " & Resource'Image(R));
      Add(W.Inventory,R);
      Ada.Text_IO.Put_Line("Inventory:");  
      write(W.Inventory);
   end;
   
   function Is_Alive(W:Warrior) return Boolean is
   begin
      return W.Status;
   end;
   
end Warrior_Package;
