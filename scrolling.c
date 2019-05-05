void scrolling(personnage *p,stage *stage1)
{      
if((p->position.x>=450)&&(stage1->pos.x<=(4730-558)))
       {
         stage1->pos.x+=20;
         monstre.x-=20;
         p->position.x=430;
         p->v.o.positionObjet.x+=0.1;
       }
 if((p->position.x<=70)&&(stage1->pos.x>=0))
             {
         stage1->pos.x-=20;
         monstre.x+=20;
         p->position.x=90;
         p->v.o.positionObjet.x-=0.1;
             }

}
