#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
//jadid

void RANDOM_POSITION() ;
int  ceil_taghsim_2(int a){
if(a%2 ==0){
a=a/2 ;
return a ;
}
else{
    a=a+1 ;
    a=a/2 ;
    return a ;
}


}
int abs(int a){
    if(a<0){
        return -a;
    }
    return a; 
}
char order[1];
int final_level=1;
int is_sound_on=0;




int position_ARR[10000]={0};//{Px , Py , Zx1 , Zy1 ,Zx2,....,Z{levelfinal}x,Z{levelfinal}y, Dx , Dy , Vx1 , Vy2 ,Vx3,....,V{levelfinal}x  , V{levelfinal}y  ,}   P Z D V A
int kill=0;
int tir=3;
int kheshab=0;
int health=3 ;
int vaccine=0;
int credit=0;
int dorebize=1;
int ROund=0;

int range_shoutgun=5;
int range_health=3;
int hajme_kheshab=3;



void red () {
  printf("\033[1;31m");
}
void yellow() {
  printf("\033[1;33m");
}
void cyan(){
    printf("\033[1;36m") ;
}
void green(){
    printf("\033[1;32m") ;
}
void magenta(){
    printf("\033[1;35m") ;
}
void blue() {
    printf("\033[0;34m") ;
}
void blue_bold(){
  printf("\033[1;31m");

}
void green_bold(){
  printf("\033[1;31m");

}
void red_bold(){
  printf("\033[1;31m");

}
void magenta_bold(){
  printf("\033[1;31m");

}
void yellow_bold(){
  printf("\033[1;31m");

}
void reset () {
  printf("\033[0m");
}


void Upgrade_print_list(){
    magenta() ;
            printf("0 - Return to game.\n\nCREDIT=%d\n\n",credit);
            cyan() ;
            printf("1 - Upgrade capacity of magazine : + 1 (maximum is 12 bullets, now is %d)\n",hajme_kheshab) ;
        green() ;
        printf("1 - Credit required: %d\n\n",hajme_kheshab * final_level) ;
        cyan() ;
        printf("2 - Upgrade range of shotgun : + 1 times the size of the person himself (maximum is 10 times, now is %d)\n",range_shoutgun) ;
        green() ;
        printf("Credit required: %d\n\n",final_level + range_shoutgun) ;
        cyan() ;
        printf("3 - get an additional health : + 1 (maximum is 8 healths, now is %d)\n",range_health) ;
        green();
        printf("Credit required: %d\n\n",(final_level + 1) * range_health) ;
        reset() ;
        return ;
}
int  Fun_D_ststus_print(){
    if(position_ARR[0]==position_ARR[2  +  2*final_level] && position_ARR[1]==position_ARR[1+ 2  +  2*final_level]){
     if(final_level!=vaccine){
        printf("First get all the vaccines.\n");
        return 0 ;
     }
     else{

         printf("You Won! You have reached level %d\n",final_level) ;
         return 1;
     }

}
else{
    return 0 ;
}

}





void Settings_print_list(){
    cyan();
    printf("0 - Return to game\n") ;
    reset();
    printf("1 - New Game\n");
    green();
    printf("2 - Settings\n");
    red();
    printf("3 - Exit\n") ;
    reset() ;
}
void Settings_Setting_list(){
                        printf("Final level is: %d\n",final_level) ;
                    if(is_sound_on==0){    printf("Sound is OFF!\nDo you want to unmute the sound?(y-->YES | n-->NO)\n") ;}
                    if(is_sound_on==1){    printf("Sound is ON!\nDo you want to mute the sound?(y-->YES | n-->NO)\n") ;}
                    printf("return(z)\n\n") ;
                    return ;
}

