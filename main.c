#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <stdlib.h>
#include <stdio.h>
#include "SDL/SDL_mixer.h"
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "header.h"
#include <SDL/SDL_ttf.h>

int main(int argc, char *argv[])
{ 
FILE *save;
pmap pmap;
personnage p1;
int what=-12;
int start_game=0,dead=0;
SDL_Event event;
    int continuer = 1;
     unsigned int frameLimit = SDL_GetTicks() + 16;
SDL_Rect position_enemy;
SDL_Surface *fenetre=NULL;
objet c1,c2;
int i=1,coll=0;
Mix_Music *musique;
char lien[20];
s.camera.w=558;
s.camera.h=417;
start_game=menu1();
if(start_game==1)
{
        SDL_Init(SDL_INIT_VIDEO);

        s.ecran = SDL_SetVideoMode(558,417, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);
        SDL_WM_SetCaption("Torn Asunder", NULL); 

if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
           {
           printf("%s",Mix_GetError());
           }

           musique=Mix_LoadMUS("music.ogg");
           Mix_PlayMusic(musique, -1);


        sprintf(lien,"r%d.png",i);
        p.sprite = IMG_Load(lien);
        s.mask=IMG_Load("trucalque.png");


        s.background=IMG_Load("final_map.png");
        SDL_SetColorKey(p.sprite, SDL_SRCCOLORKEY, SDL_MapRGB(p.sprite->format, 255, 255, 255));    
        initialiser_personnage(&p);
        s.background=initialiser_stage(&s,"final_map.png");
        afficher_background(s.background,&s.pos,s.ecran);
        s.pos.x=0;
        s.pos.y=0;
        c1=init(c1,740,70,40,32);
        c2=init(c2,740,68,40,32);
 afficher_objet(c1,"c1.png",s.background);
  initializeEnnemy();

position_enemy.x=monstre.x;
position_enemy.y=monstre.y;
position_enemy.h=10;
position_enemy.w=5;
//init minimap
initialiser_pmap(&pmap);
        while (continuer)
               {

what=Deplacement_personnage(&event,&p,&continuer,&s,&pmap);

if(p.position.y>250) p.position.y=250;
if(p.position.y<20) p.position.y=20;
            
               if(i>5){i=1;}                
               anim_perso(&i,&event,&p);
                scrolling(&p,&s);
                 // scroll_cam(p,&s); dummy.
                afficher_background(s.background,&s.pos,s.ecran);
//SDL_BlitSurface(s.background,&s.camera,s.ecran,&s.pos);                
afficher_vie(p.v,s.ecran);
    //sous_menu(s.ecran,"1r1");
afficher_pmap(&pmap,s.ecran);	
                SDL_BlitSurface(p.sprite, NULL,s.ecran,&p.position);
                  drawanimatedEnnemy();
                   SDL_Flip(s.ecran);
                  delay(frameLimit);
                  frameLimit = SDL_GetTicks() + 16;
              
if(collision_gauche_objet(p.sprite,s.mask,&p.position,&s)==1){
afficher_objet(c2,"c2.png",s.background);
p.score=20;
printf("Score = %d",p.score);
}

position_enemy.x=monstre.x;
position_enemy.y=monstre.y;
position_enemy.h=20;
position_enemy.w=10;
                SDL_Flip(s.ecran);
if(what==3) SaveGame(&p,&monstre,&s,save);
if(what==2) {start_game=menu1();}  
if(what==1) ;
            }    

        }
 SDL_FreeSurface(s.background);
 SDL_FreeSurface(p.sprite);
    SDL_Quit();

    return EXIT_SUCCESS;

}	
