<img src="https://github.com/user-attachments/assets/15600b18-f73b-4ba3-a959-47f0048a1ab6" alt="image2" width="30%">

**UNIVERSIDAD DE BUENOS AIRES**  
**Facultad de Ingeniería**  
**86.65 Sistemas Embebidos**

Memoria del Trabajo Final:

***Smartlock* - Cerradura Inteligente con Wi-Fi -**

**Autor:**

**Sr. Marcos Gómez Villafañe**

Legajo: 105.055 

*Este trabajo fue realizado en las Ciudad Autónoma de Buenos Aires,*   
*entre Agosto y Diciembre de 2024\.*

  
**RESUMEN**

En este trabajo se realiza el diseño e implementación de una cerradura inteligente con Wi-Fi para uso cotidiano en hogares, corporaciones o industrias. Este sistema tiene por objetivo registrar y administrar el acceso de los individuoas a las distintas instalaciones, facilitando al dueño de la instalación un manejo dinámico y en tiempo real de los permisos de acceso. Para la comodidad de los usuarios, la cerradura inteligente cuenta con dos métodos de acceso: mediante tarjetas RFID o mediante un pin. Adicionalmente, el sistema cuenta con sensores magnéticos que permiten registrar los estados de las puertas en todo momento. El trabajo presenta una solución práctica y escalable para la administración de accesos a una instalación, previniendo filtraciones de seguridad y promoviendo un monitoreo transparente a través de la aplicación móvil.

La implementación del mismo se realizó utilizando los lenguajes de código C++ y Python mediante el uso del entorno de desarrollo de Mbed en una placa Núcleo-F429ZI proporcionada por la cátedra de Sistemas Embebidos de la Facultad de Ingeniería de la Universidad de Buenos Aires, y se utilizaron además diferentes módulos para el desarrollo del proyecto.

En esta memoria se presenta la motivación del proyecto, los diseños de las distintas partes, y se proponen futuras mejoras y ampliaciones.

**ABSTRACT**

In this work, the design and implementation of a smart lock with Wi-Fi for everyday use in homes, corporations or industries is carried out. This system aims to register and manage the access of individuals to different facilities, providing the owner of the facility with a dynamic and real-time management of access permissions. For the comfortability of users, the smart lock has two access methods: RFID card or pin access. In addition, the system has magnetic sensors that allow the door statuses to be recorded at all times. The work presents a practical and scalable solution for managing access to a facility, preventing security leaks and promoting transparent monitoring through the mobile application.

The implementation was carried out using C++ and Python code languages through the use of the Mbed development environment on a Núcleo-F429ZI board provided by the Embedded Systems Department of the School of Engineering of the University of Buenos Aires, and different modules were also used for the development of the project.

This report presents the motivation of the project, the designs of the different parts, and proposes future improvements and extensions.



**Índice General**


