/**
 * \page Présentation
 * 
 * \brief Programme du jeu du yams
 * 
 * \author TREUST Nolwenn F1
 * 
 * \version 1.0
 * 
 * \date 28/11/2021
 * 
 * Ce programme propose plusieurs procdures et fonctions
 * amenant à un programme principal consistant à jouer au jeu du yams
 * à 2 personnes. 
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>


/*****************************************************
 *                 CONSTANTES ET TYPES               *
*****************************************************/

/**
 * \def BORNE
 * 
 * \brief Constante du plus haut nombre possible avec un dé (lors de son lancer)
 * 
 */
const int BORNE = 6 ; 

/**
 * \def NON
 * 
 * \brief Constante pour refuser de relancer ses dés
 * 
 */
const char NON = 'N' ;

/**
 * \def OUI
 * 
 * \brief Constante pour accepter de relancer ses dés
 * 
 */
const char OUI = 'O' ;

/**
 * \def ZERO
 * 
 * \brief Constante pour un résultat de 0
 * 
 */
const int ZERO = 0 ;

/**
 * \def RYAMS
 * 
 * \brief Constante pour un résultat de Yams
 * 
 */
const int RYAMS = 50 ;

/**
 * \def RGS
 * 
 * \brief Constante pour un résultat de Grande Suite
 * 
 */
const int RGS = 40 ;

/**
 * \def RPS
 * 
 * \brief Constante pour un résultat de Petite Suite
 * 
 */
const int RPS = 30 ;

/**
 * \def RFH
 * 
 * \brief Constante pour un résultat de Full House
 * 
 */
const int RFH = 25 ;

/**
 * \def ESSAI
 * 
 * \brief Constante pour le nombre de lancer lors d'un tour d'un joueur
 * 
 */
const int ESSAI = 3 ;

/**
 * \def MINDE
 * 
 * \brief Constante pour le chiffre minimale d'un dé
 * 
 */
const int MINDE = 1 ;

/**
 * \def MAXDE
 * 
 * \brief Constante pour le chiffre maximale d'un dé
 * 
 */
const int MAXDE = 6 ;

/**
 * \def BONUS
 * 
 * \brief Constante pour le bonus à ajouter si le total supérieure est > à 62 
 * 
 */
const int BONUS = 35 ;

/**
 * \def NBTOURTOTAL
 * 
 * \brief Constante du nombre de tour au total lors du jeu du yams
 * 
 */
const int NBTOURTOTAL = 26 ; 

/**
 * \def INIT
 * 
 * \brief Constante du nombre de valeurs dans le tableau de la feuille de marque
 * 
 */
#define INIT 17

/**
 * \def VIDE
 * 
 * \brief Constante de la valeur qui intialise le tableau de la feuille de marque
 * 
 */
const int VIDE = -1 ;

/**
 * \def FIN
 * 
 * \brief Constante de la valeur qui finit la suite des valeurs lors d'un relancement de dés
 * 
 */
const int FIN = 0 ;

/**
 * \typedef feuilleMarque
 * 
 * \brief type tableau de INIT entiers
 * 
 * Le type feuilleMarque constitue une feuille de marque d'un des joueurs
 */
typedef int feuilleMarque[INIT] ;

/**
 * \def NB
 * 
 * \brief Constante du nombre de valeurs dans le tableau représentant les 5 dés
 * 
 */
#define NB 5 

/**
 * \typedef typedes
 * 
 * \brief type tableau de NB entiers
 * 
 * Le type typedes constitue un tableau représentant les 5 dés du joueur lorqu'il joue 
 */
typedef int typedes[NB] ; 

/**
 * \typedef occ
 * 
 * \brief type tableau de NB entiers
 * 
 * Le type occurrence constitue un tableau représentant le nombre d'occurrence d'un dé lors de son relancer 
 */
typedef int occ[NB] ; 

/*****************************************************
 *                           DÉS                     *
*****************************************************/

/**
 * 
 * \fn void afficheDes(typedes tabDe)
 * 
 * \brief Procédure qui affiche les dés lancés
 * 
 * \param typedes tabDe : tableau contenant les valeurs des 5 dés
 * 
 * \return rien (affichage)
 * 
 * Consiste à afficher les dés qui sont entrés en paramètres
 * 
 */
void afficheDes(typedes tabDe)
{
    printf("n°	  1  	  2  	  3  	  4  	  5\n") ;
	printf("	-----	-----	-----	-----	-----\n") ;
    printf("Dés :	| %d |	| %d |	| %d |	| %d |	| %d |\n",tabDe[0],tabDe[1],tabDe[2],tabDe[3],tabDe[4]) ;
	printf("	-----	-----	-----	-----	-----\n") ;
}

/**
 * 
 * \fn int fDe()
 * 
 * \brief Fonction qui donne un nombre aléatoire entre 1 et 6
 * 
 * \param aucun
 * 
 * \return un entier entre 1 et 6
 * 
 * Consiste à lancer un dé aléatoirement et nous rend ce qui a été trouvé au lancer
 * 
 */
