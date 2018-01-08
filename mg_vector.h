/*
 * mg_vector.h
 * Generalized vector format for C
 *
 */

/*
 * Synopsis
 * 
 * #include "mg_vector.h"
   int main()
   {
      // example for integer vector
      mg_int_vec mgi_vec;
      // Last argument denotes integer
      // f for float d for double s for string c for char
      mg_init_vec(&mg_ivec, 'i');
      // Adding element
      // First resize vector
      mg_resize_vec((void**)&(mgi_vec), mgi_vec.n + 1, 'i');
      mg_append_ivec(&(mgi_vec), 10);
      int i = 0;
      for( i = 0; i < mgi_vec.n; i++)
      {
          mg_ivec_at(&mg_ivec , i);
      }
      mg_clear_vec((void**)&mgi_vector, 'i');
   }
 */
#ifndef _MG_VECTOR_H_
#define _MG_VECTOR_H_

typedef struct mg_i_vec
{
   size_t n;
   int *entry;
}mg_int_vec;

typedef struct mg_s_vec
{
    size_t n;
    char **entry;
}mg_str_vec;

typedef struct mg_d_vec
{
    size_t n;
    double *entry;
}mg_dbl_vec;

typedef struct mg_f_vec
{
    size_t n;
    float *entry;
}mg_flt_vec;

typedef struct mg_c_vec
{
    size_t n;
    char *entry;
}mg_char_vec;

void mg_init_vec(void *vector, char t);
void mg_init_int(mg_int_vec *v);
void mg_init_dbl(mg_dbl_vec *v);
void mg_init_flt(mg_flt_vec *v);
void mg_init_str(mg_str_vec *v);
void mg_init_char(mg_char_vec *v);

void mg_clear_vec(void *vector, char t);
void mg_resize_vec(void *vector, int elem, char t);

void mg_append_ivec(mg_int_vec *v, int elem);
void mg_append_dvec(mg_dbl_vec *v, double elem);
void mg_append_fvec(mg_flt_vec *v, float elem);
void mg_append_cvec(mg_char_vec* v, char elem);
void mg_append_svec(mg_str_vec* v, char * elem);

void mg_insert_ivec(mg_int_vec *v, int elem, int index);
void mg_insert_dvec(mg_dbl_vec *v, double elem, int index);
void mg_insert_fvec(mg_flt_vec *v, float elem, int index);
void mg_insert_cvec(mg_char_vec* v, char elem, int index);
void mg_insert_svec(mg_str_vec* v, char * elem, int index);

int mg_ivec_at(mg_int_vec *v, int index);
double mg_dvec_at(mg_dbl_vec *v, int index);
float mg_fvec_at(mg_flt_vec *v, int index);
char* mg_svec_at(mg_str_vec *v, int index);
char mg_cvec_at(mg_char_vec *v, int index);

#endif /* _MG_VECTOR_H_ */
