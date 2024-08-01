/*
������������������������������������������������������������������������������������������������������������������������������������������������
************************            PING 63: DEVELOPPEMENT D'UNE LIBRAIRIE GENERIQUE POUR UN WIFIBOT                   *************************
������������������������������������������������������������������������������������������������������������������������������������������������
Application � la Navigation Autonome: d�veloppement d'une approche logique de navigation utilisant les deux capteurs infrarouges du robot
================================================================================================================================================
Librairie mise � jour par: ClAMENS Thibault, GATCHUENG Darline, LARROUSSE Hugo, NYA Laeticia, WANG Junyuan, ZHENG Huazhao
================================================================================================================================================
*/


#include <stdio.h>
#include <stdlib.h>

#include "WifibotClient.h"

#define PORT	15000

extern int odo;

int SharpLUT[] = { 150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,150,103,102,101,100,99,
96,95,90,88,87,86,85,84,83,82,81,80,79,77,75,74,73,72,71,70,69,68,67,66,65,65,64,64,63,62,61,61,60,60,59,59,58,58,57,57,56,56,56,55,55,55,54,54,54,53,
53,53,52,52,51,51,50,50,49,49,49,48,48,47,47,46,46,46,45,45,44,44,43,43,42,42,41,41,41,40,40,40,39,39,39,39,39,38,38,
38,38,37,37,37,37,36,36,36,36,35,35,35,35,34,34,34,34,34,34,33,33,33,33,32,32,32,32,32,31,31,31,31,30,30,30,30,30,30,30,
30,29,29,29,29,29,29,29,28,28,28,28,28,28,27,27,27,27,27,27,27,26,26,26,26,25,25,25,25,25,25,24,24,24,24,24,23,23,23,
23,23,23,22,22,22,22,22,21,21,21,21,21,21,20,20,20,20,19,19,19,19,19,19,18,18,18,18,18,18,17,17,17,16,16,15,15 };

int main(void)
{
	WifibotClient robot;

	int Left_Speed = 0, Right_Speed = 0;
	char ip_adr[] = "10.3.141.1";		//Adresse IP de votre Wifibot.

	printf(" ***************************************************************************************************** \n");
	/* Connection to the robot */
	printf("Trying to connect to %s...   ", ip_adr);
	bool rep = robot.ConnectToRobot(ip_adr, PORT);
	if (rep)
	{
		printf("Connection failed...\n");
		getchar();
		return 0;
	}
	else
	{
		printf("Connection established...\n");
	}

	/* Entrer la vitesse � Gauche et � Droite */
	printf("Enter la vitesse au moins 60: \n");
	while( Left_Speed < 60 || Right_Speed < 60)
	{
		printf("Enter the left_speed: ");
		scanf("%d", &Left_Speed);
		printf("\n Enter the right_speed: ");
		scanf("%d", &Right_Speed);
	}
	printf("\n ***************************************************************************************************** \n");

	/*----------------------------Main program-------------------------------*/
	while (1)
	{
		robot.ApprocheLogiqueNavigation(Left_Speed, Right_Speed);
	}


}






