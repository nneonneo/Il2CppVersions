This repository contains build scripts for building a C# assembly using every version of Il2Cpp from 5.3.0f4 (from 2015) onwards. It was used to test the [Il2CppInspector](https://github.com/djkaty/Il2CppInspector) project, and can also be used to compare Il2Cpp structures and outputs between versions.

Currently, everything only works on Windows and builds only for Windows. I welcome PRs adding support for other platforms (Linux, macOS, building for Android/iOS/etc.).

## Building everything

- Install VS2015 and VS2017 C++ tools. *Uninstall* VS2019 C++ tools if you have them - otherwise certain versions will fail.
- Download every installer from the [Unity Archive](https://unity3d.com/get-unity/download/archive)
    - Download the "Unity Editor 64-bit" for Windows.
    - I extracted links using a text editor on the source of that page, and then downloaded all of them with aria2c.
- For Unity 2020+, the Windows (IL2CPP) Target Support package is necessary to support builds for these Unity versions. A link can be found on the Release Notes page for each necessary version.
    - For Unity 2020, the file can be downloaded [here](https://beta.unity3d.com/download/2ab9c4179772/TargetSupportInstaller/UnitySetup-Windows-IL2CPP-Support-for-Editor-2020.1.0f1.exe).
    - For Unity 2021, the file can be downloaded [here](https://download.unity3d.com/download_unity/61a549675243/TargetSupportInstaller/UnitySetup-Windows-IL2CPP-Support-for-Editor-2021.1.0f1.exe).
- Install 7-zip.
- Edit `extract.sh` to update the paths to 7z.exe and your downloads.
- Run `extract.sh` to extract il2cpp into each of the group directories
- Edit `Test.cs` as you see fit; it just needs to be C# 4.0 compatible.
- Run `build_all.bat` to build `Test.cs` into a DLL against every single version. These will go into the `output/` directory, one per version. Already built versions will be skipped.

To force a rebuild of an individual version, use the `f` (force) option when calling `build.bat`.

Note that downloading and building everything will probably take a *long* time - on the order of multiple hours.

## Header files

A secondary purpose for this repo is documenting and collecting header files describing the internal structures for every version of Il2Cpp. The script `headers/extract.py` can help to extract a usable C/C++ header from a particular version of Il2Cpp.

## How To Extract New Header and API files

> Note: this only works if there haven't been significant changes to the internal file structure of the Unity Installation executables. Otherwise a new "group" will have to be created for this different file structure.

- Download the desired installers from the [Unity Archive](https://unity3d.com/get-unity/download/archive)
    - Download the "Unity Editor 64-bit" for Windows.
    - For newer versions, expect each one to be over 2 GB.
- In Windows:
    - Install 7-zip.
- In the linux subsystem:
    - Install Python 3.
    - Install gcc.
- Edit `extract.sh`:
    - Update the paths to 7z.exe and your downloads.
    - If running on new Unity versions, add those versions in the appropriate groups.
- Run `update.sh` in the linux subsystem
    - This script:
        - Extracts il2cpp into each of the group directories
        - Updates the header and api files
        - Generates updated diff files
    - Starting in 2020.2.0:
        - The installer mechanism has been changed to use NSIS. Unzipping the normal way leads to a bunch of useless files, so we have to perform a silent install. Note that this is an actual install and not a pure unzip/extract. However, you can have side-by-side installations, and wiping out the folders after use has no effect on real Unity installations via Unity Hub, as they seem to be handled separately.
        - For every extraction, it might need to ask permission.
        - For the Windows Standalone IL2CPP Support, the installer will check not just for the existence of a Unity.exe but also the right version (and maybe other files), so we have to extract the Unity 64-bit Editor again, and then the IL2CPP support files. This is brutally slow but there is no better way (that we know of) to do it currently.
    - Note that this could potentially take many hours.