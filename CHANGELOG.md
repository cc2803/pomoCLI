# Changelog

All notable changes to this project are documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.1.0/).

## [Unreleased]

## [0.1.0] - 2026-11-08

### Added

- Interactive prompts for work duration, break duration, and cycle count.
- In-place terminal countdown (`mm:ss`, zero-padded), redrawn once per second.
- Terminal bell plus a bordered banner announcing the end of each work/break session.
- Repeating work/break cycle for a requested number of iterations.
- `Session`/`Timer` architecture: `Session` owns the work/break/cycle structure and orchestrates it; `Timer` runs a single, structure-agnostic countdown.
- CMake build configuration alongside a plain `g++` fallback.
