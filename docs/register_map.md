# AXI Subsystem Register Map Specification

## 1. Register Conventions

All registers:

- Width: 32 bits
- Access size: 32 bits
- Reset value: defined per register
- Address offset relative to peripheral base address


Access types:

| Type | Meaning |
|-|-|
| RW | Read and Write |
| RO | Read Only |
| WO | Write Only |


---

# 2. RAM Controller

Base Address:
0x0000_0000


The RAM peripheral provides simple memory storage.

## Register Map

| Offset | Register | Access | Description |
|-|-|-|-|
|0x0000|CONTROL|RW|Enable RAM|
|0x0004|STATUS|RO|RAM status|
|0x0008|ADDRESS|RW|Memory address|
|0x000C|DATA|RW|Read/write data|

---

## CONTROL Register

Address:
0x0000_0000

Bits:

|Bit|Name|Access|Description|
|-|-|-|-|
|0|ENABLE|RW|Enable RAM|

Reset:
0x0000_0000

---

## STATUS Register

Address:
0x0000_0004

Bits:

|Bit|Name|Access|
|-|-|-|
|0|READY|RO|

Reset:
0x00000001


---

# 3. UART Peripheral

Base Address:
0x4000_0000

Purpose:

Provide serial communication through AXI transactions.


## Register Map

|Offset|Register|Access|Description|
|-|-|-|-|
|0x00|CTRL|RW|UART configuration|
|0x04|STATUS|RO|UART state|
|0x08|TX_DATA|WO|Transmit byte|
|0x0C|RX_DATA|RO|Received byte|


---

## CTRL Register

Bits:

|Bit|Name|Description|
|-|-|-|
|0|ENABLE|Enable UART|
|1|TX_ENABLE|Enable transmitter|
|2|RX_ENABLE|Enable receiver|


Reset:
0x00000000


---

## STATUS Register

Bits:

|Bit|Name|Description|
|-|-|-|
|0|TX_READY|Transmit available|
|1|RX_VALID|Received data available|


Example:

Master checks:
STATUS.TX_READY == 1
then writes:
TX_DATA = character

---

# 4. Timer Peripheral

Base Address:
0x40010000


Purpose:

Generate timing information.


## Register Map


|Offset|Register|Access|Description|
|-|-|-|-|
|0x00|CTRL|RW|Timer control|
|0x04|STATUS|RO|Timer state|
|0x08|COUNT|RO|Current counter|
|0x0C|COMPARE|RW|Interrupt value|


---

## CTRL Register


|Bit|Name|
|-|-|
|0|ENABLE|
|1|RESET|


---

## STATUS Register


|Bit|Name|
|-|-|
|0|ACTIVE|


---

# 5. GPIO Peripheral

Base Address:
0x40020000



Purpose:

General purpose input/output.


## Register Map

|Offset|Register|Access|Description|
|-|-|-|-|
|0x00|DIR|RW|Pin direction|
|0x04|OUT|RW|Output value|
|0x08|IN|RO|Input value|


---

# 6. Software Usage Examples


## UART transmit

Sequence:

1. Enable UART
WRITE UART_CTRL
ENABLE = 1


2. Check status
READ UART_STATUS


3. Send byte
WRITE UART_TX_DATA

---

## Timer usage

Sequence:

1. Configure compare value
WRITE TIMER_COMPARE

2. Enable timer
WRITE TIMER_CTRL

3. Poll status
READ TIMER_STATUS


---

# Future Extensions

Possible future peripherals:

- DMA controller
- SPI controller
- I2C controller
- Interrupt controller
- AXI4 full support
- AXI burst transactions

