with Ada.Numerics.Discrete_Random; with Ada.Text_IO;
package body Map_Package is  
  
   
   procedure Init(M: in out Map) is 
      package Rand_Field is new Ada.Numerics.Discrete_Random(Field);
      Seed: Rand_Field.Generator;
      subtype Size is Positive range 1..M.n;
      package Rand_Pos is new Ada.Numerics.Discrete_Random(Size);
      Seed_Pos:Rand_Pos.Generator;
      Pos:Cord;
      --Random:Field;      
   begin
      Rand_Field.Reset(Seed);
      for I in M.Fields'Range(1) loop
         for J in M.Fields'Range(2) loop            
         M.Fields(I,J) := Rand_Field.Random(Seed);
         Ada.Text_IO.Put_Line("Map Field: "& Integer'Image(I) & " " & Integer'Image(J) & " " & Field'Image(M.Fields(I,J)));
         end loop;
      end loop;
      
      Rand_Pos.Reset(Seed_Pos);
      Pos.x := Rand_Pos.Random(Seed_Pos);
      Pos.y := Rand_Pos.Random(Seed_Pos);
      M.Position := Pos;
      Ada.Text_IO.Put_Line("Starting Position: " & " x: " & Positive'Image(M.Position.x) & " y: " & Positive'Image(M.Position.y));
   end;
   procedure Put(M: in Map) is
   begin
      Ada.Text_IO.Put_Line("Draw Map:");
      for I in M.Fields'Range(2) loop
         for J in M.Fields'Range(1) loop
            Ada.Text_IO.Put(" " & Field'Image(M.Fields(J,I)));
         end loop;
         Ada.Text_IO.Put_Line("");
      end loop;
   end;
   procedure Move(M: in out Map; W: in out Warrior) is 
      type Direction is (Up, Down, Left, Right);
      package Rand_Dir is new Ada.Numerics.Discrete_Random(Direction);
      Seed:Rand_Dir.Generator;
      Random:Direction;
   begin
      Rand_Dir.Reset(Seed);
      Random := Rand_Dir.Random(Seed);
      Ada.Text_IO.Put_Line("Random Move: " & Direction'Image(Random));
      Ada.Text_IO.Put_Line("Current Position: x = "& Integer'Image(M.Position.x) & " y = "& Integer'Image(M.Position.y) & " Field: " & Field'Image(M.Fields(M.Position.x,M.Position.y)));
      if Random = Up then
         if M.Position.y = 1 then
            M.Position.y := M.Fields'Last(1);
         else
            M.Position.y := M.Position.y - 1;            
         end if;
      elsif Random = Down then
         if M.Position.y = M.Fields'Last(1) then
            M.Position.y := 1;
         else
            M.Position.y := M.Position.y + 1;            
         end if;
      elsif Random = Left then
         if M.Position.x = 1 then
            M.Position.x := M.Fields'Last(1);
         else
            M.Position.x := M.Position.x - 1;            
         end if;
      else
         if M.Position.x = M.Fields'Last(1) then
            M.Position.x := 1;
         else
            M.Position.x := M.Position.x + 1;            
         end if;
         
      end if;
      Ada.Text_IO.Put_Line("After Move Position: x = "& Integer'Image(M.Position.x) & " y = "& Integer'Image(M.Position.y) & " Field: " & Field'Image(M.Fields(M.Position.x,M.Position.y)));
      
      Field_Action(M.Fields(M.Position.x,M.Position.y), W);
      
   end;
   
   function Is_Empty(M: Map) return Boolean is
   begin
      for I in M.Fields'Range(1) loop
         for J in M.Fields'Range(2) loop
            if M.Fields(I,J) /= Empty then
               return False;
            end if;
         end loop;         
      end loop;
      return True;
   end;
   
   
end Map_Package;
