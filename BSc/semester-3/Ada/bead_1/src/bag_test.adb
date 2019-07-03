with Bag_Package; with Ada.Numerics.Discrete_Random; with Ada.Text_IO;
use Ada.Text_IO;

procedure Bag_Test is
   subtype Kocka is Integer range 1..6;
   package Dice_Bag is new Bag_Package(Kocka, Natural);
   dice: Dice_Bag.Bag;
   package Rand_Int is new Ada.Numerics.Discrete_Random(Kocka);
   Roll: Kocka;
   Seed: Rand_Int.Generator;
   l: Boolean := True;
begin
   Dice_Bag.Empty(dice);
   
   Rand_Int.Reset(Seed);
   
   -- Adding random numbers
   for I in 1..20 loop
      Roll := Rand_Int.Random(Seed);
      Dice_Bag.Add(dice, Roll);
   end loop;
   
   
   while l loop
      for I in 1..6 loop 
         if Dice_Bag.Has_Any(dice, I) = False then   
            Put("Least: ");
            Put_Line(Integer'Image(I));            
            l := False;            
         end if;
         Dice_Bag.Remove(dice, I);         
      end loop;      
   end loop;
   
end Bag_Test;
