import Test.HUnit

powers :: Int -> [Integer]
powers n
    | n < 0 = error "Negative argument"
powers 0 = []
powers 1 = [2]
powers n = let less = powers (n - 1) in head less * 2 : less

main = runTestTT tests
tests = test ["empty" ~: [] ~=? powers 0,
              "1" ~: [2] ~=? powers 1,
              "4" ~: [16, 8, 4, 2] ~=? powers 4,
              "final" ~: 1099511627776 ~=? head (powers 40)]

