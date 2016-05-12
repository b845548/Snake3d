#include "HBB_DrawTool.h"
#include "HBB_MapSource.h"
#include "HBB_FontSource.h"
#include "CHARLIE_InitGameData.h"

void HBB_reinitAllStage(){
	
	  int reinit;
	  int a1=rand()%100,a2,a3;
	  for(reinit=0;reinit<10*10;reinit++)
	    if(HBB_earth2[reinit]==1||HBB_earth2[reinit]==2)
		HBB_earth2[reinit]=0;
	  
	  while(HBB_earth2[a1])
	    a1=rand()%100;
	  HBB_earth2[a1]=2;
	  a2=rand()%200;

	  for(reinit=0;reinit<10*10;reinit++)
	    if(CHARLIE_earth2[reinit]==1||CHARLIE_earth2[reinit]==2)
		CHARLIE_earth2[reinit]=0;
	  
	  while(CHARLIE_earth2[a1])
	    a1=rand()%100;
	  CHARLIE_earth2[a1]=2;
	  a2=rand()%200;

	  for(reinit=0;reinit<20*20;reinit++)
	    if(HBB_volcan1[reinit]==1||HBB_volcan1[reinit]==2)HBB_volcan1[reinit]=0;
	  while(HBB_volcan1[a2])
	    a2=rand()%400;
	  HBB_volcan1[a1]=2;

	  a3=rand()%(21*21);
	  //a2=rand()%(21*20);
	  //a3=rand()%(20*20);
	  for(reinit=0;reinit<21*21;reinit++)
	    if(MAP3Dtoit[reinit]==1||MAP3Dtoit[reinit]==2)MAP3Dtoit[reinit]=0;
	  while(MAP3Dtoit[a3])
	    a3=rand()%(17*15);
	  MAP3Dtoit[a3]=2;

	  for(reinit=0;reinit<21*20;reinit++)
	    if(MAP3Dleft[reinit]==1||MAP3Dleft[reinit]==2)MAP3Dleft[reinit]=0;
	   while(MAP3Dtoit[a3])
	    a3=rand()%(17*15);
	  MAP3Dtoit[a3]=2;

	  for(reinit=0;reinit<20*20;reinit++)
	  	if(MAP3Dright[reinit]==1||MAP3Dright[reinit]==2)MAP3Dright[reinit]=0;
	  while(MAP3Dright[a3])
	    a3=rand()%(17*15);
	  MAP3Dright[a3]=2;
	
	  for(reinit=0;reinit<21*21;reinit++)
	    if(labyrinthToit[reinit]==1||labyrinthToit[reinit]==2)labyrinthToit[reinit]=0;
	  
	  for(reinit=0;reinit<21*20;reinit++)
	    if(labyrinthLeft[reinit]==1||labyrinthLeft[reinit]==2)labyrinthLeft[reinit]=0;



	  
	  for(reinit=0;reinit<20*20;reinit++)
	    if(labyrinthRight[reinit]==1||labyrinthRight[reinit]==2)labyrinthRight[reinit]=0;

 
}

void HBB_drawVoxelLeft(Uint32 *pix,int w,int h,int cubeSize,int map[],int mapW,int mapH,int mapX,int mapY){
  int posy=mapY+488;
  int posx=mapX+109;
  int ligne,colonne;
  float decalage;
  HBB_flip(map,mapW,mapH);
  for(ligne=0;ligne<mapH;ligne++)	
    for(colonne=0,decalage=0.5;colonne<mapW;colonne++,decalage+=0.5)
      if(map[colonne+ligne*mapW]==4)HBB_cube3D(posy-ligne*cubeSize-(ligne*2)+(colonne*cubeSize/2+(int)decalage),posx+colonne*cubeSize+colonne,cubeSize,pix,w,h,Gre);
      else if(map[colonne+ligne*mapW]==3)HBB_cube3D(posy-ligne*cubeSize-(ligne*2)+(colonne*cubeSize/2+(int)decalage),posx+colonne*cubeSize+colonne,cubeSize,pix,w,h,bl);
      else if(map[colonne+ligne*mapW]==2)HBB_cube3D(posy-ligne*cubeSize-(ligne*2)+(colonne*cubeSize/2+(int)decalage),posx+colonne*cubeSize+colonne,cubeSize,pix,w,h,rN4);
      else if(map[colonne+ligne*mapW]==1)HBB_cube3D(posy-ligne*cubeSize-(ligne*2)+(colonne*cubeSize/2+(int)decalage),posx+colonne*cubeSize+colonne,cubeSize,pix,w,h,HBB_green);
      else if(map[colonne+ligne*mapW]==7)HBB_cube3D(posy-ligne*cubeSize-(ligne*2)+(colonne*cubeSize/2+(int)decalage),posx+colonne*cubeSize+colonne,cubeSize,pix,w,h,bl);
  	  else if(map[colonne+ligne*mapW]==8)HBB_cube3D(posy-ligne*cubeSize-(ligne*2)+(colonne*cubeSize/2+(int)decalage),posx+colonne*cubeSize+colonne,cubeSize,pix,w,h,HBB_green);
  HBB_flip(map,mapW,mapH);
}





