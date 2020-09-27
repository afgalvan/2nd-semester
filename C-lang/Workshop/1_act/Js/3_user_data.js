const prompt = require('prompt-sync')();
const burgos = require('./burgos.js');


function printHeader()
{
   console.clear();
   burgos.centerPrint('UNIVERSIDAD POPULAR DEL CESAR.', 4);
   burgos.centerPrint('PROGRAMA DE INGENIERIA DE SISTEMAS.', 5);
}

function getInformation(question, data, type, y)
{
   let isValid;
   do
   {
      burgos.gotoxy(1, y);
      data = prompt(question);
      
      if (type == 'n')
         isValid = /^\d+$/.test(data);
      else if (type == 'l')
         isValid = /^[A-Za-z]+$/.test(data);
      
      burgos.gotoxy(1, y+1);
      console.log('Error. Valores inválidos.');
   } while ((type == 'l' && !isValid) || (type == 'n' && !isValid));
   burgos.gotoxy(1, y+1); console.log('                                 ');
} 

function menu()
{
   let personID, name, address, phoneNumber, genre, civilState; 
   
   printHeader();
   getInformation('CEDULA      : ', personID, 'n', 7);
   getInformation('NOMBRE      : ', name, 'l', 8);
   getInformation('DIRECCION   : ', address, 'a', 9);
   getInformation('TELEFONO    : ', phoneNumber, 'n', 10);
   getInformation('SEXO M/F    : ', genre, 'l', 11);
   getInformation('EST. CIVIL  : ', civilState, 'l', 12);
   
}

function main()
{
   menu();
}

main();
