# SE_TP1_Lector_RFID
Trabajo practico número 1 de la materia Sistemas Embebidos de la FIUBA

Título: Smartlock

Alumno: Marcos Gómez Villafañe

Padrón: 105055

Objetivo Final: Desarrollar una cerradura inteligente que permita acceder con tarjeta y, en caso de visita sin tarjeta, permita hablar por telefono con la visita.

## Descripción 

Para el TP1 se desarrollará la lectura de tarjetas mediante un lector RFID y la visualización del estado de la cerradura (Bloqueado o Desbloqueado)

El sitema deberá poder leer un tag RFID y obtener el código de acceso de la tarjeta para desbloquear la puerta. Mientras la puerta este cerrada, deberá visualizarlo con un led rojo. Una vez que se abre la puerta, deberá visualizarse con un led verde. La puerta permanecerá abierta por un periodo de 3 minutos hasta cerrarse automáticamente. Deberá tener un botón en para cerrar la puerta manualmente.

Adicionalmente, el sistema deberá tener acceso a una computadora para que se pueda escribir en la tarjeta el código de acceso. 

El lector de la tarjeta rfid es como el que se muestra debajo:
- https://articulo.mercadolibre.com.ar/MLA-884349718-kit-rfid-rc522-con-lector-llavero-tarjeta-para-arduino-_JM#polycard_client=search-nordic&position=8&search_layout=grid&type=item&tracking_id=086e1311-712d-4cdf-94db-4764c49c0e53



Cada vez que se accede o se intenta acceder al edificio se envia un resumen a través del puerto serie con:
- Hora de intento de acceso
- Puerta de intento de acceso
- ID del tag (en caso de ser un ID valido)

Plataforma de desarrollo: NUCLEO-F429ZI

Periféricos a utilizar:
- LED 1: Se encenderá para indicar que se desbloquea la puerta
- LED 2: Se encenderá para indicar que se bloquea la puerta
- UART1: Se utiliza para leer la contraseña de la tarjeta mediante el lector RFID
- UART2: Se utiliza para enviar información de estado del sistema a la PC y para escribir una contraseña a la tarjeta
- USER BUTTON: Fuerza el bloqueo de la puerta


### Observaciones:
- IMPORTANTE: no se controla ningún motor en esta primera versión del sistema.
- IMPORTANTE: no se implementa ningún sistema de habla con visitas que no tengan el tag en esta versión del sistema.
- IMPORTANTE: no se implementa ningún tipo de conexión wifi para transmitir datos

  
### Diagrama en bloques:

![Sistemas Embebidos TP1 drawio](https://github.com/user-attachments/assets/3cda84e4-b717-47ed-8139-8f63a08ccd90)

## Desarrollo:
A continuación, se describe el contenido de este Trabajo Práctico:
1) Se realiza el esquemático con las conexiones en TP1_SE_esquematico. Éste se define a partir de las especificaciones y de la hoja de datos en https://os.mbed.com/platforms/ST-Nucleo-F429ZI/
2) Con el esquemático, se definen los pines a utilizar para el código en global_definitions
3) Se hace uso de:
   - Una comunicación UART con la computadora
   - Una comuniación SPI con el lector RFID
   - Un timer para contar el tiempo en que la puerta permanece abierta

4) La lógica del codigo es la siguiente:
   - Si se acerca una tarjeta nueva preguntar si se desea guardarla
   - Si se desea guardar, se escribe en la memoria de la NUCLEO el ID leido de la tarjeta
   - Si no se desea guardar, no se escribe nada en la memoria
   - Si el ID de la tarjeta leida es igual al ID guardado, se abre la puerta y se inicializa un timer
   - Si el tiempo del timer es mayor a 10 segundos,se cierra la puerta
   - En todo el proceso, si se presiona el botón para cerrar la puerta se cierra la puerta

![Estados TP1](https://github.com/user-attachments/assets/62f4d531-08d9-4f3d-b6ac-242f25beefea)

## Bugs
1) Algunas de las condiciones de if del puntero rfid_content no funcionan correctamente y por eso no se escriben los mensajes en la computadora.

## Resultado
El siguiente video muestra que el ID de la tarjeta fue leído y guardado por el sistema. Al acercar la tarjeta nuevamente, se prende el led verde indicando que abrió la puerta.

https://github.com/user-attachments/assets/06ab2fae-fa66-4fb5-a746-cb7c03a149e0


     
