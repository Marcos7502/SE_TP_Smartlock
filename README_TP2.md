# SE_TP2_Teclado_Matricial
Trabajo practico número 2 de la materia Sistemas Embebidos de la FIUBA

Título: Smartlock

Alumno: Marcos Gómez Villafañe

Padrón: 105055

Objetivo Final: Desarrollar una cerradura inteligente que permita acceder con tarjeta y, en caso de visita sin tarjeta, permita hablar por teléfono con la visita.

Los temas a incorporar para este trabajo práctico son:
- Máquina de estado finito
- Reloj de tiempo real 
- Modularización en archivos
- Buen uso de variables y funciones públicas y privadas 
- Diseño con bajo acoplamiento y alta cohesión 
- Displays alfanuméricos y gráficos
- Interfaces I2C y SPI
- Capas de abstracción de hardware y software
  
## Descripción
En este trabajo práctico se incorporará un teclado matricial para acceder a la puerta en caso de pérdida de la tarjeta RFID. Para ello, se necesitará:
- Incorporar el periférico del teclado matricial
- Implementar una máquina de estados finito para el funcionamiento del sistema y para el debounce de las teclas 
- Implementar un timer para medir el tiempo de debounce de las teclas
- Implementar un timer para definir un tiempo máximo para ingresar el código
  
El teclado matricial es como el que se muestra debajo:
- https://www.microelectronicash.com/tecla-2669f--det--TECLA-2669F
  
Se incluirán funciones de titileo de LEDS para:
- indicar cuando una tarjeta introducida es incorrecta (titileo led rojo)
- indicar cuando un código introducido es incorrecto (titileo led rojo)
- indicar cuando una tarjeta fue guardada correctamente (titileo led rojo, led verde prendido) 

Adicionalmente, en este trabajo práctico se propone revisar y rediseñar la interfaz SPI desarrollada en SE_TP1, enfatizando la modularización en archivos, el buen uso de variables y funciones, la maximización de la cohesión y la minimización del acoplamiento.

Por último, se incorporará un sensor magnético para detectar cuando la puerta está en el lugar correcto para cerrarla. Este servirá para detectar cuando fue olvidada abierta. Si fue olvidada abierta, en el próximo trabajo práctico se notificará al usuario por celular o se hará sonar una alarma.

Cada vez que se accede o se intenta acceder al edificio se envia un resumen a través del puerto serie (UART) con:
- Hora de intento de acceso
- Puerta de intento de acceso
- ID del tag (en caso de ser un ID valido)
- Código introducido (en caso de haber introducido un codigo)

Si se olvida la puerta abierta se enviara a traves del puerto serie un mensaje con:
- Hora 
- Puerta
- Indicación de que la puerta esta abierta

Plataforma de desarrollo: NUCLEO-F429ZI

Periféricos a utilizar:
- LED 1: Se encenderá para indicar que se desbloquea la puerta. Titila al guardar una tarjeta.
- LED 2: Se encenderá para indicar que se bloquea la puerta. Titila cuando se introduce un código o tarjeta erronea.
- SPI1: Se utiliza para leer la contraseña de la tarjeta mediante el lector RFID
- UART1: Se utiliza para enviar información de estado del sistema a la PC y para escribir una contraseña a la tarjeta
- USER BUTTON: Fuerza el bloqueo de la puerta
- TECLADO MATRICIAL: Se utiliza para ingresar el código cuando el usuario olvida la tarjeta
- SENSOR MAGNÉTICO: Se utiliza para detectar que la posición de la puerta sea la correcta para cerrar la puerta.

### Diagrama en bloques
![Sistemas Embebidos TP2](https://github.com/user-attachments/assets/3b8da742-4e1e-4fda-8ae9-c1bbe9e61cb6)

### Máquina de Estados
![Estados TP2 SE](https://github.com/user-attachments/assets/89ae4942-22ab-4f68-b6c9-ae8b9b16837a)

### Resultado
El siguiente link muestra un video del funcionamiento.

https://drive.google.com/file/d/1dUj6J2dgBfxXLpf9hEOSNfRaAek-ReON/view?usp=sharing

### Dificultades y Comentarios
El lector RFID MFRC522 funcionaba con normalidad desde el TP1 hasta 3 días antes de la entrega, cuando se dejaron de leer los mensajes al micro y las tarjetas. La inoperabilidad del lector RFID fue repentina y sin mensajes de error. Se observó lo siguiente:
1) El problema no era debido a un defecto en el MFRC522, ya que se probó con 3 distintos y el resultado era el mismo, no se reconocáa al MFRC522.
2) El problema no era debido a las tensiones de alimentación. Se probaron todas las tensiones de alimenatación y todas eran menor a 3.3V.
3) El problema parecía ser solamente en la nucleo debido a que en Arduino uno, con las adaptaciones necesarias, el lector funcionaba.
4) El problema no era debido a las conexiones del protoboard o los cables. Se probó la continuidad de todos los cables, se cambiaron tanto cables como protoboards y el problema persistía.
5) Utilizando versiones más simples para testear el lector en Keil Studio, un ejemplo del 2012 con una versión de MBED.os distinta fue el único en funcionar correctamente. Esto dio lugar a pensar que el problema era de la versión de MBED y probablemente de la configuración de los drivers. No se pudo hallar la versión que lo hizo funcionar porque no estaba detallado en la documentación de MBED.
6) El problema no residía en el código, porque funcionaba antes y testiandolo en esta versión vieja de MBED, funcionaba también.

**Este problema se solucionó temporalmente inicializando el modo debug cada vez que había que probar el código.** Si se intentaba compilar con el botón de run desde Keil Studio, la placa NUCLEO-F429ZI no reconocía al lector RFID. Se sigue desconociendo el origen del problema.
