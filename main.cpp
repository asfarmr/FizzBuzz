//GOMEZ MATIAS & MOHAMED RAFFIQUE ASFAR 1G
#include <iostream>
#include<string>
#include <cstdlib>
#include <cstdio>
using namespace std;

int main()
{
    string prenom;                  //nom de joueur qui sera saisie par l'utilisateur
    string nomPC="Ordinateur";      //nom qui apparaitra lorsque l'ordinateur jouera
    int MAX;                        //nombre Maximum qui sera saisie par le joueur
    int MIN;                        //nombre minimum qui sera saisie par le joueur
    int depart;                     //variable qui nous permettra de savoir qui de l'ordinateur ou du joueur commencera à jouer
    int i;
    int nbVie=3;                    //nombre de vie du joueur de depart (3 au total)
    char rejouer='o';               //variable de depart pour rejouer

    string valeurJEU;               //variable pour conversion
    char tab[250];

    bool mult3;                     //booléen pour les multiple de 3
    bool mult5;                     //booléen pour les multiple de 5
    bool tourOrdi;

    while(rejouer=='o')
    {
    cout << "Viens on joue !\n" << endl;            //Premier message afficher
    cout<<"Comment t'appelles-tu ?"<<endl;          //On demande le prenom à l'utilsateur
    cin>>prenom;                                    //Saisie du prenom par l'utilsateur

    //On demande de quel nombre à quel nombre l'ordianteur et le joueur joueront
    cout<<"Donne moi la valeur minimale et maximale dans laquelles nous jouerons."<<endl;
    cout<<"MIN= ";
    cin>>MIN;                                       //Saisie du minimum (du nombre de depart par l'utilsateur)
    cout<<"MAX= ";
    cin>>MAX;                                       //Saisie du maximum (du dernier nombre à saisir dans le jeu)

    /*Tant que l'utilisateur ne saisie pas un minimum ou un maximum
    strictement positive, ou que le maximum n'est pas superieur au minimum faire...*/
    while(MAX<=0 || MIN<=0 || MIN>MAX)
    {
        //Si il n'a pas saisie un maximum strictement positive demander à l'utilisateur de le faire
        if(MAX<=0)
        {
            cout<<"Assurez vous que le maximum soit positive"<<endl;
            cin>>MAX;
        }
        //Si il n'a pas saisie un minimum strictement positive demander à l'utilisateur de le faire
        if(MIN<=0)
        {
            cout<<"Assurez vous que le minimum soit positive"<<endl;
            cin>>MIN;
        }
        //Si il n'a pas saisie un maximum superieur au minimum demander à l'utilisateur de le faire
        if(MIN>MAX)
        {
            cout<<"Assurez vous que le maximum soit superieur au minimum SVP."<<endl;
            cout<<"MIN= ";
            cin>>MIN;
            cout<<"MAX= ";
            cin>>MAX;
        }
    }

    //On demande qui de l'ordinateur ou du joueur sera le premier à jouer
    cout<<"Je commence ou tu commences ?\n Si c'est moi qui commence tape '0' \n Si c'est toi qui commences tape '1'"<<endl;
    cin>>depart;            //saisie par l'utilsateur

    //Tant que l'utilsateur n'a pas taper '0' ou '1' pour faire son choix...
    while((depart!=0) && (depart!=1))
    {
        //Redemander à l'utilsateur de taper '0' ou '1' pour faire son choix
        cout<<"J'AI DIS !!! Si c'est moi qui commence tape '0' \n Si c'est toi qui commences tape '1'"<<endl;
        cin>>depart;        //Saisie par l'utilisateur
    }

    tourOrdi= depart==0;    //On affecte la valeur '0' qui veux dire que l'ordinateur commence

    if(tourOrdi)            //Si l'ordinateur commence...
        cout<<"OK ! Alors je commence."<<endl;      //Ecrire message
    else                    //Dans le cas contraire...
        cout<<"Super! Alors tu commences."<<endl;   //Ecrire message

    i=MIN;                  //On affecte la valeur minimal à i

    while(i<=MAX)           //Tant que i est inferieur ou égal au maximum entré
    {
        mult3= i%3 == 0;    //le booleen mult3 est vrai dans le cas où i est divisible par 3
        mult5= i%5 == 0;    //le booleen mult5 est vrai dans le cas où i est divisible par 5

        if(tourOrdi)        //Si c'est le tour de l'Ordianteur faire...
        {
            if(mult3 && mult5)      //Si le nombre i actuel est divisible par 3 et 5...
            {
                cout<<nomPC<<"> FizzBuzz"<<endl;    //Afficher "Ordinateur> FizzBuzz
            }
            else if(mult3)          //Si le nombre i actuel est divisible par 3...
            {
                cout<<nomPC<<"> Fizz"<<endl;        //Afficher "Ordinateur> Fizz
            }
            else if(mult5)                          //Si le nombre i actuel est divisible par 5...
            {
                cout<<nomPC<<"> Buzz"<<endl;        //Afficher "Ordinateur> Buzz
            }
            else                                    //Si aucun des conditions precedentes ne sont presentes

                cout<<nomPC<<"> "<<i<<endl;         //Afficher "Ordianteur> (nombre i actuel de cette boucle)
        }
        else            //Si c'est le tour de l'utilisateur faire...
        {
            cout<<prenom<<"("<<nbVie<<" vies)"<<" > ";      //Afficher "prenom de l'utilisateur (nombre de vie)>"
            cin>>valeurJEU;                                 //Saisie de ma valeur que l'utilsateur pense etre la bonne


            //Si le nombre i actuel est divisible par 3 et 5 et que la valeur rentrer par l'utilsateur est differrente de "FizzBuzz" faire...
            if((mult3 && mult5) && valeurJEU!="FizzBuzz")
            {
                cout<<"ERREUR la reponse etait FizzBuzz"<<endl;     //Afficher que l'utilisateur s'est trompé
                nbVie=nbVie-1;                                      //Et enlever une vie
            }
            //Si le nombre i actuel est divisible par 3 et que la valeur rentrer par l'utilsateur est differrente de "Fizz" faire...
            else if(mult3 && valeurJEU!="Fizz")
            {
                cout<<"ERREUR la reponse etait Fizz"<<endl;         //Afficher que l'utilisateur s'est trompé
                nbVie=nbVie-1;                                      //Et enlever une vie
            }
            //Si le nombre i actuel est divisible par 5 et que la valeur rentrer par l'utilsateur est differrente de "Buzz" faire...
            else if(mult5 && valeurJEU!="Buzz")
            {
                cout<<"ERREUR la reponse etait Buzz"<<endl;         //Afficher que l'utilisateur s'est trompé
                nbVie=nbVie-1;                                      //Et enlever une vie
            }

            else if(!(mult3 || mult5))               //Si les conditions precedentes ne sont pas remplis faire, et que le nombre i actuel n'est pas divisible par 3 ou 5 ni les deux
            {
                sprintf(tab,"%d",i);                //conversion de int vers string et envoie le resultat dans tab
                if(valeurJEU!=tab)                  //Si la valeur entrer par l'utilisateur est differente du nombre i de cette boucle
                {
                    cout<<"ERREUR la reponse etait "<<i<<endl;      //Afficher que l'utilisateur s'est trompé
                    nbVie=nbVie-1;                                  //Et enlever une vie
                }
            }
            if(nbVie==0)                            //Lorsque le nombre de vie du joueur tombe à 0...
            {
                cout<<"Defaite :("<<endl;           //Ecrire que l'utilisateur vien de perdre
                i=MAX;                              //Et affecter la valeur MAX à i pour ainsi sortir de la boucle
            }
        }
        i=i+1;                                      //Lorsque l'ordinateur ou le joueur a finis son tour rajouter i+1 à la variable i
        tourOrdi= !tourOrdi;                        //Affecter un NON(Ordinateur) pour que ce soit maintenant le tour de l'utilsateur ou de l'ordinateur (selon qui commence)
    }

        if(nbVie>0)         //Une fois i==MAX on sort de cette boucle, ce qui veut dire que le Joueur a fini la partie sans perdre toutes ses vies
        {
            cout<<"\nVictoire :)\n"<<endl;      //Afficher la victoire du joueur
        }

        cout<<"C'etait chouette on rejoue ? (o/n)"<<endl;   //On demande si le joueur veux rejouer et de repondre par 'o' pour oui ou par 'n' pour non
        cin>>rejouer;                                       //Saisie de la reponse par le joueur

        while(rejouer!='o' && rejouer!='n')                 //Tant que l'utilisateur n'a pas reponsu par 'o' ou par 'n' faire...
        {
            cout<<"Veillez a repondre par 'o' pour oui ou 'n' pour non, merci."<<endl;      //Demander a saisir correctement par 'o' ou 'n' sa reponse
            cin>>rejouer;       //Saisie de la reponse de l'utilsateur

        }
        //Si il a repondu 'o' pour rejouer alors la boucle continue pas besoin de mettre de condition

        if(rejouer=='n')        //Si l'utilisateur a repondu 'n' pour ne pas rejouer...
        {
            rejouer='n';        //On change la valeur de la variable rejouer par 'n', ce qui termine la boucle
        }
    }
    cout<<"\nA la prochaine :)"<<endl;      //Et pour finir on dit au revoir au joueur
    return 0;                   //Le programme ce termine
}
