#include <stdio.h>

#define MAXLEN 1000

#define TRUE 1
#define FALSE 0

int getStr(char line[]) {
    int c, i;

    for(i = 0; i < MAXLEN - 1 && ((c = getchar())) != EOF; ++i) {
        line[i] = c;
    }

    if(c == '\n') {
        line[i] = c;
        ++i;
    }

    line[i] = '\0';
    return i;
}

// TODO: lots of conditions need to be checked (probably  I would not do this)
void check_syntax(int str_len, char str[]) {
    int rowNumber, isParenOpen, isParenClosed, isBracketOpen, isBracketClosed, shouldBeComment, multiLineCommentStart, multiLineCommentEnd;
    isParenOpen = isParenClosed = FALSE;
    isBracketOpen = isBracketClosed = FALSE;
    shouldBeComment = FALSE;
    multiLineCommentStart = multiLineCommentEnd = FALSE;

    int curlyBraceOpenCount, curlyBraceClosedCount, doubleQuotesCount, singleQuotesCount;
    curlyBraceOpenCount = curlyBraceClosedCount = doubleQuotesCount = singleQuotesCount = 0;
    
    int multiLineCommentStartLinePos, multiLineCommentEndLinePos;
    multiLineCommentStartLinePos =  multiLineCommentEndLinePos = 0;

    rowNumber = 1;
    for(int i = 0; i < str_len; ++i) {
        if(str[i] == '/' && str[i + 1] == '*') {
            multiLineCommentStart = TRUE;
            multiLineCommentStartLinePos = rowNumber;
        }

        if(str[i] == '*' && str[i + 1] == '/') {
            multiLineCommentEnd = TRUE;
            multiLineCommentEndLinePos = rowNumber;
        }

        if(str[i] == '/' && (!multiLineCommentStart && !multiLineCommentEnd)) {
            shouldBeComment = TRUE;
        }

        if(str[i] == '"') { 
            ++doubleQuotesCount;
        }

        if(str[i] == '\'') { 
            ++singleQuotesCount;
        }

        if(str[i] == '(') {
            isParenOpen = TRUE;
        }
        if(str[i] == ')') {
            isParenClosed = TRUE;
        }

        if(str[i] == '{') {
            ++curlyBraceOpenCount;
        }
        if(str[i] == '}') {
            ++curlyBraceClosedCount;
        }

        if(str[i] == '[') {
            isBracketOpen = TRUE;
        }
        if(str[i] == ']') {
            isBracketClosed = TRUE;
        }

        if(str[i] == '\n') {
            if(doubleQuotesCount > 2) {
                printf("Syntax error: Unexpected identifier(s) \" found on line %d, did you forget to escape it?\n", rowNumber);
                doubleQuotesCount = 0;
            }

            if(shouldBeComment) {
                printf("Syntax error: Unexpected identifier found on line %d, did you mean to write //?\n", rowNumber);
                shouldBeComment = FALSE;
            }

            if(doubleQuotesCount && doubleQuotesCount % 2 != 0) {
                printf("Syntax error: Expected a \" on line %d\n", rowNumber);
                doubleQuotesCount = 0;
            }

            if(singleQuotesCount % 2 != 0) {
                printf("Syntax error: Expected a \' on line %d\n", rowNumber);
                singleQuotesCount = 0;
            }

            if(isParenOpen && !isParenClosed) {
                printf("Syntax error: Expected a ')' on line %d\n", rowNumber);
                isParenOpen = isParenClosed = FALSE;
            }else if(!isParenOpen && isParenClosed) { 
                printf("Syntax error: Expected a '(' on line %d\n", rowNumber);
                isParenOpen = isParenClosed = FALSE;
            }else {
                isParenOpen = isParenClosed = FALSE;
            }

            if(isBracketOpen && !isBracketClosed) {
                printf("Syntax error: Expected a ']' on line %d\n", rowNumber);
                isBracketOpen = isBracketClosed = FALSE;
            }else if(!isBracketOpen && isBracketClosed) { 
                printf("Syntax error: Expected a '[' on line %d\n", rowNumber);
                isBracketOpen = isBracketClosed = FALSE;
            }else {
                isBracketOpen = isBracketClosed = FALSE;
            }

            rowNumber += 1;
        }
    }

    if(multiLineCommentStart && !multiLineCommentEnd) {
        printf("Syntax error: Expected */ for the unmatched multi-line comment in the source code\n");
        multiLineCommentStart = multiLineCommentEnd = FALSE;
        multiLineCommentStartLinePos = multiLineCommentEndLinePos = 0;
    }else if(!multiLineCommentStart && multiLineCommentEnd) {
        printf("Syntax error: Expected /* for the unmatched multi-line comment in the source code\n");
        multiLineCommentStart = multiLineCommentEnd = FALSE;
        multiLineCommentStartLinePos = multiLineCommentEndLinePos = 0;
    }else {
        multiLineCommentStart = multiLineCommentEnd = FALSE;
        multiLineCommentStartLinePos = multiLineCommentEndLinePos = 0;
    }

    if(curlyBraceOpenCount != curlyBraceClosedCount) {
        if(curlyBraceOpenCount > curlyBraceClosedCount) {
            printf("Syntax error: Expected %d '}' in the source code", curlyBraceOpenCount - curlyBraceClosedCount);
            curlyBraceOpenCount = curlyBraceClosedCount = 0;
        }else if(curlyBraceClosedCount > curlyBraceOpenCount) {
            printf("Syntax error: Expected %d '{' in the source code", curlyBraceClosedCount - curlyBraceOpenCount);
            curlyBraceOpenCount = curlyBraceClosedCount = 0;
        }else {
            curlyBraceOpenCount = curlyBraceClosedCount = 0;
        }
    }
}

int main() {
    char arr[MAXLEN];
    int str_len;

    str_len = getStr(arr);
    check_syntax(str_len, arr);

    return 0;
}
