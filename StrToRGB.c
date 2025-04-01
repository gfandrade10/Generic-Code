#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define START_RGB_OBJECT(OBJ) {             \
    OBJ.SplitString = &SplitString_impl_;   \
    OBJ.FillColors = &FillColors_impl_;     \
}

typedef struct rgb_impl_
{
    int r, g, b;
    char R[3], G[3], B[3];
    void (*SplitString)(struct rgb_impl_* obj, const char* str);
    void (*FillColors)(struct rgb_impl_* obj);
} rgb;

void SplitString_impl_(rgb* obj, const char* str)
{
    char buffer[strlen(str) + 1];
    strcpy(buffer, str);
    for(size_t i = 0, rc = 0, gc = 0, bc = 0; i < strlen(str); ++i)
    {
        if(isalpha(buffer[i]))
            buffer[i] = tolower(buffer[i]);

        if(i > 0 && i < 3)
            obj->R[rc++] = buffer[i];

        else if(i > 2 && i < 5)
            obj->G[gc++] = buffer[i];

        else if(i > 4 && i < 7)
            obj->B[bc++] = buffer[i];
    }
    obj->R[2] = '\0';
    obj->G[2] = '\0';
    obj->B[2] = '\0';
}

void FillColors_impl_(rgb* obj)
{
    obj->r = (int)strtol(obj->R, NULL, 16);
    obj->g = (int)strtol(obj->G, NULL, 16);
    obj->b = (int)strtol(obj->B, NULL, 16);
}

rgb hex_str_to_rgb(const char *hex_str) 
{
    rgb ColorObject;
    START_RGB_OBJECT(ColorObject);
    
    ColorObject.SplitString(&ColorObject, hex_str);
    ColorObject.FillColors(&ColorObject);

    return ColorObject;
}

int main()
{
    char RGB[] = "#FF9933";
    rgb ColorObject = hex_str_to_rgb(RGB);

    printf("R: %s  G: %s  B: %s\n", ColorObject.R, ColorObject.G, ColorObject.B);
    printf("%i | %i | %i\n", ColorObject.r, ColorObject.g, ColorObject.b);
}
