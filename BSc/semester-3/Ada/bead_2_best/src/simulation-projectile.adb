separate (simulation)

task body Projectile is 
   C: Cord;
begin
   Safe_Random.Get_Random(C);
   if Side = Imperial and then C.Y > 5 and then Map.Get_Status(C) then
      Map.Lost_Ship(C);
   elsif(Side = Rebel and C.Y <= 5) and then Map.Get_Status(C) then
      Map.Lost_Ship(C);
   end if;   
end Projectile;
