#A Note on Testing
_Author: Michael Kirkedal Thomsen_

Testing is not something that should be put together in a last minute effort. You do not argue that a program is correct by showing a couple of examples and perhaps a screen dump. Firstly, this shows very little correctness of your implementation and, secondly, this is not how you use testing when implemented.

A good practice is to start making structured tests when you start programming. Some, of course, are small to make you understand a specific function, while others you do to convince you that some part of your implementation is correct. So as you are doing it from the very beginning you can save yourself some time by thinking more structures about it. The other good thing you get is that it also forces you to think more structured about you code.

There are a few points you should always be aware of when doing testing.

  * Purpose: Always consider what you are testing for.
  * Simplicity: Have many simple tests (and some more advanced). The simpler they are the easier they can be used for debugging. But too simple and they will not do the job.
  * Coverage: Always think if your test covers enough of both your input and code. And convince others that they do; write about this in your report.
  * Automation: You are going to be running test very often. Make them easy to do by using a testing framework or some scripts.
  * Reproduce-ability: Test are there for you to do debugging, so you would like to easily get the same test. But tests are also for other to be convinced of the correctness of your program. It is therefore important that others can easily run your test.

This will be detailed in the following. I will first talk about functional testing followed by application testing and afterwards a bit about performance testing.


## Functional Testing

Functional testing is showing that you implementation works correctly (or at least according to specification).

### Flavours of Testing

Testing is a very big field in both research and industry. I do not expect that you know about all the different approaches, but I do assume that you have leaned about unit testing on the first year. But just to recap here are a few of the concepts that you should be familiar with.

#### Black-box testing vs. White-box testing
Black-box testing is when you do not know anything about the inside of the implementation, but you do know the API and how it was supposed to behave. This is often the test that your TA will do as it can point us to some problems in your implementation and we can directly find the code that is problematic. For you it is the way to show that your implementation follows the API and requirements that have been given.

In white-box testing you know the inside and normally have access to the different parts of the implementation. This is important when making larger implementations as you and test smaller components at a time, which makes debugging much easier. When you design your tests, consider who the test different parts of your code and not just the inputs.

#### Smoke testing

This covers simple tests that can convince you that something is correct. When you made your implementation you likely do this all the time before continuing to the next part. Does the code compile? Does the program give some output? Can the program read some URL.

This is very useful for you, but can never give anyone else an expectation of correctness.

#### Unit testing

A unit test is a single test that verifies that a small part of you implementation works correctly. This you can, for example, use to test that your URL parser works correctly by writing examples of the different URLs then test all of these.

  * The first thing when making good unit testing is to identify the corner cases. Unit testing should both cover the expected cases, but also many different weird inputs that you can expect.
  * Secondly, you write a few unit tests to cover the expected inputs (and make sure that these does not fail).
  * Thirdly, you write down small tests that diverge from the previous unit tests to cover the corners that you have identified. Don't make each unit test too large, as you then would not know why they fail.
  * Fourth, you should convince yourself that all corners are covered by the unit tests.

#### Other methods of testing
I know that those of you that have IT Security are familiar with fuzzying. This is (often a black-box) testing method where you apply loads of randomly generated tests with the hope of finding some error.

In Advanced Programming on the Master's level you will also become familiar with property-based testing that (often white-boxed) make many randomly generated tests, but only with a single property in mind.


### Testing frameworks

For all mature programming languages there exist unit testing frameworks. I will highly recommend that you familiarise yourself with the one for you favourite language(s) and use it. It does take a bit of time in the beginning but you will save it many times later. (Just like learning LaTeX.)

For many simple tasks, like our assignments, it can be sufficient to use a good script.


## Application testing
The task of this is to convince that the developed program solves what is was designed to do. This is generally the most important testing when both design and developing programs. It is not if the program works correctly (you know that from your functional testing), but to what extend it can solve the overall problem.


## Performance Testing

Also called performance evaluation. The idea is showing that your implementation works as fast as you expect. You can basically do this in two ways: asymptotic evaluation or comparison evaluation.

In either case remember to include the scripts and the results of running them.

### Asymptotic evaluation

Sometimes you will first theoretically analyse the asymptotic run-time and then evaluate that your implementation actually behaves like this.

In this course we are often more interested in the network behaviour. So a better approach is to make timing tests with different file sizes and then afterwards analyse how these behave asymptotically. You can then relate it to what you have learned about the network.

### Comparison evaluation

Here you compare against some other implementation. For your browser it could be wget or Firefox (it does have a command line interface). This comparison can be quite hard as the implementation can differ much, so you should also include this aspect in your analysis.


## Your testing on CompSys

When you make a program the minimal requirement is that you make a black-boxed unit testing. In our assignment you are given a specific problem, so functional and application testing are merged.

In your report you can write about the corner cases you identify and why your unit testing covers them. Also report on the result. Also provide the tests. Do not insert a few verbatim cases in the report, but give the test as a separate file with the script of commands you use to run them.

### Failed tests

Not all tests must succeed. Some can fail because you give it an input you know are wrong, but more importantly the tests might show that you have an error in your implementation. Do not hide these tests. As a good computer scientist it is important that you can identify where you have problems.

If you hide these tests, we will still find the problems and then subtract points because you are not able to make a good test. So even though your implementation is not complete, you can still get full points on testing.

### Documentation

Remember always do document your testing in report. Cover the interesting cases: Why do some interesting tests fail and succeed? Argue why you test are covering enough to argue that your program is correct.

Write only a short conclusion on the general result of your testing. Do _not_ list all individual test in your report and state of they succeed of fail. You must also attach all your test with your source code, so the reader (TA) can check the individual test for themselves. (Remember to tell the reader how to run your tests.)