int fDe()
{   
/**
* alea : nombre aléatoire généré
*/
    int alea ;

    alea = (rand()%BORNE) +1  ;

    return alea ;
}

/*****************************************************
 *         CALCULS DE COMBINAISON PARTIE 1           *
*****************************************************/

/**
 * 
 * \fn int fCalculChanceBrelanCarre(typedes tabDe)
 * 
 * \brief Fonction qui calcule le total des 5 dés
 * 
 * \param typedes tabDe : tableau des 5 dés 
 * 
 * \return un entier qui est la somme des 5 dés
 * 
 * Consiste à calculer la somme des 5 dés lors de la combinaison Chance, Brelan, Carré
 * 
 */
int fCalculChanceBrelanCarre(typedes tabDe)
{
    return (tabDe[0]+tabDe[1]+tabDe[2]+tabDe[3]+tabDe[4]) ; 
}

/**
 * 
 * \fn int fCalculT(typedes tabDe, int combi)
 * 
 * \brief Fonction qui calcule le total de ...(combi) dans les 5 dés
 * 
 * \param typedes tabDe : tableau des 5 dés
 * \param int combi : le numéro de la combinaison total de ... à calculer
 * 
 * \return un entier qui est la somme des dés ayant combi
 * 
 * Consiste à calculer la somme des dés avec
 *  une ...(combi) lors de la combinaison Total des ...(combi)
 * 
 */
int fCalculT(typedes tabDe, int combi)
{
/**
* compteur : compte le nombre de fois qu'apparaît la combinaison 
*/    
    int compteur ; 
    compteur = 0 ;
    if (tabDe[0]==combi)
    {
        compteur = compteur + 1 ;
    }
    if (tabDe[1]==combi)
    {
        compteur = compteur + 1 ;
    }
    if (tabDe[2]==combi)
    {
        compteur = compteur + 1 ;
    }
    if (tabDe[3]==combi)
    {
        compteur = compteur + 1 ;
    }
    if (tabDe[4]==combi)
    {
        compteur = compteur + 1 ;
    }

    return (compteur*combi) ;
}

/*****************************************************
 *                FEUILLE DE MARQUE                  *
*****************************************************/

/**
 * 
 * \fn void viderBuffer()
 * 
 * \brief Procédure qui vide l'entrée du clavier
 *
 * \param aucun
 * 
 * \return rien
 * 
 */
void viderBuffer()
{
    int c = 0;
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}

/**
 * 
 * \fn void nomJoueur(char joueur1[20],char joueur2[20])
 * 
 * \brief Procédure qui demande les noms des 2 joueurs
 *
 * \param char joueur1[20] : le nom du 1er joueur
 * \param char joueur2[20] : le nom du 2e joueur 
 * 
 * \return rien (les paramètres sont en sortie) 
 * 
 */
void nomJoueur(char joueur1[20],char joueur2[20])
{
    printf("Nom du joueur 1 ? \n") ; 
    scanf("%s",joueur1) ;

    viderBuffer() ; 

    printf("Nom du joueur 2 ? \n"); 
    scanf("%s",joueur2) ;

    viderBuffer() ;  
}

/**
 * 
 * \fn void initialise(feuilleMarque feuilleJoueur1,feuilleMarque feuilleJoueur2)
 * 
 * \brief Procédure qui initialise les feuilles de marque des joueurs
 *
 * \param feuilleMarque feuilleJoueur1 : feuille du marque du joueur 1  
 * \param feuilleMarque feuilleJoueur2 : feuille du marque du joueur 2
 * 
 * \return rien (les paramètres sont en sortie)
 * 
 * Consiste à mettre toutes les valeurs de la feuille de marque à VIDE (-1) pour l'initialiser 
 */
void initialise(feuilleMarque feuilleJoueur1,feuilleMarque feuilleJoueur2)
{
    int i ;

    for (i=0 ; i<INIT ; i++)
    {
        feuilleJoueur1[i] = VIDE ;
        feuilleJoueur2[i] = VIDE ;
    }
}

/**
 * 
 * \fn void afficheFeuilleMarque(feuilleMarque tableau)
 * 
 * \brief Procédure qui affiche la feuille de marque du joueur 
 *
 * \param feuilleMarque feuilleJoueur1 : feuille du marque du joueur 1  
 * 
 * \return rien (le paramètre est en sortie)
 * 
 * Consise à afficher la feuille du marque du joueur avec un tableau visuel réalisé et adapté pour les résultats des scores 
 */
/**
 * Les cases des scores totaux ne sont pas vides et affiche zéro comparés à la maquette parce que j'ai décidé de calculer les scores dans cette fonction
 */
/**
 * J'ai vérifié à la calculatrice les scores des traces de test et ils correspondent
 */
