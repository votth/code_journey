# Basic
DevOps circle: Dev - Ops
- Plan - code - build - test
- Release - deploy - operate - monitor
- repeat


# TDD
Test driven development: tests are written before code

Without-TDD wordflow
- choosing something to work on
- build it based on specification
- test with small scripts

With-TDD
- choosing something to work on
- write tests that would pass if product works
- keep building until all tests pass


# CI - Continuous Integration
Devs pushing many small changes to a central git repo per day. These changes are verified by an automatic software that runs comprehensive tests to ensures no major issues are seen by customers.

Benefits:
- Very first step to DevOps automation and helps with code collaboration
- Improve speed without breaking existing code
- Reduce customer churn and user satisfaction by preventing broken code from publishing

CI/CD: vital tool for developer collaboration. Increase collaboration, prevent errors, and increase user satisfaction.

## Setting up CI
Plug in for GitHub: LayerCI  
Cypress


# Code Coverage
Methodology that quantitatively measures how comprehensive a code base's tests are. Increasing code coverage often increases stability and reduces bugs.  
Measuring lines of code

Branch Coverage: Measuring groups of lines

When to care
- Your product has users and those users might leave if they are affected by bugs.  
- You are working with developers that aren't immediately trusworthy like contractors/interns.  
- You are working on a very large code base with many testable components.  

 Avoid over-optimized

Open-soucre tools:
- Codecov
- Coveralls
- Code climate


# Linting best practices
Linters look at a program's source code and find problems automatically. They are a common feature of pull request automation because they ensure that "obvious" bugs do not make it to production.

"Don't shadow variables": naming an inner scope variable same as an outer scope one.  
Global style guide

The Nit approach: code reviewers leave little comments on the code called "nits" that the team can ignore until broader reviews.  
Auto Formatter
Running linting and formatting within the CI steps: no merging if linting fails; or automatically fixes the issues

Examples of linters for various programming languages:
- JS: ESLint
- TypeS: TypeScript ESLint
- Python: pylint, flake8
- C++: Googles's cpplint
- Go: gofmt
- Java: CheckStyle, FindBugs
- Ruby: RuboCop, Pronto
- Java, JS, C#, TS, Kotlin, etc.: SonarQube
- DeepSource
