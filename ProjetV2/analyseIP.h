/******************************************************************************
*  ASR => 4R2.04                                                              *
*******************************************************************************
*                                                                             *
*  N° de Sujet : Sujet 2                                                      *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Intitulé : Analyse adresse IP                                              *                
*                                                                             *
*******************************************************************************
*                                                                             *
*  Nom-prénom1 : AL-HABSI Ayoub                                               *              
*                                                                             *
*  Nom-prénom2 : BAYCHE Baptiste                                              *             
*                                                                             *
*  Nom-prénom3 : ASSELINE Téo                                                 *          
*                                                                             *
*  Nom-prénom4 : WEIDNER Arthur                                               *            
*                                                                             *
*******************************************************************************
*                                                                             *
*  Nom du fichier :  analyseIP.h                                              *
*                                                                             *
******************************************************************************/


#define MAX_LENGTH 18 
#define NUM_STRINGS 33


struct structIP {
    int oct1;
    int oct2;
    int oct3;
    int oct4;
    int CIDR;

};

//Permet de décomposer l'ip ip[] rentrer par l'utilisateur dans une structure structIP ip1
void decomposationIP(char ip[], struct structIP* ip1);

//Permet l'affiche d'une adresse IP ip avec son nom nom[]
void affichageIP(char nom[], struct structIP* ip);

//Permet de convertir un nombre décimal nb en nombre binaire
int decimal2Binaire(int nb);

// Permet de calculer le masque d'une IP ip à partir de l'adresse reseau et de l'adresse hote
void CalculerMasque(struct structIP* ip, struct structIP* adresseReseau, struct structIP* adresseHote);

// Permet de convertir une IP ip décimal en IP binaire ipBinaire
void ipBinaire(struct structIP* ip, struct structIP* ipBinaire);

//Permet de calculer la classe de l'IP ip
char classeIp(struct structIP* ip);

//Permet de  vérifier que le format de l'IP ip rentrée par l'utilisateur est correct
char* verifFormat(char ip[]);

// Permet de calculer le type de l'adresse ip
char* typeAdresse(struct structIP* ip);

//Permet d'enregistrer les analyses d'une IP dans un fichier texte nomFic
void enregistrer(struct structIP* ip,struct structIP* ipR, struct structIP* ipH, char nomFic[]);

