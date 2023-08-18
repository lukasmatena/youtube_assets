# C++ PROGRAMMING COURSE FOR BEGINNERS

This document is a summary of the following YouTube course: https://www.youtube.com/watch?v=TxmagLyfT7M&list=PLz0BKECGUM1S0N4rRlOHfTP8q6OWkTzWs.
It contains brief summary of each video and links to various assets (such as completed source codes).

Note that this is a living document that I edit and polish as I want, including updates to already finished lessons.


## LESSON 1: INTRODUCTION

Video link: https://youtu.be/TxmagLyfT7M

Brief introduction and basic thoughts about reasons to learn programming and how this course is supposed to work.

### Is C++ good for a beginner?

- There is a separate video only about that question: https://youtu.be/RTHh2PJO52k
- C++ is a good choice, PROVIDING that the student follows a course or a teacher and does not explore all the pitfalls by trial and error.

### Why another C++ course?

- The course strives to teach C++ on simple graphical applications like simple games.
- Teaches to do things the easy way.
- The author has experience with C++ software development and is willing to share it.
- Uses modern C++17, not legacy C-style features like many others.
- The course tries to teach programming, not just C++.
- A lot of practice.

### Why should you learn programming?

- Earning money (obviously)
- Interesting hobby
- May help in understanding technical subjects in general by allowing to 'touch' things.
- Shapes mind in a good way.




## LESSON 2: SETTING UP DEVELOPMENT TOOLS

Video link: https://youtu.be/kaLaj50gwr4

How to tutorial describing installation of C++ compiler, CMake and Visual Studio Code, which are the tools that we will be using throughout the course.
There are three parts, one for each of the supported desktop platforms (Windows, macOS, Linux).




## LESSON 3: HELLO WINDOW FROM A TEMPLATE

Video link: https://youtu.be/kaLaj50gwr4

Shows how to download cppgraphics library (https://www.github.com/lukasmatena/cppgraphics) and how to create and build a C++ project from a template.






## LESSON 4: HELLO WINDOW EXPLAINED

Video link: ...

Goes through the source code created from the template in the previous lesson and explains basics about C++ code structure.

### Building a C++ project

- C++ is a compiled language: an executable is built from the source code to be run later.
- Setting up the project when using external libraries may be challenging, we will rely on a ready-made template at this point.

### Writing C++ code (basics)

- C++ is case-sensitive and whitespace-independent.
- The code is composed of statements, which are separated by semicolons.
- Individual statements belonging together are grouped into blocks using curly braces.
- The block to be executed on startup is preceded by `int main()`.
- Don't place two or more statements on a single line - C++ allows that, but it is not a good habit. Resist the temptation to make your code look "compact".

### Including headers

- Some statements are only comprehensible to the compiler when respective header is `#include`d.
- Headers which are part of C++ should be included by `#include <header>`, everything else should use `#include "header"`.
- Do not use absolute paths when `#include`ing a header file. The paths to the headers need to be properly configured for the whole project.


### Compiler errors and warnings

- When the compiler is unable to compile the source code, it reports the error and line number.
- Errors should be fixed starting with the first one.
- The error description may be misleading, do not follow the hints blindly.
- The compiler can report warnings when the code is valid, but looks suspicious. Do not ignore them.

### Assets

Link to the source file at the end of this lesson: N/A