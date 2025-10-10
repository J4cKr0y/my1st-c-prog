# A3- Concepts réseaux


## 1/ Les topologies réseau 


### Introduction
La topologie réseau désigne l’organisation des liaisons entre les équipements d’un réseau informatique : ordinateurs, serveurs, imprimantes, etc. 
Cette structure influence la performance, la fiabilité, la maintenance et la sécurité du réseau. Différents modèles existent selon les époques, les besoins ou les technologies.


### Topologie Point-à-point
#### Concept
La topologie point-à-point (ou « peer-to-peer ») est la structure la plus simple : deux dispositifs sont connectés entre eux par une seule liaison physique. Il n'y a ni intermédiaire, ni routeur, ni réseau complexe ; juste deux extrémités qui peuvent communiquer directement.
#### Exemple concret
* Deux ordinateurs reliés par un câble croisé Ethernet pour jouer en réseau local, échanger des fichiers ou partager une connexion Internet.
* Un ordinateur raccordé directement à une imprimante ou à un modem.
* Une liaison fibre optique entre deux équipements réseau distants.
#### Avantages
* Simplicité de mise en place (un seul câble, aucune configuration complexe).
* Performance maximale puisque toute la bande passante du lien est dédiée à la communication entre les deux points.
* Sécurité accrue : la connexion n’est pas exposée aux autres, impossible d’écouter le trafic sans accéder physiquement au câble.
* Robustesse : peu de pannes possible sauf rupture du lien lui-même.
#### Inconvénients
* Non évolutif : impossible d’ajouter facilement d’autres appareils sans multiplier les liens ou changer de topologie.
* Fonctionnalité limitée : pas d’optimisation de trafic ou de relais, une seule communication possible à la fois. 
#### Utilisation actuelle
* Dépannage/Traitement ponctuel : transfert de données entre deux postes sans réseau étendu.
* Industriel/Embarqué : deux équipements connectés pour assurer un canal sécurisé et direct.
* Protocoles spécialisés : fibre optique entre équipements distants, DSL point-à-point.


### Topologie Bus
#### Concept
Le modèle bus relie tous les appareils à un même câble principal (bus). Les machines envoient leurs données sur ce câble et toutes les stations peuvent écouter le signal. Seuls les destinataires traitent les paquets qui les concernent.
#### Exemple concret
Ancien réseau local en coaxial (Ethernet 10Base2 ou 10Base5).
#### Avantages
* Installation simple et peu coûteuse pour des petits réseaux.
* Facilité d’extension par branchement d’un nouveau périphérique sur le bus. 
#### Inconvénients
* Collisions fréquentes si plusieurs machines communiquent en même temps; ralentissement du débit.
* Une rupture ou une panne du câble principal coupe tout le réseau.
#### Utilisation actuelle
Rare voire absente; utilisée historiquement dans les réseaux locaux desktop.


### Topologie Étoile
#### Concept
Tous les périphériques sont reliés à un nœud central : un hub, switch ou routeur. Les données passent systématiquement par cet appareil qui oriente chaque paquet vers sa destination. 
#### Exemple concret
Réseau Ethernet moderne, câblage RJ45 vers un switch au centre d’une baie réseau.
#### Avantages
* Facile à gérer : remplacer un poste ou câble défectueux n’affecte pas le reste du réseau.
* Performances élevées; chaque liaison est indépendante, peu de collisions.
* Déploiement pratique dans les bâtiments modernes, administrable.
#### Inconvénients
* Dépendance au nœud central : si le switch tombe, tout le réseau est hors service.
* Plus coûteux qu’un bus à cause du câblage et du matériel central.
#### Utilisation actuelle
Standard pour les réseaux d’entreprise, bureaux, écoles, et domiciles.


### Topologie Anneau
#### Concept
Chaque poste est relié à deux autres, formant une boucle (anneau). Les données circulent dans un seul sens, passant d’un poste à l’autre jusqu’à atteindre le destinataire.
#### Exemple concret
IBM Token Ring, FDDI (fibre optique), réseaux contra-rotatifs industriels.
#### Avantages
* Collisions rares grâce à la gestion d’un jeton circulant dans l’anneau.
* Économie de câblage par rapport à la maillée.
#### Inconvénients
* Point de faiblesse : si une station ou un câble est coupé, toute la boucle peut être interrompue.
* Difficile à étendre sans couper tout ou partie du réseau. 
#### Utilisation actuelle
Secteurs industriels ou réseaux spécialisés; encore utilisée dans certains équipements critiques.


### Topologie Arbre
#### Concept
Organisation en arborescence : les nœuds centraux de plusieurs étoiles (switches locaux) sont reliés à un backbone principal, dessinant une structure hiérarchique, semblable à un organigramme.
#### Exemple concret
Campus universitaire, grande entreprise avec plusieurs étages ou départements.
#### Avantages
* Modularité et évolutivité : on peut ajouter des branches ou sous-réseaux.
* Organisation claire pour gérer de grands groupes d’appareils.
#### Inconvénients
* Points de défaillance dans la hiérarchie : un hub racine coupé arrête une branche entière.
* Complexité de gestion dans les très grands réseaux.
#### Utilisation actuelle
Courante dans les infrastructures multi-sites, réseaux campus, sociétés avec plusieurs bâtiments.


### Topologie Maillée
#### Concept
Chaque appareil est relié à plusieurs autres, parfois à tous, créant des chemins multiples pour acheminer les données.
#### Exemple concret
Réseaux Internet, infrastructures télécom, Wi-Fi mesh couvrant plusieurs zones.
#### Avantages
* Haute disponibilité : le trafic peut être réacheminé en cas de panne; excellente tolérance.
* Sécurité : difficile à interrompre complètement, plusieurs voies alternatives.
#### Inconvénients
* Complexité de câblage et coût élevé dans les maillages filaires complets.
* Administration difficile si le nombre de nœuds croît.
#### Utilisation actuelle
Backbone Internet, réseaux industriels, couvertures Wi-Fi mesh domestiques et pro.


### Topologie Hybride
#### Concept
Combine plusieurs topologies selon les besoins : étoile + bus, étoile + anneau, etc. Pour optimiser la performance, la sécurité et la résilience.
#### Exemple concret
Entreprise avec backbone maillé et réseaux de bureaux en étoile.
#### Avantages
* Adaptabilité aux différents usages et contraintes.
* Optimisation des coûts, performances, évolutivité.
#### Inconvénients
* Complexité de conception et d’entretien; nécessite une planification rigoureuse. 
* Coût de maintenance parfois supérieur à une topologie unique.
#### Utilisation actuelle
Très courantes dans les grandes entreprises, campus, environnements multi-sites.


### LAN, MAN, WAN (pic et pic et colegram) 
#### LAN (Local Area Network) 
LAN désigne un réseau local, généralement limité à une zone restreinte comme un bâtiment, un bureau, une maison ou un campus. Il permet de relier entre eux des appareils (ordinateurs, imprimantes, serveurs) pour partager des ressources rapidement et efficacement dans un espace géographique confiné. Du temps où les connexions internet étaient extrêmement lentes, certains joueurs de jeux vidéo organisaient des “LAN party” pour jouer ensemble en reliant directement leurs ordinateurs. 
Les réseaux LAN peuvent être organisés selon plusieurs formes de topologie physique ou logique telles que étoile, bus, anneau, arbre ou maillage, selon la conception du réseau local.
Par exemple, les LAN modernes privilégient majoritairement la topologie en étoile avec des switches centraux, mais peuvent aussi utiliser d’autres topologies selon les infrastructures. 
#### WAN (Wide Area Network) 
WAN signifie réseau étendu. Ce type de réseau relie plusieurs LAN entre eux sur de grandes distances, parfois à l’échelle nationale ou mondiale, via Internet ou des liens privés. Le WAN est utilisé pour connecter des sites distants d’une même entreprise, des filiales ou pour accéder à des ressources partagées à travers le monde. 
La topologie WAN est souvent complexe, hybride, et parfois maillée, car elle doit garantir la redondance et la résilience sur des territoires étendus.
Les réseaux WAN utilisent des équipements comme les routeurs pour interconnecter les LAN distants, et peuvent combiner plusieurs topologies selon l’infrastructure physique (liaisons par fibre, satellites, liaisons point-à-point). 
#### MAN (Metropolitan Area Network) 
MAN est un réseau qui connecte plusieurs réseaux locaux (LAN) sur une zone géographique intermédiaire, souvent une ville, une agglomération ou une grande entreprise dispersée dans une même région. Sa taille est plus grande que celle d’un LAN, mais plus petite qu’un WAN. 
Un réseau MAN est fréquemment organisé en topologies hybrides, souvent combinant les topologies en anneau ou en étoile pour assurer fiabilité et redondance.




