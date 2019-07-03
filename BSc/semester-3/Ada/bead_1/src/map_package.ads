generic
   type Field is (<>);
   type Warrior is private;
   with procedure Field_Action(F: in out Field; W: in out Warrior);
   Empty:Field;

package Map_Package is
   type Map(n:Positive) is private;
   
   procedure Init(M: in out Map);
   procedure Put(M: in Map);
   procedure Move(M: in out Map; W: in out Warrior);   
   function Is_Empty(M: Map) return Boolean;
   
   
private
   type matrix is array (Positive range <>, Positive range <>) of Field;
   type Cord is record
      x:Positive;
      y:Positive;
      end record;
   type Map(n:Positive) is record      
      Fields: matrix(1..n,1..n);
      Position: Cord;

      end record;
   

end Map_Package;
