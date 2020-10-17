from os import system
system("cls")
print("\t\tVALIDAR FECHA.\n")
fecha = input("Ingrese una fecha: ")
feha_con_formato = fecha.split("-")
dia = int(feha_con_formato[0])
mes = int(feha_con_formato[1])
year = int(feha_con_formato[2])
if not (year>=0 and year<=2021):
    print("Fecha inválida")
    exit(1)

if not (mes>=1 and mes<=12):
    print("Fecha inválida")
    exit(1)

if mes >= 1 and mes <= 7:
    if mes % 2 != 0:
        if not (dia >= 1 and dia <= 31):
            print("Fecha inválida")
            exit(1)
        elif mes % 2 == 0 and mes != 2:
            if not (dia >= 1 and dia <= 30):
                print("Fecha inválida")
                exit(1)

if mes >= 8 and mes <= 12:
    if mes % 2 == 0:
        if not (dia >= 1 and dia <= 31):
            print("Fecha inválida")
            exit(1)
    elif mes % 2 != 0:
        if not (dia >= 1 and dia <= 30):
            print("Fecha inválida")
            exit(1)

if (year % 4 == 0 and (year % 100 != 0 or year % 400 == 0)) and mes == 2:
    if not (dia >= 1 and dia <= 29):
        print("La fecha no es valida")
        input("\nhecho por Orlando Agamez")
        exit(1)
elif mes == 2:
        if not (dia >= 1 and dia <= 28):
            print("La fecha no es valida")
            input("\nhecho por Orlando Agamez")
            exit(1)

print("Fecha Valida")
input("\tSANTIAGO ANDRES DAVID\n")