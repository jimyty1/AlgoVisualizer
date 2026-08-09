import type { AlgorithmEvent } from "../types/algorithm";
import "../css/ArrVisualizer.css";
import { useState } from "react";
import { getEventDescription } from "../utils/getEventDescription";
import { getElementState } from "../utils/getElementState";

export default function ArrVisualizer({events, currentEventIndex, }: {events: AlgorithmEvent[];currentEventIndex: number;})
{
  const currentEvent = events[currentEventIndex] ?? null;
  const maxValue = currentEvent
    ? Math.max(...currentEvent.array): 1;

  
  return (
    <div className="visualArray">
      {currentEvent ? (
        <div className="eventDetails">
          <div className="arrayValues">
    {currentEvent.array.map((value, index) => {
        const barHeight = (value / maxValue) * 300;

        return (
            <div
                key={index}
                className={`arrayElement ${getElementState(
                    currentEvent,
                    index
                )}`}
            >
                <div
                    className="arrayBar"
                    style={{
                        height: `${barHeight}px`,
                    }}
                />

                <div className="arrayValue">
                    {value}
                </div>

                <div className="arrayIndex">
                    {index}
                </div>
            </div>
        );
    })}
</div>

          <h4>{JSON.stringify(currentEvent, null, 2)}</h4>
           <h4>{getEventDescription(currentEvent)}</h4>
        </div>
      ) : (
        <p>No events available.</p>
      )}
    </div>
  );
}