void afficheFeuilleMarque(feuilleMarque tableau) 
{
    int i ;

    tableau[6] = 0 ;
    for (i=0 ; i<6 ; i++)
    {
        if (tableau[i]!=VIDE)
        {
            tableau[6] = tableau[6] + tableau[i] ;         
        }
    }
    if (tableau[6]<62)
    {
        tableau[6] = VIDE ; 
    }
    else
    {
        tableau[6] = BONUS ; 
    }

    tableau[7] = 0 ;
    for (i=0 ; i<=6 ; i++)
    {
        if (tableau[i]!=VIDE)
        {
            tableau[7] = tableau[7] + tableau[i] ;
        }
    }

    tableau[15] = 0 ;
    for (i=8 ; i<=14 ; i++)
    {
        if (tableau[i]!=VIDE)
        {
            tableau[15] = tableau[15] + tableau[i] ;
        }
    }

    tableau[16] = tableau[15] + tableau[7] ;

    printf("\n _______________________\t\t_______________________\n") ;
    printf("|                 |     |\t\t|                 |     |\n") ;
    if (tableau[0]!=VIDE && tableau[8]!=VIDE ) 
    {
        printf("| 1 [total de 1]  |  %2d |\t\t| Brelan [total]  |  %2d |\n",tableau[0],tableau[8]) ;
    }
    else if (tableau[0]!=VIDE && tableau[8]==VIDE)
    {
        printf("| 1 [total de 1]  |  %2d |\t\t| Brelan [total]  |     |\n",tableau[0]) ;
    }
    else if (tableau[0]==VIDE && tableau[8]!=VIDE)
    {
        printf("| 1 [total de 1]  |     |\t\t| Brelan [total]  |  %2d |\n",tableau[8]) ;
    }
    else 
    {
        printf("| 1 [total de 1]  |     |\t\t| Brelan [total]  |     |\n") ;
    }
    printf("|-----------------|-----|\t\t|-----------------|-----|\n") ;
    if (tableau[1]!=VIDE && tableau[9]!=VIDE)
    {
        printf("| 2 [total de 2]  |  %2d |\t\t| Carré  [total]  |  %2d |\n",tableau[1],tableau[9]) ;
    }
    else if (tableau[1]!=VIDE && tableau[9]==VIDE)
    {
        printf("| 2 [total de 2]  |  %2d |\t\t| Carré  [total]  |     |\n",tableau[1]) ;
    }
    else if (tableau[1]==VIDE && tableau[9]!=VIDE)
    {
        printf("| 2 [total de 2]  |     |\t\t| Carré  [total]  |  %2d |\n",tableau[9]) ;
    }
    else 
    {
        printf("| 2 [total de 2]  |     |\t\t| Carré  [total]  |     |\n") ;
    }
    printf("|-----------------|-----|\t\t|-----------------|-----|\n") ;
    if (tableau[2]!=VIDE && tableau[10]!=VIDE)
    {
        printf("| 3 [total de 3]  |  %2d |\t\t| Full House [25] |  %2d |\n",tableau[2],tableau[10]) ;
    }
    else if (tableau[2]!=VIDE && tableau[10]==VIDE)
    {
        printf("| 3 [total de 3]  |  %2d |\t\t| Full House [25] |     |\n",tableau[2]) ;
    }
    else if (tableau[2]==VIDE && tableau[10]!=VIDE)
    {
        printf("| 3 [total de 3]  |     |\t\t| Full House [25] |  %2d |\n",tableau[10]) ;
    }
    else 
    {
        printf("| 3 [total de 3]  |     |\t\t| Full House [25] |     |\n") ;
    }
    printf("|-----------------|-----|\t\t|-----------------|-----|\n") ;
    if (tableau[3]!=VIDE && tableau[11]!=VIDE)
    {
        printf("| 4 [total de 4]  |  %2d |\t\t|Petite suite [30]|  %2d |\n",tableau[3],tableau[11]) ;
    }
    else if (tableau[3]!=VIDE && tableau[11]==VIDE)
    {
        printf("| 4 [total de 4]  |  %2d |\t\t|Petite suite [30]|     |\n",tableau[3]) ;
    }
    else if (tableau[3]==VIDE && tableau[11]!=VIDE)
    {
        printf("| 4 [total de 4]  |     |\t\t|Petite suite [30]|  %2d |\n",tableau[11]) ;
    }
    else 
    {
        printf("| 4 [total de 4]  |     |\t\t|Petite suite [30]|     |\n") ;
    }
    printf("|-----------------|-----|\t\t|-----------------|-----|\n") ;
    if (tableau[4]!=VIDE && tableau[12]!=VIDE)
    {
        printf("| 5 [total de 5]  |  %2d |\t\t|Grande suite [40]|  %2d |\n",tableau[4],tableau[12]) ;
    }
    else if (tableau[4]!=VIDE && tableau[12]==VIDE)
    {
        printf("| 5 [total de 5]  |  %2d |\t\t|Grande suite [40]|     |\n",tableau[4]) ;
    }
    else if (tableau[4]==VIDE && tableau[12]!=VIDE)
    {
        printf("| 5 [total de 5]  |     |\t\t|Grande suite [40]|  %2d |\n",tableau[12]) ;
    }
    else 
    {
        printf("| 5 [total de 5]  |     |\t\t|Grande suite [40]|     |\n") ;
    }
    printf("|-----------------|-----|\t\t|-----------------|-----|\n") ;
    if (tableau[5]!=VIDE && tableau[13]!=VIDE)
    {
        printf("| 6 [total de 6]  |  %2d |\t\t| Yams      [50]  |  %2d |\n",tableau[5],tableau[13]) ;
    }
    else if (tableau[5]!=VIDE && tableau[13]==VIDE)
    {
        printf("| 6 [total de 6]  |  %2d |\t\t| Yams      [50]  |     |\n",tableau[5]) ;
    }
    else if (tableau[5]==VIDE && tableau[13]!=VIDE)
    {
        printf("| 6 [total de 6]  |     |\t\t| Yams      [50]  |  %2d |\n",tableau[13]) ;
    }
    else 
    {
        printf("| 6 [total de 6]  |     |\t\t| Yams      [50]  |     |\n") ;
    }
    printf("|-----------------|-----|\t\t|-----------------|-----|\n") ;
    if (tableau[6]!=VIDE && tableau[14]!=VIDE)
    {
        printf("| Si > à 62 [35]  |  %2d |\t\t| Chance [total]  |  %2d |\n",tableau[6],tableau[14]) ;
    }
    else if (tableau[6]!=VIDE && tableau[14]==VIDE)
    {
        printf("| Si > à 62 [35]  |  %2d |\t\t| Chance [total]  |     |\n",tableau[6]) ;
    }
    else if (tableau[6]==VIDE && tableau[14]!=VIDE)
    {
        printf("| Si > à 62 [35]  |     |\t\t| Chance [total]  |  %2d |\n",tableau[14]) ;
    }
    else
    {
        printf("| Si > à 62 [35]  |     |\t\t| Chance [total]  |     |\n") ;
    }
    printf("|-----------------|-----|\t\t|-----------------|-----|\n") ;
    printf("| Total supérieur | %3d |\t\t| Total inférieur | %3d |\n",tableau[7],tableau[15]) ;
    printf("|_________________|_____|\t\t|_________________|_____|\n") ;
    printf("\n _______________________\n") ;
    printf("| Total           | %3d |\n",tableau[16]) ;
    printf("|_________________|_____|\n\n") ; 

}

