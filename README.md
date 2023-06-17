# Arduino LED Memory Game
A minimal component LED memory game for Arduino Nano

A fun project doesn't always require a ton of parts, this simple LED memory game only requires a single WS2812B LED and a push button. 

The game presents a randomly generated RGB colour and then cycles through more randomly generated colours, presenting the originally generated colour at randomly set intervals, the player has to press the button when the start colour appears to pass that "stage"! 

If the correct colour is selected, the LED displays blue and starts the cycle again but slightly faster and with a longer period between displaying the original start colour, if the player selects the wrong colour, the LED displays red and simply resets the game back to the original state, default speed and difficulty. 

It's fun, easy to modify and quite addictive, something you can throw together in minutes. 
The connections are simple and as I used INPUT_PULLUP, no resistors are needed. 

Simply connect as follows: 
Button: GND & D4 
WS2812B: 5v - 5v/3.3v, GND-GND, DIN - D5. 

I have tried to heavily comment the code so you should have no issues what is going on. 

Modify the code to make it your own, change the difficulty options or maybe even add new levels that require memorising multiple colours to advance to the next speed! 
Have fun! I hope you enjoy it. 

![ledGame](https://github.com/aaronalam1987/Arduino-LED-Memory-Game/assets/46248931/c8f4df9b-fd79-4dce-9aa3-db9ef676df34)
