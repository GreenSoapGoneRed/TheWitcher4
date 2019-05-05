
void SaveGame(personnage *p,ENNEMY *e,stage *s,FILE *f)
 {
int persox,persoy,stagex,stagey,monstrex,monstrey;
persox=p->position.x;
persoy=p->position.y;
monstrex=e->x;
monstrey=e->y;
stagex=s->pos.x;
stagey=s->pos.y;

     f=fopen("/home/hbib/Desktop/TheGameSoFar/save.txt","w");
     if (f==NULL)
     {
         printf("\nAn error has occured during your save.");
     }
     else
     {
     fprintf(f,"%d\n %d\n %d\n %d\n %d\n %d\n %d\n %d\n ",stagex,stagey,p->score,p->v.val,persox,persoy,monstrex,monstrey);

    }
 fclose(f);
 }

void LoadGame(personnage *p,ENNEMY *e ,stage *s,FILE *f)
{
int persox,persoy,stagex,stagey,monstrex,monstrey,vie,score;
    f=fopen("/home/hbib/Desktop/TheGameSoFar/save.txt","r");
    if (f==NULL){

  printf ("\nAn error has occured during your load.");}
 else
     {
fscanf(f,"%d\n %d\n %d\n %d\n %d\n %d\n %d\n %d\n ",&stagex,&stagey,&score,&vie,&persox,&persoy,&monstrex,&monstrey);
    }
fclose(f);
p->position.x=persox;
p->position.y=persoy;
e->x=monstrex;
e->y=monstrey;
s->pos.x=stagex;
s->pos.y=stagey;
p->v.val=vie;
p->score=score;
}

