// lang::CwC

#include "map.h"
#include "object.h"
#include "string.h"
#include "helper.h"
#include <assert.h>

void test_get()
{
  ObjectObjectMap *ooMap = new ObjectObjectMap();
  StringObjectMap *soMap = new StringObjectMap();
  StringStringMap *ssMap = new StringStringMap();

  Object *Okey = new Object();
  Object *Oval = new Object();
  String *Skey = new String("Hello");
  String *Sval = new String("World");

  ooMap->add(Okey, Oval);
  soMap->add(Skey, Oval);
  ssMap->add(Skey, Sval);

  Object *o1 = ooMap->get(Okey);
  Object *o2 = soMap->get(Skey);
  String *s1 = ssMap->get(Skey);

  assert(o1->equals(Oval));
  assert(o2->equals(Oval));
  assert(s1->equals(Sval));

  String *wrongKey = new String("Goodbye");
  Object *wrongObj = new Object();

  Object *result1 = ooMap->get(wrongObj);
  Object *result2 = soMap->get(wrongKey);
  Object *result3 = ssMap->get(wrongKey);

  assert(result1 == nullptr);
  assert(result2 == nullptr);
  assert(result3 == nullptr);
}

void test_remove()
{
  ObjectObjectMap *ooMap = new ObjectObjectMap();
  StringObjectMap *soMap = new StringObjectMap();
  StringStringMap *ssMap = new StringStringMap();

  Object *Okey = new Object();
  Object *Oval = new Object();
  String *Skey = new String("Hello");
  String *Sval = new String("World");

  ooMap->add(Okey, Oval);
  soMap->add(Skey, Oval);
  ssMap->add(Skey, Sval);

  ooMap->remove(Okey);
  soMap->remove(Skey);
  ssMap->remove(Skey);

  assert(ooMap->size() == 0);
  assert(soMap->size() == 0);
  assert(ssMap->size() == 0);
}

void test_has()
{
  ObjectObjectMap *ooMap = new ObjectObjectMap();
  StringObjectMap *soMap = new StringObjectMap();
  StringStringMap *ssMap = new StringStringMap();

  Object *Okey = new Object();
  Object *Oval = new Object();
  String *Skey = new String("Hello");
  String *Sval = new String("World");

  ooMap->add(Okey, Oval);
  soMap->add(Skey, Oval);
  ssMap->add(Skey, Sval);

  assert(ooMap->has(Okey));
  assert(soMap->has(Skey));
  assert(ssMap->has(Skey));

  Object *wrongObj = new Object();
  String *wrongKey = new String("Goodbye");
  assert(!ooMap->has(wrongObj));
  assert(!soMap->has(wrongKey));
  assert(!ssMap->has(wrongKey));
}

void test_clear()
{
  ObjectObjectMap *ooMap = new ObjectObjectMap();
  StringObjectMap *soMap = new StringObjectMap();
  StringStringMap *ssMap = new StringStringMap();

  String *Skey = new String("Hello");
  String *Sval = new String("World");
  String *Skey2 = new String("Design");
  String *Sval2 = new String("Recipe");
  Object *Okey = new Object();
  Object *Oval = new Object();
  Object *Okey2 = new Object();
  Object *Oval2 = new Object();

  ooMap->add(Okey, Oval);
  ooMap->add(Okey2, Oval2);
  soMap->add(Skey, Oval);
  soMap->add(Skey2, Oval2);
  ssMap->add(Skey, Sval);
  ssMap->add(Skey2, Sval2);

  ooMap->clear();
  soMap->clear();
  ssMap->clear();

  Object *r1 = ooMap->get(Okey);
  Object *r2 = ooMap->get(Okey2);
  Object *r3 = soMap->get(Skey);
  Object *r4 = soMap->get(Skey2);
  String *r5 = ssMap->get(Skey);
  String *r6 = ssMap->get(Skey2);

  // successfully clears all entries
  assert(r1 == nullptr);
  assert(r2 == nullptr);
  assert(r3 == nullptr);
  assert(r4 == nullptr);
  assert(r5 == nullptr);
  assert(r6 == nullptr);
}

