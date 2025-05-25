# hospital_management_project
This is an OOP project the second-semester in HCMUS

## Project Structure

```
├─── build
│    ├─── bin              //  executable files
│    └─── obj              //  build files
└─── src
     ├─── controllers      //  controller classes
     ├─── models           //  model classes
     ├─── utils            //  utility classes
     └─── views            //  view classes
```

## Install packages

1. Press **Ctrl+`** to open **Package Manager Console**.
1. Use the command `Update-Package` to restore and update all packages.

## Generate documentation

Run the command: `./packages/Doxygen.1.8.14/tools/doxygen docs/Doxyfile`

## Build with CMake

1. Open **Visual Studio 2022** (ensure you have CMake integrated to your VS and Qt installed in `packages/`).
1. Choose "Open a local folder" and open this folder (or any other ways to open in folder mode).
1. Wait for **CMake generation** to finished (check for the message "CMake generation finished." in **Output View**).
1. Choose `Ctrl+Shift+B` or **Build > Build All**.
