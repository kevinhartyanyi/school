import System.IO
import Control.Monad
import Data.List
import Data.Foldable


answer a n c x | sum a < c = putStrLn "IMPOSSIBLE"
               | otherwise =  traverse_  print (f c (sort a) ((realToFrac(c))/(realToFrac(n))))

f 0 _ _= []
f c [x] a = c : []
f c (x:xs) a |c-x > 0 && r <= a || x <= h = x : f (c-x) xs a             
             |h < (avg xs)  = h : f (c-h) xs a
             |otherwise = c : f (c-x) xs a
			  where r = realToFrac(x)
			        h = c `div` (1+length xs)
           
avg x = sum x `div` genericLength x
   
main :: IO ()
main = do
    hSetBuffering stdout NoBuffering
    
    input_line <- getLine
    let n = read input_line :: Int
    input_line <- getLine
    let c = read input_line :: Int
    
    a<-replicateM n $ do
        input_line <- getLine
        let b = read input_line :: Int
        return (b)
    
    answer a n c (sort a)
        
    return ()