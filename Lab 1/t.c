// CptS 360 Lab 1.c
// Eric Chen 11381898
// Jan 28 2016

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 1. Lab 1 Q1 prints string */
int prints(char *s, ...) {
    while (*s) {
        putchar(*s);
        s++;
    }
}

/* 2.                        */
typedef unsigned int u32;

int BASE = 10;
int BASE8 = 8;
int BASE16 = 16;

char *table = "0123456789ABCDEF";

int rpu(u32 x)
{
    char c;
    if (x){
        c = table[x % BASE];
        rpu(x / BASE);
        putchar(c);
    }
}

int printu(u32 x)
{
    if (x==0)
        putchar('0');
    else
        rpu(x);

}

/* 3.   int printd(int x): print an integer, 
        int printo(u32 x): print x in OCTal as 0..., 
        int printx(u32 x): print x in HEX.  as 0x... */

// Int print
int printd(int x)
{
    if (x < 0) {
        putchar('-');
        x = x*(-1);
        printu(x);
    }
    else
        printu(x);
}

// For printo
int rpu2(u32 x)
{
    char c;
    if (x) {
        c = table[x % BASE8];
        rpu2(x / BASE8);
        putchar(c);
    }
}

// Octal print
int printo(u32 x)
{
    putchar('0');   // Leading 0

    if (x == 0)
        putchar('0');
    else
        rpu2(x);
    putchar(' ');
}

// For printx
int rpu3(u32 x)
{
    char c;
    if (x) {
        c = table[x % BASE16];
        rpu3(x / BASE16);
        putchar(c);
    }
}

// Hex print
int printx(u32 x)
{
    putchar('0');   // Leading 0x
    putchar('x');

    if (x == 0)
        putchar('0');
    else
        rpu3(x);
    putchar(' ');
}

/* 4. myprintf %c, %s, %u, %d, %o, %x, */

int myprintf(char *s, ...) {
    char *cp = s;
    int *ip = (int *)&s + 1;

    while (*cp) {

        if (*cp != '%')
        {
            putchar(*cp);
        }
        else
        {
            switch (*(cp + 1))
            {
                case 'c':
                    putchar((char)*ip++);
                    cp++;
                    break;
                case 's':
                    prints((char *)*ip++);  // Utilizing prints
                    cp++;
                    break;
                case 'u':
                    printu((u32)*ip++);
                    cp++;
                    break;
                case 'd':
                    printd((int)*ip++);
                    cp++;
                    break;
                case 'o':
                    printo((u32)*ip++);
                    cp++;
                    break;
                case 'x':
                    printx((u32)*ip++);
                    cp++;
                    break;
                default:
                    putchar(*s);
                    break;
            }
        }
        cp++;
    }
}

int testmyprintf()
{
    myprintf("\n\n* 4. myprintf: ");
    myprintf("\nchar a: %c\n", 'a');
    myprintf("\nstring hello: %s\n", "hello");
    myprintf("\nunsigned int 3: %u\n", 3);
    myprintf("\ninteger 421: %d\n", 421);
    myprintf("\noctal 8: %o\n", 8);
    myprintf("\nhex 15: %x\n\n", 15);
}

int mymain(int argc, char *argv[ ], char *env[ ])
{
    int i;

    myprintf("in mymain(): argc=%d\n", argc);

    for (i=0; i < argc; i++)
        myprintf("argv[%d] = %s\n", i, argv[i]);
  
    // WRITE CODE TO PRINT THE env strings
    while(*env)
    {
        printf("%s\n", *env++);
    }

    myprintf("---------- testing YOUR myprintf() ---------\n");
    myprintf("this is a test\n");
    myprintf("testing a=%d b=%x c=%c s=%s\n", 123, 123, 'a', "testing");
    myprintf("string=%s, a=%d  b=%u  c=%o  d=%x\n",
           "testing string", -1024, 1024, 1024, 1024);
    myprintf("mymain() return to main() in assembly\n"); 
}