void HEALTH_STATUS_print(int numberof_health){
    printf("Health: [ ") ;
    for(int i=0; i<numberof_health ;i++){
        printf("| ") ;
    }
    printf("]\t") ;
}
void AMMO_STATUS_print(int tiiiiir,int kheeeeshab){
    printf("Ammo: %d/%d\t",tir,kheshab) ;
}
void kill_mesage_PRINT(){ 
            switch (kill%14)
        {
        case  0 :
        printf("First Blood\n") ;
           
            break;
        
        case  1 :
        printf("Double Kill\n") ;

           
            break;
        case  2 :

        if(dorebize==0){printf("Triple Kill\n") ;}
        else{printf("Hattrik\n") ;}

           
            break;
        case  3 :
        printf("team Killer\n") ;
           
            break;
        case  4 :
        printf("Headshot\n") ;
           
            break;
        case  5 :
        printf("Rampage\n");
           
            break;
        case  6 :
        printf("Killing Spree\n") ;
           
            break;
        case  7 :
        printf("Unstoppable\n") ;
           
            break;
        case  8 :
        printf("Monster Kill\n") ;

           
            break;
        case  9 :
        printf("Multi Kill\n") ;
           
            break;
        case 10 :
        printf("Ludicrouskill\n") ;
           
            break;
        case 11 :
        printf("Ultra\n") ;
           
            break;
        
        case 12 :
        printf("Dominating\n") ;

           
            break;
        case 13 :
        printf("Godlike\n") ;

            break;
           
          
                                                                                        
        default:
            break;
        }
        return ;
}



void MENU_ASLI(){
    printf("1 - New Game\t2 - Settings\t3 - Credits\t4 - Help\t5 - Exit\n") ;
    scanf("%s",&order[0]) ;
switch (order[0])
{
    case 49 ://NEW GAME
    break;





    case 50 ://SETTING
    printf("Final level is: %d\n",final_level) ;
    if(is_sound_on==0){
printf("Sound is OFF!\nDo you want to unmute the sound?(y-->YES | n-->NO)\n") ;
    scanf("%s",&order[0]) ;
if(order[0]=='n'){
return MENU_ASLI() ;
}
else if(order[0]=='y'){
    is_sound_on=1;
    printf("SOUND IS ON NOW\n") ;
    return MENU_ASLI() ;

}
else{
    return MENU_ASLI() ;
}

}
else if(is_sound_on==1){
    printf("Sound is ON!\nDo you want to mute the sound?(y-->YES | n-->NO)\n") ;
    scanf("%s",&order[0]) ;
if(order[0]=='n'){
return MENU_ASLI() ;
}
else if(order[0]=='y'){
    is_sound_on=0;
    printf("SOUND IS OFF NOW\n") ;

    return MENU_ASLI() ;
}
else{
    return MENU_ASLI() ;
}
}

break;





case 53 ://EXIT
printf("Are you sure you want to exit the game?(y-->YES | n-->NO)\n");
scanf("%s",&order[0]) ;
if(order[0]=='y'){
    printf("Bye!") ;
    order[0]='@' ;
    return ;
}
if(order[0]=='n'){
    return MENU_ASLI() ;
}

    break;




    case 51 ://CREDIT
    yellow() ;
    printf("MATIN HASANALI BAKI ON THE FIRE\nI hope you enjoy playnig \"COVID 2030\" game :) \nAnd we are waiting for share your comments...\n" ) ;
    reset() ;
    sleep(1.5) ;
    return MENU_ASLI() ;
    break ;

case 52 ://HELP
blue() ;
printf("HELP MIKONAM\n") ;
reset() ;
return MENU_ASLI() ;
break ;

default://kerm rizi
return MENU_ASLI() ;
 break;
}
return ;
}


