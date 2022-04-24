General repeatable solution to a commonly occuring problem in software design.
- give the Dev a selection of tried and tested solutions to work with
- language neutral and so can be applied to any that supports OOP
- have proven track record, which helps reduce technical risk of the project when implemented
- highly flexible

# Creational
How objects are created.

## Signleton
Object that can only be instantiated once.
- `static`
- has funciton that check if an object has been created, to ensure only one instance will be created.
- eg: settings

## Prototype
Clones, inheritance.
- Share attributes

## Builder
Instead of creating objects with constructor, use step-by-step methods (get_attribute) to initiate the values.

## Factory
Instead of using new keywords to create an object, use function or method.
- eg: conditional method to decide which buttons will appear

---
# Structural
How objects are related to each others

## Facade
Abstract: simple front-facing, while has complex underlying structual that isn't neccessary to be shown to know how to use/apply. API.

## Proxy
Subtitute.
- replace target object with a proxy
- eg: ??

---
# Behavioral
How objects communicate

## Iterator
Traverse to a collection of objects.
- `for` loop
- pull-based: start with a collections, and write code to determine how to iterate through it

## Observer
Allow multiple objects "subcribe" to events that are broadcasted by another object. One-to-many relation.
- push-based
- eg.: database changes that get updated in-apps.

## Mediator
Middle-man, many-to-many relation.
- eg.: Airplanes and runways objects, need to see if an airplane has clear landing in a current runway. Without a middle-man (Tower) all of airplanes and runways have to have communication among them.

## State
Program behaves differently according to a finite number of states.
