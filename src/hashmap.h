#ifndef HASHMAP_H
#define HASHMAP_H

#include <stdint.h>

typedef uint32_t uint32;

typedef struct hashmap
{
    const char** keys;
    const char** values;
    uint32 allocations;
    uint32 maxSize;
} hashmap;

// Creates a hashmap with the number of keys equal to "size".
hashmap HashmapCreate(uint32 size);
// Destroys a hashmap, freeing its memory. The map should not be used after calling this function.
void HashmapDestroy(hashmap* map);

// Adds the given "key" and "value" pair to "map" if there is room and the key does not already exist.
// Returns 1 if success and 0 if failure.
int HashmapAdd(hashmap* map, const char* key, const char* value);
// Removes the "key" and its associated value from "map". Returns 1 if success and 0 if no matching key was found.
int HashmapRemove(hashmap* map, const char* key);

// Returns the associated value for the given "key" in "map". If none exists, returns "".
const char* HashmapFind(const hashmap* map, const char* key);
// Returns 1 if the "key" is found in the "map". Otherwise, returns 0.
int HashmapHasKey(const hashmap* map, const char* key);
// Prints all key value pairs present in "map".
void HashmapPrint(const hashmap* map);

#endif