#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <stdio.h>

ALLEGRO_DISPLAY *janela = NULL;
ALLEGRO_BITMAP *mapa = NULL, *plata = NULL, *spritePersonagem = NULL, *spritePortal = NULL;
ALLEGRO_EVENT_QUEUE *filaEventos = NULL;
ALLEGRO_FONT *fonte = NULL;
ALLEGRO_TIMER *timer = NULL;
int sair = 0, tecla = 0, teclaPulo = 0, inverte = 0, lado = 0, i=0, noAr = 0, cont = 0;
int alturaPerso = 49, larguraPerso = 48, regiaoxPerso = 0, regiaoyPerso = 0, posxPerso = 455, posyPerso = 265;
int alturaPortal = 100, larguraPortal = 100, regiaoxPortal1 = 400, regiaoyPortal1 = 0, posxPortal1 = 365, 
posyPortal1 = 325, regiaoxPortal2 = 400, regiaoyPortal2 = 0, posxPortal2 = 420, 
posyPortal2 = 225;;

int pulaSobe(int tecla, int inverte, int regiaoxPerso, int regiaoyPerso, int larguraPerso, int alturaPerso, int posxPerso, int posyPerso){
    int i, k;
    if(inverte==0){
        regiaoxPerso = 2*larguraPerso;
        regiaoyPerso = 0*alturaPerso;

        posyPerso-=10;
        al_draw_bitmap_region(mapa, 0, 0, al_get_bitmap_width(mapa), al_get_bitmap_height(mapa), 0, 0, 0);
        al_draw_bitmap(plata, 455, 300, 0);
        al_draw_bitmap(plata, 50, 400, 0);
        al_draw_bitmap_region(spritePortal, regiaoxPortal2, regiaoyPortal2, larguraPortal,alturaPortal, posxPortal2,posyPortal2,0);
        al_draw_bitmap_region(spritePortal, regiaoxPortal1, regiaoyPortal1, larguraPortal,alturaPortal, posxPortal1,posyPortal1,0);
        al_draw_bitmap_region(spritePersonagem, regiaoxPerso,regiaoyPerso, larguraPerso,alturaPerso, posxPerso,posyPerso,0);
        al_flip_display();
        al_rest(0.035);
          
    }else{
        regiaoxPerso = 2*larguraPerso;
        regiaoyPerso = 0*alturaPerso;

        posyPerso-=10;
        al_draw_bitmap_region(mapa, 0, 0, al_get_bitmap_width(mapa), al_get_bitmap_height(mapa), 0, 0, 0);
        al_draw_bitmap(plata, 455, 300, 0);
        al_draw_bitmap(plata, 50, 400, 0);
        al_draw_bitmap_region(spritePortal, regiaoxPortal2, regiaoyPortal2, larguraPortal,alturaPortal, posxPortal2,posyPortal2,0);
        al_draw_bitmap_region(spritePortal, regiaoxPortal1, regiaoyPortal1, larguraPortal,alturaPortal, posxPortal1,posyPortal1,0);
        al_draw_bitmap_region(spritePersonagem, regiaoxPerso,regiaoyPerso, larguraPerso,alturaPerso, posxPerso,posyPerso,ALLEGRO_FLIP_HORIZONTAL);
        al_flip_display();
        al_rest(0.035);
        
    }
    al_flip_display();
    return posyPerso;
}

