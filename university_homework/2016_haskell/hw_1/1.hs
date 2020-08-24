import Test.HUnit

factorial :: Integer -> Integer
factorial n
    | n < 0 = error "Negative argument" 
    | n < 2 = 1
    | otherwise = n * factorial (n - 1)

main = runTestTT tests

tests = test ["0!" ~: 1 ~=? factorial 0,
              "1!" ~: 1 ~=? factorial 1,
              "2!" ~: 2 ~=? factorial 2,
              "15!" ~: 1307674368000 ~=? factorial 15]

