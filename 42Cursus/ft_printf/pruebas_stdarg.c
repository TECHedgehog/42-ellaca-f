#include <stdarg.h>

int sum(int NumArg, ...)
{    int total = 0,i;
     va_list PuntArg;
     int arg;

     va_start(PuntArg, NumArg);

     for (i=0;i<NumArg; i++)
     {    arg = va_arg(PuntArg,int);
          total += arg;
		  printf("%d\n", arg);
     }

     va_end(PuntArg);
	 printf("%d\n", total);
     return total;
}

int main(void)
{    sum(5, 1,2,3,4);
}