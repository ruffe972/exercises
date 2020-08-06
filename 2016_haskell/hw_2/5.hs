import Test.HUnit

isPal :: String -> Bool
isPal s = s == reverse s

main = runTestTT tests
tests = test [
    "empty" ~: True ~=? isPal "",
    "character" ~: True ~=? isPal "$",
    "short pal" ~: True ~=? isPal "=^_^=",
    "long pal:" ~: True ~=? isPal (['a'..'z'] ++ reverse ['a'..'z']),
    "not pal" ~: False ~=? isPal "123421"]

