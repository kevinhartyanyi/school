{-
�rjunk egy unique :: Eq a => [a] -> [a] f�ggv�nyt,
ami elt�nteti az �sszes ism�telt elemet az input list�b�l.
 Az output lista ugyanolyan sorrendben tartalmazza az elemeket, mint az input.
 Az els� el�fordul�s�t tartsuk meg minden ism�tl�d� elemnek.
 Az implement�ci�ban haszn�lhatjuk az == m�veletet (az Eq a => miatt).
P�ld�k a m�k�d�sre:
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
		 
