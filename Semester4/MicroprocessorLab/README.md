## How to execute a program in the lab

1. Boot into DOS
2. cd into the masm1 folder
3. Type  ```edit filename.asm```
4. Write the code and save it (Shortcut to save: Alt+F then Alt+S)
5. Compile the code with the command  ```masm filename.asm;```
6. Link it to the code viewer with  ```link filename.obj```
Press Enter thrice such that all the fields that are asked remain empty
7. Now open code viewer with the command  ```cv filename.exe```
8. F2 to enable the registry viewer. F8 to trace the code step by step.
9. You can view a particular memory location by entering  ```d``` followed by the location 
address to view it (ex:  ```d 0000```). Enter this in the command line window at the bottom.
10. Enter  ```q``` to quit code view.

## How to Install an emulator
1. Download EMU8086 from the link below. (Only for Windows  https://download.cnet.com/Emu8086-Microprocessor-Emulator/3000-2069_4-10392690.html
2. Install it
3. Open emulator, open a new file, select COM template. 
4. Write whatever code you want to write and save it.
5. Click emulate, any errors will be shown there. Rectify them and save again.
6. The code view window will open, this is the same as the code view window in the lab.
7. You can now trace the code with the single step button(same as F8 in the lab).
8. variables and the memory can be viewed from the view tab at the top.
Except you do only write the address to view the memory and not the dump command.
(ie type ```0000``` in the memory window to view that memory location, not ```d 0000``` 
as done in the lab)