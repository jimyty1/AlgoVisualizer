import type { ControllerProps } from "../types/controllerprops";

export default function Controller({ step, maxStep, onStep }: ControllerProps) {
  const safeStep = Math.min(Math.max(step, 0), Math.max(maxStep, 0));

  const handleStep = (nextStep: number) => {
    const clampedStep = Math.min(Math.max(nextStep, 0), Math.max(maxStep, 0));
    onStep(clampedStep);
  };

  return (
    <div className="controller" style={{ display: 'flex', alignItems: 'center', gap: '0.75rem' }}>
      <button
        type="button"
        onClick={() => handleStep(safeStep - 1)}
        disabled={safeStep <= 0}
      >
        Prev
      </button>

      <input
        type="range"
        min={0}
        max={Math.max(maxStep, 0)}
        value={safeStep}
        onChange={(event) => handleStep(Number(event.target.value))}
        style={{ flex: 1 }}
      />

      <span>
        {safeStep} / {Math.max(maxStep, 0)}
      </span>

      <button
        type="button"
        onClick={() => handleStep(safeStep + 1)}
        disabled={safeStep >= Math.max(maxStep, 0)}
      >
        Next
      </button>
    </div>
  );
}
