const { spawn } = require('node:child_process');

const child = spawn('./main', [
  'quick',
  '12',
  '42',
  '3',
  '34',
  '75',
  '26',
  '7',
  '18',
  '19',
  '10'
]);

console.log('Child process started with PID:', child.pid);

child.stdout.on('data', (data: Buffer) => {
  console.log(`Child process output: ${data.toString()}`);
});
