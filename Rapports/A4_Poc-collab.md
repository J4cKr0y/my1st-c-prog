# Rapport de collaboration Git – Projet PocCollaboratif

## Contexte

Dans le cadre d’un exercice collaboratif simulant le fonctionnement d’une entreprise, nous avons mis en place un compte GitHub commun (`fajamag3`) 
et configuré une connexion SSH personnalisée pour permettre à chaque membre de contribuer à un projet C++ : une calculatrice modulaire.

Chaque collaborateur devait développer une fonctionnalité spécifique (addition, multiplication, etc.) dans une branche dédiée, puis fusionner son travail dans la branche principale (`main`).

---

## Étapes de configuration SSH

### 1. Génération de la clé SSH

```
ssh-keygen -t ed25519 -C "PocCollaboratif"
# Chemin : ~/.ssh/ided25519poc_collab
cat ~/.ssh/ided25519poc.pub_collab
```

### 2. Ajout de la clé sur GitHub

- Connexion au compte GitHub : fajamag3 (Login et mot de passe unique, partagé à tous les participants.)

- Menu : Settings → SSH and GPG keys → New SSH key

- Titre : PocCollaboratifMag

- Clé publique : collée depuis l’étape précédente

### 3. Configuration du fichier SSH
```
nano ~/.ssh/config
```
Contenu à insérer :
```
Host github-poc-collab
  HostName github.com
  User git
  IdentityFile ~/.ssh/ided25519poc_collab
```

## Processus de contribution

### 1. Clonage et configuration du remote

```
git clone git@github.com:fajamag3/PocCollaboratif.git
cd PocCollaboratif
git remote set-url origin git@github-poc-collab:fajamag3/PocCollaboratif.git
```

### 2. Création de branche et modification

```
`git checkout -b devMagalyUS1_Addition
nano main.c
# Modification : "Opération invalide" → "Désolée, opération invalide"
git add .
git commit -m "Ajout de l'addition"
git push origin devMagalyUS1_Addition
```

### 3. Fusion dans main

```
git checkout main
git pull origin main
git merge devMagalyUS1_Addition
```

## /!\ Problème rencontré : Merge invisible

**Problème**
Malgré le merge effectué, *aucune trace n'apparaissait sur GitHub* :

- Pas de Pull Request ouverte ou fermée

- Pas de commit de merge visible

- Git indiquait que le merge avait déjà été fait

**Diagnostic**
Git avait effectué un *merge fast-forward* :

- Aucun commit de merge généré

- Git avance simplement le pointeur de main vers le dernier commit de la branche

- GitHub ne détecte pas de fusion explicite

**Solution appliquée**
Pour forcer une trace visible du merge :

- Ajout d'une modification sur la branche (par exemple un commentaire)

- Utilisation de l’option --no-ff :
```
git merge --no-ff devfarisUS3Multiplication
```
Cela a permis de générer un *commit de merge explicite*, visible dans l’historique GitHub.

## Conclusion
Ce projet nous a permis de :

- Mettre en place une configuration SSH multi-utilisateur

- Travailler en branches individuelles avec Git

- Comprendre les subtilités du merge fast-forward

- Appliquer des solutions pour rendre les contributions visibles et traçables

Ce retour d’expérience servira de base pour améliorer nos pratiques collaboratives et documenter les comportements implicites de Git dans un contexte professionnel.