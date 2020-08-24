import Test.HUnit

data Tree a = Empty | Node a (Tree a) (Tree a)
leaf :: a -> Tree a
leaf x = Node x Empty Empty

height :: Tree a -> Int
height Empty = 0
height (Node _ l r) = 1 + max (height l) (height r)

minLeafDist :: Tree a -> Int
minLeafDist Empty = 0
minLeafDist (Node _ Empty Empty) = 0
minLeafDist (Node _ l Empty) = 1 + minLeafDist l
minLeafDist (Node _ Empty r) = 1 + minLeafDist r
minLeafDist (Node _ l r) = 1 + min (minLeafDist l) (minLeafDist r)

main = runTestTT tests
tests = test $ heightTestList ++ minLeafDistTestList where
    heightTestList = [
        "h empty" ~: 0 ~=? height Empty,
        "h root" ~: 1 ~=? height (leaf 0),
        "h stick" ~: 3 ~=? height stick,
        "h tree" ~: 4 ~=? height tree]
    minLeafDistTestList = [
        "m empty" ~: 0 ~=? minLeafDist Empty,
        "m root" ~: 0 ~=? minLeafDist (leaf "abc"),
        "m stick" ~: 2 ~=? minLeafDist stick,
        "m tree" ~: 1 ~=? minLeafDist tree]

    stick = Node
        1
        (Node
            2
            (leaf 3)
            Empty)
        Empty

    tree = Node
        1
        (leaf 2)
        (Node
            3
            (leaf 4)
            (Node
                5
                (leaf 6)
                Empty))

