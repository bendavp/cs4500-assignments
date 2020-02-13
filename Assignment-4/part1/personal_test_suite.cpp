#include "column.h"

void doesVaListActuallyWork()
{
    IntFastArray *i = new IntFastArray(5, 1, 2, 3, 4, 5);
    BoolFastArray *b = new BoolFastArray(2, true, false);
    FloatFastArray *f = new FloatFastArray(4, 4.20, 4.20, 4.20, 4.20);
    StringFastArray *s = new StringFastArray(2, "hello", "world");

    IntColumn *ic = new IntColumn(5, 1, 2, 3, 4, 5);
    // create for other types too

    assert(i->equals(ic->arr_));
    // create for other types too

    assert(i->get(0) == 1);
    assert(i->get(4) == 5);

    i->set(0, 420);
    i->set(4, 69);
    assert(i->get(0) == 420);
    assert(i->get(4) == 69);

    for (int j = 0; j < 512; j++)
    {
        // std::cout << "here" << '\n';
        i->push_back(j);
        // std::cout << "there" << '\n';
        assert(i->get(j + 5) == j);
        // std::cout << i->size() << '\n';
        // std::cout << j << '\n';
    }
}

int main()
{
    doesVaListActuallyWork();
    std::cout << "success" << '\n';
    return 0;
}