import Test.QuickCheck

reverse' :: [a] -> [a]
reverse' l = helper l []
    where helper [] newL = newL
          helper (old:oldT) new = helper oldT (old : new)

main = quickCheck ((\s -> reverse s == reverse' s) :: String -> Bool)

