

 <img src="https://github.com/user-attachments/assets/15600b18-f73b-4ba3-a959-47f0048a1ab6" alt="image2" width="50%">


# **Smartlock**

 

**Autor: Marcos Gómez Villafañe**

**Padrón: 105.055**

**Fecha: 2do cuatrimestre 2024**

 

 

 

 

### **1\. Selección del proyecto a implementar**

#### **1.1 Objetivo del proyecto y resultados esperados**

El objetivo de este proyecto es diseñar e implementar un mecanismo de seguridad para monitorear, habilitar o denegar y registrar el acceso de individuos a hogares y/o edificios corporativos. Se tiene como objetivo adicional asegurar que el acceso a la propiedad o sus compartimentos sea lo más fluido y natural posible, promoviendo un acceso rápido, seguro y robusto. Por último, se busca en este proyecto poder incorporar o remover individuos a la base de datos para administrar sus permisos de acceso al edificio o hogar.

#### **1.2 Proyectos similares**

Se consideran tres tipos de proyectos posibles que cumplen con los objetivos y resultados esperados del proyecto, todos basados en acceso mediante cerradura::

1.  Cerradura con RFID, keypad y registro en la nube. 

2. Cerradura con reconocimiento facial y registro en la nube.

3. Cerradura con keypad y registro en la nube.

Para comparar estas alternativas, se tiene en cuenta cuatro aspectos característicos:

1. Disponibilidad del hardware: Se evalúa si el proyecto es fácilmente implementable con hardware disponible en mercados regionales.

2. Facilidad de acceso: Se comprende por facilidad de acceso al tiempo que le llevaría acceder al edificio a un individuo con permiso de acceso.

3. Seguridad: Se comprende por seguridad a la robustez del sistema frente a posibles intentos fraudulentos de acceso.

4. Tiempo de implementación: Tiempo total que llevará diseñar e implementar el proyecto seleccionado.

5. Costo: El costo total del proyecto.

6. Interés personal

Se decide ponderar los aspectos de la siguiente manera del 1 al 10: Disponibilidad del hardware: 10, Facilidad de acceso: 8, Seguridad: 6, Tiempo de implementación: 8, Costo: 5, Interés personal: 8\. 

La disponibilidad del hardware es fundamental ya que para este proyecto no se busca salir del mercado regional y buscar hardware costoso y que tome tiempo en obtener. En otras palabras, la disponibilidad del hardware tiene influencia sobre otros aspectos como el tiempo y el costo, con lo cual es importante encontrar proyectos que se puedan hacer con hardware disponible. La facilidad de acceso es primordial también porque es el punto de venta del proyecto que se quiere llevar a cabo, se busca que el proyecto se diferencie del resto mediante la comodidad en la hora de acceder. La seguridad se elige con ponderación 6 porque si bien se busca algo seguro, existen varias posibilidades que podrían poner en riesgo la seguridad que no dependen del sistema en sí, sino del individuo. Por ejemplo, si a un individuo le roban la llave de la casa entonces pueden robarle la casa. En resumen, mientras que el mecanismo de seguridad sea intrínsecamente seguro, no nos interesa que la seguridad sea analizada bajo escenarios especiales y poco probables. El tiempo de implementación se elige con un valor de 8 dado que se requiere implementar el proyecto en un periodo de tiempo acotado, con baja flexibilidad para cambios o implementaciones que consuman mucho tiempo. Finalmente, el costo no es tan importante dado que, para este proyecto, se busca la mejor solución a cualquier precio, siempre y mientras no sea un precio excesivamente grande.

La siguiente tabla (Tabla 1.2.1) muestra los valores ponderados asignados a cada proyecto considerado

| Proyecto                                | Cerradura con RFID y keypad |         | Cerradura solo con keypad |         | Cerradura con reconocimiento facial |         |
| :-------------------------------------: | :-------------------------: | :-----: | :-----------------------: | :-----: | :---------------------------------: | :-----: |
|                                         | Puntaje                     | Puntaje Ponderado | Puntaje              | Puntaje Ponderado | Puntaje                      | Puntaje Ponderado |
| **Disponibilidad de Hardware** <br> *(peso: 10)* | 10                          | 100     | 10                        | 100     | 4                           | 40      |
| **Facilidad de Acceso** <br> *(peso: 8)*        | 8                           | 64      | 5                         | 40      | 10                          | 80      |
| **Seguridad** <br> *(peso: 6)*                  | 8                           | 48      | 8                         | 48      | 6                           | 36      |
| **Tiempo de Implementación** <br> *(peso: 8)*   | 8                           | 64      | 10                        | 80      | 2                           | 16      |
| **Costo** <br> *(peso: 5)*                      | 8                           | 40      | 8                         | 40      | 6                           | 30      |
| **Interés personal** <br> *(peso: 8)*           | 10                          | 80      | 4                         | 40      | 10                          | 80      |
| **Puntaje Total**                               | -                           | **396** | -                         | **348** | -                           | **282** |

<p align="center"><em>Tabla 1.2.1: Comparación de proyectos</em></p>

#### **1.3 Selección de proyecto**

