#include <stdio.h>
#include "librarie_lab10.h"
#include <stdlib.h>

int inq(Cinematograf *v)
{
    Elq *t;
    t=(Elq*)calloc(1,sizeof(*t));
    if(t==NULL) return 0;
    t->info=v;
    t->next=NULL;
    if(prim==NULL)
    {
        prim=t;
    }
    else
    {
        ultim->next=t;
    }
    ultim=t;
    return 1;
}

Cinematograf* sterq(void)
{
    Elq *t;
    Cinematograf *v;
    t=prim;
    v=t->info;
    prim=t->next;
    if(t==ultim)
    {
        ultim=NULL;
    }
    free(t);
    return v;
}

int push(Cinematograf *v)
{
    Els *t;
    t=(Els*)calloc(1,sizeof(*t));
    if(t==NULL) return 0;
    t->info=v;
    t->pre=top;
    top=t;
    return 1;
}

Cinematograf* pop(void)
{
    Els* t;
    Cinematograf* v;
    t=top;
    v=t->info;
    top=t->pre;
    free(t);
    return v;
}

int creareC(void)
{
    Cinematograf *p,*s;
    int d, f;
    root = NULL;
    prim=ultim=NULL;

    printf("\nDe creat arbore (radacina)?: (1/0): ");
    scanf("%d", &f);
    if(f==0)
    {
        puts("\n\tArbore nu a fost creat.");
        return 0;
    }
    p=(Cinematograf*)malloc(sizeof(*p));
    if(p==NULL)
    {
        printf("\tERROR! Arborele nu a fost creat! ");
        return -1;
    }
    root=p;
    printf("\n\tDenumirea: ");
    scanf("%s",&p->denumire);
    printf("\tAdresa: ");
    scanf("%s",&p->adresa);
    printf("\tTelefonul: ");
    scanf("%d",&p->telefon);
    printf("\tNm da locuri: ");
    scanf("%d",&p->locuri);
    printf("\tPretul: ");
    scanf("%f",&p->pret);
    d=inq(p);
    while(prim!=NULL)
    {
        p=sterq();

        printf("De creat fiul stang al nodului %s ? (1/0): ",p->denumire);
        scanf("%d", &f);
        if(f!=0)
        {
            p=(Cinematograf*)malloc(sizeof(*p));
            if(s==NULL)
            {
                printf("\tERROR! Fiul stang nu a fost creat! ");
                return -1;
            }
            p->st=s;
            printf("\n\tDenumirea: ");
            scanf("%s",&p->denumire);
            printf("\tAdresa: ");
            scanf("%s",&p->adresa);
            printf("\tTelefonul: ");
            scanf("%d",&p->telefon);
            printf("\tNm da locuri: ");
            scanf("%d",&p->locuri);
            printf("\tPretul: ");
            scanf("%f",&p->pret);
            d=inq(s);
        }
        else
        {
            p->st=NULL;
        }

        printf("De creat fiul drept al nodului %s ? (1/0): ", p->denumire);
        scanf("%d", &f);
        if(f!=0)
        {
           s=(Cinematograf*)malloc(sizeof(*s));
            if(s==NULL)
            {
                printf("\tERROR! Fiul stang nu a fost creat! ");
                return -1;
            }
            p->dr=s;
            printf("\n\tDenumirea: ");
            scanf("%s",&s->denumire);
            printf("\tAdresa: ");
            scanf("%s",&s->adresa);
            printf("\tTelefonul: ");
            scanf("%d",&s->telefon);
            printf("\tNm da locuri: ");
            scanf("%d",&s->locuri);
            printf("\tPretul: ");
            scanf("%f",&s->pret);
            d=inq(s);
        }
        else
        {
            p->dr=NULL;
        }
    }

    return 1;
}

