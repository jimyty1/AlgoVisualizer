import type { AlgorithmEvent } from "../types/algorithm";
import "../css/ArrVisualizer.css";

export default function ArrVisualizer({ currentEvent }: { currentEvent: AlgorithmEvent | null }) {

    function getElementState(event: AlgorithmEvent | null, index: number) {
    if (!event) {
        return "";
    }

    switch (event.type) {
        case "compare":
            if (index === event.i || index === event.j) {
                return "compared";
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
            break;

        case "partition":
            if (index === event.pivot) {
                return "pivot";
            }

            if (index === event.boundary) {
                return "boundary";
            }

            if (index === event.j) {
                return "j_index";
            }

            break;

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
                <span key={index} 
                className={"arrayValue "+ getElementState(currentEvent, index)}>
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

