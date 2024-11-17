# SE_TP3_Teclado_Matricial
Trabajo practico número 3 de la materia Sistemas Embebidos de la FIUBA

Título: Smartlock

Alumno: Marcos Gómez Villafañe

Padrón: 105055

Objetivo Final: Desarrollar una cerradura inteligente que permita acceder con tarjeta y, en caso de visita sin tarjeta, permita hablar por teléfono con la visita.

Los temas a incorporar para este trabajo práctico son:
- Motor DC
- Sensor PIR
- Módulos relé
- Interrupciones 
- Temporizadores 
- PWM (modulación por ancho de pulsos)
- Generación de audio a partir de PWM
- Filesystem (gestión de archivos)
  
## Descripción
En este trabajo práctico se incorporará un Servomotor para accionar la apertura y cierre de la cerradura. 
Adicionalmente, se incluiran interrupciones para detectar cuando se aprieta el boton de cerrar la puerta y se hara uso de los temporizadores implementados en trabajos practicos previos para controlar el tiempo de apertura de la puerta y el tiempo máximo para introducir el código en el teclado matricial.
Por último, se utilizará un parlante para generar audio a partir de PWM. El audio indica cuando se detecta que se presiona una tecla, notifica cuando el código ingresado es incorrecto y avisa cuando se deja la puerta abierta.
En resumen, se necesitará:
- Incorporar el periférico Servomotor 
- Utilizar PWM para controlar las posiciones del servomotor (abierto y cerrado)
- Implementar una interrupción para el botón de cerrar
- Incorporar el periférico parlante
- Utilizar PWM para generar audio con el parlante
  
El Servomotor es el que se muestra debajo
- [https://www.microelectronicash.com/tecla-2669f--det--TECLA-2669F](https://www.microelectronicash.com/arduino-ds04-nfc--det--ARDUINO-DS04-NFC)
  
El parlante es como el que se muestra debajo:
- https://www.electronicasafg.com/MCO-491478423-mini-parlante-8-ohm-05w-speaker-arduino-_JM
  

### Resultado
El siguiente link muestra un video del funcionamiento:

https://drive.google.com/file/d/1m4aDb67fY_7gsR8zvAbPGWMtD4l36bGP/view?usp=sharing