int afisarearboreC()
{
    Cinematograf *c,*p;
    prim=ultim=NULL;
    int a;
    a=inq(root);
    if (a==0)
    {
        printf("\n\tArborele nu exista! ");
    }
    printf("\nInformatia despre nodurile arborelui\n");
    while(prim!=NULL)
    {
        printf("\n");
        c=sterq();
        printf("\nDenumirea: %s",c->denumire);
        printf("\nAdresa: %s",c->adresa);
        printf("\nTelefonul: %d",c->telefon);
        printf("\nNr de locuri: %d",c->locuri);
        printf("\nPretul: %f",c->pret);
        printf("\nAdresa curenta %d ",c);
        printf("\nAdr urmator pe st %d ",c->st);
        printf("\nAdr urmator pe dr %d ",c->dr);
        p=c->st;
        if (p!=NULL)
        {
            inq(p);
        }
        p=c->dr;
        if (p!=NULL)
        {
            inq(p);
        }
    }
    return 1;
}

Cinematograf *cautaC(char *den)
{
    Cinematograf *c,*p;
    prim=ultim=NULL;
    int a;
    a=inq(root);
    if (a==0)
    {
        printf("\nArborele nu exista! \n");
        return -1;
    }
    while(prim!=NULL)
    {
        c=sterq();
        if(strcmp(c->denumire,den)==0)
        {
            printf("\n");
        printf("\nDenumirea: %s",c->denumire);
        printf("\nAdresa: %s",c->adresa);
        printf("\nTelefonul: %d",c->telefon);
        printf("\nNr de locuri: %d",c->locuri);
        printf("\nPretul: %f",c->pret);
            printf("\n\tAdresa curenta %d ",c);
            printf("\n\tAdr urmator pe st %d ",c->st);
            printf("\n\tAdr urmator pe dr %d ",c->dr);
            printf("\n");
            return c;
        }
        p=c->st;
        if (p!=NULL)
        {
            inq(p);
        }
        p=c->dr;
        if (p!=NULL)
        {
            inq(p);
        }
    }
    return NULL;
}
void modifiC(char *den)
{
    Cinematograf *c;
    c=cautaC(den);
    if (c!=NULL)
    {
        int f;
        printf("\n\tDoriti sa modificati denumirea? (1/0): ");
        scanf("%d", &f);
        if(f>0)
        {
            printf("\n\tIntroduceti noua denumire: ");
            scanf("%s",&c->denumire);
        }
        printf("\n\tDoriti sa modificati adresa? (1/0): ");
        scanf("%d", &f);
        if(f>0)
        {
            printf("\n\tIntroduceti noua adresa: ");
            scanf("%s",&c->adresa);
        }
        printf("\n\tDoriti sa modificati telefonul? (1/0): ");
        scanf("%d", &f);
        if(f>0)
        {
            printf("\n\tIntroduceti noul telefon: ");
            scanf("%d",&c->telefon);
        }
        printf("\n\tDoriti sa modificati locurile? (1/0): ");
        scanf("%d", &f);
        if(f>0)
        {
            printf("\n\tIntroduceti noul numar de locuri?: ");
            scanf("%d",&c->locuri);
        }
        printf("\n\tDoriti sa modificati pretul? (1/0): ");
        scanf("%d", &f);
        if(f>0)
        {
            printf("\n\tIntroduceti noul pret: ");
            scanf("%f",&c->pret);
        }
    }
    else
    {
        printf("\n\tNu a fost gasit asa cinematograf! \n");
    }
}
int nr_de_nodC()
{
    int cont=0;
    Cinematograf *c,*p;
    prim=ultim=NULL;
    int a;
    a=inq(root);
    if (a==0)
    {
        printf("\n\tArborele nu exista! ");
    }
    while(prim!=NULL)
    {
        printf("\n");
        c=sterq();
        cont++;
        p=c->st;
        if (p!=NULL)
        {
            inq(p);
        }
        p=c->dr;
        if (p!=NULL)
        {
            inq(p);
        }
    }
    return cont;
}

int inaltimeaC(Cinematograf *p)
{
    if (p)
    {
        int inst=inaltimeaC(p->st);
        int indr=inaltimeaC(p->dr);
        int max;
        if (inst>indr)
        {
            max=inst;
        }
        else
        {
            max=indr;
        }
        max++;
        return max;
    }
    else
    {
        return 0;
    }
}