### Conclusion générale
Chaque topologie correspond à des exigences particulières de simplicité, performance, sécurité ou évolutivité. Le choix dépend du contexte : nombre de nœuds, infrastructure physique, besoins organisationnels et budget.
La topologie point-à-point reste incontournable pour les liaisons directes ou les usages industriels, tandis que l’étoile domine les réseaux locaux modernes. Les architectures hybrides et maillées apportent résilience et flexibilité aux grands réseaux.
Bien comprendre ces principes garantit une infrastructure réseau solide, évolutive et adaptée à chaque environnement.






## 2/ Connectique 
### Introduction 
La connectique regroupe l'ensemble des câbles, prises et interfaces indispensables à la transmission de signaux (données, vidéo, voix, courant faible, etc.) entre différents appareils électroniques et informatiques. Elle est présente dans tous les secteurs : audio-vidéo, informatique, télécommunications, domotique, et même les installations industrielles. Comprendre la connectique, c'est appréhender les fondations du transport de l'information et de l'énergie dans la société contemporaine.De la télévision à internet en passant par le téléphone, le choix de la connectique influence la qualité du signal, la fiabilité de la transmission, la vitesse et les usages possibles. Nous allons tout d'abord expliquer les principes fondamentaux, puis détailler chaque technologie : câble coaxial, RJ45 (Ethernet), fibre optique, et aborder d'autres câbles courants pour donner une vision exhaustive et accessible du sujet.


### Les fondamentaux de la connectique
#### Définitions et enjeux
La connectique regroupe différents dispositifs destinés au transport de signaux électriques, lumineux ou radio entre deux éléments d'un circuit ou d’un système. On distingue principalement :Les câbles de transmission (coaxial, fibre optique, paires torsadées…)Les connecteurs (prises, embouts, fiches…)Les équipements intermédiaires (coffrets de communication, switchs…)
Les enjeux : rapidité, fiabilité de transmission, immunité aux interférences, coût, facilité d’installation et évolutivité.


### Le câble coaxial
#### Concept et structure
Le câble coaxial est une technologie ancienne et éprouvée utilisée pour transmettre des signaux électriques de haute fréquence (radio, télévision, internet, vidéo, etc.). Sa structure concentrique, qui lui donne son nom (“coaxial”), offre une excellente protection contre les perturbations électromagnétiques.
#### Composition
Un câble coaxial se compose de:
* Âme centrale : conducteur en cuivre, porteur du signal
* Isolant diélectrique : sépare l’âme centrale du blindage
* Blindage : tresse métallique ou feuille d’aluminium, protège des interférences
* Gaine extérieure : couche protectrice en plastique isolant
#### Propriétés techniques
* Impédances courantes : 50 Ohms (radio, données), 75 Ohms (TV, internet)
* Transmission : signaux analogiques ou numériques, bande de fréquences étendueAtténuation : le signal décroît plus lentement avec la distance que dans des câbles non-blindés
* Types de connecteurs coaxiaux
* BNC (Bayonet Neill–Concelman) : réseaux, vidéo pro, radio
* F-Type : TV, satellite, internet domestique
* N-Type : radiocommunications extérieures
#### Applications concrètes
* Télévision par câble : liaison entre l’antenne, le décodeur et le téléviseur
* Internet par câble : certaines offres Très Haut Débit utilisent le câble coaxial en alternative à la fibre
* Réseaux informatique historiques (Ethernet 10Base2, 10Base5) : réseaux locaux anciens
* Vidéosurveillance analogique : raccordement des caméras au centre de contrôle
* Transmission radio (RF) : communication sans fil, antennes, studios radio
#### Avantages
* Robustesse
* Facilité de pose
* Bon compromis coût/performance
#### Limites
* Débit limité
* Sensibilité à l’atténuation sur longues distances
* Moins évolutif que la fibre optique
#### Exemples concrets
Dans un immeuble ancien, le réseau TV collective utilise encore massivement le câble coaxial pour distribuer le signal du satellite ou de la TNT à chaque logement.Un radioamateur utilise des câbles coaxiaux pour raccorder son antenne à son émetteur.


### La prise RJ45 et le câble Ethernet
#### Concept et structure
La prise RJ45 est la connectique standard pour relier des équipements informatiques (PC, imprimantes, box, consoles, etc.) à un réseau local ou à Internet. Le câble Ethernet (catégorie 5e, 6, 7, 8) permet de transmettre la voix (VDI : Voix, Données, Images) à travers des paires de fils torsadés.
#### Composition
* Connecteur RJ45 : embout à 8 broches (contacts métalliques)
* Câble à paires torsadées : généralement 4 paires de fils cuivre isolés
* Blindage : FTP (Foiled Twisted Pair) et STP (Shielded Twisted Pair) offrent une protection contre les interférences
#### Fonctionnement
La prise RJ45 sert au passage du “courant faible” : donnée, vidéo, téléphone et non du courant fort (alimentation électrique). 
Le câble relie les équipements réseau via un commutateur (switch), une box ou un coffret de communication, et permet d’obtenir le même signal partout dans l’habitation.
#### Catégories de câble
* Cat 5e : jusqu’à 1 Gb/s
* Cat 6 : jusqu’à 10 Gb/s sur 55 m
* Cat 7 / Cat 8 : ultra-haut débit, usages data centers
#### Applications concrètes
* Connexion Internet : relie la box à un PC ou au panneau de brassage
* Téléphonie IP : certains téléphones utilisent la prise RJ45
* Réseaux locaux : interconnexion d'appareils dans l’entreprise ou la maison
* Domotique : distribution des données à différents capteurs et actionneurs
#### Cas réel
Un particulier rénovant son logement installe plusieurs prises RJ45 dans les murs pour relier tous les équipements multimédias à sa box via un coffret de communication, optimisant ainsi débit et confort.


### La fibre optique
#### Concept et technologies
La fibre optique “révolutionne” la connectique moderne, offrant des débits inégalés pour les communications sur de longues distances. C’est un fil très fin en verre ou en plastique qui transporte l’information sous forme de lumière (laser ou LED, infrarouge).
#### Structure
* Cœur : fibre de verre ou plastique, guide la lumière
* Gaine optique : matériau à faible indice de réfraction, confine la lumière
* Protection mécanique : tube PVC, couche d’aramide, gaine étanche
#### Principes physiques : la réflexion totale
La lumière pulsée dans le cœur est réfléchie continuellement sur la gaine optique intérieure, ce qui lui permet de voyager très loin sans sortir du câble (principe de la réflexion totale).
#### Types de fibres
* Monomode (SMF) : cœur très fin, la lumière circule “tout droit” sur des dizaines de kilomètres, utilisé pour les longues distances
* Multimode (MMF) : cœur plus large, plusieurs modes lumineux, utilisé pour les réseaux locaux, distance maximale : 550 m pour le 10G
#### Connecteurs spécifiques
* SC (Standard Connector) : commun pour fibre optique monomode et multimode
* LC (Lucent Connector) : petit format, souvent utilisé dans les baies de brassage ou entre étages
* ST (Straight Tip) : verrouillage à baïonnette, utilisé en industrie
#### Applications concrètes
* Internet Très Haut Débit (FTTH, FTTO) : jusqu’à 8 Gb/s pour les particuliers, 100 Gb/s pour les pros
* Télévision : IPTV, flux vidéo HD
* Téléphonie : réseaux “tout IP”
* Transmission médicale / scientifique : endoscopie, capteurs, laboratoires
* Réseaux opérateurs : backbone, data centers
#### Architecture de réseau
* FTTH dédié : une fibre du central à chaque logement, très coûteux, utilisé dans les bureaux
* FTTH partagé : une fibre partagée par plusieurs clients, divise le débit mais diminue le coût
* AON (Active Optical Network) : chaque client raccordé à la fibre via multiplexeurs et switchs actifs
#### Exemple d’usage
Dans une grande entreprise, chaque étage est raccordé à la fibre optique via des connecteurs LC, assurant des débits records pour les applications numériques (visioconférence, cloud, sauvegarde, vidéo en streaming…).
#### Autres connectiques courantes
* La RJ11 est historiquement dédiée à la téléphonie fixe (analogique). Elle possède 2 ou 4 contacts seulement et est désormais remplacée par la RJ45 pour les installations modernes
* HDMI : Transmission audio/vidéo haute définition entre box, TV, moniteurs, consoles
* USB : Transmission de données et alimentation entre périphériques informatiques (claviers, souris, disques durs, chargeurs)
#### Application réelle : installation multimédia domestique
Imaginons un projet d’aménagement d’un appartement connecté :
* La box internet est installée dans l’entrée avec un panneau de brassage.
* Chaque pièce dispose d’une prise RJ45 pour relier PC, TV, console (signal data et TV/IP).
* La télévision est raccordée à la box soit en RJ45, soit via câble coaxial si nécessaire.
* Les caméras de sécurité analogiques utilisent le câble coaxial pour transmettre les images vers l’enregistreur situé dans le salon.
* La fibre optique entre dans l’appartement via une prise terminale optique, permettant un accès optimal à Internet pour tous les équipements connectés. 
* ### Les enjeux de la modernisation de la connectique
La transition vers la fibre optique s’accélère dans les logements, bureaux et data centers, portée par la demande de débit toujours croissante (streaming 4K, cloud, visioconférence, objets connectés…). Néanmoins, l’hybridation avec les anciennes technologies (coaxial, RJ45) reste nécessaire :
* Coaxial : présent dans les installations TV/Satellite anciennes et dans certaines solutions d’accès Internet haut débit alternatives
* RJ45/Ethernet : indispensable pour la distribution réseau locale, même lorsque la fibre arrive en cœur de bâtiment
* Fibre Optique : cœur de réseau, backbone, solution de très haut débit


