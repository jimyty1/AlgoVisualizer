export type AlgorithmEvent =
  | {
      type: "compare";
      i: number;
      j: number;
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
