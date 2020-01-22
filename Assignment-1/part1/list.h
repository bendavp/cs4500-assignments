//lang::CwC

#pragma once

#include "helper.h"
#include "string.h"

class StrList : public Object
{
public:
    String **list_;

    // the number of elements in the list (different from the max index)
    size_t size_;

    StrList() : Object()
    {
        size_ = 0;

        list_ = new String *[size_];
    }

    ~StrList()
    {
        delete[] list_;
    }

    // checks if a given index exists in this list
    // if it doesn't, prints an error message to the user and terminates the program with exit code 1
    void checkIfOutOfBounds(size_t index)
    {
        if (index < 0 || index > size_)
        {
            println("Index out of bounds! Remember, the index range of a list is from 0 through (and including) one less than the size of the list.");
            exit(1);
        }
    }

    // appends e to end of the list
    virtual void push_back(String *e)
    {
        // first, store the contents of the current list in another variable
        String **old_list_ = new String *[size_];
        for (int i = 0; i < size_; i++)
        {
            old_list_[i] = list_[i];
        }

        // next, set the current list to a new list of the new size, plus 1 for the new element
        list_ = new String *[size_ + 1];

        // then populate the new list with the contents of the old list
        for (int i = 0; i < size_; i++)
        {
            list_[i] = old_list_[i];
        }

        // finally, add the new element to the end of the new list
        list_[size_] = e;

        // delete the old list
        delete[] old_list_;

        // increment the size of the current list
        size_ += 1;
    }

    // insert element e at index i
    virtual void add(size_t i, String *e)
    {
        // before doing anything, check that the given index is in bounds
        checkIfOutOfBounds(i);

        // first, store the contents of the current list in another variable
        String **old_list_ = new String *[size_];
        for (int j = 0; j < size_; j++)
        {
            old_list_[j] = list_[j];
        }

        // next, set the current list to a new list of the new size, plus 1 for the new element
        list_ = new String *[size_ + 1];

        // then populate the new list with the contents of the old list, until you get to the specified index
        for (int j = 0; j < i; j++)
        {
            list_[j] = old_list_[j];
        }

        // put the new element at the appropriate index
        list_[i] = e;

        // continue populating the current list with the old list
        for (int j = i + 1; j < size_ + 1; j++)
        {
            list_[j] = old_list_[j - 1];
        }

        // delete the old list
        delete[] old_list_;

        // incremenet the size of the current list
        size_++;
    }

    // insert all elements in c into the current list at index i
    virtual void add_all(size_t i, StrList *c)
    {
        // before doing anything, check that the given index is in bounds
        checkIfOutOfBounds(i);

        size_t index = i;
        for (int j = 0; j < c->size(); j++)
        {
            add(index, c->get(index));
            index++;
        }
    }

    // removes all elements from this list
    void clear()
    {
        size_ = 0;
        list_ = new String *[size_ + 1];
    }

    // compares the given object o to this list for equality
    bool equals(Object *o)
    {
        StrList *other = dynamic_cast<StrList *>(o);
        if (other == nullptr)
        {
            return false;
        }
        else if (other->size() != size_)
        {
            return false;
        }
        for (int i = 0; i < size_; i++)
        {
            if (!list_[i]->equals(other->get(i)))
            {
                return false;
            }
        }
        return true;
    }

    // returns the element at index
    String *get(size_t index)
    {
        // before doing anything, check that the given index is in bounds
        checkIfOutOfBounds(index);

        // if so, return the element at the given index
        return list_[index];
    }

    // returns the hashcode for this object
    size_t hash_me()
    {
        size_t res = 0;
        for (int i = 0; i < size_; i++)
        {
            res += list_[i]->hash();
        }
        return res;
    }

    // returns the index of the first occurrence of o, or size_ + 1 if not there
    size_t indexOf(Object *o)
    {

        // first, check that the given object is a string
        String *other = dynamic_cast<String *>(o);

        // otherwise, return size_ + 1
        if (other == nullptr)
        {
            return size_ + 1;
        }

        // now, check to see if the given string matches any in the list,
        // and if it does, then return the index of the element which it matches
        for (int i = 0; i < size_ + 1; i++)
        {
            if (list_[i]->equals(other))
            {
                return i;
            }
        }

        return size_ + 1;
    }

    // removes the element of this list at index i and returns it
    String *remove(size_t i)
    {
        // before we do anything, check that the given index is in bounds
        checkIfOutOfBounds(i);

        // save the old element
        String *old = list_[i];

        // first, store the contents of the current list in another variable
        String **old_list_ = new String *[size_];
        for (int j = 0; j < size_; j++)
        {
            old_list_[j] = list_[j];
        }

        // next, set the current list to a new list of the new size, minus 1 for removing the old element
        list_ = new String *[size_ - 1];

        // then populate the new list with the contents of the old list, until the old element
        for (int j = 0; j < i; j++)
        {
            list_[j] = old_list_[j];
        }

        // then populate the new list with the rest of the contents of the old list
        for (int j = i + 1; j < size_ - 1; j++)
        {
            list_[j] = old_list_[j - 1];
        }

        // delete the old list
        delete[] old_list_;

        // return the old element
        return old;
    }

