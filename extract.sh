### Start Configuration

path_to_7zip="/mnt/c/Program Files/7-Zip/7z.exe"
path_to_UnitySetup="/mnt/e/UnityInstallers"

### End Configuration

if [ -d "${path_to_UnitySetup}" ]; then
      echo Unity Folder Exists
else
  echo Unity Folder doesnt exist
fi
if [ -f "${path_to_7zip}" ]; then
      echo 7Zip Exists
else
  echo 7Zip doesnt exist
fi

extract() {
  i=$1
  path=$2
  dst=$3
  if [ -d "${dst}" ]; then
    return
  fi
  if [ -f "${path_to_UnitySetup}/UnitySetup64-$i.exe" ]; then
      echo Extracting $i...
      "${path_to_7zip}" x -bb0 -bd "`wslpath -w ${path_to_UnitySetup}`"/UnitySetup64-$i.exe "${path}" >/dev/null 2>&1
      cp -r ${path} ${dst}
      rm -rf Editor
  else
    echo Unity $i missing, skipped
  fi
}

extractWinIL2CPP() {
  i=$1
  dst=$2
  if [ -d "${dst}" ]; then
    return
  fi
  if [ -f "${path_to_UnitySetup}/UnitySetup-Windows-IL2CPP-Support-for-Editor-$i.exe" ]; then
    echo Extracting Windows Standalone IL2CPP support for $i...
      "${path_to_7zip}" x -bb0 -bd -o_Extracted "`wslpath -w ${path_to_UnitySetup}`"/UnitySetup-Windows-IL2CPP-Support-for-Editor-$i.exe >/dev/null 2>&1
      mkdir -p ${dst}
      cp -r _Extracted/\$INSTDIR\$_*/* ${dst}
      rm -rf _Extracted
  else
    echo Windows Standalone IL2CPP support for $i missing, skipped
  fi
}

extractNSIS() {
  i=$1
  path=$2
  dst=$3
  if [ -d "${dst}" ]; then
    return
  fi
  if [ -f "${path_to_UnitySetup}/UnitySetup64-$i.exe" ]; then
      echo Extracting $i...
      # Note: This is considered to be a silent install, not just a file extract, but we don't really care
      "${path_to_UnitySetup}/UnitySetup64-$i.exe" /S /D=`wslpath -w .`\\_Extracted &
      wait
      cp -r _Extracted/${path} ${dst}
      rm -rf _Extracted
  else
    echo Unity $i missing, skipped
  fi
}

extractNSISWinIL2CPP() {
  i=$1
  dst=$2
  if [ -d "${dst}" ]; then
    return
  fi
  if [ ! -f "${path_to_UnitySetup}/UnitySetup64-$i.exe" ]; then
    echo Unity $i missing, skipping Windows Standalone IL2CPP support install
  fi
  if [ -f "${path_to_UnitySetup}/UnitySetup-Windows-IL2CPP-Support-for-Editor-$i.exe" ]; then
    echo Extracting $i...
    "${path_to_UnitySetup}/UnitySetup64-$i.exe" /S /D=`wslpath -w .`\\_Extracted &
    wait

    echo Extracting Windows Standalone IL2CPP support for $i...
    # Note: This is considered to be a silent install, not just a file extract, but we don't really care
    "${path_to_UnitySetup}/UnitySetup-Windows-IL2CPP-Support-for-Editor-$i.exe" /S /D=`wslpath -w .`\\_Extracted &
    wait
    mkdir -p ${dst}
    cp -r _Extracted/Editor/Data/PlaybackEngines/windowsstandalonesupport/* ${dst}
    rm -rf _Extracted
  else
    echo Windows Standalone IL2CPP support for $i missing, skipped
  fi
}

for i in 5.3.0f4 5.3.1f1 5.3.2f1 5.3.3f1 5.3.4f1 5.3.5f1 5.3.6f1 5.3.7f1 5.3.8f2 5.4.0f3 5.4.1f1 5.4.2f2 5.4.3f1 5.4.4f1 5.4.5f1 5.4.6f3 5.5.0f3 5.5.1f1 5.5.2f1 5.5.3f1 5.5.4f1 5.5.5f1 5.5.6f1 5.6.0f3 5.6.1f1 5.6.2f1 5.6.3f1 5.6.4f1 5.6.5f1 5.6.6f2 5.6.7f1 2017.1.0f3 2017.1.1f1 2017.1.2f1 2017.1.3f1 2017.1.4f1 2017.1.5f1 2017.2.0f3 2017.2.1f1 2017.2.2f1 2017.2.3f1 2017.2.4f1 2017.2.5f1 2017.3.0f3 2017.3.1f1 2017.4.1f1 2017.4.2f2 2017.4.3f1 2017.4.4f1 2017.4.5f1 2017.4.6f1 2017.4.7f1 2017.4.8f1 2017.4.9f1 2017.4.10f1 2017.4.11f1 2017.4.12f1 2017.4.13f1 2017.4.14f1 2017.4.15f1 2017.4.16f1 2017.4.17f1 2017.4.18f1 2017.4.19f1 2017.4.20f2 2017.4.21f1 2017.4.22f1 2017.4.23f1 2017.4.24f1 2017.4.25f1 2017.4.26f1 2017.4.27f1 2017.4.28f1 2017.4.29f1 2017.4.30f1 2017.4.31f1 2017.4.32f1 2017.4.33f1
do
    extract $i Editor/data/il2cpp group1/il2cpp-$i
done
extract 5.3.0f4 Editor/data/Mono group1/Mono
extract 5.3.0f4 Editor/data/MonoBleedingEdge group1/MonoBleedingEdge
extract 5.3.0f4 Editor/data/Tools/UnusedByteCodeStripper2 group1/UnusedByteCodeStripper2

for i in 2017.4.34f1 2017.4.35f1 2017.4.36f1 2017.4.37f1 2017.4.38f1 2017.4.39f1 2017.4.40f1 2018.1.0f2 2018.1.1f1 2018.1.2f1 2018.1.3f1 2018.1.4f1 2018.1.5f1 2018.1.6f1 2018.1.7f1 2018.1.8f1 2018.1.9f2
do
    extract $i Editor/data/il2cpp group2/il2cpp-$i
done
extract 2017.4.34f1 Editor/data/Mono group2/Mono
extract 2017.4.34f1 Editor/data/MonoBleedingEdge group2/MonoBleedingEdge


for i in 2018.2.0f2 2018.2.1f1 2018.2.2f1 2018.2.3f1 2018.2.4f1 2018.2.5f1 2018.2.6f1 2018.2.7f1 2018.2.8f1 2018.2.9f1 2018.2.10f1 2018.2.11f1 2018.2.12f1 2018.2.13f1 2018.2.14f1 2018.2.15f1 2018.2.16f1 2018.2.17f1 2018.2.18f1 2018.2.19f1 2018.2.20f1 2018.2.21f1
do
    extract $i Editor/data/il2cpp group3/il2cpp-$i
done
extract 2018.2.0f2 Editor/data/Mono group3/Mono
extract 2018.2.0f2 Editor/data/MonoBleedingEdge group3/MonoBleedingEdge

for i in 2018.3.0f2 2018.3.1f1 2018.3.2f1 2018.3.3f1 2018.3.4f1 2018.3.5f1 2018.3.6f1 2018.3.7f1 2018.3.8f1 2018.3.9f1 2018.3.10f1 2018.3.11f1 2018.3.12f1 2018.3.13f1 2018.3.14f1 2018.4.0f1 2018.4.1f1 2018.4.2f1 2018.4.3f1 2018.4.4f1 2018.4.5f1 2018.4.6f1 2018.4.7f1 2018.4.8f1 2018.4.9f1 2018.4.10f1 2018.4.11f1 2018.4.12f1 2018.4.13f1 2018.4.14f1 2018.4.15f1 2018.4.16f1 2018.4.17f1 2018.4.18f1 2018.4.19f1 2018.4.20f1 2018.4.21f1 2018.4.22f1 2018.4.23f1 2018.4.24f1 2018.4.25f1 2018.4.26f1 2018.4.27f1 2018.4.28f1 2018.4.29f1 2018.4.30f1 2018.4.31f1 2018.4.32f1 2018.4.33f1 2018.4.34f1 2018.4.35f1 2018.4.36f1 2019.1.0f2 2019.1.1f1 2019.1.2f1 2019.1.3f1 2019.1.4f1 2019.1.5f1 2019.1.6f1 2019.1.7f1 2019.1.8f1 2019.1.9f1 2019.1.10f1 2019.1.11f1 2019.1.12f1 2019.1.13f1 2019.1.14f1 2019.2.0f1 2019.2.1f1 2019.2.2f1 2019.2.3f1 2019.2.4f1 2019.2.5f1 2019.2.6f1 2019.2.7f2 2019.2.8f1 2019.2.9f1 2019.2.10f1 2019.2.11f1 2019.2.12f1 2019.2.13f1 2019.2.14f1 2019.2.15f1 2019.2.16f1 2019.2.17f1 2019.2.18f1 2019.2.19f1 2019.2.20f1 2019.2.21f1
do
    extract $i Editor/data/il2cpp group4/il2cpp-$i
done
extract 2018.3.0f2 Editor/data/Mono group4/Mono
extract 2018.3.0f2 Editor/data/MonoBleedingEdge group4/MonoBleedingEdge

for i in 2019.3.0f6 2019.3.1f1 2019.3.2f1 2019.3.3f1 2019.3.4f1 2019.3.5f1 2019.3.6f1 2019.3.7f1 2019.3.8f1 2019.3.9f1 2019.3.10f1 2019.3.11f1 2019.3.12f1 2019.3.13f1 2019.3.14f1 2019.3.15f1 2019.4.0f1 2019.4.1f1 2019.4.2f1 2019.4.3f1 2019.4.4f1 2019.4.5f1 2019.4.6f1 2019.4.7f1 2019.4.8f1 2019.4.9f1 2019.4.10f1 2019.4.11f1 2019.4.12f1 2019.4.13f1 2019.4.14f1 2019.4.15f1 2019.4.16f1 2019.4.17f1 2019.4.18f1 2019.4.19f1 2019.4.20f1 2019.4.21f1 2019.4.22f1 2019.4.23f1 2019.4.24f1 2019.4.25f1 2019.4.26f1 2019.4.27f1 2019.4.28f1
do
    extract $i Editor/data/il2cpp group5/il2cpp-$i
done
extract 2019.3.0f6 Editor/data/MonoBleedingEdge group5/MonoBleedingEdge

for i in 2020.1.0f1 2020.1.1f1 2020.1.2f1 2020.1.3f1 2020.1.4f1 2020.1.5f1 2020.1.6f1 2020.1.7f1 2020.1.8f1 2020.1.9f1 2020.1.10f1 2020.1.11f1 2020.1.12f1 2020.1.13f1 2020.1.14f1 2020.1.15f1 2020.1.16f1 2020.1.17f1
do
    extract $i Editor/data/il2cpp group6/il2cpp-$i
done
extract 2020.1.0f1 Editor/data/MonoBleedingEdge group6/MonoBleedingEdge
extractWinIL2CPP 2020.1.0f1 group6/PlaybackEngines/windowsstandalonesupport

for i in 2020.2.0f1 2020.2.1f1 2020.2.2f1 2020.2.3f1 2020.2.4f1 2020.2.5f1 2020.2.6f1 2020.2.7f1 2020.3.0f1 2020.3.1f1 2020.3.2f1 2020.3.3f1 2020.3.4f1 2020.3.5f1 2020.3.6f1 2020.3.7f1 2020.3.8f1 2020.3.9f1 2020.3.10f1 2020.3.11f1 2020.3.12f1 2020.3.13f1 2020.3.14f1 2021.1.0f1 2021.1.1f1 2021.1.2f1 2021.1.3f1 2021.1.4f1 2021.1.5f1 2021.1.6f1 2021.1.7f1 2021.1.9f1 2021.1.10f1 2021.1.11f1 2021.1.12f1 2021.1.13f1 2021.1.14f1 2021.1.15f1 2021.2.0b4
do
  extractNSIS $i Editor/data/il2cpp group7/il2cpp-$i
done
extractNSIS 2021.1.0f1 Editor/data/MonoBleedingEdge group7/MonoBleedingEdge
extractNSISWinIL2CPP 2021.1.0f1 group7/PlaybackEngines/windowsstandalonesupport
