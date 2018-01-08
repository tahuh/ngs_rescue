/*
 * mg_string.h
 * 
 * Mongyool library of C language of string data type
 * 
 * Authod : Sunghoon Heo
 */

#ifndef _MG_STRING_H_
#define _MG_STRING_H_

#include "mg_vector.h"
typedef char* mg_string_t;

size_t mg_strlen(mg_string_t str);
mg_string_t *mg_split(mg_string_t origin, char delim);
void mg_split2(mg_string_t origin, char *delim, mg_str_vec *v);

#endif
