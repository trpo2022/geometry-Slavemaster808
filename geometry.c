#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 201

typedef struct Coord {
    char coor[30];
} co;

int main(void)
{
    char ch1[] = "circle\0";
    char ch2[] = "( , )\0";
    char str[MAX];
    char name[10];
    co coordin[10];

    int n = 0;
    int k = 0;

    puts("Enter string:\n");
    fgets(str, MAX - 1, stdin);

    for (int i = 0; ch1[i] != '\0'; i++) {
        if (isupper(str[i])) {
	    str[i] = tolower(str[i]);
            //puts("1st letter must be in upper case.\n");
            //break;
        }
        if (str[i] == ch1[i]) {
            n++;
            name[i] = str[i];
        }
        k = i + 2;
    }
    name[0] = toupper(name[0]);

    int c = 0;
    if (n != strlen(ch1)) {
        puts("Check name or bracket.");
        c++;
    }

    int m = 0;
    int j = 0;
    int comm = 0;
    // printf("%d\n", n);
    // printf("%c\n", str[k]);
    for (int i = k; str[i] != ')'; i++) {
        if (c != 0)
            break;

        if (str[i] == ',') {
            n++;
	    comm++;
	    //m++;
            continue;
        }

        if (str[i] == '.' || isdigit(str[i])) {
            coordin[m].coor[j] = str[i];
            j++;
        } else if (str[i] == ' ') {
            m++;
            n++;
            //comm++;
            j = 0;
        }
	 else {
            puts("Check input data or commas.\n");
            break;
        }
    }
    // printf("%d", n);
    int l = 0;
    while (l < 3) {
        if (comm < 1) {
            puts("Too few args, try again.\n");
            break;
        }

        printf("Object: %s\n", name);
        l++;

        printf("Coordinates: (%s, %s)\n", coordin[0].coor, coordin[1].coor);
        l++;

        printf("Radius: %s\n", coordin[2].coor);
        l++;
    }
    return 0;
}