void elibq()
{
    Cinematograf *c,*p;
    prim=ultim=NULL;
    int a;
    a=inq(root);
    if (a==0)
    {
        printf("\n\tArborele nu exista! \n");
    }
    while(prim!=NULL)
    {
        c=sterq();
        p=c->st;
        if (p!=NULL)
        {
            inq(p);
        }
        p=c->dr;
        if (p!=NULL)
        {
            inq(p);
        }
        free(c);
    }
    printf("\n\tMemoria a fost eliberata!\n");
}

int creareS(void)
{
    Cinematograf *p,*s;
    int d, f;
    top=NULL;
    root=NULL;
    printf("\nDe creat arbore (radacina)?: (1/0): ");
    scanf("%d", &f);
    if(f==0)
    {
        puts("\n\tArbore nu a fost creat.");
        return 0;
    }
    p=(Cinematograf*)malloc(sizeof(*p));
    if(p==NULL)
    {
        printf("\tERROR! Arborele nu a fost creat! ");
        return -1;
    }
    root=p;
            printf("\n\tDenumirea: ");
            scanf("%s",&p->denumire);
            printf("\tAdresa: ");
            scanf("%s",&p->adresa);
            printf("\tTelefonul: ");
            scanf("%d",&p->telefon);
            printf("\tNm da locuri: ");
            scanf("%d",&p->locuri);
            printf("\tPretul: ");
            scanf("%f",&p->pret);
    d=push(p);
    while(top!=NULL)
    {
        p=pop();
        printf("De creat fiul stang al nodului %s ? (1/0): ",p->denumire);
        scanf("%d", &f);
        if(f!=0)
        {
            s=(Cinematograf*)malloc(sizeof(*s));
            if(s==NULL)
            {
                printf("\tERROR! Fiul stang nu a fost creat! ");
                return -1;
            }
            p->st=s;
            printf("\n\tDenumirea: ");
            scanf("%s",&s->denumire);
            printf("\tAdresa: ");
            scanf("%s",&s->adresa);
            printf("\tTelefonul: ");
            scanf("%d",&s->telefon);
            printf("\tNm da locuri: ");
            scanf("%d",&s->locuri);
            printf("\tPretul: ");
            scanf("%f",&s->pret);
            d=push(s);
        }
        else
        {
            p->st=NULL;
        }

        printf("De creat fiul drept al nodului %s ? (1/0): ", p->denumire);
        scanf("%d", &f);
        if(f!=0)
        {
            s=(Cinematograf*)malloc(sizeof(*s));
            if(s==NULL)
            {
                printf("\tERROR! Fiul drept nu a fost creat! ");
                return -1;
            }
            p->dr=s;
            printf("\n\tDenumirea: ");
            scanf("%s",&s->denumire);
            printf("\tAdresa: ");
            scanf("%s",&s->adresa);
            printf("\tTelefonul: ");
            scanf("%d",&s->telefon);
            printf("\tNm da locuri: ");
            scanf("%d",&s->locuri);
            printf("\tPretul: ");
            scanf("%f",&s->pret);
            d=push(s);
        }
        else
        {
            p->dr=NULL;
        }
    }

    return 1;
}

int afisarearboreS()
{
    Cinematograf *c,*p;
    top=NULL;
    int a;
    a=push(root);
    if (a==0)
    {
        printf("\n\tArborele nu exista! \n");
    }
    printf("\nInformatia despre nodurile arborelui\n");
    while(top!=NULL)
    {
        printf("\n");
        c=pop();
        printf("\nDenumirea: %s",c->denumire);
        printf("\nAdresa: %s",c->adresa);
        printf("\nTelefonul: %d",c->telefon);
        printf("\nNr de locuri: %d",c->locuri);
        printf("\nPretul: %f",c->pret);
        printf("\nAdresa curenta %d ",c);
        printf("\nAdr urmator pe st %d ",c->st);
        printf("\nAdr urmator pe dr %d ",c->dr);
        p=c->st;
        if (p!=NULL)
        {
            push(p);
        }
        p=c->dr;
        if (p!=NULL)
        {
            push(p);
        }
    }
    return 1;
}