### Innovations et perspectives
#### Vers l’ultra haut débit
La fibre optique évolue constamment : nouveaux types de fibre (OM4, OM5 multimode, OS2 monomode), connecteurs plus compacts, architecture passives ou actives (GPON, AON). L’objectif : raccorder le maximum d’utilisateurs tout en couvrant toujours plus de distance et de débit.
#### Connectiques intelligentes : domotique et IoT
Les réseaux hybrides (Ethernet, Wi-Fi, Zigbee, etc.) s’interfacent via des coffrets de communication où la connectique joue un rôle central : pilotage intelligent des équipements multimédia, sécurité, confort et économie d’énergie.


### Conclusion
La connectique moderne (câble coaxial, RJ45, fibre optique)  est la clé de voûte de tous les usages numériques, multimédias et télécoms de la vie quotidienne. Leur compréhension permet d’optimiser les installations, de choisir la solution adaptée et d’accompagner la transition vers le Très Haut Débit et les nouveaux usages connectés. Grâce à la fibre optique, à la modularité du RJ45 et à la robustesse du coaxial, les réseaux s’adaptent à tous les besoins, du particulier à l’entreprise, dans une logique d’innovation continue. 




## 3/ Équipements Réseaux
### Introduction
Le fonctionnement de notre monde numérique repose sur l’infrastructure réseau. Que ce soit pour consulter les réseaux sociaux, envoyer un e-mail professionnel, effectuer un virement bancaire ou simplement regarder une vidéo en streaming, toutes ces actions reposent sur un ensemble d’équipements qui permettent de transporter l’information d’un point A à un point B. Ces équipements, appelés équipements réseaux, constituent le cœur invisible d’Internet et des systèmes d’information en entreprise.
Parmi les plus connus, on retrouve le switch (commutateur) et le routeur, mais ils ne sont pas les seuls. Des pare-feu (firewalls), des points d’accès Wi-Fi, des modems, des hubs ou encore des proxy complètent souvent l’architecture pour assurer connectivité, sécurité et performance. Nous allons voir :
* Ce que sont ces appareils.
* Comment ils fonctionnent conceptuellement.
* À quelles situations concrètes ils s’appliquent.
* Quelques exemples pratiques pour comprendre leur rôle au quotidien.
* Comprendre la communication en réseau
Avant d’entrer dans le détail des équipements, il est crucial de comprendre la logique de base de la communication réseau.
Un réseau informatique est un ensemble d’équipements (ordinateurs, serveurs, smartphones, objets connectés, etc.) qui échangent des données sous forme de paquets. Pour organiser cet échange et éviter le chaos (comme si tout le monde parlait en même temps dans une grande salle), des règles appelées protocoles sont utilisées. Le protocole le plus répandu est TCP/IP, qui oblige chaque équipement à disposer d’une adresse IP unique pour être identifié.Le transfert des données se fait par couches (modèle OSI ou modèle TCP/IP simplifié). Chaque couche utilise des équipements spécifiques. Par exemple : 
* La couche réseau gère l’adressage et fait intervenir les routeurs.
* La couche liaison de données gère les adresses MAC et fait intervenir les switches.
* La couche physique se contente de transmettre des signaux électriques ou optiques, souvent via des câbles, répéteurs ou hubs.
Ainsi, les équipements réseaux jouent chacun un rôle clé selon leur niveau dans cette hiérarchie.


### Le switch (commutateur réseau)
#### Concept
Un switch est un équipement réseau situé au niveau de la couche 2 du modèle OSI (liaison de données). Sa mission est de relier plusieurs machines au sein d’un même réseau local (LAN – Local Area Network). Contrairement au hub (plus ancien), qui se contente de dupliquer les données vers tous les ports, le switch commute intelligemment les trames Ethernet en fonction de l’adresse MAC des machines.
#### Fonctionnement
Chaque machine (PC, imprimante, caméra IP, etc.) possède une adresse MAC unique inscrite dans sa carte réseau. Le switch maintient une table de commutation qui associe chaque adresse MAC au port du switch correspondant.
#### Exemple :
* Le PC1 est connecté au port 1, son adresse MAC est A1:A2:A3.
* Le PC2 est connecté au port 2, son adresse MAC est B1:B2:B3.
Si PC1 veut envoyer un fichier à PC2, le switch lit l’adresse MAC de destination et achemine le paquet uniquement vers le port du PC2, au lieu de saturer tout le réseau.
#### Applications concrètes
* Entreprises : un switch de 24, 48 ports ou plus forme le “point de concentration” des PC, imprimantes, téléphones IP dans un bureau.
* Domotique : un switch compact 5 ports peut centraliser la box Internet, une Smart TV, une console et une borne Wi-Fi.
* Datacenters : des switches haute capacité (10/40/100 Gbit/s) construisent l’ossature interne reliant des milliers de serveurs.
#### Exemple pratique
Dans une PME de 30 salariés, chaque poste de travail est relié par câble RJ45 à un switch 48 ports situé dans une armoire réseau. Lorsque l’assistante imprime un document, seuls les paquets destinés à l’imprimante réseau sont envoyés sur son port. Résultat : la bande passante est optimisée et les flux internes restent secrets pour les autres machines.


### Le routeur
#### Concept
Le routeur est l’équipement réseau qui opère au niveau de la couche 3 (réseau) du modèle OSI. Il a pour rôle de diriger des paquets entre différents réseaux, en utilisant les adresses IP. Le switch reste limité à un seul LAN, tandis que le routeur permet d’interconnecter plusieurs LANs entre eux, ou d’accéder à Internet.
En somme, le routeur est l’aiguilleur du trafic IP.
#### Fonctionnement
Le routeur analyse l’adresse IP de destination du paquet. Il consulte sa table de routage, qui contient les routes possibles pour atteindre différentes adresses ou sous-réseaux. Selon l’algorithme, il choisit le "meilleur chemin" pour transmettre le paquet.
#### Exemple :
Un utilisateur tape l’URL d’un site américain depuis son PC français.
Le PC envoie la requête via le switch -> le routeur local -> le FAI -> routeurs de transit internationaux -> routeur du serveur hébergeant le site -> retour vers l’utilisateur.
Le routage peut être :
* Statique : l’administrateur définit manuellement les chemins.
* Dynamique : les routeurs partagent automatiquement leurs informations via des protocoles (OSPF, BGP, RIP).
#### Applications concrètes
Les box Internet domestiques combinent modem et routeur : elles gèrent la connexion ADSL/Fibre et attribuent des adresses IP aux équipements du foyer.
Une entreprise multisite utilise des routeurs pour interconnecter ses succursales à travers un VPN sécurisé.
Dans le cloud, des routeurs virtuels dirigent le trafic entre différentes zones et clusters d’un fournisseur (AWS, Azure).
#### Exemple pratique
Une famille dispose d’une box routeur. Le PC fixe reçoit l’IP 192.168.1.10, la Smart TV 192.168.1.11 et le smartphone 192.168.1.12. Lorsqu’on lance Netflix sur la TV, le routeur sait sortir le trafic vers Internet et faire correspondre les retours aux bons équipements. Sans lui, la TV ne saurait jamais comment joindre les serveurs Netflix.


### Autres équipements essentiels
#### Le Hub
Équipement de couche physique, aujourd’hui obsolète. Il se contente de diffuser les paquets reçus à tous les ports, ce qui engendre une surcharge et des risques de sécurité.
Exemple : dans une salle de classe des années 2000, un hub 8 ports reliait les PC, mais chaque envoi saturait tout le réseau.
#### Le Modem
Dispositif permettant la communication entre le réseau domestique et le réseau du fournisseur d’accès. Initialement (modems RTC), il modulait/démodulait un signal téléphonique. Aujourd’hui, le modem câble ou fibre traduit les signaux optiques/câblés en données numériques IP.
#### Le Point d’accès Wi-Fi (Access Point)
Équipement qui prolonge un réseau câblé via une interface radio. 
Exemple concret : dans un hôtel, un point d’accès est installé à chaque étage pour fournir du Wi-Fi stable aux clients.
#### Le Pare-feu (Firewall)
Barrière de sécurité filtrant le trafic autorisé ou bloqué en fonction de règles (par IP, port, protocole). 
Application typique : une entreprise bloque les connexions entrantes sauf pour un serveur web public, et empêche les connexions sortantes vers des sites malveillants.
#### Le Proxy
Serveur intermédiaire qui relaie les requêtes entre utilisateur et destination. Il peut jouer plusieurs rôles : cacher l’adresse réelle du client, appliquer des politiques d’accès ou mettre en cache les contenus fréquemment consultés.


