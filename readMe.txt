Le programme a été réalisé en C++11 et en gtkmm 3.0.

Le makefile fournie possède plusieurs variable et cible :

variable:
	-DEBUG=yes/no construit le programme avec les information de debuggage
	-GRAPHIC=yes/no l'affiche passe par gtk ou par un sortie sur la console
	-SIZE définie la taille de la map
	
cible:
	all : construit le programme.
	doc : génère la documentation au format html dans le sous dossier ./doc, doxygen nécessaire.
	mrproper : nettoye totalement le projet.
	memory_test : lance valgring et analyse l'utilisation mémoire du programme.
	
Le programme est organisé suivant l'organisation MVC. 
Un timer est implenter au niveau de la vue qui va consulter 
à intervale régulier le controlleur.
Le controlleur quand à lui va attendre que toutes les puces est terminer leur tour
pour mettre à jour les données. 