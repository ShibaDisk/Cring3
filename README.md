# Cring3
All of the information here is also avaliable in the manual. A list of instructions and how to use them can be found there.
The Cringepiler (Compiler for Cring3 files) is written in C++, the reason its labeled javascript is from the manual, which uses it so that every page doesn't need to be a seperate file.

## Basics
Cring3 is a idiotic programming language designed to be as obtuse as possible. In Cring3, every instruction and arguement must also be 
followed by a semicolon, like any REAL language (Eat your heart out, python). It is important to note that unlike in other languages that follow this convention, and most other languages
in general, will put the arguments for say, an if statement, in parenthesis. Cring3 does not do this. The arguments must be
written the same as any other line. This is not because it is easier for me to compile it like that, but because it is BETTER, and a 
bold new innovation other languages are too scared to impliment, because the n00b baby programmers that use them will be too scared 
because it's new.
All instructions are max 3 character codes. This is because its more aesthetically pleasing, easier to write, and harder to
remember.
An important thing to note with Cring3, is that there is only 2 variables, and only one can be accessed (active) at a time. 
Math, and transfering values between the two variables, etc, requires loading them into the accumulator. That's right,
I'm making you use an accumulator. REAL programming languages have accumulators... and semicolons. Continue to eat your heart out, python.

## Setup
Setting up the official Cring3 compiler, the Cringepiler, is very simple. It is portable and requires no installation. Simply download the latest release 
(or compile it yourself), and extract it to your desired folder. Now, with just the Cringepiler, you'll only get a C file. In order to get that compiled to
an executeable, you will need to download [Tiny C Compiler](https://bellard.org/tcc/) (they are not associated with Cring3 in any way, they
likely do not even know this exists). Download the latest bin zip, and extract the tcc folder to the same folder as the Cringepiler.

## Usage
Using the Cringepiler is very simple. First, move your Cring3 file (.pog) into the folder with the Cringepiler and CrMake.bat file. Then, 
either drag and drop the Cring3 file onto `CrMake.bat` (not included in the source,  all it does is run the Cringepiler to make a C file, then TCC to make an exe), or use the command line, and in the folder execute `CrMake.bat [file name]`. 
This will create both a `out.c` file and an `out.exe`, you only NEED `out.exe`, but `out.c` is left to make debugging easier. The Cringepiler itself will only catch errors with 
Cring3, not with the translated C, which should not be a problem, since GOOD programmers do everything right the first time always. If you can't handle that, 
go back to [Scratch](https://scratch.mit.edu/), you cringe ass nae nae baby, you goddamn disappointment.
