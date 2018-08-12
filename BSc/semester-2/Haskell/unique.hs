{-
Írjunk egy unique :: Eq a => [a] -> [a] függvényt,
ami eltûnteti az összes ismételt elemet az input listából.
 Az output lista ugyanolyan sorrendben tartalmazza az elemeket, mint az input.
 Az elsõ elõfordulását tartsuk meg minden ismétlõdõ elemnek.
 Az implementációban használhatjuk az == mûveletet (az Eq a => miatt).
Példák a mûködésre:
unique "Mississippi"      == "Misp"
unique []                 == []
unique [0]                == [0]
unique [0, 0, 0, 1, 1, 1] == [0, 1]
unique [0, 1, 1, 0]       == [0, 1]
-}

unique :: Eq a => [a] -> [a]
unique [] = []
unique [n] = [n] 
unique n | last n `elem` u = u
         | otherwise = u ++ [last n] 
		 where u = unique (init n)
		 
