# 4️⃣2️⃣ *~This project has been created as part of 42 curriculum by <miltavar\> and <molapoug\>*

# cub3D - Raycasting Engine

## 📝 Description
**cub3D** est un moteur de jeu 3D développé en **C**, inspiré du célèbre *Wolfenstein 3D*.
Ce projet reproduit le principe du raycasting utilisé dans le jeu iconique **Wolfenstein 3D** (id Software, 1992).

L'objectif est de générer une projection 3D à partir d'une carte 2D en utilisant des calculs mathématiques précis pour le rendu, les collisions et la gestion des textures.

Le projet repose sur la bibliothèque graphique **MiniLibX**, fournie dans le cadre de l’école 42.

---

# Ressources utilisées

**algo de dda** : https://www.uomustansiriyah.edu.iq/media/lectures/12/12_2023_04_20!12_50_11_AM.pdf

**algo de dda** : https://www.geeksforgeeks.org/computer-graphics/dda-line-generation-algorithm-computer-graphics/

**tuto cub3d** : https://hackmd.io/@nszl/H1LXByIE2

---

# Utilisation de l'IA
**Gemini** : explication des maths et vitesse d'ecriture

**Gpt5** : Algo de DDA

---

# Fonctions importantes

### Fonctions bonus
sert a initaliser le bonus
```C
int		game_loop_bonus(t_game *g);
int		game_init_bonus(t_game *game);
```
___
### Fonctions minimap
sert a afficher la map
```C
void	init_minimap(t_game *game);
```
___
### Fonctions calcul FPS
sert a afficher le nombre de fps
```C
void	calc_fps(t_game *g);
```
___
### Foncatios de mouvemnt de la souris
sert a deplacer la vu du joueur avec la souris
```C
int		mouse_move(int x, int y, t_game *game);
```
___
### Fonctions qui gere la collisions avec les mures
fonctions qui detectent la colitions avec les mures
```C
void	move_forward(t_game *game);
void	move_backward(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);
```
___
---

## 🚀 Fonctionnalités

### ✅ Partie Obligatoire
- 🎯 **Moteur de Raycasting**
  - Projection 3D à partir d'une carte 2D
  - Correction de l'effet *fisheye*
  - Calcul des distances perpendiculaires aux murs

- 🧱 **Textures**
  - Textures différentes selon l’orientation des murs :
    - Nord
    - Sud
    - Est
    - Ouest

- 🎨 **Gestion des couleurs**
  - Sol et plafond configurables via format RGB :
    ```
    F 220,100,0
    C 225,30,0
    ```

- 🎮 **Contrôles joueur**
  - `W`, `A`, `S`, `D` → Déplacements
  - `←` `→` → Rotation caméra
  - `ESC` → Quitter proprement

- 📂 **Parsing robuste**
  - Vérification stricte du fichier `.cub`
  - Carte entièrement fermée par des murs
  - Une seule position joueur
  - Chemins de textures valides
  - RGB valides

---

### ⭐ Partie Bonus
- 🗺️ **Minimap**
  - Affichage en temps réel
  - Direction du joueur visible

- 🖱️ **Rotation souris**
  - Caméra contrôlable à la souris

- 🧱 **Textures sol/plafond**
  - Remplacement des couleurs unies (floor celing)

- ⚡ **Optimisation**
  - Algorithme **DDA (Digital Differential Analysis)**
  - Rendu fluide
  - Pas de scintillement

---

# Instructions

## 🛠️ Installation & Compilation

### 1️⃣ Cloner le projet

```bash
git clone https://github.com/MiloCalise/Cub3d.git
cd cub3D
```

### 2️⃣ Compiler
```bash
make
make clean
make fclean
make re
```

---

## 🎮 Utilisation

### Lancer le programme avec une carte valide :
```bash
./cub3D maps/big.cub
```
### Avec bonus :
```bash
./cub3D maps/big.cub --bonus
```

---

## 🗂️ Format du fichier .cub

### Exemple minimal :
```
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm

F 220,100,0
C 225,30,0

111111
100001
10N001
100001
111111
```

