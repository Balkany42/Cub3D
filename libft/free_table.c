#include "libft.h"

   void    free_table(char **table)
   {
       int i;

       if (!table)
           return ;
       i = 0;
       while (table[i])
           free(table[i++]);
       free(table);
   }