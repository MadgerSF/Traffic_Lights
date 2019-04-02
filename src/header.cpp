#include "header.hpp"

int time1;
DigitalOut light[] = {(PD_14), (PD_12), (PD_13)};
InterruptIn bt_lights (PA_0);

void clear(){
    int k;
    for(k=0; k<=2; k++){
        light[k]=0;
    }
}

void transition(){
    clear();
    if(position <= 2){
        position++;
    }
    else {
        position = 0;
    }
    light[position] = 1;
    timeout.attach(&transition, time_positions[position]);
}

void alert(){
    clear();
    if(light[yellow]==0){
        light[yellow] = 1;
    }
    else {
        light[yellow] = 0;
    }
    position = 2;
}

void begin_timer(){
    timer.start();
}

void end_timer(){
    timer.stop();
    time1 = timer.read();
    
    if(time1<2){
        if(position == green){
            clear();
            transition();
            timeout.attach(&transition, time_positions[position]);
        }
    }
    else if(time1 >= 2 && time1 <=10){
        if(alert_on == 0){
            clear();
            ticker.attach(&alert, 0.5);
        }
        else {
            transition();
            timeout.attach(&transition, time_positions[position]);
        }
    }
    else if(time1 > 10){
        if(all_clear == 0){
            clear();
        }
        else {
            transition();
            timeout.attach(&transition, time_positions[position]);
        }
    }
    timer.reset();
}