void test_size()
{
  ObjectObjectMap *ooMap = new ObjectObjectMap();
  StringObjectMap *soMap = new StringObjectMap();
  StringStringMap *ssMap = new StringStringMap();

  assert(ooMap->size() == 0);
  assert(soMap->size() == 0);
  assert(ssMap->size() == 0);

  String *Skey = new String("Hello");
  String *Sval = new String("World");
  Object *Okey = new Object();
  Object *Oval = new Object();

  ooMap->add(Okey, Oval);
  soMap->add(Skey, Oval);
  ssMap->add(Skey, Sval);

  assert(ooMap->size() == 1);
  assert(soMap->size() == 1);
  assert(ssMap->size() == 1);

  ooMap->remove(Okey);
  soMap->remove(Skey);
  ssMap->remove(Skey);

  assert(ooMap->size() == 0);
  assert(soMap->size() == 0);
  assert(ssMap->size() == 0);
}

void test_keys()
{
  ObjectObjectMap *ooMap = new ObjectObjectMap();
  StringObjectMap *soMap = new StringObjectMap();
  StringStringMap *ssMap = new StringStringMap();

  String *Skey = new String("Hello");
  String *Sval = new String("World");
  String *Skey2 = new String("Design");
  String *Sval2 = new String("Recipe");
  Object *Okey = new Object();
  Object *Oval = new Object();
  Object *Okey2 = new Object();
  Object *Oval2 = new Object();

  ooMap->add(Okey, Oval);
  ooMap->add(Okey2, Oval2);
  soMap->add(Skey, Oval);
  soMap->add(Skey2, Oval2);
  ssMap->add(Skey, Sval);
  ssMap->add(Skey2, Sval2);

  Object **ookeys = new Object *[2];
  String **sokeys = new String *[2];
  String **sskeys = new String *[2];

  ooMap->keys(ookeys);
  soMap->keys(sokeys);
  ssMap->keys(sskeys);

  // the keys array contains both keys in the map, in either order
  assert(ookeys[0] == Okey && ookeys[1] == Okey2);
  assert(sokeys[0] == Skey && sokeys[1] == Skey2);
  assert(sskeys[0] == Skey && sskeys[1] == Skey2);
}

// make sure setting a key which was already in the map behaves properly
void test_overwrite()
{
  ObjectObjectMap *ooMap = new ObjectObjectMap();
  StringObjectMap *soMap = new StringObjectMap();
  StringStringMap *ssMap = new StringStringMap();

  String *Skey = new String("Hello");
  String *Sval = new String("World");
  Object *Okey = new Object();
  Object *Oval = new Object();

  ooMap->add(Okey, Oval);
  soMap->add(Skey, Oval);
  ssMap->add(Skey, Sval);

  Object *o1 = ooMap->get(Okey);
  Object *o2 = soMap->get(Skey);
  String *s1 = ssMap->get(Skey);

  assert(o1->equals(Oval));
  assert(o2->equals(Oval));
  assert(s1->equals(Sval));

  String *Sval2 = new String("Darkness");
  Object *Oval2 = new Object();

  ooMap->set(Okey, Oval2);
  soMap->set(Skey, Oval2);
  ssMap->set(Skey, Sval2);

  o1 = ooMap->get(Okey);
  o2 = soMap->get(Skey);
  s1 = ssMap->get(Skey);

  // the map successfully overwrites values
  assert(o1->equals(Oval2));
  assert(o2->equals(Oval2));
  assert(s1->equals(Sval2));
  // the map does not delete the old value
  assert(ooMap->has(Okey));
  assert(soMap->has(Skey));
  assert(ssMap->has(Skey));
}

int main()
{
  test_get();
  test_remove();
  test_has();
  test_clear();
  test_size();
  test_keys();
  test_overwrite();
  return 0;
}
