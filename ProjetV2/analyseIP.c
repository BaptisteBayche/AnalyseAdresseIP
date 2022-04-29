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
*  Nom du fichier :  analyseIP.c                                              *           
*                                                                             *
******************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "analyseIP.h"

void decomposationIP(char ip[], struct structIP* ips){
    char octet[4] = "";
    int cpt = 0;
    int placeOctet  = 1;

    for (int i = 0 ; ip[i] != '\0'  ; i ++ ){
 
        if (ip[i] == '.' || ip[i] == '/' ){    
            cpt = 0;
            //On range les valeurs décomposees dans la structure
            switch(placeOctet){
                case 1 : (*ips).oct1 = strtol(octet, NULL,10); break;
                case 2 : (*ips).oct2 = strtol(octet, NULL,10); break;
                case 3 : (*ips).oct3 = strtol(octet, NULL,10); break;
                case 4 : (*ips).oct4 = strtol(octet, NULL,10); break;
            }
            //On vide octet 
            for (int y = 0; y < 4; y++){
                octet[y] = ' ';   
            } 

            placeOctet++;          
            
        } else {
            //Tant que ce n'est pas un . ou un / on ajoute à octet les caracteres de l'adresse IP
            if (ip[i] == ' '){}
            else if(ip[i] == '0' && cpt == 0){}
            else if(ip[i] <= '9' && ip[i] >= '0'){
                octet[cpt] = ip[i];
                cpt++;
            }
            
        }
    }

    (*ips).CIDR = strtol(octet, NULL,10);    
}

void affichageIP(char nom[], struct structIP* ip){
    printf("%s : %d.%d.%d.%d/%d\n", nom, (*ip).oct1, (*ip).oct2, (*ip).oct3, (*ip).oct4, (*ip).CIDR);
}

int decimal2Binaire(int nb) {
  int resultat = 0;
  int reste, i = 1;
 

  while (nb!=0) {
    reste = nb % 2;
    nb /= 2;
    resultat += reste * i;
    i *= 10;
   
  }
  return resultat;
}

void ipBinaire(struct structIP* ip, struct structIP* ipBinaire){
    (*ipBinaire).oct1 = decimal2Binaire((*ip).oct1);
    (*ipBinaire).oct2 = decimal2Binaire((*ip).oct2);
    (*ipBinaire).oct3 = decimal2Binaire((*ip).oct3);
    (*ipBinaire).oct4 = decimal2Binaire((*ip).oct4);
    (*ipBinaire).CIDR = decimal2Binaire((*ip).CIDR);
}

void CalculerMasque(struct structIP* ip, struct structIP* adresseReseau, struct structIP* adresseHote) {
    

    char masqueTab[NUM_STRINGS][MAX_LENGTH] = { {"0.0.0.0/0"},  {"128.0.0.0/0"},       {"192.0.0.0/0"},       {"224.0.0.0/0"},       {"240.0.0.0/0"},       {"248.0.0.0/0"},       {"252.0.0.0/0"},       {"254.0.0.0/0"},       {"255.0.0.0/0"}, 
                                                                {"255.128.0.0/0"},     {"255.192.0.0/0"},     {"255.224.0.0/0"},     {"255.240.0.0/0"},     {"255.248.0.0/0"},     {"255.252.0.0/0"},     {"255.254.0.0/0"},     {"255.255.0.0/0"}, 
                                                                {"255.255.128.0/0"},   {"255.255.192.0/0"},   {"255.255.224.0/0"},   {"255.255.240.0/0"},   {"255.255.248.0/0"},   {"255.255.252.0/0"},   {"255.255.254.0/0"},   {"255.255.255.0/0"},
                                                                {"255.255.255.128/0"}, {"255.255.255.192/0"}, {"255.255.255.224/0"}, {"255.255.255.240/0"}, {"255.255.255.248/0"}, {"255.255.255.252/0"}, {"255.255.255.254/0"}, {"255.255.255.255/0"}};

    
    struct structIP masqueIP;
    decomposationIP(masqueTab[(*ip).CIDR], &masqueIP);

    (*adresseReseau).oct1 = (*ip).oct1 & masqueIP.oct1;
    (*adresseReseau).oct2 = (*ip).oct2 & masqueIP.oct2;
    (*adresseReseau).oct3 = (*ip).oct3 & masqueIP.oct3;
    (*adresseReseau).oct4 = (*ip).oct4 & masqueIP.oct4;
    (*adresseReseau).CIDR = 0;

    struct structIP masqueHote;
    masqueHote.oct1 = 255 - masqueIP.oct1;
    masqueHote.oct2 = 255 - masqueIP.oct2;
    masqueHote.oct3 = 255 - masqueIP.oct3;
    masqueHote.oct4 = 255 - masqueIP.oct4;
    masqueHote.CIDR = 0;

    (*adresseHote).oct1 = (*ip).oct1 & masqueHote.oct1;
    (*adresseHote).oct2 = (*ip).oct2 & masqueHote.oct2;
    (*adresseHote).oct3 = (*ip).oct3 & masqueHote.oct3;
    (*adresseHote).oct4 = (*ip).oct4 & masqueHote.oct4;
    (*adresseHote).CIDR = 0;
}

