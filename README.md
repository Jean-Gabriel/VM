## Virtual Machine

[![Build Status](https://travis-ci.org/Jean-Gabriel/VirtualMachine.svg?branch=master)](https://travis-ci.org/Jean-Gabriel/VirtualMachine)

A virtual machine that can read and execute instructions from given bytecode.

## Objectives

``` 
1. Expand my knowledge on how stack based virtual machines work.
2. Have it support C like structure.
3. Write units tests that covert the whole code base.
```

## Bytecode example

Given this example in Typescript 
```typescript
interface Person {
    fullName: string;
    age: number;
    canDrive: boolean;
}

function main() {
    const john: Person = {
        fullName: "John Pablo",
        age: 21,
        canDrive: true
    };

    console.log(john.fullName); // John Pablo
    console.log(john.age); // 21
    console.log(john.canDrive); // 1
}
```

... in bytecode

```
DECLARE_FUNCTION, 0, 21, 0, // main() declaration

DECLARE_OBJECT, 0, // person interface declaration
DECLARE_OBJECT_ATTRIBUTE, 0, 0, NUMBER,
DECLARE_OBJECT_ATTRIBUTE, 0, 1, OBJECT,
DECLARE_OBJECT_ATTRIBUTE, 0, 2, BOOLEAN,

CALL_FUNCTION, 0, // call main()
HALT,

LOAD_OBJECT, 0, // new Person
STORE_LOCAL, 0, // john = new Person

LOAD_LOCAL, 0, // john.age = 21
LOAD_NUMBER, 21,
STORE_ATTRIBUTE, 0,

LOAD_LOCAL, 0, // john.fullName = "John Pablo"
LOAD_STRING, 'J', 'o', 'h', 'n', ' ', 'P', 'a', 'b', 'l', 'o', '\0',
STORE_ATTRIBUTE, 1,

LOAD_LOCAL, 0, // john.canDrive = true
LOAD_BOOLEAN, 1,
STORE_ATTRIBUTE, 2,

LOAD_LOCAL, 0, // console.log(john.age)
LOAD_ATTRIBUTE, 0,
PRINT_NUMBER,

LOAD_LOCAL, 0, // console.log(john.fullname)
LOAD_ATTRIBUTE, 1,
PRINT_STRING,

LOAD_LOCAL, 0, // console.log(john.canDrive)
LOAD_ATTRIBUTE, 2,
PRINT_BOOLEAN,

RETURN
```

## Notes
It can also execute loops, conditional operations, mathematical operations, string operations and boolean operations.

The virtual machine is naive, so it expects that every program is correct (I might add bytecode validation later).

As of now it only supports, ``struct``, ``unsigned numbers``, ``string`` and ``boolean`` types.