int pulaDesce(int tecla, int inverte, int regiaoxPerso, int regiaoyPerso, int larguraPerso, int alturaPerso, int posxPerso,int posyPerso){
    int i, k;
    if(inverte==0){
        regiaoxPerso = 2*larguraPerso;
        regiaoyPerso = 0*alturaPerso;
        for(i=0; i<3; i++){
            posyPerso+=10;
            al_draw_bitmap_region(mapa, 0, 0, al_get_bitmap_width(mapa), al_get_bitmap_height(mapa), 0, 0, 0);
            al_draw_bitmap(plata, 455, 300, 0);
            al_draw_bitmap(plata, 50, 400, 0);
            al_draw_bitmap_region(spritePortal, regiaoxPortal2, regiaoyPortal2, larguraPortal,alturaPortal, posxPortal2,posyPortal2,0);
            al_draw_bitmap_region(spritePortal, regiaoxPortal1, regiaoyPortal1, larguraPortal,alturaPortal, posxPortal1,posyPortal1,0);
            al_draw_bitmap_region(spritePersonagem, regiaoxPerso,regiaoyPerso, larguraPerso,alturaPerso, posxPerso,posyPerso,0);
            al_flip_display();
            al_rest(0.035);
        }
        
        
    }else{
        regiaoxPerso = 2*larguraPerso;
        regiaoyPerso = 0*alturaPerso;
        for(i=0; i<3; i++){
            posyPerso+=10;
            al_draw_bitmap_region(mapa, 0, 0, al_get_bitmap_width(mapa), al_get_bitmap_height(mapa), 0, 0, 0);
            al_draw_bitmap(plata, 455, 300, 0);
            al_draw_bitmap(plata, 50, 400, 0);
            al_draw_bitmap_region(spritePortal, regiaoxPortal2, regiaoyPortal2, larguraPortal,alturaPortal, posxPortal2,posyPortal2,0);
            al_draw_bitmap_region(spritePortal, regiaoxPortal1, regiaoyPortal1, larguraPortal,alturaPortal, posxPortal1,posyPortal1,0);
            al_draw_bitmap_region(spritePersonagem, regiaoxPerso,regiaoyPerso, larguraPerso,alturaPerso, posxPerso,posyPerso,ALLEGRO_FLIP_HORIZONTAL);
            al_flip_display();
            al_rest(0.035);
        }
    }
    al_flip_display();
    return posyPerso;
}

int dash(int tecla, int inverte, int regiaoxPerso, int regiaoyPerso, int larguraPerso, int alturaPerso, int posxPerso, int posyPerso, int lado){
    int i;
    if(inverte==0){
        regiaoxPerso = 1*larguraPerso;
        regiaoyPerso = 1*alturaPerso;
        for(i=0;i<3; i++){
            posxPerso+=7;
            al_draw_bitmap_region(mapa, 0, 0, al_get_bitmap_width(mapa), al_get_bitmap_height(mapa), 0, 0, 0);
            al_draw_bitmap(plata, 455, 300, 0);
            al_draw_bitmap(plata, 50, 400, 0);
            al_draw_bitmap_region(spritePortal, regiaoxPortal2, regiaoyPortal2, larguraPortal,alturaPortal, posxPortal2,posyPortal2,0);
            al_draw_bitmap_region(spritePortal, regiaoxPortal1, regiaoyPortal1, larguraPortal,alturaPortal, posxPortal1,posyPortal1,0);
            al_draw_bitmap_region(spritePersonagem, regiaoxPerso,regiaoyPerso, larguraPerso,alturaPerso, posxPerso,posyPerso,0);
            al_flip_display();
            al_rest(0.05);
        }
        return posxPerso;
    }else{
        regiaoxPerso = 1*larguraPerso;
        regiaoyPerso = 1*alturaPerso;
        for(i=0; i<3; i++){
            posxPerso-=7;
            al_draw_bitmap_region(mapa, 0, 0, al_get_bitmap_width(mapa), al_get_bitmap_height(mapa), 0, 0, 0);
            al_draw_bitmap(plata, 455, 300, 0);
            al_draw_bitmap(plata, 50, 400, 0);
            al_draw_bitmap_region(spritePortal, regiaoxPortal2, regiaoyPortal2, larguraPortal,alturaPortal, posxPortal2,posyPortal2,0);
            al_draw_bitmap_region(spritePortal, regiaoxPortal1, regiaoyPortal1, larguraPortal,alturaPortal, posxPortal1,posyPortal1,0);
            al_draw_bitmap_region(spritePersonagem, regiaoxPerso,regiaoyPerso, larguraPerso,alturaPerso, posxPerso,posyPerso,ALLEGRO_FLIP_HORIZONTAL);
            al_flip_display();
            al_rest(0.05);
        }
        return posxPerso;
        }           
}

