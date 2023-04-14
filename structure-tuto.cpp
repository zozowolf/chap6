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

// Définition d'une structure Personne
struct Personne
{
    string nom;
    string prenom;
    string telephone[2];
    int age;
};
struct Etudiant
{
    Personne individu;
    string numeroINE;
    string classe;
};
/*****************************
Fonction de saisie
*****************************/
Personne saisie()
{
    Personne tmp;

    // vide le buffer clavier
    cin.seekg(0, ios::end);
    cin.clear();

    cout << endl;
    cout << "NOM ? ";
    getline(cin, tmp.nom);
    cout << "Prenom ?";
    getline(cin, tmp.prenom);
    cout << "Tel fixe ? ";
    getline(cin, tmp.telephone[0]);
    cout << "Tel portable ? ";
    getline(cin, tmp.telephone[1]);
    cout << "Age : ? ";
    cin >> tmp.age;

    // vide le buffer clavier
    cin.seekg(0, ios::end);
    cin.clear();
    return tmp;
}
/*****************************
Fonction de saisie etudiant
*****************************/
Etudiant saisieEtudiant()
{
    cin.seekg(0, ios::end);
    cin.clear();
    Etudiant tmp;

    tmp.individu = saisie();
    cin.seekg(0, ios::end);
    cin.clear();
    cout << "Numero INE ? ";
    getline(cin, tmp.numeroINE);
    cout << "Classe? ";
    getline(cin, tmp.classe);
    cin.seekg(0, ios::end);
    cin.clear();
    return tmp;
}

/*****************************
Fonction d'affichage
Passage par référence (&) pour éviter de dupliquer la variable lors du passage de paramètre
const permet d'interdire la modification du paramètre
*****************************/
void affichage(const Personne &toto)
{
    // vide le buffer clavier
    cin.seekg(0, ios::end);
    cin.clear();
    cout << endl;
    cout << "NOM : " << toto.nom << endl;
    cout << "Prenom : " << toto.prenom << endl;
    cout << "Tel fixe : " << toto.telephone[0] << endl;
    cout << "Tel portable : " << toto.telephone[1] << endl;
    cout << "Age : " << toto.age << endl;
    // vide le buffer clavier
    cin.seekg(0, ios::end);
    cin.clear();
}

/*****************************
Fonction d'affichage d’un étudiant
Passage par référence (&) pour éviter de dupliquer
la variable lors du passage de paramètre
const permet d'interdire la modification du paramètre
*****************************/
void affichage(const Etudiant &toto)
{
    affichage(toto.individu); // appel de la fonction d'affichage d'un personne
    cout << "INE=" << toto.numeroINE << endl;
    cout << "CLASSE=" << toto.classe << endl;
}
/*======================================================
Fonction principal
========================================================*/
int main()
{
    // code en dessous

    // Déclaration d'une personne test
    Personne test1 = {"DA CUNHA ALVES", "Enzo", {"0787725630", "0601010101"}, 19};
    affichage(test1);

    Personne titi;
    titi = saisie();
    affichage(titi);

    Etudiant test2 = {{"zozo", "wolf", {"0301010101", "0601010101"}, 19}, "1234567890G", "SNIR2"};
    affichage(test2);
    Etudiant test3;
    test3 = saisieEtudiant();
    affichage(test3);


    // Afficher la 3eme lettre du prénom de test1
    cout << "3eme lettre du prenom =" << test1.prenom[2] << endl;

    // Afficher le 4eme chiffre du 2eme numero de telephone de test1
    cout << "4eme chiffre portable : " << test1.telephone[1][3] << endl;

    // ===========================================================================================
    //  Création d'un tableau d'étudiants ; solution du tableau de type C
    // ===========================================================================================
    Etudiant snir1[19];

    // Saisir les 4 premiers etudiants
    for (unsigned i = 0; i < 4; i++)
    {
        cout << endl;
        cout << "Saisie de l'etudiants numero " << i << endl;
        snir1[i] = saisieEtudiant();
    }
    cout << "affichage des etudiants saissis " << endl;
    for (unsigned i = 0; i < 4; i++)
    {
        affichage(snir1[i]);
    }
    // Affichage du prenom du 2e etudiant
    cout << snir1[1].individu.prenom << endl;

    // Affichage du 3e chiffre , du 2e numero de tel et du 3 etudiants
    cout << snir1[2].individu.telephone[1][3] << endl;

    // Affichage du numero INE du 3e etudiants sans utiliser les symboles [ ]
    //  pour ceci, utiliser les poinsteurs
    cout << (*(snir1 + 2)).numeroINE << endl;
    // ou encore
    cout << (snir1 + 2)->numeroINE << endl;

    // ===========================================================================================
    //  Création d'un tableau d'étudiants ; solution avec Vector
    // ===========================================================================================
    vector<Etudiant> lesSnirs;

    // Ajoutons les étudiants
    char reponse;
    do
    {
        Etudiant tmp = saisieEtudiant();
        lesSnirs.push_back(tmp);

        cout << "Encore un autre Etudiant ? (o/n) : " << endl;
        cin >> reponse;

    } while (reponse == 'o');

    // Affichage de la saisie
    cout << "Affichage des étudiants saisis : " << endl;
    for (unsigned i = 0; i < lesSnirs.size(); i++)
        affichage(lesSnirs[i]);

    // Attendons qu'on appui sur une touche pour terminer
    cin.get();
    cin.ignore();

    return EXIT_SUCCESS;
}