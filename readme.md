## Linecounter
Tiny app to count lines inside a directory:
```
$ linecounter
Checked 3 directories
Checked 11 files
Read 1845 lines
Stats by filetypes:
Type: ".gitignore" Lines: 5 Percentage: 0%
Type: "No type" Lines: 31 Percentage: 1%
Type: ".h" Lines: 374 Percentage: 20%
Type: ".cpp" Lines: 626 Percentage: 33%
Type: ".hpp" Lines: 809 Percentage: 43%
```
## Install
To install do:
```
git clone https://github.com/Khudyakov1/linecounter.git
cd linecounter
chmod +x install.sh
./install.sh
```
And enter you password.

If you don't want to install the app inside `/usr/bin/` do:
```
chmod +x build.sh
./build.sh
```
if you want to remove the app from `/usr/bin` do:
```
chmod +x uninstall.sh
./uninstall.sh
```
And enter your password
## Usage
To get info run:
```
linecounter --help
```
To count lines inside current directory do:
```
linecounter
```
To count lines inside certain directory do:
```
linecounter <dir>
```
To only count lines inside files that match the wildcard do:
```
linecounter <dir> <wildcard>
```