Considerando la Tabla 1.2.1,  se elige implementar el sistema de acceso con RFID y keypad. El sistema de acceso mediante reconocimiento facial requiere mucho tiempo de implementación y conceptos avanzados de machine learning, lo cual excedería el margen de tiempo que se propone para el proyecto. Adicionalmente, es el más costoso de implementar debido a los requerimientos de una  buena camara con alta definición para poder entrenar la red neuronal con poco ruido. Sufre además de posibles brechas de seguridad intrínseca, dado que la red neuronal puede erróneamente habilitar el acceso a alguien que tiene características faciales similares. Por otro lado, el sistema de acceso mediante únicamente keypad no tiene tanta facilidad de acceso al edificio como el que tiene keypad y RFID, ya que los tags RFID son más rápidos.

Debido a las razones mencionadas anteriormente y a la tabla basada en dichas razones, el proyecto a implementar es un sistema de acceso con una cerradura inteligente que cuenta con un lector RFID y un teclado. La combinación de estos dos sistemas brinda flexibilidad y facilidad de acceso a los usuarios, preservando los estándares de seguridad.

En Argentina, la necesidad de seguridad en hogares y pequeñas empresas motiva la creación de soluciones tecnológicas que no solo sean confiables, sino también accesibles y fáciles de usar. Este proyecto busca una alternativa moderna a las cerraduras tradicionales, brindando flexibilidad y  seguridad simultáneamente. El presente proyecto se destaca especialmente por incorporar un módulo wifi que permite configurar los permisos de acceso de los individuos y un parlante y micrófono. Esto lo diferencia de otros sistemas similares en que permite seleccionar de forma remota los permisos de acceso y visualizar los intentos de acceso de forma remota. Adicionalmente, permite hablar con el individuo a través de los parlantes y micrófonos cuando no puede acceder a la propiedad. Una última característica especial es la presencia de un sensor magnético, el cual indica cuando se deja abierta la puerta accidentalmente.

Los desafíos principales de este proyecto son la integración de las diferentes tecnologías (RFID, teclado matricial, parlante…), la garantía de seguridad de los datos (encriptación para proteger la información), la optimización energética y el eficiente uso de recursos.

###### **1.3.1 Diagrama en bloques**

En la Figura 1.3.1 se muestra el diagrama en bloques del sistema con los principales módulos del proyecto

<p align="center">
  <img src="https://github.com/user-attachments/assets/57fad928-0021-4330-bb8f-daf010a19ebe" alt="image1">
</p>

<p align="center"><em>Figura 1.3.1: Diagrama en bloques del sistema</em></p>


### **2\. Elicitación de requisitos y casos de uso**

En Argentina existen varios productos de características similares a las del proyecto, cada producto diferenciándose de otro con detalles, como por ejemplo huellas digitales, llaves, etc. Sin embargo, parecería que no hay un producto en Argentina que cumpla exactamente la misma función que el proyecto desarrollado.

