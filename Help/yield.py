"""
19) Leer una fecha (día, mes, year) y decir si es correcta o no.
Tener en cuenta Febrero y el calculo de bisiesto. Rango de years (0-2021),
meses ( 1-12) y días (1-28, 1-29, 1-30, 1-31).
"""
from platform import system
from subprocess import call
OS = system()
if OS.upper() == "LINUX":
    call("clear")
elif OS.lower() == "windows":
    call("cls", shell=True)

print("\t\tVALIDAR FECHA.\n")
fecha = input("Ingrese una fecha: ")
feha_con_formato = fecha.split("-")
# ["01", "04", "2016"]
dia = int(feha_con_formato[0])
mes = int(feha_con_formato[1])
year = int(feha_con_formato[2])

if not year>=0 and year<=2021:
    print("Fecha inválida")
    exit(1)

if not mes>=1 and mes<=12:
    print("Fecha inválida")
    exit(1)
    
if not year>=0 and year<=2021:
    print("Fecha inválida")
    exit(1)
    
if mes >= 1 and mes < 8:
    if mes % 2 != 0:
        if not dia >= 1 and dia <= 31:
            print("Fecha inválida")
            exit(1)
    elif mes % 2 == 0 and mes != 2:
        if not dia >= 1 and dia <= 30:
            print("Fecha inválida")
            exit(1)
if mes >= 8 and mes < 12:
    if mes % 2 == 0:
        if not dia >= 1 and dia <= 31:
            print("Fecha inválida")
            exit(1)
    elif mes % 2 != 0:
        if not dia >= 1 and dia <= 30:
            print("Fecha inválida")
            exit(1)

if (year % 4 == 0 and (year % 100 != 0 or year % 400 == 0)):
    if mes == 2:
        if not dia >= 1 and dia <= 29:
            print("Fecha inválida")
            exit(1)
else:
    if mes == 2:
        if not dia >= 1 and dia <= 28:
            print("Fecha inválida")
            exit(1)

print("Fecha Valida")
