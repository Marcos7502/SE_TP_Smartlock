

**UNIVERSIDAD DE BUENOS AIRES**  
**Facultad de Ingeniería**  
**86.65 Sistemas Embebidos**

Memoria del Trabajo Final:

**Acá va el título del trabajo en este formato**

**Autor:**

**Sr. Marcos Gómez Villafañe**

Legajo: 105.055 

*Este trabajo fue realizado en las Ciudad Autónoma de Buenos Aires,*   
*entre Agosto y Diciembre de 2024\.*

**RESUMEN**

Acá va el resumen del trabajo. Debe ser lo más breve posible. No más de dos o tres párrafos, de unas cuatro o cinco oraciones cada uno. Leyendo esto debe quedar muy claro en qué consiste el trabajo realizado, por qué el trabajo es importante, por qué el trabajo muestra que el estudiante aplicó correctamente lo aprendido en la Carrera y qué información va a encontrar el lector en esta Memoria.

No usar en este resumen ninguna referencia bibliográfica del tipo \[1\], ni tampoco notas a pie de página ni siglas que no estén aclaradas como parte de este texto, ni tipografía en negritas, subrayada o cursiva. Dicho de otra forma, el texto en este resumen debe ser escrito de forma tal que si se recorta el mismo y se lo pega en un archivo .txt entonces este conserve su formato y sea perfectamente entendible sin ningún agregado adicional, es decir, quede autocontenido.

**ABSTRACT (resumen en inglés, es opcional)**

Quien lo desee puede poner en esta sección una traducción al idioma inglés del resumen presentado en la página anterior. Si no ponen un abstract en inglés, entonces borrar esta página.

**Agradecimientos (esta sección es opcional)**

Acá van los agradecimientos, que es la parte más personal de la memoria.

# 

# 

**Índice General**