void New_Game(int *a){//a = chance_UNKNOWN
    /*shayad bayad badan update shavad tabe cho motaghaere jadid shayad amad vasat*/
    *a=4 ;
  is_sound_on=0;




   //{Px , Py , Zx1 , Zy1 ,Zx2,....,Z{levelfinal}x,Z{levelfinal}y, Dx , Dy , Vx1 , Vy2 ,Vx3,....,V{levelfinal}x  , V{levelfinal}y  ,}   P Z D V A
  kill=0;
  tir=3;
  kheshab=0;
  health=3 ;
  vaccine=0;
  credit=0;
  dorebize=1;
  ROund=0;

  range_shoutgun=5;
  range_health=3;
  hajme_kheshab=3;
   RANDOM_POSITION() ;



}
void NEXT_Level_fun(int *a){
      final_level++;
    if(health<range_health){
        health++;
    }
    if(tir<hajme_kheshab){
        tir++ ;
    }
    if(dorebize%4 + 1 ==5){
        *a=4 ;
    }
    vaccine=0;
      RANDOM_POSITION() ;
      
      return ;

}
int Tir_bali_t_X(){
    int x=-1;
    int X=-1 ;
    //y=x+1
    for(int g=2 ; g  <=   2  +  2*(final_level - 1) ; g=g+2 ){
      if(   position_ARR[0]>position_ARR[g]        && position_ARR[1]==position_ARR[g+1]){
        if(range_shoutgun>= abs(position_ARR[0]-position_ARR[g])){   
            if(x<position_ARR[g]){
                x=position_ARR[g] ;
                X=g ;
            }
        
        }


    }}
    //return x dorost
    return X;

}
int Tir_paiin_g_x(){
    int x=20;//x>radiff ha
    int X=-1 ;
    //y=x+1 ;
    for(int g=2 ; g  <=   2  +  2*(final_level - 1) ; g=g+2 ){
        if(   position_ARR[0]<position_ARR[g]        && position_ARR[1]==position_ARR[g+1]){
                 if( range_shoutgun>= abs(position_ARR[0]-position_ARR[g])  ){
                        if(x>position_ARR[g]){
                            x=position_ARR[g] ;
                            X=g;
                        }

                  }

    }}
    return X;
}
int Tir_left_h_Y(){
    int y=-1 ;
    int Y=-1 ;
    //x=y-1 ;
   for(int g=2 ; g  <=   2  +  2*(final_level - 1) ; g=g+2 ){
     if(position_ARR[0]==position_ARR[g]  && position_ARR[1] > position_ARR[g+1]){
                 if(range_shoutgun>= abs(position_ARR[1]-position_ARR[g+1])) {
                            if(position_ARR[g+1]>y){
                                y=position_ARR[g+1] ;
                                Y=g+1 ;
                            }
                        }


    }}
    return Y;
}
int Tir_right_f_y(){
    int y=20 ;
    int Y=-1;
      for(int g=2 ; g  <=   2  +  2*(final_level - 1) ; g=g+2 ){
          if(position_ARR[0]==position_ARR[g]  && position_ARR[1] < position_ARR[g+1]){
                          if( range_shoutgun>= abs(position_ARR[1]-position_ARR[g+1]) ){
                                if(y>position_ARR[g+1]){
                                    y=position_ARR[g+1] ;
                                    Y=g+1 ;
                                }
                                }



    }}
    return Y ;
}


