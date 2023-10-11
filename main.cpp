#include "mbed.h"


PwmOut servo1(PA_7);//migi oku
PwmOut servo2(PB_1); //hidari_serovo temae

UnbufferedSerial pc(USBTX,USBRX);

void PCread();
char data;

// main() runs in its own thread in the OS
int main()
{
    servo1.pulsewidth_us(2500);
    servo2.pulsewidth_us(500);
    pc.attach(PCread, UnbufferedSerial::RxIrq);
    while (true) {
        if(data == 'w'){ //agaru
            
            servo1.pulsewidth_us(1100);
            servo2.pulsewidth_us(1900);

        }else if(data == 's'){ //sagaru
            servo1.pulsewidth_us(2500);
            servo2.pulsewidth_us(500); //period

        }
        printf("%c\n",data);
        ThisThread::sleep_for(100ms);
    }
}

void PCread(){
    pc.read(&data, 1);
}