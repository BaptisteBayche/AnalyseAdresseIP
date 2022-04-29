# Mini projet R2.04

Mini projet C (R2.04) sur le sujet 2 - Analyse adresse IP 

Lien GIT :

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
  - Taper la commande "make" ou "make all".
  - Le programme vous demande alors de rentrer une IP :  
    - L'IP doit être sous la forme suivante (xxx.xxx.xxx.xxx/yy)
    - Les "x" doivent être remplacé par un nombre compris entre 0 et 255.
      Ils correspondent aux 4 octets qui composent de l'IP.
    - Les  "y" doivent être remplacé par un nombre compris entre 0 et 30.
      Ils correspondent au numéro CIDR (masque réseau) de l'IP.
    - Exemples : 
        - 192.168.140.25/12
        - 10.2.3.140/28
    - Tant que l'IP n'est pas bonne, le programme demandera une nouvelle fois 
      de rentrer l'IP.
  - L'analyse de l'IP est affichée dans le terminal, et également dans le fichier "enregistrement_ip" ou toutes les analyses sont sauvegarder.
  - Une fois l'analyse terminé, vous pouvez analyser une autre IP en tapant "oui" dans la console ou "non" pour arreter.
        


