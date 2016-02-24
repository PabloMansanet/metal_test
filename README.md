# metal_test

Welcome to **metal_test**, the super-lightweight unit test framework for embedded.

metal_test is a macro based unit test framework that makes no assumptions about your target, and doesn't depend on any libraries. All of its funcionality is based on standard C features, with the exception of a few *print hooks* that you must specify yourself. The framework will generate a **main** function that you can either run natively or jump to, after your initialization routines, if you wish to run the tests on target.

metal_test is not dogmatic about specified width types, and will work whether you use chars and ints, or uint8_t, or any other variant. Comparison macros in metal_test are type agnostic (since they compare chunks of memory directly) so tests remain portable. Therefore, tests will not break even when the port layer changes.

## Why use metal_test?

If you find yourself going through many small projects, each with their own technologies and toolchains, metal_test may allow you to minimize the time spent setting up your unit test project, while maintaining your tests portable, give metal_test a try. metal_test should be buildable by any toolchain that implements the C95 standard and onwards.

## Features

* metal_test allows you to define a section of static memory (the fixture) that will be zeroed after every test. Also, it provides easy hooks for user defined *setup* and *teardown* functions, that will act before and every test.
* metal_test defines a set of type agnostic ASSERT macros. Since depending on C11 for generic macros isn't an option, this is achieved at the cost of only accepting lvalues as arguments, which does incidentally make them a bit more hygienic. 
* metal_test will output detailed test results through the user-defined hooks in *print_hooks.h*. A simple implementation of these (using stdlib) is provided, which should be applicable in most cases.

## How to use

The examples folder comes with a few test files for reference, which can be built with CMake. The *module example* directory provides a more meaningful example involving a separate fixture file. 

The steps are as follows:
* Provide implementations for the four hooks in *print_hooks.h*
* Build and link against *metal_test.c*
* Include *metal_test.h* in your test file, and follow the patterns outlied in the examples.

## How does the output look?

This is the output you'll get from the example *simple_mem_eq_example.c*:

```
------------------
-- Running test -- passing_mem_eq_test
------------------
------------------
-- Running test -- failing_mem_eq_test
------------------
  * Assertion failure at /repos/metal_test/examples/simple_examples/simple_mem_eq_example.c:33
  |-----> Expected: &METAL_FIXTURE.testVariableAlpha"
  |-----> Actual: &METAL_FIXTURE.testVariableBeta"
  |-----> Memory differs at the following byte indices:
  \---------> [15][40]
failing_mem_eq_test failed!
=========================
== Test Suite Finished == /repos/metal_test/examples/simple_examples/simple_mem_eq_example.c
==       Failure!      == 1/2 tests passed 
=========================
```

When comparing arbitrary data types using METAL_ASSERT_EQ, the framework provides possible interpretations:
```
------------------
-- Running test -- example_float_test
------------------
  * Assertion failure at /home/cuervo/Desktop/repos/metal_test/examples/simple_examples/simple_fixture_example.c:32
  |---> Expected: "expected_value", evaluated as: 0x410ccccd
  |      \->Interpretations: 
  |           [char:               -51]
  |           [int:                1091357901]
  |           [long:               1091357901]
  |           [long long:          1091357901]
  |           [unsigned char:      205]
  |           [unsigned int:       1091357901]
  |           [unsigned long:      1091357901]
  |           [float:              8.800000]
  |           [double:             0.000000]
  |           [long double:        0.000000]
  |---> Actual: "METAL_FIXTURE.example_float", evaluated as: 0x40b00000
  |      \->Interpretations: 
  |           [char:               0]
  |           [int:                1085276160]
  |           [long:               1085276160]
  |           [long long:          1085276160]
  |           [unsigned char:      0]
  |           [unsigned int:       1085276160]
  |           [unsigned long:      1085276160]
  |           [float:              5.500000]
  |           [double:             0.000000]
  |           [long double:        0.000000]
  \--> Test example_float_test failed!
```
