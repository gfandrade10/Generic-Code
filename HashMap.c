#include <stddef.h>
#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MEMBLOCK_ (30 * sizeof(char) + sizeof(int))
#define INIT_SIZE_ 10

typedef struct hashmap_ {
    void* data;
    int capacity;
    int elements;
} HashMap;

HashMap* CreateMap() 
{
    HashMap* map = (HashMap*)malloc(sizeof(HashMap));
    map->data = malloc(MEMBLOCK_ * INIT_SIZE_);
    map->capacity = INIT_SIZE_;
    map->elements = 0;
    return map;
}

void InitializeMap (HashMap* map)
{
    if(map->capacity <= 0)
        return;

    for(int i = 0; i < map->capacity; i ++)
    {
        memset((char*)map->data + i*MEMBLOCK_, '\0', MEMBLOCK_ - sizeof(int));
        *(int*)((char*)map->data + i*MEMBLOCK_ + MEMBLOCK_ - sizeof(int)) = 0;
    }
}

void FreeHashMap(HashMap* map)
{
    if(map)
    {
        if(map->data)
            free(map->data);
        free(map);
    }
}

void AddElement(HashMap* map, char* tag)
{
    for(int i = 0; i < map->elements; i++)
    {
        if(strcmp((char*)map->data + i * MEMBLOCK_, tag) == 0)
        {
            *(int*)((char*)map->data + i * MEMBLOCK_ + MEMBLOCK_ - sizeof(int)) += 1;
            return;
        }
    }

    if(map->elements == map->capacity)
    {
        map->data = realloc(map->data, map->capacity + INIT_SIZE_ * MEMBLOCK_);
        if(!map->data)
            return;
    }

    strncpy((char*)map->data + map->elements * MEMBLOCK_, tag, MEMBLOCK_ - sizeof(int) - 1);
    *(int*)((char*)map->data + map->elements * MEMBLOCK_ + MEMBLOCK_ - sizeof(int)) = 1;
    map->elements++;
}

int GetHashCount(HashMap* map, char* key)
{
    if(!map || !map->elements || strlen(key) == 0)
        return 0;

    for(int i = 0; i < map->elements; i++)
    {
        if(strcmp((char*)map->data + i * MEMBLOCK_, key) == 0)
            return *(int*)((char*)map->data + i * MEMBLOCK_ + MEMBLOCK_ - sizeof(int));
    }
    return 0;
}

void PrintMap(HashMap* Map)
{
    if(!Map->elements)
        return;

    for(size_t i = 0; i < Map->elements; i++)
        printf("{%s, %d}\n", (char*)Map->data + MEMBLOCK_ * i, 
            *(int*)((char*)Map->data + MEMBLOCK_ * i + MEMBLOCK_ - sizeof(int)));
    
    printf("\n");
}

int main()
{
    HashMap* MyMap = CreateMap();
    InitializeMap(MyMap);
    AddElement(MyMap, (char*)"Guiiiiii");
    AddElement(MyMap, (char*)"Guiiiiii");
    AddElement(MyMap, (char*)"Pit");
    AddElement(MyMap, (char*)"Bela");
    AddElement(MyMap, (char*)"Dulcinha");
    int val = GetHashCount(MyMap, (char*)"Pit");
    printf("%d\n", val);
    PrintMap(MyMap);
    FreeHashMap(MyMap);
}