/**
 * 
 * \fn void afficheGagne(feuilleMarque joueur1, feuilleMarque joueur2, char nom1[20],char nom2[20])
 * 
 * \brief Procédure qui affiche qui a gagné la partie de yams 
 *
 * \param feuilleMarque feuilleJoueur1 : feuille du marque du joueur 1  
 * \param feuilleMarque feuilleJoueur2 : feuille du marque du joueur 2
 * \param char nom1[20] : nom du joueur 1 
 * \param char nom2[20] : nom du joueur 2 
 * 
 * \return rien (affichage) 
 * 
 * Consiste à calculer d'après les scores finaux des 2 joueurs celui qui a gagné ou s'il y a égalité et de l'afficher 
 */
void afficheGagne(feuilleMarque joueur1, feuilleMarque joueur2, char nom1[20],char nom2[20])
{
    printf("\n\tJoueur 1 %s\n",nom1) ;
    afficheFeuilleMarque(joueur1) ;
    printf("\n\tJoueur 2 %s\n",nom2) ;
    afficheFeuilleMarque(joueur2) ;

    if (joueur1[16]>joueur2[16])
    {
        printf("\nJoueur 1 %s a gagné !\n",nom1) ; 
    }
    else if (joueur1[16]<joueur2[16])
    {
        printf("\nJoueur 2 %s a gagné !\n",nom2) ; 
    }
    else if (joueur1[16]==joueur2[16])
    {
        printf("\nEgalité !\n") ; 
    }
    printf("Joueur 1 %s : %d\nJoueur 2 %s : %d\n",nom1,joueur1[16],nom2,joueur2[16]) ;
}

/*****************************************************
 *                    COMBINAISON                    *
*****************************************************/

/**
 * 
 * \fn bool combiPresente(char combi,feuilleMarque joueur)
 * 
 * \brief Fonction qui renvoie un true si la combinaison n'est pas présente sinon false
 *
 * \param feuilleMarque joueur : feuille du marque du joueur  
 * \param char combi : caractère correspondant à une combinaison
 * 
 * \return True si la combinaison n'est pas présentent sinon False  
 * 
 * Consiste à vérifer si une combinaison est déja remplie dans la feuille de marque du joueur
 */