void HBB_drawVoxelRight(Uint32 * pix,int w,int h,int cubeSize,int map[],int mapW,int mapH,int mapX,int mapY){
  int posy=mapY+361;
  int posx=mapX+403;
  int colonne,ligne,sz=cubeSize;// pair
  float decalage;
 
  HBB_flip(map,mapW,mapH);
  
  for(ligne=0;ligne<mapH;ligne++)
    for(colonne=mapW-1,decalage=mapW*0.5;colonne>=0;colonne--,decalage-=0.5)
      if(map[colonne+ligne*mapW]==4)HBB_cube3D(posy-ligne*sz-(ligne*2)+(mapW*sz-colonne*sz/2-(int)decalage),posx+colonne*sz+colonne,sz,pix,w,h,Gre);
    	else if(map[colonne+ligne*mapW]==3)HBB_cube3D(posy-ligne*sz-(ligne*2)+(mapW*sz-colonne*sz/2-(int)decalage),posx+colonne*sz+colonne,sz,pix,w,h,bl);
    	else if(map[colonne+ligne*mapW]==2)HBB_cube3D(posy-ligne*sz-(ligne*2)+(mapW*sz-colonne*sz/2-(int)decalage),posx+colonne*sz+colonne,sz,pix,w,h,rN4);
		else if(map[colonne+ligne*mapW]==1)HBB_cube3D(posy-ligne*sz-(ligne*2)+(mapW*sz-colonne*sz/2-(int)decalage),posx+colonne*sz+colonne,sz,pix,w,h,HBB_green);
	else if(map[colonne+ligne*mapW]==7)HBB_cube3D(posy-ligne*sz-(ligne*2)+(mapW*sz-colonne*sz/2-(int)decalage),posx+colonne*sz+colonne,sz,pix,w,h,HBB_pastel);

  HBB_flip(map,mapW,mapH);

};


void HBB_drawVoxelTop(Uint32 *pix,int w,int h,int cubeSize,Uint32 * map,int mapW,int mapH,int mapX,int mapY){
  int posy=mapY+48;
  int posx=mapX+389;
  int sz=cubeSize;// pair
  int colonne,ligne;
  float decalageLigne,decalageColonne;
  for(ligne=0,decalageLigne=0.5;ligne<mapH;ligne++,decalageLigne+=0.5)
    for(colonne=0,decalageColonne=0.5;colonne<mapW;colonne++,decalageColonne+=0.5)	    
      if(map[colonne+ligne*mapW]==4)HBB_cube3D(posy+(ligne*sz/2+(int)decalageLigne)+(colonne*sz/2+(int)decalageColonne),posx-ligne*sz-ligne+(colonne*sz+colonne),sz,pix,w,h,Gre);
      else if(map[colonne+ligne*mapW]==3)HBB_cube3D(posy+(ligne*sz/2+(int)decalageLigne)+(colonne*sz/2+(int)decalageColonne),posx-ligne*sz-ligne+(colonne*sz+colonne),sz,pix,w,h,bl);
      else if(map[colonne+ligne*mapW]==2)HBB_cube3D(posy+(ligne*sz/2+(int)decalageLigne)+(colonne*sz/2+(int)decalageColonne),posx-ligne*sz-ligne+(colonne*sz+colonne),sz,pix,w,h,rN4);
      else if(map[colonne+ligne*mapW]==1)HBB_cube3D(posy+(ligne*sz/2+(int)decalageLigne)+(colonne*sz/2+(int)decalageColonne),posx-ligne*sz-ligne+(colonne*sz+colonne),sz,pix,w,h,HBB_green);  
}

