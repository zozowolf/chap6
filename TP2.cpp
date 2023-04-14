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

struct Rect
{
    _complex P1;
    _complex P2;
};

bool appartientAuRectangle(_complex p, Rect r)
{

    if (p.x >= r.P1.x && p.x <= r.P2.x)
        if (p.y <= r.P1.y && p.y >= r.P2.y)
            return true;

    return false;
}
/*======================================================
Fonction principal
========================================================*/
int main()
{
    int tmp=0;
    // code en dessous
    Rect LesRectangles[4];
    LesRectangles[0] = {{1, 10}, {9, 2}};
    LesRectangles[1] = {{9, 10}, {17, 2}};
    LesRectangles[2] = {{2.5, 6.5}, {3.5, 5.5}};
    LesRectangles[3] = {{14.5, 6.5}, {15.5, 5.5}};

    // question 3
    _complex test = {4, 3};

    for (int i = 0; i < 4; i++)
        if (appartientAuRectangle(test, LesRectangles[i]))
        {
            cout << "rectangle " << i << endl;
            tmp++;
        }
    if(tmp==0)
        cout << "aucun rectangle"<< endl;
    tmp=0;
    // question 4
    _complex M;

    cout << "Entrer les coordonnees d un point M (x,y) " << endl;
    cin >> M.x >> M.y;

    for (int i = 0; i < 4; i++)
        if (appartientAuRectangle(M, LesRectangles[i]))
        {
            cout << "rectangle " << i << endl;
            tmp++;
        }
    if(tmp==0)
        cout << "aucun rectangle"<< endl;
    tmp=0;
    // Attendons qu'on appui sur une touche pour terminer
    cin.get();
    cin.ignore();

    return EXIT_SUCCESS;
}