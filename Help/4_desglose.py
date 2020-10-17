from os import system
system("cls")
print("\t\tDESGLOSE DE DINERO.\n")
dinero = int(input("Ingrese la cantidad de dinero: "))
if not (dinero <= 99500 and dinero >= 100): exit(1)
billetes_50 = dinero // 50000; resto_50 = dinero - billetes_50*50000
billetes_20 = resto_50 // 20000; resto_20 = resto_50 - billetes_20*20000
billetes_10 = resto_20 // 10000; resto_10 = resto_20 - billetes_10*10000
billetes_5 = resto_10 // 5000; resto_5 = resto_10 - billetes_5*5000
billetes_2 = resto_5 // 2000; resto_2 = resto_5 - billetes_2*2000
billetes_1 = resto_2 // 1000; resto_1 = resto_2 - billetes_1*1000
monedas_500 = resto_1 // 500; resto_500 = resto_1 - monedas_500*500
monedas_200 = resto_500 // 200; resto_200 = resto_500 - monedas_200*200
monedas_100 = resto_200 // 100;

if billetes_50 > 0:
    print(billetes_50, "DE 50")
if billetes_20 > 0:
    print(billetes_20, "DE 20")
if billetes_10 > 0:
    print(billetes_10, "DE 10")