Cinematograf *cautaS(char *den)
{
    Cinematograf *c,*p;
    top=NULL;
    int a;
    a=push(root);
    if (a==0)
    {
        printf("\nArborele nu exista! \n");
        return -1;
    }
    while(top!=NULL)
    {
        c=pop();
        if(strcmp(c->denumire,den)==0)
        {
            printf("\n");
            printf("\nDenumirea: %s",c->denumire);
            printf("\nAdresa: %s",c->adresa);
            printf("\nTelefonul: %d",c->telefon);
            printf("\nNr de locuri: %d",c->locuri);
            printf("\nPretul: %f",c->pret);
            printf("\n\tAdresa curenta %d ",c);
            printf("\n\tAdr urmator pe st %d ",c->st);
            printf("\n\tAdr urmator pe dr %d ",c->dr);
            printf("\n");
            return c;
        }
        p=c->st;
        if (p!=NULL)
        {
            push(p);
        }
        p=c->dr;
        if (p!=NULL)
        {
            push(p);
        }
    }
    return NULL;
}

void modifiS(char *den)
{
    Cinematograf *c;
    c=cautaS(den);
    if (c!=NULL)
    {
        int f;
        printf("\n\tDoriti sa modificati denumirea? (1/0): ");
        scanf("%d", &f);
        if(f>0)
        {
            printf("\n\tIntroduceti noua denumire: ");
            scanf("%s",&c->denumire);
        }
        printf("\n\tDoriti sa modificati adresa? (1/0): ");
        scanf("%d", &f);
        if(f>0)
        {
            printf("\n\tIntroduceti noua adresa: ");
            scanf("%s",&c->adresa);
        }
        printf("\n\tDoriti sa modificati telefonul? (1/0): ");
        scanf("%d", &f);
        if(f>0)
        {
            printf("\n\tIntroduceti noul telefon: ");
            scanf("%d",&c->telefon);
        }
        printf("\n\tDoriti sa modificati locurile? (1/0): ");
        scanf("%d", &f);
        if(f>0)
        {
            printf("\n\tIntroduceti noul numar de locuri?: ");
            scanf("%d",&c->locuri);
        }
        printf("\n\tDoriti sa modificati pretul? (1/0): ");
        scanf("%d", &f);
        if(f>0)
        {
            printf("\n\tIntroduceti noul pret: ");
            scanf("%f",&c->pret);
        }
    }
    else
    {
        printf("\n\tNu a fost gasit asa cinematograf! \n");
    }
}

int nr_de_nodS()
{
    int cont=0;
    Cinematograf *c,*p;
    top=NULL;
    int a;
    a=push(root);
    if (a==0)
    {
        printf("\n\tArborele nu exista! \n");
    }
    while(top!=NULL)
    {
        printf("\n");
        c=pop();
        cont++;
        p=c->st;
        if (p!=NULL)
        {
            push(p);
        }
        p=c->dr;
        if (p!=NULL)
        {
            push(p);
        }
    }
    return cont;
}

int inaltimeaS(Cinematograf *p)
{
    if (p)
    {
        int inst=inaltimeaS(p->st);
        int indr=inaltimeaS(p->dr);
        int max;
        if (inst>indr)
        {
            max=inst;
        }
        else
        {
            max=indr;
        }
        max++;
        return max;
    }
    else
    {
        return 0;
    }
}

void elibs()
{
    Cinematograf *c,*p;
    top=NULL;
    int a;
    a=inq(root);
    if (a==0)
    {
        printf("\n\tArborele nu exista! \n");
    }
    while(top!=NULL)
    {
        c=pop();
        p=c->st;
        if (p!=NULL)
        {
            push(p);
        }
        p=c->dr;
        if (p!=NULL)
        {
            push(p);
        }
        free(c);
    }
    printf("\n\tMemoria a fost eliberata! \n");
}