char classeIp(struct structIP* ip){
    int octetDec = (*ip).oct1;
    int octetBin = decimal2Binaire((*ip).oct1);

    if(octetBin >= 11110000){
        return 'E';
    }else if (octetBin >= 11100000){
        return 'D';
    }else if (octetBin >= 11000000){
        return 'C';
    }else if (octetBin >= 10000000){
        return 'B';
    }else if (octetBin >= 0 && octetBin != 1111111){
        return 'A';
    }else{
        return '0';
    }

} 

char* verifFormat(char ip[]){
    struct structIP Poctet;
    int nbchiffre = 0;
    char octet[4] = "";
    int placeOctet  = 1;
    int i;
    int Ni=0;

    for (i = 0 ; ip[i] != '\n'; i ++ ){
        if (ip[i] == '.' || ip[i] == '/' ){    
            nbchiffre = 0;
            switch(placeOctet){
                case 1 : Poctet.oct1 = strtol(octet, NULL,10); break;
                case 2 : Poctet.oct2 = strtol(octet, NULL,10); break;
                case 3 : Poctet.oct3 = strtol(octet, NULL,10); break;
                case 4 : Poctet.oct4 = strtol(octet, NULL,10); break;
            }
            for (int y = 0; y < 4; y++){
                octet[y] = ' ';   
            } 
            placeOctet++; 
        } else {
            if (ip[i] == ' '){
                Ni ++;
            }else if(ip[i] == '0' && nbchiffre == 0){
                Ni ++;
            }else if(ip[i] <= '9' && ip[i] >= '0'){
                octet[nbchiffre] = ip[i];
                nbchiffre++;
            } else {
                Ni ++;
                printf("c : %d\n", ip[i]);
                return "ERREUR caractere indefini";

            }
            
        }
    }
    Poctet.CIDR = strtol(octet, NULL,10);
    
    i = i - Ni;
    if (i > 18){
        return "ERREUR IP trop grande\n";
        
    } else if(placeOctet != 5 ){
        return "ERREUR format IP\n";
        
    } else if(Poctet.oct1 > 255 || Poctet.oct1 < 0 ){
        return "ERREUR premier octet\n";
        
    } else if(Poctet.oct2 > 255 || Poctet.oct2 <0 ){
        return "ERREUR second octet\n";
        
    } else if(Poctet.oct3 > 255 || Poctet.oct3 < 0 ){
        return "ERREUR troisieme octet\n";
        
    } else if(Poctet.oct4 > 255 || Poctet.oct4 < 0 ){
        return "ERREUR quatrieme octet\n";
        
    } else if(Poctet.CIDR > 32 || Poctet.CIDR <0 ){
        return "ERREUR CIDR\n";
        
    } else {
        return "0";
    }
}


char* typeAdresse(struct structIP* ip){ 
    if ((*ip).oct1 == 255 && (*ip).oct2 == 255 && (*ip).oct3 == 255 && (*ip).oct4 == 255 && (*ip).CIDR == 32){
        return "Broadcast\n";
    }else if ((*ip).oct1 >= 224 && (*ip).oct1 <= 239) {
        return "Multicast\n";
    }else if ((*ip).oct1 == 127){
        return "Localhost\n";
    }else if(((*ip).oct1 == 10 && (*ip).CIDR == 8) || ((*ip).oct1 == 192 && (*ip).oct2 == 168 && (*ip).CIDR == 16) || (((*ip).oct1 ==172 && (*ip).CIDR == 12 && (*ip).oct2 >= 16 && (*ip).oct2 <= 31))){
        return "Privée\n";
    }else{
        return "Public\n";
    }
}

void enregistrer(struct structIP* ip,struct structIP* ipR, struct structIP* ipH, char nomFic[]){
    FILE* fic; 
    fic = fopen(nomFic, "a");
    fprintf(fic,"\n=== Analyse de l'IP ===\n");
    fprintf(fic," - IP : %d.%d.%d.%d/%d\n",(*ip).oct1, (*ip).oct2, (*ip).oct3, (*ip).oct4, (*ip).CIDR);
    fprintf(fic," - Adresse réseau :%d.%d.%d.%d/%d\n",(*ipR).oct1, (*ipR).oct2, (*ipR).oct3, (*ipR).oct4, (*ipR).CIDR);
    fprintf(fic," - Adresse Hôte : %d.%d.%d.%d/%d\n",(*ipH).oct1, (*ipH).oct2, (*ipH).oct3, (*ipH).oct4, (*ipH).CIDR);
    fprintf(fic," - Classe : %c \n",classeIp(ip));
    fprintf(fic," - Type : %s" ,typeAdresse(ip));
    fprintf(fic,"======================\n");
    fclose(fic);
}

