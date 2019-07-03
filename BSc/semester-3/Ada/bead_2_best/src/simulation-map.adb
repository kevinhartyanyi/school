separate (simulation)

protected body Map is
   procedure Init(Imp: Base_Access; Reb: Base_Access) is
      ImperialID: Integer := 1;
      RebelID: Integer := -1;
   begin
      for I in 1..Max loop
         for J in 1..Max loop
            if J <= (Max/2) then
               M.Ships(I,J) := new Ship(ImperialID, Imp);  
               ImperialID := ImperialID + 1;
            else
               M.Ships(I,J) := new Ship(RebelID, Reb);
               RebelID := RebelID - 1;
            end if;
            M.Stats(I,J) := True;            
         end loop;
      end loop;
      Imp.Send_Out_Ships(((Max*Max)/2));
      Reb.Send_Out_Ships(((Max*Max)/2));
      M.Ships(0,0) := new Ship(0, Imp);
      
      Printer.Out_Text("Map Init");
      --Ada.Text_IO.Put_Line("Map Init");
      Printer.Out_Map(M);   
      
      
   end;   
   
   procedure End_Fight is
      AgentP: Agent_Access;
   begin
      Printer.Out_Text("End Fight");
      --Ada.Text_IO.Put_Line("End Fight");
      for I in 1..Max loop
         for J in 1..Max loop
            AgentP := new Agent(M.Ships(I,J));        
         end loop;
      end loop;
      AgentP := new Agent(M.Ships(0,0));
   end;
   
   function Get_Map return Matrix is
   begin
      return M;
   end;
   
   function Get_Status(C: Cord) return Boolean is
   begin
      return M.Stats(C.X, C.Y);
   end;
   
   procedure Lost_Ship(C: Cord) is 
   begin
      M.Stats(C.X, C.Y) := False;
      M.Ships(C.X, C.Y).Hit;
      Printer.Out_Map(M);
   end;
end Map;
