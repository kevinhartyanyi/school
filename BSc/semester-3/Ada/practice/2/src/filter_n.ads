generic
   Size: Positive;
   type Item is private;
   type Index is (<>);
   type Item_Array is array (Index range <>) of Item;
   with function Condition(I: in Item) return Boolean;
procedure filter_n(InT: in Item_Array;OutT: out Item_Array; n: in out Natural);
