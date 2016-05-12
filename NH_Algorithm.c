
#include<stdlib.h>
#define	NH_WIDTHMAP 30
#define	NH_HEIGHTMAP 30
#define Up 8
#define Left 4
#define Down 2
#define Right 6
struct NH_pos{
  int x;
  int y;
  int direction;
  int done;
  int tab;
};

typedef struct NH_pos NH_pos;
static NH_pos *snake;
static int taille;
static int SCORE=0;
static int MAXPOMMES=20;
static int POMMES=0;

void NH_init_snake(){
  taille=0;
  snake= malloc(900*sizeof((NH_pos)snake[0]));
  int i;
  for(i=5; i<NH_WIDTHMAP*NH_HEIGHTMAP; i++)
    snake[i].x=snake[i].y=snake[i].direction=-1;

  snake[0].x=4;snake[0].y=0;
  snake[1].x=3;snake[1].y=0;
  snake[2].x=2;snake[2].y=0;
  snake[3].x=1;snake[3].y=0;
  snake[4].x=snake[4].y=0;
  for(i=0;i<5;i++){
    snake[i].direction=Right;
    snake[i].tab=1;
  }
  taille+=5;

}


void NH_affiche(int * tab,int w,int h){
  int x,y,i;
  for(i=0;i<taille;i++){
    if(tab[snake[i].x+snake[i].y*w]>1)return;
    else if(snake[i].x>=0&&snake[i].y>=0&&snake[i].x<w&&snake[i].y<h)tab[snake[i].x+snake[i].y*w]=1;
    //tab[snake[0].x+snake[0].y*w]=11;
  }

}

