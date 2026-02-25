# 🐺 Cub3D

**Cub3D** est un projet de l'école 42 inspiré du célèbre jeu des années 90, *Wolfenstein 3D*. L'objectif est de créer un moteur 3D rudimentaire utilisant la technique du **Raycasting** pour représenter un labyrinthe texturé en temps réel, le tout en langage C avec la bibliothèque MiniLibX.

## 🌟 Fonctionnalités

- **Moteur 3D par Raycasting** : Rendu fluide et calcul des distances à l'aide de l'algorithme DDA.
- **Textures directionnelles** : Affichage de textures distinctes selon l'orientation des murs (Nord, Sud, Est, Ouest).
- **Environnement coloré** : Couleurs paramétrables pour le sol (Floor) et le plafond (Ceiling) via le fichier de configuration.
- **Déplacements et Collisions** : Gestion complète des mouvements (avancer, reculer, pas chassés, rotation) avec glissement sur les murs (gestion des collisions).
- **Parsing robuste** : Lecture et vérification rigoureuse de la carte (`.cub`) pour éviter toute fuite ou erreur de format (Flood Fill algorithme intégré).
- **Bonus** : (Si implémentés) Mini-map pour se repérer, textures animées ou portes.

## 🛠️ Prérequis

Pour compiler et jouer, vous aurez besoin de :
- `gcc` ou `clang`
- `make`
- Dépendances graphiques pour X11 (sous Linux) : `libxext-dev` et `libx11-dev`

## 🚀 Installation & Lancement

Clonez le dépôt, puis utilisez le `Makefile` pour compiler le projet :

```bash
# Cloner le projet
git clone <votre_lien_git> cub3d
cd cub3d

# Compiler l'exécutable
make

# Lancer le jeu avec une carte (plusieurs cartes dispos dans le dossier maps/)
./cub3D maps/test.cub
