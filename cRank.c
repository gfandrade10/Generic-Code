#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define GRID_SIZE 20

typedef struct pair_impl_ { int ID; int pos; } pair_t;

typedef struct filtered_events_impl {
    int event_count;
    char** events_list;
    pair_t* runners;

    void (*get_event_count)(const char* events, struct filtered_events_impl* obj);
    void (*cleanup)(struct filtered_events_impl* obj);
    void (*erase_pos)(int pos, struct filtered_events_impl* obj);
    void (*update_position)(int pos, struct filtered_events_impl* obj);
    int  (*get_position)(int ID, struct filtered_events_impl* obj);
} filtered_events_t;

void get_event_count_impl_(const char* events, filtered_events_t* obj)
{
    int counter = 0;
    int len = (int)strlen(events);
    char copy[len+1];
    strcpy(copy, events);

    for(int i = 0; i < len; ++i)
    {
        if(events[i] == ' ') counter++;
    }
    
    counter++;
    obj->event_count = counter;
    obj->events_list = (char**)malloc(counter * sizeof(char*));

    char* p = strtok(copy, " ");
    int pos = 0;
    while(p != NULL)
    {
        int tmp = (int)strlen(p);
        obj->events_list[pos] = (char*)malloc((tmp + 1) * sizeof(char));
        snprintf(obj->events_list[pos], tmp + 1, "%s", p);
        pos++;
        p = strtok(NULL, " ");
    }

    obj->runners = (pair_t*)malloc(20 * sizeof(pair_t));
    for(int i = 0; i < GRID_SIZE; ++i)
        obj->runners[i] = (pair_t){i+1, i+1};
}

void cleanup_impl_(filtered_events_t* obj)
{
    for(int i = 0; i < obj->event_count; ++i)
    {
        free(obj->events_list[i]);
    }
    free(obj->events_list);
    free(obj->runners);
}

void erase_pos_impl_(int pos, filtered_events_t* obj)
{
    int current_pos = 0;
    for(int i = 0; i < GRID_SIZE; ++i)
    {
        if(obj->runners[i].ID == pos)
        {
            current_pos = obj->runners[i].pos;
            obj->runners[i].ID = 0;
            obj->runners[i].pos = 0;
            break;
        }
    }

    for(int i = 0; i < GRID_SIZE; ++i)
    {
        if(obj->runners[i].ID != 0)
        {
            if(obj->runners[i].pos > current_pos) 
                obj->runners[i].pos--;
        }
    }
}

void update_position_impl_(int pos, filtered_events_t* obj)
{
    pair_t* current_loc = NULL;
    pair_t* next_loc = NULL;
    int next_position = 0;

    for(int i = 0; i < GRID_SIZE; ++i)
    {
        if(obj->runners[i].ID == pos)
        {
            current_loc = &(obj->runners[i]);
            next_position = obj->runners[i].pos - 1;
            break;
        }
    }

    for(int i = 0; i < GRID_SIZE; ++i)
    {
        if(obj->runners[i].pos == next_position)
        {
            next_loc = &(obj->runners[i]);
            break;
        }
    }
    current_loc->pos--;
    next_loc->pos++;
}

int get_position_impl_(int ID, filtered_events_t* obj)
{
    for(int i = 0; i < GRID_SIZE; ++i)
    {
        if(obj->runners[i].ID == ID)
            return obj->runners[i].pos;
    }
    return -1;
}

#define START_EVENT_OBJ(OBJ) do {                   \
    OBJ.get_event_count = get_event_count_impl_;    \
    OBJ.erase_pos = erase_pos_impl_;                \
    OBJ.update_position = update_position_impl_;    \
    OBJ.cleanup = cleanup_impl_;                    \
    OBJ.get_position = get_position_impl_;          \
} while(0);

int champion_rank (int champion_ID, const char *events)
{
    //initial empty check
    if(strlen(events) == 0)
        return champion_ID;

    //object creation settings
    filtered_events_t events_obj;
    START_EVENT_OBJ(events_obj);

    //object startup
    events_obj.get_event_count(events, &events_obj);

    //operations
    printf("%i: ", champion_ID);
    for(int i = 0; i < events_obj.event_count; ++i)
    {
        printf("%s ", events_obj.events_list[i]);
        if(strcmp(events_obj.events_list[i], "I") == 0)
        {
            int temp = atoi(events_obj.events_list[i-1]);
            if(temp == champion_ID)
                return -1;
            
            events_obj.erase_pos(temp, &events_obj);
        }

        else if(strcmp(events_obj.events_list[i], "O") == 0)
        {
            int temp = atoi(events_obj.events_list[i-1]);
            events_obj.update_position(temp, &events_obj);
        }
    }
    puts("");
    int ret = events_obj.get_position(champion_ID, &events_obj);
    events_obj.cleanup(&events_obj);
    return ret;
}

int main(int argc, char *argv[])
{
    printf("%i\n", champion_rank(10, "1 I 10 O 2 I"));
    return 0;
}
