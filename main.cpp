#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string.h>
#include<limits>
using namespace std;

struct abonat
{
    string nume;
    string prenume;
    string strada;
    int nr;
    string nr_telefon;
    string facultate;
    int nr_birou;
    string adresa_mail;

} R[50];
int main()
{
    int it=0,x,i,j,k,auxiliar;
    string nume1[50];
    int dim1[50];
    bool done = false;
    string argument1,argument2;
    ifstream file1("abonati.txt");
    while(!file1.eof())
    {
        file1>>R[it].nume;
        file1>>R[it].prenume;
        file1>>R[it].strada;
        file1>>R[it].nr;
        file1>>R[it].nr_telefon;
        file1>>R[it].facultate;
        file1>>R[it].nr_birou;
        file1>>R[it].adresa_mail;

        it++;
    }


    do
    {
        cout<<"1.Pentru a afisa lista abonatilor apasati tasta 1 \n";
        cout<<"2.Pentru a adauga un abonat nou apasati tasta 2 \n";
        cout<<"3.Pentru a sterge un abonat tasta 3 \n";
        cout<<"4.Pentru a cauta un abonat dupa nume sau nr_telefon intr-un birou sau facultate apasati tasta 4  \n";
        cout<<"5.Pentru a sorta abonatii dupa nume pe facultati/birouri apasati tasta 5 \n";
        cout<<"6.Pentru a afisa lista cd-urilor ordonate crescator dupa dimensiune apasati tasta 6 \n";
        cout<<"7.Pentru a afisa cd-urile cu sesiuni deschise apasati tasta 7 \n";
        cout<<"8.Pentru a clasa cd-urile dupa viteza de inscriptionare apasati tasta 8 \n";
        cout<<"9.Pentru a clasa cd-urile dupa tipul de cd apasati tasta 9 \n";
        cout<<"0.Pentru a iesi apasati tasta 0 \n";
        cin>>x;

        //IN CAZ DE EROARE
        if(cin.fail())   // NU S-A INTRODUS O CIFRA
        {
            cin.clear(); // SE GOLESC PARAMETRII LOCALI
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // IGNORA BUFFER-UL
        }

        switch(x)
        {
        case 1:
            cout<<"Lista abonatilor este urmatoare: \n";
            for(i=0; i<it; i++)
            {
                cout<<"\n\tAbonat: "<<R[i].nume<<" "<<R[i].prenume<<"\n\tAdresa: Str."<<R[i].strada<<" Nr."<<R[i].nr<<"\n\tNr Telefon: "<<R[i].nr_telefon<<"\n\tFacultatea: "<<R[i].facultate<<" Nr Birou: "<<R[i].nr_birou<<"\n\tAdresa mail: "<<R[i].adresa_mail<<endl;

            }

            break;

        case 2:
        {
            ofstream file2;
            file2.open("abonati.txt", std::ios_base::trunc);

            cout<<"Nume: ";
            cin>>R[it].nume;
            cout<<"Prenume: ";
            cin>>R[it].prenume;
            cout<<"Strada: ";
            cin>>R[it].strada;
            cout<<"Numarul: ";
            cin>>R[it].nr;
            cout<<"Numarul de telefon: ";
            cin>>R[it].nr_telefon;
            cout<<"Facultatea(cu underscore in caz ca sunt mai multe nume): ";
            cin>>R[it].facultate;
            cout<<"Numarul biroului: ";
            cin>>R[it].nr_birou;
            cout<<"Adresa mail: ";
            cin>>R[it].adresa_mail;
            it++;

            for(i=0; i<it-1; i++)
            {
                file2<<R[i].nume<<" "<<R[i].prenume<<" "<<R[i].strada<<" "<<R[i].nr<<" "<<R[i].nr_telefon<<" "<<R[i].facultate<<" "<<R[i].nr_birou<<" "<<R[i].adresa_mail<<endl;
            }
            file2<<R[i].nume<<" "<<R[i].prenume<<" "<<R[i].strada<<" "<<R[i].nr<<" "<<R[i].nr_telefon<<" "<<R[i].facultate<<" "<<R[i].nr_birou<<" "<<R[i].adresa_mail;
            file2.close();
        }
        break;

        case 3:
        {
            cout<<"Numele abonatului(cu initiala litera mare): ";
            cin>>argument1;
            cout<<"Prenumele abonatului(cu initiala litera mare): ";
            cin>>argument2;
            for(i=0; i<it; i++)
            {
                std::size_t found1=R[i].nume.find(argument1);
                std::size_t found2=R[i].prenume.find(argument2);
                if(found1!=std::string::npos && found2!=std::string::npos)
                {
                    for(j=i; j<it-1; j++)
                    {
                        R[j].nume=R[j+1].nume;
                        R[j].prenume=R[j+1].prenume;
                        R[j].strada=R[j+1].strada;
                        R[j].nr=R[j+1].nr;
                        R[j].nr_telefon=R[j+1].nr_telefon;
                        R[j].facultate=R[j+1].facultate;
                        R[j].nr_birou=R[j+1].nr_birou;
                        R[j].adresa_mail=R[j+1].adresa_mail;
                    }
                    it--;
                }
            }
            cout<<"\n\nAbonat sters!";
            ofstream file2;
            file2.open("abonati.txt", std::ios_base::trunc);
            for(i=0; i<it-1; i++)
            {
                file2<<R[i].nume<<" "<<R[i].prenume<<" "<<R[i].strada<<" "<<R[i].nr<<" "<<R[i].nr_telefon<<" "<<R[i].facultate<<" "<<R[i].nr_birou<<" "<<R[i].adresa_mail<<endl;
            }
            file2<<R[i].nume<<" "<<R[i].prenume<<" "<<R[i].strada<<" "<<R[i].nr<<" "<<R[i].nr_telefon<<" "<<R[i].facultate<<" "<<R[i].nr_birou<<" "<<R[i].adresa_mail;
            file2.close();
            break;

        }
        break;

        case 4:
        {

            cout<<"Numele abonatului(cu initiala litera mare) sau nr de telefon: ";
            cin>>argument1;
            cout<<"Numar birou sau numele facultatii(Case Sensitive): ";
            cin>>argument2;
            for(i=0; i<it; i++)
            {
                if((R[i].nume==argument1 || R[i].nr_telefon==argument1) && (R[i].nr_birou==atoi(argument2.c_str()) || R[i].facultate==argument2) )
                {
                    cout<<"\n\tAbonat: "<<R[i].nume<<" "<<R[i].prenume<<"\n\tAdresa: Str."<<R[i].strada<<" Nr."<<R[i].nr<<"\n\tNr Telefon: "<<R[i].nr_telefon<<"\n\tFacultatea: "<<R[i].facultate<<" Nr Birou: "<<R[i].nr_birou<<"\n\tAdresa mail: "<<R[i].adresa_mail<<endl;
                }
            }
            break;
        }

        /*case 5:
        {

            cout<<"Introduceti spatiul minim liber: ";
            cin>>argument;
            for(i=0; i<it; i++)
            {
                if((R[i].dimensiuneCD-R[i].spatiuOcupat)>argument)
                {
                    cout<<"\n\tIdentificator CD: "<<R[i].cod<<"\n\tDenumire: "<<R[i].numeCD<<"\n\tDimensiune maxima: "<<R[i].dimensiuneCD<<" Viteza inscriptionare: "<<R[i].viteza_maxima<<" Spatiul ocupat: "<<R[i].spatiuOcupat<<"\n\tNr sesiuni: "<<R[i].nr_sesiuni<<" Tipul de sesiune: "<<R[i].tip_sesiune<<endl;
                }
            }
            break;
        }

        case 6:
        {
            cout<<"Lista cd-urilor sortate crescator dupa dimensiune:"<<endl;
            for(i=0; i<it; i++)
            {
                dim1[i]=R[i].dimensiuneCD;
                cduri1[i]=R[i].numeCD;
            }

            for(i=0; i<it; i++)
            {
                for(j=i+1; j<it; j++)
                {
                    if(dim1[j]>dim1[i])
                    {
                        int aux;
                        aux=dim1[i];
                        dim1[i]=dim1[j];
                        dim1[j]=aux;

                        string aux2;
                        aux2=cduri1[i];
                        cduri1[i]=cduri1[j];
                        cduri1[j]=aux2;
                    }
                }
            }
            for(i=0; i<it; i++)
            {
                for(j=0; j<it; j++)
                    if(dim1[i]==R[j].dimensiuneCD && cduri1[i]==R[j].numeCD)
                    {
                        cout<<"\n\tIdentificator CD: "<<R[j].cod<<"\n\tDenumire: "<<R[j].numeCD<<"\n\tDimensiune maxima: "<<R[j].dimensiuneCD<<" Viteza inscriptionare: "<<R[j].viteza_maxima<<" Spatiul ocupat: "<<R[j].spatiuOcupat<<"\n\tNr sesiuni: "<<R[j].nr_sesiuni<<" Tipul de sesiune: "<<R[j].tip_sesiune<<endl;

                    }
            }
            break;
        }


        case 7:
        {

            cout<<"CD urile cu sesiuni deschise: ";
            for(i=0; i<it; i++)
            {
                if(R[i].tip_sesiune=="TAO" || R[i].tip_sesiune=="PW")
                {
                    cout<<"\n\tIdentificator CD: "<<R[i].cod<<"\n\tDenumire: "<<R[i].numeCD<<"\n\tDimensiune maxima: "<<R[i].dimensiuneCD<<" Viteza inscriptionare: "<<R[i].viteza_maxima<<" Spatiul ocupat: "<<R[i].spatiuOcupat<<"\n\tNr sesiuni: "<<R[i].nr_sesiuni<<" Tipul de sesiune: "<<R[i].tip_sesiune<<endl;
                }
            }
            break;
        }


        case 8:
        {
            cout<<"Cd-urile cu viteza de inscriptionare de peste 2.4 Mbits/s intra in categoria CD-urilor rapide deoarece timpul scrierii este sub 5 min: ";
            cout<<"\n\nCd-uri rapide:";
            for(i=0; i<it; i++)
            {
                if(R[i].viteza_maxima > 2.4)
                {
                    cout<<"\n\tIdentificator CD: "<<R[i].cod<<"\n\tDenumire: "<<R[i].numeCD<<"\n\tDimensiune maxima: "<<R[i].dimensiuneCD<<" Viteza inscriptionare: "<<R[i].viteza_maxima<<" Spatiul ocupat: "<<R[i].spatiuOcupat<<"\n\tNr sesiuni: "<<R[i].nr_sesiuni<<" Tipul de sesiune: "<<R[i].tip_sesiune<<endl;
                }
            }
            cout<<"\nCd-uri lente:";
            for(i=0; i<it; i++)
            {
                if(R[i].viteza_maxima < 2.4)
                {
                    cout<<"\n\tIdentificator CD: "<<R[i].cod<<"\n\tDenumire: "<<R[i].numeCD<<"\n\tDimensiune maxima: "<<R[i].dimensiuneCD<<" Viteza inscriptionare: "<<R[i].viteza_maxima<<" Spatiul ocupat: "<<R[i].spatiuOcupat<<"\n\tNr sesiuni: "<<R[i].nr_sesiuni<<" Tipul de sesiune: "<<R[i].tip_sesiune<<endl;
                }
            }
            break;
        }

        case 9:
        {
            cout<<"\n\nCD-uri: ";
            for(i=0; i<it; i++)
            {
                if(R[i].viteza_maxima==float(1.2))
                {
                    cout<<"\n\tIdentificator CD: "<<R[i].cod<<"\n\tDenumire: "<<R[i].numeCD<<"\n\tDimensiune maxima: "<<R[i].dimensiuneCD<<" Viteza inscriptionare: "<<R[i].viteza_maxima<<" Spatiul ocupat: "<<R[i].spatiuOcupat<<"\n\tNr sesiuni: "<<R[i].nr_sesiuni<<" Tipul de sesiune: "<<R[i].tip_sesiune<<endl;
                }
            }
            cout<<"\nDVD-uri: ";
            for(i=0; i<it; i++)
            {
                if(R[i].viteza_maxima==float(1.32))
                {
                    cout<<"\n\tIdentificator CD: "<<R[i].cod<<"\n\tDenumire: "<<R[i].numeCD<<"\n\tDimensiune maxima: "<<R[i].dimensiuneCD<<" Viteza inscriptionare: "<<R[i].viteza_maxima<<" Spatiul ocupat: "<<R[i].spatiuOcupat<<"\n\tNr sesiuni: "<<R[i].nr_sesiuni<<" Tipul de sesiune: "<<R[i].tip_sesiune<<endl;
                }
            }
            cout<<"\nBlueRay-uri: ";
            for(i=0; i<it; i++)
            {
                if(R[i].viteza_maxima==float(4.29))
                {
                    cout<<"\n\tIdentificator CD: "<<R[i].cod<<"\n\tDenumire: "<<R[i].numeCD<<"\n\tDimensiune maxima: "<<R[i].dimensiuneCD<<" Viteza inscriptionare: "<<R[i].viteza_maxima<<" Spatiul ocupat: "<<R[i].spatiuOcupat<<"\n\tNr sesiuni: "<<R[i].nr_sesiuni<<" Tipul de sesiune: "<<R[i].tip_sesiune<<endl;
                }
            }
            break;
        }*/

        case 0:
            cout<<"La revedere!";
            done=true;
            break;

        }
        cout<<"\n";
    }
    while(!done);

    return 0;
}

