import Test.HUnit

fibonacci :: Integer -> Integer
fibonacci n
    | n < 0 = error "Negative argument" 
    | n < 2 = n
    | otherwise = fibonacci (n - 1) + fibonacci (n - 2)

main = runTestTT tests

tests = test ["0th" ~: 0 ~=? fibonacci 0,
              "1st" ~: 1 ~=? fibonacci 1,
              "2nd" ~: 1 ~=? fibonacci 2,
              "9th" ~: 34 ~=? fibonacci 9]