### Exemple concret d’infrastructure réseau
Imaginons une PME de 50 salariés. Son infrastructure contient :Un switch central 48 ports connectant les PC, imprimantes, caméras IP.Un routeur de cœur de réseau pour joindre Internet et créer un VPN avec une antenne régionale.Un pare-feu matériel qui protège contre les intrusions.Plusieurs points d’accès Wi-Fi pour les mobiles des employés.Un serveur proxy qui limite l’accès aux contenus non professionnels.À l’échelle domestique, ces fonctions sont souvent fusionnées dans une box : modem + routeur + switch 4 ports + Wi-Fi.


### Importance dans la société moderne
* Éducation : dans une école, un switch relie les PC de la salle informatique, et un routeur connecte le tout à Internet.
* Télémédecine : une clinique utilise un pare-feu et un routeur VPN pour transmettre des imageries médicales à des spécialistes distants.
* Divertissement : chez soi, une console branchée via switch et routeur accède à des serveurs de jeux mondiaux.
* Industrie 4.0 : en usine, des switches industriels connectent capteurs et robots, avec une latence minimale. 


### Conclusion générale
Les équipements réseaux tels que switches et routeurs sont les briques invisibles de l’univers connecté. Le switch organise le trafic interne sur un réseau local grâce aux adresses MAC. Le routeur dirige le trafic entre réseaux via des adresses IP et des protocoles de routage. Autour d’eux gravitent d’autres appareils (modems, points d’accès, firewalls, proxys) qui complètent la panoplie.
Sans eux, Internet, la mobilité, le streaming ou encore le télétravail seraient tout simplement impossibles.
En comprendre le fonctionnement, même de manière vulgarisée, permet de mieux appréhender ce que signifie “se connecter” et pourquoi une panne de routeur ou de switch peut paralyser toute une organisation.




## 4/ L’adressage IPv4


### Introduction
Internet et les réseaux informatiques modernes sont basés sur un langage commun : les adresses IP. Elles servent d’ ”identifiants” uniques pour les machines, un peu comme des adresses postales pour des maisons dans une ville. Sans ce système d’adressage, nos ordinateurs, smartphones, serveurs, imprimantes connectées et objets connectés (IoT) ne pourraient ni communiquer entre eux, ni se repérer dans le gigantesque réseau mondial qu’est Internet.
Aujourd’hui, deux grandes versions de protocole d’adressage coexistent : IPv4 (Internet Protocol version 4) et IPv6 (Internet Protocol version 6). IPv6 est prévu pour remplacer IPv4 à long terme, car ce dernier connaît une pénurie d’adresses depuis plusieurs années. Néanmoins, IPv4 reste massivement utilisé dans les réseaux domestiques, d’entreprise et encore dans de nombreux fournisseurs d’accès à Internet. Il demeure donc essentiel de comprendre dans le détail son fonctionnement.
Nous verrons les fondements de l’adressage IPv4, depuis sa conception jusqu’à ses applications pratiques, en passant par les notions de plages publiques et privées, ainsi que le mécanisme de notation CIDR qui simplifie et optimise sa gestion. Nous allons également illustrer chaque concept par des exemples concrets.


### Le concept de base d’IPv4
Une adresse IPv4 est une série de 32 bits (soit 4 octets) représentant l’identifiant unique d’un hôte ou d’une interface réseau. Ce nombre binaire de 32 chiffres (faits uniquement de 0 et de 1) peut être converti en une notation plus lisible pour les humains : la notation décimale pointée.
Ainsi, une adresse IPv4 typique ressemblera à ceci :192.168.1.15
Chaque nombre séparé par un point représente un octet (ou « octet de poids ») allant de 0 à 255. 
Par exemple, l’adresse ci-dessus en binaire s’écrit :
11000000.10101000.00000001.00001111


### Structure d’une adresse IPv4
Une adresse IPv4 est composée de deux parties :
* Le préfixe réseau : il identifie le réseau auquel appartient la machine.
* Le suffixe hôte : il identifie de manière unique la machine (ou l’interface) à l’intérieur de ce réseau.
C’est grâce à cette structure binaire divisée que l’on peut hiérarchiser et organiser l’espace d’adressage.


### Exemple concret :
Dans l’adresse 192.168.1.15/24, les 24 premiers bits (notés avec “/24”) représentent le réseau (soit 192.168.1.0), et les 8 derniers correspondent à l’hôte, c’est-à-dire le périphérique particulier (.15 dans ce cas).


### Les classes d’adresses IPv4
Historiquement, avant l’introduction du CIDR, les adresses IPv4 étaient organisées en classes prédéfinies (A, B, C, D et E). Ces classes répartissaient l’espace d’adressage en fonction des besoins : grands réseaux, réseaux moyens, petits réseaux.
* Classe A : adresses allant de 0.0.0.0 à 127.255.255.255, avec un masque par défaut /8.
Exemple de réseau : 10.0.0.0/8
* Classe B : adresses de 128.0.0.0 à 191.255.255.255, masque /16.
Exemple : 172.16.0.0/16
* Classe C : adresses de 192.0.0.0 à 223.255.255.255, masque /24.
Exemple : 192.168.1.0/24
* Classe D : adresses de 224.0.0.0 à 239.255.255.255, réservées pour le multicast.
* Classe E : 240.0.0.0 à 255.255.255.255, réservées pour des usages expérimentaux et de recherche. 
Cette classification a longtemps été utilisée, mais elle s’est révélée trop rigide car elle entraînait un gaspillage d’adresses. Pour y remédier, le CIDR (Classless Inter-Domain Routing) est apparu dans les années 1990, permettant une gestion plus fine (nous y revenons plus loin).
### Les adresses IPv4 privées et publiques
Toutes les adresses IPv4 ne sont pas utilisables sur Internet. Certaines plages spécifiques ont été réservées pour un usage en réseaux locaux (LAN). Ces adresses sont dites privées, tandis que les autres sont publiques.
#### Les adresses IPv4 privées
Les adresses privées sont définies par la norme RFC 1918. Elles ne sont jamais routées sur Internet : un routeur les bloque s’il les rencontre en dehors de leur usage prévu.
Elles sont destinées aux réseaux internes, tels que :
* Les réseaux domestiques (box Internet)
* Les réseaux d’entreprise
* Les environnements de test ou de laboratoire virtuel
Trois plages principales sont réservées :
10.0.0.0 – 10.255.255.255 (/8)172.16.0.0 – 172.31.255.255 (/12)192.168.0.0 – 192.168.255.255 (/16)
Exemple concret :
La plupart des box Internet attribuent par défaut des adresses comme 192.168.1.x aux appareils connectés au Wi-Fi.
#### Les adresses IPv4 publiques
Toutes les autres adresses, hors plages privées et réservées, sont des adresses publiques. Elles sont uniques sur Internet et attribuées par des registres appelés RIR (Regional Internet Registries). Ces adresses permettent une identification unique sur le réseau mondial.
Exemple :
Un site Web comme Google peut avoir une adresse publique telle que 142.250.190.14.


### Les adresses spéciales
Certaines adresses ont des usages bien précis :
* 127.0.0.1 : l’adresse de loopback ou localhost, utilisée pour communiquer avec soi-même.
* 169.254.0.0/16 : les adresses APIPA (Automatic Private IP Addressing), attribuées automatiquement quand aucun serveur DHCP n’est joignable.
* 255.255.255.255 : adresse de broadcast, utilisée pour s’adresser à toutes les machines d’un sous-réseau.


### Les masques de sous-réseau et la notation CIDR
#### Qu’est-ce qu’un masque ?
Un masque de sous-réseau indique quelle partie de l’adresse correspond au réseau et quelle partie correspond à l’hôte.
Un masque est aussi une série de 32 bits, composée de 1 (bits réseau) suivis de 0 (bits hôte).
Exemple :
Masque /24 = 255.255.255.0
Soit en binaire :
11111111.11111111.11111111.00000000
#### La notation CIDR
La notation CIDR (Classless Inter-Domain Routing) a modernisé la manière de représenter les réseaux depuis 1993.
Au lieu de limiter les réseaux à des masques par défaut (A, B, C), le CIDR permet d’indiquer n’importe quel nombre de bits. 
On note ainsi le préfixe réseau avec /nombre.
Exemples :
* 192.168.1.0/24 : réseau contenant 256 adresses (254 utilisables).
* 192.168.1.0/25 : réseau contenant 128 adresses (126 utilisables).
* 10.0.0.0/12 : réseau de 1 048 576 adresses (énorme plage privée).
#### Utilité du CIDR
* Réduire le gaspillage d’adresses.
* Faciliter la hiérarchisation et l’agrégation des routes dans les tables de routage.
* Permettre un découpage fin et adapté aux besoins réels.


