# Development Guide

This guide covers how to build, simulate, and contribute to the project.

## Prerequisites

- Python 3.8+
- Verilator
- Cocotb
- Make
- MkDocs + Material theme (for documentation)

## Install Python Dependencies

```bash
pip install -r requirements.txt
```

## Build Documentation

```bash
mkdocs build
```

To preview locally:

```bash
mkdocs serve
```

## Run Simulation

```bash
cd sim
make
```

## Run Lint

```bash
cd sim
make lint
```

## Contributing

1. Fork the repository.
2. Create a feature branch.
3. Add or update tests for RTL changes.
4. Update documentation under `docs/`.
5. Submit a pull request.

## Continuous Integration

GitHub Actions workflows are provided for:

- Documentation deployment to GitHub Pages (`.github/workflows/docs.yml`)
