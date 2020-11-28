const terminalWidth = process.stdout.columns;

let goToxy = (x: number, y: number): void => {
  x = Math.round(x);
  y = Math.round(y);
  process.stdout.write(`\u001b[${y};${x}H`);
};

let centerThis = (text: string): number => {
  let textLen = text.length;

  return (terminalWidth - textLen) / 2;
};

let centerPrint = (text: string, y: number): void => {
  let centerX = centerThis(text);

  goToxy(centerX, y);
  console.log(text);
};

let digitsOf = (value: number): number => {
  return value.toString().length;
};

let alingTable = (array: Array<number>): number => {
  let size = array.length;
  let tableWidth: number;
  let allDigits = 0;

  array.forEach((element) => {
    allDigits += digitsOf(element);
  });
  tableWidth = allDigits + size + 1;

  return (terminalWidth - tableWidth) / 2;
};

function arrayTable(array: Array<number>, height: number): void {
  let i: number, j: number;
  let size = array.length;
  let centerX = alingTable(array);

  goToxy(centerX, height);
  process.stdout.write("┌");
  for (i = 0; i < size; i++) {
    for (j = 0; j < digitsOf(array[i]); j++)
      process.stdout.write("─");
    if (i + 1 < size) process.stdout.write("┬");
  }
  process.stdout.write("┐");

  goToxy(centerX, height + 1);
  process.stdout.write("│");
  array.forEach((element) => {
    process.stdout.write(element.toString());
    process.stdout.write("│");
  });

  goToxy(centerX, height+2);
  process.stdout.write("└");
  for (i = 0; i < size; i++) {
    for (j = 0; j < digitsOf(array[i]); j++)
      process.stdout.write("─");
    if (i + 1 < size) process.stdout.write("┴");
  }
  process.stdout.write("┘");

}

export { centerThis, goToxy, centerPrint, digitsOf, arrayTable };