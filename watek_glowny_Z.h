#include "main.h"

void mainLoop_Z()
{
    packet_t pakiet;

    while (TRUE) {
        if(stan == REST_Z){
            ;
        }
        else if(stan == WAIT_Z){

            debug("Jestem w WAIT_Z, Sprawdzam energie %d", checkEnergy());

            if(checkEnergy() != 0 && isFilled == TRUE){ //energia nie pelna
                
                
                
                
                debug("energia pusta, wchodze do sekcji");


                changeState(INSECTION_Z);
            }
        

            

        } else if (stan == INSECTION_Z){
            debug("Poziom energi przed uzupełnieniem %d",pakiet.E);
           
            changeE(&pakiet);
            
            
            


            changeState(REST_Z);

        }

    }
    
}