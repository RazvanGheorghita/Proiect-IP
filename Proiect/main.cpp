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
void derivare(arbore ai, arbore& ad)
{
    arbore a,b,c,d,e,f,g;
    ad=new nodarb;
    ad->info=' ';
    ad->st=NULL;
    ad->dr=NULL;
    switch(ai->info)
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
        {
            ad->info='0';
            break;
        }
    case 'x':
        {
            ad->info='1';
            break;
        }
    case '+':
        {
            derivare(ai->st,a);
            ad->st=a;
            derivare(ai->dr,b);
            ad->dr=b;
            ad->info='+';
            break;
        }
    case '-':
        {
            derivare(ai->st,a);
            ad->st=a;
            derivare(ai->dr,b);
            ad->dr=b;
            ad->info='-';
            break;
        }
    case '*':
        {
            a=new nodarb;
            b=new nodarb;
            derivare(ai->st,c);
            derivare(ai->dr,d);
            ad->info='+';
            a->info='*';
            a->st=c;
            a->dr=ai->dr;
            b->info='*';
            b->st=ai->st;
            b->dr=d;
            ad->st=a;
            ad->dr=b;
            break;
        }
    case '/':
        {
            a=new nodarb;
            b=new nodarb;
            c=new nodarb;
            derivare(ai->st,d);
            derivare(ai->dr,e);
            a->info='*';
            a->st=d;
            a->dr=ai->dr;
            b->info='*';
            b->st=ai->st;
            b->dr=e;
            c->info='-';
            c->st=a;
            c->dr=b;
            f=new nodarb;
            g=new nodarb;
            f->info='2';
            f->st=NULL;
            f->dr=NULL;
            g->info='^';
            g->st=ai->dr;
            g->dr=f;
            ad->info='/';
            ad->st=c;
            ad->dr=g;
            break;
        }
    case '^':
        {
            derivare(ai->st,a);
            b=new nodarb;
            c=new nodarb;
            b->info='1';
            b->st=NULL;
            b->dr=NULL;
            c->info='-';
            c->st=ai->dr;
            c->dr=b;
            d=new nodarb;
            d->info='^';
            d->st=ai->st;
            d->dr=c;
            e=new nodarb;
            e->info='*';
            e->st=ai->dr;
            e->dr=d;
            ad->info='*';
            ad->st=e;
            ad->dr=a;
            break;
        }
    case 'e':
        {
            a=new nodarb;
            a->info=ai->info;
            a->st=ai->st;
            a->dr=ai->dr;
            derivare(ai->st,b);
            ad->info='*';
            ad->st=a;
            ad->dr=b;
            break;
        }
    case 'l':
        {
            derivare(ai->st,a);
            ad->info='/';
            ad->st=a;
            ad->dr=ai->st;
            break;
        }
    case 's':
        {
            a=new nodarb;
            a->info='c';
            a->st=ai->st;
            a->dr=NULL;
            derivare(ai->st,b);
            ad->info='*';
            ad->st=a;
            ad->dr=b;
        }
    case 'c':
    {
        derivare(ai->st,a);
        b=new nodarb;
        c=new nodarb;
        d=new nodarb;
        b->info='0';
        b->st=NULL;
        b->dr=NULL;
        c->info='s';
        c->st=ai->st;
        c->dr=NULL;
        d->info='*';
        d->st=c;
        d->dr=a;
        ad->info='-';
        ad->st=b;
        ad->dr=d;
        break;
    }
    };
}

int main()
{
    arbore arb,arbd;
    initArbore(arb);
    adaugaLaArboreElement(arb,'+');
    adaugaLaArboreElement(arb->st,'*');
    adaugaLaArboreElement(arb->st->st,'+');
    adaugaLaArboreElement(arb->st->st->st,'x');
    adaugaLaArboreElement(arb->st->st->dr,'0');
    adaugaLaArboreElement(arb->st->dr,'+');
    adaugaLaArboreElement(arb->st->dr->st,'x');
    adaugaLaArboreElement(arb->st->dr->dr,'0');
    adaugaLaArboreElement(arb->dr,'*');
    adaugaLaArboreElement(arb->dr->st,'+');
    adaugaLaArboreElement(arb->dr->st->st,'x');
    adaugaLaArboreElement(arb->dr->st->dr,'0');
    adaugaLaArboreElement(arb->dr->dr,'+');
    adaugaLaArboreElement(arb->dr->dr->st,'x');
    adaugaLaArboreElement(arb->dr->dr->dr,'0');
    cout<<"Functia data este: ";
    parcurgereInordine(arb);
    cout<<endl;
    cout<<"Derivata sa este: ";
    derivare(arb,arbd);
    parcurgereInordine(arbd);
    cout<<endl;
    return 0;
}
