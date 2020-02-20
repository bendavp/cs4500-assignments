#include "../dataframe.h"

int main()
{
    Schema scm("");                     // the schema
    DataFrame *df = new DataFrame(scm); // the data frame
    std::cout << "hello" << '\n';
    IntColumn *i_ = new IntColumn();
    for (size_t j = 0; j < 10; j++)
    {
        i_->push_back(j);
    }

    std::cout << "hello" << '\n';
    for (int i = 0; i < 10; i++)
    {
        df->add_column(i_, StrBuff().c(i).get());
    }
    std::cout << df->ncols() << " " << df->nrows() << '\n';
    std::cout << "hello" << '\n';
    AddAllInts rower_ = AddAllInts();
    df->map(rower_);

    //delete df;

    return (0);
}
