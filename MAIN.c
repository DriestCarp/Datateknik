#include <stdio.h>
#include "brick.h"
#include <unistd.h>
#include "ev3.h"

#define Sleep( msec ) usleep(( msec ) * 1000 ) /* Definerar sleep, Sleep(1000)= 1 sekund */

#define MOTOR_RIGHT    	OUTA
#define MOTOR_LEFT    	OUTB
#define MOTOR_C    		OUTC
#define MOTOR_D    		OUTD
#define SENSOR_TOUCH	IN1
#define SENSOR_2		IN2
#define SENSOR_3		IN3
#define SENSOR_US		IN4



#define MOTOR_BOTH     	( MOTOR_LEFT | MOTOR_RIGHT ) /* Bitvis ELLER ger att båda motorerna styrs samtidigt */

int max_hastighet;         /* variabel för max hastighet på motorn */
POOL_T touchSensor, sonic_sensor;




void drive_250()
{
	tacho_set_speed_sp(MOTOR_BOTH, max_hastighet * 0.5);
	tacho_run_forever(MOTOR_BOTH);
	Sleep(4000);
	tacho_stop(MOTOR_BOTH);
}

void drive_250_back()
{
	tacho_set_speed_sp(MOTOR_BOTH, max_hastighet * -0.5);
	tacho_run_forever(MOTOR_BOTH);
	Sleep(4000);
	tacho_stop(MOTOR_BOTH);
}

void turn_left()
{
	tacho_set_speed_sp(MOTOR_RIGHT, max_hastighet * -0.2);
	tacho_run_forever(MOTOR_RIGHT);
	Sleep(1700);
	tacho_stop(MOTOR_RIGHT);
}

void turn_back_left()
{
	tacho_set_speed_sp(MOTOR_LEFT, max_hastighet * 0.2);
	tacho_run_forever(MOTOR_LEFT);
	Sleep(1700);
	tacho_stop(MOTOR_LEFT);
}

void turn_right()
{
	tacho_set_speed_sp(MOTOR_LEFT, max_hastighet * -0.2);
	tacho_run_forever(MOTOR_LEFT);
	Sleep(1700);
	tacho_stop(MOTOR_LEFT);
}

void turn_back_rigth()
{
	tacho_set_speed_sp(MOTOR_RIGHT, max_hastighet * 0.2);
	tacho_run_forever(MOTOR_RIGHT);
	Sleep(1700);
	tacho_stop(MOTOR_RIGHT);
}

void spin()
{
	tacho_set_speed_sp(MOTOR_LEFT, max_hastighet * 1);
	tacho_set_speed_sp(MOTOR_RIGHT, max_hastighet * -1);
	tacho_run_forever(MOTOR_RIGHT);
	tacho_run_forever(MOTOR_LEFT);
	Sleep(5000);
	tacho_stop(MOTOR_BOTH);
}

int main( void )
{  
	
	if ( !brick_init()) return ( 1 ); /* Initialiserar EV3-klossen */
	printf( "*** ( EV3 ) Hello! ***\n" );
	Sleep( 2000 );
	
	if ( tacho_is_plugged( MOTOR_BOTH, TACHO_TYPE__NONE_ )) {  /* TACHO_TYPE__NONE_ = Alla typer av motorer */
        max_hastighet = tacho_get_max_speed( MOTOR_LEFT, 0 );	/* Kollar maxhastigheten som motorn kan ha */
        tacho_reset( MOTOR_BOTH );
    } else {
        printf( "Anslut vänster motor i port A,\n"
        "Anslut höger motor i port B.\n");
      	brick_uninit();
        return ( 0 );  /* Stänger av sig om motorer ej är inkopplade */
    }
	
	touchSensor = sensor_search( LEGO_EV3_TOUCH ); // Registrerar en touch sensor på touchSensor-variabeln
	touch_set_mode_touch(touchSensor); // anger vilken "mode" sensorn skall ha

	tacho_set_speed_sp( MOTOR_BOTH, max_hastighet * 0.5 );  // Sätter hastigheten på båda motorerna till 50% av maxhastigheten
	/* Om man vill köra bakåt anger man negativ hastighet, till exempel max_hastighet * (-0.5) */
	

	
	
	
	
	


	/* ska vara i koden */
	sonic_sensor = sensor_search(LEGO_EV3_US);
	us_set_mode_us_dist_cm(sonic_sensor);
	int us_distance; /* kan heta vad som helst */
	us_distance = (sensor_get_value(0, sonic_sensor, 0)) / 10; /* kanske i en loop så det hela tiden uppdateras */
	

	while (1)
	{
		while ((sensor_get_value(0, sonic_sensor, 0)) / 10 >= 25 )
		{
			tacho_run_forever(MOTOR_BOTH);
		}
		tacho_stop(MOTOR_BOTH);
	}
	
	

	brick_uninit();
	printf( "dying...\n" );
	Sleep(1500);
    return ( 0 );


}