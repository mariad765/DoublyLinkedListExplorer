# DoublyLinkedListExplorer
The project involves implementing operations on a magical tape represented as a doubly linked list (showing knowledge of data strunctures). The project focuses on various operations such as updating, querying, undo/redo, and executing commands on the tape.
#MAGIC BAND

An efficient method of storing information in terms of memory utilization involves the use of a magical tape. This tape is indexed and initially contains only one character, the "#" character, at position 1. Only one character can be written on each position, including letters, numbers, and keyboard symbols. The tape can be inspected, moving the indicator to the left or right, up to an element that matches a certain symbol.

At the outset, the indicator is on position 1. It can only move as far to the right as the last existing character on the tape, but it cannot move further to the left than position 1. In other words, the magic tape is finite to the left and infinite to the right. New characters can be written on the tape as needed.

For an optimized implementation, the tape can be abstracted as a doubly linked list with a sentinel, containing elements of character type (the sentinel information is not considered).

To highlight the symbol indicated by the indicator during display, it will be preceded and succeeded by the "|" (vertical bar) character. For example, for the previous example, we would have the following display: !0b|2|9a#

The tape initially has only one character on it, the "#" character, but it can expand indefinitely to the right (it cannot expand to the left).

## Usage

There are several operations that can be performed by the user. These are divided into the following categories: UPDATE, QUERY, UNDO/REDO, EXECUTE. 

The possible UPDATE operations are:
• Moving the indicator one position to the left / right: "MOVE_LEFT" or "MOVE_RIGHT". If we are at the first position and encounter the "MOVE_LEFT" operation, nothing happens, but if we are at the last position and encounter "MOVE_RIGHT", we move the indicator one position further to the right, and write the character "#" in that cell.
• Moving left / right until the first character that is equal to a certain symbol: "MOVE_LEFT_CHAR <C>", "MOVE_RIGHT_CHAR <C>", where <C> is a character. The search starts from the current position of the indicator.
– In the case of "MOVE_LEFT_CHAR <C>" operation - if we reach the left edge of the band and the searched character is not found, an ERROR message will be displayed, and the indicator's position will not change.
– In the case of "MOVE_RIGHT_CHAR <C>" operation - if we reach the right edge of the band that contains characters and the searched character is not found, we insert "#" at the end and the position of the indicator will be on the inserted "#".
• Updating the current character: "WRITE <C>"
• Inserting a character to the left / right of the indicator's position (implies insertion and moving the indicator to the new position): "INSERT_LEFT <C>", "INSERT_RIGHT <C>". If the indicator is at the first position, it cannot be inserted to the left - an ERROR message will be displayed, the band remains unchanged, and the position of the indicator remains unchanged.

The operations of the QUERY category enable the display of the current character (at the current position of the indicator), as well as the display of the content of the band, with the current position marked.Commands are SHOW, SHOW_CURRENT.

The operations of the UNDO/REDO type allow for the cancellation of the last applied operation, respectively the restoration of the last applied operation. They will only be applied to the commands that do not modify the containing of the band. Also, themselves will not modify the content.
NOTE: UNDO/REDO are not tested on MOVE_LEFT_CHAR and MOVE_RIGHT_CHAR

EXECUTE command runs the UPDATE commands stored in a queue.

##Implementation

The start point is list: structure that defines the nodes and structures with pointers to the santinel, the current position and the last position // band is still infinite
Description of files: 
Band.h: ~declare types of data // the main double linked list , type T aka char , pointers to nodes 
        ~declare functions // insert/delete/initiate/create/free -operations on the band
Execute.h: ~functions that will perform changes on the band / pointers taking into account the commands stored in the queue or the pointers to positions (stored in 2 stacks)
           ~regarding EXECUTE, REDO, UNDO commands
Free.h: ~declared functions for freeing all the memory used in the program
Move.h: ~the functions declared in this file will be called in the functions in Execute.c. They will do the operetions desired.
Print.h: ~declare two functions. One will show the whole band , and the other one will show only the current element
Update.h: ~the name of the commands UPDATE commands will be stored in a queue and will be used when executed
          ~every time a command from the queue is executed, the pointer to the current position will be sotored in the UNDO stack, also defined here.
          ~every time UNDO is executed (on spot / no need to call EXECUTE), the pointer that was on top of the stack will be added in the stack for REDO
          ~ this file also includes the declaration offunction to intiate,cretae, pop , push, free, on the stack, but also the opertions persomed on queue

#Additional

The Makefile includes the clean, build and run rules. It also includes a test with Valgrind to check for any memory leaks.

THE CODE PASSES THE LOCAL TESTS WITH 100/100 AND 20/20 (for valgrind verification)

