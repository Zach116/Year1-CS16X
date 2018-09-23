last' :: [Int] -> Int
last' [x] = x
last' (x:xs) = last xs

reverse' :: [Int] -> [Int]
reverse' [] = []
reverse' (x:xs) = (reverse' xs) ++ [x]

find' :: Int -> [Int] -> Bool
find' x []                 = False
find' x (y:ys) | x==y      = True
               | otherwise = find' x ys

