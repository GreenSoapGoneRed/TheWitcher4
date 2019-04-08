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
int main(int argc, char *argv[])
{ int start_game=0;
SDL_Event event;
    int continuer = 1;
     unsigned int frameLimit = SDL_GetTicks() + 16;

objet c1,c2;
int i=1;
Mix_Music *musique;
char lien[20];
start_game=menu1();
if(start_game==1){
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
        s.background=IMG_Load("final_map.png");
        SDL_SetColorKey(p.sprite, SDL_SRCCOLORKEY, SDL_MapRGB(p.sprite->format, 255, 255, 255));    
        initialiser_personnage(&p);
        s.background=initialiser_stage(&s,"final_map.png");
        afficher_background(s.background,&s.pos,s.ecran);
        s.pos.x=0;
        s.pos.y=0;
        c1=init(c1,740,70,40,32);
        c2=init(c2,740,70,40,32);
 afficher_objet(c1,"c1.png",s.background);
  initializeEnnemy();
       
        while (continuer)
               {Deplacement_personnage(&event,&p,&continuer,&s);
              
               if(i>5){i=1;}                
               anim_perso(&i,&event,&p);

                scrolling(&p,&s);
                afficher_background(s.background,&s.pos,s.ecran);
                afficher_vie(p.v,s.ecran);
                SDL_BlitSurface(p.sprite, NULL,s.ecran,&p.position);
                  drawanimatedEnnemy();
                   SDL_Flip(s.ecran);
                  delay(frameLimit);
                  frameLimit = SDL_GetTicks() + 16;
               
if(Collission(p.position,c1.positionObjet)==1){
afficher_objet(c2,"c2.png",s.background);
printf("collision ");
}
                SDL_Flip(s.ecran);
               }    

        }
 SDL_FreeSurface(s.background);
 SDL_FreeSurface(p.sprite);
    SDL_Quit();

    return EXIT_SUCCESS;

}
