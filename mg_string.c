/*
 * mg_string.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "mg_string.h"

size_t mg_strlen(mg_string_t str)
{
    return strlen(str);
}

// Code obtained from 
// https://stackoverflow.com/questions/9210528/split-string-with-delimiters-in-c
/*
 * usage of this function
 * mg_string_t *tokens;
   tokens = mg_split(str, d);

   int i = 0;
   for(i = 0 ; *(tokens + i); i++)
   {
       // Do stuff with tokenized strings
   }
 */
mg_string_t *mg_split(mg_string_t s, char d)
{
    mg_string_t *result = 0;
    size_t count = 0;
    mg_string_t tmp = s;
    mg_string_t last_comma = 0;

    char delim[2];
    delim[0] = d;
    delim[1] = '\0';
//    char *delim = d;
    while(*tmp)
    {
        if(d == *tmp)
        {
            count++;
            last_comma = tmp;
        }
        tmp++;
    }

    count += last_comma < ( s + mg_strlen(s) - 1 );
    count++;

    result = malloc(sizeof(char *) * count);
    if(result)
    {
        size_t idx = 0;
        char *token = strtok(s, delim);
        while(token)
        {
            assert(idx < count);
            *(result + idx++) = strdup(token);
            token = strtok(0, delim);
        }

        assert(idx == count -1);
        *(result + idx) = 0;
    }

    return result;
}

/*
 * usage of this function
 * mg_str_vec svec;
 * mg_init_vec(&svec, 's');
 * mg_string_t str = "Hello Wordl!!!\n";
 * char delim = ' ';
 * svec = mg_split2(str , delim);
 * int i = 0;
   for( i = 0 ; i < svec.n; i++)
   {
       // do stuff
   }
 */
void mg_split2(mg_string_t s, char *delim, mg_str_vec *v)
{
    char *ptr = NULL;
    char *tmp;
    char *tmp_string;
    tmp_string = strdup(s);
    //char d[2];
    //d[0] = delim; d[1] = '\0';
    char *d = delim;
    tmp = tmp_string;
    ptr = strsep(&tmp, d);
    
    while(ptr != NULL)
    {
        mg_resize_vec((v) , v->n + 1, 's');
        mg_append_svec(v, ptr);
//        ptr = strtok(NULL , d);
        ptr = strsep(&tmp, d);
    }
    free(tmp_string);
}
