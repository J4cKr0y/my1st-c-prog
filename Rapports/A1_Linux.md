## A. Arborescence des dossiers système Linux

| Dossier        | Rôle principal                                      |
|----------------|-----------------------------------------------------|
| /              | Racine du système                                   |
| /bin           | Commandes essentielles                              |
| /sbin          | Outils systèmes (admin)                             |
| /boot          | Fichiers de démarrage                               |
| /etc           | Fichiers de configuration                           |
| /home          | Répertoires des utilisateurs                        |
| /lib, /lib64   | Bibliothèques partagées                             |
| /opt           | Logiciels optionnels                                |
| /root          | Répertoire perso du superutilisateur                |
| /srv           | Données pour services réseaux                       |
| /usr           | Logiciels et ressources utilisateur                 |
| /var           | Fichiers variables/logs                             |
| /tmp           | Fichiers temporaires                                |
| /proc          | Infos dynamiques sur le système                     |
| /sys           | Interface avec le noyau                             |
| /dev           | Périphériques matériels                             |

---

## B. Fichiers et dossiers : manipulations de base

### 1. Création 

- Créer un dossier dans /home/user depuis /home/user/Documents :
  ```
  cd ..
  mkdir test
  ```

- Créer directement avec chemin absolu :
  ```
  mkdir /home/user/test
  mkdir ~/test
  ```

### 2. Suppression

  ```
  rm -rf ~/test
  ```



## C. Commandes essentielles

### 3. Afficher 

- Afficher le dossier actuel :
  ```
  pwd
  ```
### 4. Rechercher

- Rechercher tous les fichiers .xml :
  ```
  sudo find / -type f -name "*.xml"
  ```

- Rechercher dans un répertoire spécifique :
  ```
  find /home/user/Documents -type f -name "*.xml"
  ```



## D. Adresses IP & connexions réseau

### 5. IP

- IP locale :
  ```
  ip a
  hostname -I
  ```

- IP publique :
  ```
  curl ifconfig.me
  dig +short myip.opendns.com @resolver1.opendns.com
  ```

### 6. Connexions réseau

- Connexion SSH vers une machine distante :
  ```
  ssh root@192.168.1.2
  ```

- Alternatives à SSH : Telnet, FTP, VNC, Netcat...



### 7. Copie de fichiers en réseau

- Copier le contenu d’un dossier local vers une machine distante :
  ```
  scp /home/user/Documents/fichiersXML/* root@192.168.1.3:/root/doc/
  ```

## E. Fichiers 

### 8. Visualiser fichiers XML

- Modifier : nano exemple1.xml
- Afficher : cat, less, more, head, tail


### 10. Droits d’accès d’un fichier

- Voir les droits :
  ```
  ls -l exemple1.xml
  ```

- Changer les droits :
  ```
  chmod 777 exemple1.xml   # rwx pour tous
  chmod 700 exemple1.xml   # rwx uniquement pour propriétaire
  chmod 644 exemple1.xml   # lecture/écriture pour propriétaire, lecture pour autres
  ```

- Codes permission :
  - 7 = rwx
  - 6 = rw-
  - 5 = r-x
  - 4 = r--
  - 0 = aucun droit


### 11. Rechercher un motif dans des fichiers XML

- Motif insensible à la casse :
  ```
  grep -i "test" exemple1.xml exemple2.xml
  ```

## F. Variables

### 12. Variables d’environnement importantes

| Variable          | Rôle                                                           |
|-------------------|----------------------------------------------------------------|
| PATH            | Répertoires des exécutables accessibles                        |
| LDLIBRARYPATH | Répertoires des bibliothèques dynamiques (.so)                |
| LD_PRELOAD      | Injecte une bibliothèque spécifique avant exécution           |
| HOME            | Répertoire personnel de l’utilisateur                         |
| IFS             | Délimiteur pour découper les champs en bash                   |
| PWD             | Répertoire courant                                             |


## G. Archives

### 13. Création d’archives

- Créer un tar non compressé :
  ```
  tar -cvf etc_backup.tar /etc
  ```

- Créer un tar compressé :
  ```
  tar -czf etc_backup.tar.gz /etc
  tar -cjf etc_backup.tar.bz2 /etc
  ```


