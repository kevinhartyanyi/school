with Ada.Text_IO;

generic
   type Index is (<>);
   type Counter is (<>);

package Bag_Package is
   type Bag is private;
   procedure Empty(B: in out Bag);
   procedure Add(B: in out Bag; I:Index);
   procedure Remove(B: in out Bag; I:Index);
   function Has_Any (B:Bag; I:Index) return Boolean;

   procedure write(B: Bag);

private
   type T is array (Index range <>) of Counter;
   type Bag is record
      MT: T(Index'Range);
      end record;

end Bag_Package;