bool combiPresente(char combi,feuilleMarque joueur)
{
/**
* res : résultat de la présence d'un score dans une ligne du tableau
*/
    bool res ; 

    switch (combi)
    {
    case '1' : if (joueur[0]!=VIDE)
                {
                    res = false ;
                    printf("Combinaison déjà rempli !\n") ;
                }
                else 
                {
                    res = true ; 
                }
        break;
    case '2' : if (joueur[1]!=VIDE)
                {
                    res = false ;
                    printf("Combinaison déjà rempli !\n") ;
                }
                else 
                {
                    res = true ; 
                }
        break;
    case '3' : if (joueur[2]!=VIDE)
                {
                    res = false ;
                    printf("Combinaison déjà rempli !\n") ;
                }
                else 
                {
                    res = true ; 
                }
        break;
    case '4' : if (joueur[3]!=VIDE)
                {
                    res = false ;
                    printf("Combinaison déjà rempli !\n") ;
                }
                else 
                {
                    res = true ; 
                }
        break;
    case '5' : if (joueur[4]!=VIDE)
                {
                    res = false ;
                    printf("Combinaison déjà rempli !\n") ;
                }
                else 
                {
                    res = true ; 
                }
        break;
    case '6' : if (joueur[5]!=VIDE)
                {
                    res = false ;
                    printf("Combinaison déjà rempli !\n") ;
                }
                else 
                {
                    res = true ; 
                }
        break;
    case 'B' : if (joueur[8]!=VIDE)
                {
                    res = false ;
                    printf("Combinaison déjà rempli !\n") ;
                }
                else 
                {
                    res = true ; 
                }
        break;
    case 'C' : if (joueur[9]!=VIDE)
                {
                    res = false ;
                    printf("Combinaison déjà rempli !\n") ;
                }
                else 
                {
                    res = true ; 
                }
        break;
    case 'F' : if (joueur[10]!=VIDE)
                {
                    res = false ;
                    printf("Combinaison déjà rempli !\n") ;
                }
                else 
                {
                    res = true ; 
                }
        break;
    case 'P' : if (joueur[11]!=VIDE)
                {
                    res = false ;
                    printf("Combinaison déjà rempli !\n") ;
                }
                else 
                {
                    res = true ; 
                }
        break;
    case 'G' : if (joueur[12]!=VIDE)
                {
                    res = false ;
                    printf("Combinaison déjà rempli !\n") ;
                }
                else 
                {
                    res = true ; 
                }
        break;
    case 'Y' : if (joueur[13]!=VIDE)
                {
                    res = false ;
                    printf("Combinaison déjà rempli !\n") ;
                }
                else 
                {
                    res = true ; 
                }
        break;
    case 'L' : if (joueur[14]!=VIDE)
                {
                    res = false ;
                    printf("Combinaison déjà rempli !\n") ;
                }
                else 
                {
                    res = true ; 
                }
        break;
    default: printf("Erreur") ;
             res = false ; 
        break;
    }

    return res ; 
}

/*****************************************************
 *         CALCULS DE COMINAISONS PARTIE 2           *
*****************************************************/

/**
 * 
 * \fn int festCarre(typedes tabDe)
 * 
 * \brief Fonction qui calcule si il y a un Carée
 *
 * \param typedes tabDe : tableau contenant les valeurs des 5 dés
 * 
 * \return un entier  
 * 
 * Consiste à calculer si il y a un carrée à partir des dés et de retourner le résultat en fonction de cela 
 */
int festCarre(typedes tabDe)
{
    int resultat ; 

    if ((tabDe[0]==tabDe[1])&&(tabDe[1]==tabDe[2])&&(tabDe[2]==tabDe[3]))
    {
        return fCalculChanceBrelanCarre(tabDe) ; 
    }
    else if ((tabDe[4]==tabDe[1])&&(tabDe[1]==tabDe[2])&&(tabDe[2]==tabDe[3]))
    {
        return fCalculChanceBrelanCarre(tabDe) ; 
    }
    else if ((tabDe[4]==tabDe[0])&&(tabDe[0]==tabDe[2])&&(tabDe[2]==tabDe[3]))
    {
        return fCalculChanceBrelanCarre(tabDe) ; 
    }
    else if ((tabDe[4]==tabDe[1])&&(tabDe[1]==tabDe[0])&&(tabDe[0]==tabDe[3]))
    {
        return fCalculChanceBrelanCarre(tabDe) ; 
    }
    else if ((tabDe[4]==tabDe[1])&&(tabDe[1]==tabDe[2])&&(tabDe[2]==tabDe[0]))
    {
        return fCalculChanceBrelanCarre(tabDe) ; 
    }
    else
    {
        resultat = ZERO ;
        return resultat ; 
    }
}

/**
 * 
 * \fn int festBrelan(typedes tabDe)
 * 
 * \brief Fonction qui calcule si il y a un Brelan 
 *
 * \param typedes tabDe : tableau contenant les valeurs des 5 dés
 * 
 * \return un entier  
 * 
 * Consiste à calculer si il y a un brelan à partir des dés et de retourner le résultat en fonction de cela 
 */
int festBrelan(typedes tabDe)
{
/**
* i : indice de boucle des valeurs de dé possibles
*/
    int i ;
/**
* j : indice de boucle de parcours des 5 dés
*/
    int j ; 
    int resultat ; 
    i = MINDE ;
    resultat = 0 ; 


    while (i<=MAXDE && resultat<3 )
    {
        resultat = 0 ;
        for (j=0 ; j<NB ; j++)
        {
            if (tabDe[j]==i)
            {
                resultat = resultat + 1 ;
            }
        }
        i = i + 1 ;
    }    

    if (resultat>=3)
    {
        return fCalculChanceBrelanCarre(tabDe) ; 
    }
    else
    {
        resultat = ZERO ;
        return resultat ; 
    }
}

