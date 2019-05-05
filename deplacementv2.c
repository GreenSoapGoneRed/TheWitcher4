
int Deplacement_personnage(SDL_Event *event,personnage *p,int *continuer,stage *s,pmap *pmap)
{
int what=0;	
SDL_PollEvent(event);
     switch(event->type)
        {
            case SDL_QUIT:
                (*continuer)=0;
                break;
            case SDL_MOUSEBUTTONDOWN :
if(event->button.button==SDL_BUTTON_LEFT)
   {
if(event->button.x-s->pos.x>p->position.x-s->pos.x)
{if(collision_droite(p->sprite,s->mask,&p->position,s)!=1)
p->position.x+=p->vitesse+p->acceleration*0.2;}

if(event->button.x-s->pos.x<p->position.x-s->pos.x)
{if(collision_gauche(p->sprite,s->mask,&p->position,s)!=1)
p->position.x-=p->vitesse+p->acceleration*0.2;}


    }
break;           
 case SDL_KEYDOWN:
                switch(event->key.keysym.sym)
                {
                    case SDLK_ESCAPE : 
what=sous_menu_ig(*s);
break;
                    case SDLK_UP: 
if(collision_up(p->sprite,s->mask,&p->position,s)!=1)
{p->position.y-=p->vitesse/6;

}
                        break;
                    case SDLK_DOWN: 
if(collision_gravite(p->sprite,s->mask,&p->position,s)!=1)
p->position.y+=p->vitesse/6;

                        break;
                    case SDLK_RIGHT: 
if(collision_droite(p->sprite,s->mask,&p->position,s)!=1)
{
pmap->nbmoved++;
p->position.x+=p->vitesse+p->acceleration*0.2;
s->camera.x+=p->vitesse+p->acceleration*0.2;
if(s->camera.x>s->background->w-s->ecran->w)
s->camera.x=s->background->w-s->ecran->w;
}
                        break;
                    case SDLK_LEFT:
if(collision_gauche(p->sprite,s->mask,&p->position,s)!=1) 
{
pmap->nbmoved--;
p->position.x-=p->vitesse+p->acceleration*0.2;
s->camera.x-=p->vitesse+p->acceleration*0.2;
if(s->camera.x<0)
s->camera.x=0;
}
                       break;
                }
               
break;
   }
return what;
}
