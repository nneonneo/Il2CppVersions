@echo off
echo Remember to update the version list in extract.sh before starting!

wsl -e bash extract.sh
pushd headers
wsl -e ./extract.py
wsl -e bash diffs.sh
popd
pushd api
wsl -e bash diffs.sh
popd

echo Don't forget to update notes.md!
