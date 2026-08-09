import type { AlgorithmEvent } from "../types/algorithm";
import "../css/ArrVisualizer.css";
import { useState } from "react";

export default function ArrVisualizer({events, currentEventIndex, }: {events: AlgorithmEvent[];currentEventIndex: number;})
{
  const currentEvent = events[currentEventIndex] ?? null;
  const [isAnimating, setIsAnimating] = useState(false);

  function getEventDescription(event: AlgorithmEvent) {
    switch (event.type) {
        case "compare":
            return `Comparing positions ${event.i} and ${event.j}`;

        case "compare_value":
            return `Comparing position ${event.i} with ${event.value}`;

        case "swap":
            return `Swapping positions ${event.i} and ${event.j}`;

        case "overwrite":
            return `Writing ${event.with_value} to position ${event.index}`;

        case "pivot":
            return `Selecting ${event.array[event.index]} as pivot`;

        case "pivot_placed":
            return `Pivot placed at position ${event.index}`;

        case "merge_start":
            return `Merging positions ${event.start}–${event.end}`;

        case "merge_compare":
            return `Comparing ${event.left} and ${event.right}`;

        case "heapify":
            return `Heapifying position ${event.root}`;

        case "done":
            return "Sorting complete";
    }
}
  function getElementState(event: AlgorithmEvent | null, index: number) {
    if (!event) {
      return "";
    }

    switch (event.type) {
      case "partition": {
        const classes: string[] = [];
        
        if (index < event.start || index > event.end) {
          classes.push("dimmed");
          return classes.join(" ");
        }
        classes.push("partition_range");

        if (index === event.j) {
          classes.push("j_index");
        }

        if (index === event.boundary) {
          classes.push("boundary");
        }

        if (index === event.pivot) {
          classes.push("pivot");
        }

        return classes.join(" ");
      }

      case "compare":
        if (index === event.i || index === event.j) {
          return "compared";
        }
        break;
      case "compare_value":
        if (index === event.i) {
          return "compare_value";
        }
        break;

      case "swap":
        if (index === event.i || index === event.j) {
          return "swapped";
        }
        break;

      case "pivot":
        if (index === event.index) {
          return "pivot";
        }
        break;

      case "overwrite":
        if (index === event.index) {
          return "overwritten";
        }
        break;

      case "heapify":
        if (
          index === event.root ||
          index === event.left ||
          index === event.right
        ) {
          return "heapified";
        }
        break;

      case "merge_compare":
        if (index === event.left || index === event.right) {
          return "merge_compared";
        }
        break;

      case "merge_start":
        if (index >= event.start && index <= event.end) {
          return "merge_range";
        }

        return "dimmed";

      case "pivot_placed":
        if (index === event.index) {
          return "pivot_placed";
        }
        break;

      case "done":
        return "done";
    }

    return "";
  }

  return (
    <div className="visualArray">
      {currentEvent ? (
        <div className="eventDetails">
          <div className="arrayValues">
            {currentEvent.array.map((value, index) => (
              <span
                key={index}
                className={`arrayValue ${getElementState(currentEvent, index)}`}
              >
                {value}
              </span>
            ))}
          </div>

          <h4>{JSON.stringify(currentEvent, null, 2)}</h4>
        </div>
      ) : (
        <p>No events available.</p>
      )}
    </div>
  );
}
