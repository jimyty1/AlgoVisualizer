import { useEffect, useState } from "react";
import Controller from "./Controller";
import type { AlgorithmEvent } from "../types/algorithm";
import "../App.css";
import { parseEventStream } from "../utils/parseEventStream";
import ArrVisualizer from "./ArrVisualizer";


function Visualizer() {
  const [events, setEvents] = useState<AlgorithmEvent[]>([]);
  const [currentStep, setCurrentStep] = useState(0);
  const [algo, setAlgo] = useState("bubble");
  const [arrayInput, setArrayInput] = useState([64,34,25,12,22,11,90]);

  useEffect(() => {
    fetch("/test", {
      method: "POST",
      headers: {
        "Content-Type": "application/json",
      },
      body: JSON.stringify({
        algorithm: algo,
        array: arrayInput,
      }),
    })
      .then((response) => response.text())
      .then((data) => {
        console.log("Raw output from backend:", data);
        const nextEvents = parseEventStream(data);
        setEvents(nextEvents);
        setCurrentStep((previousStep) =>
          Math.min(previousStep, Math.max(nextEvents.length - 1, 0)),
        );
      })
      .catch((error) => {
        console.error("Error:", error);
        setEvents([]);
        setCurrentStep(0);
      });
  }, [algo, arrayInput]);

  const maxStep = Math.max(events.length - 1, 0);
  const currentEvent = events[currentStep] ?? null;

  return (
    <>
      <h1>Algo Visualizer</h1>

      <h2>Test</h2>
      <select name="algorithm" onChange={(e) => {setAlgo(e.target.value);}}>
        <option value="bubble">Bubble Sort</option>
        <option value="selection">Selection Sort</option>
        <option value="insertion">Insertion Sort</option>
        <option value="merge">Merge Sort</option>
        <option value="quick">Quick Sort</option>
        <option value="heap">Heap Sort</option>
      </select>
      <br/>
      <input name="array" type="text" placeholder="Enter array (comma-separated)" 
      defaultValue="64,34,25,12,22,11,90" 
      onChange={(e) => {setArrayInput(e.target.value.split(",").map(Number));}} />

      <span style={{ marginTop: "1rem", height: "1rem", display: "block" }}/>

      <p>Output:</p>
      <ArrVisualizer currentEvent={currentEvent} />
      <Controller step={currentStep} maxStep={maxStep} onStep={setCurrentStep} />
    </>
  );
}

export default Visualizer;