void HBB_drawMenu(Uint32 *texture,int texW,int texh,int page,int horloge){
  int imgLevel;	
  if(page==1){
    memset(texture,0,texW*texh* sizeof(Uint32));
    if(horloge==1)HBB_mapping(texture,texW,texh,(Uint32 *)IMG_start->pixels,IMG_start->w,IMG_start->h,positionStart.x,positionStart.y,2);
    HBB_drawImgLogo(texture,texW,texh,(Uint32 *)IMG_logo->pixels,IMG_logo->w,IMG_logo->h,positionLogo.x,positionLogo.y,0);
  }
  if(page==2){
    memset(texture,0,texW*texh* sizeof(Uint32));
    HBB_drawImgLogo(texture,texW,texh,(Uint32 *)IMG_logo->pixels,IMG_logo->w,IMG_logo->h,positionLogo.x,positionLogo.y,0);
    HBB_mapping(texture,texW,texh,(Uint32 *)IMG_arrow->pixels,IMG_arrow->w,IMG_arrow->h,positionArrow.x,positionArrow.y,0);
    for(imgLevel=0;imgLevel<5;imgLevel++)
      HBB_mapping(texture,texW,texh,(Uint32 *)IMG_level[imgLevel]->pixels,IMG_level[imgLevel]->w,IMG_level[imgLevel]->h,positionLevel[imgLevel].x,positionLevel[imgLevel].y,0);
  }
}




void HBB_drawStageTerre(Uint32 *texture,int texW,int texh,int cubeSize){
  float decalageColonne,decalageLigne;
  int ligne,colonne,etage;
  int posy=150+2*cubeSize-5;
  int posx=380;
  int mapW=10;
  int mapH=10;

    memset(texture,0,texW*texh*sizeof(Uint32));
  	for(etage=0;etage<3;etage++,posy-=cubeSize+2)
  		for(ligne=0,decalageLigne=0.5;ligne<mapH;ligne++,decalageLigne+=0.5)
    		for(colonne=0,decalageColonne=0.5;colonne<mapW;colonne++,decalageColonne+=0.5){
		    if(etage==0)HBB_cube3D(posy+(ligne*cubeSize/2+(int)decalageLigne)+(colonne*cubeSize/2+(int)decalageColonne),posx-ligne*cubeSize-ligne+(colonne*cubeSize+colonne),cubeSize,texture,texW,texh,HBB_terre);
		    if(etage==1&&HBB_earth[colonne+ligne*mapW]==3)HBB_cube3D(posy+(colonne*cubeSize/2+(int)decalageLigne)+(ligne*cubeSize/2+(int)decalageColonne),posx-ligne*cubeSize-ligne+(colonne*cubeSize+colonne),cubeSize,texture,texW,texh,HBB_water);
		    if(etage==1&&HBB_earth[colonne+ligne*mapW]==4)HBB_cube3D(posy+(colonne*cubeSize/2+(int)decalageLigne)+(ligne*cubeSize/2+(int)decalageColonne),posx-ligne*cubeSize-ligne+(colonne*cubeSize+colonne),cubeSize,texture,texW,texh,HBB_green);
		    if(etage==2&&HBB_earth2[colonne+ligne*mapW]==1)HBB_cube3D(posy+(colonne*cubeSize/2+(int)decalageLigne)+(ligne*cubeSize/2+(int)decalageColonne),posx-ligne*cubeSize-ligne+(colonne*cubeSize+colonne),cubeSize,texture,texW,texh,gN4);
		    if(etage==2&&HBB_earth2[colonne+ligne*mapW]==2)HBB_cube3D(posy+(colonne*cubeSize/2+(int)decalageLigne)+(ligne*cubeSize/2+(int)decalageColonne),posx-ligne*cubeSize-ligne+(colonne*cubeSize+colonne),cubeSize,texture,texW,texh,NH_red);
		    }
}



