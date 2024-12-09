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

[2.1.2 Módulo  Wi-Fi](#2.3.2-módulo-wi-fi)

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
| 1.2 |  |  |

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
El sistema Smartlock consta dos subsistemas principales: el sistema montado en la cerradura y el sistema de interfaz virtual para el ususario.

 <img src="https://github.com/user-attachments/assets/46be1b4e-dd71-4adf-a30a-cbd49e53a733" alt="image2" width="40%">

**Figura 1.2.1**: Diagrama en bloques del proyecto *Smartlock*.


El sistema *Smartlock* cuenta con dos métodos de acceso, mediante tarjetas RFID o mediante un pin de identificación. La tarjeta RFID es un identificador pasivo que al acercarse a un lector RFID, éste induce una corriente sobre ella para retransmitir una respuesta al lector. Estas tarjetas tienen un código de identificación unico que puede ocultarse para prevenir filtraciones de seguridad. La Figura 1.2.1 muestra la tarjeta y un lector RFID.

 <img src="https://github.com/user-attachments/assets/46be1b4e-dd71-4adf-a30a-cbd49e53a733" alt="image2" width="40%">
 
**Figura 1.2.2**: Tarjeta RFID y lector RFID.

Por otro lado, el pin se introduce en un teclado matricial de 4x4 caracteres. El largo del pin esta fijo en 4 dígitos pero es modificable. La Figura 1.2.3 muestra el teclado matricial en el que se introducen los códigos de acceso

<img src=https://github.com/user-attachments/assets/67fca740-727b-4869-a861-af216d65048b alt="image2" width="40%">
 
**Figura 1.2.3**: Teclado Matricial.

La interfaz virtual se muestra en al figura

En las próximas secciones se describira con mayor detalle los módulos utilizados y sus características.

# **CAPÍTULO 2** 

# **Introducción específica** 

## **2.1 Requisitos**

En esta sección se recomienda aprovechar lo escrito en el documento “Definición de Requisitos y Casos de Uso del Trabajo Final de 86.65 Sistemas Embebidos” en la sección “2. Elicitación de requisitos y casos de uso”. 

## **2.2 Casos de uso**

En esta sección se recomienda aprovechar lo escrito en el documento “Definición de Requisitos y Casos de Uso del Trabajo Final de 86.65 Sistemas Embebidos” en la sección “2. Elicitación de requisitos y casos de uso”.

## **2.3 Descripción  de tal cosa**

La idea de esta sección es explicar los detalles que el lector debe conocer para entender las decisiones de diseño adoptadas. Son cosas que utilizan pero que ustedes no diseñaron ni implementaron, como por ejemplo una biblioteca de código hecha por otro, o un módulo de hardware, o un protocolo de red, etc.

En el documento “Listado de Trabajos Finales de 86.65 Sistemas Embebidos de la FI-UBA” ([link](https://docs.google.com/spreadsheets/d/1HHX6xDGCmE2Ik0R4_lFpznHdhz-nmtidWsVnde-cacI/edit#gid=0&range=G:G)) se pueden ver muchos ejemplos de cómo escribir esta sección. A modo de ejemplo a continuación se muestra cómo podría ser la presentación de un módulo Wi-Fi (de paso, recordar que Wi-Fi se escribe con guión en el medio).

## **2.3.2 Módulo Wi-Fi** {#2.3.2-módulo-wi-fi}

En el trabajo realizado se empleó el módulo Wi-Fi ESP8266 \[3\], que se muestra en la figura 2.1. El mismo se comunica por puerto serie a la plataforma de desarrollo NUCLEO F429ZI para acceder a los datos y luego en función de esos actualiza la información en una página web. Su elección se basó en...

![][image2] 

**Figura 2.1:** Módulo Wi-Fi

**CAPÍTULO 3** 

# **Diseño e implementación** {#diseño-e-implementación}

## **3.1 Hardware del… (completar)** {#3.1-hardware-del…-(completar)}

Se espera que se incluya un desarrollo similar al presentado en el Example 12-3 del libro. A modo de ejemplo se sugiere considerar la Figura 12.1 y el análisis que se realiza en el libro a partir de ella. Este análisis incluye por ejemplo a las Tablas 12.10 y 12.11 y a la Figura 12.2.

Es deseable encontrar también un diagrama como el de la Figura 12.3 y un conjunto de tablas similar al de las Tablas 12.2 a 12.7. 

También se considera importante incluir una tabla similar a la Tabla 12.8.

En definitiva, la idea de esta sección es resaltar los problemas encontrados, los criterios utilizados y la justificación de las decisiones. 

## **3.2 Firmware del… (completar)** {#3.2-firmware-del…-(completar)}

Se espera que se incluya un desarrollo similar al presentado en el Example 12-4 del libro. A modo de ejemplo se sugiere considerar las Figuras 12.4, 12.5 y 12.6, y el análisis que se realiza en el libro a partir de ellas, lo que incluye por ejemplo una tabla similar a la Tabla 12.19.

A partir de esto sería bueno incluir un detalle similar al presentado en las Tablas 12.20 a 12.32.

También se espera encontrar diagramas de las máquinas de estado en forma similar a la Figura 12.7, junto con la explicación correspondiente, tal como se hace en el libro.

Si se realizó el diseño de pantallas se recomienda incluir el detalle correspondiente, tal como en las Figuras 12.8 a 12.11.

La idea de esta sección es resaltar los problemas encontrados, los criterios utilizados y la justificación de las decisiones.

Es esperable que haya fragmentos del código que sean relevantes. Para eso se recomienda utilizar un formato como el del Código 12.1, con las líneas numeradas y con una explicación en donde se haga uso de la numeración de las líneas. Por ejemplo: “en las líneas 1 a 3 tal cosa, mientras que en las líneas 5 a 9 tal otra”. Es importante que quede claro que no es necesario presentar en este documento todas las líneas de código, sino solamente aquellas que sea de interés explicar por alguna razón en particular.

Finalmente, se recomienda incluir el link al repositorio del proyecto, en el que se espera que haya un archivo Readme.md en el que se incluyan algunos fragmentos de este informe tal que permitan al usuario del repositorio entender en qué consiste el proyecto. Incluso se puede dejar este informe completo como anexo en el repositorio.

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
