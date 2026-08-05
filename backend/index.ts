import express, { type Express, type Request, type Response } from 'express';

const app: Express = express();
const port = 3000;

app.get('/', (req: Request, res: Response) => {
  res.send('Hello World!');
});
app.get('/test', (req: Request, res: Response) => {
  res.send();
});

app.listen(port, () => {
  console.log(`Example app listening on port ${port}`);
});