//سوالات از خود پی دی اف:
/*
بعد ریلود باید ص چاپ شود....و زامبی باید حرکت کند؟ یارو چی؟
   /////////////  با فرض ر یلود در جریان حرکتی مهره ها تاثیر ندارد     به   جز   زامبی ها


ریلود کردن به شکلیه    2/5   ریبود 3/4   یا  چی       3/5 ریلوذ باید بشه 3/4؟؟؟؟




*/
//17عمدی
//15 برای مهره ها !!!!!!!!
//15افقی
// مشکل چند تا کارکتر گرفتن داریم
//مشکل space,enter کاراکترو داریم
//که فوق رابا استرینگ گرفتن اووردر میتوان فعلا اوکی کرد
//اگر وردوی پرت پرت باشد در ستنیگ فکرکنم به صحفه اصلی بر نمیگردد
//اندر لاین یا بولد کردن جای های مهم در پرینت شدن (مثلا فعل اکزیت بولد یا اندر لاینی شود تا یارو دقت کند)
//یا سری جاهاشو پرینت رنگی کنم....
//رنگ با بولدی و رنگ بی بولدی جدا شود
//باگ تعداد داکسن و زامبی ها طبق دستور العمل نیست!!!!!!!!!
//مهره ها رو گاهی هم چاپ نمیشود
//قابلیت حروف کپیتال رو کوچک تبدیل کند
//وقتی زامبی نزدیک میشه به اندازه ی خونه بعد یهو محو میشه
//در اکزیت درون بازی اگر کنیم چه چیز هایی تغییر میکند و چه چیز هایی تغییر نمی کند اگر دوباره نیو گیم را بزنیم     یا اگر ستینگ را بزنیم؟؟؟؟
int Zombie_Yab_for_random_position(int i , int j ){
    int flag=0;
    for(int g=2 ; g  <=   2  +  2*(final_level - 1) ; g=g+2 ){
        if(position_ARR[g]==i  && position_ARR[g+1]==j){
            flag=1;
            break;
        }
    }
    return flag ;
}
int Vaccine_Yab_for_random_positin(int i , int j){
    int flag=0 ;
    for(int g=2+2+2*final_level ; g<=2+2+2*final_level + 2*(final_level - 1) ; g=g+2){
            if(position_ARR[g]==i  && position_ARR[g+1]==j){
            flag=1;
            break;
        }
    }
    return flag ;
}
int Ammao_Yab_for_random_position(int i  ,int j){
        int END=4 + 2*final_level + 2*final_level  + 2 * ceil_taghsim_2(final_level) ; 
    int flag=0;
    for(int g=2+2+2+2*final_level + 2*(final_level - 1)   ;    g<=END-2 ; g=g+2){
        if(position_ARR[g]==i  && position_ARR[g+1]==j ){
            flag=1;
            break;
        }
    }

    return flag ;
}
void Tir_SHOUT(){
    int x;
    int y;
    if(order[0]=='t'){
        x=Tir_bali_t_X();
        if(x!=-1){
         position_ARR[x]=-1 ; 
        position_ARR[x+1]=-1 ; 
         credit=credit+final_level+1 ;
        kill_mesage_PRINT() ;
        printf("%d credit gained\n!",final_level+1) ;
        kill++; 
        return ;}
    }


     if(order[0]=='h' ){
        y=Tir_left_h_Y();
        if(y!=-1){
         position_ARR[y-1]=-1 ; 
        position_ARR[y]=-1 ; 
         credit=credit+final_level+1 ;
        kill_mesage_PRINT() ;
        printf("%d credit gained\n!",final_level+1) ;
        kill++; 
        return ;}
         }

     if(order[0]=='f'){
        y=Tir_right_f_y() ;
        if(y!=-1){
        position_ARR[y-1]=-1 ; 
        position_ARR[y]=-1 ; 
         credit=credit+final_level+1 ;
        kill_mesage_PRINT() ;
        printf("%d credit gained\n!",final_level+1) ;
        kill++; 
        return ;}

      }
    
     if(order[0]=='g'){
        x=Tir_paiin_g_x() ;
        if(x!=-1){
        position_ARR[x]=-1 ; 
        position_ARR[x+1]=-1 ; 
         credit=credit+final_level+1 ;
        kill_mesage_PRINT() ;
        printf("%d credit gained\n!",final_level+1) ;
        kill++; 
        return ;}

        }

    /*else{
        printf("Koja ro mizani bradar \\: !?\n") ;
    }*/
return ;
}

void ZAMIN_BAZI_print(){
    printf("Level: %d\t\tVaccine: %d\tCredit: %d\tRound: %d\n",final_level,vaccine,credit,ROund) ;
    HEALTH_STATUS_print(health) ;
    printf("max health: %d\t",range_health) ;
    AMMO_STATUS_print(tir,kheshab) ;
    printf("rage shoutgun: %d\tcapcity: %d\t",range_shoutgun,hajme_kheshab) ;
    printf("Kill: %d\n",kill) ;

    printf("-----------------\n") ;
    for(int i=1;i<=15;i++){
        printf("|") ;
        for(int j=2 ; j<=16 ; j++){
            if(i==position_ARR[0] && j==position_ARR[1]){
                green() ;
                printf("P") ;
                reset() ;
            }
            else if(Zombie_Yab_for_random_position(i,j)==1){
                red() ;
                printf("Z") ;
                reset() ;
            }            
            else if(i==position_ARR[2  +  2*final_level] && j==position_ARR[1+2+2*final_level]){
                magenta() ;
                printf("D") ;
                reset() ;
            }   
            else if(Vaccine_Yab_for_random_positin(i,j)==1){
                yellow() ;
                printf("V") ;
                reset() ;
            }    
            else if(Ammao_Yab_for_random_position(i,j)){
                blue() ;
                printf("A") ;
                reset() ;
            } 
            else{
                printf(" ") ;
            }                            
        }
      





        printf("|\n");
        
    }
    printf("-----------------") ;
    return ;}

