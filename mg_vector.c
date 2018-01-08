/*
 * mg_vector.c
 * Source of mg_vector.h
 */

#include <stdlib.h>
#include <string.h>
#include "mg_vector.h"

void mg_init_vec(void *vector, char t)
{
    switch(t)
    {/*
        case 'i': mg_int_vec *tmp = (mg_int_vec*)vector;
        case 'd': mg_dbl_vec* tmp = (mg_dbl_vec*)vector;
        case 'f': mg_flt_vec* tmp = (mg_flt_vec*)vector;
        case 's': mg_str_vec* tmp = (mg_str_vec*)vector;
        case 'c': mg_char_vec* tmp = (mg_char_vec*)vector;*/
        case 'i': mg_init_int((mg_int_vec*)vector);
        case 'd': mg_init_dbl((mg_dbl_vec*)vector);
        case 'f': mg_init_flt((mg_flt_vec*)vector);
        case 's': mg_init_str((mg_str_vec*)vector);
        case 'c': mg_init_char((mg_char_vec*)vector);
    }
}

void mg_init_int(mg_int_vec *v)
{
    v->entry = NULL; v->n = 0;
}
void mg_init_dbl(mg_dbl_vec *v)
{
    v->entry = NULL; v->n = 0;
}
void mg_init_flt(mg_flt_vec *v)
{
    v->entry = NULL; v->n = 0;
}
void mg_init_str(mg_str_vec *v)
{
    v->entry = NULL; v->n = 0;
}
void mg_init_char(mg_char_vec *v)
{
    v->entry = NULL; v->n = 0;
}

void mg_clear_vec(void *vector, char t)
{
    if(t == 's')
    {
        int i = 0;
        mg_str_vec* tmp = (mg_str_vec*)vector;
        for(i = 0; i < tmp->n; i++)
        {
            free(tmp->entry[i]);
        }
        free(tmp->entry);
        return;
    }
    else
    {
        if(t == 'i')
        {
            mg_int_vec* tmp = (mg_int_vec*)vector;
            free((tmp)->entry);
        }
        else if(t == 'c')
        {
            mg_char_vec * tmp = (mg_char_vec*)vector;
            free((tmp)->entry);
        }
        else if(t == 'd')
        {
            mg_dbl_vec * tmp = (mg_dbl_vec *)vector;
            free((tmp)->entry);
        }
        else
        {
            mg_flt_vec * tmp = (mg_flt_vec *)vector;
            free((tmp)->entry);
        }
        return;
        
    }
}
void mg_resize_vec(void *vector , int elem , char t)
{
    size_t s = 0;
    switch(t)
    {
        case 'i' : 
            s = sizeof(int) * elem;
            mg_int_vec *ivec = (mg_int_vec *)vector;
            ivec->entry = (int*)realloc(ivec->entry, s);
            ivec->n = elem;
            break;
        case 'c' :
             s = elem;
             mg_char_vec* cvec = (mg_char_vec*)vector;
             cvec->entry = (char*)realloc(cvec->entry , s);
             cvec->n = elem;
             break;
        case 'f':
             s = sizeof(float) * elem;
             mg_flt_vec* fvec = (mg_flt_vec*)vector;
             fvec->entry = (float*)realloc(fvec->entry, s);
             fvec->n = elem;
             break;
         case 'd':
             s = sizeof(double) * elem;
             mg_dbl_vec* dvec = (mg_dbl_vec*)vector;
             dvec->entry = (double*)realloc(dvec->entry, s);
             dvec->n = elem;
             break;
        case 's':
             s = sizeof(char *) * elem;
             mg_str_vec* svec = (mg_str_vec*)vector;
             svec->entry = (char**)realloc(svec->entry , s);
             svec->n = elem;
             break;
    }
    
}

void mg_append_ivec(mg_int_vec *v, int elem)
{
    // Assumes that vector is already re-scaled.
    v->entry[v->n-1] = elem;
}

void mg_append_dvec(mg_dbl_vec *v, double elem)
{
   v->entry[v->n-1] = elem;
}

void mg_append_fvec(mg_flt_vec *v, float elem)
{
    v->entry[v->n-1] = elem;
}

void mg_append_cvec(mg_char_vec *v, char elem)
{
    v->entry[v->n-1] = elem;
}

void mg_append_svec(mg_str_vec *v, char *elem)
{
    v->entry[v->n-1] = strdup(elem);
}

void mg_insert_ivec(mg_int_vec *v, int elem, int index)
{
    v->entry[index] = elem;
}
void mg_insert_dvec(mg_dbl_vec *v, double elem, int index)
{
    v->entry[index] = elem;
}
void mg_insert_fvec(mg_flt_vec *v, float elem, int index)
{
    v->entry[index] = elem;
}
void mg_insert_cvec(mg_char_vec* v, char elem, int index)
{
    v->entry[index] = elem;
}
void mg_insert_svec(mg_str_vec* v, char * elem, int index)
{
    v->entry[index] = strdup(elem);
}


int mg_ivec_at(mg_int_vec *v, int index)
{
    return v->entry[index];
}

double mg_dvec_at(mg_dbl_vec *v, int index)
{
    return v->entry[index];
}
float mg_fvec_at(mg_flt_vec *v, int index)
{
    return v->entry[index];
}
char* mg_svec_at(mg_str_vec *v, int index)
{
    return v->entry[index];
}
char mg_cvec_at(mg_char_vec *v, int index)
{
    return v->entry[index];
}
