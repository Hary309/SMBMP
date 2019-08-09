# SMBMP

Multiplayer mod for Super Meat Boy v1.2.5

## Demo

[![Demo of multiplayer mod](https://img.youtube.com/vi/5aXjm1OHZyY/0.jpg)](https://www.youtube.com/watch?v=5aXjm1OHZyY)

## About project

From the beginning of project we wanted to create gamemode similar to [Race Mode DLC](https://store.steampowered.com/app/969710/Super_Meat_Boy_Race_Mode/) but through internet of course.
Unfortunately Tommy Refenes (creator of SMB) didn't allow us to recreate Race Mode, so we just abandoned the project.
In current state, mod only synchronizing players' character, animation and position.

## How to build

Clone repository

```bash
git clone https://github.com/Harry09/SMBMP.git
cd SMBMP
git submodule update --init --recursive
```

Compile enet

```bash
cd src/vendor/enet
cmake -G "Visual Studio 16 2019" -A Win32 .
cmake --build . --config Release
```

Open `SMBMP.sln`, change configuration to `Release` and target to `x86` and compile

## How to run

1. Run `Server.Launcher.exe`
1. Copy `Client.Launcher.exe` and `Client.Core.dll` to Super Meat Boy's main directory
1. Run `Client.Launcher.exe`
