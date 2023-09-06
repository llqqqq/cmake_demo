#ifndef HELLO_H
#define HELLO_H

// from linuv 

#ifdef _WIN32
  /* Windows - set up dll import/export decorators. */
# if defined(BUILDING_SHARED)
    /* Building shared library. */
#   define EXPORT __declspec(dllexport)
# elif defined(USING_SHARED)
    /* Using shared library. */
#   define UV_EXTERN __declspec(dllimport)
# else
    /* Building static library. */
#   define UV_EXTERN /* nothing */
# endif
#elif __GNUC__ >= 4
# define UV_EXTERN __attribute__((visibility("default")))
#else
# define UV_EXTERN /* nothing */
#endif

#ifdef __cplusplus
extern "C" {
#endif

void print_hello(); 

#ifdef __cplusplus
}
#endif

#endif