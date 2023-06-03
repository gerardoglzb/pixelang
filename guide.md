# Pixelang Quick Reference Manual

## Introduction
Pixelang is a basic programming language with simple built-in image manipulation capabilities.

This manual will help you quickly find your way around the project and get started writing your own programs!

## Table of Contents
- [Syntax Overview](#syntax-overview)
- [Command-Line Options](#command-line-options)
- [Constructs](#constructs)
- [Functions](#functions)
- [Examples](#examples)

## Getting started
To write your code, you will need to use the code.txt file you'll find in the root directory. If it doesn't exist, go ahead and create the file yourself! Just make sure it's in the same directory as this guide.

Once your code.txt file is ready, you can start coding.

Here's a template for a basic "HelloWorld" program.

    program HelloWorld;

    {
        print("Hello World!");
    }

You can open your terminal and type in the word "make" to run the program. You should see something like this:

    Running 'HelloWorld':
    Hello World! 
    Execution time: 0.258375 ms.

Any Pixelang program must start with the keyword ```program``` followed by the ```name of your program```, then a ```semicolon (;)```.

It must also include a main function, which is defined by a pair of ```curly brackets```. Inside this main function, you may write as many statements as you wish, even 0, meaning this is the bare minimum your program needs:

    program programName;

    {}

But more often than not, you will want to write statements, as well as variables and maybe even functions. So keep reading and you'll find more about all of this!

## Data Types

Pixelang supports integers (int), floats (float) and booleans (bool) as datatypes acceptable for both variables and functions. They can also all be used in most operations.

Strings are also supported, but only as constants typed in by the user. They cannot be stored as variables. They are mostly used for print statements, as you have seen already.

A custom datatype "Image" (image) is also included, which can be used to open and create new images in your system. We'll talk more about that later, but keep in mind that while you can have variables of type Image, they can't be used in any operations.

## Variables

### Declaring a variable

Global variables are exclusively declared at the beginning of the program, right after the program name.

    program variables;

    var a : int;

    {}

To declare a variable, you must first write the keyword ```var``` followed by the ```name of your variable```, then a ```colon (:)```, the ```datatype of your variable``` and a ```semicolon (;)```.

### Naming a variable.

Your variable <b>must</b> start with a ```letter``` and can be then followed by any amount ```alphanumeric characters``` or ```underscores (_)```. Just keep in mind your variable name <b>must not</b> end in an ```underscore (_)``` and you <b>cannot</b> have multiple ```underscores (_)``` together.

### Declaring multiple variables

You can also declare multiple variables at once, as long as they're all of the same datatype.

    program variables;

    var a, b, c : int;

    {}

To do this, just write multiple variable names in between the ```var``` keyword and the ```colon```, while separating them with a ```comma```.

If you want variables of different datatypes, you can always write more lines.

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

You can also assign a variable's value to another one, as long as their datatype is compatible.

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

Another type of variable we haven't mentioned is arrays. You can have arrays of any datatype you can declare a variable of.

    program arrays;

    var arr : int[3];
    var arr1, arr2 : float[5];

    {}

Arrays follow a similar syntax to normal variables, with the one difference being that the datatype is followed by an ```opening bracket ([)```, then a ```constant integer```, a ```closing bracket (])```, and a ```semicolon (;)```. The integer inside of the brackets represents the length of the array. Please keep in mind it can only be a constant integer, not another variable.

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