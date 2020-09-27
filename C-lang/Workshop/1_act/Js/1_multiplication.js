/* 1) Recibir por teclado un numero entero entre 1 y 12 .
Generar y mostrar por pantalla la tabla de multiplicar
de dicho número.

a) Realizar solo operaciones de productos
b) Realizar solo operaciones de sumas . */
const burgos = require('./burgos.js');
const prompt = require('prompt-sync')();

function printHeader()
{
   console.clear();
   burgos.centerPrint('TABLA DE MULTIPLICAR.', 4);
}

function askNumber()
{
   // let centerPosition;
   let isNumeric;
   let number;
   const query = 'Digite el número a calcular: '

   burgos.centerPrint('EL VALOR DEBE ESTAR ENTRE 1 Y 12.', 5);
   do
   {
      isInvalid = false;
      // centerPosition = burgos.centerThis(query);
      burgos.gotoxy(1, 7);number = prompt(query);
      isNumeric = /^\d+$/.test(number);
      burgos.centerPrint('Error. Sólo ingrese números entre 1 - 12.', 10);
   } while(!isNumeric || number > 12 || number < 1);
   burgos.centerPrint('                                               ', 10);
   
   generateTable(parseInt(number));
}

function generateTable(n)
{
   let i, product, indent;
   console.clear();
   burgos.centerPrint(`TABLA DE MULTIPLICAR DEL ${n}.`, 4);
   indent = burgos.centerThis('a x b = c');
   for (i = 1; i <= 12; i++)
   {
      product = i * n;
      if (i == 10) indent--;
      burgos.gotoxy(indent, i+6);
      console.log(`${i} x ${n} = ${product}`)
   }
}

function main()
{
   printHeader();
   askNumber();
   burgos.repeatProgram(main, 22);
}

main();
