import { useEffect, useState } from "react";
import Controller from "./Controller";
import type { AlgorithmEvent } from "../types/algorithm";
import "../App.css";
import { parseEventStream } from "../utils/parseEventStream";


function Visualizer() {
  const [events, setEvents] = useState<AlgorithmEvent[]>([]);
  const [currentStep, setCurrentStep] = useState(0);

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
  }, []);

  const maxStep = Math.max(events.length - 1, 0);
  const currentEvent = events[currentStep] ?? null;

  return (
    <>
      <h1>Algo Visualizer</h1>

      <h2>Test</h2>

      <Controller step={currentStep} maxStep={maxStep} onStep={setCurrentStep} />

      <p>Output:</p>

      {currentEvent ? (
        <pre>{JSON.stringify(currentEvent, null, 2)}</pre>
      ) : (
        <p>No events available.</p>
      )}
    </>
  );
}

export default Visualizer;

