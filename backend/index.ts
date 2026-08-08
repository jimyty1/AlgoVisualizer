import express, { type Express, type Request, type Response } from 'express';
import { spawn } from 'child_process';

const app: Express = express();
const port = 3000;
app.use(express.json());

app.get('/', (req: Request, res: Response) => {
  res.send('Hello World!');
});
app.post('/test', (req: Request, res: Response) => {
    const { algorithm, array } = req.body;

    const child = spawn('./main', [
        algorithm,
        ...array.map(String)
    ]);

    let output = '';

    child.stdout.on('data', (data: Buffer) => {
        output += data.toString();
    });

    child.stderr.on('data', (data: Buffer) => {
        console.error(data.toString());
    });

    child.on('close', (code) => {
        console.log('C program exited with:', code);
        res.send(output);
    });
});
app.listen(port, () => {
  console.log(`Example app listening on port ${port}`);
});