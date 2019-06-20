#include <stdlib.h>
#include <stdio.h>
#include "list.h"
#include <string.h>



void print (element_t ev) {
  int* e = ev;
  printf ("%d\n", *e);
}

void prints (element_t ev){
    char* e = ev;
    printf ("%s\n", e);
}

void printSingleLine(element_t ev){
  char* e = ev;
    printf ("%s", e);
}

void isInt(element_t* rv, element_t av){
  char * a = av;
  int **r = (int**) rv;
  if (*r == NULL){
    *r = malloc(sizeof(int));
  }
  **r = strtol(a,&a,10);
  if (**r == 0){
      **r = -1;
  }

}

void turnIntToNull (element_t* rv, element_t av, element_t bv) {
  int *a = av;
  char *b = bv;
  char **result = (char**) rv;
  if (*result == NULL)
    *result = malloc(sizeof(char));

    if (*a != -1){
        **result = '\0';
    }else{
      strcpy(*result,b);
    }
}

int removeNegative(element_t av) {
  int *a = av;
  return (*a > 0);
}

int removeNull(element_t av){
  char *a = av;
  return (*a != 0);
}

void turnStrToIntLength (element_t* rv, element_t av, element_t bv) {
  int *a = av;
  char *b = bv;
  char **result = (char**) rv;

// int stringlen = strlen(b); 
// *result = strncpy(*result, b, stringlen - *a);
// *result[stringlen - *a] = 0;
    *result = b;
    if(strlen(*result)<= *a){

    }else{
      (*result)[*a] = '\0'; 
    }


}
void combineStrings (element_t* rv, element_t av, element_t bv) {
  char *a = av;
  char *b = bv;
  char **result = (char**) rv;
  // if (*result == NULL)
  //   *result = malloc(sizeof(char));
  
  // if (*result != "")
  *result = realloc(*result, strlen(*result)+strlen(b)+2);
   strcat(*result,b);
  strcat(*result, " ");
}

void produceMax (element_t* rv, element_t av, element_t bv) {
  int *a = av;
  int *b = bv;
  int **result = (int**) rv;
  // if (*result == NULL)
  //   *result = malloc(sizeof(int));
  
  if (*b>**result)
  **result = *b;
}


int main(int argc, char** argv) 
{ 

    struct list* data = list_create();
    struct list* intData = list_create();
    struct list* nullNumData = list_create();
    struct list* nonNegativeIntData = list_create();
    struct list* stringListNoNullData = list_create();
    struct list* stringIntLengthData = list_create();
    for (int i = 1; i < argc; i++){
        list_append(data,argv[i]); 
    }

    list_map1(isInt, intData,data);
    list_map2(turnIntToNull,nullNumData,intData,data);

    list_filter(removeNegative, nonNegativeIntData, intData);

    list_filter(removeNull,stringListNoNullData, nullNumData);

    // list_foreach(prints,stringListNoNullData);
    // list_foreach(print,nonNegativeIntData);

    list_map2(turnStrToIntLength,stringIntLengthData,nonNegativeIntData,stringListNoNullData); 
    list_foreach(prints,stringIntLengthData);

    char* COMBINED = malloc(sizeof(char));
    list_foldl(combineStrings, (element_t*) &COMBINED, stringIntLengthData);
    printf ("%s\n", COMBINED);


    int max = 0;
    int *MAX = &max; 
    list_foldl(produceMax, (element_t*) &MAX, nonNegativeIntData);
    printf ("%d\n", *MAX);
    
    free(COMBINED);
    list_foreach(free,intData);
    list_foreach(free,nullNumData);

    list_destroy(data);
    list_destroy(intData);
    list_destroy(nullNumData);
    list_destroy(nonNegativeIntData);
    list_destroy(stringListNoNullData);
    list_destroy(stringIntLengthData);
    return 0;
} 