    // replaces the element of this list at index i with e and returns the old element
    virtual String *set(size_t i, String *e)
    {
        // before doing anything, check that the given index is in bounds
        checkIfOutOfBounds(i);

        // save the old element
        String *old = list_[i];

        // set the pointer at given index to new element
        list_[i] = e;

        // return the old element
        return old;
    }

    // returns the number of elements in the list
    size_t size()
    {
        return size_;
    }

    // returns what to print
    const char *print()
    {
        print_("[");
        for (int i = 0; i < size_; i++)
        {
            print_(list_[i]->str_);
            if (i != size_ - 1)
            {
                print_(", ");
            }
        }
        print_("]");
    }

    // checks if the current StrList is sorted alphabetically
    bool isSorted()
    {
        for (int i = 0; i < size_ - 1; i++)
        {
            if (!(list_[i]->compareTo(list_[i + 1]) == 1 || list_[i]->compareTo(list_[i + 1]) == 0))
            {
                return false;
            }
        }
        return true;
    }
};

// same as StrList, but holds the invariant that the list must be always be alphabetically sorted
class SortedStrList : public StrList
{
public:
    // appends e to the end of the list only if the list is still sorted afterwards
    // otherwise, terminates the program
    void push_back(String *e)
    {
        if (StrList::size_ == 0 || (StrList::list_[StrList::size_ - 1]->compareTo(e) == 1 || StrList::list_[StrList::size_ - 1]->compareTo(e) == 0))
        {
            StrList::push_back(e);
        }
        else
        {
            println("Can't add a string that comes alphabetically before the last string in the sorted list!");
            exit(1);
        }
    }

    // adds given string e at index i if alphabetically appropriate
    // otherwise, terminate the program
    void add(size_t i, String *e)
    {
        // before we do anything, check that the index is in bounds
        StrList::checkIfOutOfBounds(i);

        if (i != 0)
        {
            if (!(e->compareTo(StrList::list_[i - 1]) == -1 || e->compareTo(StrList::list_[i - 1]) == 0))
            {
                println("Can't add the given string at the given index, as this would leave the list unsorted!");
                exit(1);
            }
        }
        if (i != StrList::size_)
        {
            if (!(e->compareTo(StrList::list_[i]) == 1 || e->compareTo(StrList::list_[i]) == 0))
            {
                println("Can't add the given string at the given index, as this would leave the list unsorted!");
                exit(1);
            }
        }

        StrList::add(i, e);
    }

    // adds all elements of the given StrList into this SortedStrList at index i, under 3 conditions:
    // 1. The given StrList is sorted
    // 2. The first element of the given StrList comes alphabetically after the element at index i - 1
    // 3. The last element of the given StrList comes alphabetically before the element at index i
    // These conditions are the only way to ensure that the given StrList is added to the SortedStrList in the same order
    // given, at the given index, while still staying sorted.
    void add_all(size_t i, StrList *c)
    {
        // before doing anything, check that the given index is in bounds
        StrList::checkIfOutOfBounds(i);

        if (!c->isSorted())
        {
            println("The given StrList must be sorted to add it to a SortedStrList!");
            exit(1);
        }

        if (i != 0)
        {
            if (!(c->get(0)->compareTo(StrList::list_[i - 1]) == -1 || c->get(0)->compareTo(StrList::list_[i - 1]) == 0))
            {
                println("Can't add the given list at the given index, as this would leave the sorted list unsorted!");
                exit(1);
            }
        }
        if (i != StrList::size_)
        {
            if (!(c->get(c->size_ - 1)->compareTo(StrList::list_[i]) == 1 || c->get(c->size_ - 1)->compareTo(StrList::list_[i]) == 0))
            {
                println("Can't add the given list at the given index, as this would leave the sorted list unsorted!");
                exit(1);
            }
        }

        StrList::add_all(i, c);
    }

    // replaces the element of this list at index i with e and returns the old element
    // as long as it is alphabetically appropriate
    // otherwise, terminates the program
    String *set(size_t i, String *e)
    {
        // before we do anything, check that the given index is in bounds
        StrList::checkIfOutOfBounds(i);

        if (i != 0)
        {
            if (!(e->compareTo(StrList::list_[i - 1]) == -1 || e->compareTo(StrList::list_[i - 1]) == 0))
            {
                println("Can't add the given string at the given index, as this would leave the list unsorted!");
                exit(1);
            }
        }
        if (i != StrList::size_)
        {
            if (!(e->compareTo(StrList::list_[i + 1]) == 1 || e->compareTo(StrList::list_[i + 1]) == 0))
            {
                println("Can't add the given string at the given index, as this would leave the list unsorted!");
                exit(1);
            }
        }

        return StrList::set(i, e);
    }

    // adds the given string at the appropriate index alphabetically
    // returns the index at which the string was placed
    size_t sorted_add(String *e)
    {
        for (int i = 0; i < StrList::size_; i++)
        {
            if (e->compareTo(StrList::list_[i]) == 1 || e->compareTo(StrList::list_[i]) == 0)
            {
                StrList::add(i, e);
                return i;
            }
        }

        push_back(e);
        return StrList::size_ - 1;
    }
};