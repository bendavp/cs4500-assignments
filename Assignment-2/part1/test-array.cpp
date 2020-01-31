//lang:cwc

#include <stdio.h>
#include "object.h"
#include "string.h"
#include "array.h"

//will be called when a test fails
void fail()
{
    perror("Test failure: program terminating");
}

void pass()
{
    printf("Test passed!");
}

void checkTrue(bool b)
{
    if (!b)
        fail();
}

void checkFalse(bool b)
{
    if (b)
        fail();
}

void objectTest()
{
    Object *o1 = new Object();
    Object *o2 = o1;
    Object *o3 = new Object();

    //Objects o1 and o2 equal
    //if equal, then same hash
    checkTrue(o1->equals(o2));
    checkTrue(o1->hash() == o2->hash());

    checkFalse(o1->equals(o3));
    checkFalse(o1->hash() == o3->hash());

    checkFalse(o3->equals(o2));
    checkFalse(o3->hash() == o2->hash());
}

void stringTest()
{
    String *empty = new String();
    String *hello = new String("hello");
    String *world = new String("world");
    String *helloWorld = new String("helloworld");

    //should be "helloworld"
    //equals means they should also have same hashes
    String *catRes = hello->concat(world);
    checkTrue(catRes->equals(helloWorld));
    checkTrue(catRes->hash() == helloWorld->hash());
    checkFalse(catRes->hash() == hello->hash());

    //should be "hello"
    String *catWithEmpty = hello->concat(empty);
    checkTrue(catWithEmpty->equals(hello));
    checkFalse(catWithEmpty->equals(helloWorld));
    checkTrue(catWithEmpty->hash() == hello->hash());

    //comparing strings lexicographically
    checkTrue(hello->compareTo(world) < 0);
    checkTrue(hello->compareTo(empty) > 0);
    checkTrue(hello->compareTo(helloWorld) < 0);
    checkTrue(world->compareTo(empty) > 0);
    checkTrue(world->compareTo(world) == 0);
}

void arrayTest1()
{
    Object *o1 = new Object();
    Object *o2 = new Object();
    Object *o3 = new Object();

    Array *arr1 = new Array();

    //insert elements
    arr1->insertAtEnd(o1);
    arr1->insertAtEnd(o2);

    //inserting in-between o1 and o2
    arr1->insert(o3, 1);

    checkTrue(arr1->getSize() == 3);
    checkTrue(arr1->getElementAt(0)->equals(o1));
    checkTrue(arr1->getElementAt(1)->equals(o3));
    checkTrue(arr1->getElementAt(2)->equals(o2));

    //remove middle element and check return
    checkTrue(arr1->remove(1)->equals(o3));

    checkTrue(arr1->getSize() == 2);
    checkTrue(arr1->getElementAt(0)->equals(o1));
    checkTrue(arr1->getElementAt(1)->equals(o2));

    checkTrue(arr1->indexOf(o1) == 0);
    checkTrue(arr1->indexOf(o3) == -1);

    //Create new array
    Array *arr2 = new Array();
    Object *o4 = new Object();
    Object *o5 = new Object();

    arr2->insertAtEnd(o4);
    arr2->insert(o5, 0);

    checkTrue(arr2->getSize() == 2);
    checkTrue(arr2->getElementAt(0)->equals(o5));
    checkTrue(arr2->getElementAt(1)->equals(o4));

    //insert arr1 into arr2
    arr2->insertMultiple(arr1, 1);

    checkTrue(arr2->getSize() == 4);
    checkTrue(arr2->getElementAt(0)->equals(o5));
    checkTrue(arr2->getElementAt(1)->equals(o1));
    checkTrue(arr2->getElementAt(2)->equals(o2));
    checkTrue(arr2->getElementAt(3)->equals(o4));
}

void arrayTest2()
{
    Object *o1 = new Object();
    Object *o2 = new Object();
    Object *o3 = new Object();

    Array *arr1 = new Array();

    //insert elements into array
    arr1->insert(o2, 0);
    arr1->insert(o3, 0);

    //override element at index 0
    arr1->set(o1, 0);

    checkTrue(arr1->getSize() == 2);
    checkTrue(arr1->getElementAt(0)->equals(o1));
    checkTrue(arr1->getElementAt(1)->equals(o2));

    //clear array
    arr1->clear();

    //should no longer have elements
    checkTrue(arr1->getSize() == 0);
}

int main()
{
    objectTest();
    stringTest();
    arrayTest1();
    arrayTest2();
}