/**
 * 
 * \fn int festYams(typedes tabDe)
 * 
 * \brief Fonction qui calcule si il y a un Yams 
 *
 * \param typedes tabDe : tableau contenant les valeurs des 5 dés
 * 
 * \return un entier  
 * 
 * Consiste à calculer si il y a un yams à partir des dés et de retourner le résultat en fonction de cela 
 */
int festYams(typedes tabDe)
{
    int resultat ; 

    if ((tabDe[0]==tabDe[1])&&(tabDe[1]==tabDe[2])&&(tabDe[2]==tabDe[3])&&(tabDe[3]==tabDe[4]))
    {
        resultat = RYAMS ; 
        return resultat ;
    }
    else
    {
        resultat = ZERO ;
        return resultat ; 
    }
}

/**
 * 
 * \fn int festGrandeSuite(typedes tabDe)
 * 
 * \brief Fonction qui calcule si il y a une Grande Suite 
 *
 * \param typedes tabDe : tableau contenant les valeurs des 5 dés
 * 
 * \return un entier  
 * 
 * Consiste à calculer si il y a une grande suite à partir des dés et de retourner le résultat en fonction de cela 
 */
int festGrandeSuite(typedes tabDe)
{
/**
* i : indice de boucle des valeurs de dé possibles
*/
    int i ;
/**
* j : indice de boucle de parcours des 5 dés
*/
    int j ; 
    int resultat ;
    int compteur ;   

    resultat = 0 ; 
    compteur = 0 ; 

    i = MINDE ;
    while (i<=(MAXDE-1) && resultat<=1)
    {
        resultat = 0 ;
        for (j=0 ; j<NB ; j++)
        {
            if (tabDe[j]==i)
            {
                resultat = resultat + 1 ; 
            }
        }
        i = i + 1 ; 
        if (resultat==1)
        {
          compteur = compteur + 1 ;
        }
    }

    if (compteur==5)
    {
        resultat = RGS ; 
        return resultat ;
    }
    else 
    {
      i = MINDE+1 ;
      resultat = 0 ; 
      compteur = 0 ; 
      while (i<=MAXDE && resultat<=1)
      {
          resultat = 0 ;
          for (j=0 ; j<NB ; j++)
          {
            if (tabDe[j]==i)
            {
                resultat = resultat + 1 ; 
            }
        }
        i = i + 1 ; 
        if (resultat==1)
        {
          compteur = compteur + 1 ;
        }
    }
    if (compteur==5)
    {
        resultat = RGS ; 
        return resultat ;
    }
    else
    {
        resultat = ZERO ; 
        return resultat ;
    }
  }
}

/**
 * 
 * \fn int festPetiteSuite(typedes tabDe)
 * 
 * \brief Fonction qui calcule si il y a une Petite Suite 
 *
 * \param typedes tabDe : tableau contenant les valeurs des 5 dés
 * 
 * \return un entier  
 * 
 * Consiste à calculer si il y a une petite suite à partir des dés et de retourner le résultat en fonction de cela 
 */
int festPetiteSuite(typedes tabDe)
{
/**
* i : indice de boucle des valeurs de dé possibles
*/
    int i ;
/**
* j : indice de boucle de parcours des 5 dés
*/
    int j ; 
    int resultat ;
    int compteur ;   
    resultat = 0 ; 
    compteur = 0 ; 

    i = 1 ;
    while (i<=4 && resultat<=2)
    {
        resultat = 0 ;
        for (j=0 ; j<NB ; j++)
        {
            if (tabDe[j]==i)
            {
                resultat = resultat + 1 ; 
            }
        }
        i = i + 1 ; 
        if (resultat>=1)
        {
          compteur = compteur + 1 ;
        }
    }

    if (compteur==4)
    {
        resultat = RPS ; 
        return resultat ;
    }
    else 
    {
        i = 2 ;
        resultat = 0 ; 
        compteur = 0 ; 
        while (i<=5 && resultat<=2)
        {
            resultat = 0 ;
            for (j=0 ; j<NB ; j++)
            {
                if (tabDe[j]==i)
                {
                    resultat = resultat + 1 ; 
                }
            }
            i = i + 1 ; 
            if (resultat>=1)
            {
            compteur = compteur + 1 ;
            }
        }
        if (compteur==4)
        {
            resultat = RPS ; 
            return resultat ;
        }
        else
        {
            i = 3 ;
            resultat = 0 ; 
            compteur = 0 ; 
            while (i<=6 && resultat<=2)
            {
                resultat = 0 ;
                for (j=0 ; j<NB ; j++)
                {
                    if (tabDe[j]==i)
                    {
                        resultat = resultat + 1 ; 
                    }
                }
                i = i + 1 ; 
                if (resultat>=1)
                {
                    compteur = compteur + 1 ;
                }
            }
            if (compteur==4)
            {
                resultat = RPS ; 
                return resultat ;
            }
            else
            {
                resultat = ZERO ; 
                return resultat ;
            }
        }     
    }
}

