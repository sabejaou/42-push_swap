# Push_swap

Push_swap est un projet du cursus 42 qui implémente un algorithme de tri pour deux piles (stacks) en utilisant un ensemble limité d'instructions. Le but est de trier une pile de nombres entiers en utilisant le minimum d'opérations possible.

## Sommaire
- [Fonctionnalités](#fonctionnalités)
- [Arborescence](#arborescence)
- [Installation](#installation)
- [Utilisation](#utilisation)
- [Instructions disponibles](#instructions-disponibles)
- [Algorithme](#algorithme)
- [Exemples](#exemples)
- [Auteur](#auteur)

---

## Fonctionnalités
- Tri de piles avec un nombre limité d'instructions
- Gestion des arguments en ligne de commande
- Validation des entrées (nombres entiers uniquement)
- Algorithme optimisé pour différents tailles de piles
- Gestion des erreurs et messages appropriés
- Utilisation de ft_printf pour l'affichage

---

## Arborescence

```
42-push_swap/
├── includes/
│   └── push_swap.h
├── src/
│   ├── core/
│   │   ├── main.c
│   │   ├── args.c
│   │   ├── sorting.c
│   │   ├── sorting_three.c
│   │   ├── sorting_four.c
│   │   └── sorting_five.c
│   └── utils/
│       ├── circlist_utils.c
│       ├── stack_instruction.c
│       └── ft_atoi.c
├── libftprintf/
│   ├── incl/
│   │   └── ft_printf.h
│   └── srcs/
│       ├── ft_printf.c
│       ├── ft_putstr_fd.c
│       ├── ft_putnbr_fd.c
│       ├── ft_putadd_fd.c
│       ├── ft_putadd_ul_fd.c
│       └── ft_putnbr_ul_fd.c
├── obj/
├── Makefile
└── README.md
```

---

## Installation

1. **Cloner le dépôt**  
   ```sh
   git clone https://github.com/sabejaou/42-push_swap.git
   cd 42-push_swap
   ```

2. **Compiler le projet**  
   ```sh
   make
   ```

---

## Utilisation

```sh
./push_swap [nombres...]
```

**Paramètres :**
- `nombres` : Liste d'entiers à trier (séparés par des espaces)

**Exemples :**
```sh
# Tri de 3 nombres
./push_swap 3 1 2

# Tri de 5 nombres
./push_swap 5 2 3 1 4

# Tri de 100 nombres
./push_swap $(seq 1 100 | shuf)
```

---

## Instructions disponibles

Le programme utilise uniquement les instructions suivantes :

- **sa** : swap a - échange les 2 premiers éléments de la pile a
- **sb** : swap b - échange les 2 premiers éléments de la pile b
- **ss** : sa et sb en même temps
- **pa** : push a - prend le premier élément de b et le met en haut de a
- **pb** : push b - prend le premier élément de a et le met en haut de b
- **ra** : rotate a - décale tous les éléments de a d'une position vers le haut
- **rb** : rotate b - décale tous les éléments de b d'une position vers le haut
- **rr** : ra et rb en même temps
- **rra** : reverse rotate a - décale tous les éléments de a d'une position vers le bas
- **rrb** : reverse rotate b - décale tous les éléments de b d'une position vers le bas
- **rrr** : rra et rrb en même temps

---

## Algorithme

Le programme utilise différentes stratégies selon la taille de la pile :

- **2-3 éléments** : Algorithme simple avec comparaisons directes
- **4-5 éléments** : Algorithme optimisé pour petites piles
- **6+ éléments** : Algorithme de tri par insertion avec optimisation

L'algorithme principal :
1. Validation des arguments
2. Création de la pile initiale
3. Vérification si déjà trié
4. Application de l'algorithme approprié selon la taille
5. Affichage des instructions utilisées

---

## Exemples

### Test avec 3 nombres
```sh
$ ./push_swap 3 1 2
ra
sa
```

### Test avec 5 nombres
```sh
$ ./push_swap 5 2 3 1 4
pb
pb
sa
pa
pa
ra
sa
```

### Vérification du nombre d'instructions
```sh
$ ./push_swap 3 1 2 | wc -l
2
```

---

## Auteur

- **Sabejaou**  
  [sabejaou@student.42lyon.fr](mailto:sabejaou@student.42lyon.fr)