void HBB_drawStageVolcan(Uint32 *texture,int textureWidth,int textureHeight,int cubeSize){
  float decalageLigne,decalageColonne;
  int colonne,ligne,etage;
  int mapW=20,mapH=20;
  int posy=230,posx=390;
  int volcanEtage=11;
  Uint32 *volcanMap[]={HBB_volcan0mm,HBB_volcan0mm,HBB_volcan0mm,HBB_volcan0m,HBB_volcan0,HBB_volcan1,HBB_volcan2,HBB_volcan3,HBB_volcan4,
		       HBB_volcan5,HBB_volcan6};
  	memset(texture, 0,textureWidth *textureHeight * sizeof(Uint32));
    
  for(etage=0;etage<volcanEtage;etage++,posy-=cubeSize+2)
    for(ligne=0,decalageLigne=0.5; ligne<mapH;ligne++,decalageLigne+=0.5)
      for(colonne=0,decalageColonne=0.5; colonne<mapW; colonne++,decalageColonne+=0.5){
		if(volcanMap[etage][colonne+ligne*mapW]==1)HBB_cube3D(posy+(ligne*cubeSize/2+(int)decalageLigne)+(colonne*cubeSize/2+(int)decalageColonne),posx-ligne*cubeSize-ligne+(colonne*cubeSize+colonne),cubeSize,texture,textureWidth,textureHeight,gN4);	
		else if(volcanMap[etage][colonne+ligne*mapW]==2)HBB_cube3D(posy+(ligne*cubeSize/2+(int)decalageLigne)+(colonne*cubeSize/2+(int)decalageColonne),posx-ligne*cubeSize-ligne+(colonne*cubeSize+colonne),cubeSize,texture,textureWidth,textureHeight,rN4);	
		else if(volcanMap[etage][colonne+ligne*mapW]==3)HBB_cube3D(posy+(ligne*cubeSize/2+(int)decalageLigne)+(colonne*cubeSize/2+(int)decalageColonne),posx-ligne*cubeSize-ligne+(colonne*cubeSize+colonne),cubeSize,texture,textureWidth,textureHeight,HBB_terre);
		else if(volcanMap[etage][colonne+ligne*mapW]==4)HBB_cube3D(posy+(ligne*cubeSize/2+(int)decalageLigne)+(colonne*cubeSize/2+(int)decalageColonne),posx-ligne*cubeSize-ligne+(colonne*cubeSize+colonne),cubeSize,texture,textureWidth,textureHeight,HBB_org);
		else if(volcanMap[etage][colonne+ligne*mapW]==6)HBB_cube3D(posy+(ligne*cubeSize/2+(int)decalageLigne)+(colonne*cubeSize/2+(int)decalageColonne),posx-ligne*cubeSize-ligne+(colonne*cubeSize+colonne),cubeSize,texture,textureWidth,textureHeight,Gre);
    
	}  
}
void HBB_drawStage3D(Uint32 *texture,int textureW,int textureH,int *topMap,int topW,int topH,
int *leftMap,int leftW,int leftH,int *rightMap,int rightW,int rightH){
	Uint32 top[20*20];
	Uint32 left[20*20];
	Uint32 right[20*20];
	int init;
	for(init=0;init<400;init++){
		top[init]=3;
		left[init]=3;
		right[init]=3;
	}   	
	memset(texture, 0, textureW*textureH * sizeof(Uint32));
	HBB_drawVoxelRight(texture,textureW,textureH,13,right,rightW-1,rightH-1,0,0);
    HBB_drawVoxelLeft(texture,textureW,textureH,13,left,leftW-1,leftH-1,14,-6);
	HBB_drawVoxelTop(texture,textureW,textureH,13,top,topW-1,topH-1,0,16);
	HBB_drawVoxelRight(texture,textureW,textureH,13,rightMap,rightW,rightH,1,1);
   	HBB_drawVoxelLeft(texture,textureW,textureH,13,leftMap,leftW,leftH,1,1);
  	HBB_drawVoxelTop(texture,textureW,textureH,13,topMap,topW,topH,1,1);

}
void HBB_drawStageRainbow(Uint32* pix,int w,int h){
	memset(pix,0,w*h* sizeof(Uint32));
	HBB_drawRainbowCube(pix,w,h,148,183);
	HBB_drawVoxelRight(pix,w,h,15,MAP3Dright,16,15,1,-50);
	HBB_drawVoxelLeft(pix,w,h,15,MAP3Dleft,17,15,23,-57);
	HBB_drawVoxelTop(pix,w,h,15,MAP3Dtoit,17,17,-1,0);
}