int cair(int tecla, int inverte, int regiaoxPerso, int regiaoyPerso, int larguraPerso, int alturaPerso, int posxPerso, int posyPerso, int lado){
        regiaoxPerso = 2*larguraPerso;
        regiaoyPerso = 0*alturaPerso;
        posyPerso+=10;
        al_draw_bitmap_region(mapa, 0, 0, al_get_bitmap_width(mapa), al_get_bitmap_height(mapa), 0, 0, 0);
        al_draw_bitmap(plata, 455, 300, 0);
        al_draw_bitmap(plata, 50, 400, 0);
        al_draw_bitmap_region(spritePortal, regiaoxPortal2, regiaoyPortal2, larguraPortal,alturaPortal, posxPortal2,posyPortal2,0);
        al_draw_bitmap_region(spritePortal, regiaoxPortal1, regiaoyPortal1, larguraPortal,alturaPortal, posxPortal1,posyPortal1,0);
        al_draw_bitmap_region(spritePersonagem,regiaoxPerso,regiaoyPerso, larguraPerso,alturaPerso, posxPerso,posyPerso,0);
        al_flip_display();
        al_rest(0.05);
    return posyPerso;

}

void inicializaTudo() {
    if(!al_init()){
        printf("al init\n");
    }
    if(!al_init_image_addon()){
        printf("al init image\n");
    }
    if(!al_init_font_addon()){
        printf("al init font\n");
    }
    if(!al_init_ttf_addon()){
        printf("al init ttf\n");
    }
    if(!al_install_keyboard()){
        printf("keyboard\n");
    }
    if(!al_install_mouse()){
        printf("mouse\n");
    }
    timer = al_create_timer(1.0 / 60);
    if(!timer){
        printf("timer");
    } 
    mapa = al_load_bitmap("img/mapa.png");
    if(!mapa){
        printf("mapa\n");
    }
    plata = al_load_bitmap("img/plata.png");
    if(!plata){
        printf("plata\n");
    }
    janela = al_create_display(al_get_bitmap_width(mapa), al_get_bitmap_height(mapa));
    if(!janela){
        printf("janela\n");
    }
    spritePersonagem = al_load_bitmap("sprites/sprite1.png");
    if(!spritePersonagem){
        printf("spritePersonagem\n");
    }
    spritePortal = al_load_bitmap("sprites/sprite2.png");
    if(!spritePersonagem){
        printf("spritePortal\n");
    }
    al_convert_mask_to_alpha(spritePersonagem, al_map_rgb(255, 0, 232));
    al_convert_mask_to_alpha(spritePortal, al_map_rgb(0, 0, 254));

    filaEventos = al_create_event_queue();
    if(!filaEventos){
        printf("filaEventos\n");
    }
    fonte = al_load_font("fonts/fonte.ttf", 30, 0);
    if(!fonte){
        printf("fonte contador\n");
    }
}