void NH_deplacement(int * map,int mapX,int mapY){
  int i;
  NH_pos tmp; 
  int a=rand()%(mapX*mapY);
  tmp.x=snake[taille-1].x;
  tmp.y=snake[taille-1].y;
  tmp.direction=snake[taille-1].direction;
  

  if(map[snake[taille-1].x+snake[taille-1].y*mapX]>1);
  else map[snake[taille-1].x+snake[taille-1].y*mapX]=0;
  for(i=taille-1; i>0; i--){
    snake[i].x=snake[i-1].x;
    snake[i].y=snake[i-1].y;
    snake[i].direction=snake[i-1].direction;
  }

  if(snake[0].direction==Right){
   if(map[snake[0].x+1+(snake[0].y*mapX)]==2){
      map[snake[0].x+1+(snake[0].y*mapX)]=0;
      snake[taille].x=tmp.x;
      snake[taille].y=tmp.y;
      snake[taille].direction=tmp.direction;
      taille++;
      SCORE+=10;
      while(map[a])
	a= rand()%(mapX*mapY);
      map[a]=2;
    }
    snake[0].x++;
    //snake[0].direction=Down;
  }
  if(snake[0].direction==Down){
      if(map[snake[0].x+(snake[0].y+1)*mapX]==2){
      snake[taille].x=tmp.x;
      snake[taille].y=tmp.y;
      snake[taille].direction=tmp.direction;
      map[snake[0].x+(snake[0].y+1)*mapX]=0;
      taille++;
      SCORE+=10;
      while(map[a])
	a= rand()%(mapX*mapY);
      map[a]=2;
    }
    snake[0].y++;
    // snake[0].direction=Down;
  }
  if(snake[0].direction==Up){
     if(map[(snake[0].y-1)*mapX +snake[0].x]==2){
      map[(snake[0].y-1)*mapX +snake[0].x]=0;
      snake[taille].x=tmp.x;
      snake[taille].y=tmp.y;
      snake[taille].direction=tmp.direction;
      taille++;
      SCORE+=10;
      while(map[a])
	a= rand()%(mapX*mapY);
      map[a]=2;
    }
    snake[0].y--;
    // snake[0].direction=Down;
  }
  if(snake[0].direction==Left){
        if( map[snake[0].x-1+(snake[0].y*mapX)]==2){
	
	  map[snake[0].x-1+(snake[0].y*mapX)]=0;
      snake[taille].x=tmp.x;
      snake[taille].y=tmp.y;
      snake[taille].direction=tmp.direction;
      taille++;
      SCORE+=10;
      while(map[a])
	a= rand()%(mapX*mapY);
       map[a]=2;
    }

    snake[0].x--;
    //snake[0].direction=Down;
  }

 
}
void NH_affiche_3D(int * tab,int w,int h,int * tabg,int wg,int hg,int * tabd,int wd,int hd){
  int x,y,i;
  for(i=0;i<taille;i++){
    if(snake[i].tab==1){
   // if(tab[snake[i].x+snake[i].y*w]>1)return;
    if(snake[i].x>=0&&snake[i].y>=0&&snake[i].x<w&&snake[i].y<h)tab[snake[i].x+snake[i].y*w]=1;
    }else if(snake[i].tab==2){

  //  if(tabd[snake[i].x+snake[i].y*wd]>1)return;
    if(snake[i].x>=0&&snake[i].y>=0&&snake[i].x<wg&&snake[i].y<hg)
tabg[snake[i].x+snake[i].y*wg]=1;
    }else if(snake[i].tab==3){

  //  if(tabg[snake[i].x+snake[i].y*wg]>1)return;
     if(snake[i].x>=0&&snake[i].y>=0&&snake[i].x<wd&&snake[i].y<hd)
tabd[snake[i].x+snake[i].y*wd]=1;
	 }
  }
}
void NH_deplacement_3D(int * map,int mapX,int mapY,int *mapLeft,int mapLeftX,int mapLeftY,int *mapRight,int mapRightX,int mapRightY){
  int i;
  NH_pos tmp; 
  int a=rand()%(mapX*mapY);
  int a2=rand()%(mapLeftX*mapLeftY);
  int a3=rand()%(mapRightX*mapRightY);
  int rnd;
  tmp.x=snake[taille-1].x;
  tmp.y=snake[taille-1].y;
  tmp.direction=snake[taille-1].direction;
 


 // if(map[snake[taille-1].x+snake[taille-1].y*mapX]>1);
 // else {
if(snake[taille-1].tab==1)map[snake[taille-1].x+snake[taille-1].y*mapX]=0;
if(snake[taille-1].tab==2)mapLeft[snake[taille-1].x+snake[taille-1].y*mapLeftX]=0;
if(snake[taille-1].tab==3)mapRight[snake[taille-1].x+snake[taille-1].y*mapRightX]=0;

//}


  for(i=taille-1; i>0; i--){
    snake[i].x=snake[i-1].x;
    snake[i].y=snake[i-1].y;
    snake[i].direction=snake[i-1].direction;
    snake[i].tab=snake[i-1].tab;
  }


 if(snake[0].direction==Right){ //3D Deplacement TOP to RIGHT
   if(snake[0].tab==1){
     if(snake[0].x==mapX-1){
       snake[0].tab=3;
       snake[0].x=mapX-1-2-snake[0].y;
       snake[0].y=-1;
       snake[0].direction=Down;
      }
   }else if(snake[0].tab==2){ //3D Deplacement LEFT to RIGHT
   if(snake[0].x==mapLeftX-1){
      snake[0].tab=3;
      snake[0].x=-1;
   }
}



   if((map[snake[0].x+1+(snake[0].y*mapX)]==2&&snake[0].tab==1)||(mapLeft[snake[0].x+1+(snake[0].y*mapLeftX)]==2&&snake[0].tab==2)||(mapRight[snake[0].x+1+(snake[0].y*mapRightX)]==2&&snake[0].tab==3)){

if(snake[0].tab==1)map[snake[0].x+1+(snake[0].y*mapX)]=0;
if(snake[0].tab==2)mapLeft[snake[0].x+1+(snake[0].y*mapLeftX)]=0;
if(snake[0].tab==3)mapRight[snake[0].x+1+(snake[0].y*mapRightX)]=0;



      snake[taille].x=tmp.x;
      snake[taille].y=tmp.y;
      snake[taille].direction=tmp.direction;
      taille++;
      SCORE+=10;

if(POMMES<MAXPOMMES){
  rnd= rand()%4;
  if(rnd==1){
    while(map[a])
	a= rand()%(mapX*mapY);
       map[a]=2;
	POMMES++;
  }
  if(rnd==2){
    while(mapLeft[a2])
	a2=rand()%(mapLeftX*mapLeftY);
    mapLeft[a2]=2;
	POMMES++;
  }
  else{
    while(mapRight[a3])
	a3=rand()%(mapRightX*mapRightY);
	mapRight[a3]=2;
	POMMES++;
	}	
 }   
	      
    }
    snake[0].x++;

//////////////////////////////////////////////////////////
  }
  if(snake[0].direction==Down){ //3D Deplacement TOP to LEFT
    if(snake[0].tab==1){
	if(snake[0].y==mapY-1){
      snake[0].tab=2;
      snake[0].y=-1;
      snake[0].direction=Down;
	}
    }
///////////////////////////////////////////////
    if((map[snake[0].x+(snake[0].y+1)*mapX]==2&&snake[0].tab==1)
||(mapLeft[snake[0].x+(snake[0].y+1)*mapLeftX]==2&&snake[0].tab==2)
||(mapRight[snake[0].x+(snake[0].y+1)*mapRightX]==2&&snake[0].tab==3)){
	if(snake[0].tab==1)map[snake[0].x+(snake[0].y+1)*mapX]=0;
	if(snake[0].tab==2)mapLeft[snake[0].x+(snake[0].y+1)*mapLeftX]=0;
	if(snake[0].tab==3)mapRight[snake[0].x+(snake[0].y+1)*mapRightX]=0;
      snake[taille].x=tmp.x;
      snake[taille].y=tmp.y;
      snake[taille].direction=tmp.direction;
      map[snake[0].x+(snake[0].y+1)*mapX]=0;
      taille++;
      SCORE+=10;

if(POMMES<MAXPOMMES){
  rnd=rand()%4;
  if(rnd==1){
    while(map[a])
	a= rand()%(mapX*mapY);
       map[a]=2;
	POMMES++;
  }
  if(rnd==2){
    while(mapLeft[a2])
	a2=rand()%(mapLeftX*mapLeftY);
    mapLeft[a2]=2;
	POMMES++;
  }
  else{
    while(mapRight[a3])
	a3=rand()%(mapRightX*mapRightY);
	mapRight[a3]=2;
	POMMES++;
	}
 }	
      
    }
    snake[0].y++;
///////////////////////////////////////////////
  }
 if(snake[0].direction==Up){
    if(snake[0].y==0&&snake[0].tab==2){ //3D Deplacement LEFT to TOP
      snake[0].tab=1;
      snake[0].y=mapLeftX;
      snake[0].direction=Up;
    }
    if(snake[0].y==0&&snake[0].tab==3){//3D Deplacement RIGHT to TOP
      snake[0].tab=1;
      snake[0].y=  snake[0].y=mapY-1-snake[0].x;
      snake[0].x=mapX;
      snake[0].direction=Left;
    }
    


//////////////////////////////////////////////////////////
    if((map[(snake[0].y-1)*mapX +snake[0].x]==2&&snake[0].tab==1)
       ||(mapLeft[(snake[0].y-1)*mapLeftX +snake[0].x]==2&&snake[0].tab==2)
       ||(mapRight[(snake[0].y-1)*mapRightX +snake[0].x]==2&&snake[0].tab==3)){

if(snake[0].tab==1)map[(snake[0].y-1)*mapX +snake[0].x]=0;
if(snake[0].tab==2)mapLeft[(snake[0].y-1)*mapLeftX +snake[0].x]=0;
if(snake[0].tab==3)mapRight[(snake[0].y-1)*mapRightX +snake[0].x]=0;



      snake[taille].x=tmp.x;
      snake[taille].y=tmp.y;
      snake[taille].direction=tmp.direction;
      taille++;
      SCORE+=10;
    
if(POMMES<MAXPOMMES){
  rnd = rand()%4;
  if(rnd==1){
    while(map[a])
	a= rand()%(mapX*mapY);
       map[a]=2;
	POMMES++;
  }
  if(rnd==2){
    while(mapLeft[a2])
	a2=rand()%(mapLeftX*mapLeftY);
    mapLeft[a2]=2;
	POMMES++;
  }
  else{
    while(mapRight[a3])
	a3=rand()%(mapRightX*mapRightY);
	mapRight[a3]=2;
	POMMES++;
	}	
    }
    }
    POMMES=1;
    snake[0].y--;
//////////////////////////////////////////////////////////
  }
 if(snake[0].direction==Left){

 if(snake[0].tab==3){ //3D Deplacement LEFT to RIGHT
    if(snake[0].x==0){
      snake[0].tab=2;
      snake[0].x=mapX;
      snake[0].direction=Left;
    }
}
 if(( map[snake[0].x-1+(snake[0].y*mapX)]==2&&snake[0].tab==1)
    ||(mapLeft[snake[0].x-1+(snake[0].y*mapLeftX)]==2&& snake[0].tab==2)||
    (mapRight[snake[0].x-1+(snake[0].y*mapRightX)]==2&&snake[0].tab==3)){
	
if(snake[0].tab==1)map[(snake[0].y-1)*mapX +snake[0].x]=0;
if(snake[0].tab==2)mapLeft[snake[0].x-1+(snake[0].y*mapLeftX)]=0;
if(snake[0].tab==3)mapRight[snake[0].x-1+(snake[0].y*mapRightX)]=0;

      snake[taille].x=tmp.x;
      snake[taille].y=tmp.y;
      snake[taille].direction=tmp.direction;
      taille++;
      SCORE+=10;
if(POMMES<MAXPOMMES){
  rnd= rand()%4;
  if(rnd==1){
    while(map[a])
	a= rand()%(mapX*mapY);
       map[a]=2;
	POMMES++;
  }
  if(rnd==2){
    while(mapLeft[a2])
	a2=rand()%(mapLeftX*mapLeftY);
    mapLeft[a2]=2;
	POMMES++;
  }
  else{
    while(mapRight[a3])
	a3=rand()%(mapRightX*mapRightY);
	mapRight[a3]=2;
	POMMES++;
	}
 }	
     ////////////
    }

    snake[0].x--;
  }

 
}

