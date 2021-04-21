typedef struct Cinematograf
{
    char    denumire[50];
    char    adresa[50];
    int   telefon;
    int   locuri;
    float   pret;
    struct Cinematograf *st;
    struct Cinematograf *dr;
} Cinematograf;

Cinematograf *root;

typedef struct Elq
{
    Cinematograf *info;
    struct Elq *next;
} Elq;

Elq *prim,*ultim;

typedef struct Els
{
    Cinematograf *info;
    struct Els *pre;
} Els;

Els *top;

int inq(Cinematograf* v);
Cinematograf *sterq(void);

int push(Cinematograf *v);
Cinematograf *pop(void);

int creareC(void);
int creareS(void);
int afisarearboreC(void);
int afisarearboreS(void);
Cinematograf *cautaC(char *den);
Cinematograf *cautaS(char *den);
void modifiC(char *den);
void modifiS(char *den);
int nr_de_nodC(void);
int nr_de_nodS(void);
int inaltimeaC(Cinematograf *p);
int inaltimeaS(Cinematograf *p);
void elibq(void);
void elibs(void);
