import { useEffect, useState } from "react";
import "./App.css";

function App() {
  const [output, setOutput] = useState("");

  useEffect(() => {
    fetch("/test", {
      method: "POST",
      headers: {
        "Content-Type": "application/json",
      },
      body: JSON.stringify({
        algorithm: "quick",
        array: [64, 34, 25, 12, 22, 11, 90],
      }),
    })
      .then((response) => response.text())
      .then((data) => {
        console.log(data);
        setOutput(data);
      })
      .catch((error) => {
        console.error("Error:", error);
        setOutput("Error connecting to backend");
      });
  }, []);

  return (
    <>
      <h1>Algo Visualizer</h1>

      <h2>Test</h2>

      <p>Output:</p>

      <pre>{output}</pre>
    </>
  );
}

export default App;

