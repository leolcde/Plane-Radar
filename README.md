# Aviation Radar Simulator

## 🛩️ Overview

The **Aviation Radar Simulator** is a real-time radar system simulation developed in C using **CSFML** (Simple and Fast Multimedia Library for C). It simulates aircraft movement, radar scanning, and aircraft detection on a 2D map.

---

## 🎯 Features

- Real-time radar sweep animation
- Aircraft simulation with speed, direction, and position
- Collision detection and alert system
- Configurable airspace and aircraft parameters
- Graphical rendering using CSFML (sprites, shapes, text)

---

## 🛠️ Technologies

- Language: **C**
- Graphics and Windowing: **CSFML**
- Build Tool: `make`
- Compiler: `gcc` or `clang`

---

## 📁 Project Structure

plane_radar/
├── include/ # Header files
│ └── radar.h
├── src/ # Source code files
│ ├── main.c
│ ├── radar.c
│ ├── aircraft.c
│ └── collision.c
├── assets/ # Textures, fonts, and configuration files
├── Makefile
└── README.md


---

## 🧩 Dependencies

Install **CSFML** before compiling:

### On Ubuntu:
```bash
sudo apt update
sudo apt install libcsfml-dev
```

### On Arch:
```bash
sudo pacman -S csfml
```

## 🧪 How to Build & Run

### Build the project:
```bash
make
```

### Générate maps:
```bash
python map_generator.py -p <nb_planes> -t <nb_towers> [options]
```

### Run the simulator:
```bash
./my_radar <"maps generate by python scrypt">
```

