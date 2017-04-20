
#include <iostream>

using namespace std;


void kysy_luvut(int *luku1, int *luku2)
{
    cout<<"Anna ensimmäinen luku>";
    cin>>*luku1;
    cout<<endl<<"Anna toinen luku>";
    cin>>*luku2;
}




void laske(int luku1, int luku2, int *pVastaus)
{
    *pVastaus = luku1 + luku2;
}


void tulosta( int luku1, int luku2, int vastaus)
{
      cout<<"Luku 1 on "<<luku1<<endl
        <<"Luku 2 on "<<luku2<<endl
        <<"Yhteenlaskettuna "<<vastaus<<endl;
}


void lisaa_osoitinta( int **osoitin)
{
 // **osoitin = **osoitin + 1;
}

int main()
{
    int *osoitin = 0;

    int  vastaus ;
    int luku1, luku2;
    luku1 = 5;
    luku2 = 4;

  // lisaa_osoitinta(&osoitin);
     kysy_luvut(&luku1, &luku2);
     laske(luku1, luku2, &vastaus);
     tulosta(luku1,luku2,vastaus);

     cout<<endl<<"Osoittimen arvo on "<<osoitin;
//    pOsoitin = &luku1 ;
//    *pOsoitin = 5;
//    pOsoitin = &luku2;
//    *pOsoitin = 4;

//    cout<<"Luku 1 on "<<luku1<<endl
//        <<"Luku 2 on "<<luku2<<endl
//        <<"Yhteenlaskettuna "<<pVastaus<<endl;
    return 0;
}
