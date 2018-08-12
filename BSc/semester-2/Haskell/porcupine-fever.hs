{-
You have a hobby of visiting a porcupine farm. Porcupines are kept in cages and regularly fed. They are usually healthy and have been one of the rodents with longest lifespans, but some of these porcupines are sick.

Every year, each porcupines who were sick last year will cause 2 healthy porcupines in the same cage to be sick, and then die.

Simulate to find the total amount of surviving porcupines after every year. Stop if all the porcupines are dead (do not repeat "0"s after the first time).
-}

import System.IO
import Control.Monad

answer 0 e x = return ()
answer y e x|sum [m!!e|m<-x] == 0 = print 0
            | otherwise = do
              print (sum [m!!e|m<-x])
              answer (y-1) (e+1) x					 

collect 0 y x = answer y 0 x
collect n y x = do
        input_line <- getLine
        let input = words input_line
        let s = read (input!!0) :: Int
        let h = read (input!!1) :: Int
        let a = read (input!!2) :: Int
	collect (n-1) y (cage y (f s h a) : x)
	return()

cage 0 _ = []		   
cage y (a,b,c) = c : cage (y-1) (f a b c)  

f s h a | h-s*2 >=0  = (s*2, (h-s*2), h)
        | h == 0 = (0,0,0)
        | otherwise = (h,0,h)

main :: IO ()
main = do
    hSetBuffering stdout NoBuffering
    
    input_line <- getLine
    let n = read input_line :: Int
    input_line <- getLine
    let y = read input_line :: Int
    
    collect n y []
    
    return ()