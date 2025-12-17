# Le Modèle OSI : L'Oignon des Réseaux ! 


​Vous vous êtes déjà demandé comment votre message arrive de votre téléphone à l'autre bout du monde ? 
C'est grâce au Modèle OSI (Open Systems Interconnection) ! 
C'est le standard ultime pour comprendre comment les réseaux communiquent.

"Les ogres, c'est comme les oignons. Ça a des couches."-Shrek
Les réseaux aussi ! 7. Chacune a une mission spécifique. 
C'est un peu le "Inception" du networking : chaque niveau encapsule l'information du niveau supérieur ! 


​Au cœur de tout, il y a les Protocoles informatiques . 
Ce sont des règles (un peu comme le code de conduite des Jedi) qui définissent comment les données doivent être formatées, envoyées et reçues.
​Quand vous envoyez un message, il est d'abord emballé dans un Paquet TCP (Couche 4), qui garantit la bonne réception, 
puis dans un Paquet IP (Couche 3), qui lui donne une adresse logique pour le routage. Sans ces protocoles, l'Internet ne serait qu'un bruit blanc !


​Pour s'assurer que l'info arrive à bon port, on passe par les 7 étapes suivantes :

​- Application (Couche 7) : L'interface utilisateur. C'est là que le contenu est créé (votre post LinkedIn !).
​Protocole Ex : HTTP/HTTPS 
​Job : Développeur Web/Frontend 

​- Présentation (Couche 6) : Formatage et chiffrement. Elle traduit le langage de l'Application.
​Protocole Ex : TLS/SSL, JPEG 
​Job : Ingénieur Sécurité (Le gardien des secrets) 

​- Session (Couche 5) : Établissement, gestion et fermeture de la connexion entre deux applications.
​Protocole Ex : RPC (Remote Procedure Call) 
​Job : Architecte Cloud/SaaS (Gère les sessions à grande échelle) 

- Transport (Couche 4) : Livraison de bout en bout des données. Le choix de la méthode : fiable (TCP) ou rapide (UDP).
​Protocole Ex : TCP (le recommandé avec AR) / UDP (l'email sans suivi) 
​Job : Ingénieur Réseaux Senior (Le chef d'orchestre des flux) 

- Réseau (Couche 3) : Routage des paquets entre différents réseaux (la fonction du Paquet IP). C'est le GPS de l'Internet !
Protocole Ex : IP (Internet Protocol) 
Job : Administrateur Systèmes/Routage 

- Liaison de Données (Couche 2) : Transmission des données sur un lien physique direct (d'un routeur au suivant).
Protocole Ex : Ethernet, Wi-Fi 
Job : Développeur Embarqué/IoT (Parle directement au matériel) 

- Physique (Couche 1) : La transmission physique des bits (câbles, ondes radio, lumière). La matière même du réseau.
Protocole Ex : RJ45 (le câble bleu !) 
Job : Technicien Support/Maintenance (Le héros du câble mal branché) 


​Comprendre l'OSI, c'est maîtriser les fondations de l'IT. 
Que vous soyez en mode Application (Couche 7) ou en mode Physique (Couche 1), chaque niveau est une pièce essentielle du puzzle.
