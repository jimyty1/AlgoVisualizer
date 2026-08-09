export type ControllerProps = {
  step: number;
  maxStep: number;
  onStep: (step: number) => void;
};