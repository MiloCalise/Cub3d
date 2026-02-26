# cub3D - Raycasting Engine

## 📝 Présentation
**cub3D** est un moteur de jeu 3D développé en **C**, inspiré du célèbre *Wolfenstein 3D*.  
Ce projet reproduit le principe du raycasting utilisé dans le jeu iconique **Wolfenstein 3D** (id Software, 1992).

L'objectif est de générer une projection 3D à partir d'une carte 2D en utilisant des calculs mathématiques précis pour le rendu, les collisions et la gestion des textures.

Le projet repose sur la bibliothèque graphique **MiniLibX**, fournie dans le cadre de l’école 42.

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
