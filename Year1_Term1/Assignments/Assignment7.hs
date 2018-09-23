addOne :: [Int] -> [Int]
addOne xs = map (+1) xs

rawGradeToLetter :: Float -> Char
rawGradeToLetter x   | x >= 90 = 'A'
		     | x >= 80 && x < 90 = 'B'
		     | x >= 70 && x < 80 = 'C'
		     | x >= 60 && x < 70 = 'D'
		     | x < 60 = 'F'

convertRawsToLetters :: [Float] -> [Char]
convertRawsToLetters xs = map rawGradeToLetter xs

ouncesToCups :: [Float] -> [Float]
ouncesToCups xs = map (*0.125) xs

glassOfWater :: [Float] -> [Float]
glassOfWater xs = map (/ 8) xs

hydrated :: Float -> String
hydrated x   | (x / 8) >= 8 = "Hydrated"
	     | otherwise = "Not hydrated"

waterNeeded :: Float -> Float
waterNeeded x = 8 - (x / 8)
