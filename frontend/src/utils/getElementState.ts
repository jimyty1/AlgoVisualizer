import type { AlgorithmEvent } from "../types/algorithm";

export function getElementState(event: AlgorithmEvent | null, index: number) {
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
