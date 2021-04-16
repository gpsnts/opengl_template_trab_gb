# **opengl_template**

## **Resposta 3**

Objetos "renderizados" nessa configuração de projeção ortogonal, ao contrário de uma configuração 1:1 ("normal") são reduzidos ao ponto de ser praticamente invísivel devido ao seu tamanho relativo a janela. No caso, como o viewport está com o (x, y) nas coordenadas (0, 0). Este, mesmo que de forma praticamente imperceptível, está "fixado" no caso superior direito.

## **IMPORTANT**

Tested only in Linux!

## **Used tools**

* GCC (10.2.0)
* CMake (3.16.3)
* Ninja (1.10.0)

## **Operational System**

* Ubuntu (20.10)| Kernel 5.8.0-7642-generic

## **Running**

Everything is automated just by running `./run`. To more info, read the script

Add a `show_fps` arg to show info about the app. E.g `./run show_fps`

## Show exercises

Press key to show guide

| Exercise | Hide | Show |
|----------|------|------|
| 1        | Q    | A    |
| 2        | W    | S    |
| 4        | E    | D    |
| 5        | R    | F    |