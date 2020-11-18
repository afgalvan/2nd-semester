const burgos = require('./burgos.js');
const prompt = require('prompt-sync')();

function printHeader(currentNumber)
{
   console.clear();
   burgos.centerPrint(`TABLA DE MULTIPLICAR DEL ${currentNumber}.`, 4);
}

function showTable(n)
{
   let i, product, line = 6;
   let indent = burgos.centerThis('a x b = c');

   printHeader(n);
   for (i = 1; i <= 12; i++)
   {
      product = i * n;
      if (i == 10) indent--;
      burgos.gotoxy(indent, i+line);
      console.log(`${i} x ${n} = ${product}`);
   }

}

function keepShowing()
{
   let number = 1;
   let choice = 's';

   while (number <= 12 && choice == 's')
   {
      showTable(number);
      number ++;
      do
      {
         burgos.centerPrint('¿Desea continuar? S/N', 20);
         choice = prompt('');
         choice = choice.toLowerCase();
      } while (choice != 's' && choice != 'n')
   }
}

function main()
{
   keepShowing();
}

main();
