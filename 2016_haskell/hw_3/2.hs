import Test.HUnit

infL :: [Integer]
infL = concat matrix where
    digits = [1,7,9]
    matrix = digits : (zipWith upgrade [1..] matrix) where
        --upgrade 1 [1,7,9] = [11,17..99]
        --upgrade 2 [11..99] = [111,117..999]
        upgrade digNum level = concat [map (10 ^ digNum * digit +) level | digit <- digits]

main = runTestTT tests
tests = test ["badTest" ~: snippet ~=? take (length snippet) infL] where
    snippet = [1,7,9, 11,17,19,71,77,79,91,97,99, 111,117]

