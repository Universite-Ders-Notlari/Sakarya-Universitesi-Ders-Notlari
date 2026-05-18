/* Libraries for fields, doubly-linked lists and red-black trees.
   Copyright (C) 2018 James S. Plank */

#ifndef _FIELDS_ 
#define _FIELDS_ 

/* The fields library -- making input processing easier */

#include <stdio.h>
#define MAXLEN 1001
#define MAXFIELDS 1000

typedef struct inputstruct {
  char *name;               /* File name */
  FILE *f;                  /* File descriptor */
  int line;                 /* Line number */
  char text1[MAXLEN];       /* The line */
  char text2[MAXLEN];       /* Working -- contains fields */
  int NF;                   /* Number of fields */
  char *fields[MAXFIELDS];  /* Pointers to fields */
  int file;                 /* 1 for file, 0 for popen */
} *IS;

extern IS new_inputstruct(/* FILENAME -- NULL for stdin */);
extern IS pipe_inputstruct(/* COMMAND -- NULL for stdin */);
extern int get_line(/* IS */); /* returns NF, or -1 on EOF.  Does not
                                  close the file */
extern void jettison_inputstruct(/* IS */);  /* frees the IS and fcloses 
                                                the file */
#endif
