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
*  Nom du fichier :  main.c                                                   *
*                                                                             *
******************************************************************************/


#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "analyseIP.h"

#define MAX_SIZE_IP 99

void main () {
    char ip[MAX_SIZE_IP];
    char recommencer[] = "oui";
    while (strcmp(recommencer, "oui") == 0 || strcmp(recommencer, "OUI") == 0 || strcmp(recommencer, "Oui") == 0){
        printf("Veuillez rentrer une IP sous la forme (xxx.xxx.xxx.xxx/xx)\n");
        fgets(ip,MAX_SIZE_IP,stdin);
        if (strcmp(ip, "\n") == 0){
            fgets(ip,MAX_SIZE_IP,stdin);
        }
        if (strcmp(verifFormat(ip), "0") == 0) {
            struct structIP ipDec; 
            struct structIP adresseReseau;
            struct structIP adresseHote;
            
            decomposationIP(ip, &ipDec);
            
            CalculerMasque(&ipDec,&adresseReseau,&adresseHote);
            
            //Affichage
            printf("\n=== Analyse de l'IP ===\n");
            affichageIP(" - IP", &ipDec);
            affichageIP(" - Adresse Reseau", &adresseReseau);
            affichageIP(" - Adresse Hote", &adresseHote);
            printf(" - Classe : %c \n",classeIp(&ipDec));
            printf(" - Type : %s" ,typeAdresse(&ipDec));
            printf("======================\n");

            enregistrer(&ipDec, &adresseReseau, &adresseHote, "enregistrement_ip");

            printf("\nVoulez vous analyser une autre IP? (oui / non)\n");
            fgets(recommencer,4,stdin);

            
        }else{
            printf("%sEntrer une adresse IP valide ! (4 octets entre 0 et 255, et 1 CIDR entre 0 et 30)\n",verifFormat(ip));
        }
    }
    
}