void RANDOM_POSITION(){
    int tekrar ;
    int end=4 + 2*final_level + 2*final_level  + 2 * ceil_taghsim_2(final_level) ; 
    //end%2 ==0 
    srand(time(NULL)) ;
    for(int i=0 ;i<=end-2;i=i+2){//i=2k RADIFha     i=2k+1 SOTONha
        do{
             position_ARR[i] =rand()%15  +  1  ;
            position_ARR[i+1] =rand()%15   +  2  ;
             tekrar=0 ;
                  for(int g=i-2; g>=0 ;g=g-2){
                         if(position_ARR[i]==position_ARR[g]  && position_ARR[i+1]==position_ARR[g+1]){
                             tekrar=1;
                             break;
                    }
                }
        }
        while (tekrar==1) ;

    }
return;   
}

void FUNharahat_Zombie(){
    if(dorebize==0){
      for(int g =2 ; g<= 2  +  2*(final_level - 1)  ; g=g+2){
        if(position_ARR[g]>0){
            if(position_ARR[1]>position_ARR[g+1]){
             position_ARR[g+1]+=1;
               }
             else if(position_ARR[1]< position_ARR[g+1]){
                position_ARR[g+1]-=1;
             }
    else{//tasavi
            if(position_ARR[0]>position_ARR[g]){
              position_ARR[g]+=1;
                 }
                else if(position_ARR[0]<position_ARR[g]){
                 position_ARR[g]-=1;
            }
    }
      }
    }  
    }
}




void FUN_harekat_Player(){

        int END=4 + 2*final_level + 2*final_level  + 2 * ceil_taghsim_2(final_level) ; 
if(order[0]=='w'){
    if(position_ARR[0]>1){
        position_ARR[0]--;
    }
}

else if( order[0]=='d' ) {
    if(position_ARR[1]<16){
        position_ARR[1]++;
    }
}

else if(order[0]=='s' ) {
    if(position_ARR[0]<15){
        position_ARR[0]++;
    }
}

else if(order[0]=='a' ) {
    if(position_ARR[1]>2){
        position_ARR[1]--;
    }

}

if(  Vaccine_Yab_for_random_positin(position_ARR[0] ,position_ARR[1]) ==1 ){
    printf("Vaccine collected!\n%d credit gained!\n",final_level + 1) ;
    vaccine++;
    kheshab++;
 for(int g=2+2+2*final_level ; g<=2+2+2*final_level + 2*(final_level - 1) ; g=g+2) {

    if(position_ARR[0]==position_ARR[g] && position_ARR[1]==position_ARR[g+1]){
        position_ARR[g]=-1  ;
         position_ARR[g+1]=-1 ;
    }


 }
 
    credit=credit+final_level+1;
}
else if(  Ammao_Yab_for_random_position(position_ARR[0] ,position_ARR[1] ) == 1 ){
    printf("Ammo collected!\n%d credit gained!\n",final_level + 1) ;
    kheshab++;
 for(int g=2+2+2+2*final_level + 2*(final_level - 1)   ;    g<=END-2 ; g=g+2) {

    if(position_ARR[0]==position_ARR[g] && position_ARR[1]==position_ARR[g+1]){
        position_ARR[g]=-1  ;
         position_ARR[g+1]=-1 ;
    }


 }
    credit=credit+final_level+1;

}
    return ; 
}










