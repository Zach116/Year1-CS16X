module Date where

daysInWeek :: Int
daysInWeek = 7

daysInMonth :: Int -> Int
daysInMonth m = daysInWeek * 4 * m

minutes :: Int -> Int
minutes d = 24 * 60 * d
