/*======================================================
 programme élementaire en C++
 Auteur: Da Cunha Enzo
 Date:../../2022
 version:1.0
========================================================*/

// iostream contient la déclaration des fonctions
// d'entrée/sortie que je vais utiliser
#include <iostream> // entete de gestion des E/S
#include <string>
#include <conio.h>
#include <vector>

using namespace std; // utilisation de l'espace de nommage
                     // de la bibliothéque standard

// Définition d'une structure animal
struct Animal
{
    string ID;
    string sexe;
    string date_naissance;
    int poids;
};

struct acquisition
{
    Animal animal;
    string heure_mesure;
    int interval;
    vector<double> temperature;
};

Animal saisie()
{
    Animal tmp;

    // vide le buffer clavier
    cin.seekg(0, ios::end);
    cin.clear();

    cout << endl;
    cout << "ID ? ";
    getline(cin, tmp.ID);
    cout << "sexe ? ";
    getline(cin, tmp.sexe);
    cout << "date de naissance  (jj/mm/aaaa) ? ";
    getline(cin, tmp.date_naissance);
    cout << "poids en gramme (entier) ? ";
    cin >> tmp.poids;

    // vide le buffer clavier
    cin.seekg(0, ios::end);
    cin.clear();
    return tmp;
}

acquisition saisie2()
{
    cin.seekg(0, ios::end);
    cin.clear();
    acquisition tmp;

    cin.seekg(0, ios::end);
    cin.clear();
    cout << endl;

    cout << "date et heure de mesure sous la forme jj/mm/aaaa hh:mm:ss ? ";
    getline(cin, tmp.heure_mesure);

    char reponse;
    double x;
    do
    {
        cout << "temperature mesurees a 10-2 ? ";
        cin >> x;

        tmp.temperature.push_back(x);

        cout << "Encore une autre temperature ? (o/n) : " << endl;
        cin >> reponse;

    } while (reponse == 'o');

    cout << "interval entre deux mesure  ? ";
    cin >> tmp.interval;

    // vide le buffer clavier
    cin.seekg(0, ios::end);
    cin.clear();
    return tmp;
}

void affichage(const Animal &toto)
{
    cout << "L'animal n " << toto.ID << ", " << toto.sexe << " ne le " << toto.date_naissance << " pesant actuellement " << toto.poids << "g" << endl;
}
void affichage(const acquisition &toto)
{
    cout << "Le " << toto.heure_mesure << ", la temperature de cet animal a ete mesuree toutes les " << toto.interval << " secondes et les temperatures mesurees sont : ";
    for (int i = 0; i < toto.temperature.size(); i++)
        cout << toto.temperature[i] << "\t";

    cout << endl;
}
/*======================================================
Fonction principal
========================================================*/
int main()
{
    vector<double> tmp={37.58 , 37.79 , 38.02 , 38.10 , 38.45 , 28.71} ;
    // code en dessous
    Animal test = {"1234567890", "male", "13/01/2020", 127};
    affichage(test);

    acquisition test4={test ,"30/03/2020 10h:34:15",7, tmp };
    affichage(test4);

    Animal test2;
    test2 = saisie();
    affichage(test2);

    acquisition test3;
    test3 = saisie2();
    affichage(test3);

    
    // Attendons qu'on appui sur une touche pour terminer
    cin.get();
    cin.ignore();

    return EXIT_SUCCESS;
}