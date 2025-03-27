#include "associative_array.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

hashmap HashmapCreate(const uint32 size)
{
    hashmap newHash;
    newHash.allocations = 0; // How many spaces in the "keys" and "values"
                             // arrays have been used before.
    newHash.maxSize = size;  // Maximum number of unique keys and values.
    newHash.keys = (const char**)malloc(size * sizeof(const char*)); // INTERNAL
    newHash.values =
        (const char**)malloc(size * sizeof(const char*)); // INTERNAL
    return newHash;
}

void HashmapDestroy(hashmap* map)
{
    free(map->values);
    free(map->keys);
}

int HashmapAdd(hashmap* map, const char* key, const char* value)
{
    // Don't add values for duplicate keys
    if (HashmapHasKey(map, key)) return 0;

    if (map->allocations < map->maxSize)
    {
        const int index = map->allocations++;
        map->keys[index] = key;
        map->values[index] = value;
        return 1;
    }

    for (int i = 0; i < map->allocations; i++)
    {
        if (strcmp(map->keys[i], "") == 0)
        {
            map->keys[i] = key;
            map->values[i] = value;
            return 1;
        }
    }

    return 0;
}

const char* HashmapFind(const hashmap* map, const char* key)
{
    for (int i = 0; i < map->allocations; i++)
    {
        if (strcmp(map->keys[i], key) == 0)
        {
            return map->values[i];
        }
    }

    return "";
}

int HashmapHasKey(const hashmap* map, const char* key)
{
    for (int i = 0; i < map->allocations; i++)
    {
        if (strcmp(map->keys[i], key) == 0) return 1;
    }

    return 0;
}

void HashmapPrint(const hashmap* map)
{
    printf("Beginning of map of with %i allocations\n", map->allocations);
    for (int i = 0; i < map->allocations; i++)
    {
        const char* key = map->keys[i];
        // Don't print empty keys
        if (strcmp(key, "") == 0) continue;
        printf("Key: %s | Value: %s\n", key, map->values[i]);
    }
    printf("Ending of map with %i allocations\n\n", map->allocations);
}

int HashmapRemove(hashmap* map, const char* key)
{
    for (int i = 0; i < map->allocations; i++)
    {
        if (strcmp(map->keys[i], key) == 0)
        {
            map->keys[i] = "";
            map->values[i] = "";
            return 1;
        }
    }

    return 0;
}
