# Mini projet R2.04

Mini projet C (R2.04) sur le sujet 2 - Analyse adresse IP 

Lien GIT : https://gitlab.info.iut-tlse3.fr/bcb4249a/projetc-s2ga2

# But du programme

 Le but de ce programme est de permettre l’étude et l’extraction d’informations 
 provenant d’une adresse IP et de son masque réseau (CIDR).
 
 Le programme calcul les données suivantes : 
  - L'adresse réseau
  - L'adresse hôte
  - La classe 
  - Le type


# Membre du groupe
Groupe A2 :
 - AL-HABSI Ayoub
 - ASSELINE Téo
 - BAYCHE Baptiste
 - WEIDNER Arthur

 # Fonctionnement 

Pour utiliser le programme : 
  - Se placer dans le dossier contenant le code via un terminal.
  - Taper la commande "`make`" ou "`make all`".
  - Le programme vous demande alors de rentrer une IP :  
    - L'IP doit être sous la forme suivante (xxx.xxx.xxx.xxx/yy)
    - Les "x" doivent être remplacé par un nombre compris entre 0 et 255.
      Ils correspondent aux 4 octets qui composent de l'IP.
    - Les  "y" doivent être remplacé par un nombre compris entre 0 et 32.
      Ils correspondent au numéro CIDR (masque réseau) de l'IP.
    - Exemples : 
        - 192.168.140.25/12
        - 10.2.3.140/28
    - Tant que l'IP n'est pas bonne, le programme demandera une nouvelle fois 
      de rentrer l'IP.
  - L'analyse de l'IP est affichée dans le terminal, et également dans le fichier "enregistrement_ip" ou toutes les analyses sont sauvegarder.
  - Une fois l'analyse terminé, vous pouvez analyser une autre IP en tapant "oui" dans la console ou "non" pour arreter.

  - La commande "`make supAnalyse`" permet de supprimer toutes les analyses sauvegarder dans le fichier "enregistrement_ip".
  - La commande "`make clean`" permet de supprimer les fichiers .o et .exe crée lors de la compilation.      

  # Documentation 


  - **`decompositionIP`**
    - Description : Permet de décomposer l'ip rentrer par l'utilisateur dans une structure structIP
    - Entête : `void decomposationIP(char ip[], struct structIP* ip1);`
    - Entrée :             
      - char `ip[]` : chaîne de charactere sous forme d'IP (xxx.xxx.xxx.xxx/yy).
      - struct structIP* `ip1` : Structure structIP permettant de stocker `ip` décomposer.
    - Sortie : 
      - struct structIP* `ip1` : Adresse d'une structure structIP contenant les informations de `ip`.
    - Erreur : 
       - Si l'ip n'est pas sous la bonne forme.
>
>

  - **`affichageIP`**
    - Description : Permet l'affichage d'une adresse IP et de son nom sous le forme "nom : (xxx.xxx.xxx.xxx/yy)". 
    - Entête : `void affichageIP(char nom[], struct structIP* ip);`
    - Entrée :             
      - char `nom[]` : chaine de caractere contenant le nom de l'ip.
      - struct structIP* `ip1` : Adresse d'une structure structIP d'une ip.
    - Sortie : 
      - Affichage console sous la forme "nom : (xxx.xxx.xxx.xxx/yy)".

>
>

  - **`decimal2Binaire`**
    - Description : Permet de convertir un nombre décimal en nombre binaire.
    - Entête : `int decimal2Binaire(int nb);`
    - Entrée :             
      - int `nb` : Entier à convertir (supérieur ou égal à 0)
    - Sortie : 
      - int `resultat` : Nombre `nb` en binaire .
    - Erreur : 
      - Si `nb` est négatif.

>
>

  - **`CalculerMasque`**
    - Description :  Permet de calculer d'adresse reseau et l'adresse hote d'une IP.
    - Entête : `void CalculerMasque(struct structIP* ip, struct structIP* adresseReseau, struct structIP* adresseHote);`
    - Entrée :             
      - struct structIP* `ip` : StructIP contentant l'IP dont nous voulons calculer le masque
      - struct structIP* `adresseReseau` : StructIP où l'adresse réseau sera stockée après calcul
      - struct structIP* `adresseHote` : StructIP où l'adresse hôte sera stockée après calcul
    - Sortie : 
      - struct structIP* `adresseReseau` : Contient l'adresse réseau de `ip`.
      - struct structIP* `adresseHote` : Contient l'adresse hote de `ip`.
>
>

  - **`ipBinaire`**
    - Description : Permet de convertir une IP décimal en IP binaire.
    - Entête : `void ipBinaire(struct structIP* ip, struct structIP* ipBinaire);`
    - Entrée :             
      - struct structIP* `ip` : StructIP contenant l'IP à convertir
      - struct structIP* `ipBinaire` : StructIP où l'IP sera stockée en binaire après calcul sous forme de structIP.
    - Sortie : 
      - struct structIP* `ipBinaire` : Contient l'IP `ip` en binaire sous forme de structIP.

>
>

  - **`classeIp`**
    - Description : Permet de calculer la classe de l'IP.
    - Entête : `char classeIp(struct structIP* ip);`
    - Entrée :             
      - struct structIP* `ip` : StructIP contenant l'IP pour calculer ca classe
    - Sortie : 
      - char : Retourne un caractere correspondant à la classe de l'`ip` ('A', 'B', 'C', 'D', 'E').
    - Erreur : 
      - Retourne '0' en cas d'erreur.

>
>

  - **`typeAdresse`**
    - Description : Permet de calculer le type de l'IP.
    - Entête : `char* typeAdresse(struct structIP* ip);`
    - Entrée :             
      - struct structIP* `ip` : StructIP contenant l'IP pour calculer son type
    - Sortie : 
      - char[] : Retourne une chaine de caractere correspondant au type de l'`ip` (publique, privé, localhost, broadcast ou multicast) .
     
>
>

  - **`verifFormat`**
    - Description : Permet de vérifier que le format de l'IP soit sous la forme (xxx.xxx.xxx.xxx/yy)
    - Entête : `char* verifFormat(char ip[]);`
    - Entrée :             
      - struct structIP* `ip` : StructIP contenant l'IP à vérifier
    - Sortie : 
      - char[] : Retourne une chaine de caractere correspondant à l'erreur de format si il y a une erreur de format.
      - char[] : retourne "0" si il n'y a aucune erreur de format
>
>

  - **`enregistrer`**
    - Description : Permet d'enregistrer les analyses d'une IP dans un fichier texte` nomFi`c
    - Entête : `void enregistrer(struct structIP* ip,struct structIP* ipR, struct structIP* ipH, char nomFic[]);`
    - Entrée :             
      - struct structIP* `ip` : StructIP contenant l'IP à enregistrer.
      - struct structIP* `ipR` : StructIP contenant l'adresse reseau à enregistrer.
      - struct structIP* `ipH` : StructIP contenant l'adresse hote à enregistrer.
      - char `nomFic[]` : Chaine de caractere contenant le nom du fichier dans lequel enregistrer les données.
    - Sortie : 
      - Modifie le fichier `nomFic[]`
         





  


