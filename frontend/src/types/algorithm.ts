export type AlgorithmEvent =
  | {
      type: "compare";
      i: number;
      j: number;
      array: number[];
    }
    | {
      type: "compareValue";
      i: number;
      value: number;
      array: number[];
    }
    | {
      type: "partition";
      start: number;
      end: number;
      pivot: number;
      boundary: number;
      j: number;
      array: number[];
    }
    | {
      type: "mergeStart";
      start: number;
      mid: number;
      end: number;
      array: number[];
    }
    | {
      type: "mergeCompare";
      left: number;
      right: number;
      start: number;
      mid: number;
      end: number;
      array: number[];
    }
    | {
      type: "pivotPlaced";
      index: number;
      array: number[];
    }
  | {
      type: "swap";
      i: number;
      j: number;
      array: number[];
    }
  | {
      type: "pivot";
      index: number;
      array: number[];
    }
  | {
      type: "overwrite";
      index: number;
      "with value"?: number;
      value?: number;
      array: number[];
    }
  | {
      type: "heapify";
      root: number;
      left: number;
      right: number;
      heapSize: number;
      array: number[];
    }
  | {
      type: "done";
      array: number[];
    };
export function isAlgorithmEvent(value: unknown): value is AlgorithmEvent {
  if (typeof value !== "object" || value === null) {
    return false;
  }
  const event = value as Record<string, unknown>;
  if (typeof event.type !== "string") {
    return false;
  }
  if (
    !Array.isArray(event.array) ||
    !event.array.every((item) => typeof item === "number")
  ) {
    return false;
  }
  switch (event.type) {
    case "compare":
    case "swap":
      return (
        typeof event.i === "number" &&
        typeof event.j === "number"
      );

    case "pivot":
      return typeof event.index === "number";

    case "overwrite":
      return (
        typeof event.index === "number" &&
        (event.value === undefined ||
          typeof event.value === "number") &&
        (event["with value"] === undefined ||
          typeof event["with value"] === "number")
      );

    case "heapify":
      return (
        typeof event.root === "number" &&
        typeof event.left === "number" &&
        typeof event.right === "number" &&
        typeof event.heapSize === "number"
      );

    case "done":
      return true;

    default:
      return false;
  }
}
