Voici la traduction française de ton rapport, structurée et prête pour ton fichier `.md`.
# Green Efficiency Analysis Report

## Measurement Methodology

Afin d'évaluer l'efficacité informatique des algorithmes fournis, j'ai mis en place une instrumentation temporelle de haute précision en utilisant la fonction `clock()` de la bibliothèque standard C `<time.h>`. Cette méthodologie se concentre sur la capture du "temps CPU", qui représente le temps réel passé par le processeur à exécuter les instructions du programme spécifique, plutôt que le "temps réel écoulé" (wall-clock time), lequel peut être influencé par les processus système en arrière-plan.

Le processus a consisté à placer des marqueurs de type `clock_t` immédiatement avant et après l'exécution de fonctions spécifiques : `build_dataset()`, `process_dataset()`, et `reduce_checksum()`. En calculant la différence entre ces marqueurs et en divisant le résultat par la constante `CLOCKS_PER_SEC`, j'ai obtenu le temps d'exécution en secondes avec une précision de six décimales (`%.6f`). Pour garantir la pertinence statistique, j'ai effectué plusieurs essais pour la boucle de référence et la comparaison algorithmique, calculant des moyennes pour atténuer l'impact des fluctuations mineures du système.

## Observed Performance Differences

Les données recueillies révèlent une disparité massive entre les approches algorithmiques. Lors du test de référence de la boucle, le temps d'exécution est resté stable sur trois passages, avec une moyenne d'environ **0,245 seconde** pour 100 millions d'itérations. Cependant, la découverte la plus significative réside dans la comparaison entre les algorithmes "Naïf" et "Single-pass" (à passage unique).

D'après mes relevés :

* L'**algorithme Naïf** (complexité $O(n^2)$) a nécessité en moyenne **4,222 secondes** pour traiter un ensemble de données de 50 000 éléments.
* L'**algorithme Single-pass** (complexité $O(n)$) n'a nécessité en moyenne que **0,000142 seconde** pour le même ensemble de données.

Cela démontre que la version Naïve est environ **29 595 fois plus lente** que la version Single-pass. Un tel écart illustre que, à mesure que la taille de l'ensemble de données ($n$) augmente, la croissance quadratique de l'algorithme Naïf devient un goulot d'étranglement critique pour les performances du système.

## Relation Between Runtime and Energy Consumption

Il existe une corrélation directe et linéaire entre le temps d'exécution et la consommation d'énergie. Les processeurs modernes consomment une puissance électrique importante lorsqu'ils sont dans un état actif de calcul. En tournant pendant 4,222 secondes au lieu de 0,000142 seconde, l'algorithme Naïf force le CPU à rester dans un état de haute consommation pendant une durée supérieure de plusieurs ordres de grandeur.

Cette exécution prolongée entraîne une consommation d'électricité accrue et une dissipation thermique plus élevée. Dans un environnement de centre de données (Data Center), l'exécution de code inefficace à grande échelle conduit à une "double peine" : davantage d'énergie est consommée pour effectuer les calculs, et une énergie supplémentaire est requise pour les systèmes de refroidissement afin d'évacuer la chaleur excédentaire. Par conséquent, la réduction du temps d'exécution via l'optimisation algorithmique est un levier majeur du "Green IT" et de la durabilité environnementale.

## Limitations of the Experiment

Bien que les résultats soient concluants, cette expérience comporte certaines limites :

1. **CPU vs E/S (I/O) :** La fonction `clock()` ne tient pas compte du temps passé à attendre l'accès à la mémoire ou les entrées/sorties du disque. Dans les applications réelles, la récupération des données consomme souvent plus de temps que le calcul lui-même.
2. **Bruit Environnemental :** Bien que le temps CPU soit plus stable que le temps réel, des fonctionnalités matérielles telles que le "Turbo Boost" ou le bridage thermique (thermal throttling) peuvent faire varier la vitesse du processeur lors de tâches longues, ce qui peut potentiellement fausser les résultats pour l'algorithme Naïf.

## Practical Engineering Takeaway

La leçon la plus cruciale pour un ingénieur logiciel est que **l'efficacité algorithmique est l'outil le plus efficace pour la durabilité.** Aucune mise à niveau matérielle ne peut compenser l'inefficacité d'un algorithme en $O(n^2)$ lorsqu'une alternative en $O(n)$ existe. Coder de manière efficace n'est pas seulement une question de vitesse ou d'expérience utilisateur ; c'est un choix d'ingénierie éthique qui minimise directement l'empreinte carbone de l'infrastructure numérique.