import type { AlgorithmEvent } from "../types/algorithm";
import { isAlgorithmEvent } from "../types/algorithm";
export function parseEventStream(rawOutput: string): AlgorithmEvent[] {
  return rawOutput
    .split(/\r?\n/)
    .map((line) => line.trim())
    .filter((line) => line.startsWith("{"))
    .flatMap((line) => {
      try {
        const parsed = JSON.parse(line);

        if (isAlgorithmEvent(parsed)) {
          return [parsed];
        }

        return [];
      } catch {
        return [];
      }
    });
}