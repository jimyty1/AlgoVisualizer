import { useEffect, useState } from "react";
import Controller from "./Controller";
import type { AlgorithmEvent } from "../types/algorithm";
import "../App.css";

function parseEventStream(rawOutput: string): AlgorithmEvent[] {
  return rawOutput
    .split(/\r?\n/)
    .map((line) => line.trim())
    .filter((line) => line.startsWith("{"))
    .flatMap((line) => {
      try {
        const parsed = JSON.parse(line) as Partial<AlgorithmEvent>;

        if (parsed && typeof parsed === "object" && "type" in parsed) {
          return [parsed as AlgorithmEvent];
        }

        return [];
      } catch {
        return [];
      }
    });
}

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

