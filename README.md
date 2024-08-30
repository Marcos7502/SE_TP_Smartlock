# SE_TP1_Lector_RFID
Trabajo practico número 1 de la materia Sistemas Embebidos de la FIUBA

Título: 

Alumno: Marcos Gómez Villafañe

Padrón: 105055

Objetivo: Desarrollar una cerradura inteligente que permita acceder con tarjeta y, en caso de visita sin tarjeta, permita hablar por telefono con la visita.

Descripción: 

Para el TP1 se deserrollará la lectura tarjetas mediante un lector RFID y la visualización del estado 

El sitema deberá poder leer un tag RFID y obtener el código de acceso de la tarjeta para desbloquear la puerta. Mientras la puerta este cerrada, deberá visualizarlo con un red rojo. Una vez que se abre la puerta, deberá visualizarse con un led verde. La puerta permanecerá abierta por un periodo de 3 minutos hasta cerrarse automaticamente. Deberá tener un botón en para cerrar la puerta manualmente.

Adicionalmente, el sistema deberá tener acceso a una computadora para que se pueda escribir sobre la tarjeta el código de acceso. 

El lector de la tarjeta rfid es como el que se muestra debajo:
- https://articulo.mercadolibre.com.ar/MLA-884349718-kit-rfid-rc522-con-lector-llavero-tarjeta-para-arduino-_JM#polycard_client=search-nordic&position=8&search_layout=grid&type=item&tracking_id=086e1311-712d-4cdf-94db-4764c49c0e53

Observaciones:
- IMPORTANTE: no se controla ningún motor en esta primera versión del sistema.
- IMPORTANTE: no se implementa ningún sistema de habla con visitas que no tengan el tag en esta versión del sistema.
- IMPORTANTE: no se implementa ningún tipo de conexión wifi para transmitir datos

Cada vez que se accede o se intenta acceder al edificio se envia un resumen a traves del puerto serie con:
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

Diagrama en bloques:

![Sistemas Embebidos TP1 drawio](https://github.com/user-attachments/assets/3cda84e4-b717-47ed-8139-8f63a08ccd90)

