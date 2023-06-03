# Pixelang Quick Reference Manual

## Introduction
Pixelang is a basic programming language with simple built-in image manipulation capabilities.

This manual will help you quickly find your way around the project and get started writing your own programs!

## Table of Contents
- [Getting started](#getting-started)
- [Data Types](#data-types)
- [Variables](#variables)
- [Operators](#operators)
- [Control flow](#control-flow)
- [Functions](#functions)
- [Output](#output)
- [Image processing](#image-processing)
- [Running tests](#running-tests)
- [Extra information](#extra-information)

## Getting started
To write your code, you will need to use the `code.txt` file you'll find in the root directory. If it doesn't exist, go ahead and create the file yourself! Just make sure it's in the same directory as this guide.

Once your `code.txt` file is ready, you can start coding.

Here's a template for a basic "HelloWorld" program.

    program HelloWorld;

    {
        print("Hello World!");
    }

You can open your terminal and type in the word `make` to run the program. You should see something like this:

    Running 'HelloWorld':
    Hello World! 
    Execution time: 0.258375 ms.

Any Pixelang program must start with the keyword ```program``` followed by the ```name of your program```, then a ```semicolon (;)```.

It must also include a main function, which is defined by a pair of ```curly brackets```. Inside this main function, you may write as many statements as you wish, even 0, meaning this is the bare minimum your program needs:

    program programName;

    {}

But more often than not, you will want to write statements, as well as variables and maybe even functions. So keep reading and you'll find more about all of this!

## Data Types

Pixelang supports integers (int), floats (float) and booleans (bool) as data types acceptable for both variables and functions. They can also all be used in most operations.

Strings are also supported, but only as constants typed in by the user. They cannot be stored as variables. They are mostly used for print statements, as you have seen already.

A custom data type "Image" (image) is also included, which can be used to open and create new images in your system. We'll talk more about that later, but keep in mind that while you can have variables of type Image, they can't be used in any operations.

## Variables

### Declaring a variable

Global variables are exclusively declared at the beginning of the program, right after the program name.

    program variables;

    var a : int;

    {}

To declare a variable, you must first write the keyword ```var``` followed by the ```name of your variable```, then a ```colon (:)```, the ```data type of your variable``` and a ```semicolon (;)```.

### Naming a variable.

Your variable <b>must</b> start with a ```letter``` and can be then followed by any amount ```alphanumeric characters``` or ```underscores (_)```. Just keep in mind your variable name <b>must not</b> end in an ```underscore (_)``` and you <b>cannot</b> have multiple ```underscores (_)``` together.

### Declaring multiple variables

You can also declare multiple variables at once, as long as they're all of the same data type.

    program variables;

    var a, b, c : int;

    {}

To do this, just write multiple variable names in between the ```var``` keyword and the ```colon```, while separating them with a ```comma```.

If you want variables of different data types, you can always write more lines.

    program variables;

    var i1, i2, i3 : int;
    var f1 : float;
    var b1, b2 : bool;

    {}

This is a good time to remind you variables <b>must</b> have unique names, meaning any redeclaration of a variable will lead to an error, as long as they're in the same scope. We'll talk more about scopes later.

### Assignments

While you cannot initialize variables to have any sort of value, you can assign them one inside of your main function by using the ```assignment operator (=)```.

    program assignments;

    var i : int;
    var f : float;

    {
        i = 1;
        f = 1.5;
    }

You can also assign a variable's value to another one, as long as their data type is compatible.

    program assignments;

    var a, b : int;

    {
        a = 1;
        b = a;
    }

Booleans also have special ```true``` and ```false``` keywords you can use.

    program assignments;

    var t, f : bool;

    {
        t = true;
        f = false;
    }

### Declaring an array

Another type of variable we haven't mentioned is arrays. You can have arrays of any data type you can declare a variable of.

    program arrays;

    var arr : int[3];
    var arr1, arr2 : float[5];

    {}

Arrays follow a similar syntax to normal variables, with the one difference being that the data type is followed by an ```opening bracket ([)```, then a ```constant integer```, a ```closing bracket (])```, and a ```semicolon (;)```. The integer inside of the brackets represents the length of the array. Please keep in mind it can only be a constant integer, not another variable.

It's also worth mentioning that all the arrays declared in a single line will share the same lengths and dimensions. That's right, arrays can also have more than one dimension.

### Multiple dimensions

    program arrays;

    var arr : int[3][2];
    var arr1, arr2 : bool[5][1][3];

    {}

By adding more pairs of ```brackets``` with a constant integer, you can add dimensions to your array. Each bracket is a new dimension and they can all have different lengths.

## Operators

Here's a listing of the operators available for your programs.

- Arithmetic:
    - Addition: `+`
    - Subtraction: `-`
    - Multiplication: `*`
    - Division: `/`
    - Modulus: `%`
    - Assignment: `=`
- Comparison:
  - Equal to: `==`
  - Not equal to: `!=`
  - Greater than: `>`
  - Less than: `<`
  - Greater than or equal to: `>=`
  - Less than or equal to: `<=`
- Logical:
  - AND: `&&`
  - OR: `||`
  - NOT: `!`

They work as you would expect them to in any other programming language.

## Control flow

### Conditionals: if statements

Pixelang supports conditionals. Here's a basic if statement:

    program conditionals;

    var x : bool;

    {
        x = true;
        if (x == true) {
            print("x is true");
        }
    }

It consists of the ```if``` keyword, followed by a pair of ```parentheses``` which contain a boolean value. This is then followed by ```opening and closing curly brackets```, inside of which you can start writing more ```statements```.

Our previous code, of course, will print out:

    x is true

We could also remove the true comparison and still get the same result.

    program conditionals;

    var x : bool;

    {
        x = true;
        if (x) {
            print("x is true");
        }
    }

Setting x to false would, of course, not print out anything.

    program conditionals;

    var x : bool;

    {
        x = false;
        if (x) {
            print("x is true");
        }
    }

If we did want to get some sort of feedback, we'd have to add an ```else statement``` to our conditional.

### Conditionals: else statements

    program conditionals;

    var x : bool;

    {
        x = false;
        if (x) {
            print("x is true");
        } else {
            print("x is false");
        }
    }

This gives us the result:

    x is false

### Conditionals: examples

To add an else statement to your conditional, you just need to write the keyword ```else``` after your ```closing curly bracket```, then ```open``` them once again, write your ```statements``` and ```close your curly brackets```.

It's worth mentioning now you can also have more complicated conditions by using ```comparisons``` or ```logical operators```. You can even use integers as Booleans with the `0` representing a `false` value and anything else being a `true` value.

Finally, don't forget you can write ```if statements``` inside other ```if statements```.

Here's an example.

    program conditionalsExample;

    var b1, b2, b3 : bool;
    var i1, i2, i3 : int;
    var f1, f2, f3 : float;

    {
        b1 = true; b2 = false; b3 = false;
        i1 = 1; i2 = 2; i3 = 0;
        f1 = 1.2; f2 = 2.4; f3 = 3.0;
        if (b1 && b2 == true) {
            if (i1 > i2 || f1 == f2) {
                b3 = true;
            }
        } else {
            if (f3 == 3.0) {
                b3 = true;
            } else {
                print("Hello!");
            }
        }
        if (b3 && !i3) {
            print("Good bye!");
        }
    }

Can you guess what this code would print?

Here's the answer:

    Good bye!

Take your time to figure out why.

### For loops

A for loop in Pixelang would look something like this:

    program forLoops;

    var i : int;

    {
        for (i = 0 to 3) {
            print("Hello!");
        }
    }

This program outputs:

    Hello!
    Hello!
    Hello!

The syntax of a for loop includes the ```for``` keyword, followed by a ```pair of parentheses``` inside of which we'll find an ```assignment of an already existing variable```, followed by the keyword ```to``` and a ```target number```. After your ```closing parenthesis```, you'll have your ```opening and closing curly brackets``` with your statements inside of it.

Both the variable you're assigning (which will be your `control variable`) and the `target number` <b>must</b> be integers. Your `control variable` will increase by one <b>after</b> each loop. It will <b>start off</b> with whatever value you assigned to it and will finish once it is equal to the `target number`. This example will beter demonstrate this:

    program forLoops;

    var i : int;

    {
        for (i = 0 to 3) {
            print(i);
        }
    }

It's worth noting the control variable of the loop for (i, in this example) has to have been previously declared. If you don't wish to change its value, you could also assign it to itself.

    program forLoops;

    var i : int;

    {
        i = 1;
        for (i = i to 3) {
            print("Hello!");
        }
    }

This would output:

    Hello!
    Hello!

### For loops: accessing arrays

One common use of for loops is accessing arrays.

    program accessingArrays;

    var i : int;
    var arr : float[3];
    var n : int;

    {
        arr[0] = 1; arr[1] = 1.5; arr[2] = 2.0;
        n = 3;
        for (i = 0 to n) {
            print(arr[i]);
        }
    }

This, of course, prints:

    1 
    1.5 
    2 

### For loops: nested loops

One more thing that's worth bringing up is that you can actually have a for loop inside of another one. This works well for accessing matrices.

program accessingMatrices;

var i, j : int;
var arr : float[2][3];
var n1, n2 : int;

{
    arr[0][0] = 1; arr[0][1] = 1.5; arr[0][2] = 2.0;
    arr[1][0] = -1; arr[1][1] = 1.25; arr[1][2] = 2.0;
    n1 = 2; n2 = 3;
    for (i = 0 to n1) {
        for (j = 0 to n2) {
            print(arr[i][j]);
        }
    }
}

This results in:

    1 
    1.5 
    2 
    -1 
    1.25 
    2 

### While loops

Here's a simple while loop:

    program whileLoops;

    var i : int;

    {
        i = 0;
        while (i < 3) do {
            print("Hello!");
            i = i + 1;
        }
    }

It prints:

    Hello! 
    Hello! 
    Hello!

It's essentially the same as our first for loop example. The main differences are that you'll be the one defining the ```condition``` now as well as the change in the ```control variable```.

The syntax requires a ```while``` keyword, followed by a ```condition``` enclosed by ```parentheses```, followed by the keyword ```do``` and finally a pair of ```curly brackets```, inside of which you can write whatever statements you want.

It's <b>important</b> to remember to change whatever `variable` or `variables` your `condition` depends on inside the loop. Otherwise, you'll find yourself in an endless loop and you'll have to terminate the program.

Other than that, it works pretty much the same as a `for loop`. Think of the `while loop` as a `for loop` and an `if statement` put together.

## Functions

### Defining and calling a function

You can actually define your own functions in your program. A program with a simple function (that does nothing) would look something like this:

    program functions;

    function myFunction() : void {

    }

    {
        myFunction();
    }

The syntax consists of the keyword ```function```, followed by the ```name of your function``` (which follows the same rules as the variables names), a ```pair of parentheses```, then a ```colon (:)```, then the data type of your function and finally a pair of ```curly brackets``` containing your function's functionality.

We can also see an example of a `call`, which occurs by typing the name of the function, followed by the ```parentheses``` and a ```semicolon (;)```. Parameters/arguments can also be used inside of the parentheses of the function's definition and call, but we'll get into that a bit later.

The functions also introduce a new data type: `void`, which refers to a function that doesn't return anything. That's right! Functions can return values.

### Returns

The keyword `return` allows a function to end before it reaches the end of definition. It looks something like this:

    program returns;

    function myFunction() : void {
        print("Start of function");
        if (true) {
            return;
        }
        print("End of function");
    }

    {
        myFunction();
    }

This functions returns:

    Start of function

It doesn't print "End of function" because it returns earlier.

The `return` statement can also return a value if it's followed by a ```pair of parenthesis``` containing an expression to be returned. It's worth noting in both cases (with or without a value to return), the return statement must be ended with a ```semicolon (;)```. Here's an example of a function that returns a value.

    program functions;

    function myFunction() : int {
        return(3);
    }

    {
        print(myFunction());
    }

This obviously returns:

    3

A difference is worth noting is that `void` functions cannot be assigned to anything. Functions with other data types do return a value and as such can be used in assignments.

### Parameters

We can also pass in parameters to functions through parameters, which are defined inside the ```parentheses``` of the function definition. These parameters are a ```list of comma-separated ids``` that follow the same rules as variable names (and actually are declared as variables inside the function!) followed by a ```colon (:)``` and a ```data type```. It's worth mentioning arrays cannot be passed as parameters. Here's an example so you can understand it better.

    program parameters;

    function multiply(val : int, val2 : int) : int {
        return(val * val2);
    }

    {
        print(double(5, 3));
    }

This returns:

    15

Like I mentioned, parameters are essentially variables that only work inside of your function. You can actually also declare your own new variables for each function as well aside from the parameters. This is where scopes come into place.

### Scopes

There's essentially two different types of scopes in your programs: global and local scopes. Variables in the global scope can be accessed by any function. Variables in the local scope refer to those declared inside of a function (including parameters). They can only be accessed by the function that declared them. It's worth mentioning that a variable in the local scope can share the same name as one in the global scope. If that's the case, a function will always prioritize the one in the local scope.

Declaring local variables is essentially the same as global ones, but they must written at the very top of the contents of your function.

    program scopes;

    var total : int;
    var i : int;

    function handmadeMultiply(val : int, val2 : int) : int {
        var total : int;
        total = 0;
        for (i = 0 to val) {
            total = total + val2;
        }
        return(total);
    }

    {
        total = 0;
        print("local total: ", handmadeMultiply(5, 3));
        print("global total: ", total);
        print("i: ", i);
    }

Let's analyze the output of this function:

    local total:  15 
    global total:  0 
    i:  5

The function accesses the `total` variable. Since there's one in the global scope and another one in the local one, it prioritizes the latter and uses it. That's why at the end we can see the global `total` is left untouched. The `i`, however, was uesd in the loop and as cuh, ends up as the same value as it was in the function.

This is now a good moment to menetion all of your functions must be written after all your global variables have been declared and before your main function.

### Recursion

Finally, one thing that's also worth mentioning is that you can actually call functions inside another function! This looks a little like this:

    program scopes;

    var i : int;

    function handmadeSum(val : int, val2: int) : int {
        return(val + val2);
    }

    function handmadeMultiply(val : int, val2 : int) : int {
        var total : int;
        total = 0;
        for (i = 0 to val) {
            total = handmadeSum(total, val2);
        }
        return(total);
    }

    {
        print("total: ", handmadeMultiply(5, 3));
    }

This also allows for a fun little thing known as `recursion`: calling a function inside itself. You just need to remember to include a base case that terminates the recursion. Otherwise, you'll run out of memory fairly quickly.

Here's a fun little example:

    program recursion;

    function fact(x : int) : int {
        if (x < 1 || x == 1) {
            return(1);
        }
        return(x * fact(x-1));
    }

    {
        print(fact(6));
    }

## Output

One last thing that we probably should've mentioned earlier is the `print` statement, but by now you should be pretty familiar with it.

Syntax is simple: ```print``` keyword, followed by a ```pair of parentheses``` and a ```semicolon (;)```. Inside these parentheses, you may write a list of comma separated expressions. These can be integers, floats, Booleans or even strings! When printing multiple values inside a single `print` statement, they'll show up in the same line, separated by a white space. A `print` statement will always end on a newline.

## Image Processing

Now we're getting into the good stuff.

There is one final data type we haven't dived into: `image`.

`image` cannot be a constant and it cannot be used with any operators. It exists only to be declared as a variable and then used by calling its different methods. Here's an example.

    program image_manipulation;

    var img : image;

    {
        img.open("images/test.png");
        img.save("images/new.png");
    }

This very simple program opens (`open`) an image found in `images/test.png` and then saves (`save`) that same image as a new one `images/new.png`. So essentially images exist as virtual images that can be obtained from a local file and also converted into a local file.

Parameters work the same way they do for normal function calling.

To call an image manipulation method, the call must always be preceded by your ```image variable``` and a ```dot (.)```.

Here's a description of each method:

- open(filename: string): Reads an image file and stores its data into the image variable that called it.
    - Parameters:
        - filename: Filename of the image to read.
- save(filename: string): Saves the data of your image variable into a new image file.
    - Parameters:
        - filename: filename of the new image file to be saved.
- grayscale(): Turns the image into a grayscale one, meaning it only uses shades of gray.
- bandw(): Turns the image into a black-and-white one.
- change_color(r: float, g: float, b: float): Changes the color of the image to the one indicated by the parameters.
    - Parameters:
        - r: intensity of red color.
        - g: intensity of green color.
        - b: intensity of blue color.
- change_color(hex: string): Changes the color of the image to the one indicated by the parameter.
    - Parameters:
        - hex: hexadecimal value of color.
- hflip(): Flips the image horizontally.
- hflip(): Flips the image vertically.
- crop(x: int, y: int, width: int, height: int): Crops the image based on the parameters given.
    - Parameters.
        - x: horizontal start of the crop.
        - y: vertical start of the crop.
        - width: width of the crop.
        - height: height of the crop.

## Running tests

Once you're done writing a program in your code.txt file, you can actually move it into the src/tests/ folder. If it doesn't exist, you can create it. You can use this folder to save your scripts and if the folder already existed, there should be some fun scripts you can try out yourself. To do this, type `make SRC={filename}` where `{filename}` is the filename of whatever script you want to run, without the `.txt` extension.

## Extra information

### Execution time

When running your programs, you may notice at the bottom of the output, there's a line that says `Execution time`. This is exactly what it says it is: the time in miliseconds it took for your program to be executed by the virtual machine.

### Execution

If you head over to the `output/` folder on your project, you'll find an `execution.txt` file. If you take a look at it, you'll actually find all the instructions, in order, that were executed by the virtual machine in order to run your program.

### Memory

In the same `output/` folder, you'll find a `memory.txt` file, which contains the number of variables of each type that were stored in your virtual machine in both global scope and the local scopes of each function you defined.