int main(){
    int Victory=0;
    char Lose_and_again_ingame[1] ;
    char arr_sound_off_on_inGame[1] ;
    char arr_exit_ingame[1]="#" ;
    char arr_New_game[1] ;//in game???
    char arr_Menu[1] ;//ingame
    char arrexit[1]="!" ;
    char sajad[1] ;
    char arrhelpUNKOWN[1];
    char arrUPGRADE[1] ;
    int  chance_UNKOWN_error=4;
    red();
printf(" ######   #######  ##     ## #### ########      #######    #####     #######    #####\n");
printf("##    ## ##     ## ##     ##  ##  ##     ##    ##     ##  ##    ##  ##     ##  ##    ##\n");
printf("##       ##     ## ##     ##  ##  ##     ##           ## ##      ##        ## ##      ##\n");
printf("##       ##     ## ##     ##  ##  ##     ##     #######  ##      ##  #######  ##      ## \n");
printf("##       ##     ##  ##    ##  ##  ##     ##    ##        ##      ##        ## ##      ##    \n");
printf("##    ## ##     ##   ##  ##   ##  ##     ##    ##         ##    ##  ##     ##  ##    ##  \n");
printf(" ######   #######     ###    #### ########     ########    #####     #######    #####\n");
reset() ;
printf("Welcome to Covid 2030 game!\n") ;
MENU_ASLI();
RANDOM_POSITION();

while (order[0]!=64)
{
    printf("%d\n",dorebize) ;

    ZAMIN_BAZI_print() ;
    scanf("%s",&order[0]) ;
    if(order[0]=='e'){//exit the game
    arrexit[0]='!' ;

    while (arrexit[0]>'y'   ||  ( 'n' <arrexit[0]  &&  arrexit[0]<'y' )  ||   arrexit[0]<'n' )
    {
        printf("YOU ARE LEFTING THE MINE GAME MF?\nARE YOU SURE?(YES==y  | NO==n)\n(!)the game isnt save(!)\n") ;

        scanf("%c",&arrexit[0]) ;   
     
        if(arrexit[0]=='y'){
            printf(":( ") ;
            return 0;

        }
        else if(arrexit[0]=='n'){
            continue;
        }
    }
    }
    else if(order[0]=='m'){/*menu*/
            arr_exit_ingame[0]='#' ;
            Settings_print_list();
           do{
           scanf("%s",&arr_Menu[0]) ;
             if(arr_Menu[0]=='1'){/*NEW GAME*/
                    printf("Are you Sure?(YES==y | NO==n)\n") ;
                    do{
                           scanf("%s",&arr_New_game[0]) ;
                        if(arr_New_game[0]=='y'){
                        New_Game(&chance_UNKOWN_error) ;
                        final_level=1;
                        //********************//
                        break;
                         }
                         else if(arr_New_game[0]!='n'){
                            printf("Please just enter the charecter in the menu:\n") ;
                         }


                    }while(arr_New_game[0]!='n');
                    if(arr_New_game[0]=='y'){
                        break;
                    }
                            printf("\n") ;
                        Settings_print_list()  ;

                    /*NEW GAME*/
                }
       
       
        else if(arr_Menu[0]=='2'){/*SETTINGS*/
                Settings_Setting_list() ;
                /*SETTINGS*/
        do{
            scanf("%s",&arr_sound_off_on_inGame[0]) ;
                if(arr_sound_off_on_inGame[0]=='n'){
                     Settings_Setting_list() ; 

                 }
                 else if(arr_sound_off_on_inGame[0]=='y'){
                         is_sound_on=(is_sound_on+1)%2 ;
                         if(is_sound_on==0){
                                printf("SOUND IS ON OFF\n") ;

                          }
                         else if(is_sound_on==1){
                             printf("SOUND IS ON NOW\n") ;
                         }
                         Settings_Setting_list() ; 

                 }

                   else if(arr_sound_off_on_inGame[0]!='z'){
                            printf("Please just enter the numbers in the menu:\n") ;

                     }
                    printf("\n") ;
            }while(arr_sound_off_on_inGame[0]!='z') ; 
            Settings_print_list() ;


        }




           
        else if(arr_Menu[0]=='3'){//EXIT
                /*RESTART GAME FUN*/
                  printf("Are you Sure?(YES==y | NO==n)\n") ;
                    do{
                        scanf("%s",&arr_exit_ingame[0]) ;
                        if(arr_exit_ingame[0]=='y'){
                                New_Game(&chance_UNKOWN_error) ;
                                final_level=1 ;
                                Victory=0;
                                break;
                        }
                        else if(arr_exit_ingame[0]!='n'){
                            printf("Please just enter the numbers in the menu:\n") ;

                        }

                    }while(arr_exit_ingame[0]!='n');

                    if(arr_exit_ingame[0]=='y'){
                        break;
                    }
                    if(arr_exit_ingame[0]=='n'){printf("\n"); Settings_print_list() ;}
        }                
        else if(arr_Menu[0]!='0'){
               printf("Please just enter the numbers in the menu:\n") ;

        }
        }while (arr_Menu[0]!='0' );
        if(arr_exit_ingame[0]=='y'){
            MENU_ASLI() ;
        }
        continue;
    
    
    }
    else if(order[0]=='u'){/*Upgrade Menu*/
        
        Upgrade_print_list() ;

        do{
           scanf("%s",&arrUPGRADE[0]) ;
             if(arrUPGRADE[0]=='1'){
            if( (credit >= (hajme_kheshab * final_level) )  && hajme_kheshab<12 ){
                credit=credit-hajme_kheshab * final_level ;
                hajme_kheshab++;
                printf("Upgrade done successfully.\nYour magazine capacity is now %d.\n",hajme_kheshab) ;
                        Upgrade_print_list() ;

            }
            else{
            if(hajme_kheshab==12){
                printf("The selected item is maximum.") ;
            }
            if(credit<hajme_kheshab * final_level && hajme_kheshab<12 ){
                printf("Unfortunately, your credit is not enough to get this item. Please gain %d more credit by playing.(enter another options)\n",hajme_kheshab * final_level-credit) ;
            }}

        }
        else if(arrUPGRADE[0]=='2'){
                if(credit >=  final_level + range_shoutgun  && range_shoutgun<10){
                  credit=credit-range_shoutgun - final_level ;

                range_shoutgun ++ ;

                printf("Upgrade done successfully.\nYour shotgun range is now %d.\n",range_shoutgun) ;
                        Upgrade_print_list() ;

            }

            else{
             if(range_shoutgun==10){
                printf("The selected item is maximum.\n") ;
            }
                 if(credit<final_level + range_shoutgun){
                printf("Unfortunately, your credit is not enough to get this item. Please gain %d more credit by playing.(enter another options)\n",final_level + range_shoutgun -credit) ;
            } }


            
            
        }
        else if(arrUPGRADE[0]=='3'){
                if(credit >= (final_level + 1) * range_health   && range_health<8 ){
                credit=credit-( (final_level + 1) * range_health ) ;

                range_health++;
                printf("Additional health received successfully.\nYour health is now %d.\n",range_health) ;
                        Upgrade_print_list() ;

            }
            else{
            if(range_health==8){
                printf("The selected item is maximum.\n") ;
            }
            if(credit<(final_level + 1) * range_health){
                printf("Unfortunately, your credit is not enough to get this item. Please gain %d more credit by playing.(enter another options)\n",(final_level + 1) * range_health-credit) ;
            }      }      
        }                
        else if(arrUPGRADE[0]!='0'){
            printf("Please just enter the numbers in the menu:\n(if you want it again enter {a} | else enter anykey)") ;
           scanf("%s",&arrUPGRADE[0]) ;
           if( arrUPGRADE[0]=='a'){
                    Upgrade_print_list() ;
           }   
           else{
            arrUPGRADE[0]='1' ;
           }
        }
        }while (arrUPGRADE[0]!='0' );
        continue;
          
    }
    else if(order[0]=='r'){//RELOADING  
        FUNharahat_Zombie() ;

      //  با فرض ر یلود در جریان حرکتی مهره ها تاثیر ندارد     به   جز   زامبی ها
    //و ریلود
    int delta=hajme_kheshab-tir ;
    if(kheshab==0){
        printf("No Ammao!\n") ;
        FUNharahat_Zombie() ;
    }
    else if(tir==hajme_kheshab){
        printf("The gun is already Charged\n") ;

    }
    else if(kheshab-delta>=0){
        kheshab=kheshab-delta;
        tir=hajme_kheshab ;
        printf("Reloaded!\n") ;
       FUNharahat_Zombie() ;
        
    }
    else{
        tir=tir+kheshab ;
        kheshab=0;
        printf("Reloaded!\n") ;
        FUNharahat_Zombie() ;


    }
    }
   
    else if( order[0]=='t'  || order[0]=='f'  || order[0]=='g'  ||  order[0]=='h' ){//   tir : bala ||| rast |||  paiin  |||  chap
        if(tir>0){
                    //play sound tir
        Tir_SHOUT() ;
        //point++   aghar shod
        tir--;
        }
        else if(tir==0){
            printf("No charged ammo!\n");
        }
           FUNharahat_Zombie() ;

            }
    else if( order[0]=='w'  || order[0]=='d'  ||  order[0]=='s'  || order[0]=='a' ){ //harakat player 
        FUN_harekat_Player() ;
        Victory=Fun_D_ststus_print();
        if(Victory==0){
            int Flag=0;
            int manfi=0;
           FUNharahat_Zombie() ;
              for(int g=2 ; g  <=   2  +  2*(final_level - 1) ; g=g+2 ){
                if(position_ARR[0]==position_ARR[g] && position_ARR[1]==position_ARR[g+1]){
                    if(Flag!=0){  Flag=1;}
                    manfi++;
                }
              }
              if(manfi>0){
                         if(health-manfi>0){
                             printf("The zombie is eating you! You lost %d of your healths!{YOU HAVE JUST %d health}\n\n",manfi,health-manfi) ;
                             health=health-manfi ;
                              }
                              else if(health-manfi==0){
                                printf("You Died!\nYou Lose! Would you like to try again?(YES==y | NO==n)\n\n") ;
                                health=0;
                                
                                
                                do{
                                scanf("%s",&Lose_and_again_ingame[0]) ;
                                     if(Lose_and_again_ingame[0]=='y'){
                                        New_Game(&chance_UNKOWN_error) ;
                                        final_level=1 ;
                                         Victory=0;

                                         break;
                                         }
                                 else if(Lose_and_again_ingame[0]=='n'){
                                    MENU_ASLI() ;
                                    break;

                                 }
                                     printf("Please just enter the numbers in the menu:\n") ;
                                }while (Lose_and_again_ingame[0]!='n');
                                

                              }


                 }
        }
        else if(Victory==1){
            //Next level//
            NEXT_Level_fun(&chance_UNKOWN_error) ;
            dorebize=1 ;
            continue;
        
        }

    }





    else{

        if( chance_UNKOWN_error==0){
            red() ;
            printf("you are nt allow to insert unknown command!(if you are nt understand it insert {i} and read HELP)\nelse enter anykey to return to game...\n") ;
            reset() ;
            scanf("%s",&arrhelpUNKOWN[0]) ;
            if(arrhelpUNKOWN[0]=='i'){
                //HELP DOC
                blue() ;
                printf("HELP MIKONAM\n") ;
                reset() ;
                //ppress enter to resume the game 
                yellow();
                 printf("are you ready to play?\n") ; 
                 reset();
                scanf("%s",&sajad) ;
            }
            FUNharahat_Zombie() ;
        }
        else if(chance_UNKOWN_error>0){
            dorebize+=1;
            chance_UNKOWN_error--;
            red();
        printf("UNKOWN  COMMAND!\nif you are new in this game press i...else press anything!(WARNING: you just %d times allow to insert wrong command)\n",chance_UNKOWN_error) ;
        reset() ;
        scanf("%s",&arrhelpUNKOWN[0]) ;
            if(arrhelpUNKOWN[0]=='i'){
                //HELP DOC
                blue() ;
                printf("HELP MIKONAM\n") ;
                reset() ;
                //ppress enter to resume the game
                yellow() ;
                printf("are you ready to play?\n") ; 
                reset() ;
                scanf("%s",&sajad) ;
            }
        }
    }
     
     dorebize=(dorebize+ 1)%2 ;

}


printf("") ;














    return 0;

}