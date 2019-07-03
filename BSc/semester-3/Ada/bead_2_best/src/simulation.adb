with Ada.Numerics.Discrete_Random, Ada.Text_IO;
procedure Simulation is

   Max: Integer := 20;

   subtype Size is Integer range 1..Max;
   package Random_Int is new Ada.Numerics.Discrete_Random(Result_Subtype => Size);

   type Cord is record
      X: Integer;
      Y: Integer;
   end record;

   protected Safe_Random is
      procedure Get_Random(R: out Cord);
      procedure Initalise;
   private
      Ready: Boolean := False;
      G: Random_Int.Generator;
   end Safe_Random;

   protected body Safe_Random is separate;


   type Faction is (Rebel, Imperial);

   task type Base(Side: Faction) is
      entry Send_Out_Ships(I: Integer);
      --entry Get_Type(Side: in out Faction);
      entry Ship_Lost;
      entry Destroy;
   end Base;



   type Base_Access is access Base;


   task type Projectile(Side: Faction) is
   end Projectile;

   type P_Access is access Projectile;


   task type Ship(ID: Integer; Side: Base_Access) is
      entry Hit;
      entry Call_Back;
   end Ship;



   type Ship_Access is access Ship;
   type Ship_Array is array (0..Max, 0..Max) of Ship_Access;
   type Stats_Array is array (0..Max, 0..Max) of Boolean;

   type Matrix is record
      Ships: Ship_Array;
      Stats: Stats_Array;
   end record;

   protected Printer is
      procedure Out_Text(O: String);
      procedure Out_Map(O: in Matrix);
   end Printer;

   task body Ship is separate;



   task type Agent(Ship: Ship_Access);
   type Agent_Access is access Agent;

   protected Map is
      procedure Init(Imp: Base_Access; Reb: Base_Access);
      function Get_Map return Matrix;
      function Get_Status(C: Cord) return Boolean;
      procedure Lost_Ship(C: Cord);
      procedure End_Fight;
   private
      M:Matrix;
   end Map;

   task body Base is separate;

   protected body Map is separate;

   task body Agent is separate;

   task body Projectile is separate;

   protected body Printer is separate;





   Death_Star: Base_Access;
   Rebel_Base: Base_Access;
--   Rebel_Base:  Base(Rebel);
begin
   Death_Star := new Base(Imperial);
   Rebel_Base := new Base(Rebel);
   Map.Init(Death_Star, Rebel_Base);




end Simulation;
