import Test.HUnit

maxNeighborsIndex :: (Num a, Ord a) => [a] -> Int
maxNeighborsIndex all@(x1:x2:_) = helper (x1 + x2) 0 0 all where
    helper maxVal maxPos pos (x1:x2:xs) = helper newMaxVal newMaxPos (pos + 1) (x2 : xs) where
        (newMaxVal, newMaxPos) = if (x1 + x2) > maxVal
            then (x1 + x2, pos)
            else (maxVal, maxPos)
    helper _ maxPos _ _ = maxPos
maxNeighborsIndex _ = error "The list is too small"

main = runTestTT tests
tests = test [
    "pair" ~: 0 ~=? maxNeighborsIndex [-1,1],
    "triple 0" ~: 0 ~=? maxNeighborsIndex [1, 2, 1],
    "triple 1" ~: 1 ~=? maxNeighborsIndex [1, 2, 1.5],
    "long list" ~: 99 ~=? maxNeighborsIndex ([0..100] ++ [0..100]),
    "final test" ~: 3 ~=? maxNeighborsIndex [3,4,2,5,3,1,0,2,3,5]]
