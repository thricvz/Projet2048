---
jupytext:
  text_representation:
    extension: .md
    format_name: myst
    format_version: 0.13
kernelspec:
  display_name: Python 3 (ipykernel)
  language: python
  name: python3
---

# Rapport de projet 2048

+++

## Auteurs

- Altit, Adam, adam.altit@gmail.com, LDDIM2
- Fontez-Vaz, Eric, ericvaz2505@gmail.com, LDDIM2

+++

## Résumé du travail effectué

:::{admonition} Consignes

Pour chaque niveau du sujet, décrivez brièvement l'avancement de votre
projet.

Exemples de réponses : «non traitée», «réalisée, documentée, testée»,
«réalisée, sauf 2.3», «réalisée mais non testée», «réalisée sauf ...
pour lequel notre programme ne compile pas» ou «pour lequel les tests
de la fonction D ne passent pas».

Pour les questions «Aller plus loin» plus ouvertes, décrivez plus en
détail ce que vous avez choisi de réaliser. Précisez les difficultés
rencontrées, les choix d'implantation que vous avez fait, etc.

En plus du rapport, la documentation de chaque fonction dans le code
devra préciser son auteur et votre degré de confiance dans
l'implantation, ainsi que les éléments factuels motivant cette
confiance: présence de tests, bogues et limitations connus, etc.

- Niveau 0: ...
- Niveau 1: ...
- ...

:::

+++

### Niveau 0 :
- Fonctions crées sauf problème avec fontion affichage, documentées, testées
- Pas encore de score
- Colonnes mal alignées
- Changement d'une fonction dans le modèle de départ
- Ajout d'une fonction renvoyant le maximum du plateau

+++

### Niveau 1 :
- Couleur ?
- 

+++

### Niveau 2 :
- Mise en place de Makefile pour compilation
- Mise en place de Git

+++

### Niveau 3 :
- Interface graphique avec SFML
- Tentative création bande audio avec Fl studio

+++

## Démonstration

:::{admonition} Consignes

Soutenez ce que vous affirmez dans la section précédente au moyen de
quelques exemples **bien choisis**. Vous pouvez par exemple compiler
et lancer certains de vos programmes, lancer des tests, etc.

À titre d'inspiration, vous trouverez ci-dessous comment compiler un
programme du projet depuis cette feuille. 

Notez comment on lance une commande shell en la préfixant d'un point
d'exclamation (mais cela ne permet pas l'interaction avec
l'utilisateur).

Ne gardez que des exemples pertinents qui mettent en valeur votre
travail. Inutile de perdre du temps sur le premier programme si vous
avez fait les suivants plus compliqués; l'auditeur se doutera bien que
vous avez réussi à le faire.

:::

+++

On a remarqué que la documentation de la fonction "estTerminé" n'était pas cohérente.

En effet elle devait renvoyé un booléens en fonction de si le plateau était vide, ce qu'on n'a pas trouvé logique et utile.

Avec l'accord du chargé de TD, on a donc modifié la fonction afin qu'elle renvoit un booléens en fonction de si un mouvement est possible sur le plateau. La documentation à été modifiée en conséquences.

+++

## Organisation du travail

:::{admonition} Consignes
Décrivez en quelques phrases comment vous vous êtes organisés pour
travailler sur le projet: nombre d'heures consacrées au projet,
répartition du travail dans le binôme, moyens mis en œuvre pour
collaborer, etc. Si vous avez bénéficié d'aide (en dehors de celle de
vos enseigants), précisez le.
:::

+++

Dans un premier temps, on a trouvé plus pratique de se séparer le travail de la manière suivante : l'un s'occupe de toute les fonctions, l'autre de tout les tests.

On a utilisé Visual Studio code à la place de Jupyter pour des raisons d'ergonomie de travail en groupe (mise en place de Git également).

On a ensuite profité des séances de td afin de rassembler nos idées et pour décider de la répartition des prochaines amélioration du projet

Seul internet a été notre aide, lors de notre recherches pour certaines fonctionnalités.

+++

## Prise de recul

:::{admonition} Consignes
Décrivez en quelques phrases les difficultés rencontrées, ce que vous
avez appris à l'occasion du projet, le cas échéant comment vous vous y
prendriez si vous aviez à le refaire.
:::

+++

On a rencontré des difficultés au niveau de la fonction gérant l'affichage du plateau. On s'est un peu trop compliqué la tâche en pensant que la taille des cases devait être dynamique en fonction du plus grand nombre du plateau. 

Aussi questionnement sur le caractère "aléatoire" de la fonction qui tire un nombre entre 2 et 4. En effet on s'est alors posé la question de si le test devrait être en capacité de vérifier les probabilités. Faut-il exécuter 1000 fois la fonction et alors vérifier que P(4)≈1/10 ± x ?

De plus l'interface graphique n'était au départ pas capable d'enregister les input de l'utilisateurs, problématique.

On a appris l'utilisation du Makefile, magnifique outil pratique pour la compilation.

L'un de nous a aussi pu découvrir Git, qu'on utilisera plus tôt si on avait a refaire un projet
