with Ada.Numerics.Discrete_Random, Ada.Text_IO;
procedure Main is

   K: Integer := 10;

   subtype Interval is Integer range 1..K;
   package MyRandom is new Ada.Numerics.Discrete_Random(Interval);

   protected Own is
      procedure Write(I:in String);
      procedure Random(R: out Integer);
   private
      procedure Initialize;
      G: MyRandom.Generator;
      Init: Boolean := False;
   end Own;

   protected body Own is
      procedure Write(I:in String) is
      begin
         Ada.Text_IO.Put_Line(I);
      end;

      procedure Initialize is
      begin
         MyRandom.Reset(G);
         Init := True;
      end;


      procedure Random(R: out Integer) is
      begin
         if Init /= True then
            Initialize;
         end if;
         R := MyRandom.Random(G);
      end;
   end Own;


    task Kertesz is
      entry Jump(P: in Integer; B: out Boolean);
      entry Death;
   end Kertesz;

   task type Saska is
   end Saska;

   task body Saska is
      Alive: Boolean := True;
      Parcella: Integer;
      P:Boolean := False;
   begin
      Own.Random(Parcella);
      Own.Write("Saska in " & Parcella'Image);
      while Alive loop

         delay 0.5;
         Own.Random(Parcella);
         Own.Write("Saska in " & Parcella'Image);
         Kertesz.Jump(Parcella, P);
         if P then
            Alive := False;
         end if;

      end loop;
      Own.Write("Saska Death");
      Kertesz.Death;
   end;

   type Saska_Access is access Saska;



   task body Kertesz is
      type Bool_Array is array (Integer range 1..K) of Boolean;
      Parcell: Bool_Array;
      Saska_Alive: Boolean := True;
      Attack: Integer := 1;
   begin
      for I in Parcell'Range loop
         Parcell(I) := False;
      end loop;
      while Saska_Alive loop
         select
            accept Jump(P: in Integer; B: out Boolean) do
               B := Parcell(P);
            end Jump;
         or
            accept Death do
               Saska_Alive := False;
            end Death;
         or
            delay 1.0;
            Parcell(Attack) := False;
            Own.Random(Attack);
            Own.Write("Attack " & Attack'Image);
            Parcell(Attack) := True;
         end select;
      end loop;
      Own.Write("Kertesz Win");
   end;

   S: Saska_Access;
begin
   S := new Saska;

end Main;

--task type Semafor( Max: Positive ) is
  --    entry P;
    --  entry V;
  --end Semafor;

--task body Semafor is
--     Inside: Natural := 0;
--  begin
--     loop
--        select
--           when Inside < Max => accept P; Inside := Inside + 1;
--	or
--	   accept V; Inside := Inside - 1;
--	or
--	   terminate;
--	end select;
--     end loop;
--  end Semafor;

--bt: Duration := 2.0;
--delay bt;
--bt := 2*bt;

