palindrome :: String -> Bool
palindrome [] = True
palindrome [word] = True
palindrome word  | head word == last word = palindrome (tail (init word))
                 | otherwise = False

countStairs :: Int -> Int
countStairs 0 = 0
countStairs 1 = 1
countStairs 2 = 2
countStairs 3 = 4
countStairs x = countStairs (x - 1) + countStairs (x - 2) + countStairs (x - 3)
