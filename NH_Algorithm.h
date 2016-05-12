#include"NH_Algorithm.c"

void NH_init_snake();
void NH_affiche(int * tab,int w,int h);
void NH_deplacement(int * map,int mapX,int mapY);
int NH_gameover(Uint32 * map,int mapX,int mapY);
void NH_affiche_3D(int * tab,int w,int h,int * tabg,int wg,int hg,int * tabd,int wd,int hd);
int NH_gameover_3D(Uint32 * map,int mapX,int mapY,int * mapg,int wg,int hg,int * mapd,int wd,int hd);
void NH_deplacement_3D(int * map,int mapX,int mapY,int *mapLeft,int mapLeftX,int mapLeftY,int *mapRight,int mapRightX,int mapRightY);
