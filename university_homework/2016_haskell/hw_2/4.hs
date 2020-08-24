import Test.HUnit

notFound = -1
pos :: (Eq a, Num a) => a -> [a] -> Int
pos _ [] = notFound
pos n (x:xs) = if x == n
    then 0
    else let posInTail = pos n xs in
        if posInTail == notFound
            then notFound
            else 1 + posInTail

main = runTestTT tests
tests = test [
    "empty" ~: notFound ~=? pos 0 [],
    "single present" ~: 0 ~=? pos 1.2 [1.2],
    "single absent" ~: notFound ~=? pos 3 [-3],
    "middle" ~: 1 ~=? pos 2 [1, 2, 1, 2],
    "last" ~: 3 ~=? pos 5 [1, 3, 2, 5],
    "final test" ~: 10000 ~=? pos 10000 [0..10000]]

