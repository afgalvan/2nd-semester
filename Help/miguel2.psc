Algoritmo punto_7
	//PUNTO 7: Un entrenador le ha propuesto a un atleta recorrer
	//una ruta de cinco kilómetros durante 10 días, para determinar si 
	//es apto para la prueba de 5 Kilómetros o debe buscar otra especialidad.
	//Para considerarlo apto debe cumplir por lo menos una de las siguientes condiciones:
	//
	//•	Que en ninguna de las pruebas haga un tiempo mayor a 16 minutos. 
	//•	Que al menos en una de las pruebas realice un tiempo menor a 10 minutos.   
	//•	Que su promedio de tiempos sea menor o igual a 15 minuto
	//IVAN DAVID CASTRO BLANCO
	//MIGUEL ANDRES DAZA BRAN
	dias <- 10
	promedio <- 0
	Dimension tiempos[10]
	
	Para i <- 1 Hasta dias Hacer
		Escribir "Tiempo en el transcurrido en el día ", i ": "
		Leer tiempos[i]
	FinPara
	
FinAlgoritmo