[**Registro de versiones**](#registro-de-versiones)	

[**Introducción general**](#introducción-general)	

[1.1 Título de la sección con este uso de las mayúsculas](#1.1-título-de-la-sección-con-este-uso-de-las-mayúsculas)	

[1.1.1 Este es el título de una subsección](#1.1.1-este-es-el-título-de-una-subsección)	

[1.2 Figuras y tablas](#1.2-figuras-y-tablas)	

[1.3 Ecuaciones](#1.3-ecuaciones)	

[1.4 “Trabajo vs. Proyecto” y tiempo verbal a utilizar](#1.4-trabajo-vs.-proyecto-y-tiempo-verbal-a-utilizar)	

[1.5 Estado del arte o análisis de sistemas similares al desarrollado](#1.6-estado-del-arte-o-análisis-de-sistemas-similares-al-desarrollado)	

[**Introducción específica**](#introducción-específica)	

[2.1 Descripción  de tal cosa](#heading=h.qt52d4use48v)	

[2.3.1 Alimentación](#2.3.1-alimentacion)

[**Diseño e implementación**](#diseño-e-implementación)	**[16](#diseño-e-implementación)**

[3.1 Hardware del… (completar)](#3.1-hardware-del…-\(completar\))	[16](#3.1-hardware-del…-\(completar\))

[3.2 Firmware del… (completar)](#3.2-firmware-del…-\(completar\))	[16](#3.2-firmware-del…-\(completar\))

[**Ensayos y resultados**](#ensayos-y-resultados)	**[17](#ensayos-y-resultados)**

[4.1 Pruebas funcionales del hardware](#4.1-pruebas-funcionales-del-hardware)	[17](#4.1-pruebas-funcionales-del-hardware)

[4.2 Pruebas funcionales del firmware](#4.2-pruebas-funcionales-del-firmware)	[17](#4.2-pruebas-funcionales-del-firmware)

[4.3 Pruebas de integración](#4.3-pruebas-de-integración)	[17](#4.3-pruebas-de-integración)

[4.4 Comparación con otros sistemas similares](#4.5-comparación-con-otros-sistemas-similares)	[17](#4.5-comparación-con-otros-sistemas-similares)

[**Conclusiones**](#conclusiones)	**[18](#conclusiones)**

[5.1 Resultados obtenidos](#5.1-resultados-obtenidos)	[18](#5.1-resultados-obtenidos)

[5.2 Próximos pasos](#5.2-próximos-pasos)	[18](#5.2-próximos-pasos)

[**Bibliografía**](#bibliografía)	

[**Anexos (sólo en caso de ser necesarios)**](#anexos-\(sólo-en-caso-de-ser-necesarios\))	**[20](#anexos-\(sólo-en-caso-de-ser-necesarios\))**

[A. Primer Anexo](#a.-primer-anexo)	[20](#a.-primer-anexo)



# Registro de versiones 

| Revisión | Cambios realizados | Fecha |
| :---: | ----- | ----- |
| 1.0 | Creación del documento | 9/12/2024 |
| 1.1 | Redacción del primer capítulo | 9/12/2024 |
| 1.2 | Redacción del segundo capítulo | 10/12/2024 |
| 1.2 | Redacción del tercer capítulo | 10/12/2024 |

### 

# **CAPÍTULO 1** 

# **Introducción general** 

## **1.1 Análisis de necesidad y objetivos** 

La creciente urbanización, las permanentes tasas de criminalidad y el acceso no autorizado a instalaciones han generado una necesidad de reinventar el tradicional mecanismo de acceso con llaves. Las cerraduras tradicionales, aunque ampliamente utilizadas, presentan limitaciones críticas, como la vulnerabilidad al robo de llaves, su duplicación no autorizada y la falta de registros de acceso. El auge de las tecnologías IoT promueven la implementación de sistemas de acceso más seguros, transparentes e ilimitadamente escalables y adaptables. A través de protocolos de Wi-Fi, una cerradura convencional puede controlarse de forma remota, otorgando flexibilidad en las entregas a domicilio y el permiso de acceso para visitas. En la Figura 1.1 se puede ver un modelo de cerradura inteligente con Wi-Fi y una apliación de celular para controlarla.

La implementación de las tecnologías IoT en el ámbito de las cerraduras y la seguridad presenta los siguientes beneficios:
- Seguridad Avanzada: El método de acceso convencional (llave) es susceptible a robo y plagios, pero con las cerraduras inteligentes se puede utilizar pines, RFID o huellas dactilares o reconocimiento facial, eliminando los riesgos de seguridad de las llaves físicas.
- Acceso remoto: A través de una conexión Wi-Fi, se puede acceder a la instalación desde cualquier lugar.
- Flexibilidad y comodidad de acceso: Se pueden crear claves de acceso de forma dinámica, tanto permanentes como temporales, lo cual es cómodo tanto para el dueño como para el visitante.
- Monitoreo: Las llaves convencionales no permiten identificar quien accede al edificio ni cuando accede. Estos dos problemas se solucionan con los sistemas inteligentes, que notifican y registran los accesos.


 <img src="https://github.com/user-attachments/assets/9d2beedb-58af-48eb-bad7-87d907b22b32" alt="image2" width="50%">
 
**Figura 1.1**: Modelo de cerradura inteligente con Wi-Fi .


En Argentina existen varios productos de características similares a las del proyecto, cada producto diferenciándose de otro con detalles, como por ejemplo huellas digitales, llaves, etc. Sin embargo, parecería que no hay un producto en Argentina que cumpla exactamente la misma función que el proyecto desarrollado.

Como primer competidor del mercado se puede mencionar a Yale, la cual ofrece una amplia gama de cerraduras digitales inteligentes para seguridad del hogar. Los precios de sus productos orbitan desde los 45.000 hasta los 600.000 pesos y sus productos incluyen desde cerraduras con teclado matricial hasta cerraduras con huellas digitales, todas con una aplicación para el celular. El proyecto tiene similitudes en el teclado matricial y en la aplicación, pero se diferencia en la oferta de los sensores magnéticos, del lector RFID y de la comunicación con parlante y micrófono.

Un segundo competidor es Philips, la cual tiene productos con reconocimiento facial y video portero. Esta tecnología es considerablemente superior al igual que sus precios, los cuales rondan el 1.000.000 de pesos. Sin embargo, la empresa no cuenta con lectores RFID ni sensores magnéticos, lo cual diferencia a nuestro proyecto.

En resumen, el mercado es sumamente competitivo y las características y funcionalidades de la cerradura pueden ser modificadas y ampliadas fácilmente, permitiendo desarrollar productos únicos y distintos de la competencia que encuentren un lugar en el mercado.

El presente proyecto se destaca especialmente por incorporar un módulo Wi-Fi que permite configurar los permisos de acceso de los individuos y un parlante y micrófono. Esto lo diferencia de otros sistemas similares en que permite seleccionar de forma remota los permisos de acceso y visualizar los intentos de acceso de forma remota. Adicionalmente, permite monitorear y regsitrar el ingreso y egreso de las visitas a la instalacion a traves de la aplicación. Una última característica especial es la presencia de un sensor magnético, el cual indica cuando se deja abierta la puerta accidentalmente, lo cual previene filtraciones de seguridad.

### **1.2 Módulos e Interfaces de *Smartlock*** 
El sistema *Smartlock* consta dos subsistemas principales: el sistema montado en la cerradura y el sistema de interfaz virtual para el ususario. En la Figura 1.2.1 se muestra el diagrama en bloques del proyecto.

 <img src="https://github.com/user-attachments/assets/54470de0-882c-4329-aed6-d6e38e0a0185" alt="image2" width="80%">

**Figura 1.2.1**: Diagrama en bloques del proyecto *Smartlock*.

En la Fiugra 1.2.1 se observa por un lado el subsistema de la cerradura con los periféricos que se encapsulan juntos como son el motor, el lector RFID y otros, y por el otro lado, el segundo susbsistema se encarga de mostrar los datos de la cerradura y enviar los comandos desde la aplicacion, interconectando los subsistemas por Wi-Fi.

La cerradura cuenta con dos métodos de acceso, mediante tarjetas RFID o mediante un pin de identificación. La tarjeta RFID es un identificador pasivo que al acercarse a un lector RFID, éste induce una corriente sobre ella para retransmitir una respuesta al lector. Estas tarjetas tienen un código de identificación unico que puede ocultarse para prevenir filtraciones de seguridad. La Figura 1.2.2 muestra la tarjeta y un lector RFID.

 <img src="https://github.com/user-attachments/assets/46be1b4e-dd71-4adf-a30a-cbd49e53a733" alt="image2" width="40%">
 
**Figura 1.2.2**: Tarjeta RFID y lector RFID.

Por otro lado, el pin se introduce en un teclado matricial de 4x4 caracteres. El largo del pin esta fijo en 4 dígitos pero es modificable. La Figura 1.2.3 muestra el teclado matricial en el que se introducen los códigos de acceso

<img src=https://github.com/user-attachments/assets/67fca740-727b-4869-a861-af216d65048b alt="image2" width="40%">
 
**Figura 1.2.3**: Teclado Matricial.

La interfaz virtual se muestra en al Figura 1.2.4.

<img src=https://github.com/user-attachments/assets/67fca740-727b-4869-a861-af216d65048b alt="image2" width="40%">

**Figura 1.2.4**: Interfaz virtual para el usuario.

En las próximas secciones se describirá con mayor detalle los módulos utilizados y sus características.

# **CAPÍTULO 2** 

# **Introducción específica** 

## **2.1 Requisitos**

Habiendo analizado las características principales de la cerradura, se definieron los principales requisitos para que el sistema cumpla con su función de forma correcta y resulte útil para su propósito. Para esto, se realizó una tabla definiendo los principales requisitos a implementar, mostrado en la Tabla 1.2.

| Grupo | ID | Descripción |
| :---- | :---- | :---- |
| Acceso | 1.1 | El sistema permitirá el acceso a la instalación mediante RFID |
|  | 1.2 | El sistema permitirá el acceso a la instalación mediante un teclado matricial |
|  | 1.3 | En caso de acceso permitido, el  sistema abrirá la puerta durante un periodo de tiempo fijado |
| Indicadores | 2.1 | El sistema contará con un indicador luminoso para indicar que la puerta está cerrada |
|  | 2.2 | El sistema contará con un indicador luminoso para indicar que la puerta está abierta |
|  | 2.3 | El sistema contará con un parlante que indique mediante sonido cuando se abre la puerta |
|  | 2.4 | El sistema contará con un parlante que indique mediante sonido cuando se introduce un código incorrecto |
|  | 2.5 | El sistema contará con un parlante que indique mediante sonido cuando se presiona una tecla |
|  | 2.6 | El sistema notificará con el parlante cuando se deja la puerta abierta |
|  | 2.7 | El sistema notificará mediante el titileo de leds cuando la puerta se deja abierta o cuando se introduce un código/RFID erróneo |
|  | 2.8 | El sistema notifica con audio y luz cuando se deja un código sin introducir completamente |
| Motor | 3.1  | El sistema contará con un motor para abrir y cerrar la cerradura |
|  | 3.2 | El sistema solo podrá cerrar la puerta cuando esta se halla contra el marco |
| Comunicación Audio  | 4.1 | El sistema deberá contar con un parlante para transmitir señales de audio |
| Comunicación Wi-Fi | 5.1 | El sistema se comunicará mediante Wi-Fi con la aplicación de celular |
|  | 5.2 | El sistema deberá enviar a la aplicación la información de acceso a la instalación |
|  | 5.3 | El sistema deberá enviar a la aplicación la información de acceso denegado a la instalación |
|  | 5.4 | En caso de lectura RFID, el sistema deberá comunicar la lectura de RFIDs desconocidos, junto con su ID (para poder guardarlo posteriormente) |
|  | 5.4 | El sistema deberá comunicarle a la aplicación el estado de la puerta y el numero de puerta |
| Aplicación | 6.1 | La aplicación tendrá la base de datos de los individuos habilitados con sus IDs |
|  | 6.2 | La aplicación deberá permitirle al usuario configurar los permisos de acceso de los individuos |
|  | 6.3 | La aplicación deberá poder mostrar la información de los accesos e intentos de acceso |
|  | 6.4 | La aplicación deberá poder controlar manualmente la apertura o cerradura de la puerta |
|  | 6.5 | La aplicación deberá permitirle al usuario configurar añadir nuevos individuos a la base de datos mediante codigo o RFID |
|  | 6.6 | La aplicación deberá mostrarle al usuario el estado de la puerta |
| Interruptores/ Botones | 7.1 | El sistema contará con botones para abrir o cerrar la puerta de forma manual |
|  | 7.2 | El sistema contará con un botón de timbre |
| Sensores | 8.1 | El sistema contará con un sensor magnético que detectará cuando la puerta se halla contra el marco |

<p align="center"><em>Tabla 2.1: Requisitos del proyecto.</em></p>


## **2.2 Casos de uso**
En las tablas 2.2 a 2.4 se presentan 3 casos de uso para ejemplificar el uso del sistema.

| Elemento | Definición |
| :---- | :---- |
| Disparador | Se quiere acceder a la instalación con permiso de acceso y con código en el teclado matricial. |
| Precondiciones | El sistema está encendido La puerta está cerrada, con la  cerradura cerrada. La aplicación está conectada al sistema. El indicador de puerta cerrada está encendido  |
| Flujo principal | El individuo introduce su código en el teclado matricial. Por cada tecla que presione recibe una melodía indicando la recepción del carácter introducido. Una vez introducido todo el código, el motor abre la cerradura y se notifica con una melodía el acceso habilitado. Además, con un led se notifica la habilitación del acceso. El módulo Wi-Fi comunica a la aplicación el acceso a la instalación, mostrando el estado de la puerta, la identificación del ingresante, la hora y el número de puerta. El individuo cierra la puerta una vez adentro. |
| Flujos alternativos | a. El individuo introduce erróneamente el código, con lo cual se notifica auditiva y visualmente al usuario y se notifica mediante Wi-Fi que se intentó acceder sin permiso a la instalación.  b. El individuo deja de introducir el código a mitad de camino. Luego de un tiempo preestablecido, el código a medias se descarta y se notifica que el intento fue incorrecto tanto al individuo como al propietario mediante Wi-Fi.. c. El individuo olvida la puerta abierta, entonces se suena una “alarma” y se notifica al propietario mediante Wi-Fi d. Un usuario dentro de la instalación presiona el botón de cerrar la puerta antes de que se introduzca el código. La puerta permanece cerrada. e. El usuario acerca su tarjeta en vez de terminar el código. La puerta se abre y se indica que la puerta está abierta. |

<p align="center"><em>Tabla 2.2: Caso de uso 1: El usuario quiere acceder con código.</em></p>


| Elemento | Definición |
| :---- | :---- |
| Disparador | Se quiere acceder a la instalación con permiso de acceso y con RFID. |
| Precondiciones | El sistema está encendido La puerta está cerrada, con la  cerradura cerrada. La aplicación está conectada al sistema. El indicador de puerta cerrada está encendido  |
| Flujo principal | El individuo acerca su tarjeta al lector. El ID de la tarjeta es correcto, el motor abre la cerradura y se notifica con una melodía el acceso habilitado. Además, con un led se notifica la habilitación del acceso. El módulo Wi-Fi comunica a la aplicación el acceso a la instalación, mostrando el estado de la puerta, la identificación del ingresante, la hora y el número de puerta. El individuo cierra la puerta una vez adentro. |
| Flujos alternativos | a. El individuo usa una tarjeta no habilitada, con lo cual se notifica auditiva y visualmente al usuario y se notifica mediante Wi-Fi que se intentó acceder sin permiso a la instalación.  b. El individuo olvida la puerta abierta, entonces se suena una “alarma” y se notifica al propietario mediante Wi-Fi |

<p align="center"><em>Tabla 2.3: Caso de uso 2: El usuario quiere acceder con RFID.</em></p>


| Elemento | Definición |
| :---- | :---- |
| Disparador | Se quiere añadir una nueva tarjeta RFID |
| Precondiciones | El sistema está encendido La puerta está cerrada, con la  cerradura cerrada. La aplicación está conectada al sistema. El indicador de puerta cerrada está encendido |
| Flujo principal | Se acerca una tarjeta desconocida al lector RFID. El sistema indica que el intento de acceso es incorrecto. El sistema muestra el ID de la tarjeta e indica si se quiere guardar la tarjeta mediante comunicación Wi-Fi con la aplicación. |
| Flujos alternativos | a. Se pierde la conexión Wi-Fi. El sistema no puede continuar con el guardado de la tarjeta. Se indica que se perdió la conexión b. Se apaga el sistema. El sistema no puede continuar con el guardado de la tarjeta.  |

<p align="center"><em>Tabla 2.4: Caso de uso 3: El usuario quiere guardar una tarjeta RFID.</em></p>

## **2.3 Descripción de los Módulos del sitema**
## **2.3.1 Alimentación**
El sistema se alimenta con 3 sistemas de alimentación que pueden reemplazarse posteriormente por un solo sistema de alimentación. Se menciona que se tiene muchos sistemas de alimentación debido a la etapa de desarrollo inicial. La primer alimentación se encarga de alimentar la placa Nucleo-F429ZI y es la alimentación proveniente de la computadora portatil mediante USB, la cual permite comunicación UART. 

El segundo sistema de alimentación es una fuente transformadora marca HAMA modelo 00201644 con 5V de salida y hasta 1.2 A de corriente. Esta alimentación es para el esp32, encargado de la comunicación Wi-Fi. Una tercera fuente transformadora 220 VAC a 12 VDC con 2000 mA modelo FJ-SW102 se utiliza para alimentar una fuente modelo Mb-102 capaz de entregar a la salida 5 V o 3,3 V seleccionables, y hasta 700 mA. A través del Mb-102 se alimenta a todos los otros periféricos como el lector RFID, el motor y otros. Se muestra la fuente Mb-102 en la Figura

<img src=https://github.com/user-attachments/assets/036b1989-56ed-49ab-b803-4aeecc3f1c3f alt="image2" width="40%">

**Figura 2.3.1**: Fuente de alimentación Mb-102.


## **2.3.2 Microcontrolador** 
Como controlador principal del sistema se utiliza la placa NUCLEO-F429ZI. La elección de esta placa recayó exclusivamente en la disponibilidad, teniendo además como requerimiento la cantidad de memoria, pines y periféricos de la placa. La placa se programó en C++ a través de la plataforma *Keil Studio Cloud* y se muestra en la Figura 2.3.2 .

<img src=https://github.com/user-attachments/assets/14a92d96-6aab-463f-b4e8-22d7dc2e253b alt="image2" width="40%">

**Figura 2.3.2**: Placa NUCLEO-F429ZI.

## **2.3.3 Motor** 
El acceso a la instalación se habilita con el accionamiento de un servomotor. El servomotor utilizado en este proyecto es el microservo de 9g de TOWERPRO modelo SG90, mostrado en la Figura 2.3.3. Para el control de este servomotor se usa PWM, identificando mediante experimentos las frecuencias correspondientes a los ángulos máximos de operación del servomotor.

<img src=https://github.com/user-attachments/assets/ee3fd32b-8d09-45cc-870d-dcbe58f827f3 alt="image2" width="40%">

**Figura 2.3.3**: Servomotor SG90.

Este servomotor se reemplazaría para puertas grandes por otro motor con mas potencia para poder mover la perilla más pesada.

## **2.3.4 Lector RFID** 
Para este proyecto se buscó un lector RFID de bajo costo y compacitibilidad, eligiendo el modelo RC522 mostrado en la Figura 2.3.4.Este módulo cuenta con el circuito integrado MFRC522, que es un lector inalámbrico que trabaja a 13,56 MHz con la cual se leen las tarjetas de acceso.

<img src=https://github.com/user-attachments/assets/83078155-b70e-44d6-9eb2-d634a3e11e06  alt="image2" width="40%">

**Figura 2.3.4**: Lector RFID RC522.

Para comunicarse con este módulo se utiliza el protocolo SPI, y para la programación de la placa NUCLEO se utilizó una librería de software escrita por Martin Olejar y publicado en la página oficial de MBED.

## **2.3.5 Teclado Matricial** 
El teclado matricial elegido es un Teclado Membrana Matricial 4x4 como se muestra en la Figura 2.3.5. La selección de este teclado se hizo en base a su disponibilidad en el mercado local y su bajo costo.

<img src=https://github.com/user-attachments/assets/6c647715-ff55-45e0-8941-e491e28d6c11  alt="image2" width="40%">

**Figura 2.3.5**: Teclado matricial.

Para comunicarse con este módulo se utiliza GPIO, el código del teclado fue obtenido y adaptado del libro *A Beginner’s Guide to Designing Embedded System Applications on Arm Cortex-M Microcontrollers* por Ariel Lutenberg.

## **2.3.6 Sensor Magnetico** 
El sensor magnetico utilizado consta de dos componentes: un imán y una llave magnetica (se muestra ambos en la Figura 2.3.6). La llave magnética son hilos finos que al acercar un imán hace un contacto.

<img src=https://github.com/user-attachments/assets/41ace232-ff76-4d27-9861-f1221cc78199  alt="image2" width="40%">

**Figura 2.3.6**: Sensor magnético.

## **2.3.7 Parlante** 
Para la comunicación por audio se usa un parlante de 8 ohms y 2 Watts como se muestra en la Figura 2.3.7 .

<img src= https://github.com/user-attachments/assets/59824229-6f30-46c4-aadc-45b2e2f2f51d alt="image2" width="40%">

**Figura 2.3.7**: Parlante 8 Ohms 2 Watts.

## **2.3.8 Comunicación Wi-Fi** 
Para la comunicación por audio se usa un parlante de 8 ohms y 2 Watts como se muestra en la Figura 2.3.7 .
<img src= https://github.com/user-attachments/assets/ac1e1a22-ae50-4a56-801a-45ebbec1cbdc alt="image2" width="40%">


**Figura 2.3.8**: Parlante 8 Ohms 2 Watts.



# **CAPÍTULO 3** 

# **Diseño e implementación** 

## **3.1 Diseño del Hardware** 

Para el diseño del prototipo se construyó una maqueta de madera haciendo los agujeros correspondientes para pasar los cables y conectándolos al protoboard de forma prolija y ordenada. La figura 3.1 muestra el montaje final del prototipo.

<img src= https://github.com/user-attachments/assets/59824229-6f30-46c4-aadc-45b2e2f2f51d alt="image2" width="40%">

**Figura 3.1**: Montaje final del prototipo.

Los esquemáticos se muestran en las secciones posteriores.

## **3.1.1 Diseño de la alimentación** 
En la figura 3.1.1 se muestra el circuito esquemático del hardware de alimentación con sus debidos capacitores a la salida para estabilizar la salida ante picos de corriente.

<img src=https://github.com/user-attachments/assets/a7625bac-d907-4369-8133-8f78a38716eb alt="image2" width="40%">

**Figura 3.1.1**: Alimentación del sistema.

## **3.1.2 Diseño de los indicadores e interruptores** 

<img src=https://github.com/user-attachments/assets/37805a98-bcfc-4c11-983b-6d91c570b76e  alt="image2" width="40%">

**Figura 3.1.2**: Conexionado de los indicadores e interruptores del sistema.

## **3.1.3 Diseño del lector RFID** 

<img src=https://github.com/user-attachments/assets/a2770d18-31b0-4e5b-81f5-ed92d74112ae  alt="image2" width="40%">

**Figura 3.1.3**: Conexionado del lector RFID del sistema.

## **3.1.4 Diseño del parlante** 

<img src=https://github.com/user-attachments/assets/cf5e304f-a75d-4c79-8a84-3961b2433360  alt="image2" width="40%">

**Figura 3.1.4**: Diseño del parlante del sistema.

## **3.1.5 Diseño del motor** 
<img src=https://github.com/user-attachments/assets/4ce16d1c-2db0-4873-8110-544dd7427657  alt="image2" width="40%">

**Figura 3.1.5**: Diseño del motor del sistema.

## **3.1.6 Diseño del teclado matricial** 
<img src=https://github.com/user-attachments/assets/ffb93399-ce71-42b2-83dc-5e8bec9a9624  alt="image2" width="40%">

**Figura 3.1.6**: Diseño del teclado matricial del sistema.

## **3.1.7 Diseño del Modulo Wi-Fi** 
<img src=https://github.com/user-attachments/assets/66cd0279-c347-494b-bb1c-3e01c6b74f6f alt="image2" width="40%">

**Figura 3.1.7**: Diseño del Módulo Wi-Fi.

## **3.1.8 Diseño del hardware con la placa NUCLEO-F429ZI** 

<img src= https://github.com/user-attachments/assets/2ddeee79-c87c-4892-9026-08ff3395c338 alt="image2" width="40%">

**Figura 3.1.9**: Circuito esquemático del conexionado del NUCLEO-F429ZI.

## **3.2 Firmware del *Smartlock*** 

La implementación del trabajo se realizó en lenguaje C++ utilizando Mbed y bajo el paradigma de la programación orientada a objetos. El firmware está conformado por un archivo main.cpp que inicializa al sistema con *system_init()* y luego convoca repetidamente a la función *system_update()*, las librerías arm_book_lib.h, global_defines.h, el archivo mbed_app.json y una carpeta con modulos que contienen un archivo .cpp y otro .h. Las librerias mencionadas y el archivo json contienen, respectivamente, la función main del programa, numerosas definiciones y algunas configuraciones. La Figura 3.2.1 muestra un diagrama de archivos del sistema.

<img src= https://github.com/user-attachments/assets/95144be5-f9d5-4684-866b-590c30889119 alt="image2" width="40%">

**Figura 3.2.1**: Diagrama de archivos del *Smartlock*.

Como se mencionaba, el archivo main.cpp solamente se encarga de inicializar el sistema y actualizar el estado, como se muestra en la Figura . En el archivo  *global_defines.h* se encuentran muchas definiciones constantes de pins y valores necesarios para el funcionamiento del sistema. Solo fueron definidos los pines para la placa que se usa en este trabajo, pero se tomó esta decisión para simplificar el trabajo si en un futuro se decide utilizar otra placa. La Figura 3.2.1 muestra el archivo main.cpp.

<img src=https://github.com/user-attachments/assets/96ef8f41-0467-491d-a9cd-02f5e88e5a65 alt="image2" width="20%">

**Figura 3.2.2**: Archivo Main.cpp.

## **3.2.1 Módulo Keypad** 
Para este módulo el código y la FSM se incorpora del libro *A Beginner’s Guide to Designing Embedded System Applications on Arm Cortex-M Microcontrollers* escrito por Ariel Lutenberg y se lo modifica para que sea un objeto. La máquina de estados finita del módulo se muestra en la Figura

![image](https://github.com/user-attachments/assets/23a69610-ce9a-432d-a751-463a9237f7d6)


**CAPÍTULO 4** 

# **Ensayos y resultados** {#ensayos-y-resultados}

## **4.1 Pruebas funcionales del hardware**  {#4.1-pruebas-funcionales-del-hardware}

La idea de esta sección es explicar cómo se hicieron los ensayos, qué resultados se obtuvieron y analizarlos.

Es muy importante que haya fotografías que sirvan de evidencia de que los ensayos realmente se hicieron.

También es esperable que haya tablas o gráficos que presenten los resultados obtenidos.

## **4.2 Pruebas funcionales del firmware**  {#4.2-pruebas-funcionales-del-firmware}

La idea de esta sección es explicar cómo se hicieron los ensayos, qué resultados se obtuvieron y analizarlos.

Es muy importante que haya fotografías que sirvan de evidencia de que los ensayos realmente se hicieron.

También es esperable que haya tablas o gráficos que presenten los resultados obtenidos.

## **4.3 Pruebas de integración** {#4.3-pruebas-de-integración}

Las pruebas de integración son aquellas que se realizan en el ámbito del desarrollo de software una vez que se han aprobado las pruebas unitarias y lo que prueban es que todos los elementos unitarios que componen el software, funcionan juntos correctamente probándolos en grupo. 

Se pueden incluir fotos o links a vídeos donde se aprecien las pruebas de integración desarrolladas y los resultados obtenidos. En esta sección se espera encontrar un análisis similar al presentado en la Tabla 12.36 del libro. 

## **4.4 Cumplimiento de requisitos**

En esta sección se espera encontrar un análisis similar al presentado en la Tabla 12.35 del libro. 

## **4.5 Comparación con otros sistemas similares**   {#4.5-comparación-con-otros-sistemas-similares}

Esta sección sería la continuación del análisis de sistemas similares presentados en el Capítulo 1\. La diferencia es que en este caso se incluye en la comparación al desarrollo realizado. Esta comparación se recomienda que se haga mediante una tabla.

## **4.6 Documentación del desarrollo realizado**

En esta sección se espera encontrar una tabla similar a la Tabla 12.37 que se presenta en el libro. 

**CAPÍTULO 5** 

# **Conclusiones** {#conclusiones}

## **5.1 Resultados obtenidos** {#5.1-resultados-obtenidos}

La idea de esta sección es resaltar cuáles son los principales aportes del trabajo realizado. Debe ser especialmente breve y concisa. Es buena idea usar un listado para enumerar los logros obtenidos.

## **5.2 Próximos pasos** {#5.2-próximos-pasos}

Acá se indica bien breve cómo se podría continuar el trabajo más adelante. Se propone incluir un análisis al respecto similar al que se realiza en el libro en relación a la mencionada Tabla 12.37, donde se discuten las mejoras adicionales que se podrían realizar en el futuro. 

# **Bibliografía** {#bibliografía}

\[1\] IEEE (2016, Jun 26). IEEE Citation Reference \[Online\]. Available: http://www.ieee.org/documents/ieeecitationref.pdf  

\[2\] Proyecto CIAA (2016, Jun 26). EDU-CIAA-NXP \[Online\]. Available: http://www.proyecto-ciaa.com.ar/devwiki/doku.php 

# **Anexos (sólo en caso de ser necesarios)** {#anexos-(sólo-en-caso-de-ser-necesarios)}

## **A. Primer Anexo**  {#a.-primer-anexo}

En caso de ser necesario utilizar anexos, siguiendo siempre el mismo formato que para el cuerpo principal de la Memoria.

[^1]:  Como esta nota por ejemplo.

[^2]:  ARM (2016, Jun 26). ARM Cores \[Online\]. Available: http://www.arm.com/cores.html
