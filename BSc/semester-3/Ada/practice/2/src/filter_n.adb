procedure filter_n(InT: in Item_Array;OutT: out Item_Array; n: in out Natural) is
   ind:Index := OutT'First;
   count:Natural := 0;
begin   
   n:=0;
   for I in InT'Range loop 
      if Condition(InT(I)) then
         OutT(ind) := InT(I);
         ind:= Index'Succ(ind);         
         n := n + 1;
      end if; 
      count := count + 1;
      exit when Size = count;
   end loop;
end;
