add :: Int -> Int -> Int
add a b = a + b

sub :: Int -> Int -> Int
sub a b = a - b

mult :: Int -> Int -> Int
mult a b = a * b

square :: Int -> Int
square a = a * a

f1 :: Int -> Int -> Int 
f1 a b = sub (add a b) 5

f2 :: Int -> Int -> Int
f2 a b = add (sub 0 a) b

f3 :: Int -> Int
f3 a = mult (sub 0 a) (sub 0 a)

f4 :: Int -> Int -> Int
f4 a b = add (f3 a) b

f5 :: Int -> Int
f5 a = add (add (mult 2 (mult a a)) (mult 3 a)) 5

f6 :: Int -> Int
f6 a = mult (mult a a) (mult a a)