### Applications concrètes de l’adressage IPv4
#### Dans un réseau domestique
Prenons le cas d’une box Internet. 
Elle reçoit une adresse publique IPv4 de son fournisseur d’accès, par exemple : 82.154.22.47.
Ensuite, elle crée un réseau interne privé, souvent 192.168.1.0/24, et attribue :
* à elle-même l’adresse 192.168.1.1
* aux appareils du foyer des adresses comme 192.168.1.5 (PC), 192.168.1.10 (smartphone), etc.
Grâce à la traduction d’adresse (NAT, Network Address Translation), tous ces appareils accèdent à Internet via l’adresse publique unique 82.154.22.47.
#### Dans une entreprise
Une entreprise peut utiliser les plages privées pour son réseau interne (ex. 10.0.0.0/16). 
Chaque département peut recevoir un sous-réseau, par exemple :
* 10.0.10.0/24 pour les ressources humaines
* 10.0.20.0/24 pour les développeurs
* 10.0.30.0/24 pour les serveurs
Cela facilite la gestion, la sécurité et le routage interne.
#### Dans le cloud et les datacenters
Les serveurs dans le cloud utilisent souvent à la fois : 
* Des adresses privées pour la communication interne au datacenter.
* Des adresses publiques pour être accessibles aux clients d’Internet.
Par exemple, un serveur AWS peut être configuré avec une IP privée 172.31.25.12 mais être exposé au monde via une IP publique 54.72.115.9.


### Exemples détaillés chiffrés
#### Exemple 1 : réseau domestique simple
* Adresse WAN (publique) : 81.220.13.58
* Réseau LAN : 192.168.0.0/24
* Box/routeur : 192.168.0.1
* PC fixe : 192.168.0.10
* Imprimante Wi-Fi : 192.168.0.20
* Smartphone : 192.168.0.25
Le NAT permet à tout ce réseau d’utiliser la seule adresse publique 81.220.13.58.
#### Exemple 2 : sous-réseaux en entreprise
Si une entreprise dispose de 192.168.100.0/24 mais souhaite scinder pour mieux gérer ses services :
* 192.168.100.0/26 (64 adresses) pour le département marketing
* 192.168.100.64/26 (64 adresses) pour le support
* 192.168.100.128/25 (128 adresses) pour le reste du personnel
Le CIDR permet un découpage optimal de l’espace disponible.


### Problèmes liés à IPv4
* Pénurie d’adresses disponibles : seulement environ 4,3 milliards d’adresses (2^32). Aujourd’hui, tout est connecté : ordinateurs, smartphones, objets connectés, serveurs, véhicules, capteurs… D’où une saturation.
* NAT obligatoire : les réseaux privés utilisent massivement la traduction d’adresses, qui complexifie le fonctionnement (impossible par défaut d’accéder directement à un PC derrière une box).
* Sécurité insuffisante en soi : IPv4 ne contient pas de chiffrement par défaut.


### Transition vers IPv6
Pour répondre à la pénurie, IPv6 a été introduit, avec des adresses de 128 bits, soit une quantité astronomique (3,4 x 10^38 adresses). 
IPv6 permet également des fonctionnalités modernes, mais comme expliqué plus tôt, l’IPv4 reste omniprésent, et la coexistence durera encore longtemps.


### Explication par analogie
On peut comparer l’IPv4 au système d’adresses postales d’une ville :
* Le réseau correspond au nom de la rue (ex. "rue des Fleurs").
* Le numéro de la maison équivaut au numéro de l’hôte (ex. "numéro 15").
* Le masque correspond à la grille de découpage de la ville qui délimite jusqu’où va une rue.
Les adresses privées sont comme des numéros de maison valables uniquement à l’intérieur d’un lotissement privé, ou les numéros de bungalow d’un camping.
Les adresses publiques sont celles qui sont visibles sur la carte globale de la ville.


### Conclusion
L’adressage IPv4 est à la fois un concept technique et une réalité quotidienne invisible pour l’utilisateur moyen, mais absolument vital pour le fonctionnement d’Internet. 
Composé de 32 bits, il permet d’identifier les machines sur un réseau, en distinguant les parties réseau et hôte grâce aux masques et à la notation CIDR. 
La distinction entre adresses privées et publiques rend possible l’usage massif des objets connectés, notamment grâce à la traduction d’adresses (NAT).
Avec ses limites, notamment la pénurie, IPv4 est complété (mais pas encore remplacé) par IPv6. 
Aujourd’hui encore, comprendre IPv4 reste indispensable pour tout informaticien, administrateur réseau ou simplement utilisateur curieux de savoir comment son ordinateur communique avec le monde.


## 5/ Les protocoles réseau 
*(Ethernet, ICMP, DNS, DHCP, IMAP, POP3, SMTP, RIP/OSPF, TCP, UDP, HTTP)*
Les protocoles réseau sont les “langues” qui permettent aux ordinateurs et autres appareils connectés d’échanger des informations de manière ordonnée et compréhensible. 
Sans eux, Internet et les réseaux privés ne pourraient pas fonctionner. 
Nous allons aborder ensemble onze des plus importants protocoles.


### Ethernet
#### Concept
Ethernet est un protocole de communication qui définit comment les machines connectées à un même réseau local (LAN) échangent des données. 
C’est un protocole bas niveau, proche du matériel (câbles, cartes réseau, switches). 
Il définit la manière d’encapsuler les informations dans des trames, qui contiennent les adresses physiques MAC.
#### Application concrète
Chaque fois qu’un ordinateur, une console de jeu ou une imprimante est reliée par câble à une box ou à un switch, l’échange se fait via Ethernet. 
Sa fiabilité et sa simplicité expliquent pourquoi il reste dominant depuis les années 1980, malgré l’essor du Wi-Fi.
Dans un bureau, quand 20 ordinateurs sont connectés à un switch, Ethernet gère quel ordinateur “parle” à quel autre sans confusion.
Les trames Ethernet incluent une adresse source (MAC de la carte réseau envoyant) et une adresse de destination, ce qui garantit que seuls les bons destinataires reçoivent les données.
#### Exemple concret
Vous envoyez un fichier à une imprimante réseau. 
Votre PC encapsule la demande d’impression dans une trame Ethernet avec l’adresse MAC de l’imprimante. 
Même si d’autres machines sont branchées sur le même switch, seule l’imprimante comprend et traite la trame.


### ICMP
#### Concept
ICMP (Internet Control Message Protocol) n’est pas fait pour transmettre du contenu (comme des pages web) mais pour envoyer des messages de contrôle et de diagnostic. 
Il aide à surveiller la santé du réseau.
#### Application concrète
Un des outils les plus connus utilisant ICMP est la commande ping. 
Quand on “ping” un site, votre machine envoie un message ICMP “echo request” et attend la réponse “echo reply”. 
Cela permet de vérifier :
* si la machine est joignable 
* combien de temps prennent les paquets pour l’atteindre
#### Exemple
Votre connexion Internet semble lente. 
Vous tapez ping www.google.com. 
Votre ordinateur envoie quatre paquets ICMP. 
Si vous voyez des réponses avec “temps = 30 ms”, cela prouve que la communication fonctionne mais prend 30 millisecondes pour l’aller-retour.
Si aucune réponse n’arrive, le réseau est coupé (ou alors le serveur est volontairement configuré à ignorer les pings :-P).


### DNS
#### Concept
DNS (Domain Name System) est le “répertoire téléphonique” d’Internet. 
Il traduit les noms faciles à retenir par les humains (www.wikipedia.org) en adresses IP numériques (par ex. 208.80.154.224). 
Sans lui, il faudrait se souvenir uniquement de suites de chiffres.
#### Application concrète
Chaque fois que vous entrez une adresse dans votre navigateur ou cliquez sur un lien, un serveur DNS est consulté. 
C’est un protocole hiérarchique avec :
* des serveurs racine qui connaissent l’existence de tous les TLD (.com, .org, .fr, etc.)
* des serveurs de domaines (exemple : qui gèrent “wikipedia.org”)
* un mécanisme de cache pour éviter de redemander à chaque fois
#### Exemple
Quand vous tapez “www.lemonde.fr” :
Votre ordinateur demande à un serveur DNS 
“quelle est l’adresse IP de www.lemonde.fr ?”
Le serveur répond avec l’adresse IP (comme 145.226.xxx.xxx).
Le navigateur peut alors communiquer directement avec le serveur web du journal.


