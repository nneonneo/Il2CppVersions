@echo off
echo Remember to update the version list in extract.sh before starting!

./extract.sh
pushd headers
echo Extracting headers...
python3 ./extract.py
echo Done Extracting headers.

./diffs.sh
popd
pushd api
./diffs.sh
popd
echo Dont forget to update notes.md and build_all.bat!
