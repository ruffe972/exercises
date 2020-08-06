#include <i_comparable.h>


int IComparable::compareTo(IComparable *that) const
{
    if (len() < that->len())
        return less;
    if (len() > that->len())
        return more;
    return equal;
}