### DHCP
#### Concept
DHCP (Dynamic Host Configuration Protocol) automatise l’attribution d’adresses IP aux machines d’un réseau. 
Sans lui, il faudrait configurer manuellement chaque ordinateur avec son adresse IP, son masque de sous-réseau, sa passerelle et son serveur DNS.
#### Application concrète
Quand vous connectez votre PC ou smartphone à une box Internet, le protocole DHCP attribue automatiquement une adresse comme “192.168.1.14”.
Cela évite les conflits d’adresse et assure que chaque machine est identifiée correctement.
Dans notre TP où deux VM devaient communiquer, nous avons dû fixer les IP afin que le DHCP ne les change pas au redémarrage. Mais cela a nécessité de la viligeance, afin de ne pas attribuer une même IP fixe à deux machines différentes. 
#### Exemple concret
Vous invitez des amis chez vous. 
Ils se connectent au Wi-Fi. 
Chaque téléphone envoie au réseau : “J’ai besoin d’une adresse IP”. 
Le serveur DHCP de la box répond : “Tu peux utiliser 192.168.1.23 pour la durée de ton passage”, personne d'autre ne l'utilise. 
Tout est fait automatiquement, sans intervention manuelle.


### IMAP
#### Concept
IMAP (Internet Message Access Protocol) est un protocole de gestion des emails. 
Il permet de consulter ses messages tout en les laissant stockés sur le serveur. 
L’utilisateur peut organiser ses dossiers (boîte de réception, envoyés, brouillons, etc.) et retrouver la même organisation sur plusieurs appareils.
#### Application concrète
Si vous lisez vos emails sur votre PC le matin et sur votre smartphone le soir, IMAP garde une synchronisation centralisée.
Les courriels ne sont pas supprimés du serveur sauf indication explicite.
#### Exemple
Vous consultez un mail de votre banque depuis votre smartphone. 
Vous ne l’avez pas encore supprimé. 
Le soir, vous ouvrez Outlook sur PC : 
le même mail s’y trouve encore, car IMAP a synchronisé les dossiers.


### POP3
#### Concept
POP3 (Post Office Protocol version 3) est un autre protocole de consultation du courrier électronique. 
Contrairement à IMAP, il télécharge les mails du serveur et les efface souvent ensuite (selon configuration).
#### Application concrète
POP3 était très utilisé quand les serveurs avaient peu d’espace de stockage.
Il convient bien pour quelqu’un qui lit ses mails uniquement depuis un seul appareil.
#### Exemple concret
Un utilisateur configure son client Outlook en POP3. 
Chaque matin, Outlook télécharge les mails et les supprime du serveur. 
L’espace du serveur reste libre, mais si l’utilisateur veut les lire depuis son téléphone, ce ne sera plus possible (ils sont stockés localement sur le PC).


### SMTP
#### Concept
SMTP (Simple Mail Transfer Protocol) est le protocole qui sert à envoyer des courriels, contrairement à IMAP/POP3 qui permettent de recevoir.
#### Application concrète
Chaque fois que vous cliquez sur “envoyer” dans votre boîte mail, votre ordinateur utilise SMTP pour livrer votre message au serveur de messagerie, lequel le transmet au serveur du destinataire.
#### Exemple
Vous envoyez un mail avec Gmail à un ami qui utilise Yahoo. 
Gmail utilise SMTP pour transférer le message. 
Yahoo reçoit alors l’email et le place dans la boîte de réception de votre ami.


### RIP et OSPF
#### Concept
Ces deux protocoles appartiennent à la famille des protocoles de routage dynamique. 
Leur but est d’aider les routeurs à déterminer le meilleur chemin pour transmettre des paquets à travers un réseau complexe.
* RIP (Routing Information Protocol) : 
un des plus anciens, basé sur la distance (nombre de “sauts” de routeurs). 
Simple, mais limité en efficacité et vitesse.
* OSPF (Open Shortest Path First) : protocole plus sophistiqué, qui calcule le chemin le plus rapide en tenant compte de la bande passante et d’autres métriques.
#### Application concrète
Dans une grande entreprise avec plusieurs bâtiments reliés en réseau, les routeurs doivent savoir par quel chemin envoyer les données.
Avec RIP/OSPF, les routeurs s’échangent régulièrement leurs cartes du réseau et s’ajustent automatiquement si une liaison tombe en panne.
#### Exemple
Si la liaison entre deux bâtiments tombe, OSPF détecte la panne et trouve une route alternative. 
Ainsi, les employés n’ont pas de coupure. 
RIP le ferait aussi, mais de manière plus lente et moins optimisée.


### TCP
#### Concept
TCP (Transmission Control Protocol) est un protocole de transport, c’est-à-dire qu’il agit entre l’application et Internet. 
Sa force est de fournir une communication fiable et ordonnée entre machines. 
TCP s’assure que toutes les données arrivent, qu’elles arrivent dans le bon ordre, et qu’aucune n’est perdue.
#### Application concrète
Beaucoup de sites web, messageries et transferts de fichiers utilisent TCP.
Quand vous téléchargez un fichier, TCP se charge de réémettre les paquets perdus.
Il divise les données en “segments”, les numérote et vérifie que rien ne manque.
#### Exemple
Vous téléchargez un PDF de 20 Mo. 
Pendant le transfert, deux paquets sont perdus. 
TCP le détecte et redemande uniquement les paquets manquants au serveur. 
Le fichier final sera identique à l’original.


### UDP
#### Concept
UDP (User Datagram Protocol) est aussi un protocole de transport, mais sans les garanties de TCP. 
Il envoie les paquets sans vérifier leur ordre ni s’ils arrivent tous. 
Cela dit, il est beaucoup plus rapide. 
C’est comme choisir de lancer votre linge salle dans le panier comme si vous jouiez au basket. Vous n’êtes pas sûr de tout mettre dans le panier, mais vous allez gagner du temps. 
#### Application concrète
UDP est souvent utilisé pour :
* les jeux vidéo en ligne
* les appels téléphoniques sur Internet (VoIP)
* le streaming vidéo en direct
Dans ces cas, perdre un paquet n’est pas dramatique, car il vaut mieux avoir une communication fluide que parfaite.
#### Exemple
Vous suivez un match en direct en streaming HD. 
Si un petit paquet d’images manque, vous voyez un pixel glitché ou un saut, mais le match ne s’arrête pas. 
UDP continue d’envoyer le flux sans attendre les données manquantes.


### HTTP
#### Concept
HTTP (HyperText Transfer Protocol) est le protocole de communication entre les navigateurs (clients) et les serveurs web. 
C’est grâce à lui que l’on accède à des pages web, des images, des vidéos, etc.
Aujourd’hui, il est presque toujours utilisé en version sécurisée HTTPS, qui chiffre les échanges pour éviter l’espionnage.
#### Application concrète
En ouvrant n’importe quel site (Amazon, Wikipédia, réseaux sociaux), votre navigateur envoie une requête HTTP aux serveurs du site. 
Ceux-ci répondent avec du contenu (HTML, CSS, JavaScript), que votre navigateur transforme en page lisible.
#### Exemple
* Vous tapez “https://www.wikipedia.org”. 
* Votre navigateur envoie une requête HTTP “GET /” au serveur de Wikipédia. 
* Celui-ci renvoie le code HTML de la page d’accueil. 
* Votre navigateur interprète ce code et affiche le site.


### Conclusion
Ces protocoles sont les fondations silencieuses d’Internet et des réseaux modernes. 
Chacun a son rôle spécifique :
* Ethernet relie les appareils localement.
* ICMP vérifie leur bon fonctionnement.
* DNS traduit les adresses compréhensibles.
* DHCP distribue les configurations automatiques.
* IMAP/POP3 consultent les mails.
* SMTP les envoie.
* RIP/OSPF guident les paquets dans les réseaux complexes.
* TCP garantit la fiabilité.
* UDP privilégie la vitesse.
* HTTP transporte les pages web.
Sans l’interaction cohérente de tous ces protocoles, aucune application quotidienne (naviguer, écrire un mail, jouer en ligne) ne serait possible.


## 6/ Comparatif détaillé TCP/UDP


### Introduction 
TCP (Transmission Control Protocol) et UDP (User Datagram Protocol) sont deux des protocoles principaux de la couche transport dans le modèle TCP/IP, qui gouverne la communication réseau sur internet et dans les réseaux locaux. 
Bien qu’ils servent tous deux à transmettre des données entre machines, TCP et UDP ont des architectures, des mécanismes et des usages très différents.
TCP est un protocole orienté connexion : il établit une connexion fiable et ordonnée entre l’émetteur et le récepteur avant tout échange de données. 
En revanche, UDP est un protocole sans connexion qui envoie les données sans garantie d’arrivée ni d’ordre, privilégiant la simplicité et la rapidité.