int main(void){
    // Inicializa tudo que precisa
    inicializaTudo();

    al_set_window_title(janela, "CInhalla");
    al_register_event_source(filaEventos, al_get_keyboard_event_source());
    al_register_event_source(filaEventos, al_get_display_event_source(janela));
    al_register_event_source(filaEventos, al_get_timer_event_source(timer));
    al_start_timer(timer);
    al_draw_bitmap_region(mapa, 0, 0, al_get_bitmap_width(mapa), al_get_bitmap_height(mapa), 0, 0, 0);
    al_draw_bitmap(plata, 455, 300, 0);
    al_draw_bitmap(plata, 50, 400, 0);
    al_draw_bitmap_region(spritePortal, regiaoxPortal2, regiaoyPortal2, larguraPortal,alturaPortal, posxPortal2,posyPortal2,0);
    al_draw_bitmap_region(spritePortal,regiaoxPortal1,regiaoyPortal1,larguraPortal,alturaPortal,posxPortal1,posyPortal1,0);
    al_draw_bitmap_region(spritePersonagem, regiaoxPerso,regiaoyPerso, larguraPerso,alturaPerso, posxPerso,posyPerso,0);
    al_flip_display();
    
    while(!sair){
        while(!al_is_event_queue_empty(filaEventos)){
            ALLEGRO_EVENT evento;
            al_wait_for_event(filaEventos, &evento);
                if(evento.type == ALLEGRO_EVENT_KEY_DOWN){ 
                    switch(evento.keyboard.keycode){ 
                        case ALLEGRO_KEY_W : // TECLA W
                            printf("pulo\n");
                            teclaPulo = 1;
                            break;
                        case ALLEGRO_KEY_S : // TECLA S
                            printf("defende\n");
                            tecla = 2;
                            break;
                        case ALLEGRO_KEY_A : // TECLA A
                            printf("esquerda\n");
                            posxPerso -= 10;
                            tecla = 3;
                            break;
                        case ALLEGRO_KEY_D : // TECLA D
                            printf("direita\n");
                            posxPerso += 10;
                            tecla = 4;
                            break;
                        case ALLEGRO_KEY_SPACE : // TECLA ESPAÇO
                            printf("bate\n");
                            tecla = 5;
                            break;
                        case ALLEGRO_KEY_N: // TECLA N
                            printf("dash\n");
                            tecla = 6;
                            break;
                        case ALLEGRO_KEY_ESCAPE: // TECLA ESC
                            printf("esc\n");
                            sair = 1;
                            break;
                    }
                }else if(evento.type = ALLEGRO_EVENT_KEY_UP){

                }
            }

        if(1){
            if((posyPerso>=365 && (posxPerso<20 || posxPerso>=830)) || (posxPerso>=830) || (posyPerso>365 && posxPerso<420)|| (posyPerso>300 && posxPerso>=420)){ // CAI
                posyPerso = cair (tecla, inverte, regiaoxPerso, regiaoyPerso, larguraPerso, alturaPerso, posxPerso, posyPerso, lado);
            }
            if(posxPerso>385 && posxPerso<410 && posyPerso == 365){ // PORTAL DEBAIXO
                posxPerso = 465;
                posyPerso = 265;
            }
            if(posxPerso>440 && posxPerso<460 && posyPerso == 265){ // PORTAL DE CIMA
                posxPerso = 380;
                posyPerso = 365;
            }
            
            printf("%d %d\n", posxPerso, posyPerso);
            if(noAr == 1 && cont==3){ //CAI DO PULO
                posyPerso = pulaDesce(tecla, inverte, regiaoxPerso, regiaoyPerso, larguraPerso, alturaPerso, posxPerso, posyPerso);
                teclaPulo = 0;
                noAr = 0;
                cont = 0;
                printf("desceu\n");
            }else if(teclaPulo == 1 && noAr == 0){ // PULA 
                posyPerso = pulaSobe(tecla, inverte, regiaoxPerso, regiaoyPerso, larguraPerso, alturaPerso, posxPerso, posyPerso);
                teclaPulo = 1;
                cont ++;
                printf("cont %d\n", cont);
                if(cont<3){
                    noAr = 0;
                }else{
                    noAr = 1;
                }
            }else if(tecla == 2){ // DEFENDE
                al_draw_bitmap_region(mapa, 0, 0, al_get_bitmap_width(mapa), al_get_bitmap_height(mapa), 0, 0, 0);
                al_draw_bitmap(plata, 455, 300, 0);
                al_draw_bitmap(plata, 50, 400, 0);
                if(inverte==0){
                regiaoxPerso = 1*larguraPerso;
                regiaoyPerso = 0*alturaPerso;
                al_draw_bitmap_region(spritePortal, regiaoxPortal2, regiaoyPortal2, larguraPortal,alturaPortal, posxPortal2,posyPortal2,0);
                al_draw_bitmap_region(spritePortal, regiaoxPortal1, regiaoyPortal1, larguraPortal,alturaPortal, posxPortal1,posyPortal1,0);
                al_draw_bitmap_region(spritePersonagem,regiaoxPerso,regiaoyPerso, larguraPerso,alturaPerso, posxPerso,posyPerso,0);
                }else{
                regiaoxPerso = 1*larguraPerso;
                regiaoyPerso = 0*alturaPerso;
                al_draw_bitmap_region(spritePortal, regiaoxPortal2, regiaoyPortal2, larguraPortal,alturaPortal, posxPortal2,posyPortal2,0);
                al_draw_bitmap_region(spritePortal, regiaoxPortal1, regiaoyPortal1, larguraPortal,alturaPortal, posxPortal1,posyPortal1,0);
                al_draw_bitmap_region(spritePersonagem, regiaoxPerso, regiaoyPerso, larguraPerso,alturaPerso, posxPerso,posyPerso,ALLEGRO_FLIP_HORIZONTAL);
                }
                al_flip_display();
                al_rest(0.1);
                tecla = 0;
            }else if(tecla == 3){ // ESQUERDA
                regiaoxPerso = 1*larguraPerso;
                regiaoyPerso = 1*alturaPerso;
                al_draw_bitmap_region(mapa, 0, 0, al_get_bitmap_width(mapa), al_get_bitmap_height(mapa), 0, 0, 0);
                al_draw_bitmap(plata, 455, 300, 0);
                al_draw_bitmap(plata, 50, 400, 0);
                al_draw_bitmap_region(spritePortal, regiaoxPortal2, regiaoyPortal2, larguraPortal,alturaPortal, posxPortal2,posyPortal2,0);
                al_draw_bitmap_region(spritePortal, regiaoxPortal1, regiaoyPortal1, larguraPortal,alturaPortal, posxPortal1,posyPortal1,0);
                al_draw_bitmap_region(spritePersonagem, regiaoxPerso, regiaoyPerso, larguraPerso,alturaPerso, posxPerso,posyPerso,ALLEGRO_FLIP_HORIZONTAL);
                al_flip_display();
                al_rest(0.05);
                tecla = 0;
                inverte = 1;
            }else if(tecla == 4){// DIREITA
                regiaoxPerso = 1*larguraPerso;
                regiaoyPerso = 1*alturaPerso;
                al_draw_bitmap_region(mapa, 0, 0, al_get_bitmap_width(mapa), al_get_bitmap_height(mapa), 0, 0, 0);
                al_draw_bitmap(plata, 455, 300, 0);
                al_draw_bitmap(plata, 50, 400, 0);
                al_draw_bitmap_region(spritePortal, regiaoxPortal2, regiaoyPortal2, larguraPortal,alturaPortal, posxPortal2,posyPortal2,0);
                al_draw_bitmap_region(spritePortal, regiaoxPortal1, regiaoyPortal1, larguraPortal,alturaPortal, posxPortal1,posyPortal1,0);
                al_draw_bitmap_region(spritePersonagem, regiaoxPerso, regiaoyPerso, larguraPerso,alturaPerso, posxPerso,posyPerso,0);
                al_flip_display();
                al_rest(0.05);
                tecla = 0;
                inverte = 0;
            }else if(tecla == 5){ // BATE
                regiaoxPerso = 2*larguraPerso;
                regiaoyPerso = 1*alturaPerso;
                al_draw_bitmap_region(mapa, 0, 0, al_get_bitmap_width(mapa), al_get_bitmap_height(mapa), 0, 0, 0);
                al_draw_bitmap(plata, 455, 300, 0);
                al_draw_bitmap(plata, 50, 400, 0);
                if(inverte==0){
                regiaoxPerso = 2*larguraPerso;
                regiaoyPerso = 1*alturaPerso;
                al_draw_bitmap_region(spritePortal, regiaoxPortal2, regiaoyPortal2, larguraPortal,alturaPortal, posxPortal2,posyPortal2,0);
                al_draw_bitmap_region(spritePortal, regiaoxPortal1, regiaoyPortal1, larguraPortal,alturaPortal, posxPortal1,posyPortal1,0);
                al_draw_bitmap_region(spritePersonagem, regiaoxPerso,regiaoyPerso, larguraPerso,alturaPerso, posxPerso,posyPerso,0);
                }else{
                regiaoxPerso = 2*larguraPerso;
                regiaoyPerso = 1*alturaPerso;
                al_draw_bitmap_region(spritePortal, regiaoxPortal2, regiaoyPortal2, larguraPortal,alturaPortal, posxPortal2,posyPortal2,0);
                al_draw_bitmap_region(spritePortal, regiaoxPortal1, regiaoyPortal1, larguraPortal,alturaPortal, posxPortal1,posyPortal1,0);
                al_draw_bitmap_region(spritePersonagem, regiaoxPerso, regiaoyPerso, larguraPerso,alturaPerso, posxPerso,posyPerso,ALLEGRO_FLIP_HORIZONTAL);
                }
                al_flip_display();
                al_rest(0.05);
                tecla = 0;
            }else if(tecla == 6){ // DASH
                posxPerso = dash(tecla, inverte, regiaoxPerso, regiaoyPerso, larguraPerso, alturaPerso, posxPerso, posyPerso,lado);
                tecla = 0;
            }else if(noAr==0) { // FICA PARADO
                al_draw_bitmap_region(mapa, 0, 0, al_get_bitmap_width(mapa), al_get_bitmap_height(mapa), 0, 0, 0);
                al_draw_bitmap(plata, 455, 300, 0);
                al_draw_bitmap(plata, 50, 400, 0);
                if(inverte==0){
                regiaoxPerso = 0*larguraPerso;
                regiaoyPerso = 0*alturaPerso;
                al_draw_bitmap_region(spritePortal, regiaoxPortal2, regiaoyPortal2, larguraPortal,alturaPortal, posxPortal2,posyPortal2,0);
                al_draw_bitmap_region(spritePortal, regiaoxPortal1, regiaoyPortal1, larguraPortal,alturaPortal, posxPortal1,posyPortal1,0);
                al_draw_bitmap_region(spritePersonagem, regiaoxPerso,regiaoyPerso, larguraPerso, alturaPerso, posxPerso,posyPerso,0);
                }else{
                regiaoxPerso = 0*larguraPerso;
                regiaoyPerso = 1*alturaPerso;
                al_draw_bitmap_region(spritePortal, regiaoxPortal2, regiaoyPortal2, larguraPortal,alturaPortal, posxPortal2,posyPortal2,0);
                al_draw_bitmap_region(spritePortal, regiaoxPortal1, regiaoyPortal1, larguraPortal,alturaPortal, posxPortal1,posyPortal1,0);
                al_draw_bitmap_region(spritePersonagem, regiaoxPerso, regiaoyPerso, larguraPerso, alturaPerso, posxPerso,posyPerso,0);
                }
                al_flip_display();
                tecla = 0;
            }
        }
    }
    al_destroy_bitmap(mapa);
    al_destroy_bitmap(plata);
    al_destroy_font(fonte);
    al_destroy_bitmap(spritePersonagem);
    al_destroy_timer(timer);
    al_destroy_display(janela);
    al_destroy_event_queue(filaEventos);
    return 0;

}