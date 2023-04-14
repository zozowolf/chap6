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
#include <math.h>

using namespace std; // utilisation de l'espace de nommage
                     // de la bibliothéque standard

/*
 struct _complex
        {
            double x, y; // real and imaginary parts
        };

*/

struct Cercle
{
    _complex centre;
    double rayon;
};

bool appartientAuCercle(_complex p, Cercle C)
{

    if (((p.x - C.centre.x) * (p.x - C.centre.x)) + ((p.y - C.centre.y) * (p.y - C.centre.y)) <= (C.rayon * C.rayon))
        return true;

    return false;
}
/*======================================================
Fonction principal
========================================================*/
int main()
{
    int tmp = 0;

    Cercle LesCercles[4];
    LesCercles[0] = {{5, 6}, 5};
    LesCercles[1] = {{12, 6}, 5};
    LesCercles[2] = {{3, 6}, 0.5};
    LesCercles[3] = {{14, 6}, 0.5};

    // question 3
    _complex test = {4, 3};

    for (int i = 0; i < 4; i++)
        if (appartientAuCercle(test, LesCercles[i]))
        {
            cout << "Cercle " << i << endl;
            tmp++;
        }
    if (tmp == 0)
        cout << "aucun Cercle" << endl;
    tmp = 0;
    // question 4
    _complex M;

    cout << "Entrer les coordonnees d un point M (x,y) " << endl;
    cin >> M.x >> M.y;

    for (int i = 0; i < 4; i++)
        if (appartientAuCercle(M, LesCercles[i]))
        {
            cout << "Cercle " << i << endl;
            tmp++;
        }
    if (tmp == 0)
        cout << "aucun Cercle" << endl;
    tmp = 0;
    // Attendons qu'on appui sur une touche pour terminer
    cin.get();
    cin.ignore();

    return EXIT_SUCCESS;
}