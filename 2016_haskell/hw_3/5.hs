import Test.HUnit

bracketSeqIsGood :: String -> Bool
bracketSeqIsGood = helper 0 where
    helper balance ('(':xs) = helper (balance + 1) xs
    helper balance (')':xs) = if balance == 0
        then False
        else helper (balance - 1) xs
    helper balance (_:xs) = helper balance xs
    helper balance "" = balance == 0

main = runTestTT tests
tests = let br = bracketSeqIsGood in test [
    "empty" ~: True ~=? br "",
    "no brackets" ~: True ~=? br "gdfg341",
    "single" ~: False ~=? br "(",
    "pair good" ~: True ~=? br "()",
    "pair bad 1" ~: False ~=? br "((",
    "pair bad 2" ~: False ~=? br "))",
    "pair bad 3" ~: False ~=? br ")(",
    "good" ~: True ~=? br "((e(wee)(w))()rtn()(123()))()",
    "bad" ~: False ~=? br "((()())(1)()(()12)((123)",
    "infinite 1" ~: False ~=? br (replicate 1000 '(' ++ repeat ')'),
    "infinite 2" ~: False ~=? br (')' : cycle "(wow)")]
