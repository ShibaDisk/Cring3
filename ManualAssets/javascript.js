var contentBox = document.getElementById("content");
const Basics = 0;
const QuickRef = 1;
const Setup = 2;
const Usage = 3;


function tabChange(tab){
    switch(tab){
        case "Basics":
            contentBox.innerHTML = content[Basics];
            break;
        case "QuickRef":
            contentBox.innerHTML = content[QuickRef];
            break;
        case "Setup":
            contentBox.innerHTML = content[Setup];
            break;
        case "Usage":
            contentBox.innerHTML = content[Usage];
            break;
    }

}


content = ["<h2>Basics</h2>\
            <p>\
                Cring3 is a idiotic programming language designed to be as obtuse as possible. In Cring3, every instruction and arguement must also be \
                followed by a semicolon, like any REAL language (Eat your heart out, python). It is important to note that unlike in other languages that follow this convention, and most other languages\
                in general, will put the arguments for say, an if statement, in parenthesis. Cring3 does <b>not</b> do this. The arguments must be\
                written the same as any other line. This is not because it is easier for me to compile it like that, but because it is BETTER, and a \
                bold new innovation other languages are too scared to impliment, because the n00b baby programmers that use them will be too scared \
                because it's new.<br>\
                All instructions are max 3 character codes. This is because its more aesthetically pleasing, easier to write, and harder to\
                remember.<br>\
                An important thing to note with Cring3, is that there is only 2 variables, and only one can be accessed (active) at a time. \
                Math, and transfering values between the two variables, etc, requires loading them into the accumulator. That's right,\
                I'm making you use an accumulator. REAL programming languages have accumulators... and semicolons. Continue to eat your heart out, python. <br>\
            </p>",
            '<h2>Quick Reference</h2>\
                <table class="nestTable">\
                    <tr>\
                        <th colspan="3" class="nestTable">Index of Instructions</th>\
                    </tr>\
                    <tr class="nestTable">\
                        <th class="nestTable">Opcode</th>\
                        <th class="nestTable" style="width: 50%;">What It Does</th>\
                        <th class="nestTable" style="width: 30%;">Example</th>\
                    </tr>\
                    <tr>\
                        <td class="nestTable">#</td>\
                        <td class="nestTable">Marks a comment, everything between the # and ; will be ignored.</td>\
                        <td class="nestTable"><div class="codeblock">#Swap active variable;<br>Swp;</div></td>\
                    </tr>\
                    <tr>\
                        <td class="nestTable">Swp</td>\
                        <td class="nestTable">Swaps active variable.</td>\
                        <td class="nestTable"><div class="codeblock">Swp;</div></td>\
                    </tr>\
                    <tr>\
                        <td class="nestTable">Add</td>\
                        <td class="nestTable">Add active variable to accumulator.</td>\
                        <td class="nestTable"><div class="codeblock">Add;</div></td>\
                    </tr>\
                    <tr>\
                        <td class="nestTable">Div</td>\
                        <td class="nestTable">Divides the accumulator by the active variable. It should be noted that all variables are still integers, so no decimal.</td>\
                        <td class="nestTable"><div class="codeblock">Div;</div></td>\
                    </tr>\
                    <tr>\
                        <td class="nestTable">Mlt</td>\
                        <td class="nestTable">Multiplies the accumulator by the active variable.</td>\
                        <td class="nestTable"><div class="codeblock">Mlt;</div></td>\
                    </tr>\
                    <tr>\
                        <td class="nestTable">Sub</td>\
                        <td class="nestTable">Subtracts active variable from accumulator.</td>\
                        <td class="nestTable"><div class="codeblock">Sub;</div></td>\
                    </tr>\
                    <tr>\
                        <td class="nestTable">Equ</td>\
                        <td class="nestTable">Sets both variables to the active variable.</td>\
                        <td class="nestTable"><div class="codeblock">Equ;</div></td>\
                    </tr>\
                    <tr>\
                        <td class="nestTable">Set</td>\
                        <td class="nestTable">Sets active variable to a number. Takes one parameter of the number to set.</td>\
                        <td class="nestTable"><div class="codeblock">Set;<br>255;</div></td>\
                    </tr>\
                    <tr>\
                        <td class="nestTable">Lda</td>\
                        <td class="nestTable">Sets active variable to the accumulator.</td>\
                        <td class="nestTable"><div class="codeblock">Lda;</div></td>\
                    </tr>\
                    <tr>\
                        <td class="nestTable">Sta</td>\
                        <td class="nestTable">Sets the accumulator to the active variable.</td>\
                        <td class="nestTable"><div class="codeblock">Lda;</div></td>\
                    </tr>\
                    <tr>\
                        <td class="nestTable">Cla</td>\
                        <td class="nestTable">Sets the accumulator to 0.</td>\
                        <td class="nestTable"><div class="codeblock">Cla;</div></td>\
                    </tr>\
                    <tr>\
                        <td class="nestTable">Prt</td>\
                        <td class="nestTable">Prints active variable.</td>\
                        <td class="nestTable"><div class="codeblock">Prt;</div></td>\
                    </tr>\
                    <tr>\
                        <td class="nestTable">Pra</td>\
                        <td class="nestTable">Prints accumulator.</td>\
                        <td class="nestTable"><div class="codeblock">Pra;</div></td>\
                    </tr>\
                    <tr>\
                        <td class="nestTable">Hlw</td>\
                        <td class="nestTable">Hellos the world.</td>\
                        <td class="nestTable"><div class="codeblock">Hlw;</div></td>\
                    </tr>\
                    <tr>\
                        <td class="nestTable">Dsp</td>\
                        <td class="nestTable">Displays a string to the screen, it can not contain semicolons, deal with it.<br>\
                                                If you try to use a " to escape the string and write proper C, the compiler \
                                                will freeze in an act of divine punishment, and you should feel ashamed for \
                                                trying to exploit my perfect language. You may display quotes using \\, however.</td>\
                        <td class="nestTable"><div class="codeblock">Dsp;<br>Super Mario in Real Life;</div></td>\
                    </tr>\
                    <tr>\
                        <td class="nestTable">Stp</td>\
                        <td class="nestTable">Pauses until enter is hit.</td>\
                        <td class="nestTable"><div class="codeblock">Stp;</div></td>\
                    </tr>\
                    <tr>\
                        <td class="nestTable">For</td>\
                        <td class="nestTable">Loops through instructions a specified amount of times.</td>\
                        <td class="nestTable"><div class="codeblock">For;10;<br>Prt;<br>Brk;</div></td>\
                    </tr>\
                    <tr>\
                        <td class="nestTable">Chk</td>\
                        <td class="nestTable">Checks the current variable against the accumulator, based on an operator.\
                                                If true,  it will execute the instructions between it and a Brk. (Basically,\
                                                its an if statement.)</td>\
                        <td class="nestTable"><div class="codeblock">#If primary is equal to acc;<br>Chk;Equ;<br>Hlw;<br>Brk;</td>\
                    </tr>\
                    <tr>\
                        <td class="nestTable">Els</td>\
                        <td class="nestTable">An else statment. Executes the code inside if the previous Chk instruction did not run.</td>\
                        <td class="nestTable"><div class="codeblock">#If primary is equal to acc;<br>Chk;Equ;<br>Hlw;<br>Brk;<br>#Otherwise make it equal<br>Els;<br>Lda;<br>Brk;</td>\
                    </tr>\
                    <tr>\
                        <td class="nestTable">Brk</td>\
                        <td class="nestTable">Indicates the end of instructions like For loops.</td>\
                        <td class="nestTable"><div class="codeblock">For;10;<br>Prt;<br>Brk;</div></td>\
                    </tr>\
                    <tr>\
                        <td class="nestTable">Inp</td>\
                        <td class="nestTable">Gets input from the user, then sets the active variable to that input.<br><b>Important</b>\
                                to note that like in regular C, the program will crash if anything other than an int is\
                                entered.</td>\
                        <td class="nestTable"><div class="codeblock">Inp;</div></td>\
                    </tr>\
                    <tr>\
                        <td class="nestTable">Ext</td>\
                        <td class="nestTable">Exits the program.</td>\
                        <td class="nestTable"><div class="codeblock">Ext;</div></td>\
                    </tr>\
                </table>\
                \
                <br>\
                \
                <table class="nestTable">\
                <tr>\
                    <th class="nestTable" colspan="3">Index Of Operators</th>\
                </tr>\
                <tr>\
                    <th class="nestTable">Opcode</th>\
                    <th class="nestTable">Function</th>\
                </tr>\
                <tr>\
                    <td class="nestTable">Equ</th>\
                    <td class="nestTable">Equal.</th>\
                </tr>\
                <tr>\
                    <td class="nestTable">Nqu</th>\
                    <td class="nestTable">Not equal.</th>\
                </tr>\
                <tr>\
                    <td class="nestTable">Grt</th>\
                    <td class="nestTable">Greater than.</th>\
                </tr>\
                <tr>\
                    <td class="nestTable">Lst</th>\
                    <td class="nestTable">Less than.</th>\
                </tr>\
                <tr>\
                    <td class="nestTable">Gre</th>\
                    <td class="nestTable">Greater than or equal to.</th>\
                </tr>\
                <tr>\
                    <td class="nestTable">Lse</th>\
                    <td class="nestTable">Less than or equal to.</th>\
                </tr>\
            </table>\
            ',
            '\
            <h2>Setting Up The Cringepiler</h2>\
            <p>\
                Setting up the official Cring3 compiler, the Cringepiler, is very simple. It is portable and requires no installation. Simply download the latest release \
                (or compile it yourself), and extract it to your desired folder. Now, with just the Cringepiler, you\'ll only get a C file. In order to get that compiled to\
                an executeable, you will need to download <a href="https://bellard.org/tcc/">Tiny C Compiler</a> (they are not associated with Cring3 in any way, they\
                likely do not even know this exists). Download the latest bin zip, and extract the tcc folder to the same folder as the Cringepiler, it should look like \
                <a href="ManualAssets/structure.png" target="_blank">this</a>.\
            </p>\
            ',
            '\
            <h2>Usage</h2>\
            <p>\
                Using the Cringepiler is very simple. First, move your Cring3 file (.pog) into the folder with the Cringepiler and CrMake.bat file. Then, \
                either drag and drop the Cring3 file onto CrMake.bat, or use the command line, and in the folder execute <span class="codeblock">CrMake.bat [file name]</span>. \
                This will create both a out.c file and an out.exe, you only NEED out.exe, but out.c is left to make debugging easier. Cringepiler will only catch errors with \
                Cring3, not with the translated C, which should not be a problem, since GOOD programmers do everything right the first time always. If you can\'t handle that, \
                go back to <a href="https://scratch.mit.edu/">Scratch</a>, you cringe ass nae nae baby, you goddamn disappointment.\
            </p>\
            ','\
            <h2>Demos</h2>\
            <b class="demoName">Fibonacci.pog</b><br>\
            <b>Written by: Me</b><br>\
            Calculates the first 12 digits of the fibonacci sequence.<br><br>\
            <b>Thats all</b><br>\
            If you make some cool ones, and want them to be included in the manual/download, feel free to submit them to me @KirsVantas#1337 on discord.\
            '

        ];

onload(tabChange('Basics'));