void HBB_drawScoreBoard(Uint32* pixels,int w,int h,int score,int x,int y){
	int i;
	int * alphaTab[]={alpha0,alpha1,alpha2
	,alpha3,alpha4,alpha5,alpha6,alpha7,alpha8,
	alpha9};
	HBB_drawVoxelLeft(pixels,w,h,3,alphaS,5,5,x,-y);
	HBB_drawVoxelLeft(pixels,w,h,3,alphaC,5,5,x+30,-y+15);
	HBB_drawVoxelLeft(pixels,w,h,3,alphaO,5,5,x+60,-y+30);
	HBB_drawVoxelLeft(pixels,w,h,3,alphaR,5,5,x+90,-y+45);
	HBB_drawVoxelLeft(pixels,w,h,3,alphaE,5,5,x+120,-y+60);
  	HBB_drawVoxelLeft(pixels,w,h,3,alphaDeuxPoint,5,5,x+150,-y+75);
	if(score==0)HBB_drawVoxelLeft(pixels,w,h,3,alpha0,5,5,x+180,-y+90);
	else if(10<=score&&score<100){
	for(i=0;i<10;i++)
  	HBB_drawVoxelLeft(pixels,w,h,3,alphaTab[score/10],5,5,x+180,-y+90);
  	HBB_drawVoxelLeft(pixels,w,h,3,alpha0,5,5,x+205,-y+105);
  	HBB_drawVoxelLeft(pixels,w,h,3,alpha0,5,5,x+230,-y+120);
	}	
	else if(100<=score&&score<1000){
	for(i=0;i<10;i++)
  	HBB_drawVoxelLeft(pixels,w,h,3,alphaTab[score/100],5,5,x+180,-y+90);
  	HBB_drawVoxelLeft(pixels,w,h,3,alphaTab[(score/10)%10],5,5,x+210,-y+105);
  	HBB_drawVoxelLeft(pixels,w,h,3,alpha0,5,5,x+235,-y+120);
  	HBB_drawVoxelLeft(pixels,w,h,3,alpha0,5,5,x+260,-y+135);
	}	
}



void CHARLIE_drawStagerand(Uint32 *texture,int texW,int texh,int cubeSize){
  float decalageColonne,decalageLigne;
  int ligne,colonne,etage;
  int posy=150+2*cubeSize-5;
  int posx=380;
  int mapW=10;
  int mapH=10;

    memset(texture,0,texW*texh*sizeof(Uint32));
  	for(etage=0;etage<3;etage++,posy-=cubeSize+2)
  		for(ligne=0,decalageLigne=0.5;ligne<mapH;ligne++,decalageLigne+=0.5)
    		for(colonne=0,decalageColonne=0.5;colonne<mapW;colonne++,decalageColonne+=0.5){
		    if(etage==0)HBB_cube3D(posy+(ligne*cubeSize/2+(int)decalageLigne)+(colonne*cubeSize/2+(int)decalageColonne),posx-ligne*cubeSize-ligne+(colonne*cubeSize+colonne),cubeSize,texture,texW,texh,HBB_green);
		    if(etage==1&&CHARLIE_earth[colonne+ligne*mapW]==3)HBB_cube3D(posy+(colonne*cubeSize/2+(int)decalageLigne)+(ligne*cubeSize/2+(int)decalageColonne),posx-ligne*cubeSize-ligne+(colonne*cubeSize+colonne),cubeSize,texture,texW,texh,CHARLIE_col);
		    if(etage==1&&CHARLIE_earth[colonne+ligne*mapW]==4)HBB_cube3D(posy+(colonne*cubeSize/2+(int)decalageLigne)+(ligne*cubeSize/2+(int)decalageColonne),posx-ligne*cubeSize-ligne+(colonne*cubeSize+colonne),cubeSize,texture,texW,texh,CHARLIE_co);
		    if(etage==2&&CHARLIE_earth2[colonne+ligne*mapW]==1)HBB_cube3D(posy+(colonne*cubeSize/2+(int)decalageLigne)+(ligne*cubeSize/2+(int)decalageColonne),posx-ligne*cubeSize-ligne+(colonne*cubeSize+colonne),cubeSize,texture,texW,texh,CHARLIE_c);
		    if(etage==2&&CHARLIE_earth2[colonne+ligne*mapW]==2)HBB_cube3D(posy+(colonne*cubeSize/2+(int)decalageLigne)+(ligne*cubeSize/2+(int)decalageColonne),posx-ligne*cubeSize-ligne+(colonne*cubeSize+colonne),cubeSize,texture,texW,texh,NH_red);
		    }
}


