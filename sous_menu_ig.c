int sous_menu_ig(stage s)
{
int sousmenu=1;
SDL_Event event;
SDL_Surface *texte=NULL,*sprite1=NULL,*sprite2=NULL,*sprite3=NULL;
TTF_Font *police = NULL;
SDL_Color couleur = {255,255, 255};
SDL_Rect textposition,positionsprite2,positionsprite1,positionsprite3;
//position sprite& texte 
textposition.x=230;
textposition.y=210;
positionsprite1.x=230;
positionsprite1.y=140;
positionsprite1.w =128;
positionsprite1.h =26;
positionsprite2.x=230;
positionsprite2.y=260;
positionsprite2.w =128;
positionsprite2.h =26;
positionsprite3.x=230;
positionsprite3.y=200;
positionsprite3.h=26;
positionsprite3.w=128;
SDL_Flip(s.ecran);
charger_image("play.png",s.ecran,sprite1,&positionsprite1);
charger_image("quit.png",s.ecran,sprite2,&positionsprite2);
charger_image("save.png",s.ecran,sprite3,&positionsprite3);
int mouse=0,keyboard=0;
while(sousmenu){
SDL_WaitEvent(&event);
switch(event.type)
        { 
   case SDL_QUIT: sousmenu=0; break ;
   case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
             {case SDLK_UP:
              keyboard++;
              break;
              case SDLK_DOWN:  
              keyboard--;
              break;
              case SDLK_RETURN:
if(keyboard==3){
TTF_Quit();
SDL_FreeSurface(texte); 
SDL_FreeSurface(sprite1);
SDL_FreeSurface(sprite2);
sousmenu = 0;return 2;
break;} 
               
              if(keyboard==2){
TTF_Quit();
SDL_FreeSurface(texte); 
SDL_FreeSurface(sprite1);
SDL_FreeSurface(sprite2);
sousmenu=0;return -1;break;} 
              if(keyboard==1){
TTF_Quit();
SDL_FreeSurface(texte); 
SDL_FreeSurface(sprite1);
SDL_FreeSurface(sprite2);
sousmenu=0;
return 1;break;}
              break;
              }}
if(keyboard==1){charger_image("play2.png",s.ecran,sprite1,&positionsprite1);
}else {charger_image("play.png",s.ecran,sprite1,&positionsprite1);}
if(keyboard==3){charger_image("quit2.png",s.ecran,sprite2,&positionsprite2);}else {charger_image("quit.png",s.ecran,sprite2,&positionsprite2);}
if(keyboard==2){charger_image("save2.png",s.ecran,sprite3,&positionsprite3);}else{charger_image("save.png",s.ecran,sprite3,&positionsprite3);}
if(keyboard<1){keyboard=3; 
TTF_Quit();
SDL_FreeSurface(texte); 
SDL_FreeSurface(sprite1);
SDL_FreeSurface(sprite2);
SDL_FreeSurface(sprite3);
}
if(keyboard>3){keyboard=1;
TTF_Quit();
SDL_FreeSurface(texte); 
SDL_FreeSurface(sprite1);
SDL_FreeSurface(sprite2);
SDL_FreeSurface(sprite3);
}
} 
TTF_Quit();
SDL_FreeSurface(texte);
}
