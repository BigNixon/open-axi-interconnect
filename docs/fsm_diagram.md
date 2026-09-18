# AXI4-Lite Transaction State Machines

## Write Transaction (Single Master)

```
        +-------+
        | IDLE  |
        +---+---+
            |
            | AWVALID && WVALID
            v
    +---------------+
    | WAIT AWREADY  |------------------+
    +---------------+                  |
            |                        |
            | AWREADY                |
            v                        |
    +---------------+                |
    | WAIT WREADY   |----------------+
    +---------------+                |
            |                        |
            | WREADY                 |
            v                        |
    +---------------+                |
    | DRIVE BVALID  |                |
    +---------------+                |
            |                        |
            | BREADY                 |
            v                        |
        +-------+<-------------------+
        | IDLE  |
        +-------+
```

## Read Transaction (Single Master)

```
        +-------+
        | IDLE  |
        +---+---+
            |
            | ARVALID
            v
    +---------------+
    | WAIT ARREADY  |
    +---------------+
            |
            | ARREADY
            v
    +---------------+
    | DRIVE RVALID  |
    +---------------+
            |
            | RREADY
            v
        +-------+
        | IDLE  |
        +-------+
```

## Notes

- In this minimal subsystem, `AWREADY`/`WREADY`/`ARREADY` are tied high, so the master can generally complete the address/data phase in one clock cycle.
- `BVALID` and `RVALID` are asserted one cycle after the request is accepted and remain asserted until the corresponding `BREADY`/`RREADY` is seen.
