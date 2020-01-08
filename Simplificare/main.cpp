#include <iostream>
using namespace std;

struct nodarb {
    unsigned char info;
    struct nodarb* st; struct nodarb* dr;
};
typedef nodarb* arbore;
int esteArboreNul(arbore a)
{
   if(a==NULL)
    return 1;
   else
    return 0;
}
void initArbore(arbore& a)
{
   if (!esteArboreNul(a)) a=NULL;
}
void parcurgereInordine(arbore a)
{
    if(!esteArboreNul(a))
    {
        parcurgereInordine(a->st);
        cout<<a->info;
        parcurgereInordine(a->dr);
    }
}
bool adaugaLaArboreElement(arbore& a, unsigned char el) {
    if (esteArboreNul(a)) {
        a=new nodarb;
        if (!a) return false;
        a->info = el; a->st = NULL; a->dr = NULL;
        return true;
    }
    else if (el < a->info)
        return adaugaLaArboreElement(a->st, el);
    else
        return adaugaLaArboreElement(a->dr, el);
}
void Simplificare(arbore arbi,arbore& arbs)
{
    arbore numar;
    numar=new nodarb;
    numar->info='n';
    numar->st=NULL;
    numar->dr=NULL;
    arbs=new nodarb;
    arbs->st=NULL;
    arbs->dr=NULL;
    switch(arbi->info)
    {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
        case 'x':
        {
            arbs=arbi;
            break;
        }
        case '+':
            {
                if((arbi->st->info=='0')||(arbi->st==NULL))
                {
                    arbs=arbi->dr;
                }
                else
                if((arbi->dr->info=='0')||(arbi->dr==NULL))
                {
                    arbs=arbi->st;
                }
                else
                if(arbi->st->info==arbi->dr->info)
                {
                    numar->info='2';
                    arbs->info='*';
                    arbs->st=numar;
                    arbs->dr=arbi->dr;
                }
                else
                arbs=arbi;
                break;
            }
        case '-':
            {
                if((arbi->st->info=='0')||(arbi->st==NULL))
                {
                    arbs=arbi->dr;
                }
                else
                if((arbi->dr->info=='0')||(arbi->dr==NULL))
                {
                    arbs=arbi->st;
                }
                else
                if(arbi->st->info==arbi->dr->info)
                {
                    numar->info='0';
                    arbs->info='*';
                    arbs->st=numar;
                    arbs->dr=arbi->dr;
                }
                arbs=arbi;
                break;
            }
        case '*':
            {
                if((arbi->st->info=='0')||(arbi->dr->info=='0'))
                    {
                        numar->info='0';
                        arbs=numar;
                    }
                else
                if(arbi->st->info=='1')
                {
                    arbs=arbi->dr;
                }
                else
                if(arbi->dr->info=='1')
                {
                    arbs=arbi->st;
                }
                else
                if(arbi->st->info==arbi->dr->info)
                {
                    numar->info='2';
                    arbs->info='^';
                    arbs->dr=numar;
                    arbs->st=arbi->st;
                }
                arbs=arbi;
                break;
            }
        case '/':
            {
                if(arbi->dr->info=='1')
                {
                    arbs=arbi->st;
                }
                else
                if(arbi->dr->info=='0')
                {
                    numar->info='!';
                    arbs=numar;
                }
                else
                if(arbi->st->info==arbi->dr->info)
                {
                    numar->info='1';
                    arbs=numar;
                }
                else
                arbs=arbi;
                break;
            }
        case '^':
            {
                if(arbi->dr->info=='0')
                {
                    numar->info='1';
                    arbs=numar;
                }
                else
                if(arbi->dr->info=='1')
                {
                    arbs=arbi->st;
                }
                else
                arbs=arbi;
                break;
            }
        case 'l':
            {
                if(arbi->st->info=='1')
                {
                    numar->info='0';
                    arbs=numar;
                }
                else
                if(arbi->st->info=='e')
                {
                    numar->info='1';
                    arbs=numar;
                }
                else
                arbs=arbi;
                break;
            }
        case 's':
            {
                if(arbi->st->info=='0')
                {
                    numar->info='0';
                    arbs=numar;
                }
                else
                if((arbi->st->info=='/')&&(arbi->st->st->info='p'))
                {
                    if(arbi->st->dr->info=='6')
                    {
                        numar->info='/';
                        adaugaLaArboreElement(numar->st,'1');
                        adaugaLaArboreElement(numar->dr,'2');
                        arbs=numar;
                    }
                    else
                    if(arbi->st->dr->info=='4')
                    {
                        numar->info='/';
                        adaugaLaArboreElement(numar->st,'r');
                        adaugaLaArboreElement(numar->st->st,'2');
                        adaugaLaArboreElement(numar->dr,'2');
                        arbs=numar;
                    }
                    else
                    if(arbi->st->dr->info=='3')
                    {
                        numar->info='/';
                        adaugaLaArboreElement(numar->st,'r');
                        adaugaLaArboreElement(numar->st->st,'3');
                        adaugaLaArboreElement(numar->dr,'2');
                        arbs=numar;
                    }
                    else
                    if(arbi->st->dr->info=='2')
                    {
                        numar->info='1';
                        arbs=numar;
                    }
                }

                  break;
            }
        default:    arbs=arbi; break;
    }
}
int main()
{
    arbore arb,arbs,arbs2;
    initArbore(arb);
    initArbore(arbs);
    initArbore(arbs2);
    adaugaLaArboreElement(arb,'s');
    adaugaLaArboreElement(arb->st,'/');
    adaugaLaArboreElement(arb->st->st,'p');
    //adaugaLaArboreElement(arb->st->st->st,'x');
    //adaugaLaArboreElement(arb->st->st->dr,'0');
    adaugaLaArboreElement(arb->st->dr,'2');
   // adaugaLaArboreElement(arb->st->dr->st,'x');
   // adaugaLaArboreElement(arb->st->dr->dr,'0');*/
    // adaugaLaArboreElement(arb->dr,'1');
    /*adaugaLaArboreElement(arb->dr->st,'+');
    adaugaLaArboreElement(arb->dr->st->st,'x');
    adaugaLaArboreElement(arb->dr->st->dr,'0');
    adaugaLaArboreElement(arb->dr->dr,'+');
    adaugaLaArboreElement(arb->dr->dr->st,'x');
    adaugaLaArboreElement(arb->dr->dr->dr,'0');*/
    cout<<"Functia data este: ";
    parcurgereInordine(arb);
    cout<<endl;
    Simplificare(arb,arbs);
    cout<<"Functia simplifacata x1: ";
    parcurgereInordine(arbs);
    cout<<endl;
    Simplificare(arbs,arbs2);
    cout<<"Functia simplificata x2: ";
    parcurgereInordine(arbs2);
    return 0;
}