int NH_gameover(Uint32 * map,int mapX,int mapY){
  int i,j;
  if(snake[0].direction==Right&&(map[snake[0].x+1+snake[0].y*mapX]==3||map[snake[0].x+1+snake[0].y*mapX]==4))return 0;
  if(snake[0].direction==Left&&(map[snake[0].x-1+snake[0].y*mapX]==3||map[snake[0].x+1+snake[0].y*mapX]==4))return 0;
  if(snake[0].direction==Up&&(map[snake[0].x+(snake[0].y+1)*mapX]==3&&map[snake[0].x+(snake[0].y+1)*mapX]==4))return 0;
  if(snake[0].direction==Down&&(map[snake[0].x+(snake[0].y-1)*mapX]==3||map[snake[0].x+(snake[0].y-1)*mapX]==4))return 0;


  for(i=0;i<taille;i++)
    for(j=0;j<taille;j++)
      if((snake[i].x==snake[j].x && snake[i].y==snake[j].y&&i!=j)||(snake[i].y>=mapY||snake[i].x>=mapX||snake[i].x<0||snake[i].y<0))
	return 0;
  return 1;
 

}


int NH_gameover_3D(Uint32 * map,int mapX,int mapY,int * mapg,int wg,int hg,int * mapd,int wd,int hd){
  int i,j;

  if(snake[0].tab==1&&(snake[0].x<0||snake[0].y<0)){
  printf("cas 1 : %d %d \n",snake[0].x,snake[0].y);
  
return 0;
  }
  if(snake[0].tab==2&&((snake[0].x<0&&/*snake[0].y<hg*/1)||snake[0].y>hg-1))
    {
 printf("cas 2 : %d %d \n",snake[0].x,snake[0].y);
return 0;
    }
  if(snake[0].tab==3&&(snake[0].x>wd||snake[0].y>hg-1))
    {
 printf("cas 3: %d %d \n",snake[0].x,snake[0].y);
return 0;
    }
  if(snake[0].tab==1&&snake[0].x==mapX-1&&snake[0].y==mapY-1)return 0;
  
  
  switch(snake[0].tab){
  case 1:
    if(snake[0].direction==Right&&map[snake[0].x+1+snake[0].y*mapX]==9)return 0;
  if(snake[0].direction==Left&&map[snake[0].x-1+snake[0].y*mapX]==9)return 0;
  if(snake[0].direction==Up&&map[snake[0].x+(snake[0].y+1)*mapX]==9)return 0;
  if(snake[0].direction==Down&&map[snake[0].x+(snake[0].y-1)*mapX]==9)return 0;
	break;
  case 2: 
    
  if(snake[0].direction==Right&&mapg[snake[0].x+1+snake[0].y*wg]==9)return 0;
  if(snake[0].direction==Left&&mapg[snake[0].x-1+snake[0].y*wg]==9)return 0;
  if(snake[0].direction==Up&&mapg[snake[0].x+(snake[0].y+1)*wg]==9)return 0;
  if(snake[0].direction==Down&&mapg[snake[0].x+(snake[0].y-1)*wg]==9)return 0;
    	break;
case 3: 
   if(snake[0].direction==Right&&mapd[snake[0].x+1+snake[0].y*wd]==9)return 0;
  if(snake[0].direction==Left&&mapd[snake[0].x-1+snake[0].y*wd]==9)return 0;
  if(snake[0].direction==Up&&mapd[snake[0].x+(snake[0].y+1)*wd]==9)return 0;
  if(snake[0].direction==Down&&mapd[snake[0].x+(snake[0].y-1)*wd]==9)return 0;
	break;
	default:
		break;
  }
  
  
   for(i=0;i<taille;i++)
    for(j=0;j<taille;j++)
      if(snake[i].x==snake[j].x && snake[i].y==snake[j].y&&i!=j&&snake[i].tab==snake[j].tab)
      return 0;
  return 1;
   

}


