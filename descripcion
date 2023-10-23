void cleanBuffer():

Descripción: Esta función se encarga de limpiar el búfer de entrada, eliminando cualquier carácter pendiente en la entrada estándar (normalmente el teclado) hasta que se alcance un salto de línea ('\n').
Uso: Se utiliza para evitar problemas cuando se capturan datos de entrada del usuario.
void tableroInicial():

Descripción: Inicializa el tablero de juego (matriz tablero) configurando las posiciones iniciales de las fichas negras ('N') y blancas ('B').
Uso: Establece el estado inicial del tablero antes de comenzar el juego.
void imprimirTablero():

Descripción: Imprime el estado actual del tablero en la consola, mostrando las fichas y casillas vacías.
Uso: Proporciona una representación visual del tablero para que los jugadores vean su estado.
int UserData(char *nombre, char *lado, char *turno):

Descripción: Esta función interactúa con el usuario para obtener información sobre el nombre del jugador, el lado elegido (blanco o negro) y quién empieza el juego (jugador o máquina). También permite al usuario aleatorizar la configuración del juego.
Uso: Captura datos del usuario para personalizar la configuración del juego y decide quién comienza.
void elegirCoord(char* mensaje, coord* coordenada):

Descripción: Interactúa con el usuario para obtener coordenadas (posición en el tablero) y las almacena en la estructura coord.
Uso: Utilizada para que el jugador o la máquina seleccionen las coordenadas de movimiento.
void randomPC(coord* coordenada):

Descripción: Genera aleatoriamente coordenadas de movimiento para la máquina y las almacena en la estructura coord.
Uso: Empleado para que la máquina realice movimientos aleatorios.
int isJumpable(int tablero[16][16], int coord[4]):

Descripción: Verifica si un salto de ficha entre dos coordenadas en el tablero es válido.
Uso: Utilizada en la validación de saltos de fichas durante el juego.
int checkJugada(coord pcActual, coord pcSiguiente, int turno):

Descripción: Verifica si un movimiento de ficha es válido, considerando las reglas del juego, incluidos los saltos.
Uso: Determina si el movimiento de una ficha seleccionada por un jugador (ya sea humano o máquina) es válido.
int coinFlip(int range):

Descripción: Realiza un volado virtual para generar un número aleatorio en el rango especificado.
Uso: Se utiliza para tomar decisiones aleatorias, como los movimientos de la máquina.
int rango(int number):

Descripción: Verifica si un número está dentro de un rango específico (0 a 15).
Uso: Usada para verificar si las coordenadas están dentro de los límites del tablero.
void juegoPurete(char *nombre, unsigned int colorJugador, unsigned int turno):
Descripción: La función principal que controla el flujo del juego. Permite a los jugadores (jugador humano y máquina) realizar movimientos y verifica si hay un ganador.
Uso: Maneja la lógica principal del juego.
int victoriaBlanco():
Descripción: Verifica si las fichas blancas han ganado el juego según las reglas especificadas. Devuelve 1 si las fichas blancas ganan y 0 en caso contrario.
Uso: Utilizada para comprobar si las fichas blancas han ganado el juego.
int victoriaNegro():
Descripción: Verifica si las fichas negras han ganado el juego según las reglas especificadas. Devuelve 1 si las fichas negras ganan y 0 en caso contrario.
Uso: Utilizada para comprobar si las fichas negras han ganado el juego.
int main():
Descripción: La función principal que inicia el programa. Llama a otras funciones para inicializar el tablero, capturar la configuración del jugador y controlar el flujo del juego.
Uso: Inicia el programa y controla la ejecución del juego.
