# TP6QT

---
### Projet Client TCP
Description

Ce projet implémente une application console en C++ utilisant Qt pour établir une connexion TCP avec un serveur. L'application permet de :

    Envoyer un message initial au serveur une fois connecté.
    Recevoir et afficher les messages envoyés par le serveur.
    Gérer les erreurs de connexion et autres événements liés à la socket.
---
### Structure des fichiers

    main.cpp : Point d'entrée principal de l'application, qui initialise l'application et démarre le client.
    client.h : Déclaration de la classe Client, qui encapsule la gestion des événements réseau via une socket TCP.
    client.cpp : Définition des méthodes de la classe Client, notamment :
---
### Prérequis

    Linux/Ubuntu(Terminal).
    Qt : Installer Qt version 5 ou supérieure, avec les modules Core et Network.
    Serveur TCP : Un serveur TCP fonctionnel à des fins de test.
---
### Installer Qt

Ligne de commande : 
```
sudo apt update
sudo apt install qtcreator qt5-default libqt5sql5-mysql
```
### Connexion avec QT
On utilise cette commande ou 8000 est le port serveur :
```
nc -l -p 8000
```

### Video qui montre le resultat : 

[Capture vidéo du 2025-01-08 14-28-22.webm](https://github.com/user-attachments/assets/3cd953e5-00cb-4d14-9ed3-9e839705b276)


























