with Map_Package; with Warrior_Package; with Bag_Package; with Ada.Text_IO;
procedure Simulation is
   type Field is (Empty, Stone, Wood, Sword, Water, Trap, Enemy);
   subtype Resource is Field range Stone..Sword;
   subtype Obstacle is Field range Water..Enemy;
   function Tool (O: Obstacle) return Resource is
   begin
      if O = Water then
         return Stone;
      elsif O = Trap then
         return Wood;
      elsif O = Enemy then
         return Sword;
      else
         Ada.Text_IO.Put_Line("Error: Bad Obstacle type");
         null;
      end if;
   end;
   

   package Bag is new Bag_Package(Index   => Resource,
                                  Counter => Natural);
   package Warrior is new Warrior_Package(Resource => Resource,
                                          Obstacle => Obstacle,
                                          Tool     => Tool,
                                          Bag      => Bag.Bag,
                                          Empty    => Bag.Empty,
                                          Add      => Bag.Add,
                                          Remove   => Bag.Remove,
                                          Has_Any  => Bag.Has_Any,
                                          write    => Bag.write);
   procedure Field_Action(F: in out Field; W: in out Warrior.Warrior) is
   begin
      if F in Resource then
         Warrior.Collect(W,F);
      elsif F in Obstacle then
         Warrior.Fight(W,F);
      else
         Ada.Text_IO.Put_Line("Nothing");
      end if;
      
      if Warrior.Is_Alive(W) then
         F := Empty;
      end if;
   end;
   package Map is new Map_Package(Field        => Field,
                                  Warrior      => Warrior.Warrior,
                                  Field_Action => Field_Action,
                                  Empty        => Empty);
   MyWarrior:Warrior.Warrior;
   MyMap: Map.Map(5);
   l : Boolean := True;
begin
   Map.Init(MyMap);
   Warrior.Init(MyWarrior);
   Map.Put(MyMap);
   
   while l loop
      Ada.Text_IO.Put_Line("Move");
      Map.Move(MyMap, MyWarrior);
      if Warrior.Is_Alive(MyWarrior) = False then
         Ada.Text_IO.Put_Line("Warrior dead");
         l := False;
      elsif Map.Is_Empty(MyMap) then
         Ada.Text_IO.Put_Line("Map Cleared");
         l := False;
      end if;
      Map.Put(MyMap);
   end loop;
end Simulation;
