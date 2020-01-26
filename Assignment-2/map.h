#pragma once

// lang::CwC

#include "object.h"
#include "string.h"

/**
 * A dictionary of string keys and object values.  All keys and values are owned
 * by the caller, and none of the map's methods will modify them.  Keys which
 * are .equals are equal, i.e. the map will never contain two keys which are
 * extensionally equivalent at the same time.
 */
class Map : public Object
{
public:
  virtual ~Map(){};

  /**
   * Returns the value which was set for this key.
   * Returns nullptr if not in map.
   */
  virtual Object *get(Object *key) = 0;

  /**
   * Set the value at the given key in this map.
   */
  virtual void set(Object *key, Object *value) = 0;

  /**
   * Remove the value at the given key in this map. No-op if value not in map.
   */
  virtual void remove(Object *key) = 0;

  /**
   * Determine if the given key is in this map.
   */
  virtual bool has(Object *key) = 0;

  /**
   * Remove all keys from this map.
   */
  virtual void clear() = 0;

  /**
   * Return the number of entries in this map.
   */
  virtual size_t size() = 0;

  /**
   * Store keys in the given array. Caller responsible for allocating at least
   * Map::size() elements.
   */
  virtual void keys(Object **dest) = 0;
};