Como primer competidor del mercado se puede mencionar a [Yale](https://yalehome.com.ar/categoria-producto/cerraduras-digitales/), la cual ofrece una amplia gama de cerraduras digitales inteligentes para seguridad del hogar. Los precios de sus productos orbitan desde los 45.000 hasta los 600.000 pesos y sus productos incluyen desde cerraduras con teclado matricial hasta cerraduras con huellas digitales, todas con una aplicación para el celular. El proyecto tiene similitudes en el teclado matricial y en la aplicación, pero se diferencia en la oferta de los sensores magnéticos, del lector RFID y de la comunicación con parlante y micrófono.

Un segundo competidor es [Philips](https://www.tienda.philips.com.ar/productos-para-el-hogar/smart-lock/cerraduras-inteligentes), la cual tiene productos con reconocimiento facial y video portero. Esta tecnología es considerablemente superior al igual que sus precios, los cuales rondan el 1.000.000 de pesos. Sin embargo, la empresa no cuenta con lectores RFID ni sensores magnéticos, lo cual diferencia a nuestro proyecto.

En resumen, el mercado es sumamente competitivo y las características y funcionalidades de la cerradura pueden ser modificadas y ampliadas fácilmente, permitiendo desarrollar productos únicos y distintos de la competencia que encuentren un lugar en el mercado.

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
|  | 4.2 | El sistema deberá contar con un micrófono para recibir señales de audio |
| Comunicación Wi-Fi | 5.1 | El sistema se comunicará mediante Wi-Fi con la aplicación de celular |
|  | 5.2 | El sistema deberá enviar a la aplicación la información de acceso a la instalación |
|  | 5.3 | El sistema deberá enviar a la aplicación la información de acceso denegado a la instalación |
|  | 5.4 | En caso de lectura RFID, el sistema deberá comunicar la lectura de RFIDs desconocidos, junto con su ID (para poder guardarlo posteriormente) |
|  | 5.4 | El sistema deberá comunicarle a la aplicación el estado de la puerta y el numero de puerta |
|  | 5.5 | El sistema deberá poder recibir señales de audio de la aplicación |
|  | 5.6 | El sistema deberá poder transmitir señales de audio a la aplicación |
| Aplicación | 6.1 | La aplicación tendrá la base de datos de los individuos habilitados con sus IDs |
|  | 6.2 | La aplicación deberá permitirle al usuario configurar los permisos de acceso de los individuos |
|  | 6.3 | La aplicación deberá poder mostrar la información de los accesos e intentos de acceso |
|  | 6.4 | La aplicación deberá poder controlar manualmente la apertura o cerradura de la puerta |
|  | 6.5 | La aplicación deberá permitirle al usuario configurar añadir nuevos individuos a la base de datos mediante codigo o RFID |
|  | 6.6 | La aplicación deberá mostrarle al usuario el estado de la puerta |
| Interruptores/ Botones | 7.1 | El sistema contará con botones para abrir o cerrar la puerta de forma manual |
|  | 7.2 | El sistema contará con un botón de timbre |
| Sensores | 8.1 | El sistema contará con un sensor magnético que detectará cuando la puerta se halla contra el marco |

<p align="center"><em>Tabla 2.1: Requisitos del proyecto</em></p>

En las tablas 2.2 a 2.4 se presentan 3 casos de uso para el sistema.

| Elemento | Definición |
| :---- | :---- |
| Disparador | Se quiere acceder a la instalación con permiso de acceso y con código en el teclado matricial. |
| Precondiciones | El sistema está encendido La puerta está cerrada, con la  cerradura cerrada. La aplicación está conectada al sistema. El indicador de puerta cerrada está encendido  |
| Flujo principal | El individuo introduce su código en el teclado matricial. Por cada tecla que presione recibe una melodía indicando la recepción del carácter introducido. Una vez introducido todo el código, el motor abre la cerradura y se notifica con una melodía el acceso habilitado. Además, con un led se notifica la habilitación del acceso. El módulo wifi comunica a la aplicación el acceso a la instalación, mostrando el estado de la puerta, la identificación del ingresante, la hora y el número de puerta. El individuo cierra la puerta una vez adentro. |
| Flujos alternativos | a. El individuo introduce erróneamente el código, con lo cual se notifica auditiva y visualmente al usuario y se notifica mediante Wi-Fi que se intentó acceder sin permiso a la instalación.  b. El individuo deja de introducir el código a mitad de camino. Luego de un tiempo preestablecido, el código a medias se descarta y se notifica que el intento fue incorrecto tanto al individuo como al propietario mediante Wi-Fi.. c. El individuo olvida la puerta abierta, entonces se suena una “alarma” y se notifica al propietario mediante Wi-Fi d. Un usuario dentro de la instalación presiona el botón de cerrar la puerta antes de que se introduzca el código. La puerta permanece cerrada. e. El usuario acerca su tarjeta en vez de terminar el código. La puerta se abre y se indica que la puerta está abierta. |

<p align="center"><em>Tabla 2.2: Caso de uso 1: El usuario quiere acceder con código</em></p>


| Elemento | Definición |
| :---- | :---- |
| Disparador | Se quiere acceder a la instalación con permiso de acceso y con RFID. |
| Precondiciones | El sistema está encendido La puerta está cerrada, con la  cerradura cerrada. La aplicación está conectada al sistema. El indicador de puerta cerrada está encendido  |
| Flujo principal | El individuo acerca su tarjeta al lector. El ID de la tarjeta es correcto, el motor abre la cerradura y se notifica con una melodía el acceso habilitado. Además, con un led se notifica la habilitación del acceso. El módulo wifi comunica a la aplicación el acceso a la instalación, mostrando el estado de la puerta, la identificación del ingresante, la hora y el número de puerta. El individuo cierra la puerta una vez adentro. |
| Flujos alternativos | a. El individuo usa una tarjeta no habilitada, con lo cual se notifica auditiva y visualmente al usuario y se notifica mediante Wi-Fi que se intentó acceder sin permiso a la instalación.  b. El individuo olvida la puerta abierta, entonces se suena una “alarma” y se notifica al propietario mediante Wi-Fi |

<p align="center"><em>Tabla 2.3: Caso de uso 2: El usuario quiere acceder con RFID</em></p>


| Elemento | Definición |
| :---- | :---- |
| Disparador | Se quiere añadir una nueva tarjeta RFID |
| Precondiciones | El sistema está encendido La puerta está cerrada, con la  cerradura cerrada. La aplicación está conectada al sistema. El indicador de puerta cerrada está encendido |
| Flujo principal | Se acerca una tarjeta desconocida al lector RFID. El sistema indica que el intento de acceso es incorrecto. El sistema muestra el ID de la tarjeta e indica si se quiere guardar la tarjeta mediante comunicación Wi-Fi con la aplicación. |
| Flujos alternativos | a. Se pierde la conexión Wi-Fi. El sistema no puede continuar con el guardado de la tarjeta. Se indica que se perdió la conexión b. Se apaga el sistema. El sistema no puede continuar con el guardado de la tarjeta.  |

<p align="center"><em>Tabla 2.4: Caso de uso 3: El usuario quiere guardar una tarjeta RFID</em></p>


