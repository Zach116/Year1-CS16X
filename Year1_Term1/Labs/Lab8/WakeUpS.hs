type Minute = Int
type Hour = Int
type Time = (Hour,Minute)

timeToMinutes :: Time -> Minute
timeToMinutes (h,m) = h * 60 + m

minutesToTime :: Minute -> Time
minutesToTime m = (m `div` 60,m `mod` 60) 

validMinute :: Minute -> Bool
validMinute m | m >= 0 && m < 60 = True
              | otherwise = False
	   
validHour :: Hour -> Bool
validHour h | h >= 0 && h < 24 = True
            | otherwise = False
	    
validTime :: Time -> Bool
validTime (h,m) = (validHour h) && (validMinute m)

wakeUp :: Time -> Minute -> Time
wakeUp wakeTime duration = minutesToTime (timeToMinutes wakeTime - duration) 
