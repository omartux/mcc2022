#Generador Aleatorio
#Grupo 3
import random
import csv

archivo = input ('Nombre de archivo?: ')
archivo = archivo+".txt"
inferior = int(input('limite inferior?: '))
superior = int(input('limite superior?: '))
cantidad = int(input('Cuantos elementos desea generar?: '))
# Abre un archivo en modo de escritura "w" 
f = open(archivo, 'w')
# create the csv writer
writer = csv.writer(f)
#Genera numeros entre inferior y superior y en cantidad
randomlist = random.sample(range(inferior, superior), cantidad)
print(randomlist)
# escribe una fila con los numeros generados
writer.writerow(randomlist)
# cierra el archivo
f.close()
