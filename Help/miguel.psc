Proceso punto_8
	//IVAN DAVID CASTRO BLANCO
	//MIGUEL ANDRES DAZA BRAN
	numero_mayor <- -99999999
	entrada <- 0
	repeticiones <- 0
	i <- 1
	Dimension lista_numeros[200]
	
	Mientras entrada != 999 Hacer
		Si i < 2 Entonces
			Escribir "Ingrese un número: "
		SiNo
			Escribir "Ingrese otro número: "
		Finsi
		Leer entrada
		lista_numeros[i] <- entrada
		i <- i+1
		Si (entrada > numero_mayor) & (entrada != 999) Entonces
			numero_mayor <- entrada
		FinSi
	FinMientras
	
	Para j <- 1 Hasta i Hacer
		Si lista_numeros[j] = numero_mayor Entonces
			repeticiones <- repeticiones+1
		FinSi
	FinPara
	
	Escribir "El número mayor fue el ", numero_mayor
	Escribir "El número se repitió ", repeticiones, " veces"
	
FinProceso
