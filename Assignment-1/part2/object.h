//lang::CwC

#pragma once

#include <stdio.h>

/**
 * @brief Object class. Represents an abstract datatype that can be created by any developer.
 * 
 * Any new datatype that a developer would like to implement can have this class as a parent class, so that all their
 * datatypes can have a unified set of functions and a unified type.
 * 
 * @note Included functions inspired by the methods described in the interface for the Java 8 Object class:
 * https://docs.oracle.com/javase/8/docs/api/java/lang/Object.html
 */
class Object
{
     /**
     * @brief Copies this Object by initializing a new Object with the information from this Object
     * 
     * @return Object* a copy of this Object
     */
     virtual Object *clone() {}

     /**
     * @brief Compares shallow equality between this Object and another Object
     * 
     * @param other the Object to be compared to this Object for equality
     * @return true if the two Objects are equal, i.e. have the same hashcode
     * @return false if the two Objects are not equal, i.e. have different hashcodes
     */
     virtual bool equals(Object *other) {}

     /**
     * @brief Calls the hash_me() helper function, caches its result, and returns it
     * 
     * @return size_t the hashcode for this object
     */
     size_t hash() {}

     /**
     * @brief Calculates the hashcode for this object
     * 
     * @return size_t the hashcode for this object
     */
     virtual size_t hash_me() {}

     /**
     * @brief Returns a char array representation of the information contained in this object, so that 
     * it can be printed
     * 
     * @return const char* the char array representation of this object
     */
     virtual const char *print() {}
};