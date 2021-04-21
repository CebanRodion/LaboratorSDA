#include <stdio.h>
#include "functii_lab10.c"
int main ()
{
    int p,nr,g,z;
    Cinematograf *f;
    char den[10];
    while (1)
    {
        printf("\n\t\t\t<><><> <MENIU> <><><>\n");
        printf("\nCOADA");
        printf("\t1. Crearea nodurilor arborelui binar oarecare in memoria\n\t   dinamica si introducerea informatiei despre nodurile\n\t   arborelui de la tastatura in mod interactiv.(COADA)");
        printf("\n");
        printf("\t2. Afisarea informatiei despre nodurile arborelui la ecran.");
        printf("\n");
        printf("\t3. Cautarea nodului in arbore");
        printf("\n");
        printf("\t4. Modificarea informatiei unui nod din arbore.");
        printf("\n");
        printf("\t5. Determinarea numarului de noduri.");
        printf("\n");
        printf("\t6. Determinarea inaltimii arborelui.");
        printf("\n");
        printf("\t7. Eliberarea memoriei alocate pentru arbore.");
        printf("\n");
        printf("\nSTIVA");
        printf("\t8. Crearea nodurilor arborelui binar oarecare in memoria\n\t   dinamica si introducerea informatiei despre nodurile\n\t   arborelui de la tastatura in mod interactiv.(STIVA)");
        printf("\n");
        printf("\t9. Afisarea informatiei despre nodurile arborelui la ecran.");
        printf("\n");
        printf("\t10. Cautarea nodului in arbore");
        printf("\n");
        printf("\t11. Modificarea informatiei unui nod din arbore.");
        printf("\n");
        printf("\t12. Determinarea numarului de noduri.");
        printf("\n");
        printf("\t13. Determinarea inaltimii arborelui.");
        printf("\n");
        printf("\t14. Eliberarea memoriei alocate pentru arbore.");
        printf("\n");
        scanf("%d",&nr);
        switch (nr)
        {
        case 1:
            creareC();
            printf("\n");
            break;
        case 2:
            afisarearboreC();
            printf("\n");
            break;
        case 3:
            printf ("\n\tIntroduceti denumirea disciplinei pe care o cautati: ");
            scanf("%s",&den);
            f=cautaC(den);
            if (f==NULL)
            {
                printf("\n\tNu exista o disciplina cu aceasta denumire! ");
            }
            break;
        case 4:
            printf("\n\tIntroduceti denumirea disciplinei pe care doriti sa o modificati: ");
            scanf("%s",&den);
            modifiC(den);
            break;
        case 5:
            g=nr_de_nodC();
            printf("\n\tArborele are %d noduri! ",g);
            break;
        case 6:
            z=inaltimeaC(root);
            printf("\n\tArborele are %d niveluri! ",z);
            break;
        case 7:
            elibq();
            root=NULL;
            break;
        case 8:
            creareS();
            break;
        case 9:
            afisarearboreS();
            break;
        case 10:
            printf ("\n\tIntroduceti denumirea disciplinei pe care o cautati: ");
            scanf("%s",&den);
            f=cautaS(den);
             if (f==NULL)
            {
                printf("\n\tNu exista o disciplina cu aceasta denumire! ");
            }
            break;
        case 11:
            printf("\n\tIntroduceti denumirea disciplinei pe care doriti sa o modificati: ");
            scanf("%s",&den);
            modifiS(den);
            break;
        case 12:
            g=nr_de_nodS();
            printf("\n\tArborele are %d noduri! ",g);
            break;
        case 13:
            z=inaltimeaS(root);
            printf("\n\tArborele are %d niveluri! ",z);
            break;
        case 14:
            elibs();
            root=NULL;
            break;
        default:
            printf("\n\tNu ati ales o optiune din acest meniu!\n");
            break;
        }
    }
    return 0;
}
