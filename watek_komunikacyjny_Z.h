#include "main.h"

void* startKomWatek_Z(void* ptr){
    MPI_Status status;
    packet_t recv;
    packet_t send;

    while(TRUE){
        recvPacket(recv, status);

        switch(status.MPI_TAG){
            case UZUPELNIONO:
                isFilled = TRUE;
            //prawdobodnie zmiana stanu
            break;

            case ZWIEKSZAM:
                pthread_mutex_lock(&energyMut);
                recv.E += 1;
                pthread_mutex_unlock(&energyMut);
            break;

            case ZMNIEJSZAM:
                pthread_mutex_lock(&energyMut);
                recv.E -= 1;
                pthread_mutex_unlock(&energyMut);
            break;
        }

    }
}
