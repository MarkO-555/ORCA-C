/****************************************************************
*
*  stdarg.h - variable length parameter list handling
*
*  February 1989
*  Mike Westerfield
*
*  Copyright 1989
*  Byte Works, Inc.
*
*****************************************************************
*
*  Modified July 1994
*
*  Thanks to Doug Gwyn for the new va_start & va_arg declarations.
*
****************************************************************/

#ifndef __stdarg__
#define __stdarg__

#ifndef __va_list__
#define __va_list__
typedef char *__va_list[2];
#endif

typedef __va_list va_list;
#define va_end(a) __va_end(a)
#define	va_start(ap,LastFixedParm) ((void) ((ap)[0] = (ap)[1] = (char *) (&LastFixedParm + 1)))
#define	va_arg(ap,type)	((type *)((ap)[0] += sizeof(type)))[-1]

void __va_end(va_list);

#endif
