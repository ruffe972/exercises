import Test.QuickCheck

func' x l = map (\y -> y*x) l
--func x = map (\y -> y*x)
--func x = map (*x)
func = map . (*)

main = quickCheck((\x l -> func' x l == func x l) :: Int -> [Int] -> Bool)
