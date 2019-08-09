# SMBMP

Super Meat Boy Multiplayer Mod

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
