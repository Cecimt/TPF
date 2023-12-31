#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define BLANCO 1
#define NEGRO 0
#define PERSONA 1
#define PC 0

char tablero [16][16];
/*
 * funcion encargada de guardar en diferentes vectores los datos ingresados por el usuario para el desarrollo de la partida
 * -->llama a los vectores con punteros
 *    ingresa los datos del usuario en los vectores correspondientes
 *    recibe y valida los datos del usuario para cada dato.
 * -->cualquier nombre es valido
 * -->maneras de optimizar: lograr meter cada vector en un vector maestro
 *    para luego invocar los datos necesarios usando los indices del vector maestro.
 */
void cleanBuffer()
{
    char c;
    while ((c = getchar()) != '\n');
}

void tableroInicial(){
    srand(time(NULL));
    int i,j;
    for(i = 0;i<16;i++ ){
        for(j=0;j<16;j++){
            tablero[i][j] = '-';
            // está en el medio
            if((i==0 && j<5)|| (i==1 && j<5) || (i==2 && j<4) || (i==3 && j<3) || (i==4 && j<2) ){ //Posiciona las fichas Negras
        tablero[i][j] = 'N';
      }
      if((i==11 && j>13) || (i==12 && j>12) || (i==13 && j>11) || (i==14 && j>10) || (i==15 && j>10) ){ //Posiciona las fichas Blancas
        tablero[i][j] = 'B';
      }
    }
  }
}

void imprimirTablero(){
    //Imprime tablero
    int i,j;
    printf("Tablero:\n");
    printf("\t ");
    for(i=0;i<16;i++){
        printf("\t %d",i);
    }
    printf("\n");
    for(i=0;i<16;i++){
        printf("\t %d",i);
        for(j=0;j<16;j++){
            printf("\t %c", tablero[i][j]);
        }
        printf("\n");
    }
}
/*
 * esta funcion permite al usuario cargar la congifuracion de la partida (elige pieza y turno)
 * se utilizan bucles con while para que no puede ingresar valores que no sean los requeridos y devuelven los mismos mediante punteros
 */

typedef struct string{
	char* array;
	unsigned int charsTotales;
	unsigned int charsUsados;
}string;

int UserData(char *nombre, char *lado, char *turno) {
    printf("BIENVENIDO A HOPPITI!\nIngrese el nombre del jugador: ");
    scanf("%s",nombre);
    cleanBuffer();
    printf("ELIJA SU LADO: Jugador Blanco --> 1 | Jugador Negro --> 2\nsi desea aleatorizar la configuración de la partida--> 3\n");
    while (*lado != '1' && *lado != '2' && *lado !='3') {
        *lado = getchar();


        /*
         * permite al usuario elegir que se aleatorize la configuracion de la partida mediante un rand
         * si el usuario elige esta opcion al asignar los valores a los punteros se invoca un return para terminar la funcion
         */

        if (*lado=='3')
        {
          *lado=(rand()%2)+1;
          *turno=(rand()%2)+1;
          return 0;
        }
        if (*lado != '1' && *lado != '2') {
          cleanBuffer();
            printf("Valor invalido. Intenta nuevamente.\n");
        }
    }
    cleanBuffer();
    printf("QUIEN EMPIEZA EL JUEGO? Usuario --> 1 | Maquina --> 2\n");
    *turno = getchar();

    while (*turno != '1' && *turno != '2')
    {
        printf("Valor invalido. Intenta nuevamente.\n");
        *turno = getchar();
        cleanBuffer();
    }
    cleanBuffer();
    return turno;
}

typedef struct coord{
  int x;
  int y;
}coord;

void elegirCoord(char* mensaje,coord* coordenada){

  printf("%s\n",mensaje);
  coordenada->x=-1;
  coordenada->y=-1;
  while (((coordenada->x <0) || (coordenada->x > 15)))
  {
    printf("ingrese la posición en x para la ficha que desea mover: ");
    scanf("%d", &coordenada->x);
  }
  while (coordenada->y<0 || coordenada->y>15)
    {
      printf("ingrese la posición en y para la ficha que desea mover: ");
      scanf("%d", &coordenada->y);
    }

}

