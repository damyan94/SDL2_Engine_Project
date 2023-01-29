# SDL2_Engine_Project

# History
This is a copy of the now deleted repository that I had - I am starting clean. It has some changes since the last commit that I made but didn't find the time to commit.

# Description
The following is copy-paste text from the readme file of the deleted repository.

### SDL2_Game_Engine
<i>A first attempt to make a functional and easy to use 2D game engine for C++ with the SDL2 library.</i>

This is my first very own attempt to make a 2D game engine in C++ around the SDL2 library. This engine is heavily inspired by the engine that we created in SoftUni during the Applications Development with C++ course 2021 with lecturer Zhivko Petrov.

### Some details
It is not as sophisticated as the engine developed there but is in my opinion more light and user friendly and I personally cannot wait to make some exciting games with it.

It applies several design patterns such as the fly-weight design pattern. There are funcionalities for rendering images and text, playing sounds and music and timer utilities.

I am sure there are possibilities for improvement in order to make it more robust and safer but as a first attempt I am quite content. I am open to criticism and ideas for improvement.

### Motivation
I started this project on 17.06.2022 and finished it on 28.06.2022. I have been working in my spare time and had to research some topics but I think it is a fair result in the end. I played a tower defense game one day and that inspired me to make my very own TD game. I had a game engine available to me from the course I took in SoftUni but thought that I could give it a try and make my own engine. I really did not expect to have a functioning engine at all, but it happened.

### Finishing words
This code is free to use but please do not claim it as your own as I do not claim others' work as my own.

Thanks for reading and using my creation if you did.

Damyan Damyanov 2022


# TODO
1. Reformat code to use PascalCase for classes and functions and the m_VariableName notation for class members.
2. Maybe have a precompiled header or some header with common includes.
3. Move all enums, enum classes, typedefs etc. in single file(s) and not have them scattered across various files.
4. Refactor utils code, especially time, positioning and other utils.
5. Add managers to abstract some of the logic in the Engine – resource, drawing, text, audio, im-gui etc. managers.
6. Refactor sdl_utils code and hide it under managers.
7. Add im-gui class/manager/controller that will abstract all im-gui logic and provide similar API to existing classes – Init, Deinit, Update, Draw. Have a single .h file included in the Engine.
