# libft-asm

## Part 1

- ~~bzero~~
- ~~strcat~~
- ~~isalpha~~
- ~~isdigit~~
- ~~isalnum~~
- ~~isascii~~
- ~~isprint~~
- ~~toupper~~
- ~~tolower~~
- ~~puts~~ (obviously, you can use the write syscall)

## Part 2

- ~~strlen~~
- ~~memset~~
- memcpy
- ~~strdup~~ (obviously you are allowed to call malloc)

## Part 3

To conclude, you must code a ft_cat function which will take a file descriptor (for
example 0...) as argument and that will have the same behavior as the cat command it’ll
return void.


## Nasm on macOS

- Stack must be 16-bit aligned.
- Symbols must be prefixed with an underscore (_printf).
- Syscalls on x86_64 uses the same opcodes as x86.
- Syscall opcodes must be offset by x200000, i.e. a syscall to write (usually 0x4) would be 0x2000004 (2, five 0's, 4).


## Useful articles

Tutorial on nasm assembly, covers plenty of topics:
- <http://cs.lmu.edu/~ray/notes/nasmtutorial/>

Stack?
- <https://eli.thegreenplace.net/2011/02/04/where-the-top-of-the-stack-is-on-x86/>
- <https://eli.thegreenplace.net/2011/09/06/stack-frame-layout-on-x86-64/>

Sample code:
- <https://www.csee.umbc.edu/portal/help/nasm/sample_64.shtml>

Complete tutorial (lots of useful information but overall not extremely reliable information):
- <https://www.tutorialspoint.com/assembly_programming/index.htm>
- <https://www.tutorialspoint.com/assembly_programming/assembly_strings.htm> (especially useful for mem* operations like memcpy (see next point!))

strlen (a little extra info on rep and scasb):
- <https://osandamalith.com/2016/11/08/string-length-function-in-nasm/>

Syscalls/interfacing with Linux:
- <https://en.wikibooks.org/wiki/X86_Assembly/Interfacing_with_Linux#syscall>

Architecture (describes register purposes):
- <https://en.wikibooks.org/wiki/X86_Assembly/X86_Architecture>

x86 opcode and instruction set reference:
- <http://ref.x86asm.net/> (see the table near the top of the page for the differences between the versions)

Not exactly sure what this is but I used the x86-64 psABI version 1.0 document for register reference on p. 23 (version 1, Jan 28, 2018).
The document contains a lot of information on the x86-64 architecture:
- <https://github.com/hjl-tools/x86-psABI/wiki/X86-psABI>

Debugging:
- [Debugging x86-64 assembly with lldb and dtrace](http://nickdesaulniers.github.io/blog/2016/01/20/debugging-x86-64-assembly-with-lldb-and-dtrace/)

Some answers that cleared up confusion for me:
- [LEA vs MOV](https://stackoverflow.com/questions/1699748/what-is-the-difference-between-mov-and-lea>)

And, of course, there is always the official documentation:
- [nasm](https://www.nasm.us/docs.php) (available in pdf and html format)
- [Intel assembly](https://software.intel.com/en-us/articles/introduction-to-x64-assembly) (also available in pdf format, link at the top of the article)
- [Intel® 64 and IA-32 Architectures Software Developer’s Manual (all volumes)](https://software.intel.com/sites/default/files/managed/39/c5/325462-sdm-vol-1-2abcd-3abcd.pdf)