void randomPC(coord* coordenada){
  coordenada->x=rand()%16;
  coordenada->y=rand()%16;
}
int isJumpable(int tablero[16][16],int coord[4]){
    bool isValid = false;
    int diffI = (coord[2]-coord[0])/2;
    int diffJ = (coord[3]-coord[1])/2;
    int midPosicI = coord[0] + diffI, midPosicJ = coord[1] + diffJ;
    //-midPosic es la coordenada de la pieza a la que se quiere saltar
    isValid = (tablero[midPosicI][midPosicJ] == '-')? false: true;
    isValid = (diffI == 0 && diffJ == 0)? false: isValid;
    return isValid;
}
int checkJugada(coord pcActual,coord pcSiguiente,int turno){
    int coord[4] = {pcActual.x,pcActual.y,pcSiguiente.x,pcSiguiente.y};
    bool isValid = false;
    int absDiffI = abs(coord[0]-coord[2]);
    int absDiffJ = abs(coord[1]-coord[3]);
    //No se puede seleccionar una pieza vacia
    if(tablero[coord[0]][coord[1]] == '-' && coord[0] == coord[2] && coord[1] == coord[3]){
        return false;
    }
    if(absDiffI <= 1 && absDiffJ <= 1){
        isValid = (tablero[coord[2]][coord[3]] == '-')? true: false;
    }else{//es un salto
        if (turno==PERSONA){
            int cont=0;
            int salto;
            do
            {
                if((absDiffI == 2 && absDiffJ == 2) || (absDiffI == 0 && absDiffJ == 2) || (absDiffI == 2 && absDiffJ == 0) && cont==0){
                isValid = (tablero[coord[2]][coord[3]] != '-')? false: isJumpable(tablero,coord);
                cont=cont++;
                pcActual=pcSiguiente;

                }else{
                    if((absDiffI == 2 && absDiffJ == 2) || (absDiffI == 0 && absDiffJ == 2) || (absDiffI == 2 && absDiffJ == 0)){
                        printf("Desea realizar otro salto? 1 --> Si, 2 --> No:\n");
                        scanf ("%d",&salto);
                        if (salto==1)//si desea realizar otro salto
                        {
                        //entre a la funcion de condicion de salto
                            elegirCoord("Elija el proximo salto",&pcSiguiente);
                            int coord[4] = {pcActual.x,pcActual.y,pcSiguiente.x,pcSiguiente.y};
                            int absDiffI = abs(coord[0]-coord[2]);
                            int absDiffJ = abs(coord[1]-coord[3]);
                            isValid = (tablero[coord[2]][coord[3]] != '-')? false: isJumpable(tablero,coord);
                            pcActual=pcSiguiente;
                        }
                        if (salto != '1' && salto != '2')
                        {
                            printf("Valor invalido. Intenta nuevamente.\n");
                        }else{
                            isValid == false;
                        }
                    }else{
                        isValid == false;
                    }
                }
            }while (isValid==true);
        }else{//es un salto
            if((absDiffI == 2 && absDiffJ == 2) || (absDiffI == 0 && absDiffJ == 2) || (absDiffI == 2 && absDiffJ == 0) ){
            isValid = (tablero[coord[2]][coord[3]] != '-')? false: isJumpable(tablero,coord);
            }
        }
    }
    return isValid;
}

int coinFlip( int range){
  static int xd = 0;
  (xd == 0)? srand(time(NULL)):1;
  xd++;
  return rand()%(range+1);
}
int rango(int number){
  return 0<=number && number<=15;
}
void juegoPurete(char *nombre,unsigned int colorJugador, unsigned int turno){
  coord jugadorActual;
  coord jugadorSiguiente;
  coord pcActual;
  coord pcSiguiente;

  int victoria = 0;

  while(victoria == 0){
    	char bandera = 0;
    	if(turno == PERSONA){
    		printf("Juega %s con el color %s\n",nombre,colorJugador == BLANCO?"Negro":"Blanco");
			do{
				  elegirCoord("Elija la posicion inicial",&jugadorActual);
				  elegirCoord("Elija la posicion a mover",&jugadorSiguiente);
				  if(tablero[jugadorActual.x][jugadorActual.y] == (colorJugador = BLANCO?'B':'N'))
					  bandera = checkJugada(jugadorActual,jugadorSiguiente,turno);
			}while(bandera == 0);
			tablero[jugadorActual.x][jugadorActual.y] = '-';
			tablero[jugadorSiguiente.x][jugadorSiguiente.y] = (colorJugador = BLANCO?'B':'N');
			victoria=(colorJugador = BLANCO?victoriaBlanco():victoriaNegro());
			imprimirTablero();

			if (victoria!=0)
			{
			  printf("VICTORIA DE %s", nombre);
			  break;
			}
    	}
    	else{
    		printf("Juega la maquina con el color %s\n",colorJugador == NEGRO?"Blanco":"Negro");
			do{
			  pcSiguiente.x = coinFlip(15);
			  pcSiguiente.y = coinFlip(15);
			  pcActual.x = coinFlip(15);
			  pcActual.y = coinFlip(15);
			  if(tablero[pcActual.x][pcActual.y] == (colorJugador = NEGRO?'B':'N'))
				  bandera =  checkJugada(pcActual,pcSiguiente,turno);
			}while(bandera == 0);

			tablero[pcActual.x][pcActual.y] = '-';
			tablero[pcSiguiente.x][pcSiguiente.y] = (colorJugador = NEGRO?'B':'N');
			imprimirTablero();
			victoria=(colorJugador = NEGRO?victoriaBlanco():victoriaNegro());

			if (victoria!=0)
			{
			  printf("VICTORIA DE LA MAQUINA");
			  break;
			}

    	}
    	turno=!turno;
  	  }

}

/*
 *
 */
int victoriaBlanco()
{
  int cont=0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3 - i; j++) {
            if (tablero[i][j]== 'B'){
                cont+=1;
            }
        }
    }
  if (tablero[1][4]=='N')
  {
    cont+=1;
  }
  if (tablero[2][3]=='N')
  {
    cont+=1;
  }
  if (tablero[3][2]=='N')
  {
    cont+=1;
  }
  if (tablero[4][1]=='N')
  {
    cont+=1;
  }
    if (cont==19)
    {
      return 1;
    }
    return 0;
}

int victoriaNegro()
{
  int cont=0;
  for (int i=11;i<16;i++)
  {
    for(int j=15;j>11;j--)
    {
      if (tablero[i][j])
      {
        cont+=1;
      }
    }
  }
  if (tablero[11][14]=='N')
  {
    cont+=1;
  }
  if (tablero[12][13]=='N')
  {
    cont+=1;
  }
  if (tablero[13][12]=='N')
  {
    cont+=1;
  }
  if (tablero[14][11]=='N')
  {
    cont+=1;
  }
  if (cont==19)
  {
    return 1;
  }
  return 0;
}

int main()
{
    tableroInicial();
    imprimirTablero();
    char nombre[20];
    char lado[2];
    char turno[2];
    srand(time(NULL));
    UserData(nombre, lado, turno);//cargar datos para el juego
    unsigned int colorJugador = lado[0] =='1'?NEGRO:BLANCO;
    unsigned int turnoInicial = turno[0] == '1'?PERSONA:PC;
    juegoPurete(nombre,colorJugador,turnoInicial);
}
