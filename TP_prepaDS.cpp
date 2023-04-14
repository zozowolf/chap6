/***************************
Interrogation écrite sur les structures
*****************************/
#include <iostream> // bibliothèque de gestion des E/S
#include <conio.h>  // gestion de la console (ici _getch())
#include <Windows.h>
#include <string>
#include <vector>

using namespace std;

// Définition d'une structure contenant la carte d'identité d'une
// personne
struct Personne
{
    string nom;
    string prenom;
    unsigned short age;
    unsigned short taille; // taille en cm
};

struct Matiere
{
    string nomProfesseur;
    string nomMatiere;

    vector<double> notes; // toutes les notes obtenues dans cette matière
    double moyenne;       // la moyenne dans cette matière
};

struct Etudiant
{
    Personne identite;
    string classe;
    vector<Matiere> lesMatieres; // toutes les matières
    double moyenneGenerale;      // moyenne générale de l’étudiant
};

void calculDesMoyennes( Etudiant &cador) // cador est un étudiant
{
    double somme, sommeGenerale = 0;
    // Calcul des sommes des notes dans chaque matiere
    // Diviser la somme par le nombre de notes

    // Balayer toutes les matières associées à cet étudiant
    for (unsigned i = 0; i < cador.lesMatieres.size(); i++)
    {
        somme = 0; // somme des notes dans une matière donnée

        // Faire la somme de toutes les notes de la matière i
        for (unsigned j = 0; j < cador.lesMatieres[i].notes.size(); j++)
        {
            somme += cador.lesMatieres[i].notes[j];
        }

        // S'il y a au moins une note dans cette matière

        if (cador.lesMatieres[i].notes.size() > 1)
        {
            // On calcule la moyenne et on met à jour la moyenne de cette matière
            // dans la structure

            cador.lesMatieres[i].moyenne = somme / cador.lesMatieres[i].notes.size();

            // On ajoute cette moyenne à la somme générale
            sommeGenerale += cador.lesMatieres[i].moyenne;
        }
    }

    // Calcul et mise à jour de la moyenne générale de l’étudiant

    cador.moyenneGenerale = sommeGenerale / cador.lesMatieres.size();
}

/*****************************
Fonction d'affichage de toutes les informations de l'étudiant
*****************************/
void affichage(const Etudiant &cador)
{
    cout << "PRENOM : " << cador.identite.prenom << endl;
    cout << "NOM : " << cador.identite.nom << endl;
    cout << "AGE : " << cador.identite.age << endl;

    // Balayer toutes les matières de cet étudiant
    for (unsigned i = 0; i < cador.lesMatieres.size(); i++)
    {
        cout << "MATIERE : " << cador.lesMatieres[i].nomMatiere << endl;
        cout << "ENSEIGNEE PAR : " << cador.lesMatieres[i].nomProfesseur << endl;
        cout << "\tNotes obtenues : ";
        // Afficher toutes les notes de cette matière
        for (unsigned j = 0; j < cador.lesMatieres[i].notes.size(); j++)
            cout << cador.lesMatieres[i].notes[j] << "  ";

        cout << endl;
        cout << "\tMOYENNE DE LA MATIERE : "
             << cador.lesMatieres[i].moyenne << endl
             << endl;
    }
    cout << "MOYENNE GENERALE : " << cador.moyenneGenerale << endl;
}

/*****************************
Fonction principale
*****************************/
int main() // Fonction principale
{
    // Définition des matières. Les moyennes sont mises à 0 car elles seront
    // calculées par le programme
    Matiere math = {"C ROBERT", "MATH", {12, 7.5, 13, 11}, 0};
    Matiere anglais = {"I MORET", "ANGLAIS", {14.5, 18.5}, 0};
    Matiere informatique = {"C JACQUET", "INFORMATIQUE", {6, 12.15, 10}, 0};

    // Définir un étudiant toto ayant les caractéristiques suivantes :
    // NOM : "NOMTOTO",  Prenom : "PrenomTOTO", 19 ans, 75kg, 181 cm, Classe : "SNIR1"
    // Comporte les matières et notes définies ci-dessus.

    // Définir l’étudiant toto en accord avec les informations ci-dessus

    Etudiant toto = {{"NOMTOTO", "PrenomTOTO", 19, 181}, "SNIR1", {math, anglais, informatique}, 0};

    calculDesMoyennes(toto);
    affichage(toto);
    cin.get();
    cin.ignore();
    return EXIT_SUCCESS;
}