[**Índice de figuras (esta sección es opcional)**](#índice-de-figuras-\(esta-sección-es-opcional\))	**[7](#índice-de-figuras-\(esta-sección-es-opcional\))**

[**Índice de tablas (esta sección es opcional)**](#índice-de-tablas-\(esta-sección-es-opcional\))	**[8](#índice-de-tablas-\(esta-sección-es-opcional\))**

[**Registro de versiones**](#registro-de-versiones)	**[9](#registro-de-versiones)**

[**Introducción general**](#introducción-general)	**[10](#introducción-general)**

[1.1 Título de la sección con este uso de las mayúsculas](#1.1-título-de-la-sección-con-este-uso-de-las-mayúsculas)	[10](#1.1-título-de-la-sección-con-este-uso-de-las-mayúsculas)

[1.1.1 Este es el título de una subsección](#1.1.1-este-es-el-título-de-una-subsección)	[10](#1.1.1-este-es-el-título-de-una-subsección)

[1.2 Figuras y tablas](#1.2-figuras-y-tablas)	[11](#1.2-figuras-y-tablas)

[1.3 Ecuaciones](#1.3-ecuaciones)	[13](#1.3-ecuaciones)

[1.4 “Trabajo vs. Proyecto” y tiempo verbal a utilizar](#1.4-trabajo-vs.-proyecto-y-tiempo-verbal-a-utilizar)	[13](#1.4-trabajo-vs.-proyecto-y-tiempo-verbal-a-utilizar)

[1.5 Estado del arte o análisis de sistemas similares al desarrollado](#1.6-estado-del-arte-o-análisis-de-sistemas-similares-al-desarrollado)	[14](#1.6-estado-del-arte-o-análisis-de-sistemas-similares-al-desarrollado)

[**Introducción específica**](#introducción-específica)	**[15](#introducción-específica)**

[2.1 Descripción  de tal cosa](#heading=h.qt52d4use48v)	[15](#heading=h.qt52d4use48v)

[2.1.2 Módulo  Wi-Fi](#2.3.2-módulo-wi-fi)	[15](#2.3.2-módulo-wi-fi)

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

[**Bibliografía**](#bibliografía)	**[19](#bibliografía)**

[**Anexos (sólo en caso de ser necesarios)**](#anexos-\(sólo-en-caso-de-ser-necesarios\))	**[20](#anexos-\(sólo-en-caso-de-ser-necesarios\))**

[A. Primer Anexo](#a.-primer-anexo)	[20](#a.-primer-anexo)

# **Índice de figuras (esta sección es opcional)** {#índice-de-figuras-(esta-sección-es-opcional)}

# 

# **Índice de tablas (esta sección es opcional)** {#índice-de-tablas-(esta-sección-es-opcional)}

# 

# **Registro de versiones**  {#registro-de-versiones}

| Revisión | Cambios realizados | Fecha |
| :---: | ----- | ----- |
| 1.0 | Creación del documento |  |
| 1.1 |  |  |
| 1.2 |  |  |

### 

**CAPÍTULO 1** 

# **Introducción general** {#introducción-general}

## **1.1 Título de la sección con este uso de las mayúsculas** {#1.1-título-de-la-sección-con-este-uso-de-las-mayúsculas}

La idea de esta sección es presentar el tema de modo que cualquier persona que no conoce el tema pueda entender de qué se trata y por qué es importante realizar este trabajo y cuál es su impacto. 

Se recomienda reutilizar partes de lo escrito previamente en la sección 1 del documento “Definición de Requisitos y Casos de Uso del Trabajo Final de 86.65 Sistemas Embebidos”. En particular se recomienda reutilizar lo escrito en la sección 1\. Selección del proyecto a implementar, en lo que se refiere a “En relación con el proyecto que resulte seleccionado sería deseable que quede claro de qué se trata el proyecto y cuáles son sus desafíos, su motivación y su importancia.” 

También se recomienda aprovechar lo escrito en relación a “Se debe destacar claramente cuál es el valor que agrega el proyecto a realizar. Por ejemplo escribir: “El presente proyecto se destaca especialmente por incorporar tal cosa… Esto lo diferencia de otros sistemas similares en que ...””

Además se puede incluir como parte de este Capítulo 1 lo que se haya escrito en ese documento en relación a “Se debe incluir al menos un diagrama en bloques del sistema”. En todo caso la idea es incluir acá un diagrama en bloques general, que sirva a los fines de explicar la idea general, y luego en todo caso en el Capítulo 3, Diseño e implementación, de este documento incluir un diagrama más detallado si fuera necesario.

Si en el texto se hace alusión a diferentes partes del trabajo entonces referirse a ellas como Capítulo, Sección o subsección según corresponda. Por ejemplo: “En el Capítulo 1 se explica tal cosa”, o “En la Sección 1.1 se presenta lo que sea”, o “En la la subsección 1.1.1 se discute otra cosa”.

Entre párrafos sucesivos dejar un espacio, como el que se observa entre este párrafo y el anterior. Pero las oraciones de un mismo párrafo van en forma consecutiva, como se observa acá. Luego, cuando se quiere poner una lista tabulada se hace así:

* Este es el primer elemento de la lista.  
* Este es el segundo elemento de la lista.  
* Notar el uso de las mayúsculas y el punto al final de cada elemento.

Si se desea poner una lista numerada el formato es este:

1. Este es el primer elemento de la lista.  
2. Este es el segundo elemento de la lista.  
3. Notar el uso de las mayúsculas y el punto al final de cada elemento.

### **1.1.1 Este es el título de una subsección** {#1.1.1-este-es-el-título-de-una-subsección}

Se recomienda no utilizar **texto en negritas** en ningún párrafo, ni tampoco texto subrayado. En cambio sí se sugiere utilizar *texto en itálicas* donde se considere apropiado, por ejemplo para palabras en idioma inglés.

Se sugiere que la escritura sea impersonal. Por ejemplo, no utilizar “el diseño del firmware lo hice de acuerdo con tal principio”, sino “el firmware fue diseñado utilizando tal principio”. En lo posible hablar en tiempo pasado, ya que la memoria describe un trabajo que ya fue realizado. Y emplear oraciones cortas y bien concretas.

Se recomienda no utilizar una sección de glosario sino colocar la descripción de las abreviaturas como parte del mismo cuerpo del texto. Por ejemplo, RTOS (*Real Time Operating System*, Sistema Operativo de Tiempo Real) o en caso de considerarlo apropiado mediante notas a pie de página[^1].

Si se desea indicar alguna página web utilizar el siguiente formato de referencias bibliográficas, dónde las referencias se detallan en la sección de bibliografía de la memoria, utilizado el formato establecido por IEEE en \[1\]. Por ejemplo, “el presente trabajo se basa en la plataforma EDU-CIAA-NXP, la cual se describe en detalle en \[2\]”. 

## **1.2 Figuras y tablas** {#1.2-figuras-y-tablas}

Al insertar figuras en la memoria se deben considerar determinadas pautas. Para empezar, usar siempre tipografía claramente legible. Luego, tener claro que es incorrecto escribir por ejemplo esto: “El diseño elegido es un cuadrado,  como se ve en la siguiente figura:”

La forma correcta de utilizar una figura es la siguiente: “Se eligió utilizar un cuadrado azul para el logo, el cual se ilustra en la figura 1.1”.

**Figura 1.1:** Ilustración del cuadrado azul que se eligió para el diseño del logo.

El texto de las figuras debe estar siempre en español, excepto que se decida reproducir una figura original tomada de alguna referencia. En ese caso la referencia de la cual se tomó la figura debe ser indicada en el epígrafe de la figura e incluida como una nota al pie, como se ilustra en la figura 1.2.

**Figura 1.2:** Imagen  ilustrativa de tal cosa, tomada de la página oficial del fabricante del procesador[^2].

La figura y el epígrafe deben conformar una unidad cuyo significado principal pueda ser comprendido por el lector sin necesidad de leer el cuerpo central de la memoria. Para eso es necesario que el epígrafe sea todo lo detallado que corresponda y si en la figura se utilizan abreviaturas entonces aclarar su significado en el epígrafe o en la misma figura.

**Figura 1.3:** El lector no sabe por qué de pronto aparece esta figura.

Nunca colocar una figura en el documento antes de hacer la primera referencia a ella, como se ilustra con la figura 1.3,  porque sino el lector no comprenderá por qué de pronto aparece la figura en el documento, lo que distraerá su atención.

Para las tablas utilizar el mismo formato que para las figuras, sólo que el epígrafe se debe colocar arriba de la tabla, como se ilustra en la tabla 1.1. Observar que sólo algunas filas van con líneas visibles y notar el uso de las negritas para los encabezados.

**Tabla 1.1:** Resumen de los primeros dos campeonatos mundiales de fútbol 

| Año | Sede | Campeón |
| :---- | :---- | :---- |
| 1930 | Uruguay | Uruguay |
| 1934 | Italia | Italia |

En cada capítulo se debe reiniciar el número de conteo de las figuras y las tablas, por ejemplo, Fig. 2.1 o Tabla 2.1, pero no se debe reiniciar el conteo en cada sección. 

## **1.3 Ecuaciones** {#1.3-ecuaciones}

Al insertar ecuaciones en la memoria estas se deben numerar de la siguiente forma:

xy                                                                        (1.1)

Es importante tener presente que en el caso de las ecuaciones estas pueden ser referidas por su número, como por ejemplo “tal como describe la ecuación (1.1)”, pero también es correcto utilizar los dos puntos, como por ejemplo “la expresión matemática que describe este comportamiento es la siguiente:”

xy                                                                        (1.2)

Para las ecuaciones se debe utilizar un tamaño de letra equivalente al utilizado para el texto del trabajo, en tipografía cursiva y preferentemente del tipo Times New Roman o similar. El espaciado antes y después de cada ecuación es de aproximadamente el doble que entre párrafos consecutivos del cuerpo principal del texto.

## **1.4 Trabajo vs. proyecto y tiempo verbal a utilizar** {#1.4-trabajo-vs.-proyecto-y-tiempo-verbal-a-utilizar}

Cuando en la planificación se habló de algo que todavía no estaba hecho nos referimos a eso como "el proyecto". En cambio, en este informe, como ya finalizó el desarrollo, para referinos a lo que se hizo hablamos en términos de "el trabajo". 

Para hacer la descripción utilizamos en general tiempo pasado, porque nos referimos a algo que ya se hizo. Por ejemplo, decimos "se utilizó la placa EDU-CIAA". 

Para describir que se incluye en tal capítulo o sección se usa tiempo presente, porque es lo que está en ese lugar al momento en que el lector lo está leyendo. 

## **1.5 Magnitudes y unidades**

En español las magnitudes se deben escribir de la siguiente forma: 20,5 cm, 41,7 °C, 2,4 GHz, 3,3 V, 20 mA, 60 km/h, etc. Es decir, se debe utilizar la coma como separador decimal, se debe dejar espacio entre la magnitud y las unidades, y se debe respetar el hecho de que algunos prefijos del sistema internacional se escriben en minúsculas (por ejemplo, k, m, µ, n, p) y otros en mayúsculas (por ejemplo, M, G).

## **1.6 Estado del arte o análisis de sistemas similares al desarrollado** {#1.6-estado-del-arte-o-análisis-de-sistemas-similares-al-desarrollado}

En el Capítulo 1 es recomendable incluir una sección que podría llamarse “Análisis del estado del arte” o quizás más sencillo “Análisis de sistemas similares al desarrollado”. De esa forma el lector entiende mejor el contexto en el cual se hace el desarrollo. 

Se recomienda aprovechar acá lo escrito en la sección “2. Elicitación de requisitos y casos de uso” del documento “Definición de Requisitos y Casos de Uso del Trabajo Final de 86.65 Sistemas Embebidos” en lo referido a “Se espera que se presente una tabla con el análisis de productos disponibles en el mercado similar a la Tabla 12.5, y una discusión respecto a las principales características de esos productos. Agregar un link a cada uno de los productos disponibles en el mercado que se analicen.”

En el Capítulo 4 podría agregarse una sección “Comparación con sistemas similares”. Así el lector podría entender qué ventajas y desventajas presenta el trabajo realizado respecto a los sistemas similares tomados como referencia. No se recomienda poner en el Capítulo 1 esta comparación con sistemas similares ya que el Capítulo 1 se escribe como si el sistema aún no estuviera implementado.

**CAPÍTULO 2** 

# **Introducción específica** {#introducción-específica}

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
