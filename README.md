# Proyecto III - Sistemas Operativos Avanzados

## Aventuras en Threadville

### Descripción:
En este proyecto se considerará un manejo no trivial de threads y concurrencia. Toda la programación debe realizarse en C sobre Linux, utilizando la biblioteca Pthreads para el manejo de hilos de ejecución.

### Requerimientos:
Para poder utilizar este proyecto de simulación usted debe contar con una versión de GNU/Linux (Nativo de preferencia) y debe instalar las siguientes bibliotecas:
1. ```sudo apt-get update```
2. ```sudo apt-get install build-essential```
3. ```sudo apt-get install libgtk-3-dev```
4. ```pkg-config --cflags gtk+-3.0```
5. ```sudo apt-get install make```

### ¿Cómo usar el programa?
Para poder excutar el programa primero debe compilarlo, haciendo uso de la herramienta make vaya al direcctorio del programa.
```cd ~/SOA_P3 ```
Y ejecute: ```make``` cuando se haya finalizado la compilación usted podrá encontrar en la carpeta ```build``` un archivo listo para ejecutar hágalo desde la misma carpeta raíz con el siguiente comando: ``./build/simulacion.o``