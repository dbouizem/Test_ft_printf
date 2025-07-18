
---

📝 Note :
Le sujet de ft_printf indique que les segfaults sont interdits, sauf si printf se comporte de la même façon dans les mêmes circonstances.
Or, appeler printf(NULL) est un comportement indéfini selon la norme C (ISO/IEC 9899).
Cela signifie que le résultat peut varier selon les systèmes :

Sur certaines implémentations (comme glibc), printf(NULL) peut afficher (null) ou ne rien faire.

Sur d’autres (comme musl, ou certaines versions de macOS), cela peut provoquer un crash (segfault).

La man page de printf ne garantit jamais que NULL est un format valide. Elle parle uniquement de "character strings", ce qui exclut les pointeurs NULL.

En conséquence, j’ai choisi de ne pas gérer le cas ft_printf(NULL), car il est hors-scope, non défini par la norme, et toléré par le sujet.
Mon comportement — provoquer un crash dans ce cas — est donc acceptable et conforme, car printf lui-même peut crash aussi dans cette situation.

Enfin, il ne s’agit pas d’un bug ou d’un oubli, mais d’un choix volontaire pour rester fidèle au comportement de la fonction standard printf dans un contexte défini par la norme, et non par une implémentation particulière (glibc, musl, etc.).

dépend de la lib utilisée

glibc (souvent) affiche (null)

Mais ce n’est pas une obligation !

Tu n’as pas à copier glibc : tu dois respecter la norme, pas un comportement particulier de telle ou telle lib

---
