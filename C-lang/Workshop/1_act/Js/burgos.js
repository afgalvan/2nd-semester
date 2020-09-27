const prompt = require('prompt-sync')();

const gotoxy = function(x, y)
{
   process.stdout.write(`\u001b[${y};${x}H`);   
}

const centerThis = function(text)
{
   let width = process.stdout.columns;
   let textLen = text.length;
   
   centered = (width - textLen) / 2;
   return centered;
}

const centerPrint = function(text, height)
{
   let centered;
   centered = centerThis(text);
   gotoxy(centered, height);
   console.log(text);
}

const detectOS = function()
{
   if (process.platform == 'win32') return 'Windows';
   if (process.platform == 'darwin') return 'MacOS';
   if (process.platform == 'linux') return 'Linux';
   return 'Unknown';
}

const repeatProgram = function(mainFuction, height)
{
   let choice;
   const separator = '-----------------------------';
   xPosition = centerThis(separator) ;
   
   gotoxy(xPosition, height); console.log(separator);
   height++;
   centerPrint('¿Desea repetir el programa?', height);
   height++;
   gotoxy(xPosition+1, height); console.log('[1] SI.');
   height++;
   gotoxy(xPosition+1, height); console.log('[2] NO.');
   height -= 3;
   
   choice = prompt('');
   if (choice == '1') mainFuction();
   else if (choice == '2') return 0;
   else repeatProgram(mainFuction, height);
}

module.exports = {
   gotoxy, centerPrint, centerThis, detectOS, repeatProgram
}
