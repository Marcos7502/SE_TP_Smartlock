# **Smartlock**

**Autor**

**Marcos Gómez Villafañe \- Padrón 105.055**

**Fecha:**

**2do cuatrimestre 2024**

### **Cumplimiento de los requerimientos**

En base a los requerimientos planteados en la definición del proyecto, se evalúa el estado actual de cada uno indicando en <span style="color:green">verde</span> aquellos que ya fueron cumplidos, en <span style="color:orange">amarillo</span> los que aún no fueron cumplidos pero se proyecta que será posible hacerlo, y en <span style="color:red">rojo</span> los requerimientos que no serán cumplidos, ya sea por falta de tiempo o por otro inconveniente.

| Grupo          | ID   | Descripción                                                                                               |
|---------------- |------|----------------------------------------------------------------------------------------------------------|
| **Acceso**      | 1.1  | <span style="color:green">El sistema permitirá el acceso a la instalación mediante RFID</span>           |
|                 | 1.2  | <span style="color:orange">El sistema permitirá el acceso a la instalación mediante un teclado matricial</span> |
|                 | 1.3  | <span style="color:green">En caso de acceso permitido, el sistema abrirá la puerta durante un periodo de tiempo fijado</span> |
| **Indicadores** | 2.1  | <span style="color:green">El sistema contará con un indicador luminoso para indicar que la puerta está cerrada</span> |
|                 | 2.2  | <span style="color:green">El sistema contará con un indicador luminoso para indicar que la puerta está abierta</span> |
|                 | 2.3  | <span style="color:orange">El sistema contará con un parlante que indique mediante sonido cuando se abre la puerta</span> |
|                 | 2.4  | <span style="color:red">El sistema contará con un parlante que indique mediante sonido cuando se introduce un código incorrecto</span> |
|                 | 2.5  | <span style="color:green">El sistema contará con un parlante que indique mediante sonido cuando se presiona una tecla</span> |
|                 | 2.6  | <span style="color:orange">El sistema notificará con el parlante cuando se deja la puerta abierta</span> |
|                 | 2.7  | <span style="color:orange">El sistema notificará mediante el titileo de leds cuando la puerta se deja abierta o cuando se introduce un código/RFID erróneo</span> |
|                 | 2.8  | <span style="color:orange">El sistema notifica con audio y luz cuando se deja un código sin introducir completamente</span> |
| **Motor**       | 3.1  | <span style="color:green">El sistema contará con un motor para abrir y cerrar la cerradura</span>         |
|                 | 3.2  | <span style="color:orange">El sistema solo podrá cerrar la puerta cuando esta se halla contra el marco</span> |
| **Audio**       | 4.1  | <span style="color:orange">El sistema deberá contar con un parlante para transmitir señales de audio</span> |
|                 | 4.2  | <span style="color:red">El sistema deberá contar con un micrófono para recibir señales de audio</span>    |
| **Wi-Fi**       | 5.1  | <span style="color:green">El sistema se comunicará mediante Wi-Fi con la aplicación de celular</span>     |
|                 | 5.2  | <span style="color:green">El sistema deberá enviar a la aplicación la información de acceso a la instalación</span> |
|                 | 5.3  | <span style="color:orange">El sistema deberá enviar a la aplicación la información de acceso denegado a la instalación</span> |
|                 | 5.4  | <span style="color:red">En caso de lectura RFID, el sistema deberá comunicar la lectura de RFIDs desconocidos, junto con su ID</span> |
|                 | 5.4  | <span style="color:orange">El sistema deberá comunicarle a la aplicación el estado de la puerta y el número de puerta</span> |
|                 | 5.5  | <span style="color:red">El sistema deberá poder recibir señales de audio de la aplicación</span>          |
|                 | 5.6  | <span style="color:red">El sistema deberá poder transmitir señales de audio a la aplicación</span>        |
| **Aplicación**  | 6.1  | <span style="color:green">La aplicación tendrá la base de datos de los individuos habilitados con sus IDs</span> |
|                 | 6.2  | <span style="color:orange">La aplicación deberá permitirle al usuario configurar los permisos de acceso de los individuos</span> |
|                 | 6.3  | <span style="color:orange">La aplicación deberá poder mostrar la información de los accesos e intentos de acceso</span> |
|                 | 6.4  | <span style="color:red">La aplicación deberá poder controlar manualmente la apertura o cerradura de la puerta</span> |
|                 | 6.5  | <span style="color:red">La aplicación deberá permitirle al usuario configurar añadir nuevos individuos a la base de datos mediante código o RFID</span> |
|                 | 6.6  | <span style="color:orange">La aplicación deberá mostrarle al usuario el estado de la puerta</span>        |
| **Botones**     | 7.1  | <span style="color:green">El sistema contará con botones para abrir o cerrar la puerta de forma manual</span> |
|                 | 7.2  | <span style="color:orange">El sistema contará con un botón de timbre</span>                               |
| **Sensores**    | 8.1  | <span style="color:green">El sistema contará con un sensor magnético que detectará cuando la puerta se halla contra el marco</span> |
