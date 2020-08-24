import Test.HUnit

digitSum :: Integer -> Int
digitSum x
    | x < 0 = digitSum (-x)
digitSum 0 = 0
digitSum x = fromIntegral x `mod` 10 + digitSum (x `div` 10)

main = runTestTT tests
tests = test [
    "zero" ~: 0 ~=? digitSum 0,
    "single digit" ~: 4 ~=? digitSum 4,
    "positive" ~: 25 ~=? digitSum 01234543210000,
    "negative" ~: 10 ~=? digitSum (-28)]

