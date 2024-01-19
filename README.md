## NES emulator (paused)

After my chip8 project I've decided to start building a NES emulator.
Currently in development.

Currently implementing: cpu


### Log:
##### 2024 Update:
- Decided to pause the project after being forced to send my laptop for repair. Will probably make a smaller project and then come back to this eventually.


#### Previous Logs:
##### Nov 13, 2023
- Finshing last instructions to complete cpu
- Both my keyboard and trackpad stopped working so I had to buy external keyboard and mouse to continue.

##### Nov 1, 2023:
- After many attempts at doing flags, I've decided to use std::bitset and just set and unset using the included methods.
- Bitset and enum class should work together to tacke specific bytes. 
- Should check enum flagStatus and set/unset functions as they may be deprecated now.
- With this finished, I should be able to hop into subroutines and hopefully finish the rest of the instructions.

##### Nov 7, 2023:
- Refactoring for flags is done.