### Différences conceptuelles majeures
—
| Caractéristiques | TCP | UDP |
—---------------------------------------
| Type de protocole | Orienté connexion | Sans connexion |
| Fiabilité | Garantie via accusés de réception et retransmissions | Pas de garantie, pas de retransmission |
| Contrôle d'erreur | Correction des erreurs, retransmission | Simple somme de contrôle, pas de correction |
| Ordonnancement | Données reçues dans l’ordre envoyé | Données peuvent arriver dans le désordre |
| Contrôle de flux | Oui, contrôle de congestion | Non |
| Taille de l’en-tête | Plus volumineuse (au moins 20 octets) | Très léger (8 octets) |
| Vitesse | Plus lent dû aux mécanismes de fiabilité | Plus rapide car sans surcharge (jusqu’à x8) |
| Usage type | Transfert fiable, applications critiques | Applications temps réel, streaming, jeux |


Les en-têtes TCP comportent des informations complexes telles que le numéro de séquence, l’accusé de réception, la taille de la fenêtre et d’autres options qui assurent la fiabilité, tandis que l’en-tête UDP contient seulement les ports source et destination, la longueur et une somme de contrôle basique. 


### Fonctionnement détaillé
#### TCP : un protocole fiable et ordonné
TCP établit une connexion avec un handshake en trois étapes (SYN, SYN-ACK, ACK) avant d’échanger les données. 
Chaque segment transmis est numéroté, et le destinataire accuse réception des données reçues correctement. 
En cas de perte, les segments sont retransmis.
Cela engendre un contrôle de flux et de congestion pour éviter la surcharge du réseau.
Cette fiabilité assure que la donnée réseau arrive intègre, complète et dans l'ordre exact, ce qui est essentiel pour de nombreuses applications critiques comme le transfert de fichiers, les emails, ou la navigation web.
#### UDP : simplicité et rapidité
UDP transmet simplement les paquets (datagrammes) sans établir de connexion ni assurer leur arrivée. 
Il n’y a ni numéro de séquence, ni accusé de réception. 
Le protocole repose sur la couche application pour gérer d’éventuelles pertes ou erreurs.
Cela réduit la latence au minimum et permet des transmissions au plus proche du temps réel, au prix d’une possible perte ou désordre des données. 
Idéal pour des usages où la vitesse prime sur la fiabilité : streaming vidéo ou audio, jeux en ligne, appels en VoIP, ou DNS.


### Applications pratiques


| Application | Protocole privilégié | Raisons principales |
—---------------------------------------
| Transfert de fichiers (FTP, SCP) | TCP | Fiabilité et intégrité des données |
| Navigation web (HTTP/HTTPS)  | TCP  |  Fiabilité et ordonnancement pour affichage correct |
| Envoi d’emails (SMTP, IMAP)  | TCP | Transmission garantie des messages  |
| Appels VoIP (SIP, RTP)  | UDP  | Faible latence, tolérance à la perte de paquets  |
|  Jeux en ligne multijoueur | UDP  | Vitesse, réactivité même si quelques paquets sont perdus  |
| Streaming vidéo en direct  | UDP  | Rapidité, faible latence, perte acceptable  |
| Requêtes DNS  | UDP | Rapidité, peu de données transférées, demande/réponse simple  |


### Exemples concrets
* Un serveur web utilise TCP pour garantir que toutes les parties d’une page arrivent dans l’ordre
* Un jeu en ligne utilise UDP pour minimiser les délais quoiqu’il arrive même si cela implique parfois une perte de données.


### Benchmarks et performances
* Latence: UDP a une latence bien plus faible que TCP car il n’y a pas d’établissement de connexion ni d’accusés de réception.
* Débit: UDP peut atteindre des débits plus élevés car il ne retransmet pas ni ne contrôle la congestion.
* Consommation de ressources: TCP utilise plus de mémoire et CPU à cause de la gestion de la connexion, retransmission, contrôle de flux, alors qu’UDP est très léger.
* Robustesse réseau: TCP s’adapte à la congestion et évite la saturation du réseau, ce que UDP ne fait pas, ce qui peut engendrer des pertes importantes sur des réseaux chargés.
* Des optimisations modernes comme TCP Fast Open (TFO) ou Multipath TCP (MPTCP) réduisent la latence TCP sans sacrifier la fiabilité, mais UDP reste quasi systématiquement plus rapide dans les scénarios temps réel.


### Avantages et inconvénients
#### TCP
Avantages :
* Garantie que les données arrivent complètes et ordonnées.
* Gestion automatique des erreurs, retransmissions.
* Contrôle de congestion et flux pour stabilité réseau.
* Adapté aux applications nécessitant robustesse (web, email, transfert fichiers).
Inconvénients :
* Latence plus élevée due au handshake et mécanismes.
* Surcharge protocolaire plus importante (en-tête plus long).
* Performances affectées sur réseaux instables ou communication lente.
#### UDP
Avantages :
* Simplicité du protocole, encombrement réseau minimal (header léger).
* Très faible latence, idéal pour applications en temps réel.
* Meilleure performance sur réseaux rapides pour transfert rapide.
Inconvénients :
* Pas de garantie de livraison ou d’ordre des paquets.
* Risque de perte de données sans récupération automatique.
* Nécessite que la couche application gère la fiabilité si besoin.


### Alternatives à TCP et UDP
#### QUIC
Protocole développé par Google et maintenant normalisé par l’IETF. 
Fonctionne au-dessus d’UDP, combine la rapidité et faible latence avec la fiabilité habituellement associée à TCP. 
QUIC intègre chiffrement, multiplexage, et correction d’erreurs avancée pour le web moderne.
#### SCTP: Stream Control Transmission Protocol
Un protocole orienté connexion avec des fonctions avancées comme la multipath et plusieurs canaux, visant une fiabilité améliorée surtout pour la signalisation dans les télécoms.
#### DCCP: Datagram Congestion Control Protocol
DCCP offre un contrôle de congestion pour les transmissions basées sur datagrammes, intermédiaire entre TCP et UDP.


Ces alternatives essaient de combiner les bénéfices des deux familles de protocoles tout en minimisant leurs limites.


### Exemples d’utilisation approfondis
#### HTTP/HTTPS (TCP)
HTTP utilise TCP pour s’assurer que toutes les parties des pages web et fichiers multimédia arrivent correctement. 
La nature transactionnelle du web nécessite la fiabilité.
#### DNS (UDP en majorité)
Les requêtes DNS sont généralement envoyées via UDP pour rapidité, la requête/réponse étant brève et l’application pouvant gérer une nouvelle requête en cas de perte.
#### VoIP (UDP)
Protocoles SIP et RTP s’appuient sur UDP pour transmettre les données audio en temps réel avec un minimum de délai.
#### Streaming vidéo live (UDP)
Services comme Twitch utilisent UDP pour que la vidéo arrive rapidement même s’il y a des pertes mineures.
#### Transferts de fichiers SSH, FTP (TCP) 
Garantissent l’intégralité des fichiers transférés avec contrôle strict.


### Conclusion
TCP et UDP incarnent deux philosophies différentes du transport réseau. 
TCP privilégie la fiabilité, la stabilité et l’ordre, sacrifiant la rapidité au profit d’une communication garantie. 
UDP maximise la vitesse et la simplicité, laissant à la couche application la gestion d'éventuelles pertes, ce qui le rend irremplaçable pour des usages temps réel où la latence critique prime.
Le choix entre TCP et UDP dépend donc des impératifs métiers. 
Des alternatives comme QUIC émergent pour conjuguer le meilleur des deux mondes. 
Comprendre ces différences et leurs conséquences pratiques est essentiel pour concevoir des réseaux, applications et services performants et adaptés.




## 7. Étude du paquet IPv4


### Objectif et Contexte
Cette manipulation vise à isoler et analyser le trafic réseau généré par un test de connectivité forcé en IPv4 (ping -4 www.google.com). L'analyse se concentre sur la séquence de résolution de noms DNS, la structure des paquets ICMPv4, et la validation de la communication via la pile protocolaire TCP/IP jusqu'au niveau d'encapsulation de la couche Liaison de Données (L2).


### Mise en place du protocole
Pour cette étude j’ai installé et configuré WireShark. 
Je l'ai lancé, l’ai placé à gauche de mon écran, puis ai ouvert le terminal. 
J’ai cliqué sur Eth0 car je suis connecté en Ethernet. 
Puis j’ai lancé un ping à Google


### Analyse du Flux Global
Le flux capturé dans Wireshark illustre une communication classique en trois phases (Trames 1 à 9) :


