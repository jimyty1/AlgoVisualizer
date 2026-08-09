import type { AlgorithmEvent } from "../types/algorithm";

export function getEventDescription(event: AlgorithmEvent): string {
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

        case "partition":
            return `Partitioning positions ${event.start} to ${event.end}`;

        case "merge_start":
            return `Merging positions ${event.start} to ${event.end}`;

        case "merge_compare":
            return `Comparing positions ${event.left} and ${event.right}`;

        case "heapify":
            return `Heapifying position ${event.root}`;

        case "done":
            return "Sorting complete";
    }
}