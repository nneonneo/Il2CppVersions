This repository contains build scripts for building a C# assembly using every version of Il2Cpp from 5.3.0f4 (from 2015) onwards. It was used to test the [Il2CppInspector](https://github.com/djkaty/Il2CppInspector) project, and can also be used to compare Il2Cpp structures and outputs between versions.

Currently, everything only works on Windows and builds only for Windows. I welcome PRs adding support for other platforms (Linux, macOS, building for Android/iOS/etc.).

## Building everything

- Install VS2015 and VS2017 C++ tools. *Uninstall* VS2019 C++ tools if you have them - otherwise certain versions will fail.
- Download every installer from the [Unity site](https://unity3d.com/get-unity/download/archive)
    - Download the "Unity Editor 64-bit" for Windows.
    - I extracted links using a text editor on the source of that page, and then downloaded all of them with aria2c.
- For Unity 2020+, download the [Windows (IL2CPP) Target Support](https://beta.unity3d.com/download/2ab9c4179772/TargetSupportInstaller/UnitySetup-Windows-IL2CPP-Support-for-Editor-2020.1.0f1.exe) package to support builds for these Unity versions.
- Install 7-zip.
- Edit `extract.sh` to update the paths to 7z.exe and your downloads.
- Run `extract.sh` to extract il2cpp into each of the group directories
- Edit `Test.cs` as you see fit; it just needs to be C# 4.0 compatible.
- Run `build_all.bat` to build `Test.cs` into a DLL against every single version. These will go into the `output/` directory, one per version. Already built versions will be skipped.

To force a rebuild of an individual version, use the `f` (force) option when calling `build.bat`.

Note that downloading and building everything will probably take a *long* time - on the order of multiple hours.

## Header files

A secondary purpose for this repo is documenting and collecting header files describing the internal structures for every version of Il2Cpp. The script `headers/extract.py` can help to extract a usable C/C++ header from a particular version of Il2Cpp.