* A. Phase I : Résolution DNS (Couche 5, 4, 3, 2)
Le client (192.168.1.4) interroge le serveur DNS (192.168.1.254) pour obtenir l'adresse IP de www.google.com.
Trames 2, 3 (Requêtes) : Le client émet des requêtes DNS standard (Standard query A www.google.com) à la recherche de l'A record (IPv4).
Encapsulation : Ces requêtes transitent par la pile DNS/UDP/IPv4/Ethernet II.
Trame 4 (Réponse A) : Le serveur DNS répond avec l'adresse IPv4 de Google (142.250.201.164).
Trame 5 (Requête AAAA) : Le client effectue également une requête pour l'AAAA record (IPv6) suite à la politique Happy Eyeballs, même si l'outil ping -4 n'utilisera pas cette information.


* B. Phase II : Test de Connectivité (ICMPv4)
Après avoir obtenu l'adresse IPv4 (142.250.201.164), le client initie les paquets de test.
Trames 6 et 7 (Échange ICMP) : L'échange de paquets ICMPv4 entre le client (192.168.1.4) et le serveur Google (142.250.201.164) est clairement visible.
Trame 6 : ICMP Echo (ping) reply de Google au client. (Réponse de Google reçue en premier dans cette capture partielle).
Trame 7 : ICMP Echo (ping) request du client à Google.
Observation : Contrairement à un flux de paquets parfait, la trame 6 (réponse) apparaît avant la trame 7 (requête) dans la capture. Cela est courant et souvent dû au fait que la réponse a mis moins de temps à atteindre la carte réseau de capture que la requête pour être processée et affichée dans le buffer de Wireshark. L'important est la corrélation par le Sequence Number (seq=1/6) et l'ID (0x0cbb/0x0cbb).


* C. Phase III : Résolution Inverse (DNS PTR)
Trames 8 et 9 : Le système client effectue des requêtes DNS PTR inverses pour l'adresse de Google (164.201.250.142.in-addr.arpa).
Raison : Cette opération est souvent exécutée par le shell ou par le système d'exploitation pour afficher le nom d'hôte dans le terminal à la place ou en plus de l'adresse IP pure.


### Paquet ICMPv4 (Trame 7) :
L'analyse de la trame 7 (requête ICMP sélectionnée) met en évidence les champs clés de la pile IPv4 :
* A. Couche 2 : Liaison de Données (Ethernet II)
Source MAC (Src) : IngramMl_25:8e:c8 (18:86:37:25:8e:c8).
Destination MAC (Dst) : PcsCompu_6e:ab:bc (08:00:27:6e:ab:bc).
Observation : Les adresses MAC indiquent la communication sur le segment LAN. La destination MAC correspond à la carte réseau du client, car cette trame est une réponse (Source IP Google, Destination IP Client) envoyée par le routeur local. Le champ Type d'Ethernet est implicitement 0x0800 (IPv4).


* B. Couche 3 : Réseau (Internet Protocol Version 4)
Version : 4 (Validation de l'objectif du TP).
Source IP (Src) : 142.250.201.164 (Serveur Google).
Destination IP (Dst) : 192.168.1.4 (Client).
Time To Live (TTL) : 114 (dans la requête ICMP, trame 7). Cette valeur élevée indique un nombre de hops restant important (valeur initiale probable de 128), attestant que le paquet a traversé le réseau mondial.
Protocole : 1 (ICMP). Ce champ indique que le protocole de la couche supérieure encapsulé est ICMP.


* C. Couche 3 (suite) : ICMP (Internet Control Message Protocol)
Type : 8 (Echo (ping) request) ou 0 (Echo (ping) reply).
Code : 0.
Identifiant (ID) : 0x0cbb.
Sequence Number (Seq) : 6 (pour la requête de la trame 7).


### Conclusion
La capture confirme la transition réussie vers un flux de communication IPv4 en utilisant l'option ping -4. La séquence DNS, l'encapsulation ICMP/IPv4/Ethernet II et la résolution inverse DNS (PTR) sont clairement validées. Cette analyse souligne l'importance des outils de dissection pour comprendre la complexité des communications réseaux, où même un simple ping active une chaîne complète de protocoles du modèle TCP/IP.




## 8. Étude du paquet IPv6. 
###  Objectif du TP
​L'objectif de cette manipulation était d'observer, de capturer et de décortiquer les paquets générés par une requête de connectivité de base (ping www.google.com) afin de valider la compréhension des modèles de communication OSI/TCP-IP, des mécanismes de résolution de noms (DNS) et du protocole ICMPv6 dans un environnement dual-stack typique (IPv4/IPv6).


​### Analyse de la Séquence de Capture
​La capture démontre une séquence d'événements réseau bien ordonnée, révélatrice du processus d'établissement d'une communication IP.
* ​A. Phase de Résolution de Noms (DNS)
​Avant d'émettre le premier paquet ICMP, le client (192.168.1.4) interroge son serveur DNS (probablement la gateway locale, 192.168.1.254).
​Trame type: Standard query 0x**** PTR 4.0.0.0.2.0.0.0.... (Voir trames 17.5, 22.0, 27.0).
​Protocole : DNS (UDP). Le protocole DNS utilise ici UDP (User Datagram Protocol) sur le port 53.
​Observations Clés :
​On note des requêtes PTR (Pointer Record) inverses pour l'adresse de l'interface locale (1.4.168.192.in-addr.arpa). Ces requêtes inverses sont souvent générées par des applications ou des services système tentant d'associer une adresse IP à un nom d'hôte (résolution inverse), non directement liées au ping lui-même mais révélatrices de l'activité de fond de l'OS.
​L'affichage du terminal montre que la résolution pour www.google.com a abouti à une adresse IPv6 (e.g., 2a00:1450:4007:81a::2004), ce qui explique l'utilisation subséquente d'ICMPv6.
* ​B. Phase de Test de Connectivité (ICMPv6)
​Une fois l'adresse IPv6 obtenue, le client envoie des paquets de test.
​Protocole : ICMPv6 (Internet Control Message Protocol version 6). Ce protocole de la couche Réseau (L3) est fondamental pour le diagnostic et le signalement d'erreurs.
​Flux : On observe l'alternance parfaite entre les paires Echo (ping) request et Echo (ping) reply (trames 19.9/20.6, 23.0/24.7, 28.0/28.8).
​Champs ICMPv6 Dissectés (Trame 28.8, encadrée) :
​Type : 129 (Echo (ping) reply).
​Code : 0.
​Identifier (ID) : 0x0cdc. Ce champ permet au client de corréler toutes les réponses à une même série de pings.
​Sequence Number (Seq) : 5 (Visible dans la réponse reply de la trame 28.8, faisant écho à une requête request avec seq=5). C'est l'indice d'ordonnancement pour détecter les paquets perdus.
​Hop Limit : 64 dans la requête, 248 dans la réponse (valeur du TTL).


​### Dissection des Couches (Trame ICMPv6 Sélectionnée)
​La vue détaillée de la trame 28.8 (réponse ICMPv6) illustre la pile de protocoles :
* A. Couche 2 : Liaison de Données (Ethernet II)
​Source MAC : IngramMl_25:8e:c8 (18:86:37:25:8e:c8)
​Destination MAC : PcsCompu_6e:ab:bc (08:00:27:6e:ab:bc)
​Note : L'adresse Source MAC ici est celle du serveur Google (ou d'un routeur intermédiaire) si l'on est dans un réseau local. 
L'adresse Destination MAC est celle de la carte réseau du client (machine virtuelle dans ce cas). 
C'est la couche qui gère la communication physique sur le segment local.
* ​B. Couche 3 : Réseau (Internet Protocol Version 6)
​Source IP : 2a00:1450:4007:81a::2004 (Adresse IPv6 du serveur Google).
​Destination IP : 2a01:cb0d:83a9:6b00:28a4:d1f6:2449 (Adresse IPv6 du client).
​Next Header : Indique le protocole de la couche supérieure contenu dans le payload, ici ICMPv6 (58).
* ​C. Couche 4 : Transport (N/A)
​Le protocole ICMP (v4 ou v6) ne fait pas appel à la couche Transport (TCP ou UDP) ; il est directement encapsulé dans la couche Réseau (IP).
* ​D. Couche 3 (suite) : ICMPv6
​Comme mentionné précédemment, on y trouve le type (129, Reply), le code (0), et les numéros de séquence et d'identification.
​
### Conclusion 
​Ce TP a permis d'observer l'efficacité de la pile TCP/IP en opération. 
Le passage par la résolution de noms DNS/UDP pour convertir une URL en adresse IP a été la première étape critique, suivie par l'utilisation d'ICMPv6 pour valider la connectivité réseau end-to-end. 
L'absence de la couche Transport (L4) pour ICMP met en évidence sa fonction diagnostique purement réseau (L3). 
L'analyse confirme une communication réussie avec Google utilisant le protocole IPv6.