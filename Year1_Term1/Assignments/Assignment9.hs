swapPass :: [Int] -> [Int]
swapPass [x] = [x]
swapPass (x:y:xs) | x > y = y : swapPass (x:xs)
	          | otherwise =  x : swapPass (y:xs)

loopOverAll :: [Int] -> Int -> [Int]
loopOverAll xs numberOfElements | numberOfElements == (length xs) = xs
			        | otherwise = loopOverAll (swapPass xs) (numberOfElements + 1)

bubbleSort :: [Int] -> [Int]
bubbleSort [] = []
bubbleSort xs = loopOverAll xs 0
