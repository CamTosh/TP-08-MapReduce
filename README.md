# [TP 08 : MapReduce](https://drive.google.com/file/d/0B-vA3-U63KZXcDlpVG5nOFFYS28/view "lien du TP")

> Avant tout le code dispo ici peut être utiliser SAUF à des fins commercials, c'est sympa si vous m'en faites part ;)


Ce TP permet de mettre en place un traitement de données basé sur le principe de « map » et « reduce ».
Ce travail va être mené en langage C. La mise en œuvre peut se faire dans tous les environnements.

L’opération de mappage consiste à mettre en place une structure de données qui va contenir des couples (clés, valeurs).
L’opération de mappage sera répartie sur deux processus au minimum (voir maximum).

La dernière opération « reduce », permet de reprendre le résultat des processus et de faire une synthèse des résultats. Cette synthèse se fait encore une fois avec une structure de données qui travaille toujours avec des couples (clés, valeurs).

Attention : Dans ce travail, le programmeur à la charge de répartir les travaux sur les processus (versions mono-thread et multi-threads).

Les différentes étapes de travail sont les suivantes :

1. Elaborer un fichier .txt qui sera analysé. Vous pouvez d’ailleurs prévoir plusieurs jeux d’essais, afin de mettre au point l’algorithme. L’objectif est de pouvoir traiter un fichier avec plus de 10 000 entrées, pour commencer à faire du traitement plus massif.

2. Charger le fichier dans une structure en mémoire. Il ne faut pas oublier que la mémoire centrale permet les meilleures performances. Dans le cas du Big Data, la plupart des données sont présentes en mémoire centrale. Les machines actuelles offrent suffisamment de mémoire pour travailler facilement.

3. Une fois le fichier chargé, il faut commencer avec un traitement mono-thread. Dans ce cas, le premier tableau est lu, puis un tableau de sortie est constitué avec des opérations de « Shuffling » (battage). Plus simplement il faut mêler les éléments identiques afin de faire des cumuls sur la rubrique valeur de chaque clé.

4. Dans le cas d’un mono-thread, il n’y a pas d’opération de « reduce » (réduction) ou de mappage dissociées. Le simple battage, qui permet de faire le cumul des valeurs, permet d’obtenir le résultat final. Le mapReduce se limite donc à une simple fonction baptisée mapReduce.

## Todo en vrac

Utiliser la POO.
Utiliser les tests unitaires.
Ajouter des Toast.

## Memo en vrac :

Un programme Hadoop se divise généralement en trois parties :

- Le driver, qui s'exécute sur une machine client, est chargé de configurer le job puis de le soumettre pour exécution.
- Le mapper est chargé de lire les données stockées sur disque et les traiter.
- Le reducer est chargé de consolider les résultats issus du mapper puis de les écrire sur disque.

Les données sont toujours lues ou écrites selon le format `<key, value>` (`<clef, valeur>`). 

## liens utiles
[Journal du net](http://www.journaldunet.com/developpeur/outils/mapreduce.shtml)

[Blog de soat](http://blog.soat.fr/2015/05/comprendre-mapreduce/ "avec des poneys !")

[Piloter.org "La business intelligence"](http://www.piloter.org/business-intelligence/map-reduce.htm)

[Le tri topologique](http://stephane.bunel.org/Algo/tri-topologique)

[Le tri topologique façon wikipedia](https://fr.wikipedia.org/wiki/Tri_topologique)

[Le graphe acyclique](https://fr.wikipedia.org/wiki/Graphe_orient%C3%A9_acyclique)

[Le Map Reduce par Google](http://research.google.com/archive/mapreduce-osdi04-slides/)