#include <stdio.h>
#include <string.h>

#define MAXLINES 5000
#define MAXLEN 1000
#define ALLOCSIZE 32

char *lineptr[MAXLINES];
static char allocbuf[ALLOCSIZE];
static char* allocp = allocbuf;

int getLine(char *, int);
void swap(char *v[], int i, int j);
char *alloc(int);

/*
[1, 1, 0, 0, 0] an int array of size 5
char* alloc(int n) {
    if((allocbuf + ALLOCSIZE - allocp) >= n) {
        allocp += n;
        return allocp - n;
    }else {
        fprintf(stderr, "Not enough storage, buy more RAM\n");
        return 0;
    }
}
*/

int getLine(char s[], int max_len) {
    int c;
    char* ptr = s;

    for(s; s < (s + MAXLEN) && (c = getchar()) != EOF && c != '\n'; ++s) {
        *s = c;
    }

    // van\n\0
    if(c == '\n') { 
        *s++ = c;
    }

    *s = '\0';
    /*
       if(*s == '\0') {
       printf("CHAR?:%d\n", *s);
       }
       */
    return s - ptr;
}

int readlines(char *lineptr[], char* line, int maxlines) {
    int len, nlines;
    nlines = 0;

    while ((len = getLine(line, MAXLEN)) > 0) {
        // len is the number of chars read from the line and it cannot be greater than or equal to the maxlen for a line right??? 
        // MAXLEN -> 1000
        // len should 0 to 999
        if (nlines >= maxlines || line >= (line + MAXLEN))
            return -1;
        else {
            line[len-1] = '\0'; /* delete newline */
            lineptr[nlines++] = line;
            line = line + len;
        }
    }
    return nlines;
}

void writelines(char *lineptr[], int nlines) {
    while(nlines-- > 0) {
        printf("%s\n", *lineptr++);
    }
}

void qsort(char *v[], int left, int right) {
    int i, last;
    if (left >= right) /* do nothing if array contains */
        return; /* fewer than two elements */

    swap(v, left, (left + right)/2);
    last = left;

    for (i = left+1; i <= right; i++) {
        if (strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);
    }

    swap(v, left, last);
    qsort(v, left, last-1);
    qsort(v, last+1, right);
}

void swap(char *v[], int i, int j) {
    char *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

int main() {
    int nlines;
    char line[MAXLEN];

    if ((nlines = readlines(lineptr, line, MAXLINES)) >= 0) {
        qsort(lineptr, 0, nlines-1);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("error: input too big to sort\n");
        return 1;
    }

    return 0;
}
