#include <stdio.h>

#include "hashmap.h"

int main(void)
{
    hashmap map = HashmapCreate(2);
    HashmapAdd(&map, "car", "forester");
    HashmapAdd(&map, "car2", "civic");
    HashmapPrint(&map);
    HashmapRemove(&map, "car");
    HashmapPrint(&map);
    HashmapDestroy(&map);
    return 0;
}