/**
 * 
 * \fn int festFullHouse(typedes tabDe)
 * 
 * \brief Fonction qui calcule si il y a un Fulle House
 *
 * \param typedes tabDe : tableau contenant les valeurs des 5 dés
 * 
 * \return un entier  
 * 
 * Consiste à calculer si il y a un full house à partir des dés et de retourner le résultat en fonction de cela 
 */
int festFullHouse(typedes tabDe)
{
    int resultat ; 
/**
* i : indice de boucle des valeurs de dé possibles
*/
    int i ;
/**
* j : indice de boucle de parcours des 5 dés
*/
    int j ;
    int occurence[6] ;
    int compteur ; 
    
    if (festBrelan(tabDe)!=0)
    {
        for (i=0 ; i<6 ; i++)
        {
            occurence[i] = 0 ;
        }

        for (i=1 ; i<=6 ; i++)
        {
            for (j=0 ; j<NB ; j++)
            {
                if (tabDe[j]==i)
                {
                    occurence[(i-1)] = occurence[(i-1)] + 1 ; 
                }
            }
        }

        compteur = 0 ; 

        for (i=0 ; i<6 ; i++)
        {
            if (occurence[i]==3)
            {
                compteur = compteur + 1 ;
            }
            else if (occurence[i]==2)
            {
                compteur = compteur + 1 ;
            }
        }

        if(compteur==2)
        {
            resultat = RFH ;
            return resultat ;
        }
        else
        {
            resultat = ZERO ;
            return resultat ; 
        }

    }
    else if (festYams(tabDe)!=0)
    {
        resultat = RFH ;
        return resultat ; 
    }
    else
    {
        resultat = ZERO ;
        return resultat ; 
    }
}

/*****************************************************
 *                  COMBINAISON                      *
*****************************************************/

/**
 * 
 * \fn void combinaison(typedes tabDe,feuilleMarque joueur)
 * 
 * \brief Procédure qui demande la combinaison voulue au joueur, vérifie sa présence et remplit le tableau de la feuille de marque
 *
 * \param typedes tabDe : tableau contenant les valeurs des 5 dés
 * \param feuilleMarque joueur : feuille du marque du joueur
 * 
 * \return rien (les paramètres sont en entrée/sortie)  
 * 
 * Consiste à demander au joueur la combinaison qu'il veut rentrer dans sa feuille de marque, puis vérifie si elle est déjà présente dans le tableau, si oui, la 
 * procédure lui redemande une combinaison, sinon elle remplit la ligne correspondante de la feuille de marque du résultat de la combinaison 
 */
void combinaison(typedes tabDe,feuilleMarque joueur)
{
    char combinaison ;
/**
* rtn : valeur du return lorque ENTREE est tapé sur le clavier
*/
    char rtn ; 

    printf("\nQuelle combinaison ?\n") ;

    do
    {
        printf("\nTotal de 1(1)") ; 
        printf("\nTotal de 2(2)") ; 
        printf("\nTotal de 3(3)") ;
        printf("\nTotal de 4(4)") ; 
        printf("\nTotal de 5(5)") ; 
        printf("\nTotal de 6(6)") ;
        printf("\nBrelan(B)") ; 
        printf("\nCarrée(C)") ;
        printf("\nFull House(F)") ;
        printf("\nPetite Suite(P)") ;
        printf("\nGrande Suite(G)") ;
        printf("\nYams(Y)") ;
        printf("\nChance(L)(luck anglais)\n") ;

        scanf("%c%c",&combinaison,&rtn) ;
    } 
    while (combiPresente(combinaison,joueur)==0);

    switch (combinaison)
    {
    case '1' : joueur[0] = fCalculT(tabDe,1) ;
        break;
    case '2' : joueur[1] = fCalculT(tabDe,2) ;
        break;
    case '3' : joueur[2] = fCalculT(tabDe,3) ;
        break;
    case '4' : joueur[3] = fCalculT(tabDe,4) ;
        break;
    case '5' : joueur[4] = fCalculT(tabDe,5) ;
        break;
    case '6' : joueur[5] = fCalculT(tabDe,6) ;
        break;
    case 'B' : joueur[8] = festBrelan(tabDe) ;
        break;
    case 'C' : joueur[9] = festCarre(tabDe) ;
        break;
    case 'F' : joueur[10] = festFullHouse(tabDe) ; 
        break;
    case 'P' : joueur[11] = festPetiteSuite(tabDe) ;
        break;
    case 'G' : joueur[12] = festGrandeSuite(tabDe) ; 
        break;
    case 'Y' : joueur[13] = festYams(tabDe) ; 
        break;
    case 'L' : joueur[14] = fCalculChanceBrelanCarre(tabDe) ; 
        break;
    default: printf("Erreur") ;
        break;
    }
    
}

/*****************************************************
 *                  LANCEMENT DES DES                *
*****************************************************/

