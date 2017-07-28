#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Typ
{
   char wortliste[934];
};


double zeile = 0, laenge;
int i = 0, k, l, m = 0, ret1 = 1, ret2 = 1;
size_t length;
struct Typ Liste[1000];
char test, line[934], eingabe, eraten[100] = {}, falsch[25] = {}, Wort[100] = {}, a;

int main()
{
    srand((unsigned)time(NULL));
    zeile = (rand()%934+1);
    anfang: printf("\nHallo");


    ret1 = spiel();
    if(ret1 == 0)
        printf("Alles ok,  Returnwert = %i;\n", ret1);
    else if (ret1 != 0)
        printf("Fehler in funktion spiel()\tReturnwert = %i\n", ret1);

    getchar();
    printf("Nochmal(J/N)");
    scanf("%c", &test);

    if(test == 'J' || test == 'j')
    {
    ret2 = reset();
    if(ret2 == 0)
        printf("Alles ok,  Returnwert = %i;\n", ret2);
    else if (ret2 != 0)
        printf("Fehler in funktion reset()\tReturnwert = %i\n", ret2);
    //goto anfang;
    }
    else
        ;

    return 0;

}

int spiel()
{

    printf("%f\n\n", zeile);

    /////////////////////////////

    FILE *fp;
    fp = fopen("woerter.csv", "r");
    if(fp == NULL) {printf("Dateifehler\n"); return 1;}

    for(i = 0; i < 934; i++)
    {
    fscanf(fp, "%s", line);
    strcpy(Liste[i].wortliste, strtok(line, ";"));
    printf("%s\n", Liste[i].wortliste);
    }

    i = zeile;
    printf("\n\n\n\n%s", Liste[i].wortliste);

    /////////////////////////////

    length = strlen(Liste[i].wortliste);
    laenge = length;
    printf("\n\n\n%f\n\n", laenge);

    for(k = 0; k < laenge; k++)
    {
        eraten[k] = '_';
        printf("%c ", eraten[k]);
    }

    char *text = Liste[i].wortliste;

    for(k = 0; k < laenge; k++)
    {
        Wort[k] = text[k];
        printf("\n%c", Wort[k]);
    }

    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    system("clear");

    printf("Galgenraten\n Ä = AE; Ö = OE; Ü = UE\n");
    printf("%s\n\nFalsche Buchstaben:%s", eraten, falsch);
    for(l = 0; l < 26; l++)
    {
        //system("clear");

        printf("\nBitte einen Buchstaben eingeben(nur Großbuchstaben):\n");
        scanf("%c", &eingabe);
        printf("\n\n\n\n\n\n\n\n\n\n\n\n");

        for(k = 0; k < laenge; k++)
        {
            if(eingabe == Wort[k])
                eraten[k] = Wort[k];

        }

        if(strchr(Wort, eingabe) == NULL)
        {
            falsch[m] = eingabe;
            m = m+1;
        }

        switch(m)
        {
            case 1:
            {
                printf(" ┌─────────────────┐\n"\
                       "─┘                 └─\n\n");
                break;
            }
            case 2:
            {
                printf("          │\n"\
                       "          │\n"\
                       "          │\n"\
                       "          │\n"\
                       "          │\n"\
                       "          │\n"\
                       "          │\n"\
                       "          │\n"\
                       "          │\n"\
                       "          │\n"\
                       " ┌────────┴────────┐\n"\
                       "─┘                 └─\n\n");
                break;
            }
            case 3:
            {
                printf("          ┌──────────\n"\
                       "          │\n"\
                       "          │\n"\
                       "          │\n"\
                       "          │\n"\
                       "          │\n"\
                       "          │\n"\
                       "          │\n"\
                       "          │\n"\
                       "          │\n"\
                       " ┌────────┴────────┐\n"\
                       "─┘                 └─\n\n");
                break;
            }
            case 4:
            {
                printf("          ┌───┬──────\n"\
                       "          │ ┌─┘\n"\
                       "          ├─┘\n"\
                       "          │\n"\
                       "          │\n"\
                       "          │\n"\
                       "          │\n"\
                       "          │\n"\
                       "          │\n"\
                       "          │\n"\
                       " ┌────────┴────────┐\n"\
                       "─┘                 └─\n\n");
                break;
            }
            case 5:
            {
                printf("          ┌───┬─────┬─\n"\
                       "          │ ┌─┘     │\n"\
                       "          ├─┘       │\n"\
                       "          │\n"\
                       "          │\n"\
                       "          │\n"\
                       "          │\n"\
                       "          │\n"\
                       "          │\n"\
                       "          │\n"\
                       " ┌────────┴────────┐\n"\
                       "─┘                 └─\n\n");
                break;
            }
            case 6:
            {
                printf("          ┌───┬─────┬─\n"\
                       "          │ ┌─┘     │\n"\
                       "          ├─┘      ┌┴─┐\n"\
                       "          │        │  │\n"\
                       "          │        └──┘\n"\
                       "          │\n"\
                       "          │\n"\
                       "          │\n"\
                       "          │\n"\
                       "          │\n"\
                       " ┌────────┴────────┐\n"\
                       "─┘                 └─\n\n");
                break;
            }
            case 7:
            {
                printf("          ┌───┬─────┬─\n"\
                       "          │ ┌─┘     │\n"\
                       "          ├─┘      ┌┴─┐\n"\
                       "          │        │  │\n"\
                       "          │        └┬─┘\n"\
                       "          │         │\n"\
                       "          │         │\n"\
                       "          │\n"\
                       "          │\n"\
                       "          │\n"\
                       " ┌────────┴────────┐\n"\
                       "─┘                 └─\n\n");
                break;
            }
            case 8:
            {
                printf("          ┌───┬─────┬─\n"\
                       "          │ ┌─┘     │\n"\
                       "          ├─┘      ┌┴─┐\n"\
                       "          │        │  │\n"\
                       "          │        └┬─┘\n"\
                       "          │         │\n"\
                       "          │         │\n"\
                       "          │        ┌┴┐\n"\
                       "          │        │ │\n"\
                       "          │\n"\
                       " ┌────────┴────────┐\n"\
                       "─┘                 └─\n\n");
                break;
            }
            case 9:
            {
                printf("          ┌───┬─────┬─\n"\
                       "          │ ┌─┘     │\n"\
                       "          ├─┘      ┌┴─┐\n"\
                       "          │        │  │\n"\
                       "          │        └┬─┘\n"\
                       "          │        ┌┼┐\n"\
                       "          │        │││\n"\
                       "          │        ┌┴┐\n"\
                       "          │        │ │\n"\
                       "          │\n"\
                       " ┌────────┴────────┐\n"\
                       "─┘                 └─\n\n");
                break;
            }
            case 10:
            {
                printf("          ┌───┬─────┬─\n"\
                       "          │ ┌─┘     │\n"\
                       "          ├─┘      ┌┴─┐\n"\
                       "          │        │xx│\n"\
                       "          │        └┬─┘\n"\
                       "          │        ┌┼┐\n"\
                       "          │        │││\n"\
                       "          │        ┌┴┐\n"\
                       "          │        │ │\n"\
                       "          │\n"\
                       " ┌────────┴────────┐\n"\
                       "─┘                 └─\n\n");
                break;
            }
        }

        printf("%s\n\nFalsche Buchstaben:%s", eraten, falsch);
        if(strncmp(eraten, Wort, laenge) == 0)
        {
            printf("\n\nGeschafft!!!!!!!!!!!:)\n\n");
            goto ende;
        }

        if(m >= 10)
        {
            printf("\n\nVerloren\nDas Wort war:%s\n\n\n", Wort);
            goto ende;
        }

        getchar();
    }
    getchar();
    ende: printf("Ende\n\n");
    return 0;
}

int reset()
{
    printf("Hallo\n");
    ////////int///////////
    i = 0;
    k = 0;
    l = 0;
    m = 0;
    ret1 = 1;
    ret2 = 1;
    length = 0;
    printf("Int fertig\t");
    ////////double////////
    zeile = (rand()%934+1);
    laenge = 0;
    printf("Double fertig\t");
    ////////char//////////
    //Liste = ;
    test = ' ';
    a = ' ';
    eingabe = ' ';
    //line[934] = {}, eraten[100] = {}, falsch[25] = {}, Wort[100] = {};
    printf("Char fertig\t");

    return 0;
}
// ─ │ ┌ ┐ └ ┘ ├ ┤ ┬ ┴ ┼