/**
 * 
 * \fn void lancementDesDes(typedes tabDe) 
 * 
 * \brief Procédure qui lance les 5 dés puis les relance si le joueur le demande 
 *
 * \param typedes tabDe : tableau contenant les valeurs des 5 dés
 * 
 * \return rien (les paramètres sont en entrée/sortie)  
 * 
 * Consiste à lancer une première fois les 5 dés, puis les relance si le joueur répond OUI, la procédure demande combien de dés à relancer,
 * puis le joueur entre 1 par 1 les numéros des dés à relancer pour l'essai, (il y a vérification pour que le joueur ne puiise pas relancer le même dé dans
 * le même essai). Le joueur a 3 lancers en tout. 
 */
void lancementDesDes(typedes tabDe) 
{
/**
* i : indice de boucle du nombre d'essai possible
*/
    int i ;
/**
* j : indice de boucle du 1er lancer de dé
*/
    int j ; 
/**
* j : indice de boucle pour initialiser le tableau occDe à 0 
*/
    int k ;
    int num ;                                              
    char relance ;
/**
* rtn : valeur du return lorque ENTREE est tapé sur le clavier
*/
    char rtn ;
    int compteur ;
/**
* occDe : tableau représentant les occurences d'aparrition d'un dé à relancer lors d'un essai 
*/ 
    occ occDe ; 

    i = 0 ;
    relance = OUI ;

    srand(time(NULL));

    for (j=0 ; j<NB ; j++)
        {
            tabDe[j] = fDe() ;
        }

    afficheDes(tabDe) ; 

    while((i<ESSAI)&&(relance==OUI))
    {
        i = i + 1 ;
    
        do
        {
          printf("Relancer ?\nOui (O) ou Non (N)\n") ;
          scanf("%c%c",&relance,&rtn) ;
        } 
        while ((relance!=OUI)&&(relance!=NON));

        if (i==ESSAI) 
        {
            printf("Vous avez déjà réalisé vos %d essais\n",ESSAI) ;
        }
        else if (relance==OUI)
        { 
          compteur = 0 ;
          num = -1 ; 

          for (k=0 ; k<5 ; k++)
          {
            occDe[k] = 0 ;
          }
            printf("Entrez un par un les numéros des dés à lancer lors de ce lancer/essai\nPour finir le choix des dés, entrez 0 (zéro)\n") ; 
            while (compteur<NB && num!=FIN)
            {
              do 
              {
                printf("Numéro du dé à relancer\n") ;
                scanf("%d%c",&num,&rtn) ;
                if (num!=FIN && (num<MINDE||num>MAXDE))
                {
                  printf("Erreur...\n") ; 
                }
                else if (num!=FIN && occDe[num-1]!=0)
                {
                  printf("Dé déjà relancé pour cet essai\n") ; 
                }
              } 
              while(occDe[num-1]!=0 && num!=FIN && (num<MINDE||num>MAXDE)) ;
            
              if (num!=FIN)
              {
                occDe[num-1] = occDe[num-1] + 1 ;
                tabDe[(num-1)] = fDe() ;
              }
                
              compteur = compteur + 1 ;
            } 
        }
        afficheDes(tabDe) ;
    }
}


/*****************************************************
 * PROGRAMME PRINCIPAL *
*****************************************************/

/**
 * 
 * \fn int main()
 * 
 * \brief Programme principal du jeu du yams 
 *
 * \param aucun
 * 
 * \return rien   
 * 
 * Programme principal du yams avec les 26 tours au totals des 2 joueurs (chacun a 13 tours de jeu) 
 */
int main()
{
    char nom1[20],nom2[20] ;

    typedes tabDe ; 

    int tourJ1 , tourJ2 , tourTotal ; 

    feuilleMarque feuilleJoueur1 ;
    feuilleMarque feuilleJoueur2 ;

    nomJoueur(nom1,nom2) ; 

    initialise(feuilleJoueur1,feuilleJoueur2) ; 

    tourJ1 = 1 ;
    tourJ2 = 1 ;
    tourTotal = 1 ;
    
    while (tourTotal<=NBTOURTOTAL) 
    {
        if (tourJ1<=tourJ2)
        {
            printf("\n\tTour %d Joueur 1\n",tourJ1) ;
            printf("\t%s\n",nom1) ;

            afficheFeuilleMarque(feuilleJoueur1) ;

            lancementDesDes(tabDe) ;

            combinaison(tabDe,feuilleJoueur1) ;

            afficheFeuilleMarque(feuilleJoueur1) ;

            printf("\n\tFin Tour %d Joueur1\n",tourJ1) ;

            tourJ1 = tourJ1 + 1 ;
        }
        else 
        {
            printf("\n\tTour %d Joueur2\n",tourJ2) ;
            printf("\t%s\n",nom2) ;

            afficheFeuilleMarque(feuilleJoueur2) ;

            lancementDesDes(tabDe) ;

            combinaison(tabDe,feuilleJoueur2) ;

            afficheFeuilleMarque(feuilleJoueur2) ;

            printf("\n\tFin Tour %d Joueur2\n",tourJ2) ;

            tourJ2 = tourJ2 + 1 ;
        }

        tourTotal = tourTotal + 1 ;
    }

    afficheGagne(feuilleJoueur1,feuilleJoueur2,nom1,nom2) ;

    return EXIT_SUCCESS ; 
}